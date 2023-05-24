#include "include/WareHouse.hpp"
#include "include/Employee.hpp"
#include "../src/include/Employee.hpp" 

Warehouse::Warehouse() {}

void Warehouse::addEmployee(const Employee& employee) {
    employees.push_back(employee);
}

void Warehouse::addShelf(const Shelf& shelf) {
    shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf& shelf) {
    // Check if there is an available employee with forkliftCertificate
    bool employeeAvailable = false;
    for (const auto& employee : employees) {
        if (employee.getForkliftCertificate() && !employee.getBusy()) {
            employeeAvailable = true;
            employee.setBusy(true);
            break;
        }
    }

    if (!employeeAvailable) {
        return false; // No available employee with forkliftCertificate
    }

    // Rearrange the pallets on the shelf
    bool rearranged = shelf.rearrangePallets();
    if (rearranged) {
        // Release the employee once the rearrangement is done
        for (auto& employee : employees) {
            if (employee.getBusy()) {
                employee.setBusy(false);
                break;
            }
        }
    }

    return rearranged;
}

bool Warehouse::pickItems(const std::string& itemName, int itemCount) {
    int remainingCount = itemCount;

    // Iterate over all shelves
    for (auto& shelf : shelves) {
        // Iterate over all pallets on the shelf
        for (auto& pallet : shelf.getPallets()) {
            if (pallet.getItemName() == itemName) {
                while (remainingCount > 0 && pallet.takeOne()) {
                    remainingCount--;
                }
            }

            if (remainingCount == 0) {
                return true; // All items have been picked
            }
        }
    }

    return false; // Not enough items of the specified itemName available
}
