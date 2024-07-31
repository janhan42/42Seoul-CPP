/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 06:05:23 by janhan            #+#    #+#             */
/*   Updated: 2024/08/01 08:12:34 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
: mValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}
/*
	복사 생성자(Copy Constructor)에서 대입 연산자 '='를 호출해서 초기화 하는 것보다
	초기화 목록을 사용하는게 효율이 좋다.
	1. 효율성
		- 초기화 목록을 사용하면 객체가 생성될 떄 바로 원하는 값으로 초기화된다.
		대입 연산자를 호출하느 방식은 먼저 객체를 기본 생성자로 초기화한 . 후대입 연산을
		수행하므로, 초기화 목록을 사용하는 것보다 비효율 적이다.
	2. 명확성
		- 초기화 목록을 사용하면 멤버 변수가 복사 생성자를 통해 어떻게 초기화되는지 명확히
		알수 있고 코드의 가독성을 높이고 유지보수를 용이하게 만든다.
 */
Fixed::Fixed(const Fixed& fixed)
: mValue(fixed.mValue)	// 초기화 목록 사용
{
	std::cout << "Copy constructor called" << std::endl;
}

/*
	복사 대입 연산자 (Copy Assingment Operator)
	주의할 점
	1. 자기 대입 방지
		- 자기 대입을 방지하기 위해 'if(tihs != &other)' 조건문을 사용해야 한다.
		이를 통해 불필요한 작업을 피할 수있다.
	2. 리소스 관리
		- 대입 연산자에서는 새로운 값을 할당하기 전에 기존 자원을 적절히 해제해야한다.
		그렇지 않으면 메모리 누수나 기타 리소스 문제가 발생할수있다.
		- 예를 들어, 포인터를 사용하는경우 'delete'를 호출하여 기존 메모리를 하제한 후
		새로운 메모리를 할당해야한다.
	3. 자기 자신을 반환
		- 대입 연산자는 일반적으로 '*this'를 반환한다. 이는 연산자 체이닝을 가능하게 한다.
 */
Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) // 자기 대입 방지.
		mValue = other.getRawBits();
	// mBit는 static const이므로 모든 객체가 동일한 값을 가지며 대입할 필요가 없음
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (mValue);
}

void	Fixed::setRawBits(const int raw)
{
	mValue = raw;
}
