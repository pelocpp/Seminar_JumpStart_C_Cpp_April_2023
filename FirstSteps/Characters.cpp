#include <iostream>

void main_characters_01()
{
    char ch;

    ch = 'A';

    std::cout << ch << std::endl;

    // char / int 

    int n;

    n = ch;

    std::cout << n << std::endl;

    ch = '0';

    ch = 0;

    ch = '\0';  //  == ASCII Value 0
}

void main_characters_02()
{
    // sequence of characters / string / "

    // i) std::string  s =  "Hello World";

    char manyChars[30] = "Hello World";

    // iii)

    const char* cp = "Hello World";

    int i = 0;

    while (cp[i] != '\0') {

        int n = cp[i];
        std::cout << "    ASCII: " << n << std::endl;

        ++i;
    }

    std::cout << "Length: " << i << std::endl;
}

void main_characters_03()
{
    for (int i = 0; i < 127; ++i) {

        char ch = i;

        std::cout << "ASCII: " << i << ": " << ch << std::endl;
    }
}

void main_characters()
{
    //main_characters_01();
    //main_characters_02();
    main_characters_03();
}