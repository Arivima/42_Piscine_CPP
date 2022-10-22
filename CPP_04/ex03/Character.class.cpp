# include "Character.class.hpp"

// Constructors, Destructors
                    Character::Character(void) : _name("Default")
{
    for (int i = 0; i < 4; i++)
        this->setInventory(i, nullptr);
    this->wasteList = nullptr;
    if (DEBUG)
        std::cout << GREEN "\t[Character]\t[Default Constructor]" << *this << std::endl;
    return;
}

                    Character::Character(std::string const & name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        this->setInventory(i, nullptr);
    this->wasteList = nullptr;
    if (DEBUG)
        std::cout << GREEN "\t[Character]\t[String Constructor]" << *this << std::endl;
    return;
}

                    Character::Character(const Character & src) : _name(src.getName())
{
    for (int i = 0; i < 4; i++)
        this->setInventory(i, nullptr);
    this->wasteList = nullptr;
    *this = src;
    if (DEBUG)
        std::cout << GREEN "\t[Character]\t[Copy Constructor]" << *this << std::endl;
    return;
}

                    Character::~Character (void)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->getInventory(i) != nullptr)
            _delete(_inventory[i]);
    }
    deleteList(&this->wasteList);
    if (DEBUG)
        std::cout << RED "\t[Character]\t[Destructor]\t" << *this << std::endl;
    return;
}

// Operators
Character &          Character::operator=   (const Character & src)
{
    if (DEBUG)
    {
        std::cout << std::endl << "\t[Character]\t\t[Assignment Operator] [" << this->getName() << "] = [" << src.getName() << "]" << std::endl;
        std::cout << *this << std::endl ;
    }

    this->setName(src.getName());
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Materia #" << i << " [" << this->getInventory(i) << "] = [" << src.getInventory(i) << "]" << std::endl;
        if (this->getInventory(i) != nullptr)
            _delete(this->_inventory[i]);
        AMateria * newm = nullptr;
        if (src.getInventory(i) != nullptr)
            newm = src.getInventory(i)->clone();
        this->setInventory(i, newm);
    }
    {
        std::cout << "Wastelist [" << this->wasteList << "] = [" << src.wasteList << "]" << std::endl;
        if (this->wasteList != nullptr)
            deleteList(&this->wasteList);
        if (src.wasteList != nullptr)
            this->wasteList = copyList((t_list **)&(src.wasteList));
    }
    if (DEBUG)
        std::cout << "\tbecomes " << std::endl << *this << std::endl << std::endl;
    return *this;
}

std::ostream &      operator<<(std::ostream &o, Character const &object)
{
    o << "\t[name: " << object.getName() << "]" << RESET;
    if (object.wasteList != nullptr)
        o << "\t[wastelist: " << GREEN "yes" RESET << "]" << RESET;
    else
        o << "\t[wastelist: " << RED "no" RESET << "]" << RESET;
    for (int i = 0; i < 4; i++)
    {
        if (object.getInventory(i) == nullptr)
        o << "\t[Materia " << i << " : " MAGENTA "empty]" << RESET;
        else
            o << "\t[Materia " << i << " : " << *(object.getInventory(i)) << "]" << RESET;
    }
	return o;
}

// Getters, Setters
std::string const & Character::getName     (void) const
{
    return this->_name;
}

AMateria *          Character::getInventory (int i) const
{
    return this->_inventory[i];
}

void                Character::setName    (std::string const & name)
{
    this->_name.assign(name);
    return;
}

void                Character::setInventory (int i, AMateria * m)
{
    this->_inventory[i] = m;
    return;
}

// functions 
void                Character::equip       (AMateria* m)
{

    if (m != nullptr)
    {
        int i = 0;
        for (i = 0; i < 4; i++)
        {
            if (this->getInventory(i) == nullptr)
            {
                this->setInventory(i, m->clone());
                break;
            }
        }
        if (DEBUG)
        {
            std::cout << "\t[name: " << this->getName() << "]";
            std::cout << "\t[equip]";
            if (i < 4)
                std::cout << "\t[spot :" << i << *(this->_inventory[i]) << "]";
            else 
                std::cout << RED " [inventory already full]" RESET;
            std::cout << RESET << std::endl;
        } 
    }
    else
        std::cout << "\t[Character::equip Wrong input]";
    return;
}

void                Character::unequip     (int idx)
{
    if (idx >= 0 && idx < 4)
    {
        if (this->getInventory(idx) != nullptr)
        {
            if (DEBUG)
            {
                std::cout << "\t[name: " << this->getName() << "]";
                std::cout << "\t[unequip]";
                std::cout << "\t[spot :" << idx << *(_inventory[idx]) << "]";
                std::cout << RESET << std::endl;
            }
            addNode(&this->wasteList, this->getInventory(idx));
            this->setInventory(idx, nullptr);
        }
        else
        std::cout << "\t[Character::unequip: spot already empty]" << std::endl;
    }
    else
        std::cout << "\t[Character::unequip: Wrong input]" << std::endl;
    return;
}

void                Character::use         (int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4)
    {
        if (this->getInventory(idx) != nullptr)
        {
            if (DEBUG)
            {
                std::cout << "\t[name: " << this->getName() << "]";
                std::cout << "\t[use]";
                std::cout << "\t[spot :" << idx << *(_inventory[idx]) << "]";
                std::cout << "\t[on " << target.getName() << "]";
                std::cout << RESET << std::endl;
            }
            this->_inventory[idx]->use(target);
        }
        else
            std::cout << "\t[Character::use: no Materia at this spot]" << std::endl;
    }
    else
        std::cout << "\t[Character::use: Wrong input]" << std::endl;
    return;
}
