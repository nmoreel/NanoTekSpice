/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Clock methodes
*/

#include "Clock.hpp"
#include "Error.hpp"
#include "IComponent.hpp"

Clock::Clock() :
Component::MyComponent(nts::CLOCK)
{
    _output.insert(std::pair<std::size_t, nts::Pin>(1, {1, nts::UNDEFINED, nullptr, -1}));
}

Clock::~Clock()
{
}

nts::Tristate Clock::compute(std::size_t pin)
{
    auto search = _output.find(pin);
    nts::Tristate state = nts::UNDEFINED;

    if (search == _output.end())
        throw Error::Component::ComputeError("No corresponding pin", " Clock::compute");
    if (search->second.state == nts::FALSE) {
        state = nts::FALSE;
        search->second.state = nts::TRUE;
    }
    else if (search->second.state == nts::TRUE){
        state = nts::TRUE;
        search->second.state = nts::FALSE;
    }
    return state;
}

void Clock::setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin)
{
    auto search = _output.find(pin);

    if (search == _output.end())
        throw Error::Parser::FileError("No corresponding pin", "Clock::setLink");
    _output[pin] = {pin, nts::UNDEFINED, &other, static_cast<int>(otherPin)};
    try {
        other.setInput(otherPin, *this, pin);
    } catch (Error::Error e) {
        std::cerr << e.what() << " " << e.where() << std::endl;
        throw;
    }
}

void Clock::setInput(std::size_t, nts::IComponent &, std::size_t)
{
}

void Clock::setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    auto search = _output.find(pin);

    if (search == _output.end())
        throw Error::Parser::FileError("No corresponding pin", "Clock::setOutput");
    if (_output[pin].destinationName != nullptr)
        throw Error::Component::LinkError("Pin already linked", "Clock::setOutput");
    _output[pin] = {pin, nts::UNDEFINED, &other, static_cast<int>(otherPin)};
}

void Clock::setState(const std::string &state)
{
    if (state == "0")
        _output[1].state = nts::FALSE;
    else if (state == "1")
        _output[1].state = nts::TRUE;
    else
        throw Error::Component::StateError("State can only be set to 0 or 1", "Clock::setState");
}

void Clock::dump() const noexcept
{
    std::cout << std::endl << "-----------------------------------------------" << std::endl;
    std::cout << "Clock #" <<_name << std::endl;

    for (auto it = _output.begin(); it != _output.end(); ++it) {
        std::cout << "\tpin #" << it->second.pin << std::endl <<
        "\t-> state: " << it->second.state << std::endl <<
        "\t-> linked to: " << it->second.destinationName->getName() <<
        " - pin #" << it->second.destinationPin << std::endl;
    }
}