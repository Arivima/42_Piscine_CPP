# include "utils_list.hpp"

t_list*         newNode(AMateria * m)
{
    t_list * tmp = new t_list();

    std::cout << YELLOW "Adding element to Waste list" RESET << std::endl;
    tmp->m = m;
    tmp->next = nullptr;
    return tmp;
}

void            addNode(t_list **head, AMateria * m)
{
    t_list *tmp = *head;

    if (DEBUG)
        printList(head, "addNode: before newNode");
    if (*head == nullptr)
    {
        if (DEBUG)
            std::cout << YELLOW "Creating Waste list" RESET << std::endl;
        *head = newNode(m);
    }
    else
    {
        while (tmp->next != nullptr)
            tmp = tmp->next;
        (tmp->next) = newNode(m);        
    }
    if (DEBUG)
        printList(head, "addNode: After newNode");
    return;
}

void            deleteList(t_list **head)
{
    if (DEBUG)
        std::cout << YELLOW "Deleting Waste list" RESET << std::endl;
    if (DEBUG)
        printList(head, "deleteList: before delete");

    while (*head != nullptr)
    {
        t_list *next = (*head)->next;
        if ((*head)->m != nullptr)
            _delete((*head)->m);
        _delete((*head));
        (*head) = next; 
    }
    if (DEBUG)
        printList(head, "deleteList: after delete");
    return;
}

t_list*         copyList(t_list **head)
{
    t_list  *tmp        = *head;
    t_list  *newList    = nullptr;
    t_list  *newHead    = nullptr;

    if (DEBUG)
        std::cout << YELLOW "Copying Waste list" RESET << std::endl;
    if (DEBUG)
    {
        printList(head, "copyList: Source before copy");
        printList(&newList, "copyList: Dest before copy");
    }

    if (*head == nullptr)
        return nullptr;

    newList = newNode(((*head)->m)->clone());
    newHead = newList;

    if ((*head)->next == nullptr)
        return newHead;

    while (tmp->next != nullptr)
    {
        newList->next = newNode(((tmp->next)->m)->clone());
        newList = newList->next;
        tmp = tmp->next; 
    }


    if (DEBUG)
    {
        printList(head, "copyList: Source after copy");
        printList(&newHead, "copyList: Dest after copy");
    }
    return newHead;
}

void            printList(t_list **head, std::string name)
{
    int         i       = 0;
    t_list      *tmp    = *head;

    std::cout << BLUE "|---Printing Waste List---| " RESET YELLOW << name << RESET BLUE;
    if (tmp == nullptr)
        std::cout << RED "\nNo list at this location\t| *head (" << tmp << ")" RESET ;
    while (tmp)
    {
        std::cout << BLUE "\n#" << i << " ";
        std::cout << "\t| (" << tmp << ") ";
        std::cout << "\t| m (" << tmp->m << ") ";
        if (tmp->next)
            std::cout << "\t| next (" << tmp->next << ") ";
        else
            std::cout << "\t| next (" << tmp->next << ")\t\t";
        if (tmp->m)
            std::cout << "\t| *m " << *(tmp->m);
        else
            std::cout << "\t| NO *m ";

        tmp = tmp->next; 
        i++;
    }
    std::cout << BLUE "\n|---End of print---|" RESET << std::endl;
    return;
}
