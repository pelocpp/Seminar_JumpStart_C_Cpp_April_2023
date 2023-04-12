#include <iostream>
#include <vector>
#include <algorithm>

// using namespace std;  // ambiguity

namespace FutureProject {

    namespace Input {
    }

    namespace Output {
    }

    namespace UI {
    }

    namespace Logic
    {
        class Account {};
    }

    namespace MockLogic  // test data // mocking data
    {
        class Account {};
    }
}



void test()
{
    using namespace FutureProject::MockLogic;

    [[ maybe_unused ]] FutureProject::Logic::Account a;
}

void main_stl_01()
{
    // STL Container
    std::vector<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    // old-fashioned loop
    for (int i = 0; i < numbers.size(); ++i ) {

        std::cout << numbers[i] << std::endl;
    }
}


void main_stl_02()
{
    // STL Container
    std::vector<int> numbers;

    numbers.reserve(90);

    // old-fashioned loop
    for (int i = 0; i < 100; ++i)
    {
        numbers.push_back(2 * i);

        std::cout 
            << "index: " << i 
            << ", Size:" << numbers.size() 
            << ", Capacity: " << numbers.capacity() << std::endl;
    }

    numbers.shrink_to_fit();

    std::cout
        << ", Size:" << numbers.size()
        << ", Capacity: " << numbers.capacity() << std::endl;
}

void main_stl_03()
{
    // STL Container
    std::vector<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    std::vector<int>::iterator positionFirstElement;
    std::vector<int>::iterator positionLastElement;

    positionFirstElement = numbers.begin();
    positionLastElement = numbers.end();

    if (positionFirstElement == positionLastElement)
        return;

    int value = *positionFirstElement;
    std::cout << value << std::endl;

    ++positionFirstElement;

    if (positionFirstElement == positionLastElement)
        return;

    value = *positionFirstElement;
    std::cout << value << std::endl;

    ++positionFirstElement;

    if (positionFirstElement == positionLastElement)
        return;

    value = *positionFirstElement;
    std::cout << value << std::endl;

    ++positionFirstElement;

    if (positionFirstElement == positionLastElement)
        return;

    value = *positionFirstElement;
    std::cout << value << std::endl;
}

void main_stl_04()
{
    // STL Container
    std::vector<int> numbers;

    numbers.push_back(3);
    numbers.push_back(2);
    numbers.push_back(1);

    std::vector<int>::iterator positionFirstElement;
    std::vector<int>::iterator positionLastElement;

    positionFirstElement = numbers.begin();
    positionLastElement = numbers.end();

    for ( ; positionFirstElement != positionLastElement; ++ positionFirstElement)
    {
        int value = *positionFirstElement;
        std::cout << value << std::endl;
    }
}

void doSomething(int value) 
{
    std::cout << "Value: " << value << std::endl;
}

void main_stl_05()
{
    // STL Container
    std::vector<int> numbers;

    numbers.push_back(3);
    numbers.push_back(2);
    numbers.push_back(1);

    // acts on a range
    std::for_each(
        numbers.begin(),
        numbers.end(),
        doSomething
    );
}

void main_stl_06()
{
    // STL Container
    std::vector<int> numbers;
    numbers.resize(10);

    std::vector<int>::iterator pos1 = numbers.begin();
    pos1 = std::next (pos1);

    std::vector<int>::iterator pos2 = numbers.end();
    pos2 = std::prev(pos2);

    std::fill(
        // numbers.begin(),
        pos1,
        // numbers.end(),
        pos2,
        123
    );

    // acts on a range
    std::for_each(
        numbers.begin(),
        numbers.end(),
        doSomething
    );
}


// static int startValue = 99;   // local variable ==> global variable

int doInitialization()
{ 
    static int startValue = 99;   // local variable ==> global variable
    ++startValue;

    std::cout << "doInitialization called ..." << std::endl;
    return startValue;
}

void main_stl_07()
{
    // STL Container
    std::vector<int> numbers;
    numbers.resize(10);

    std::fill(
        numbers.begin(),
        numbers.end(),
        123
    );

    std::generate(
        numbers.begin(),
        numbers.end(),
        doInitialization
    );

    // acts on a range
    std::for_each(
        numbers.begin(),
        numbers.end(),
        doSomething
    );
}


void main_stl_08()
{
    // STL Container
    std::vector<int> numbers;
    numbers.resize(10);

    std::generate(
        numbers.begin(),
        numbers.end(),
        doInitialization
    );

    // acts on a range // up-to C++ 11
    // Range-Based for Loop
    for ( int n : numbers ) {

        std::cout << "VALUE: " << n << std::endl;
    }

    //std::for_each(
    //    numbers.begin(),
    //    numbers.end(),
    //    doSomething
    //);
}

void main_stl_09()
{
    // STL Container
    std::vector<int> numbers;
    numbers.resize(10);

    std::generate(
        numbers.begin(),
        numbers.end(),
        doInitialization
    );

    //std::vector<int>::iterator found;

    //found = std::find(
    //    numbers.begin(),
    //    numbers.end(),
    //    1005
    //);


    auto u = 123;  // Typ Deduction

    //var n;
    //let x;
    //x;

    auto found = std::find(
            numbers.begin(),
            numbers.end(),
            1005
        );

    if (found == numbers.end()) {
        std::cout << "Not found" << std::endl;
    }
    else {
        std::cout << "Found: " << *found << std::endl;
    }

    // searching ....

    std::for_each(
        numbers.begin(),
        numbers.end(),
        doSomething
    );
}

void main_stl()
{
    main_stl_09();
}