/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** C4030 class
*/

/**
 * \file C4030.hpp
 * \brief C4030 class.
 * \author Cécile CADOUL
 * \author Florent POINSARD
 */

#ifndef C4030_HPP_
    #define C4030_HPP_

#include "IComponent.hpp"
#include "Component.hpp"
#include <iostream>
#include <string>
#include <map>

/*!
 * \class C4030
 * \brief Quad 2-input EXCLUSIVE-OR gate
 */
class C4030 : public Component::MyComponent
{
    public:
        /*!
         * \brief Component 4030 Constructor
         *
         * Initializes four EXCLUSIVE-OR gates with their own output and input pins.
         */
        C4030();
        /*!
         * \brief Component 4030 Destructor
         */
        ~C4030();
        /*!
         * \brief Compute
         *
         * Searches for the door containing the requested pin and
         * calculates the exit status.
         *
         * \param pin Pin requested
         * \return Output's door state. Can be true, false or undefined
         */
        nts::Tristate compute(std::size_t pin = 1) override;
        /*!
         * \brief Set link method
         *
         * Link this component to another
         *
         * \param pin Component pin that needs to be linked
         * \param other The other Component
         * \param otherPin The other component pin
         */
        void setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin) final;
        /*!
         * \brief Display information
         *
         * Display all pins state and link of component 4030
         */
        void dump() const noexcept override;
        /*!
         * \brief Set input link method
         *
         * Method call by another component to bind to component 4030's input
         *
         * \param pin Pin linked
         * \param other Other Component
         * \param otherPin Ohter component pin
         */
        void setInput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
        /*!
         * \brief Set output link method
         *
         * Method call by another component to bind to component 4030's output
         *
         * \param pin Pin linked
         * \param other Other Component
         * \param otherPin Ohter component pin
         */
        void setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;

    private:
        /*!
         * \brief Check self link method
         *
         * Check the link if the component is linked to itself
         *
         * \param pin1 First pin
         * \param pin2 Second pin
         */
        void checkSelfLink(std::size_t pin1, std::size_t pin2);
        /*!
         * \brief Compute input pin
         *
         * Return pin state passed as parameter
         *
         * \param pin Input pin
         * \return Pin state
         */
        nts::Tristate computeInput(nts::Pin &pin);
        /*!
         * \brief Compute output pin
         *
         * Return pin state passed in parameter thanks to the state of its
         *  two input pins
         *
         * \param pin Output pin
         * \return Pin state
         */
        nts::Tristate computeOutput(nts::Door &door);

        std::map<size_t, nts::Door> _doors; /*!< Component's doors map*/
};

#endif /* !C4030_HPP_ */