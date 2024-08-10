/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:33:14 by janhan            #+#    #+#             */
/*   Updated: 2024/08/10 16:31:14 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>

/*

	For every exercise, you have to provide the most complete tests you can.
	Constructor and destructor of each class must display specific messages. Don't use the
	same message for all classes.

	Start by implementing a simple base class called Animal. It has one protected atrribute:
		- std::string type;

	Implement a Dog class that inherits from Animal.
	Implement a Cat class that inherits from Animal.

	These two derived classes must set their type field depending on their name. Then,
	the Dog's type will be initialized to "Dog", and the Cat's type will be initialized to "Cat".
	The type of the Animal class can be left empty or set to the value of your choice.

	Every animal must be able to use the member function:
	makeSound()
	It will print an appropriate sound (cats don't bark)

	To ensure you understood how it works, inplement a WrongCat class that inherits from a
	WrongAnimal class. If you replace the Animal and the Cat by the wrong ones in the code above,
	the WrongCat should output the WrongAnimal sound.

	Implement and turn in more tests than the ones given above.

	-------------------------------------------------------------------------

	이 문제는 C++에서 상속과 다형성에 대한 이해를 돕기 위한 것입니다. 주어진 치침을 따라 'Animal' 클래스를 기본 클래스로 구현하고, 이를
	상속 받는 'Dog'와 'Cat'클래스, 그리고 'WrongAnimal'과 'WrongCat'클래스를 구현하는 것을 요구합니다.

	요구 사항 요약:
		1. Animal 클래스 구현:
			- std::string type이라는 보호된 속성을 가지는 'Animal' 클래스를 구현합니다.
			- 이 클래스의 생성자와 소멸자는 각각 고유한 메시지를 출력해야 합니다.

		2. Dog 및 Cat 클래스 구현:
			- 'Dog'클래스와 'Cat'클래스를 'Animal' 클래스로부터 상속받아 구현합니다.
			- 각각의 생성자에서 'type'필드를 'Dog'와 'Cat'으로 설정합니다.
			- 각 클래스는 자신에게 맞는 소리를 출력하는 makeSound() 라는 멤버 함수를 구현합니다.
			- 이 클래스들의 생성자와 소멸자도 고유한 메세지를 출력해야합니다.

		3. 다형성 테스트:
			- main함수에서 Animal클래스 포인터로 'Dog'와 'Cat' 개체를 생성하고, getType()과 makeSound()
			함수를 호출하여 각각의 클래스가 각각의 클래스가 올바른 소리와 타입을 출력하는지 확인합니다.

		4. WrongAnimal 및 WrongCat 클래스 구현:
			- WrongAnimal 클래스를 구현하고, 이를 상속받아 WrongCat클래스를 구현합니다.
			- 이 클래스들의 생성자와 소멸자 역시 고유한 메세지를 출력해야합니다.
			- WrongCat은 Wrong

 */

class Animal
{
	public:
		Animal();									/* Constructor */
		Animal(std::string type);					/* Constructor by type */
		Animal(const Animal& other);				/* Copy Constructor */
		Animal&	operator=(const Animal& othre);		/* Copy Assignment Constructor */
		virtual	~Animal();							/* Destructor */

		virtual void	makeSound(void) const;		/* Subject Function makeSound(void) */
		std::string		getType(void) const;		/* Subject Function getType(void) */
	protected:
		std::string mType;
};
