#include "include/Shelf.hpp"
#include "include/Pallet.hpp"
#include<vector>


Shelf::Shelf() {

    for (std::size_t i = 0; i < pallets.size(); i++) {
        pallets[i] = Pallet("", 0, 0);
    }
}


bool Shelf::swapPallet(std::size_t slot1, std::size_t slot2) {

    if (slot1 < pallets.size() && slot2 < pallets.size()) {
     
        Pallet temp = pallets[slot1];
        pallets[slot1] = pallets[slot2];
        pallets[slot2] = temp;
        return true;  
    }
    return false; 
}

std::array<Pallet, 4>& Shelf::getPallets() {
    return pallets;
}

bool Shelf::isEmpty() {
   for (std::size_t i = 0; i < pallets.size(); i++) {
        if (pallets[i].getItemCount() > 0) {
            return false;
        }
    }
    return true;
}

bool Shelf::isFull() {
    for (std::size_t i = 0; i < pallets.size(); i++) {
        if (pallets[i].getItemCount() < pallets[i].getItemcapacity()) {
            return false;
        }
    }
    return true;
}
