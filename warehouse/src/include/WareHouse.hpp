#ifndef WAREHOUSE_HPP
#define WAREHOUSE_HPP

#include "Pallet.hpp"
#include "Shelf.hpp"
#include "Employee.hpp"
#include <vector>
#include <array>


class Warehouse {

    public:
       
       
        std::vector<Employee> employees;
        std::vector<Shelf> shelves;
        Warehouse();
        void addEmployee(const Employee& employee);
        void addShelf(const Shelf& shelf);
        bool rearrangeShelf(Shelf& shelf);
        bool pickItems(const std::string& itemName, int itemCount);
        // bool pickItems(const std::string& itemName, int itemCount);



};
#endif