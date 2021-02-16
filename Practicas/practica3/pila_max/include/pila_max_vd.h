#ifndef _PILA_MAX_VD
#define _PILA_MAX_VD
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

struct elemento{
    int ele;
    int maximo;
};
ostream & operator<<(ostream & os,const elemento &e);

class Pila_max{
    private:
        vector<elemento> datos;
    public:
        elemento tope()const;
        void quitar();
        void poner(int x);
        bool vacia()const;
        int size()const;
};



#endif 