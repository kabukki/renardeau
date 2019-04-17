#include <algorithm>
#include <iostream>
#include <fstream>
#include "Solver.hpp"

Solver::Solver (const std::string & path)
{
	std::ifstream		file(path);

	if (file.is_open()) {
		std::string		word;

		// Enregistre chaque mot du dictionnaire
		while (std::getline(file, word)) {
			_dictionary.push_back(new Word(word));
		}
	} else {
		throw std::runtime_error("Solver n'a pas pu charger le dictionnaire " + path);
	}
}

Solver::~Solver ()
{
	for (auto word : _dictionary) {
		delete word;
	}
}

/**
 * Retourne un mot du dictionnaire pouvant être assemblé à partir des lettres fournies
 */
Word *				Solver::solve(const Word & letters)
{
	std::vector<Word *>	matches;

	// Trouve tous les mots contenant les lettres fournies
	for (auto word : _dictionary) {
		if (letters.contains(*word)) {
			matches.push_back(word);
		}
	}

	if (matches.size() > 0) {
		// Trie les mots trouvés par longueur et score par ordre décroissant
		// BONUS: trie par score plutôt que par longueur
		std::sort(matches.begin(), matches.end(), [](const Word * a, const Word * b) {
			// return a->size() > b->size();
			return a->score() > b->score();
		});

		std::cout << "Mots analysés: " << matches.size() << std::endl;

		return matches.front();
	} else {
		return nullptr;
	}
}

/**
 * Taille du dictionnaire
 */
size_t				Solver::size() const
{
	return _dictionary.size();
}
