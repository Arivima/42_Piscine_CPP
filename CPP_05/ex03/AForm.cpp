#include "AForm.hpp"

// Constructors
				AForm::AForm() 
				: _name("?"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
	if (DEBUG)
		std::cout << GREEN "[Default Constructor]\t[Form]\t" RESET << *this << RESET << std::endl;
}

				AForm::AForm(const AForm &copy) 
				: _name(copy.getName()), _signed(copy.getSigned()), _gradeToSign(copy.getGradeToSign()), _gradeToExec(copy.getGradeToExec())
{
	if (DEBUG)
		std::cout << GREEN "[Copy Constructor]\t[Form]\t" RESET << *this << RESET << std::endl;
}

				AForm::AForm(std::string name, int gradeToSign, int gradeToExec) 
				: _name(name), _signed(false)
{
	this->setGradeToSign(gradeToSign);
	this->setGradeToExec(gradeToExec);
	if (DEBUG)
		std::cout << GREEN "[Fields Constructor]\t[Form]\t" RESET << *this << RESET << std::endl;
}

// Destructor
				AForm::~AForm()
{
	if (DEBUG)
		std::cout << RED "[Destructor]\t\t[Form]\t" RESET << *this << RESET << std::endl;
}

// Operators
AForm &	AForm::operator=(const AForm &src)
{
    if (DEBUG)
        std::cout << CYAN "[Assignment Operator]\t[Form]\t" RESET << *this;

	this->setGradeToSign(src.getGradeToSign());
	this->setGradeToExec(src.getGradeToExec());
	this->setSigned(src.getSigned());
    if (DEBUG)
		std::cout << " becomes " << *this << std::endl;
	return *this;
}

// Getters 
std::string		AForm::getName() const
{
	return _name;
}
int				AForm::getSigned() const
{
	return _signed;
}
int				AForm::getGradeToSign() const
{
	return _gradeToSign;
}
int				AForm::getGradeToExec() const
{
	return _gradeToExec;
}

// Setters

void			AForm::setSigned(bool s)
{
	this->_signed = s;
	return;
}

void			AForm::setGradeToSign(int gradeToSign)
{
	try
	{
		if (gradeToSign > 150)
		{
			this->_gradeToSign = 150;
			throw AForm::GradeTooLow();
		}
		else if (gradeToSign < 1)
		{
			this->_gradeToSign = 1;
			throw AForm::GradeTooHigh();
		}
		else
			this->_gradeToSign = gradeToSign;
	}
	catch (AForm::GradeTooLow & e)
	{
		std::cerr << BOLDRED ">> Form: " << e.what() << ": Setting grade to Sign to 150" << RESET << std::endl;
	}
	catch (AForm::GradeTooHigh & e)
	{
		std::cerr << BOLDRED ">> Form: " << e.what() << ": Setting grade to Sign to 1" << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << std::endl << BOLDRED ">>" << e.what() << RESET << std::endl;
	}
	return;
}

void			AForm::setGradeToExec(int gradeToExec)
{
	try
	{
		if (gradeToExec > 150)
		{
			this->_gradeToExec = 150;
			throw AForm::GradeTooLow();
		}
		else if (gradeToExec < 1)
		{
			this->_gradeToExec = 1;
			throw AForm::GradeTooHigh();
		}
		else
			this->_gradeToExec = gradeToExec;
	}
	catch (AForm::GradeTooLow & e)
	{
		std::cerr << BOLDRED ">> Form: " << e.what() << ": Setting grade to Exec to 150" << RESET << std::endl;
	}
	catch (AForm::GradeTooHigh & e)
	{
		std::cerr << BOLDRED ">> Form: " << e.what() << ": Setting grade to Exec to 1" << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << std::endl << BOLDRED ">>" << e.what() << RESET << std::endl;
	}
	return;
}

// Stream operators
std::ostream &	operator<<(std::ostream &stream, const AForm &object)
{
	stream << "[" MAGENTA << object.getName() << RESET;
	stream << "\t|signed:" YELLOW << object.getSigned() << RESET;
	stream << "\t|G2Sign:" CYAN  << object.getGradeToSign() << RESET;
	stream << "\t|G2Exec:" BLUE << object.getGradeToExec() << RESET "]";
	return stream;
}

// Functions
void			AForm::beSigned(Bureaucrat const &b)
{
	std::cout << b.getName();
	std::cout << " attempts to sign form "	<< this->getName();
	std::cout << "| bureaucrat grade: "		<< b.getGrade() ;
	std::cout << "| Form min sign grade: "	<< this->getGradeToSign() << std::endl;
	try
	{
		if (b.getGrade() <= this->getGradeToSign())
		{
			if (this->getSigned() == false)
			{
				this->setSigned(true);
			}
			else
			{
				throw AForm::FormSigned();
			}
		}
		else
		{
			throw AForm::GradeTooLow();
		}
		std::cout << GREEN << b.getName() << " signed " << this->getName() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLDRED << b.getName() << " couldn't sign " << this->getName() << " because: " << e.what() << RESET << std::endl;
	}
	return;
}

void			AForm::execute(Bureaucrat const & executor) const
{
	std::cout << executor.getName();
	std::cout << " attempts to execute form " << this->getName();
	std::cout << "| executor grade: " << executor.getGrade() ;
	std::cout << "| Form min exec grade: " << this->getGradeToExec() << std::endl;

	try
	{
		if (executor.getGrade() <= this->getGradeToExec())
		{
			if (this->getSigned() == true)
			{
				this->executeDerived(executor);
			}
			else
			{
				throw AForm::FormNotSigned();
			}
		}
		else
		{
			throw AForm::GradeTooLow();
		}
		std::cout << GREEN << executor.getName() << " executed " << this->getName() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLDRED << executor.getName() << " couldn't execute " << this->getName() << " because: " << e.what() << RESET << std::endl;
	}
	return;
}

