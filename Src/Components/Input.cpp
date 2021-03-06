/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Input methodes
*/

#include "Input.hpp"
#include "Error.hpp"
#include "IComponent.hpp"

Input::Input() :
Component::MyComponent(nts::INPUT)
{
    _output.insert(std::pair<std::size_t, nts::Pin>(1, {1, nts::UNDEFINED, nullptr, -1}));
}

Input::~Input()
{
}

nts::Tristate Input::compute(std::size_t pin)
{
    auto search = _output.find(pin);

    if (search == _output.end())
        throw Error::Component::ComputeError("No corresponding pin", " Input::compute");

    return search->second.state;
}

void Input::setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin)
{
    auto search = _output.find(pin);

    if (search == _output.end())
        throw Error::Parser::FileError("No corresponding pin", "Input::setLink");
    _output[pin] = {pin, nts::UNDEFINED, &other, static_cast<int>(otherPin)};
    try {
        other.setInput(otherPin, *this, pin);
    } catch (Error::Error e) {
        std::cerr << e.what() << " " << e.where() << std::endl;
        throw;
    }
}

void Input::setInput(std::size_t, nts::IComponent &, std::size_t)
{
}

void Input::setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    auto search = _output.find(pin);

    if (search == _output.end())
        throw Error::Parser::FileError("No corresponding pin", "Input::setOutput");
    if (_output[pin].destinationName != nullptr)
        throw Error::Component::LinkError("Pin already linked", "Input::setOutput");
    _output[pin] = {pin, nts::UNDEFINED, &other, static_cast<int>(otherPin)};
}

void Input::setState(const std::string &state)
{
    if (state == "0")
        _output[1].state = nts::FALSE;
    else if (state == "1")
        _output[1].state = nts::TRUE;
    else
        throw Error::Component::StateError("State can only be set to 0 or 1", "Input::setState");
}

void Input::dump() const noexcept
{
    std::cout << std::endl << "-----------------------------------------------" << std::endl;
    std::cout << "Input #" << _name << std::endl;

    for (auto it = _output.begin(); it != _output.end(); ++it) {
        std::cout << "\tpin #" << it->second.pin << std::endl <<
        "\t-> state: " << it->second.state << std::endl;
        
        if (it->second.destinationName != nullptr)
            std::cout << "\t\t\t->linked to: " << it->second.destinationName->getName() <<
            " - pin #" << it->second.destinationPin << std::endl;
        else
            std::cout << "\t\t\t-> no linked" <<
        " - pin #" << it->second.destinationPin << std::endl;
    }
}