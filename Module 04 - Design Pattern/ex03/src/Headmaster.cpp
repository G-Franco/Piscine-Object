/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headmaster.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:29:00 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/27 11:54:55 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Headmaster.hpp"
#include "../include/Professor.hpp"
#include "../include/Student.hpp"
#include "../include/Course.hpp"
#include "../include/CourseFinishedForm.hpp"
#include "../include/NeedCourseCreationForm.hpp"
#include "../include/SubscriptionToCourseForm.hpp"
#include "../include/NeedMoreClassRoomForm.hpp"
#include "../include/helper.hpp"

Headmaster::Headmaster(std::string p_name)
  : Staff(p_name),
    _secretary("Mary") {}

Headmaster::Headmaster(const Headmaster &copy)
  : Staff(copy),
    _formToValidate(copy._formToValidate),
    _professors(copy._professors),
    _students(copy._students),
    _courses(copy._courses),
    _classrooms(copy._classrooms),
    _secretary(copy._secretary) {}

Headmaster &Headmaster::operator=(const Headmaster &copy) {
  _formToValidate = copy._formToValidate;
  _professors = copy._professors;
  _students = copy._students;
  _courses = copy._courses;
  _classrooms = copy._classrooms;  
  return *this;
}

Headmaster::~Headmaster() {}

std::weak_ptr<Professor> Headmaster::add_professor(std::string name) {
  if (name.empty()) {
    std::cout << "[ADD PROFESSOR] Name is empty\n";
    return std::weak_ptr<Professor>();
  }
  auto professor = std::make_shared<Professor>(name);
  professor->set_self(professor);
  professor->set_headmaster(this);
  _professors.push_back(professor);
  return professor;
}

std::weak_ptr<Student> Headmaster::add_student(std::string name) {
  if (name.empty()) {
    std::cout << "[ADD STUDENT] Name is empty\n";
    return std::weak_ptr<Student>();
  }
  auto student = std::make_shared<Student>(name);
  student->set_self(student);
  student->set_headmaster(this);
  _students.push_back(student);
  return student;
}

std::weak_ptr<Course> Headmaster::add_course(std::string name) {
  if (name.empty()) {
    std::cout << "[ADD COURSE] Name is empty\n";
    return std::weak_ptr<Course>();
  }
  auto course = std::make_shared<Course>(name);
  course->set_self(course);
  _courses.push_back(course);
  return course;
}

std::weak_ptr<Classroom> Headmaster::add_classroom() {
  auto classroom = std::make_shared<Classroom>();
  std::weak_ptr<Classroom> classroom_weak = classroom;
  classroom->set_self(classroom_weak);
  _classrooms.push_back(classroom);
  return classroom;
}

void Headmaster::remove_professor(std::weak_ptr<Professor> &professor) {
  if (auto pf = professor.lock()) {
    auto it = std::find(_professors.begin(), _professors.end(), pf);
    if (it == _professors.end()) {
      std::cout << "[REMOVE PROFESSOR] Professor: " << pf->get_name()
                << " does not belong to this school\n";
      return;
    }
    _professors.erase(it);
  }
}

void Headmaster::remove_student(std::weak_ptr<Student> &student) {
  if (auto stud = student.lock()) {
    auto it = std::find(_students.begin(), _students.end(), stud);
    if (it == _students.end()) {
      std::cout << "[REMOVE STUDENT] Student: " << stud->get_name()
                << " does not belong to this school\n";
      return;
    }
    _students.erase(it);
  }
}

void Headmaster::remove_course(std::weak_ptr<Course> &course) {
  if (auto crs = course.lock()) {
    auto it = std::find(_courses.begin(), _courses.end(), crs);
    if (it == _courses.end()) {
      std::cout << "[REMOVE COURSE] Course: " << crs->get_name()
                << " is not taught at this school\n";
      return;
    }
    _courses.erase(it);
  }
}

void Headmaster::remove_classroom(std::weak_ptr<Classroom> &classroom) {
  if (auto cls = classroom.lock()) {
    auto it = std::find(_classrooms.begin(), _classrooms.end(), cls);
    if (it == _classrooms.end()) {
      std::cout << "[REMOVE CLASSROOM] Classroom: " << cls->get_id()
                << " does not belong to this school\n";
      return;
    }
    _classrooms.erase(it);
  }
}

