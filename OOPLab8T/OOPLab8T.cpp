
#include <iostream>
#include "example.h"
int main()
{
     int r;       
     std::cout << "Lab 8 \n";
     std::cout << " 1 - Task 1 Remove minimuns from array\n";
     std::cout << " 2 - Task 2 Merge arrays\n";
     std::cout << " 3 - Task 3 Linked list \n";
     std::cout << " Your choice: ";
     std::cin >> r; 
     if (r == 1) task1();
     if (r == 2) task2();
     if (r == 3) task3();
}

