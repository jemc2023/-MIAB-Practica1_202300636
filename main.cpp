#include <iostream>
#include "utils.cpp"
#include "ListaLigada.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
    system("chcp 65001");
    displayWelcome();
    while (true)
    {
        displayMenu(false);
        system("cls");
    }
    return 0;
}
