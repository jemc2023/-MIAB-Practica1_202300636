#ifndef UTILS_H
#define UTILS_H
#include <string>
using namespace std;

void displayWelcome();
void displayMenu(bool);
void displayListOptions();
int pickOption();

void listaContigua();
bool displayMenuListaContigua(bool, int, int *);
void addListaContigua(int, int *);
void removeListaContigua(int, int *);
void showListaContigua(int, int *);

void menuListaLigada(bool);
int askForValue();

struct SimpleNode
{
    int data;
    SimpleNode *right = nullptr;
    int id;
};

struct DobleLinkNode
{
    int data;
    DobleLinkNode *left=nullptr;
    DobleLinkNode *right=nullptr;
    int id;
};


class ListaLigada
{
private:
    SimpleNode *head = nullptr;
    int size;
    int counter = 0;
    int getId();

public:
    ListaLigada(/* args */);
    void add(int);
    void remove(int);
    void show();
    int getSize();
    ~ListaLigada();
};

class ListaDobleLigada
{
private:
    SimpleNode *head = nullptr;
    int size;
    int counter = 0;
    int getId();

public:
    ListaDobleLigada(/* args */);
    void add(int);
    void remove(int);
    void show();
    int getSize();
    ~ListaDobleLigada();
};



#endif