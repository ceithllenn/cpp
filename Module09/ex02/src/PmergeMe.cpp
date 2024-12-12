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
 * @brief Main fonction of the PmergeMe class
 * 
 * sorts the number sequence using both vector and list containers
 * prints results and timestamps
 */
void PmergeMe::sortSequence(void)
{
	printSequence(1);
	start = std::clock();
	data_vector = sortSequenceVector(data_vector);
	timeV = std::clock();
	data_list = sortSequenceList(data_list);
	timeL = std::clock();
	printSequence(0);
}

/**************************************************************************/
/*							PRIVATE METHODS					   			  */
/**************************************************************************/

/**
 * @brief sort the number sequence using the vectors container
 * 
 */
std::vector<int> PmergeMe::sortSequenceVector(std::vector<int> &v)
{
	std::vector<int>	min;
	std::vector<int>	max;

/*Divides the sequences into pairs
Biggest number in all pairs goes into max vector
Shortest into min*/
	while (v.size() > 1)
	{
		if (v[v.size() - 1] >= v[v.size() - 2])
		{
			max.push_back(v[v.size() - 1]);
			min.push_back(v[v.size() - 2]);
		}
		else
		{
			min.push_back(v[v.size() - 1]);
			max.push_back(v[v.size() - 2]);
		}
		v.pop_back();
		v.pop_back();
	}
	if (v.size())
	{
		max.push_back(v[0]);
		v.pop_back();
	}

/*Sorts the sub-sequences, using the sortSequenceVector function
recursively until we treat only two elements vectors which can easily
be swapped if not sorted*/

	if (max.size() > 2)
	{
		max = sortSequenceVector(max);
		min = sortSequenceVector(min);
	}
	else
	{
		if (max[0] > max[1])
			max.swap(max);
		if (min.size() > 1 && min[0] > min[1])
			min.swap(min);
	}

/*Both sub-sequences are merged in the v vector, returned by the function*/
	v = min;
	v = mergeVectors(max, v);
	
	return (v);
}

/**
 * @brief sort the number sequence using the lists container
 * 
 */
std::list<int> PmergeMe::sortSequenceList(std::list<int> &l)
{
	std::list<int>				min;
	std::list<int>				max;
	std::list<int>::iterator	i = l.end(); i--;
	std::list<int>::iterator	j = i; j--;

/*Divides the sequences into pairs
Biggest number in all pairs goes into max list
Shortest into min*/

	while (l.size() > 1)
	{
		if (*i >= *j)
		{
			max.push_back(*i);
			min.push_back(*j);
		}
		else
		{
			min.push_back(*j);
			max.push_back(*i);
		}
		l.pop_back();
		l.pop_back();
		i = l.end(); i--;
		j = i; j--;
	}
	if (!l.empty())
	{
		max.push_back(l.front());
		l.pop_front();
	}

/*Sorts the sub-sequences, using the sortSequenceLists function
recursively until we treat only two elements lists which can easily
be swapped if not sorted*/

	if (max.size() > 2)
	{
		max = sortSequenceList(max);
		min = sortSequenceList(min);
	}
	else
	{
		std::list<int>::iterator	tmp = max.begin();
		tmp++;
		if (*max.begin() > *tmp)
			max.swap(max);
		tmp = min.begin();
		tmp++;
		if (tmp != min.end() && *min.begin() > *tmp)
			min.swap(min);
	}

/*Both sub-sequences are merged in the l list, returned by the function*/
	l = min;
	l = mergeLists(max, l);

	return (l);
}

/**
 * @brief merges both sub-sequences into a single sorted vector
 * using Ford-Johnson algorithm and Jacobsthal suite
 */
