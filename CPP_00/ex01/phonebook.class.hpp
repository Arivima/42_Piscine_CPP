#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
# include "contact.class.hpp"
# include "colors.hpp"

class PhoneBook
{
    public:
                            PhoneBook(void);
                            ~PhoneBook(void);

        std::string         input;
        int                 ftAdd();
        int                 ftSearch();

    private:
        Contact             ContactEntry[8];
        int                 index;

        int                 ftAddContact(int index);
        int                 ftPrintPhoneBook() const ;
        int                 ftPrintContact(int index) const ;
        std::string         ftFormatStr(std::string str) const;
};

#endif
