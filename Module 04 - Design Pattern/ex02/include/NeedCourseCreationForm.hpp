/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NeedCourseCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:36:38 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/13 17:21:10 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class NeedCourseCreationForm : public Form {
  private:
    std::string _course_name;
  
  public:
    NeedCourseCreationForm();
    NeedCourseCreationForm(const NeedCourseCreationForm &copy);
    NeedCourseCreationForm &operator=(const NeedCourseCreationForm &copy);
    ~NeedCourseCreationForm();
    void set_course_name(std::string course_name);
    void sign();
  	void execute();
};
