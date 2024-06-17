/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:43:53 by janhan            #+#    #+#             */
/*   Updated: 2024/06/16 05:49:19 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

std::string	replaceStr(std::string content, const std::string& search, const std::string& repalce)
{
	size_t	i = 0;
	while (true)
	{
		i = content.find(search, i);
		if (i == std::string::npos)
			break ;
		content = content.substr(0, i) + repalce + content.substr(i + search.length());
		i += repalce.length();
	}
	return (content);
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./replace filename s1 s2." << std::endl;
		return (1);
	}
	if (std::string(av[2]).empty() == true)
	{
		std::cerr << "Error: s1 shouldn't be empty string." << std::endl;
		return (1);
	}
	std::ifstream	file(av[1], std::ios::in | std::ios::out);
	if (file.is_open() == false)
	{
		std::cerr << "Error: Unabel to open file." << std::endl;
		return (1);
	}
	std::ostringstream	stringStraem;
	stringStraem << file.rdbuf();
	file.close();
	std::string content = stringStraem.str();

	content = replaceStr(content, av[2], av[3]);

	std::string	newFile(av[1]);
	newFile.append(".replace");
	std::ofstream	resultFile(newFile.c_str());
	if (!resultFile)
	{
		std::cerr << "Error: Unable to open or create file." << std::endl;
		return (1);
	}
	resultFile << content;
	if (resultFile.fail())
	{
		std::cerr << "Error: Failed to write to the file '" << newFile << "'." << std::endl;
		resultFile.close();
		return (1);
	}
	resultFile.close();
	return (0);
}
