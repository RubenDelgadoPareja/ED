#ifndef __PUNTO__H
#define __PUNTO__H
#include <ios>
#include <iostream>
#include <string>
using namespace std;

void QuitaSeparadores(istream &is){
    while (is &&(is.peek()=='\t' || is.peek()==' ' || is.peek()=='\n'))
        is.get();
}
/**
 * @class Punto 
 * @brief Esta clase se utiliza para definir puntos en el globo terraqueo 
 * contiene dos tipos doubles que corresponden con la latitud y longitud del punto
 * y un tipo string que corresponde a una pequeña descripcion del punto
 */
class Punto{
    private:
        double latitud, longitud; 
        string descripcion;

    public:
    /**
     * @brief Constructor por defecto
     */
    Punto(){ latitud=longitud=0;}
    /**
     * @brief Constructor por parametros 
     * @param lat: valor de la latitud entre -90 y 90
     * @param lon: valor de la longitud entre -180 y 180 
     * @param d: descripcion del punto
    */
    Punto(double lat, double lon, const string &d){
        if( lat > -90 && lat < 90 && lon > -180 && lon < 180 )
            latitud = lat;
            longitud = lon;
            descripcion = d;
    }
    /**
     * @brief Getter de latitud
     * @return devuelve el valor de la latitud del punto
     */
    double GetLatitud()const{
        return this->latitud;
    }
    /**
     * @brief Getter de longitud
     * @return devuelve el valor de la longitud del punto
     */
    double GetLongitud()const{
        return this->longitud;
    }
    /**
     * @brief Setter de latitud 
     * @param lat: Valor de la nueva latitud  
     */
    void SetLatitud(double lat){
        if(lat > -90 && lat < 90)
            this->latitud = lat;
    }
    /**
     * @brief Setter de longitud 
     * @param lon: Valor de la nueva longitud  
     */
    void SetLongitud(double lon){
        if(lon > -180 && lon < 180)
        this->longitud = lon;
    }

    /**
     * @brief Operador menor
     * @param p: Punto con el que vamos a comparar si es menor
     * @return Devuelve verdadero cuando p1<p2 y false cuando no
     */
    bool operator<(const Punto & p)const{
        bool res = false;
        if(this->GetLatitud() == p.GetLatitud()){
            if(this->GetLongitud() < p.GetLongitud())
                res = true;
        }
        else if(this->GetLatitud() < p.GetLatitud())
            res = true;

        return res;
    }
    /**
     * @brief Operador comparador
     * @param p: Punto con el que vamos a comparar
     * @return Devuelve verdadero si los puntos son iguales, false en caso contrario
     */
    bool operator==(const Punto &p)const{
        bool res = false;

        if(this->GetLatitud() == p.GetLatitud() && this->GetLongitud() == p.GetLongitud())
            res = true;

        return res;
    }
    /**
     * @brief Operador distinto
     * @param p: Punto con el que vamos a comparar
     * @return Devuelve verdadero si no son iguales y false en caso contrario
     */
    bool operator!=(const Punto &p)const{
        bool res = false;

        if(this->GetLatitud() != p.GetLatitud() || this->GetLongitud() != p.GetLongitud())
            res = true;

        return res;
    }
    /**
     * @brief Operador de asignacion
     * @param p: Punto del que vamos a copiar
     * @return Devuelve el punto que copiado 
     */
    Punto operator=(const Punto &p){
        if(this != &p){
            this->SetLatitud(p.GetLatitud());
            this->SetLongitud(p.GetLongitud());
            this->descripcion = p.descripcion;
        }
        return *this;
    }


    friend istream & operator>>(istream & is, Punto &p);
    friend ostream & operator<<(ostream & os, const Punto &p);


    //constructores, operadores de asignacion...
    //funciones de consulta y cambio de los miembros
    //iteradores 
    //funciones de lectura y escritura de puntos
};

/**
 * @brief Sobrecarga del operador de entrada
 * @param is: Flujo de entrada 
 * @param p: Punto que vamos a almacenar
 * @return flujo de entrada
 * 
 */
istream & operator>>(istream & is, Punto &p){
    long double valor_lat;
    long double valor_lon;
    char basura;
    QuitaSeparadores(is);
    is>>basura;
    is>>valor_lat;
    is>>basura;
    is>>valor_lon;
    is>>basura;

    p.SetLatitud(valor_lat);
    p.SetLongitud(valor_lon);

    return is;
}
/**
 * @brief Sobrecarga del operador de salida
 * @param os: Flujo de salida 
 * @param p: Punto que vamos a imprimir
 * @return Flujo de salida
 */
ostream & operator<<(ostream & os, const Punto &p){
    os << "(" << p.latitud << "," << p.longitud << ")";
    return os;
}



#endif

