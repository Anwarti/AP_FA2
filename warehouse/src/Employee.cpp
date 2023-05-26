#include "include/Employee.hpp"


Employee::Employee(std::string name, bool forkliftCertificate)
    : _name(name), busy(false), forkliftCertificate(forkliftCertificate){}

std::string Employee::getName() 
{
    return _name;
}

bool Employee::getBusy()
{
    return busy;
}

void Employee::setBusy(bool busy)
{
    this->busy = busy;
}

bool Employee::getForkliftCertificate() 
{
    return forkliftCertificate;
}

void Employee::setForkliftCertificate(bool forkliftCertificate)
{
    this->forkliftCertificate = forkliftCertificate;
}


