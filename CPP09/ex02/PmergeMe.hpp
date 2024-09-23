#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe
{
	public:
		PmergeMe(const int ac, const char** av);
		PmergeMe(const PmergeMe& rhs);
		~PmergeMe();

		bool	run();
	private:
		bool	isInt(const char* num);
		void	sort(std::deque<size_t>& squence);
		void	sort(std::vector<size_t>& squence);
	private:	/* member var */
		const int			mArgc;
		const char**		mArgv;
		std::deque<size_t>	mSquenceDeque;
		std::vector<size_t>	mSquenceVector;
	private:	/* ban copy assignment operator */
		PmergeMe& operator=(const PmergeMe& rhs);
};

#endif