std::weak_ptr<Professor> Headmaster::check_professor(std::weak_ptr<Person> &person) {
  if (auto shared_person = person.lock()) {
    if (auto professor = std::dynamic_pointer_cast<Professor>(shared_person)) {
      if (std::find(_professors.begin(), _professors.end(), professor) == _professors.end()) {
        std::cout << "[REQUEST] Professor: " << professor->get_name()
                  << " does not belong to this school\n";
        return std::weak_ptr<Professor>();
      }
      return professor;
    }
  }
  std::cout << "[REQUEST] Person is not a professor\n";
  return std::weak_ptr<Professor>();
}

std::weak_ptr<Student> Headmaster::check_student(std::weak_ptr<Person> &person) {
  if (auto shared_person = person.lock()) {
    if (auto student = std::dynamic_pointer_cast<Student>(shared_person)) {
      if (std::find(_students.begin(), _students.end(), student) == _students.end()) {
        std::cout << "[REQUEST] Student: " << student->get_name()
                  << " does not belong to this school\n";
        return std::weak_ptr<Student>();
      }
      return student;
    }
  }
  std::cout << "[REQUEST] Person is not a student\n";
  return std::weak_ptr<Student>();
}

bool Headmaster::request(std::weak_ptr<Person> &person, FormType form_type, std::string info) {
  if (info.empty() && form_type != FormType::NeedMoreClassRoom) {
    std::cout << "[REQUEST] Info is empty\n";
    return false;
  }
  switch (form_type) {
    case FormType::NeedCourseCreation: {
      auto professor = check_professor(person);
      if (!professor.expired()) {
        return request_course_creation(professor, info);
      }
      return false;
    }
    case FormType::NeedMoreClassRoom: {
      auto professor = check_professor(person);
      if (!professor.expired()) {
        return request_classroom_creation(professor);
      }
      return false;
    }
    case FormType::CourseFinished: {
      auto professor = check_professor(person);
      if (!professor.expired()) {
        return request_course_finished(professor, info);
      }
      return false;
    }
    case FormType::SubscriptionToCourse: {
      auto student = check_student(person);
      if (!student.expired()) {
        return request_course_subscription(student, info);
      }
      return false;
    }
    default:
      return false;
  }
}

bool Headmaster::request_course_creation(std::weak_ptr<Professor> &professor, std::string info) {
  if (info.empty()) {
    std::cout << "[REQUEST] Course name is empty\n";
    return false;
  }
  auto prof = professor.lock();
  if (!prof) {
    std::cout << "[REQUEST] Professor is empty\n";
    return false;
  }
  auto form = _secretary.createForm(FormType::NeedCourseCreation);
  receiveForm(form);
  auto course_form = std::dynamic_pointer_cast<NeedCourseCreationForm>(form);
  course_form->set_course_name(info);
  sign_form(form);
  execute_form(form);
  std::weak_ptr<Course> course = add_course(info);
  auto crs = course.lock();
  prof->assignCourse(course);
  crs->assign(prof);
  std::cout << "Headmaster created course: " << info
            << " and assigned it to professor: "
            << prof->get_name() << "\n";
  return true;
}

bool Headmaster::request_course_finished(std::weak_ptr<Professor> &professor, std::string info) {
  if (info.empty()) {
    std::cout << "[REQUEST] Course name is empty\n";
    return false;
  }
  auto prof = professor.lock();
  if (!prof) {
    std::cout << "[REQUEST] Professor is empty or has no course\n";
    return false;
  }
  std::weak_ptr<Course> course = prof->get_current_course();
  auto crs = course.lock();
  if (!crs) {
    std::cout << "[REQUEST] Professor: " << prof->get_name()
              << " has no course\n";
    return false;
  }
  std::shared_ptr<Student> student = shared_pointer_get_by_name(_students, info);
  if (!student) {
    std::cout << "[REQUEST] Student: " << info << " is not a part of the school\n";
    return false;
  }
  auto form = _secretary.createForm(FormType::CourseFinished);
  receiveForm(form);
  auto course_form = std::dynamic_pointer_cast<CourseFinishedForm>(form);
  course_form->set_course(course);
  sign_form(form);
  execute_form(form);
  std::cout << "Headmaster gave student: " << info
            << "a diploma for finishing course: "
            << crs->get_name() << "\n";
  std::weak_ptr<Student> student_weak = student;
  crs->remove_student(student_weak);
  student->graduate(course);
  return true;
}

