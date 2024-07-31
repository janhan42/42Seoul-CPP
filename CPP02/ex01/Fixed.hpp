/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 05:56:41 by janhan            #+#    #+#             */
/*   Updated: 2024/08/01 08:13:19 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

/*

	The previous exerciese was a good start but our class is pretty useless.
	It can only represent the value 0.0.

	Add the following public constructors and public memeber functions to your class:

		- A constructor that takes a constant integer as a parameter.
		It converts it to the corresponding fixed-point value. The fractional bits value is
		initialized to 8 like exercise 00.

		- A constructor that takes a constant floationg-point number as a parameter.
		It converts it to the corresponding fixed-point value. The faractional bits value is
		initialized to 8 like exercise 00.

		- A member function flaot toFloat( void ) const;
		that converts the fixed-point value to a floating-point value.

		- A member function in toInt( void ) const;
		that converts the fixed-point value to an integer value.

	And add the following function to the Fixed class files:
		- An overload of the insertion( << ) operator that inserts a floating-point representation
		of the fixed-point number into the output stream object passed as parameter.

 */

class Fixed
{
	public:
		Fixed();								/* Default constructor */
		Fixed(const Fixed& fixed);				/* Copy constructor */
		Fixed(const int num);					/* Int constructor */
		Fixed(const float num);					/* float constructor */
		Fixed&	operator=(const Fixed& other);	/* Copy assignment operator */
		~Fixed();								/* Destructor */

		int		getRawBits(void) const;			/* Subject function */
		void	setRawBits(const int raw);		/* Subject function */
		float	toFloat(void) const;			/* Subject function */
		int		toInt(void) const;				/* Subject function */
	private:
		int	mValue;								/* integer to store the fixed-point number value */
		static const int mBits = 8;				/* ststic constant integer to store the number of fractional bits*/
		int	mPowInt(int base, int exponent) const;
};

std::ostream&	operator<<(std::ostream &str, const Fixed& fixed); /* overload of the istretion (<<) operator */

/*

	고정 소수점 방식에서 소수부가 8비트일때,
	소수부가 8비트라는 것은 소수점 아래 8비트가 소수 부분을 표현한다는 의미이다,

	예를 들어 고정 소수점 수의 내부 표현이 32비트라면, 그중 상위 24비트가 정수부분
	하위 8비트가 소수 부분을 나타낸다.

	소수부 8비트를 가지는 고정 소수점 수를 이해하기 위해 아래 단계를 따라간다

	1. 이진수 표현
		- 고정 소수점에서 정수부분은 정수의 이진 표현과 같고, 소수 부분은 2의 거듭제곱
		역수의 합으로 표현된다, 예를 들어 소수 0,75는 0.11로 표현된다.
		0.75 * 2 = 1.5 -> 1을 빼고 나머지 0.5
		0.5 * 2 = 1.0 -> 1을 뺴면 나머지 0
		0.11이 된다.
	2. 고정 소수점 변환
		-실수 '42.42'를 고정 소수점으로 변환하려면, 먼저 정수 부분과 소수 부분을 분리
		한다.
		- 정수 부분 42는 이진수로 101010이고, 소수부분 0.42는 이진수로
		0.01101011이다
		- 따라서 고정 소수점으로 저장하면 '101010.01101011'이 된다.
	3. 비트 시프트 . 및저장
		- 내부 저장 방식에서는 전체 수를 8비트 만큼 시프트하여 소수 부분을 정수화 한 후,
		그 값을 정수로 저장한다. 예를들어 '42.42'를 8비트 시프트 하면
		'42.42 * 256 = 10859'가 되고 정수 부분 10859만 저장한다, 즉 내부 값은
		'10859'로 저장 되어 있다.
	4. 복원 및 변환
		- 내부에 저장된 값을 다시 실수로 변환할 때는 8비트 만큼 오른쪽으로 시프트 하여 소수
		부분을 복원한다.
		- 10859 / 256 = 42.421875가 된다, 이 과정에서 약간의 오차가 발생할수 있다.

	여기서 과제에서는 반올림을 사용해서 42.42f로 생성한 c가 Fixed로 생성했을떄의 출력이
	42.4219로 나오게 된다.
 */
