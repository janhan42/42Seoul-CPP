/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:41:52 by janhan            #+#    #+#             */
/*   Updated: 2024/09/02 11:46:52 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

static void printNum(int num)
{
	std::cout << num << std::endl;
}

static void printFloat(float num)
{
	std::cout << num << std::endl;
}

int main(void)
{
	int intArr[5] = {0, 1, 2, 3, 4};
	iter(intArr, 5, printNum);

	float floatArr[5] = {0.1f, 0.2f, 0.3f, 0.4f, 0.5f};
	iter(floatArr, 5, printFloat);

	return 0;
}
