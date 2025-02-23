/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headmaster.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:29:00 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/23 16:38:56 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Headmaster.hpp"
#include "../include/Professor.hpp"
#include "../include/Student.hpp"
#include "../include/Course.hpp"
#include "../include/CourseFinishedForm.hpp"
#include "../include/NeedCourseCreationForm.hpp"
#include "../include/SubscriptionToCourseForm.hpp"
#include "../include/NeedMoreClassRoomForm.hpp"

Headmaster::Headmaster(std::string p_name)
  : Staff(p_name),
    _professors(Singleton<Professor>::get_instance()),
    _students(Singleton<Student>::get_instance()),
    _courses(Singleton<Course>::get_instance()),
    _classrooms(Singleton<Classroom>::get_instance()),
    _secretary("Mary") {}

Headmaster::Headmaster(const Headmaster &copy)
  : Staff(copy),
    _formToValidate(copy._formToValidate),
    _professors(Singleton<Professor>::get_instance()),
    _students(Singleton<Student>::get_instance()),
    _courses(Singleton<Course>::get_instance()),
    _classrooms(Singleton<Classroom>::get_instance()),
    _secretary(copy._secretary) {}

Headmaster &Headmaster::operator=(const Headmaster &copy) {
  _formToValidate = copy._formToValidate;
  return *this;
}

Headmaster::~Headmaster() {}

void Headmaster::add_professor(std::shared_ptr<Professor> &professor) {
  if (!professor) {
    std::cout << "[ADD PROFESSOR] Professor is null\n";
    return;
  }
  professor->set_headmaster(this);
  _professors.add(professor);
}

void Headmaster::add_student(std::shared_ptr<Student> &student) {
  if (!student) {
    std::cout << "[ADD STUDENT] Student is null\n";
    return;
  }
  student->set_headmaster(this);
  _students.add(student);
}

void Headmaster::add_course(std::shared_ptr<Course> &course) {
  if (!course) {
    std::cout << "[ADD COURSE] Course is null\n";
    return;
  }
  _courses.add(course);
}

void Headmaster::add_classroom(std::shared_ptr<Classroom> &classroom) {
  if (!classroom) {
    std::cout << "[ADD CLASSROOM] Classroom is null\n";
    return;
  }
  _classrooms.add(classroom);
}

void Headmaster::remove_professor(std::shared_ptr<Professor> &professor) {
  if (!professor) {
    std::cout << "[REMOVE PROFESSOR] Professor is null\n";
    return;
  }
  _professors.remove(professor);
}

void Headmaster::remove_student(std::shared_ptr<Student> &student) {
  if (!student) {
    std::cout << "[REMOVE STUDENT] Student is null\n";
    return;
  }
  _students.remove(student);
}

void Headmaster::remove_course(std::shared_ptr<Course> &course) {
  if (!course) {
    std::cout << "[REMOVE COURSE] Course is null\n";
    return;
  }
  _courses.remove(course);
}

void Headmaster::remove_classroom(std::shared_ptr<Classroom> &classroom) {
  if (!classroom) {
    std::cout << "[REMOVE CLASSROOM] Classroom is null\n";
    return;
  }
  _classrooms.remove(classroom);
}

std::shared_ptr<Professor> Headmaster::check_professor(std::shared_ptr<Person> &person) {
  if (std::shared_ptr<Professor> professor = std::dynamic_pointer_cast<Professor>(person)) {
    if (!_professors.find(professor)) {
      std::cout << "[REQUEST] Professor: " << professor->get_name()
                << " does not belong to this school\n";
      return nullptr;
    }
    return professor;
  }
  std::cout << "[REQUEST] Person is not a professor\n";
  return nullptr;
}

std::shared_ptr<Student> Headmaster::check_student(std::shared_ptr<Person> &person) {
  if (std::shared_ptr<Student> student = std::dynamic_pointer_cast<Student>(person)) {
    if (!_students.find(student)) {
      std::cout << "[REQUEST] Student: " << student->get_name()
                << " does not belong to this school\n";
      return nullptr;
    }
    return student;
  }
  std::cout << "[REQUEST] Person is not a student\n";
  return nullptr;
}

void Headmaster::request(std::shared_ptr<Person> &person, FormType form_type, std::string info) {
  if (info.empty()) {
    std::cout << "[REQUEST] Info is empty\n";
    return;
  }
  switch (form_type) {
    case FormType::NeedCourseCreation:
      if (std::shared_ptr<Professor> professor = check_professor(person)) {
        request_course_creation(professor, info);
      }
      break;
    case FormType::NeedMoreClassRoom:
      if (std::shared_ptr<Professor> professor = check_professor(person)) {
        request_classroom_creation(professor);
      }
      break;
    case FormType::CourseFinished:
      if (std::shared_ptr<Professor> professor = check_professor(person)) {
        request_course_finished(professor, info);
      }
      break;
    case FormType::SubscriptionToCourse:
      if (std::shared_ptr<Student> student = check_student(person)) {
        request_course_subscription(student, info);
      }
      break;
    default:
      return;
  }
}

void Headmaster::request_course_creation(std::shared_ptr<Professor> &professor, std::string info) {
  auto form = _secretary.createForm(FormType::NeedCourseCreation);
  receiveForm(form);
  auto course_form = std::dynamic_pointer_cast<NeedCourseCreationForm>(form);
  course_form->set_course_name(info);
  sign_form(form);
  execute_form(form);
  std::shared_ptr<Course> course = std::make_shared<Course>(info);
  professor->assignCourse(course);
  course->assign(professor);
  add_course(course);
  std::cout << "Headmaster created course: " << info
            << " and assigned it to professor: "
            << professor->get_name() << "\n";
}

