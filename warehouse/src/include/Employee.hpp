#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>


class Employee
{
    private:
        std :: string _name;
        bool busy;
        bool forkliftCertificate;

    public:
    
        Employee(std :: string name, bool forkliftCertificate);
        
        std :: string getName();

        bool getBusy();

        void setBusy(bool busy);

        bool getForkliftCertificate();

        void setForkliftCertificate(bool forkliftCertificate);
};

#endif 