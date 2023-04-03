#include <iostream>

// function prototype
// forward declaration
// signature of a function
void ourFirstSubroutine(int count);
int multiplyByTwo(int value);

// Function  / Procedure / Subroutine / Method 

int main()
{
    int count = 3;
    ourFirstSubroutine( count );
    ourFirstSubroutine(5);

    int result = multiplyByTwo(5);
    std::cout << "multiplyByTwo(5): " << result << std::endl;

    multiplyByTwo(20);   // there is NO error / we ignore the result
    // use less invocation
}

// terminus: parameter / place - holder
// 
void ourFirstSubroutine(int count)
{
    for (int i = 0; i < count; ++i) {
        std::cout << "Hello World" << std::endl;

        //if (i == 3)
        //    return;
    }
}

// function
int multiplyByTwo(int value)
{
    int tmp = value * 2;
    
    return tmp;
}


int main_first_steps()
{
    std::cout << "Hello World";

    int n = 0;
    int m = 0;

    // ...

    // logical operator:: && and
    //                    || or
    //                    !  negation
    if (n > 0 || m < 0) {
        std::cout << "n is greater than 0" << std::endl;
    }
    else {
        std::cout << "n is less-than or equal 0" << std::endl;
    }

    //  &  |    ::  binary operators ( not right now ... )

    int x = 5;
    int y = 0;

    y = ++x;   // pre-increment
    // vs.

    y = x++;   // post- increment
    x++;
    y = x;

    // side-effect
    // short circuit evaluation
    if (n < m && x < y)
    {

    }

    for ( int i = 0 ; i < 5; ++i) {

        std::cout << "for-loop" << std::endl;
        // 
        if (i == 3) {
            break;
        }
    }


    n = 10;
    // rejecting kind of a loop
    while (n <= 6) {

        std::cout << "while-loop: " << n << std::endl;
        n = n + 2;
    }

    // accepting loop
    n = 10;
    do
    {
        std::cout << "while-loop: " << n << std::endl;
        n = n + 2;
    }
    while (n <= 6);

    return 0;
}
