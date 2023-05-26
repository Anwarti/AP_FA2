#ifndef SHELF_HPP
#define SHELF_HPP


#include"IContainer.hpp"
#include"Pallet.hpp"
#include<array>
#include<vector>


class Shelf:public IContainer
{


    public:
        std::array<Pallet, 4> pallets;
        Shelf();
        Pallet& getPallet(int index) { return pallets[index]; }
        bool swapPallet(std::size_t slot1, std::size_t slot2);
        std::array<Pallet, 4>& getPallets();
        bool isEmpty() override;
        bool isFull() override;
};

#endif
