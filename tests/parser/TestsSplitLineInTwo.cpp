/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Tests file of the ChipsetHandler
*/

#include <criterion/criterion.h>
#include <iostream>
#include "Parser.hpp"

Test(Parser, split_line_space)
{
    std::map<std::string, std::string> lineInfo;

    lineInfo = Parser::Parser::SplitLineInTwo("input 4");
    cr_assert_eq(lineInfo["key"].compare("input"), 0);
    cr_assert_eq(lineInfo["value"].compare("4"), 0);
}

Test(Parser, split_line_tab)
{
    std::map<std::string, std::string> lineInfo;

    lineInfo = Parser::Parser::SplitLineInTwo("input\t4");
    cr_assert_eq(lineInfo["key"].compare("input"), 0);
    cr_assert_eq(lineInfo["value"].compare("4"), 0);
}