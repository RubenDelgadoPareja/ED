#include <iostream>
#include "imagen.h"
#include "imagenES.h"

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

void Umbralizar(const char *entrada, const char *salida,int T1,int T2){
    unsigned char *imagen;
    int nf, nc, npixeles;
    npixeles = nf*nc;
    imagen = LeerImagenPGM(entrada,nf,nc);

    if (!imagen){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        exit (1);
    }
    
   for (int i=0; i<nf*nc; i++){
        if( imagen[i] < T1 || imagen[i] > T2  )
            imagen[i] = 255;
    }

    
    if (EscribirImagenPGM(salida, imagen, nf,nc))
        cout  << "La imagen se guardo en " << salida << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        exit (2);
    }

    delete [] imagen;
};

void Icono(const char *entrada, const char *salida,int nfi,int nci){
    unsigned char *imagen;
    unsigned char *ico;
    ico = new unsigned char[nfi*nci];
    int nf, nc, npixeles;
    npixeles = nf*nc;
    imagen = LeerImagenPGM(entrada,nf,nc);

    cout << endl;
    cout << "Dimensiones de " << entrada << ":" << endl;
  
    cout << "   Imagen   = " << nfi  << " filas x " << nci << " columnas " << endl;

    if (!imagen){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        exit (1);
    }

    int redfila = nf/nfi;
    int redcolumna = nc/nci;
    unsigned char aux = 0;


    /*
    k=0;
    for(int i = 0; i < nfi*nci ; i++){
        for(int j= 0; j < redcolumna*redfila; j++){
            aux += imagen[k];
            //aux += imagen[k+1];
            k++;
        }
        ico[i] = aux/(redcolumna*redfila);
        aux = 0;

    }*/
    cout<<"SIDA"<<endl;
    Imagen img(nf,nc);
    for(int i=0; i<nf ; i++){
        for(int j=0; i<nc; j++)
            img.asigna_pixel(i,j,imagen[i+j]);
    }

    cout<<"SIDA"<<endl;
    int k=0;
    for(int i=0; i<nf ; i+=redfila){
        for(int j=0; j<nc; j+=redcolumna){
            for(int z = 0; z<redfila ; z++){
                for(int y = 0; y<redcolumna; y++){
                    aux += img.valor_pixel(i+z,j+y);
                }
            }
            if(k < nfi*nci)
                ico[k] = aux/(redfila*redcolumna);
            k++;
            aux = 0;
        }
    }
    /*
    for(int i=0; i<nf*nc; i++){
        for(int j=0; j<redfila*redcolumna; j++){
                aux += imagen[i+j];
        }
        ico[k] = aux/(redfila*redcolumna);
        aux = 0;
        k++;
    } */
   //ico = imagen;

    cout<<"SIDA"<<endl;
    if (EscribirImagenPGM(salida, ico, nfi,nci))
        cout  << "La imagen se guardo en " << salida << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        exit (2);
    }

    delete [] imagen;
    delete [] ico;
};