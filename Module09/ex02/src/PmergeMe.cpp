#include "PmergeMe.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/**
 * @brief Destroy the Pmerge Me:: Pmerge Me object
 * 
 */
PmergeMe::~PmergeMe()
{
//	std::cout << PURP << "PmergeMe destructor called" << RST << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/**
 * @brief Construct a new Pmerge Me:: Pmerge Me object
 * 
 */
PmergeMe::PmergeMe()
{
	//std::cout << PURP << "PmergeMe default constructor called" << RST << std::endl;
}

/**
 * @brief Construct a new Pmerge Me:: Pmerge Me object
 * 
 * @param copy 
 */
PmergeMe::PmergeMe(const PmergeMe &copy)
{
	//std::cout << PURP << "PmergeMe copy constructor called" << RST << std::endl;
	if (this != &copy)
		*this = copy;
}

/**
 * @brief PmergeMe assignation operator overload
 */
PmergeMe& PmergeMe::operator=(const PmergeMe &src)
{
	//std::cout << PURP << "PmergMe assignation operator called" << RST << std::endl;
	if (this != &src)
	{
		this->data_vector = src.data_vector;
		this->data_list = src.data_list;
	}
	return (*this);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/**
 * @brief Adds a number in the vector and the list in PmergeMe
 * 
 * @param n number
 */
void PmergeMe::addNumber(int n)
{
	if (std::find(data_vector.begin(), data_vector.end(), n) != data_vector.end())
		throw DuplicateUnauthorizedException();
	data_vector.push_back(n);
	data_list.push_back(n);
}

/**
 * @brief prints the number's sequence
 * 
 */
void PmergeMe::printSequence(bool flag) const
{
	if (flag)
		std::cout << "\nBefore: ";
	else
		std::cout << "\nAfter: ";
	for (size_t i = 0; i < data_vector.size() && (int)i < 10; i++)
		std::cout << data_vector[i] << " ";
	if (data_vector.size() > 10)
		std::cout << "[...]";
	std::cout << std::endl;
	if (!flag)
	{
    	double elapsed_time = static_cast<double>((v - start) / 10);
		
		std::cout << "\nTime to process a range of " << data_vector.size()
				<< " elements with std::vector: " << elapsed_time << "ms." << std::endl;
	}
}

/**
 * @brief sort the number sequence using the vectors container
 * 
 */
void PmergeMe::sortSequenceVector(void)
{
	std::vector<int>	min;
	std::vector<int>	max;

	while (data_vector.size() > 1)
	{
		if (data_vector[data_vector.size() - 1] >= data_vector[data_vector.size() - 2])
		{
			max.push_back(data_vector[data_vector.size() - 1]);
			min.push_back(data_vector[data_vector.size() - 2]);
		}
		else
		{
			min.push_back(data_vector[data_vector.size() - 1]);
			max.push_back(data_vector[data_vector.size() - 2]);
		}
		data_vector.pop_back();
		data_vector.pop_back();
	}
	if (data_vector.size())
	{
		max.push_back(data_vector[0]);
		min.push_back(-1);
		data_vector.pop_back();
	}

	/*********** @debug **********/
	// std::cout << OLIV << std::endl;
	// std::cout << "********Making pairs*********" << std::endl;
	// for (size_t i = 0; i < max.size(); i++)
	// 	std::cout << max[i] << "\t";
	// std::cout << std::endl;
	// for (size_t i = 0; i < min.size(); i++)
	// 	std::cout << min[i] << "\t";
	// std::cout << std::endl << std::endl;

	std::sort(max.begin(), max.end());
	std::sort(min.begin(), min.end());

	/*************@debug **********/
	// std::cout << PURP << "********Sorting sublists*****" << std::endl;
	// for (size_t i = 0; i < max.size(); i++)
	// 	std::cout << max[i] << "\t";
	// std::cout << std::endl;
	// for (size_t i = 0; i < min.size(); i++)
	// 	std::cout << min[i] << "\t";
	// std::cout << RST << std::endl << std::endl;

	data_vector = min;
	mergeVectors(max);
	v = std::clock();
}

void PmergeMe::sortSequence(void)
{
	printSequence(1);
	start = std::clock();
	sortSequenceVector();
	printSequence(0);
}

/**************************************************************************/
/*							PRIVATE METHODS					   			  */
/**************************************************************************/

// int *ft_jacobsthal(int n)
// {
// 	int	*tab = new int[n];

// 	for (int i = 0; i < n; i++)
// 	{
// 		if (i == 0)
// 			tab[i] = 0;
// 		else if (i == 1)
// 			tab[i] = 1;
// 		else
// 			tab[i] = tab[i - 1] + 2 * tab[i - 2];
// 	}
// 	return (tab);
// }

void PmergeMe::mergeVectors(std::vector<int> max)
{
	int	len = static_cast<int>(max.size());
	int	nb = 0;
	int	tmp = 0;
	std::vector<int> jacob;
	std::vector<int>::iterator	it = data_vector.begin();

	for (int i = 0; i < len; i++)
	{
		if (i == 0)
			tmp = 0;
		else if (i == 1)
			tmp = 1;
		else if (i == 2)
			continue ;
		else
			tmp = jacob[i - 1] + 2 * jacob[i - 2];
		if (tmp > len)
			break ;
		jacob.push_back(tmp);
		nb = max[jacob[i]];
		max[jacob[i]] = -1;
		while (it != data_vector.end() && *it < nb)
			it++;
		data_vector.insert(it, nb);
	}

	it = data_vector.begin();
	for (int i = 0; i < len; i++)
	{
		if (max[i] != -1)
		{
			nb = max[i];
			while (it != data_vector.end() && *it < nb)
				it++;
			data_vector.insert(it, nb);
		}
	}

	/*************@debug **********/
	// std::cout << BLUE << "\n********Merging lists*****" << std::endl;
	// for (size_t i = 0; i < data_vector.size(); i++)
	// 	std::cout << data_vector[i] << "\t";
	// std::cout << std::endl;
	// std::cout << RST << std::endl << std::endl;
}

/**************************************************************************/
/*								EXCEPTIONS					   			  */
/**************************************************************************/

/**
 * @brief number duplicate error
 */
const char *PmergeMe::DuplicateUnauthorizedException::what(void) const throw()
{
	return ("Error: each number must be unique");
}

