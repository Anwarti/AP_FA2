#pragma once

/**
 * @interface IContainer
 * @brief Interface voor containers zoals pallets.
 */
class IContainer{
    public:
        /**
         * @brief Controleert of de container leeg is
         * @return Of de container leeg is
         */
        virtual bool isEmpty() = 0;

        /**
         * @brief Controleert of de container vol is
         * @return Of de container vol is
         */
        virtual bool isFull() = 0;
};