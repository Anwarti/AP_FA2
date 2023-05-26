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
    for (Shelf& shelf : shelves) {
        for (Pallet& pallet : shelf.getPallets()) {
            if (pallet.getItemName() == itemName && itemCount > 0) {
                while (pallet.takeOne() && itemCount > 0) {
                    itemCount--;
                }
            }
            if (itemCount == 0) {
                return true;
            }
        }
    }
    return false;
}



