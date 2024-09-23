/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:41:52 by janhan            #+#    #+#             */
/*   Updated: 2024/09/23 12:41:23 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

/**
 * @brief
 *
 * @tparam T
 * @param num
 */
template <typename T>
void printT(T num)
{
	std::cout << num << std::endl;
}

void	print(int num)
{
	std::cout << num << std::endl;
}

int main(void)
{
	int intArr[5] = {0, 1, 2, 3, 4};
	std::cout << "인스턴스화 된 템플릿 함수" << std::endl;
	iter(intArr, 5, printT<int>);

	float floatArr[5] = {0.1f, 0.2f, 0.3f, 0.4f, 0.5f};
	iter(floatArr, 5, printT<float>);

	std::cout << "함수" << std::endl;
	iter(intArr, 5, print);

	return 0;
}
