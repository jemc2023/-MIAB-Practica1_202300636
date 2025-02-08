#include "utils.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <limits>
using namespace std;

ListaLigada::ListaLigada() {}
ListaLigada::~ListaLigada() {}

int ListaLigada::getId()
{
    this->counter++;
    return this->counter;
}

int ListaLigada::getSize()
{
    return this->size;
}

void ListaLigada::add(int data)
{
    SimpleNode *neoNode = new SimpleNode();
    neoNode->id = this->getId();
    neoNode->data = data;
    if (this->head == nullptr)
    {
        this->head = neoNode;
    }
    else
    {
        SimpleNode *aux = this->head;
        while (aux->right != nullptr)
        {
            aux = aux->right;
        }
        aux->right = neoNode;
    }
    this->size++;
}

void ListaLigada::remove(int data)
{
    SimpleNode *aux = this->head;
    SimpleNode *aux2 = nullptr;
    if (head == nullptr)
    {
        cout << endl
             << "Lista vacia..." << endl;
        return;
    }
    if (aux->data == data)
    {
        this->head = aux->right;
        delete aux;
        aux = nullptr;
        this->size--;
        return;
    }
    aux2 = aux;
    aux = aux->right;
    while (aux != nullptr)
    {
        if (aux->data == data)
        {
            aux2->right = aux->right;
            delete aux;
            aux = nullptr;
            this->size--;
            return;
        }
        aux2 = aux;
        aux = aux->right;
    }
    cout << endl
         << "Valor invalido para eliminar..." << endl;
}

void ListaLigada::show()
{
    SimpleNode *aux = this->head;

    system("cls");
    cout << "--------------------------------------------------------" << endl;
    cout << "Index  |  ";
    for (int i = 0; i < this->counter; i++)
    {
        cout << (i + 1) << "  |  ";
    }
    cout << endl
         << "--------------------------------------------------------" << endl;
    cout << "Valor  |  ";
    for (int i = 0; i < this->counter; i++)
    {
        // i: 0-9
        // id: 1-10
        if (aux->id == i + 1)
        {
            cout << aux->data << " →|  ";
            aux = aux->right;
        }
        else
        {
            cout << "-  |  ";
        }
        }
    cout << endl
         << "--------------------------------------------------------" << endl;
}