bool Headmaster::request_classroom_creation(std::weak_ptr<Professor> &professor) {
  auto prof = professor.lock();
  if (!prof) {
    std::cout << "[REQUEST] Professor is empty or has no course\n";
    return false;
  }
  std::weak_ptr<Course> course = prof->get_current_course();
  auto crs = course.lock();
  if (!crs) {
    std::cout << "[REQUEST] Professor: " << prof->get_name()
              << " has no course\n";
    return false;
  }
  auto form = _secretary.createForm(FormType::NeedMoreClassRoom);
  receiveForm(form);
  auto classroom_form = std::dynamic_pointer_cast<NeedMoreClassRoomForm>(form);
  classroom_form->set_course(course);
  sign_form(form);
  execute_form(form);
  std::weak_ptr<Classroom> classroom = add_classroom();
  crs->add_classroom(classroom);
  classroom.lock()->assignCourse(course);
  std::cout << "Headmaster created classroom for course: "
            << crs->get_name() << "\n";
  return true;
}

bool Headmaster::request_course_subscription(std::weak_ptr<Student> &student, std::string info) {
  if (info.empty()) {
    std::cout << "[REQUEST] Course name is empty\n";
    return false;
  }
  if (student.expired()) {
    std::cout << "[REQUEST] Student is empty\n";
    return false;
  }
  auto stud = student.lock();
  auto course = shared_pointer_get_by_name(_courses, info);
  if (!course) {
    std::cout << "[REQUEST] Course: " << info << " does not exist\n";
    return false;
  }
  std::weak_ptr<Course> crs = course;
  if (!course->subscribe(student)) {
    std::cout << "[REQUEST] Student: " << stud->get_name()
              << " cannot subscribe to course: " << info << "\n";
    return false;
  }
  if (!stud->subscribe(crs)) {
    std::cout << "[REQUEST] Student: " << stud->get_name()
              << " cannot subscribe to course: " << info << "\n";
    course->remove_student(student);
    return false;
  }
  auto form = _secretary.createForm(FormType::SubscriptionToCourse);
  receiveForm(form);
  auto course_form = std::dynamic_pointer_cast<SubscriptionToCourseForm>(form);
  course_form->set_course(crs);
  sign_form(form);
  execute_form(form);
  std::cout << "Headmaster subscribed student: " << stud->get_name()
            << " to course: " << info << "\n";
  return true;
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
  for (auto professor :_professors) {
    professor->doClass();
  }
}

void Headmaster::start_class(std::weak_ptr<Professor> &professor) {
  auto prof = professor.lock();
  if (std::find(_professors.begin(), _professors.end(), prof) == _professors.end()) {
    std::cout << "[START CLASS] Professor: " << prof->get_name()
              << " does not belong to this school\n";
    return;
  }
  prof->doClass();
}

void Headmaster::attend_class(std::weak_ptr<Course> &course) {
  auto crs = course.lock();
  if (std::find(_courses.begin(), _courses.end(), crs) == _courses.end()) {
    std::cout << "[ATTEND CLASS] Course: " << crs->get_name()
              << " does not exist in this school\n";
    return;
  }
  for (auto student : _students) {
    student->attendClass(course);
  }
}

void Headmaster::attend_class(std::weak_ptr<Student> &student, std::weak_ptr<Course> &course) {
  auto crs = course.lock();
  if (std::find(_courses.begin(), _courses.end(), crs) == _courses.end()) {
    std::cout << "[ATTEND CLASS] Course: " << crs->get_name()
              << " does not exist in this school\n";
    return;
  }
  auto stud = student.lock();
  if (std::find(_students.begin(), _students.end(), stud) == _students.end()) {
    std::cout << "[ATTEND CLASS] Student: " << stud->get_name()
              << " does not belong to this school\n";
    return;
  }
  stud->attendClass(course);
}