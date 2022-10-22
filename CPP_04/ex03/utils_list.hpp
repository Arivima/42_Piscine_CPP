#ifndef         T_LIST_CLASS_HPP
# define        T_LIST_CLASS_HPP

# include       "AMateria.class.hpp"
# include       "types.class.hpp"

// list structure
typedef struct s_list
{
        AMateria        *m;
        struct s_list   *next;
}              t_list;

// list functions
t_list* newNode         (AMateria *m);
void    deleteList      (t_list **head);
t_list* copyList        (t_list **head);
void    addNode         (t_list **head, AMateria *m);
void    printList       (t_list **head, std::string name);

# endif