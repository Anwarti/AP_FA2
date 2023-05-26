#include <iostream>
#include "src/include/WareHouse.hpp"
#include "src/include/Employee.hpp"
#include "src/include/Shelf.hpp"
#include "src/include/Pallet.hpp"

int main() {
    // Maak medewerkers aan
    Employee emp1("Pim", true);
    Employee emp2("Mark", false);
    Employee emp3("Toby", true);
    Employee emp4("Piet", false);

    // Maak pallets aan
    Pallet pal1("Banaan", 50, 30);
    Pallet pal2("Peren", 100, 80);
    Pallet pal3("Aardbei", 50, 30);
    Pallet pal4("Peren", 100, 80);


    // Maak een schap aan en voeg pallets toe
    Shelf shelf;
    shelf.getPallets()[0] = pal1;
    shelf.getPallets()[1] = pal2;
    shelf.getPallets()[2] = pal3;
    shelf.getPallets()[3] = pal4;

    // Maak een magazijn aan, voeg medewerkers en schap toe
    Warehouse warehouse;
    warehouse.addEmployee(emp1);
    warehouse.addEmployee(emp2);
    warehouse.addShelf(shelf);

    // Schap herschikken
    if (warehouse.rearrangeShelf(warehouse.shelves[0])) {
        std::cout << "Schap succesvol herschikt!" << std::endl;
    } else {
        std::cout << "Schap herschikken is neit gelukt!" << std::endl;
    }

    // Items ophalen
    if (warehouse.pickItems("Banaan", 10)) {
        std::cout << "Items succesvol opgehaald!" << std::endl;
    } else {
        std::cout << "Items ophalen is misgelukt!" << std::endl;
    }

    return 0;
}
