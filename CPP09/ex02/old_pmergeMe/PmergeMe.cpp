/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 00:01:39 by janhan            #+#    #+#             */
/*   Updated: 2024/09/23 08:55:38 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "nordmap.hpp"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <utility>

PmergeMe::PmergeMe(const int ac, const char** av)
: mArgc(ac)
, mArgv(av)
{}

PmergeMe::PmergeMe(const PmergeMe& rhs)
: mArgc(rhs.mArgc)
, mArgv(rhs.mArgv)
{}

PmergeMe::~PmergeMe()
{}

bool	PmergeMe::run()
{
	mSquenceDeque.clear();
	mSquenceVector.clear();

	if (mArgc == 1)
	{
		std::cout << "Error" << std::endl;
		return false;
	}

	/* vlide check */
	for (int i = 1; i < mArgc; ++i)
	{
		int temp = std::atoi(mArgv[i]);
		if (temp < 1 || isInt(mArgv[i]) == false)
		{
			std::cout << "Error" << std::endl;
			return false;
		}
	}

	clock_t start, end;
	/* Deque Process */
	start = clock();
	for (int i = 1; i < mArgc; ++i)
	{
		mSquenceDeque.push_back(std::atoi(mArgv[i]));
	}
	sort(mSquenceDeque);
	end = clock();
	double	dequeTime = (double(end - start) / CLOCKS_PER_SEC) * 1000.0;
	/* Deque Process end */

	/* Vector Process */
	start = clock();
	for (int i = 1; i < mArgc; ++i)
	{
		mSquenceVector.push_back(std::atoi(mArgv[i]));
	}
	sort(mSquenceVector);
	end = clock();
	double vectorTime = (double(end - start) / CLOCKS_PER_SEC) * 1000.0;
	/* Vector Porcess end */
	std::cout << "Before:\t";
	printArgv();
	std::cout << "\nAfter:\t";
	printDeque();
	std::cout	<< "\nTime to process a range of "
				<< mArgc - 1
				<< " elements with std::deque : "
				<< static_cast<unsigned long>(dequeTime)
				<< " ms"
				<< std::endl;
	std::cout	<< "Time to process a range of "
				<< mArgc - 1
				<< " elements with std::vector : "
				<< static_cast<unsigned long>(vectorTime)
				<< " ms"
				<< std::endl;
	return true;
}

