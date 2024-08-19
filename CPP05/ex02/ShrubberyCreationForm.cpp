/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:02:46 by janhan            #+#    #+#             */
/*   Updated: 2024/08/19 16:30:40 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShurbberyCreationForm::ShurbberyCreationForm(std::string target)
: AForm("ShurbberyCreationForm", 145, 137)
, mTarget(target)
{
}

ShurbberyCreationForm::ShurbberyCreationForm(const ShurbberyCreationForm& other)
: AForm(other)
, mTarget(other.getTarget())
{
}

ShurbberyCreationForm& ShurbberyCreationForm::operator=(const ShurbberyCreationForm& other)
{
	(void)other;
	throw AForm::InvalidOperatorException();
}

ShurbberyCreationForm::~ShurbberyCreationForm()
{
}

void ShurbberyCreationForm::execute(const Bureaucrat& bureaucrat) const
{
	if (bureaucrat.getGrade() > getGradeRequiredToExecute())
		throw AForm::GradeTooLowException();
	if (getSign() == false)
		throw AForm::NotSignedException();

	std::ofstream file((getTarget() + std::string("_shrubbery")).c_str());
	if (file.fail())
		throw ShurbberyCreationForm::FailedToFileOpen();
	file << "                                                         ."					<< std::endl
		 << "                                              .         ;"						<< std::endl
		 << "                 .              .              ;%     ;;"						<< std::endl
		 << "                   ,           ,                :;%  %;"						<< std::endl
		 << "                    :         ;                   :;%;'     .,"				<< std::endl
		 << "           ,.        %;     %;            ;        %;'    ,;"					<< std::endl
		 << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'"					<< std::endl
		 << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'"					<< std::endl
		 << "               ;%;      %;        ;%;        % ;%;  ,%;'"						<< std::endl
		 << "                `%;.     ;%;     %;'         `;%%;.%;'"						<< std::endl
		 << "                 `:;%.    ;%%. %@;        %; ;@%;%'"							<< std::endl
		 << "                    `:%;.  :;bd%;          %;@%;'"								<< std::endl
		 << "                      `@%:.  :;%.         ;@@%;'"								<< std::endl
		 << "                        `@%.  `;@%.      ;@@%;"								<< std::endl
		 << "                          `@%%. `@%%    ;@@%;"									<< std::endl
		 << "                            ;@%. :@%%  %@@%;"									<< std::endl
		 << "                              %@bd%%%bd%%:;"									<< std::endl
		 << "                                #@%%%%%:;;"									<< std::endl
		 << "                                %@@%%%::;"										<< std::endl
		 << "                                %@@@%(o);  . '"								<< std::endl
		 << "                                %@@@o%;:(.,'"									<< std::endl
		 << "                            `.. %@@@o%::;"										<< std::endl
		 << "                               `)@@@o%::;"										<< std::endl
		 << "                                %@@(o)::;"										<< std::endl
		 << "                               .%@@@@%::;"										<< std::endl
		 << "                               ;%@@@@%::;."									<< std::endl
		 << "                              ;%@@@@%%:;;;."									<< std::endl
		 << "                          ...;%@@@@@%%:;;;;,.."								<< std::endl;
	if (file.fail())
		throw ShurbberyCreationForm::FailedToFileWrite();
	file.close();
}

const std::string&	ShurbberyCreationForm::getTarget(void) const
{
	return mTarget;
}

void	ShurbberyCreationForm::setTarget(std::string target)
{
	mTarget = target;
}
