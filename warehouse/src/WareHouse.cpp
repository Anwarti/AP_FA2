    #include "include/WareHouse.hpp"
    #include "include/Employee.hpp"
    #include "include/Shelf.hpp"
    #include "include/Pallet.hpp"
    #include <vector>
    #include <algorithm>

    Warehouse::Warehouse(){
        
    }

    void Warehouse::addShelf(const Shelf& shelf) {
        shelves.push_back(shelf);
    }

    void Warehouse::addEmployee(const Employee& employee) {
        employees.push_back(employee);
    }

    bool Warehouse::rearrangeShelf(Shelf& shelf) {
    // Check if there is a certified and available employee
    auto it = std::find_if(employees.begin(), employees.end(), [](const Employee& employee) {
        return employee.getForkliftCertificate() && !employee.getBusy();
    });

    if (it == employees.end()) {
        // No certified and available employee found
        return false;
    }

    // Mark the employee as busy
    it->setBusy(true);

    // Sort the pallets on the shelf by item count
    std::sort(shelf.getPallets().begin(), shelf.getPallets().end(), [](const Pallet& a, const Pallet& b) {
        return a.getItemCount() < b.getItemCount();
    });

    // Mark the employee as not busy
    it->setBusy(false);

    return true;
}


bool Warehouse::pickItems(const std::string& itemName, int count) {
    // Find a pallet with the requested item
    for (auto& shelf : shelves) {
        for (auto& pallet : shelf.getPallets()) {
            // You will need to implement getName and removeItem methods in Pallet class 
            if (pallet.getName() == itemName && pallet.getItemCount() >= count) {
                pallet.removeItem(count);
                return true;
            }
        }
    }

    // No pallet with enough requested items was found
    return false;
}


