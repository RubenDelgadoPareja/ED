#ifndef _PILA_MAX_COLA
#define _PILA_MAX_COLA
#include "cola.h"
#include <iostream>
using namespace std;

struct elemento{
    int ele;
    int maximo;
};
ostream & operator<<(ostream & os,const elemento &e);

class Pila_max{
    private:
        Cola<elemento> datos;
    public:
        elemento tope()const;
        void quitar();
        void poner(int x);
        bool vacia()const;
        int size()const;
};



#endif