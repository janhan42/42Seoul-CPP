/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:02:29 by janhan            #+#    #+#             */
/*   Updated: 2024/09/14 07:31:18 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <deque>
#include <vector>
#include <iostream>
#include <ctime>
#include <cmath>
#include <utility>
#include <algorithm>
#include <limits>

#include "nordmap.hpp"

class PmergeMe
{
	public:
		PmergeMe(const int ac, const char** av);
		PmergeMe(const PmergeMe& rhs);
		~PmergeMe();

		bool				run();
	private:
		const int			mArgc;
		const char**		mArgv;
		std::deque<size_t>	mSquenceDeque;
		std::vector<size_t>	mSquenceVector;
	private:
		bool				isInt(const char* num);
		void				sort(std::deque<size_t>& squenceDeque);
		void				sort(std::vector<size_t>& squenceVector);
		std::deque<size_t>	getJacobsthalDeque(size_t size);
		std::vector<size_t>	getJacobsthalVector(size_t size);
		size_t				findInsertPoint(size_t x, const std::deque<size_t>& sequence);
		size_t				findInsertPoint(size_t x, const std::vector<size_t>& sequence);
		void				printArgv(void) const;
		void				printDeque(void) const;
	private:
		PmergeMe& operator=(const PmergeMe& rhs);
};

/*

function FordJohnsonSort(sequence):
    if size of sequence < 2:
        return sequence

    # Step 1: Split the sequence into two halves
    half = size of sequence / 2
    firstHalf = sequence[0:half]
    secondHalf = sequence[half:end]

    # Step 2: Pair comparison and swap
    for i from 0 to half-1:
        if firstHalf[i] < secondHalf[i]:
            swap(firstHalf[i], secondHalf[i])

    # Step 3: Recursively sort the first half
    sortedFirstHalf = FordJohnsonSort(firstHalf)

    # Step 4: Generate Jacobsthal order for insertion
    jacobsthalOrder = generateJacobsthalOrder(half)

    # Step 5: Insert the second half into sortedFirstHalf
    for i from 0 to size of jacobsthalOrder - 1:
        index = jacobsthalOrder[i] - 1
        y = secondHalf[index]

        # Find insertion point in sortedFirstHalf
        insertPoint = findInsertPoint(y, sortedFirstHalf)

        # Insert element y into the correct position
        insert sortedFirstHalf at insertPoint with y

    # Step 6: If the sequence length is odd, insert the last element
    if size of sequence is odd:
        lastElement = sequence[end]
        insertPoint = findInsertPoint(lastElement, sortedFirstHalf)
        insert sortedFirstHalf at insertPoint with lastElement

    return sortedFirstHalf

function findInsertPoint(value, sortedSequence):
    # Use binary search to find the correct insertion point
    left = 0
    right = size of sortedSequence - 1
    while left <= right:
        mid = (left + right) / 2
        if sortedSequence[mid] < value:
            left = mid + 1
        else:
            right = mid - 1
    return left

function generateJacobsthalOrder(n):
    # Generate Jacobsthal sequence to determine insertion order
    jacobsthal = []
    i = 0
    while size of jacobsthal < n:
        jacobsthalNumber = calculateJacobsthal(i)
        if jacobsthalNumber <= n:
            append jacobsthalNumber to jacobsthal
        i += 1
    return jacobsthal

function calculateJacobsthal(n):
    # Jacobsthal number sequence: J(n) = J(n-1) + 2 * J(n-2)
    if n == 0:
        return 0
    if n == 1:
        return 1
    return calculateJacobsthal(n-1) + 2 * calculateJacobsthal(n-2)


 */
