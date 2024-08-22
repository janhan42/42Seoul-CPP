/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:02:46 by janhan            #+#    #+#             */
/*   Updated: 2024/08/23 03:23:09 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137)
, mTarget(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other)
, mTarget(other.getTarget())
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	(void)other;
	throw AForm::InvalidOperatorException();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const
{
	if (bureaucrat.getGrade() > getGradeRequiredToExecute())
		throw AForm::GradeTooLowException();
	if (getSign() == false)
		throw AForm::NotSignedException();

	std::ofstream file((getTarget() + std::string("_shrubbery")).c_str());
	if (file.fail())
		throw ShrubberyCreationForm::FailedToFileOpen();
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
		throw ShrubberyCreationForm::FailedToFileWrite();
	file.close();
}

const std::string&	ShrubberyCreationForm::getTarget(void) const
{
	return mTarget;
}

void	ShrubberyCreationForm::setTarget(std::string target)
{
	mTarget = target;
}