/* Deque process */
void	PmergeMe::sort(std::deque<size_t>& sequnceDeque)
{
	if (sequnceDeque.size() < 2)
		return ;
	nordMap<size_t, std::deque<size_t>
	, std::deque<std::pair<size_t, std::deque<size_t> > > > nord; // 승자그룹 인덱스 저장용
	size_t	half = sequnceDeque.size() / 2;

	/* TEST Output */
	std::cout << "Swap Before Deque ";
	for (std::deque<size_t>::iterator it = sequnceDeque.begin(); it != sequnceDeque.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	/* End */

	for (size_t i = 0; i < half; ++i)
	{
		if (sequnceDeque[i] < sequnceDeque[i + half])
			std::swap(sequnceDeque[i], sequnceDeque[i + half]);
		nord[sequnceDeque[i]].push_back(sequnceDeque[i + half]); // b그룹을 저장함
		// sequnceDeque[0](14) vs. sequnceDeque[6](3): 14 > 3이므로 스왑하지 않음. nord[14]에 3을 저장.
		// sequnceDeque[1](7) vs. sequnceDeque[7](1): 7 > 1이므로 스왑하지 않음. nord[7]에 1을 저장.
		// sequnceDeque[2](14) vs. sequnceDeque[8](6): 14 > 6이므로 스왑하지 않음. nord[14]에 6을 저장.
		// sequnceDeque[3](20) vs. sequnceDeque[9](6): 20 > 6이므로 스왑하지 않음. nord[20]에 6을 저장.
		// sequnceDeque[4](16) vs. sequnceDeque[10](3): 16 > 3이므로 스왑하지 않음. nord[16]에 3을 저장.
		// sequnceDeque[5](20) vs. sequnceDeque[11](20): 같으므로 스왑하지 않음. nord[20]에 20을 저장.
	}

	std::deque<size_t> firstHalf(sequnceDeque.begin(), sequnceDeque.begin() + half);

	/* TEST Output */
	std::cout << "sort Before Deque ";
	for (std::deque<size_t>::iterator it = sequnceDeque.begin(); it != sequnceDeque.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "sort Before firstHalf ";
	for (std::deque<size_t>::iterator it = firstHalf.begin(); it != firstHalf.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;
	/* End */

	sort(firstHalf);

	/* TEST Output */
	std::cout << "sort After sequnceDeque ";
	for (std::deque<size_t>::iterator it = sequnceDeque.begin(); it != sequnceDeque.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	/* End */
	// std::copy(firstHalf.begin(), firstHalf.end(), sequnceDeque.begin());

	/* TEST Output */
	std::cout << "sort After firstHalf ";
	for (std::deque<size_t>::iterator it = firstHalf.begin(); it != firstHalf.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Copy sequnceDeque ";
	for (std::deque<size_t>::iterator it = sequnceDeque.begin(); it != sequnceDeque.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl << "-------------------------" << std::endl;
	/* End */

	std::deque<size_t> jacobsthalDeque = getJacobsthalDeque(half);
	for (size_t i = 0; i < half; ++i)
	{
		size_t y = nord[sequnceDeque[jacobsthalDeque[i] - 1]].back();
		nord[sequnceDeque[jacobsthalDeque[i] - 1]].pop_back();
		std::deque<size_t>::iterator it = firstHalf.begin();
		while (*it != sequnceDeque[jacobsthalDeque[i] - 1])
			++it;
		size_t	index = 0;
		if (i != 0)
			index = findInsertPoint(y, std::deque<size_t>(firstHalf.begin(), it + 1));
		if (i == 0)
			firstHalf.push_front(y);
		else
			firstHalf.insert(firstHalf.begin() + index, y);

		/* TEST Output */
		std::cout << "[" << i << "]" << "isert " << "[" << y << "] ";
		for (std::deque<size_t>::iterator it = firstHalf.begin(); it != firstHalf.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		/* End */
	}
	if (sequnceDeque.size() & 1)
	{
		size_t	i = sequnceDeque.size() - 1;
		size_t	index = findInsertPoint(sequnceDeque[i], firstHalf);
		firstHalf.insert(firstHalf.begin() + index, sequnceDeque[i]);
	}
	std::cout << std::endl;
	std::copy(firstHalf.begin(), firstHalf.end(), sequnceDeque.begin());
}

size_t	PmergeMe::findInsertPoint(size_t x, const std::deque<size_t>& sequence)
{
	size_t	left = 0;
	size_t	right = sequence.size();
	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (sequence[mid] < x)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}
/* Deque process end */

/* Vector process start */
void	PmergeMe::sort(std::vector<size_t>& sequenceVector)
{
	if (sequenceVector.size() < 2)
		return ;
	nordMap<size_t, std::vector<size_t>
	, std::vector<std::pair<size_t, std::vector<size_t> > > > nord;
	size_t	half = sequenceVector.size() / 2;
	for (size_t i = 0; i < half; ++i)
	{
		if (sequenceVector[i] < sequenceVector[i + half])
			std::swap(sequenceVector[i], sequenceVector[i + half]);
		nord[sequenceVector[i]].push_back(sequenceVector[i + half]);
	}
	std::vector<size_t> firstHalf(sequenceVector.begin(), sequenceVector.begin() + half);
	sort(firstHalf);

	std::copy(firstHalf.begin(), firstHalf.end(), sequenceVector.begin());
	std::vector<size_t> jacobsthalvector = getJacobsthalVector(half);
	for (size_t i = 0; i < half; ++i)
	{
		size_t y = nord[sequenceVector[jacobsthalvector[i] - 1]].back();
		nord[sequenceVector[jacobsthalvector[i] - 1]].pop_back();
		std::vector<size_t>::iterator it = firstHalf.begin();
		while (*it != sequenceVector[jacobsthalvector[i] - 1])
			++it;
		size_t	index = 0;
		if (i != 0)
			index = findInsertPoint(y, std::vector<size_t>(firstHalf.begin(), it + 1));
		firstHalf.insert(firstHalf.begin() + index, y);
	}
	if (sequenceVector.size() & 1)
	{
		size_t	i = sequenceVector.size() - 1;
		size_t	index = findInsertPoint(sequenceVector[i], firstHalf);
		firstHalf.insert(firstHalf.begin() + index, sequenceVector[i]);
	}
	std::copy(firstHalf.begin(), firstHalf.end(), sequenceVector.begin());
}

size_t	PmergeMe::findInsertPoint(size_t x, const std::vector<size_t>& sequence)
{
	size_t	left = 0;
	size_t	right = sequence.size();
	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (sequence[mid] < x)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}
/* Vector process end */

std::deque<size_t>	PmergeMe::getJacobsthalDeque(size_t size)
{
	std::deque<size_t>	result(size);
	for (size_t i = 1; i <= size; ++i)
		result[i - 1] = i;
	if (size == 1)
		return result;
	std::deque<size_t>::iterator start = result.begin() + 1, end = result.begin();
	for (size_t i = 2; end != result.end(); ++i)
	{
		size_t	jacobsthalNum = (pow(2, i + 1)) + pow(-1, i) / 3;
		while (*end != jacobsthalNum && end != result.end())
			++end;
		std::reverse(start, end + (end == result.end() ? 0 : 1));
		start = end + (end == result.end() ? 0 : 1);
	}
	return result;
}

std::vector<size_t>	PmergeMe::getJacobsthalVector(size_t size)
{
	std::vector<size_t>	result(size);
	for (size_t i = 1; i <= size; ++i)
		result[i - 1] = i;
	if (size == 1)
		return result;
	std::vector<size_t>::iterator start = result.begin() + 1, end = result.begin();
	for (size_t i = 2; end != result.end(); ++i)
	{
		size_t jaconsthalNum = (std::pow(2, i + 1) + std::pow(-1, i)) / 3;
		while(*end != jaconsthalNum && end != result.end())
			++end;
		std::reverse(start, end + (end == result.end() ? 0 : 1));
		start = end + (end == result.end() ? 0 : 1);
	}
	return result;
}

/* Util */
bool	PmergeMe::isInt(const char *num)
{
	char*	endPtr;
	long	longValue;

	longValue = strtol(num, &endPtr, 10);
	if ((static_cast<long>(std::numeric_limits<int>::min())) <= longValue
	&&	longValue <= (static_cast<long>(std::numeric_limits<int>::max()))
	&& *endPtr == '\0')
		return true;
	else
		return false;
}

void	PmergeMe::printArgv(void) const
{
	for (int i = 1; i < mArgc; ++i)
		std::cout << mArgv[i] << " ";
	std::cout << std::endl;
}

void	PmergeMe::printDeque(void) const
{
	for (std::deque<size_t>::const_iterator it = mSquenceDeque.begin(); it != mSquenceDeque.end(); it++)
		std::cout << *it << " ";
}
