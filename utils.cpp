#include "utils.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <limits>
using namespace std;

void displayWelcome()
{
    system("cls");
    cout << "==============================================" << endl;
    cout << "===               PRACTICA 1               ===" << endl;
    cout << "===           Archivos seccion B           ===" << endl;
    cout << "===        Emilio Morales 202300636        ===" << endl;
    cout << "==============================================" << endl;
}

void displayListOptions()
{
    cout << endl
         << "Seleccione el tipo de la lista a probar: " << endl
         << endl;
    cout << "1. Lista Contigua (Arreglo)" << endl;
    cout << "2. Lista Ligada (Simple)" << endl;
    cout << "3. Lista Doblemente Ligada" << endl;
    cout << "4. Lista Indexada" << endl;
    cout << "5. Salir" << endl
         << endl;
}

void displayListOptions2()
{
    cout << endl
         << "Seleccione el tipo de la lista a probar: " << endl
         << endl;
    cout << "1. Insertar datos" << endl;
    cout << "2. Eliminar datos" << endl;
    cout << "3. Mostrar datos visualmente" << endl;
    cout << "4. Regresar al meno anterior " << endl;
}

void displayMenu(bool flag)
{
    if (flag)
    {
        system("cls");
        cout << "Ingrese solo el numero entero de las opciones previas..." << endl;
        cout << endl;
    }
    displayListOptions();
    int option = pickOption();
    switch (option)
    {
    case 1:
        listaContigua();
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    case 5:
        exit(0);
        break;
    default:
        displayMenu(true);
        break;
    }
}

int pickOption()
{
    int option = 0;
    cout << "Ingrese una opcion: ";
    while (!(cin >> option))
    {
        cout << "Solo se aceptan numeros enteros.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return option;
}

void listaContigua()
{
    int lista, n, i;
    int arreglo[10] = {};

    cout << endl
         << "Ingrese el numero de elemntos (maximo 10): ";
    while (!(cin >> n))
    {
        cout << "Solo se aceptan numeros enteros.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    bool flagRepetition = displayMenuListaContigua(false, n, arreglo);
    while (flagRepetition)
    {
        flagRepetition = displayMenuListaContigua(false, n, arreglo);
    }
}

bool displayMenuListaContigua(bool flag, int maxLen, int *arreglo)
{
    if (flag)
    {
        system("cls");
        cout << "Ingrese solo el numero entero de las opciones previas..." << endl;
        cout << endl;
    }
    displayListOptions2();
    int option = pickOption();
    switch (option)
    {
    case 1:
        addListaContigua(maxLen, arreglo);
        break;
    case 2:
        removeListaContigua(maxLen, arreglo);
        break;
    case 3:
        showListaContigua(maxLen, arreglo);
        break;
    case 4:
        return false;
    default:
        return displayMenuListaContigua(true, maxLen, arreglo);
    }
    return true;
}

void addListaContigua(int maxLen, int *arreglo)
{
    for (int i = 0; i < maxLen; i++)
    {
        if (arreglo[i] != 0)
        {
            continue;
        }
        cout << "Ingrese un valor: ";
        while (!(cin >> arreglo[i]))
        {
            cout << endl
                 << "Solo se aceptan numeros enteros.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingrese un valor: ";
        }
        break;
    }
}

void removeListaContigua(int maxLen, int *arreglo)
{
    int index = 0;
    cout << "Ingrese el indice del arreglo a borrar: ";
    while (!(cin >> index))
    {
        cout << endl
             << "Solo se aceptan numeros enteros.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese un nuevo valor: ";
    }
    if (index > maxLen)
    {
        cout << "Numero invalido..." << endl;
        removeListaContigua(maxLen, arreglo);
    }
    for (int i = 0; i < maxLen; i++)
    {
        if (i == index - 1)
        {
            arreglo[i] = -1;
        }
    }
}

void showListaContigua(int maxLen, int *arreglo)
{
    system("cls");
    cout << "--------------------------------------------------------" << endl;
    cout << "Index  |  ";
    for (int i = 0; i < maxLen; i++)
    {
        cout << (i + 1) << "  |  ";
    }
    cout << endl
         << "--------------------------------------------------------" << endl;
    cout << "Valor  |  ";
    for (int i = 0; i < maxLen; i++)
    {
        cout << arreglo[i] << "  |  ";
    }
    cout << endl
         << "--------------------------------------------------------" << endl;
}
