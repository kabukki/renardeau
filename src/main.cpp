#include <iostream>
#include "Color.hpp"
#include "Solver.hpp"
#include "Word.hpp"

int		main(int ac, char **av)
{
	if (ac == 3) {
		Word				letters(av[2]);

		if (letters.size() >= 1 && letters.size() <= 10) {
			try {
				Solver		solver(av[1]);
				Word *		match = solver.solve(letters);

				if (match != nullptr) {
					std::cout << Color::FG_GREEN << "Solution trouvée: " << *match << Color::RESET << std::endl;
				} else {
					std::cerr << Color::FG_YELLOW << "Aucune solution trouvée pour les lettres " << letters << Color::RESET << std::endl;
				}
			} catch (std::exception& e) {
				std::cerr << Color::FG_RED << "Erreur: " << e.what() << Color::RESET << std::endl;
			}
		} else {
			std::cerr << Color::FG_RED << "Vous devez fournir entre 1 et 10 lettres." << Color::RESET << std::endl;
		}
	} else {
		std::cerr << "Syntaxe: " << av[0] << " <dictionnaire> <lettres>" << std::endl;
	}

	return 0;
}
