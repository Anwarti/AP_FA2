#include"IContainer.hpp"
#include<string>
#include<iostream>

class Pallet : public IContainer {
    private:
        int itemCount;
        std::string itemName;
        int itemCapacity;

    public:
        Pallet();
        Pallet(std::string itemName, int itemCapacity, int itemCount);

        std::string getItemName();
        int getItemcapacity();
        int getItemCount();
        int getRemainingSpace();
        bool reallocateEmptyPallet(std::string itemName, int itemCapacity);
        bool takeOne();
        bool putOne();
        bool isEmpty() override;
        bool isFull() override;
};
