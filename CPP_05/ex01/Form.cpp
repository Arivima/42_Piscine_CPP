#include "Form.hpp"

// Constructors
				Form::Form() 
				: _name("?"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
	if (DEBUG)
		std::cout << GREEN "[Default Constructor]\t[Form]\t" RESET << *this << RESET << std::endl;
}

				Form::Form(const Form &copy) 
				: _name(copy.getName()), _signed(copy.getSigned()), _gradeToSign(copy.getGradeToSign()), _gradeToExec(copy.getGradeToExec())
{
	if (DEBUG)
		std::cout << GREEN "[Copy Constructor]\t[Form]\t" RESET << *this << RESET << std::endl;
}

				Form::Form(std::string name, int gradeToSign, int gradeToExec) 
				: _name(name), _signed(false)
{
	this->setGradeToSign(gradeToSign);
	this->setGradeToExec(gradeToExec);
	if (DEBUG)
		std::cout << GREEN "[Fields Constructor]\t[Form]\t" RESET << *this << RESET << std::endl;
}

// Destructor
				Form::~Form()
{
	if (DEBUG)
		std::cout << RED "[Destructor]\t\t[Form]\t" RESET << *this << RESET << std::endl;
}

// Operators
Form &	Form::operator=(const Form &src)
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
std::string		Form::getName() const
{
	return _name;
}
int				Form::getSigned() const
{
	return _signed;
}
int				Form::getGradeToSign() const
{
	return _gradeToSign;
}
int				Form::getGradeToExec() const
{
	return _gradeToExec;
}

// Setters

void			Form::setSigned(bool s)
{
	this->_signed = s;
	return;
}

void			Form::setGradeToSign(int gradeToSign)
{
	try
	{
		if (gradeToSign > 150)
		{
			_gradeToSign = 150;
			throw Form::GradeTooLow();
		}
		else if (gradeToSign < 1)
		{
			_gradeToSign = 1;
			throw Form::GradeTooHigh();
		}
		else
			this->_gradeToSign = gradeToSign;
	}
	catch (Form::GradeTooLow & e)
	{
		std::cerr << BOLDRED ">> Form: " << e.what() << ": Setting grade to Sign to 150" << RESET << std::endl;
	}
	catch (Form::GradeTooHigh & e)
	{
		std::cerr << BOLDRED ">> Form: " << e.what() << ": Setting grade to Sign to 1" << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << std::endl << BOLDRED ">>" << e.what() << RESET << std::endl;
	}
	return;
}

void			Form::setGradeToExec(int gradeToExec)
{
	try
	{
		if (gradeToExec > 150)
		{
			_gradeToExec = 150;
			throw Form::GradeTooLow();
		}
		else if (gradeToExec < 1)
		{
			_gradeToExec = 1;
			throw Form::GradeTooHigh();
		}
		else
			this->_gradeToExec = gradeToExec;
	}
	catch (Form::GradeTooLow & e)
	{
		std::cerr << BOLDRED ">> Form: " << e.what() << ": Setting grade to Exec to 150" << RESET << std::endl;
	}
	catch (Form::GradeTooHigh & e)
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
std::ostream &	operator<<(std::ostream &stream, const Form &object)
{
	stream << "[" MAGENTA << object.getName() << RESET;
	stream << "\t|signed:" YELLOW << object.getSigned() << RESET;
	stream << "\t|G2Sign:" CYAN  << object.getGradeToSign() << RESET;
	stream << "\t|G2Exec:" BLUE << object.getGradeToExec() << RESET "]";
	return stream;
}

// Functions
void			Form::beSigned(Bureaucrat &b)
{
	std::cout << "Signing attempt : Bureaucrat grade: " << b.getGrade() << " | Form minimum grade to be signed: " << this->getGradeToSign() << std::endl;
	try
	{
		if (b.getGrade() <= this->getGradeToSign())
		{
			if (this->getSigned() == false)
			{
				this->setSigned(true);
				b.signForm(*this, "");
			}
			else
			{
				throw "Form is already signed";
			}
		}
		else
		{
			throw Form::GradeTooLow();
		}
	}	
	catch (Form::GradeTooLow & e)
	{
		b.signForm(*this, e.what());
	}
	catch (char const* err)
	{
		b.signForm(*this, err);
	}
	catch (std::exception& e)
	{
		b.signForm(*this, e.what());
	}
	return;
}
