#include <iostream>
#include "MyList.h"

int main()
{
    MyList list;

    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_up(1);
    list.show();
    std::cout << "==========================\n";
    list.remove(6);
    list.show();
}


