#include <iostream>
#include "imagen.h"

using namespace std;

Imagen::Imagen(){};

Imagen::Imagen(const Imagen & J){
    this->copy(J);
};

Imagen::Imagen(int filas, int cols){
    if(filas > 0 && cols > 0){
        this->filas = filas;
        this->cols = cols;
        img = new byte*[filas];
        for(int i=0; i<cols; i++)
            img[i] = new byte[cols];
    }
};

Imagen::~Imagen(){
    this->filas = 0;
    this->cols = 0;
    this->limpiar();
};

int Imagen::num_filas() const{
    return this->filas;
};

int Imagen::num_columnas() const{
    return this->cols;
};

void Imagen::asigna_pixel(int fila,int col, byte valor){
    if(0 <= filas < num_filas() && 0 <= col < num_columnas() && 0<= valor <=255)  
        this->img[fila][col] = valor;   
};

byte Imagen::valor_pixel(int fila,int col) const{
    byte valor = -1;
    if(0 <= filas < num_filas() && 0 <= col < num_columnas())
        valor = this->img[fila][col];
    return valor;    
};

Imagen & Imagen::operator=(const Imagen & J){
    if(this != &J){
        this->limpiar();
        this->copy(J);
    }
};

void Imagen::limpiar(){
    for(int i=0; i<this->num_filas(); i++){
        delete []img[i];
    }
    delete []img;
};

void Imagen::copy(const Imagen & im){
    this->filas = im.num_filas();
    this->cols = im.num_columnas();
    this->img = new byte*[filas];
    for(int i=0; i<cols; i++)
        this->img[i] = new byte[cols];

    for(int i=0; i<filas; i++){
        for(int j=0; j<cols; j++){
            this->asigna_pixel(i,j,im.valor_pixel(i,j));
        }
    }
};