std::vector<int> PmergeMe::mergeVectors(std::vector<int> max, std::vector<int> v)
{
	int							len = static_cast<int>(max.size());
	int							nb = 0;
	int							tmp = 0;
	std::vector<int>			jacob;
	std::vector<int>::iterator	it = v.begin();

	for (int i = 0; i < len; i++)
	{

/*We calculate each number of the jacobsthal suite until it becomes bigger
than the size of max vector and use it to select the index of the first numbers
we are going to push back into v*/

		if (i == 0)
			tmp = 0;
		else if (i == 1)
			tmp = 1;
		else
		{
			tmp = jacob[i - 1] + 2 * jacob[i - 2];
			if (tmp >= len)
				break ;
		}
		jacob.push_back(tmp);
		if (tmp == 1 && i == 2)
			continue ;
		tmp = jacob[i];

/*Once we've selected the number we needed, we insert it where it belongs
in the v vector*/

		if (max[tmp] != -1)
		{
			nb = max[tmp];
			max[tmp] = -1;
			while (it != v.end() && *it < nb)
				it++;
			if (it == v.end())
				v.push_back(nb), it = v.begin();
			else
				it = v.insert(it, nb);
		}
	}

/* Then we proceed to inserting into v the numbers left in max*/
	it = v.begin();
	for (int i = 0; i < len; i++)
	{
		if (max[i] != -1)
		{
			nb = max[i];
			while (it != v.end() && *it < nb)
				it++;
			if (it == v.end())
				v.push_back(nb), it = v.begin();
			else
				it = v.insert(it, nb);
		}
	}

	return (v);
}

std::list<int> PmergeMe::mergeLists(std::list<int> max, std::list<int> l)
{
	int							len = static_cast<int>(max.size());
	int							nb = 0;
	int							tmp = 0;
	int							jacob[14] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};
	std::list<int>::iterator	it = l.begin();
	std::list<int>::iterator	it2;


/*We follow the jacobsthal suite until it becomes bigger
than the size of max list and use it to select the index of the first numbers
we are going to push back into l*/
	for (int i = 0; i < len; i++)
	{
		tmp = jacob[i];
		if (tmp >= len)
			break ;
		it2 = max.begin();
		for (int j = 0; j < tmp && it2 != max.end(); j++)
			it2++;
		nb = *it2;
		*it2 = -1;

/*Once we've selected the number we needed, we insert it where it belongs
in the l list*/

		if (nb != -1)
		{
			while (it != l.end() && *it < nb)
				it++;
			if (it == l.end())
				l.push_back(nb), it = l.begin();
			else
				it = l.insert(it, nb);
		}
	}
/* Then we proceed to inserting into l the numbers left in max*/
	it = l.begin();
	it2 = max.begin();
	for (int i = 0; i < len; i++)
	{
		nb = *it2;
		if (nb != -1)
		{
			while (it != l.end() && *it < nb)
				it++;
			if (it == l.end())
				l.push_back(nb), it = l.begin();
			else
				it = l.insert(it, nb);
		}
		it2++;
		if (it2 == l.end())
			break ;
	}

	return (l);
}

/**
 * @brief prints the number's sequence
 * 
 */
void PmergeMe::printSequence(bool flag) const
{
	if (flag)
		std::cout << "Before: ";
	else
		std::cout << "After: ";
	for (size_t i = 0; i < data_vector.size() && (int)i < 20; i++)
		std::cout << data_vector[i] << " ";
	// for (std::list<int>::const_iterator it = data_list.begin(); it != data_list.end(); it++)
	// 	std::cout << " " << *it;
	if (data_vector.size() > 20)
		std::cout << "[...]";
	std::cout << std::endl;
	if (!flag)
	{
    	double timerVector = static_cast<double>((timeV - start) * 10000 / CLOCKS_PER_SEC);
		
		std::cout << "\nTime to process a range of " << data_vector.size()
				<< " elements with std::vector: " << timerVector << "µs." << std::endl;

		double timerList = static_cast<double>((timeL - timeV) * 10000 / CLOCKS_PER_SEC);
		
		std::cout << "Time to process a range of " << data_list.size()
				<< " elements with std::list: " << timerList << "µs." << std::endl;
	}
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

