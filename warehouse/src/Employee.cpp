#include "include/Employee.hpp"

Employee :: Employee(std :: string name, bool forkliftCertificate) :
_name(name), forkliftCertificate(forkliftCertificate), busy(false){}

std :: string Employee :: getName()
{
    return _name;
}


bool Employee :: getBusy()
{
    return busy;
}

void Employee :: setBusy(bool isBusy)
{
    busy = isBusy;
}  

bool Employee :: getForkliftCertificate()
{
    return forkliftCertificate;
}

void Employee :: setForkliftCertificate(bool forkliftCertificate)
{
    this -> forkliftCertificate = forkliftCertificate;
};