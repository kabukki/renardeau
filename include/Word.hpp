#ifndef WORD_HPP
#define WORD_HPP

#include <map>

/**
 * Alphabet
 */
const std::string	alphabet = "abcdefghijklmnopqrstuvwxyz";

/**
 * Points associés à chaque lettre
 */
const std::map<char, size_t> scores = {
	{ 'a', 1 }, { 'e', 1 }, { 'i', 1 }, { 'l', 1 }, { 'n', 1 }, { 'o', 1 }, { 'r', 1 }, { 's', 1 }, { 't', 1 }, { 'u', 1 },
	{ 'd', 2 }, { 'g', 2 }, { 'm', 2 },
	{ 'b', 3 }, { 'c', 3 }, { 'p', 3 },
	{ 'f', 4 }, { 'h', 4 }, { 'v', 4 },
	{ 'j', 8 }, { 'q', 8 },
	{ 'k', 10 }, { 'w', 10 }, { 'x', 10 }, { 'y', 10 }, { 'z', 10 }
};

class Word
{
private:
	std::string				_original;
	std::array<size_t, 26>	_letters;
	size_t					_score;

public:
	Word(const std::string & word);
	~Word();

	bool				contains(const Word & other) const;
	size_t				score() const;
	size_t				size() const;
	size_t				at(const char letter) const;
	std::string			original() const;
};

std::ostream & operator<<(std::ostream &os, const Word & word);

#endif