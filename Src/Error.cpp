/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** File containing all the error
*/

#include <string>
#include "Error.hpp"

Error::Error::Error(const std::string &message, const std::string &where) :
_where(where), _message(message)
{
}

const std::string &Error::Error::where() const
{
    return _where;
}

const char *Error::Error::what() const noexcept
{
    return _message.c_str();
}