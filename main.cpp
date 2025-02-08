#include <iostream>
#include "utils.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
    displayWelcome();
    while (true)
    {
        displayMenu(false);
        system("cls");
    }
    return 0;
}
