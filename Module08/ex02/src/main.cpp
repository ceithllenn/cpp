#include "MutantStack.hpp"

int subject_test()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

int main()
{
	subject_test();
    std::cout << YLLW "\n\n\nTesting with int\n" << RST << std::endl;
    MutantStack<int> intStack;
    intStack.push(42);
    intStack.push(-1);
    intStack.push(2024);
    intStack.push(0);

    std::cout << BLUE << "Iterating using non-const iterator:" << RST << std::endl;
    for (MutantStack<int>::iterator it = intStack.begin(); it != intStack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << BLUE << "Iterating using const_iterator:" << RST << std::endl;
    for (MutantStack<int>::const_iterator cit = intStack.begin(); cit != intStack.end(); ++cit) {
        std::cout << *cit << std::endl;
    }

    std::cout << YLLW << "\nTesting with std::string\n" << RST << std::endl;
    MutantStack<std::string> stringStack;
    stringStack.push("Check out");
    stringStack.push("How my");
    stringStack.push("MutantStack");
    stringStack.push("is");
    stringStack.push("awesome!");

	std::cout << BLUE << "All elements:" RST << std::endl;
    for (MutantStack<std::string>::const_iterator it = stringStack.begin(); it != stringStack.end(); ++it)
	{
        std::cout << *it << " ";
	}
	
	std::cout << std::endl;

    std::cout << BLUE << "Top element: " << RST << stringStack.top() << std::endl;
    stringStack.pop();
    std::cout << BLUE << "Top after pop: " << RST << stringStack.top() << std::endl;
	std::cout << std::endl;

    std::cout << YLLW << "\nTesting with float\n" << RST << std::endl;
    MutantStack<float> floatStack;
    floatStack.push(3.14f);
    floatStack.push(1.618f);
    floatStack.push(2.718f);
    floatStack.push(1.414f);

    std::cout << BLUE "All elements:" << RST << std::endl;
	for (MutantStack<float>::iterator it = floatStack.begin(); it != floatStack.end(); ++it)
		std::cout << (*it) << std::endl;
	std::cout << BLUE "\nIterating backwards:" << RST << std::endl;
    MutantStack<float>::iterator ite = floatStack.end();
    MutantStack<float>::iterator itb = floatStack.begin();
    while (ite != itb) 
	{
        --ite;
        std::cout << *ite << std::endl;
    }

    std::cout << YLLW << "\nTesting edge case with empty MutantStack<int>" << RST << std::endl;
    MutantStack<int> emptyStack;
    std::cout << "Is stack empty? " << (emptyStack.empty() ? "Yes" : "No") << std::endl;
    if (!emptyStack.empty()) {
        std::cout << "Unexpected non-empty stack!" << std::endl;
    }

    // Copy constructor and assignment operator
    std::cout << YLLW << "\nTesting copy and assignment (on Stack<int>)" << RST << std::endl;
    MutantStack<int> copiedStack = intStack;
    MutantStack<int> assignedStack;
    assignedStack = intStack;

    std::cout << "Copied stack size: " << copiedStack.size() << std::endl;
    std::cout << "Assigned stack size: " << assignedStack.size() << std::endl;

	
	MutantStack<int> mstack;
    mstack.push(42);
    
}