void Headmaster::request_course_finished(std::shared_ptr<Professor> &professor, std::string info) {
  std::shared_ptr<Student> student = _students.find(info);
  if (!student) {
    std::cout << "[REQUEST] Student: " << info << " is not a part of the school\n";
    return;
  }
  std::shared_ptr<Course> course = professor->get_current_course();
  auto form = _secretary.createForm(FormType::CourseFinished);
  receiveForm(form);
  auto course_form = std::dynamic_pointer_cast<CourseFinishedForm>(form);
  course_form->set_course(professor->get_current_course());
  sign_form(form);
  execute_form(form);
  std::cout << "Headmaster gave student: " << info
            << "a diploma for finishing course: "
            << professor->get_current_course()->get_name() << "\n";
  course->remove_student(student);
  student->graduate(course);
}

void Headmaster::request_classroom_creation(std::shared_ptr<Professor> &professor) {
  auto form = _secretary.createForm(FormType::NeedMoreClassRoom);
  auto course = professor->get_current_course();
  receiveForm(form);
  auto classroom_form = std::dynamic_pointer_cast<NeedMoreClassRoomForm>(form);
  classroom_form->set_course(course);
  sign_form(form);
  execute_form(form);
  std::shared_ptr<Classroom> classroom = std::make_shared<Classroom>();
  classroom->assignCourse(course);
  add_classroom(classroom);
  std::cout << "Headmaster created classroom for course: "
            << course->get_name() << "\n";
}

void Headmaster::request_course_subscription(std::shared_ptr<Student> &student, std::string info) {
  std::shared_ptr<Course> course = _courses.find(info);
  if (!course) {
    std::cout << "[REQUEST] Course: " << info << " does not exist\n";
    return;
  }
  if (!course->subscribe(student)) {
    std::cout << "[REQUEST] Student: " << student->get_name()
              << " cannot subscribe to course: " << info << "\n";
    return;
  }
  if (!student->subscribe(course)) {
    std::cout << "[REQUEST] Student: " << student->get_name()
              << " cannot subscribe to course: " << info << "\n";
    course->remove_student(student);
    return;
  }
  auto form = _secretary.createForm(FormType::SubscriptionToCourse);
  receiveForm(form);
  auto course_form = std::dynamic_pointer_cast<SubscriptionToCourseForm>(form);
  course_form->set_course(course);
  sign_form(form);
  execute_form(form);
  std::cout << "Headmaster subscribed student: " << student->get_name()
            << " to course: " << info << "\n";
}

void Headmaster::receiveForm(std::shared_ptr<Form> &p_form) {
  if (!p_form) {
    std::cout << "[RECEIVE FORM] Form is null\n";
    return;
  }
  _formToValidate.push_back(p_form);
  std::cout << "Form received\n";
}

void Headmaster::sign_form(std::shared_ptr<Form> &form) {
  if (!form) {
    std::cout << "[SIGN FORM] Form is null\n";
    return;
  }
  if (std::find(_formToValidate.begin(), _formToValidate.end(), form) == _formToValidate.end()) {
    std::cout << "[SIGN FORM] Form not received\n";
    return;
  }
  form->sign();
}

void Headmaster::execute_form(std::shared_ptr<Form> &form) {
  if (!form) {
    std::cout << "[EXECUTE FORM] Form is null\n";
    return;
  }
  if (std::find(_formToValidate.begin(), _formToValidate.end(), form) == _formToValidate.end()) {
    std::cout << "[EXECUTE FORM] Form not received\n";
    return;
  }
  form->execute();
}

void Headmaster::sign_all_forms() {
  for (auto &form : _formToValidate) {
    form->sign();
  }
}

void Headmaster::execute_all_forms() {
  for (auto &form : _formToValidate) {
    form->execute();
  }
}

// To archive the correct forms and remove them from the vector
// in a single loop we need to use the erase-remove idiom:
// https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
// In short, remove_if places the elements that should be removed at the end of 
// the vector and returns an iterator to the first of those elements.
// We then use erase to remove those elements from the vector.
// A lambda function is used to check if the form has been executed.
// Lambda function: [captured variable](parameters) {function body}
void Headmaster::clean_forms(Secretary &secretary) {
  _formToValidate.erase(
    std::remove_if(
      _formToValidate.begin(),
      _formToValidate.end(),
      [&secretary](std::shared_ptr<Form> &form) {
        if (form->check_executed()) {
          secretary.archiveForm(form);
          return true;
        }
        return false;
      }),
    _formToValidate.end());
}

void Headmaster::start_class() {
  for (auto professor :_professors.get_group()) {
    professor->doClass();
  }
}

void Headmaster::start_class(std::shared_ptr<Professor> &professor) {
  if (!_professors.find(professor)) {
    std::cout << "[START CLASS] Professor: " << professor->get_name()
              << " does not belong to this school\n";
    return;
  }
  professor->doClass();
}

void Headmaster::attend_class(std::shared_ptr<Course> &course) {
  if (!_courses.find(course)) {
    std::cout << "[ATTEND CLASS] Course: " << course->get_name()
              << " does not exist in this school\n";
    return;
  }
  for (auto student : _students.get_group()) {
    student->attendClass(course);
  }
}

void Headmaster::attend_class(std::shared_ptr<Student> &student, std::shared_ptr<Course> &course) {
  if (!_courses.find(course)) {
    std::cout << "[ATTEND CLASS] Course: " << course->get_name()
              << " does not exist in this school\n";
    return;
  }
  if (!_students.find(student)) {
    std::cout << "[ATTEND CLASS] Student: " << student->get_name()
              << " does not belong to this school\n";
    return;
  }
  student->attendClass(course);
}