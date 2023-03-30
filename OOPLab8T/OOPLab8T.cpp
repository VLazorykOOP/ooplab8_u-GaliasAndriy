
#include <iostream>
#include "example.h"
int main()
{
     int r;       
     std::cout << "Lab 8 \n";
     std::cout << " 1 - Task 1 \n";
     std::cout << " 2 - Task 2 \n";
     std::cout << " Your choice: ";
     std::cin >> r; 
     if (r == 1) task1();
     if (r == 2) task2();  
}

