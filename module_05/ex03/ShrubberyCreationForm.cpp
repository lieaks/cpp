#include "ShrubberyCreationForm.hpp"

/* -----------------CONSTRUCTOR-----------------*/
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), m_target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), m_target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec()) {
	*this = src;}

/* -----------------DESTRUCTOR-----------------*/
ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* -----------------OPERATOR-----------------*/
ShrubberyCreationForm & ShrubberyCreationForm::operator= (const ShrubberyCreationForm &rhs) {
	if (this != &rhs)
	{
		m_target = rhs.m_target;
	}
	return *this;}

std::string ShrubberyCreationForm::getTarget() const {
  return m_target;
};

/* -----------------METHOD-----------------*/
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (getSigned() == false)
		throw NotSignedException();
	else if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();
  std::string file_name;
  file_name.append(m_target + "_shrubbery");
	std::ofstream file(file_name.c_str());
	if (!file.is_open())
	 	throw ErrorOpen();
  file << "                                                         ." << std::endl;
  file << "                                            .         ;  " << std::endl;
  file << "               .              .              ;%     ;;   " << std::endl;
  file << "                 ,           ,                :;%  %;   " << std::endl;
  file << "                  :         ;                   :;%;'     .,   " << std::endl;
  file << "         ,.        %;     %;            ;        %;'    ,;" << std::endl;
  file << "           ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
  file << "            %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
  file << "             ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
  file << "              `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
  file << "               `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
  file << "                  `:%;.  :;bd%;          %;@%;'" << std::endl;
  file << "                    `@%:.  :;%.         ;@@%;'   " << std::endl;
  file << "                      `@%.  `;@%.      ;@@%;         " << std::endl;
  file << "                        `@%%. `@%%    ;@@%;        " << std::endl;
  file << "                          ;@%. :@%%  %@@%;       " << std::endl;
  file << "                            %@bd%%%bd%%:;     " << std::endl;
  file << "                              #@%%%%%:;;" << std::endl;
  file << "                              %@@%%%::;" << std::endl;
  file << "                              %@@@%(o);  . '         " << std::endl;
  file << "                              %@@@o%;:(.,'         " << std::endl;
  file << "                          `.. %@@@o%::;         " << std::endl;
  file << "                             `)@@@o%::;         " << std::endl;
  file << "                              %@@(o)::;        " << std::endl;
  file << "                             .%@@@@%::;         " << std::endl;
  file << "                             ;%@@@@%::;.          " << std::endl;
  file << "                            ;%@@@@%%:;;;. " << std::endl;
  file << "                        ...;%@@@@@%%:;;;;,.." << std::endl;
  file.close();
}
