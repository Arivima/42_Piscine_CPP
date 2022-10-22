# include "Animal.class.hpp"
# include "Dog.class.hpp"
# include "Cat.class.hpp"
# include "Brain.class.hpp"

int main( void ) 
{
    std::cout << "------------- STARTING TEST EX01 " << std::endl;
    // Animal, Dog, Cat, Brain
    // if (DEBUG)
    // {
    //     std::cout << "------------- TEST CONSTRUCTOR " << std::endl;
    //     Animal Default;
    //     std::cout << "------------- " << std::endl;
    //     Animal Copy(Default);
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
    //     std::cout << "------------- " << std::endl;
    //     Animal.makeSound();
    //     Dog.makeSound();
    //     Cat.makeSound();
    // }
    // {
        // std::cout << "------------- TEST LEAKS " << std::endl;
        // Animal *medor = new Dog();
        // std::cout << medor;
        // _delete medor;
    //     std::cout << "------------- TEST ANIMAL ARRAY " << std::endl;
    //     int zoo_size = 4;
    //     Animal *zoo[zoo_size];
    //     Animal *zoo_cpy[zoo_size];
    //     std::cout << CYAN << "creating zoo" RESET << std::endl;
    //     for (int i = 0; i < zoo_size; i++)
    //     {
    //         std::cout << CYAN << "Animal " << i << std::endl;
    //         if (i % 2 == 0)
    //             zoo[i] = new Dog();
    //         else
    //             zoo[i] = new Cat();
    //     }
    //     for (int i = 0; i < zoo_size; i++)
    //         zoo_cpy[i] = new Dog();

    //     std::cout << CYAN << "printing zoo" RESET << std::endl;
    //     for (int i = 0; i < zoo_size; i++)
    //     {
    //         std::cout << CYAN << "Animal " << i << " is a " RESET;
    //         zoo[i]->makeSound();
    //     }
    //     std::cout << CYAN << "printing zoo_cpy" RESET << std::endl;
    //     for (int i = 0; i < zoo_size; i++)
    //     {
    //         std::cout << CYAN << "Animal " << i << " is a " RESET;
    //         zoo_cpy[i]->makeSound();
    //     }

    //     std::cout << CYAN << "reorganizing zoo" RESET << std::endl;
    //     for (int i = 0; i < zoo_size; i++)
    //     {
    //         std::cout << CYAN << "Animal " << i << " | \n" << *zoo_cpy[i] << *zoo[i] << RESET << std::endl;
    //         *zoo_cpy[i] = *zoo[i];
    //     }

    //     std::cout << CYAN << "printing zoo" RESET << std::endl;
    //     for (int i = 0; i < zoo_size; i++) // printing zoo
    //     {
    //         std::cout << CYAN << "Animal " << i << " is a " RESET;
    //         zoo[i]->makeSound();
    //         std::cout << *zoo[i];
    //     }
    //     std::cout << CYAN << "printing zoo_cpy" RESET << std::endl;
    //     for (int i = 0; i < zoo_size; i++)
    //     {
    //         std::cout << CYAN << "Animal " << i << " is a " RESET;
    //         zoo_cpy[i]->makeSound();
    //         std::cout << *zoo_cpy[i];
    //     }

    //     std::cout << CYAN << "deleting zoo" RESET << std::endl;
    //     for (int i = 0; i < zoo_size; i++) 
    //     {
    //         std::cout << CYAN << "Animal " << i << std::endl;
    //         _delete(zoo[i]);
    //     }
    //     std::cout << CYAN << "deleting zoo_cpy" RESET << std::endl;
    //     for (int i = 0; i < zoo_size; i++) 
    //     {
    //         std::cout << CYAN << "Animal " << i << std::endl;
    //         _delete(zoo_cpy[i]);
    //     }
    //     std::cout << std::endl;
    // }
    // {
        // std::cout << "------------- TEST DEEP COPY WITHIN CLASSES" << std::endl;
        // Animal* animal= new Animal();
        // Animal* animal2= new Animal();
        // std::cout << "------------- " << std::endl;
        // Dog* dog = new Dog();
        // Dog* dog2 = new Dog();
        // std::cout << "------------- " << std::endl;
        // Cat* cat = new Cat();
        // Cat* cat2 = new Cat();
        // std::cout << "------------- " << std::endl;

        // std::cout << "------------- Base = Base" << std::endl;
        // animal->makeSound();
        // animal2->makeSound();
        // *animal = *animal2;
        // animal->makeSound();
        // animal2->makeSound();
        // std::cout << "------------- Derived A = Derived A" << std::endl;
        // dog->makeSound();
        // dog2->makeSound();
        // *dog = *dog2;
        // dog->makeSound();
        // dog2->makeSound();
        // std::cout << "------------- Derived B = Derived B" << std::endl;
        // cat->makeSound();
        // cat2->makeSound();
        // *cat = *cat2;
        // cat->makeSound();
        // cat2->makeSound();
        // std::cout << "------------- " << std::endl;
        // _delete(animal);
        // _delete(animal2);
        // _delete(dog);
        // _delete(dog2);
        // _delete(cat);
        // _delete(cat2);
    // }
    // {
    //     std::cout << "------------- TEST DEEP COPY BETWEEN CLASSES" << std::endl;
    //     Animal* animal= new Animal();
    //     std::cout << "------------- " << std::endl;
    //     Dog* dog = new Dog();
    //     std::cout << "------------- " << std::endl;
    //     Cat* cat = new Cat();
    //     std::cout << "------------- " << std::endl;

    //     std::cout << "------------- Base = Derived A" << std::endl;
    //     animal->makeSound();
    //     dog->makeSound();
    //     *animal = *dog;
    //     animal->makeSound();
    //     dog->makeSound();

    //     std::cout << "------------- Derived A = Base" << std::endl;
    //     dog->makeSound();
    //     animal->makeSound();
    //     *dog = *animal;
    //     dog->makeSound();
    //     animal->makeSound();
        
    //     std::cout << "------------- Derived A = Derived B" << std::endl;
    //     dog->makeSound();
    //     cat->makeSound();
    //     *dog = *cat;
    //     dog->makeSound();
    //     cat->makeSound();

    //      std::cout << "------------- " << std::endl;
    //     _delete(animal);
    //     _delete(dog);
    //     _delete(cat);
    // }
    {
        std::cout << "------------- TEST SUBJECT 1 " << std::endl;
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;//should not create a leak
        delete i;        
    }
    std::cout << "------------- Game over ! " << std::endl;
    return 0;
}
