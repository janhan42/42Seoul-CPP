/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:20:14 by janhan            #+#    #+#             */
/*   Updated: 2024/04/25 07:35:17 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Content.hpp"

# include <iostream>
# include <iomanip>


class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		void	add();
		void	show_content();
		void	shon_content_by_index(int index);
		int		get_count() const;
	private:
		Content _content[8];
		int		_index;
		int		_count;
		void	_print_value(std::string str);
		void	_print_content(int index);
};
#endif
