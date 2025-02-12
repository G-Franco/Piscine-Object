/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NeedCourseCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:36:38 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 16:10:51 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class NeedCourseCreationForm : public Form {
  private:
  
  public:
    NeedCourseCreationForm();
    NeedCourseCreationForm(const NeedCourseCreationForm &copy);
    NeedCourseCreationForm &operator=(const NeedCourseCreationForm &copy);
    ~NeedCourseCreationForm();
  	void execute();
};
