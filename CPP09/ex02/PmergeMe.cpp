#include "PmergeMe.hpp"
#include <ctime>
#include <limits>

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
	/* 멤버 Squence 클리어 */
	mSquenceDeque.clear();
	mSquenceVector.clear();

	/* Uasge 체크 */
	if (mArgc == 1)
	{
		std::cout << "Error" << std::endl;
		return false;
	}

	/* 인자 체크 */
	for (int i = 2; i < mArgc; ++i)
	{
		int temp = std::atoi(mArgv[i]);
		if (temp < 1 || isInt(mArgv[i]) == false)
		{
			std::cout << "Error" << std::endl;
			return false;
		}
	}

	clock_t start, end;
	/* Deque sort */
	start = clock();
	for (int i = 2; i < mArgc; ++i)
	{
		mSquenceDeque.push_back(std::atoi(mArgv[i]));
	}
	// 16 7 11 8 16 1 14 16 26 7 15 3 18 10 10 21 1 26 21 12 6 6 8 19 8
	sort(mSquenceDeque);
	end = clock();
	double dequeTime = (double(end - start) / CLOCKS_PER_SEC) * 1000.0;
}


bool	PmergeMe::isInt(const char* num)
{
	char*	endPtr;
	long	longValue;

	longValue = strtol(num, &endPtr, 10);
	if ((static_cast<long>(std::numeric_limits<int>::min()) <= longValue
	&& longValue <= (static_cast<long>(std::numeric_limits<int>::max())))
	&& *endPtr == '\0')
		return true;
	else
		return false;
}
