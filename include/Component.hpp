/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Declaration of the Component class and its functions
*/

#if !defined(_COMPONENT_HPP)
#define _COMPONENT_HPP

#include <vector>
#include <string>

namespace Component
{

    enum Type {
        NOT_SET,
        INPUT,
        OUTPUT,
        CLOCK
    }; // TODO: add all the other components...

    struct Link
    {
        std::string OriginName;
        int OriginPin;
        std::string DestinationName;
        int DestinationPin;
    };

    struct ComponentSetting
    {
        std::string value;
        Type type;
        std::vector<Link> links;
    };

} // Component


#endif // _COMPONENT_HPP