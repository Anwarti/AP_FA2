#ifndef WAREHOUSE_HPP
#define WAREHOUSE_HPP

#include "Pallet.hpp"
#include "Shelf.hpp"
#include "Employee.hpp"
#include <vector>
#include <array>


/**
 * @class Warehouse
 * @brief Klasse die een magazijn representeert.
 */
class Warehouse
{
    public:
        std::vector<Employee> employees; ///< De werknemers in het magazijn
        std::vector<Shelf> shelves; ///< De schappen in het magazijn

        /**
         * @brief Standaardconstructor voor Warehouse
         */
        Warehouse();

        /**
         * @brief Voegt een werknemer toe aan het magazijn
         * @param employee De werknemer om toe te voegen
         */
        void addEmployee(const Employee& employee);

        /**
         * @brief Voegt een schap toe aan het magazijn
         * @param shelf Het schap om toe te voegen
         */
        void addShelf(const Shelf& shelf);

        /**
         * @brief Herschikt een schap in het magazijn
         * @param shelf Het schap om te herschikken
         * @return Of het herschikken gelukt is
         */
        bool rearrangeShelf(Shelf& shelf);

        /**
         * @brief Pakt items uit het magazijn
         * @param itemName De naam van de items om te pakken
         * @param itemCount Het aantal items om te pakken
         * @return Of het pakken gelukt is
         */
        bool pickItems(const std::string& itemName, int itemCount);
};


#endif