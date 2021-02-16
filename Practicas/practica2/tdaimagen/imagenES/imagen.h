
#ifndef _IMAGEN_H_
#define _IMAGEN_H_

#include <iostream>
using namespace std;

typedef unsigned char byte;

class Imagen{
    private:
        int filas;
        int cols;
        byte  **img;
        void copy(const Imagen & i);
        void limpiar();
    public:
        Imagen();
        Imagen(const Imagen & J);
        Imagen(int filas, int cols);
        ~Imagen();
        int num_filas() const;
        int num_columnas() const;
        void asigna_pixel(int fila, int col,byte valor);
        byte valor_pixel(int fila,int col) const;
        Imagen & operator=(const Imagen & J);
};

void Umbralizar(const char *entrada, const char *salida,int T1,int T2);
void Icono(const char *entrada, const char *salida,int nfi,int nci);


#endif