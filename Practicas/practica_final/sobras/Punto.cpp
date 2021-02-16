#include <iostream>
#include <string>
#include "Punto.h"

using namespace std;

double Punto::GetLatitud()const{
    return this->latitud;
}

double Punto::GetLongitud()const{
    return this->longitud;
}

void Punto::SetLatitud(double lat){
    this->latitud = lat;
}

void Punto::SetLongitud(double lon){
    this->longitud = lon;
}

bool Punto::operator<(const Punto & p)const{
    bool res = false;
    if(this->GetLatitud() == p.GetLatitud()){
        if(this->GetLongitud() < p.GetLongitud())
            res = true;
    }
    else if(this->GetLatitud() < p.GetLatitud())
        res = true;
    
    return res;
}

bool Punto::operator==(const Punto &p)const{
    bool res = false;

    if(this->GetLatitud() == p.GetLatitud() && this->GetLongitud() == p.GetLongitud())
        res = true;

    return res;
}

bool Punto::operator!=(const Punto &p)const{
    bool res = false;

    if(this->GetLatitud() != p.GetLatitud() || this->GetLongitud() != p.GetLongitud())
        res = true;

    return res;
}

Punto Punto::operator=(const Punto &p){
    if(this != &p){
        this->SetLatitud(p.GetLatitud());
        this->SetLongitud(p.GetLongitud());
        this->descripcion = p.descripcion;
    }
    return *this;
}

istream & operator>>(istream & is, Punto &p){
    char bas;
    is >> bas;
    is >> p.latitud;
    is >> bas;
    is >> p.longitud;
    is >> bas;
    return is;
}

ostream & operator<<(ostream & os, const Punto &p){
    os << "(" << p.latitud << "," << p.longitud << ")";
    return os;
}
