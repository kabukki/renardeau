#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <vector>
#include "Word.hpp"

class Solver
{
private:
	std::vector<Word *>		_dictionary;

public:
	Solver(const std::string & path);
	~Solver();

	Word *				solve(const Word & word);
	
	size_t				size() const;
};

#endif