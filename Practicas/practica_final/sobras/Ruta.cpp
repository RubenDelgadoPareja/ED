#include <iostream>
#include "Ruta.h"
#include <list>

void Ruta::Insertar(const Punto &n){
    this->puntos.push_back(n);
}

void Ruta::Borrar(const Punto &n){
    this->puntos.remove(n);
}

string Ruta::GetCode()const{
    return this->code;
}

void Ruta::SetCode(const string &code){
    this->code = code;
}

bool Ruta::operator<(const Ruta &r)const{
    bool res = false;
    if (this->code < r.code){ 
        res = true;
    }

    return res;
}

bool Ruta::operator==(const Ruta &r)const{
    bool res = true;
    if (this->GetCode() == r.GetCode() && this->puntos.size() == r.puntos.size()){

        auto it_r = r.puntos.begin();
        for(auto it = this->puntos.begin(); res && it!=this->puntos.end(); ++it ){
            if( *it != *it_r){
                res = false;
            }
            ++it_r;
        }
    }
    else 
        res = false;

    return res;
}

bool Ruta::operator!=(const Ruta &r)const{
    bool res = false;
    if (this->GetCode() == r.GetCode() && this->puntos.size() == r.puntos.size()){

        auto it_r = r.puntos.begin();
        for(auto it = this->puntos.begin(); !res && it!=this->puntos.end(); ++it ){
            if( *it != *it_r){
                res = true;
            }
            ++it_r;
        }
    }
    else 
        res = true;

    return res;
}


Ruta Ruta::operator=(const Ruta &r){
    if(this != &r){
        this->SetCode(r.GetCode());

        this->puntos.resize(0);
        for(auto it=r.puntos.begin(); it!=r.puntos.end(); ++it){
            this->puntos.push_back(*it);
        }
        
    }
    return *this;

}



istream & operator>>(iostream & is, Ruta & R){
    string codigo;
    int tam;
    Punto aux;
    is >> codigo;
    is >> tam;
    while(tam > 0){
        is>>aux;
        R.Insertar(aux);
        tam--;
    }
    R.SetCode(codigo);

    return is;

};

ostream & operator<<(ostream & os, const Ruta &R){
    os <<R.GetCode()<<" "<<R.puntos.size()<<" ";
    for(auto it= R.puntos.begin(); it!=R.puntos.end(); ++it){
        os<<*it<<" ";
    }

    return os;
};




