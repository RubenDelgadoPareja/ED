
#include <iostream>
#include "pila_max_vd.h"
#include <vector>
#include <iterator>

using namespace std;

ostream & operator<<(ostream & os,const elemento &e){
    os <<"vector : ("<<e.ele<<","<<e.maximo<<")";
    return os;
}

elemento Pila_max::tope()const{
    elemento aux = {0,0};
    if(!datos.empty())
        return datos.back();
    else
    {
        return aux;
    }
    
}

void Pila_max::quitar(){
    this->datos.pop_back();
}



void Pila_max::poner(int x){
    elemento aux;
    aux.ele = x;
    if( x > this->tope().maximo || this->datos.empty())
        aux.maximo = x;
    else
        aux.maximo = this->tope().maximo;
    
    this->datos.push_back(aux);
}



int Pila_max::size()const{
    return this->datos.size();
}


bool Pila_max::vacia()const{
    return this->datos.empty();
}
