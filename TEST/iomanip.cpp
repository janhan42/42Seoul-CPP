#include <iostream>
#include <iomanip>

int	main(void)
{
	// 칸 설정하기
	// 한 번에 하나만 가능
	std::cout << "결과 : " << std::setw(10) << 12 << std::endl << std::endl;

	// 칸 지정할 때 공백 채우기
	// setfill()은 한번 설정하면 계속 유지
	std::cout << "결과 : " << std::setw(10) << std::setfill('A') << 12 << std::endl;
	std::cout << "결과 : " << std::setw(10) << 12 << std::endl << std::endl;

	// 진법 설정하기 (8, 10, 16만 가능)
	// setbase()는 한번 설정하면 계속 유지
	std::cout << "결과 : " << std::setbase(8)<< 10 << std::endl;
	std::cout << "결과 : " << 10 << std::endl;
	std::cout << "결과 : " << std::setbase(16)<< 12 << std::endl;
	std::cout << "결과 : " << std::setbase(10)<< 12 << std::endl << std::endl;

	// 부동 소수점 수 유효 숫자 설정하기
	// 부동 소수점 수의 오차로 인해 6부터 확실히 반올림
	// setprecision()은 한번 설정하면 계속 유지
	std::cout << "결과 : " << 10.62 << std::endl;
	std::cout << "결과 : " << std::setprecision(3) << 10.62 << std::endl;
	// .을 제외한 숫자 전체 개수로 판단
	std::cout << "결과 : " << 10.9999 << std::endl;
	std::cout << "결과 : " << std::setprecision(4) << 10.652 << std::endl;
	return (0);
}
