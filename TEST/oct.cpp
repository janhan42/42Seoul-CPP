#include <iostream>

int	main(void)
{
	// 8 진수로 출력 설정하기
	// 한번 지정하면 계속 유지
	std::oct(std::cout);
	std::cout << "결과 : " << 10 << std::endl << std::endl;

	// 순서대로 8진수, 10진수, 16진수
	// 한번 지정하면 계속 유지
	std::cout << "결과 : " << std::oct << 8 << std::endl;
	std::cout << "결과 : " << std::dec << std::showpos << 9 << std::endl;
	std::cout << "결과 : " << std::hex << 11 << std::endl << std::endl;
	// 16진수 출력 방식
	// 한번  지정하면 계속 유지
	std::cout << "결과 : " << std::showbase << 11 << std::endl;
	std::cout << "결과 : " << std::uppercase << 11 << std::endl << std::endl;

	// 출력 방식 해제
	// 반드시 ios를 밝혀야 함
	std::cout.unsetf(std::ios::hex | std::ios::showpos | std::ios::uppercase);
	std::cout << "결과 : " << 11 << std::endl << std::endl;

	// 출력 방식 설정
	std::cout.setf(std::ios::hex | std::ios::showpos | std::ios::uppercase);
	std::cout << "결과 : " << 11 << std::endl;
	return (0);
}
