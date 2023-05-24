#include"IContainer.hpp"
#include"Pallet.hpp"
#include<array>


class Shelf:public IContainer
{
    private:
        std::array<Pallet, 4> pallets;
    public:
        Shelf();
        bool swapPallet(int slot1, int slot2);
        std::array<Pallet, 4>& getPallets();
        bool isEmpty() override;
        bool isFull() override;
};