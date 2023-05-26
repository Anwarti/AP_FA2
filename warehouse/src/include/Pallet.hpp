#ifndef PALLET_HPP
#define PALLET_HPP


#include"IContainer.hpp"
#include<string>
#include<iostream>


/**
 * @class Pallet
 * @brief Klasse die een pallet representeert. Erft van IContainer.
 */
class Pallet : public IContainer {
    private:
        int itemCount; ///< Het aantal items op de pallet
        std::string itemName; ///< De naam van de items op de pallet
        int itemCapacity; ///< De capaciteit van de pallet

    public:
        Pallet(); ///< Standaardconstructor voor Pallet
        /**
         * @brief Constructor voor Pallet met parameters
         * @param itemName De naam van de items op de pallet
         * @param itemCapacity De capaciteit van de pallet
         * @param itemCount Het huidige aantal items op de pallet
         */
        Pallet(std::string itemName, int itemCapacity, int itemCount = 0);

        /**
         * @brief Verkrijgt de naam van de items op de pallet
         * @return De naam van de items op de pallet
         */
        std::string getItemName();

        /**
         * @brief Verkrijgt de capaciteit van de pallet
         * @return De capaciteit van de pallet
         */
        int getItemcapacity();

        /**
         * @brief Verkrijgt het aantal items op de pallet
         * @return Het aantal items op de pallet
         */
        int getItemCount();

        /**
         * @brief Verkrijgt de resterende ruimte op de pallet
         * @return De resterende ruimte op de pallet
         */
        int getRemainingSpace();

        /**
         * @brief Herstelt een lege pallet voor hergebruik
         * @param itemName De naam van het nieuwe item op de pallet
         * @param itemCapacity De nieuwe capaciteit van de pallet
         * @return Of het hergebruik gelukt is
         */
        bool reallocateEmptyPallet(std::string itemName, int itemCapacity);

        /**
         * @brief Neemt één item van de pallet
         * @return Of het nemen gelukt is
         */
        bool takeOne();

        /**
         * @brief Plaatst één item op de pallet
         * @return Of het plaatsen gelukt is
         */
        bool putOne();

        /**
         * @brief Controleert of de pallet leeg is
         * @return Of de pallet leeg is
         */
        bool isEmpty() override;

        /**
         * @brief Controleert of de pallet vol is
         * @return Of de pallet vol is
         */
        bool isFull() override;
};

#endif // PALLET_HPP