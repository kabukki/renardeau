#include <algorithm>
#include <iostream>
#include "Word.hpp"

Word::Word (const std::string & word) : _original(word)
{
	_letters.fill(0);
	_score = 0;

	for (char letter : word) {
		_letters[std::tolower(letter) - 97] += 1;
		_score += scores.at(letter);
	}
}

Word::~Word () {}

/**
 * Retourne vrai si ce mot contient les lettres nécessaires pour former l'autre mot
 * ex: pwuqaztr contains quartz ; quartz !contains pwuqaztr.
 */
bool			Word::contains(const Word & other) const
{
	for (char letter : alphabet) {
		if (at(letter) < other.at(letter)) {
			return false;
		}
	}
	return true;
}

/**
 * Score obtenu grâce à ce mot
 */
size_t			Word::score() const
{
	return _score;
}

/**
 * Nombre de lettres présentes
 */
size_t			Word::size() const
{
	return _original.length();
}

/**
 * Retourne le nombre d'occurrences de la lettre fournie
 */
size_t			Word::at(const char letter) const
{
	return _letters[letter - 97];
}

/**
 * Retourne le not original
 */
std::string		Word::original() const
{
	return _original;
}

std::ostream & operator<<(std::ostream &os, const Word & word) {
	return os << word.original() << " (" << word.score() << " pts)";
};
