/*
** EPITECH PROJECT, 2024
** papaya-library
** File description:
** PapayaError
*/

#include "Papaya.hpp"

Papaya::PapayaError::PapayaError(std::string const &what, std::string const &where)
{
    _what = what;
    _where = where;
}

const char *Papaya::PapayaError::what() const noexcept
{
    return _what.c_str();
}

const char *Papaya::PapayaError::where() const noexcept
{
    return _where.c_str();
}

void Papaya::PapayaError::read() const noexcept
{
    std::cerr << "Papaya Error: " << _what << std::endl;
    std::cerr << ">> " << _where << std::endl;
}
