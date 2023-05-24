#include"include/Pallet.hpp"

Pallet::Pallet(int itemCount, std::string itemName, int itemCapacity)
    : itemCount(itemCount), itemName(itemName), itemCapacity(itemCapacity) {}


std::string Pallet::getItemName()
{
    return itemName;
}

int Pallet::getItemcapacity()  
{
    return itemCapacity;
}

int Pallet::getItemCount()
{
    return itemCount;
}  

int Pallet::getRemainingSpace()
{
    return itemCapacity - itemCount;

}

bool Pallet::isEmpty()
{
    return itemCount == 0;
}

bool Pallet::isFull()
{
    return itemCount == itemCapacity;
}



bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity)
{
    if (isEmpty())
    {
        this -> itemName = itemName;
        this -> itemCapacity = itemCapacity;
        return true;
    }
    else
    {
        return false;
    }
}

bool Pallet::takeOne()
{
    if (itemCount > 0)
    {
        itemCount--;
        return true;
    }
    else
    {
        return false;
    }
}

bool Pallet::putOne()
{
    if (itemCount < itemCapacity)
    {
        itemCount++;
        return true;
    }
    else
    {
        return false;
    }
};
