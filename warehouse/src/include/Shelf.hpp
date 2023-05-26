#ifndef SHELF_HPP
#define SHELF_HPP


#include"IContainer.hpp"
#include"Pallet.hpp"
#include<array>
#include<vector>

/**
 * @class Shelf
 * @brief Klasse die een schap representeert.
 */
class Shelf
{
    private:
        std::array<Pallet, 4> pallets; ///< Het aantal pallets op het schap

    public:
        /**
         * @brief Standaardconstructor voor Shelf
         */
        Shelf();

        /**
         * @brief Ruilt twee pallets in het schap
         * @param slot1 Het eerste slot om te ruilen
         * @param slot2 Het tweede slot om te ruilen
         * @return Of de ruil gelukt is
         */
        bool swapPallet(std::size_t slot1, std::size_t slot2);

        /**
         * @brief Verkrijgt de pallets op het schap
         * @return De pallets op het schap
         */
        std::array<Pallet, 4>& getPallets();

        /**
         * @brief Controleert of het schap leeg is
         * @return Of het schap leeg is
         */
        bool isEmpty();

        /**
         * @brief Controleert of het schap vol is
         * @return Of het schap vol is
         */
        bool isFull();
};

#endif
