/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:43:53 by janhan            #+#    #+#             */
/*   Updated: 2024/07/29 11:52:17 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

/*

	Create a program that takes three parameters in the following order:
	a filename and tow strings, s1 and s2

	It will opne the file <filename> and copies its content into a new file <filename>.replace
	replacing every occurrence of s1 with s2.

	Using C file mamipulations is forbidden and will be considered cheating.
	All the member functions of the class std::string are allowd, excpt replace.
	Use them wisely!

	Of course, handle unexpected inputs and errors, You have to create and turn in
	your own test to ensure you program woks as expected.

 */

std::string	replaceString(std::string content, const std::string& search, const std::string& repalce)
{
	size_t pos = 0;
	while ((pos = content.find(search, pos)) != std::string::npos) /* std::string::find함수를 실행후 std::string::npos가 아닐때 즉 우리가 찾고싶은 search를 찾았을때 */
	{
		content.replace(pos, search.length(), repalce); /* std::string::replace를 사용해서 변경 */
		pos += repalce.length(); /* pos를 search.length만큼 이동 */
	}
	return (content);
}
/*
	인자로 filename s1 s2가 들어온다.
	s1을 s2로 교체해서 <filename>.replace로 내보낸다
 */
int	main(int ac, char **av)
{
	if (ac != 4) /* 프로그램 실행 사용법에 맞게 인자가 들어왔는지 체크한다 */
	{
		std::cerr << "Usage: ./replace filename s1 s2." << std::endl;
		return (1);
	}
	if (std::string(av[2]).empty() == true) /* 교체할 s1이 비어있게 들어왔는지 체크한다 */
	{
		std::cerr << "Error: s1 shouldn't be empty string." << std::endl;
		return (1);
	}
	std::ifstream	file(av[1], std::ios::in | std::ios::out); /* ifstream으로 읽어들일 파일을 읽기 쓰기 둘다로 열어준다. */
	if (file.is_open() == false) /* ifstream이 정상적으로 들어왔는지 체크 한다. */
	{
		std::cerr << "Error: Unabel to open file." << std::endl;
		return (1);
	}
	std::ostringstream	stringStraem;
	stringStraem << file.rdbuf(); /* ifstream으로 열어준 내용을 ostringstream에 전부 백업해준다. */
	file.close(); /* 필요 없어진 file을 close한다 */
	std::string content = stringStraem.str(); /* content에 stringStream의 문자열 전부를 string 객체로 넣어준다 */

	content = replaceString(content, av[2], av[3]); /* 불러온 문자열에서 s1 을 s2로 바꾸는 함수 */

	std::string	newFile(av[1]); /* 새로운 파일의 이름 */
	newFile.append(".replace"); /* append로 뒤에 .replace를 붙여줌 */
	std::ofstream	resultFile(newFile.c_str(), std::ios_base::trunc); /* c++ 98버전에서는 const char *를 요구하기 떄문에 c_str로 넣어준다 */
	/* ofstream의 기본적으로 동일한 이름의 파일이 있을때 trunc로 작동하는데 명시적으로 써주는게 좋을까? */
	if (!resultFile) /* ofstream 실패 처리 */
	{
		std::cerr << "Error: Unable to open or create file." << std::endl;
		return (1);
	}
	resultFile << content; /* 변경된 내용을 resultFile에 작성 */
	if (resultFile.fail()) /* fail함수를 사용해서 failbit, badbit, eofbit을 동시에 확인해서 입력에 실패했는지 확인 */
	{
		std::cerr << "Error: Failed to write to the file '" << newFile << "'." << std::endl;
		resultFile.close(); /* resultFile을 close */
		return (1);
	}
	resultFile.close(); /* resultFile을 close */
	return (0);
}
