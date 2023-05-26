#include "include/WareHouse.hpp"

#include <array>

#include <vector>

Warehouse::Warehouse(){
}

void Warehouse::addShelf(const Shelf& shelf) {
    shelves.push_back(shelf);
}

void Warehouse::addEmployee(const Employee& employee) {
    employees.push_back(employee);
}


bool Warehouse::rearrangeShelf(Shelf& shelf) {


    for (Employee& emp : employees) {
        if (!emp.getBusy() && emp.getForkliftCertificate()) {


            emp.setBusy(true);


            auto& pallets = shelf.getPallets();


            for (std::size_t i = 0; i < pallets.size() - 1; i++) {
                std::size_t minIndex = i;

                for (std::size_t j = i + 1; j < pallets.size(); j++) {
                    if (pallets[j].getItemCount() < pallets[minIndex].getItemCount()) {
                        minIndex = j;
                    }
                }

        
                if (minIndex != i) {
                    shelf.swapPallet(i, minIndex);
                }
            }


            emp.setBusy(false);

            return true;
        }
    }


    return false;
    }

bool Warehouse::pickItems(const std::string& itemName, int itemCount) {
    std::cout << "Picking items: " << itemName << ", " << itemCount << std::endl;

    for (Shelf& shelf : shelves) {
        for (Pallet& pallet : shelf.getPallets()) {
            std::cout << "contrleer pallet: " << pallet.getItemName() << ", " << pallet.getItemCount() << std::endl;

            if (pallet.getItemName() == itemName && itemCount > 0) {
                std::cout << "kies item uit het pallet: " << pallet.getItemName() << std::endl;
                std::cout << "aantal huidig items: " << pallet.getItemCount() << std::endl;

                while (pallet.takeOne() && itemCount > 0) {
                    std::cout << "neem één item van uit het pallet" << std::endl;
                    itemCount--;
                }

                std::cout << "bijgewerkte aantal items: " << pallet.getItemCount() << std::endl;
            }

            if (itemCount == 0) {
                return true;
            }
        }
    }

    return false;
}




