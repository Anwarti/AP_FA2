#include "include/WareHouse.hpp"
#include <vector>
#include <algorithm>

 

void Warehouse::addShelf(const Shelf& shelf) {
    shelves.push_back(shelf);
}

void Warehouse::addEmployee(const Employee& employee) {
    employees.push_back(employee);
}

bool Warehouse::rearrangeShelf(Shelf& shelf) {
    // Check if there is a certified and available employee
    auto it = std::find_if(employees.begin(), employees.end(), [](const Employee& employee) {
        return employee.isCertified() && !employee.isBusy();
    });

    if (it == employees.end()) {
        // No certified and available employee found
        return false;
    }

    // Mark the employee as busy
    it->setBusy(true);

    // Sort the pallets on the shelf by item count
    std::sort(shelf.pallets.begin(), shelf.pallets.end(), [](const Pallet& a, const Pallet& b) {
        return a.getItemCount() < b.getItemCount();
    });

    // Mark the employee as not busy
    it->setBusy(false);

    return true;
}

bool Warehouse::pickItem(const std::string& itemName, int count) {
    // Find a pallet with the requested item
    for (auto& shelf : shelves) {
        for (auto& pallet : shelf.pallets) {
            if (pallet.getName() == itemName && pallet.getItemCount() >= count) {
                pallet.removeItem(count);
                return true;
            }
        }
    }

    // No pallet with enough requested items was found
    return false;
}
