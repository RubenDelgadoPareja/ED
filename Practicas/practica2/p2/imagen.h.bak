
/*********************************************************************************************/
//  Autores: Rubén Delgado Pareja y Alberto López Jiménez
//  Fichero: imagen.h
//  Implementacion del TDA Imagen con escala de grises
/*********************************************************************************************/

#ifndef _IMAGEN_H_
#define _IMAGEN_H_

#include <iostream>
using namespace std;

typedef unsigned char byte;

/**
 * @class Imagen
 * @brief Representa una imagen en blanco y negro , mediante una matriz de bytes, que son número
 * en el intervalo [0,255] que indican el nivel de luminosidad del pixel. Las filas y las columnas
 * de la matriz representan la dimension de la imagen
 */
class Imagen{
    private:
        int filas;
        int cols;
        byte  **img;

        /**
         * @brief Copia una imagen que se pasa por parametro a la imagen que llama a la funcion
         * @param   i Imagen que vamos a copiar
         */
        void copy(const Imagen & i);
        /**
         * @brief Borramos la memoria dinamica
         */
        void limpiar();
    public:
        /**
         * @brief Constructor por defecto
         * @return Devuelve una imagen vacia
         */
        Imagen();
        /**
         * @brief Constructor por copia 
         * @param J Imagen que vamos a copiar
         * @return Imagen copiada
         */
        Imagen(const Imagen & J);
        /**
         * @brief Constructor por filas y columnas
         * @param filas Filas que tendrá la imagen
         * @param cols Columnas que tendrá la imagen
         * @return Imagen con las dimensiones de las filas y las columnas
         * pero vacia
         */
        Imagen(int filas, int cols);
        /**
         * @brief Constructor por filas, columas y un vector de bytes
         * @param filas Filas que tendrá la imagen
         * @param cols Columnas que tendrá la iamgen
         * @param vect Valores de los píxeles de la imagen
         * @return Imagen completa con los valores del vector
         */
        Imagen(int filas, int cols,const unsigned char * vect);
        /**
         * @brief Destructor de Imagen
         */
        ~Imagen();
        /**
         * @brief Funcion que convierte una instacia de la clase Imagen a un vector de byte
         * @return Un vector de byte
         */
        unsigned char * Convertir();
        /**
         * @brief Funcion que nos devuelve el numero de filas de una imagen
         * @return Filas de una imagen
         */
        int num_filas() const;
        /**
         * @brief Funcion que nos devuelve el numero de columnas de una imagen
         * @return Columnas de una imagen
         */
        int num_columnas() const;
        /**
         * @brief Funcion para asigna un valor a un pixel determinado
         * @param fila Fila donde se encuentra el pixel
         * @param col Columna donde se encuentra el pixel
         * @param valor Valor del pixel que vamos a asignar
         * @return Nada, se modifica la imagen que llama a la funcion
         */
        void asigna_pixel(int fila, int col,byte valor);
        /**
         * @brief Funcion para obtener el valor de un determinado pixel de la imagen
         * @param fila Fila donde se encuentra el pixel
         * @param col Columana donde se encuentra el pixel
         * @return Byte que es el valor del pixel en esa posicion
         */
        byte valor_pixel(int fila,int col) const;
        /**
         * @brief Sobrecarga del operador de asignación, permite copar una Imagen en otra
         * @param J Imagen que vamos a copiar
         * @return Nueva Imagen copiada
         */
        Imagen & operator=(const Imagen & J);
        /**
         * @brief Sobrecargar del operador de comprobacion (==), permite concer si dos imagenes
         * son iguales
         * @param J Imagen que se quiere comparar
         * @return Booleano que devuelve true en caso de que sean iguales y false en caso contrario
         */
        bool operator==(const Imagen & J);
};
/**
         * @brief Funcion que dado un intervalo por parametros, comprueba cada valor de los píxeles
         * haciendo que los que se encuentren fuera del intervalo se pongan en blanco (valor 255)
         * @param entrada Fichero de entrada, que es la imagen que vamos a cambiar
         * @param salida Fichero de salida, que es la imagen que vamos a generar 
         * @param T1 Valor inferior del intervalo
         * @param T2 Valor superior del intervalo
         * @return Nada
         */
void Umbralizar(const char *entrada, const char *salida,int T1,int T2);
/**
         * @brief Funcion que dada una imagen y 2 puntos (fila y columna) de esta, nos devuelve
         * una imagen cuadrada en la que la esquina superior izquierda es el primer punto y la 
         * esquina inferior derecha el segundo punto
         * @param entrada Fichero de entrada, que es la imagen que vamos a cambiar
         * @param salida Fichero de salida, que es la imagen que vamos a generar 
         * @param f1 Fila del primer punto
         * @param c1 Columna del primer punto
         * @param f2 Fila del segundo punto
         * @param c2 Columna del segundo punto
         * @return Nada
         */
void Zoom(const char* entrada, const char* salida, int f1, int c1, int f2, int c2);
/**
         * @brief Funcion que convierte la imagen de entrada con una transformacion lineal
         *  en otra imagen cuyos valores estarán dentro del intervalo que se pasa por parámetro.
         * @param entrada Fichero de entrada, que es la imagen que vamos a cambiar
         * @param salida Fichero de salida, que es la imagen que vamos a generar 
         * @param min Valor inferior del intervalo
         * @param max Valor superior del intervalo
         * @return Nada
         */
void Contraste(const char* entrada, const char* salida, byte min, byte max);
/**
         * @brief Funcion que genera una secuencia de imagenes las cuales se van modificando
         * para que la imagen de entrada se convierta en la imagen de salida, genera como maximo
         * 256 imagenes.
         * @param entrada Fichero de entrada, que es la imagen incial
         * @param salida Fichero de salida, que es la imagen final
         * @return Nada
         */
void Morphing(const char* fichero1, const char* fichero2);

#endif
