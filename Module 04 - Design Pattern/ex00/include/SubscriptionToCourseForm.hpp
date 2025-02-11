/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SubscriptionToCourseForm.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:36:57 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 16:11:20 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class SubscriptionToCourseForm : public Form {
  private:
  
  public:
    SubscriptionToCourseForm();
    SubscriptionToCourseForm(const SubscriptionToCourseForm &copy);
    SubscriptionToCourseForm &operator=(const SubscriptionToCourseForm &copy);
    ~SubscriptionToCourseForm();
  	void execute();
};
