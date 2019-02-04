/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Circuit class
*/

#ifndef CIRCUIT_HPP_
	#define CIRCUIT_HPP_

#include "IComponent.hpp"
#include <map>

class Circuit {
	public:
		Circuit();
		~Circuit();

		void createAllComponents();

	private:
	std::map<std::string, nts::ptrIComponent_t> _allComponents;
};

#endif /* !CIRCUIT_HPP_ */
