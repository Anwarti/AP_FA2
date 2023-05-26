#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>


/**
 * @class Employee
 * @brief Klasse die een werknemer representeert.
 */
class Employee
{
    private:
        std :: string _name; ///< Naam van de werknemer
        bool busy; ///< Geeft aan of de werknemer momenteel bezig is
        bool forkliftCertificate; ///< Geeft aan of de werknemer een heftruckcertificaat heeft

    public:
    
        /**
         * @brief Constructor voor Employee
         * @param name De naam van de werknemer
         * @param forkliftCertificate Of de werknemer een heftruckcertificaat heeft
         */
        Employee(std :: string name, bool forkliftCertificate);
        
        /**
         * @brief Verkrijgt de naam van de werknemer
         * @return De naam van de werknemer
         */
        std :: string getName();

        /**
         * @brief Controleert of de werknemer momenteel bezig is
         * @return Of de werknemer momenteel bezig is
         */
        bool getBusy();

        /**
         * @brief Stelt in of de werknemer momenteel bezig is
         * @param busy Of de werknemer momenteel bezig is
         */
        void setBusy(bool busy);

        /**
         * @brief Verkrijgt of de werknemer een heftruckcertificaat heeft
         * @return Of de werknemer een heftruckcertificaat heeft
         */
        bool getForkliftCertificate();

        /**
         * @brief Stelt in of de werknemer een heftruckcertificaat heeft
         * @param forkliftCertificate Of de werknemer een heftruckcertificaat heeft
         */
        void setForkliftCertificate(bool forkliftCertificate);
};


#endif 