#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP

# include <iostream>
# include <string>

# include "colors.hpp"

# define IDEAS_NB    100

class Brain
{
    private:
        std::string     _ideas[IDEAS_NB];

    public:
                        Brain          ( void );
                        Brain          ( const Brain& src );
        virtual         ~Brain         ( void );

        std::string     getIdeas        (int i) const;
        void            setIdeas        (std::string ideas, int i);

        Brain &         operator=       ( const Brain & src );

};

std::ostream &      operator<<(std::ostream &o, Brain const &object);


# endif
