#ifndef HARL_CLASS_H
# define HARL_CLASS_H

# include <iostream>
# include <string>
# include "colors.hpp"

class Harl
{
    public:
                                    Harl(void);
                                    ~Harl(void);

        void                        complain( std::string level );

    private:
        void                        _debug( void );
        void                        _info( void );
        void                        _warning( void );
        void                        _error( void );

        int                         _ftStoi(std:: string str);
        enum                        level {eDebug, eInfo, eWarning, eError};

        // aliasing for readability and usability
        typedef void                (Harl::*HarlFptr)( void ); 
        typedef struct              s_harl_struct
        {
            std::string	name;
            HarlFptr      ptr; 
            // oppure senza typedef // void        (Harl::*fp)(void);
        }	                        t_harl_struct;
        static const t_harl_struct   Harlarray[4];
};

#endif
