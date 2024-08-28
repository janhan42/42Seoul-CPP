/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 00:25:21 by janhan            #+#    #+#             */
/*   Updated: 2024/08/29 00:29:07 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Data.h"
#include "Serializer.hpp"

int main(void)
{
	{
		Data* myData = new Data;
		myData->data = 42;
		std::uintptr_t ptr = Serializer::serialize(myData);
		Data* myDataCopy = Serializer::deserialize(ptr);
		std::cout << "myData: "  << myData->data << std::endl;
		std::cout << "myDataCopy: " << myDataCopy->data << std::endl;
		myDataCopy->data = 20;
		std::cout << "myData: " << myData->data << std::endl;
		std::cout << "myDataCopy: " << myDataCopy->data << std::endl;
		delete myData;
	}
	return 0;
}
