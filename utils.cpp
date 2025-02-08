#include "utils.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits>
using namespace std;

ListaLigada *listaLigada = new ListaLigada();
ListaDobleLigada *listaDobleLigada = new ListaDobleLigada();

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
        menuListaLigada(false);
        break;
    case 3:
        menuListaDobleLigada(false);
        break;
    case 4:
        listaAnexada();
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
    int n;
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
    cout << "Index  |   ";
    for (int i = 0; i < maxLen; i++)
    {
        cout << (i + 1) << "  |   ";
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

void menuListaLigada(bool flag)
{
    if (flag)
    {
        system("cls");
        cout << "Ingrese solo el numero entero de las opciones previas..." << endl;
        cout << endl;
    }
    displayListOptions2();
    int option = pickOption();
    int data;
    int data2;
    switch (option)
    {
    case 1:
        data = askForValue();
        listaLigada->add(data);
        menuListaLigada(false);
        break;
    case 2:
        data2 = askForValue();
        listaLigada->remove(data2);
        menuListaLigada(false);
        break;
    case 3:
        listaLigada->show();
        menuListaLigada(false);
        break;
    case 4:
        return;
    default:
        menuListaLigada(true);
        break;
    }
}
void menuListaDobleLigada(bool flag)
{
    if (flag)
    {
        system("cls");
        cout << "Ingrese solo el numero entero de las opciones previas..." << endl;
        cout << endl;
    }
    displayListOptions2();
    int option = pickOption();
    int data;
    int data2;
    switch (option)
    {
    case 1:
        data = askForValue();
        listaDobleLigada->add(data);
        menuListaDobleLigada(false);
        break;
    case 2:
        data2 = askForValue();
        listaDobleLigada->remove(data2);
        menuListaDobleLigada(false);
        break;
    case 3:
        listaDobleLigada->show();
        menuListaDobleLigada(false);
        break;
    case 4:
        return;
    default:
        menuListaDobleLigada(true);
        break;
    }
}

int askForValue()
{
    int result;
    cout << "Ingrese un valor: ";
    while (!(cin >> result))
    {
        cout << endl
             << "Solo se aceptan numeros enteros.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese un valor: ";
    }
    return result;
}

void listaAnexada()
{
    int lista[10] = {};
    int n;
    cout << endl
         << "Ingrese el numero de elemntos (maximo 10): ";
    while (!(cin >> n))
    {
        cout << "Solo se aceptan numeros enteros.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    bool flagRepetition = displayMenuListaAnexada(false, n, lista);
    while (flagRepetition)
    {
        flagRepetition = displayMenuListaAnexada(false, n, lista);
    }
}

bool displayMenuListaAnexada(bool flag, int maxLen, int *arreglo)
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
        addListaAnexada(maxLen, arreglo);
        break;
    case 2:
        removeListaAnexada(maxLen, arreglo);
        break;
    case 3:
        showListaAnexada(maxLen, arreglo);
        break;
    case 4:
        return false;
    default:
        return displayMenuListaAnexada(true, maxLen, arreglo);
    }
    return true;
}

void addListaAnexada(int maxLen, int *arreglo)
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

void removeListaAnexada(int maxLen, int *arreglo)
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
        removeListaAnexada(maxLen, arreglo);
    }
    for (int i = 0; i < maxLen; i++)
    {
        if (i == index - 1)
        {
            arreglo[i] = 0;
        }
    }
}

void showListaAnexada(int maxLen, int *arreglo)
{
    system("cls");
    cout << string(130, '-') << endl;
    cout << "Index  |       ";
    for (int i = 0; i < maxLen; i++)
    {
        cout << (i + 1) << "      |       ";
    }
    cout << string(130, '-') << endl;
    cout << "Valor  |      ";
    for (int i = 0; i < maxLen; i++)
    {
        cout << arreglo[i] << "      |      ";
    }
    cout << string(130, '-') << endl;
    cout << "       |       ";
    for (int i = 0; i < maxLen; i++)
    {
        cout << "↑" << "      |       ";
    }
    cout << endl
         << "NodoI  | ";
    for (int i = 0; i < maxLen; i++)
    {
        if (arreglo[i] != 0)
        {
            cout << &arreglo[i] << " | ";
        }
        else
        {
            cout << "             | ";
        }
    }
    cout << string(130, '-') << endl;
}
