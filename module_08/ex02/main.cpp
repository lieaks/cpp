#include "MutantStack.hpp"
#include <list>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
    ++it; }
    std::stack<int> s(mstack);

    std::cout << "-----------------COPY CONSTRUCTOR--------------------" << std::endl;
    MutantStack<int> mstack2(mstack);
    std::cout << "mstack2 size:" <<mstack2.size() << std::endl;
    it = mstack2.begin();
    ite = mstack2.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
    ++it; }
    std::cout << "-----------------COPY OPERATOR--------------------" << std::endl;
    MutantStack<int> mstack3;
    mstack3 = mstack2;
    std::cout << "mstack3 size:" <<mstack3.size() << std::endl;
    it = mstack3.begin();
    ite = mstack3.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
    ++it; }

    std::cout << "-----------------CHAR--------------------" << std::endl;
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
    return 0;
}

// int main()
// {
//     std::list<int> mstack;
//     mstack.push_back(5);
//     mstack.push_back(17);
//     std::cout << mstack.back() << std::endl;
//     mstack.pop_back();
//     std::cout << mstack.size() << std::endl;
//     mstack.push_back(3); mstack.push_back(5); mstack.push_back(737); //[...] mstack.push(0);
//     std::list<int>::iterator it = mstack.begin(); std::list<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite) {
//         std::cout << *it << std::endl;
//     ++it; }
//     std::list<int> s(mstack); return 0;
// }
