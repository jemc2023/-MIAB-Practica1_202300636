#include <iostream>
#include "utils.cpp"
#include "ListaLigada.cpp"
#include "ListaDobleLigada.cpp"
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
