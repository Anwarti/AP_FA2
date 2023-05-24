#include "include/Shelf.hpp"
#include "include/Pallet.hpp"


Shelf::Shelf() {
    // Initialize all pallets with itemCount of 0
    for (int i = 0; i < pallets.size(); i++) {
        pallets[i] = Pallet("", 0, 0);
    }
}

bool Shelf::swapPallet(int slot1, int slot2) {
    if (slot1 >= 0 && slot1 < pallets.size() && slot2 >= 0 && slot2 < pallets.size()) {
        // Geldige slotnummers
        // Voer de gewenste logica uit
        std::swap(pallets[slot1], pallets[slot2]);
        return true;
    } else {
        // Ongeldige slotnummers
        return false;
    }

}

bool Shelf::isEmpty() {
   for (int i = 0; i < pallets.size(); i++) {
        if (pallets[i].getItemCount() > 0) {
            return false;
        }
    }
    return true;
}
bool Shelf::isFull() {
    for (int i = 0; i < pallets.size(); i++) {
        if (pallets[i].getItemCount() < pallets[i].getItemcapacity()) {
            return false;
        }
    }
    return true;
}