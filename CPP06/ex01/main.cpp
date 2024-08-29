/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 00:25:21 by janhan            #+#    #+#             */
/*   Updated: 2024/08/29 16:09:29 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Data.h"
#include "Serializer.hpp"

int main(void)
{
	Data originalData;
	originalData.data = 42;
	std::cout << "Original Data Address: " << &originalData << std::endl;

	uintptr_t raw = Serializer::serialize(&originalData);
	std::cout << "Serialized Address(uinptr_t): " << raw << std::endl;

	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized Address: " << deserializedData << std::endl;

	if (deserializedData == &originalData)
	{
		std::cout << "Success! The deserialized pointer matches the original pointer" << std::endl;
		std::cout << "Data data: " << deserializedData->data << std::endl;
		std::cout << "originalData: " << originalData.data << std::endl;
	}
	else
	{
		std::cout << "Error!" << std::endl;
	}

	return 0;
}
