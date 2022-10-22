#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
# include "colors.hpp"

class Contact
{
    public:
                    Contact(void);
                    ~Contact(void);

        enum        Field {eFirstName, eLastName, eNickname, ePhoneNumber, eDarkestSecret};

        int         ftSetFieldStr(int FieldID, std::string input);
        int         ftResetContact();

        std::string ftGetFieldStr(int FieldID) const;
        std::string ftGetFieldName(int FieldID) const;

        int         ftPrintContact() const;
    
    private:
        std::string FirstName;
        std::string LastName;
        std::string Nickname;
        std::string PhoneNumber;
        std::string DarkestSecret;
};

#endif
