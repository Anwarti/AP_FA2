#include "include/Shelf.hpp"
#include "include/Employee.hpp"
#include <vector>


class Warehouse {
    private:
        std::vector<Employee> employees;
        std::vector<Shelf> shelves;

    public:
        Warehouse();

        void addEmployee(Employee& employee);
        void addShelf(Shelf& shelf);
        bool rearrangeShelf(Shelf& shelf);
        bool pickItems(const std::string& itemName, int itemCount);
};
