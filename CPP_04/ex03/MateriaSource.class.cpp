# include "MateriaSource.class.hpp"

// Constructors, Destructors
                MateriaSource::MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
		this->_materias[i] = nullptr;
    if (DEBUG)
        std::cout << GREEN "\t[MateriaSource]\t\t[Default Constructor]" RESET << std::endl;
    return;
}

                MateriaSource::MateriaSource(const MateriaSource & src)
{
    *this = src;
    if (DEBUG)
        std::cout << GREEN "\t[MateriaSource]\t\t[Copy Constructor]" RESET << std::endl;
    return;
}

                MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
	{
        if (this->_materias[i] != nullptr)
			_delete(this->_materias[i]);
    }
    
    if (DEBUG)
        std::cout << RED "\t[MateriaSource]\t\t[Destructor]\t" RESET << std::endl;
    return;
}

// Operators
MateriaSource & MateriaSource::operator=   (const MateriaSource & src)
{
    if (DEBUG)
        std::cout << "\t[MateriaSource]\t\t[Assignment Operator]";

    for (int i = 0; i < 4; i++)
	{
        if (this->_materias[i] != nullptr)
			_delete(this->_materias[i]);
		if (src._materias[i] == nullptr)
			this->_materias[i] = nullptr;
		else
			this->_materias[i] = src._materias[i]->clone();        
    }
    
    return *this;
}

std::ostream &      operator<<(std::ostream &o, MateriaSource const &object)
{
    for (int i = 0; i < 4; i++)
    {
        if (object.getMateria(i)  == nullptr)
            o << "\t[Materia " << i << " : " MAGENTA "empty]" << RESET;
        else
            o << "\t[Materia " << i << " : " << *(object.getMateria(i)) << "]" << RESET;
    }
	return o;
}

// Getter setters
AMateria *      MateriaSource::getMateria (int i) const
{
    return this->_materias[i];
}

void            MateriaSource::setMateria (int i, AMateria * m)
{
    this->_materias[i] = m;
    return;
}


// functions
void            MateriaSource::learnMateria    (AMateria* materia)
{
	int err = 0;

    if (materia != nullptr)
	{
		for (int i = 0; i < 4; i++)
		{
            if (this->_materias[i] == nullptr)
			{
                this->_materias[i] = materia->clone();
                break;
            }
            else
                err++;
        }
        if (err == 4)
            std::cout << RED "[learnMateria: MateriaSource database already full]" RESET << std::endl;
	}
    else
        std::cout << RED "[learnMateria: Wrong input]" RESET << std::endl;
    return;
}

AMateria*       MateriaSource::createMateria   (std::string const & type)
{
	if (type.empty() == false)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->_materias[i] != nullptr)
            {
                if (this->_materias[i]->getType().compare(type) == 0)
                    return this->_materias[i]->clone();
            } 

        }
        std::cout << RED "[createMateria: No type match in MateriaSource database]" RESET << std::endl;
        return 0;
    }
    else
        std::cout << RED "[createMateria: Wrong input]" RESET << std::endl;
    return nullptr;
}