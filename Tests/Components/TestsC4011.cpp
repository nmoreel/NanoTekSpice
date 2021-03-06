/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Unit tests on component 4011 compute
*/

#include <criterion/criterion.h>
#include <string>
#include <iostream>
#include "Circuit.hpp"
#include "Parser.hpp"
#include "ArgumentParser.hpp"
#include "Error.hpp"

Test(C4011, UndefinedOutput)
{
    Circuit circuit;
    Parser::container_setting_t settings;

    settings = Parser::Parser("./Tests/assets/exemple/public/basics/nand.nts").Parse();
    circuit.createAllComponents(settings);
    cr_assert_eq(circuit.compute(1), nts::UNDEFINED);
    circuit.setState("a", "1");
    cr_assert_eq(circuit.compute(1), nts::UNDEFINED);
}

Test(C4011, FalseOutput)
{
    Circuit circuit;
    Parser::container_setting_t settings;

    settings = Parser::Parser("./Tests/assets/exemple/public/basics/nand.nts").Parse();
    circuit.createAllComponents(settings);
    circuit.setState("a", "1");
    circuit.setState("b", "1");
    cr_assert_eq(circuit.compute(1), nts::FALSE);
}

Test(C4011, TrueOutput)
{
    Circuit circuit;
    Parser::container_setting_t settings;

    settings = Parser::Parser("./Tests/assets/exemple/public/basics/nand.nts").Parse();
    circuit.createAllComponents(settings);
    circuit.setState("a", "0");
    cr_assert_eq(circuit.compute(1), nts::TRUE);
    circuit.setState("b", "0");
    cr_assert_eq(circuit.compute(1), nts::TRUE);
    circuit.setState("b", "1");
    cr_assert_eq(circuit.compute(1), nts::TRUE);
    circuit.setState("b", "0");
    circuit.setState("a", "1");
    cr_assert_eq(circuit.compute(1), nts::TRUE);
}

Test(C4011, WrongLInk)
{
    Circuit circuit;
    Parser::container_setting_t settings;

    settings = Parser::Parser("./Tests/assets/exemple/errored/false_nand.nts").Parse();
    try {
        circuit.createAllComponents(settings);
    } catch (Error::Component::LinkError e) {
        cr_assert_str_eq(e.what(), "Door linked to itself");
    }
}