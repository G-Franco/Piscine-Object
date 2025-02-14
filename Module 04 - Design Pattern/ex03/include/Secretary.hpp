/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Secretary.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:38:38 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/13 17:14:33 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Staff.hpp"
#include "CourseFinishedForm.hpp"
#include "NeedMoreClassRoomForm.hpp"
#include "NeedCourseCreationForm.hpp"
#include "SubscriptionToCourseForm.hpp"

class Secretary : public Staff {
  private:
    std::vector<std::shared_ptr<Form> > _form_archive;
    Secretary();
  
  public:
    Secretary(std::string p_name);
    Secretary(const Secretary &copy);
    Secretary &operator=(const Secretary &copy);
    ~Secretary();
  	std::shared_ptr<Form> createForm(FormType p_formType);
  	void archiveForm(std::shared_ptr<Form> p_form);
    int get_archive_size() const;
};
