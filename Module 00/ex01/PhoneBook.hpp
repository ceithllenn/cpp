/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvallet <elvallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:51:34 by elvallet          #+#    #+#             */
/*   Updated: 2024/08/28 09:26:59 by elvallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	int		index;
public:
	PhoneBook(void);
	~PhoneBook(void);
	Contact	add_contact(void);
};

#endif