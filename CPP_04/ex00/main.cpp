# include "Animal.class.hpp"
# include "Dog.class.hpp"
# include "Cat.class.hpp"
# include "WrongAnimal.class.hpp"
# include "WrongCat.class.hpp"

int main( void ) 
{
    system("clear");
    std::cout << "------------- STARTING TEST EX00 " << std::endl;
    // Animal, WrongAnimal, Dog, Cat, WrongCat
    // if (DEBUG)
    // {
    //     std::cout << "------------- TEST CONSTRUCTOR " << std::endl;
    //     WrongAnimal Default;
    //     std::cout << "------------- " << std::endl;
    //     WrongAnimal Copy(Default);
    //     std::cout << "------------- = operator " << std::endl;
    //     std::cout << "Default:" << Default;
    //     std::cout << "Copy:  "<< Copy;
    //     Default = Copy;
    //     std::cout << "Default:" << Default;
    //     std::cout << "Copy:  "<< Copy;
    //     std::cout << "------------- << operator " << std::endl;
    //     std::cout << "Default:" << Default;
    //     std::cout << "Copy:   "<< Copy;
    // }

    // {
    //     std::cout << "------------- TEST functions " << std::endl;
    //     Animal Animal;
    //     std::cout << "------------- " << std::endl;
    //     Dog Dog;
    //     std::cout << "------------- " << std::endl;
    //     Cat Cat;
    //     Animal.makeSound();
    //     Dog.makeSound();
    //     Cat.makeSound();
    //     std::cout << "------------- " << std::endl;
    //     WrongAnimal WrongAnimal;
    //     WrongCat WrongCat;
    //     WrongAnimal.makeSound();
    //     WrongCat.makeSound();

    // }
    {
        std::cout << "------------- TEST SUBJECT 1" << std::endl;
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << "= Dog" << std::endl;
        std::cout << i->getType() << "= Cat" << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
    }
    {
        std::cout << "------------- TEST SUBJECT 2" << std::endl;
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();
        std::cout << i->getType() << "= WrongCat" << std::endl;
        i->makeSound();
        meta->makeSound();
    }
    std::cout << "------------- Game over ! " << std::endl;
    return 0;
}
