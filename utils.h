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

#endif