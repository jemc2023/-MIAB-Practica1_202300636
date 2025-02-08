#include "utils.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <limits>
using namespace std;

ListaDobleLigada::ListaDobleLigada() {}
ListaDobleLigada::~ListaDobleLigada() {}

int ListaDobleLigada::getId()
{
    this->counter++;
    return this->counter;
}

int ListaDobleLigada::getSize()
{
    return this->size;
}

void ListaDobleLigada::add(int data)
{
    DobleLinkNode *neoNode = new DobleLinkNode();
    neoNode->data = data;
    neoNode->id = this->getId();
    cout << "EL NUEVO: " << neoNode->id;
    if (this->head == nullptr)
    {
        this->head = neoNode;
        this->tail = neoNode;
    }
    else
    {
        neoNode->left = this->tail;
        this->tail->right = neoNode;
        neoNode->right = this->head;
        this->head->left = neoNode;
        this->tail = neoNode;
    }
    this->size++;
}

void ListaDobleLigada::remove(int data)
{
    DobleLinkNode *aux = this->head;
    DobleLinkNode *aux2 = nullptr;
    if (head == nullptr)
    {
        cout << endl
             << "Lista vacia..." << endl;
        return;
    }
    if (aux->data == data)
    {
        this->head = aux->right;
        this->head->left = this->tail;
        this->tail->right = this->head;
        delete aux;
        aux = nullptr;
        this->size--;
        return;
    }
    aux2 = aux;
    aux = aux->right;
    while (aux != this->head)
    {
        if (aux->data == data)
        {
            aux2->right = aux->right;
            aux->right->left = aux2;
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

void ListaDobleLigada::show()
{
    DobleLinkNode *aux = this->head;

    system("cls");
    cout << "--------------------------------------------------------" << endl;
    cout << "Index  |  ";
    for (int i = 0; i < this->counter; i++)
    {
        cout << (i + 1) << "  |  ";
    }
    cout << endl
         << "--------------------------------------------------------" << endl;
    cout << "Valor  |";
    for (int i = 0; i < this->counter; i++)
    {
        // i: 0-9
        // id: 1-10
        if (aux->id == i + 1)
        {
            cout << "← " << aux->data << " →|";
            aux = aux->right;
        }
        else
        {
            cout << "  -  |";
        }
    }
    cout << endl
         << "--------------------------------------------------------" << endl;
}