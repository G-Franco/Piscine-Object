/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CourseFinishedForm.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:35:55 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 16:01:55 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class CourseFinishedForm : public Form {
  private:
  
  public:
    CourseFinishedForm();
    CourseFinishedForm(const CourseFinishedForm &copy);
    CourseFinishedForm &operator=(const CourseFinishedForm &copy);
    ~CourseFinishedForm();
  	void execute();
};
