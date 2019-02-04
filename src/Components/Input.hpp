/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Input class
*/

#ifndef INPUT_HPP_
	#define INPUT_HPP_

#include "IComponent.hpp"
#include <iostream>
#include <map>

class Input : public nts::IComponent
{
	public:
		Input(const std::string &name);
		~Input();

	nts::Tristate compute(std::size_t pin = 1) override;
	void setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin) override;
	void dump() const override;

	void setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

	private:
		const std::string &_name;
		std::map<size_t, nts::Pin> _output;
};

#endif /* !INPUT_HPP_ */