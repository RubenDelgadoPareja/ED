
//  Autores: Rubén Delgado Pareja y Alberto López Jiménez
#include <iostream>
#include <cstring>
#include <cstdlib>

#include <imagenES.h>
#include <imagen.h>

using namespace std;

int main (int argc, char *argv[]){
 
  char *origen, *destino; // nombres de los ficheros

  int menu = -1;

    if (argc != 3){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: negativo <FichImagenOriginal> <FichImagenDestino>\n";
    exit (1);
  }

  origen  = argv[1];
  destino = argv[2];

    do
    {
        cout<<"Menu: "<<endl;
        cout<<"Introduzca el valor 0: Umbralizar "<<endl;
        cout<<"Introduzca el valor 1: Zoom "<<endl;
        cout<<"Introduzca el valor 2: Constraste "<<endl;
        cout<<"Introduzca el valor 3: Morphing "<<endl;
        cin>>menu;

    } while ( -1 < menu > 4);

    switch (menu)
    {
    case 0:
        int T1, T2;
        cout<<"Has seleccionado Umbralizar"<<endl;
        cout<<"Introduzca valor inferior del intervalo"<<endl;
        cin>>T1;
        cout<<"Introduzca valor superior del intervalo"<<endl;
        cin>>T2;
        Umbralizar(origen,destino,T1,T2);
        break;
    case 1:
        int f1, c1, f2, c2;
        cout<<"Has seleccionado Zoom"<<endl;
        cout<<"Introduzca valor de la fila 1 "<<endl;
        cin>>f1;
        cout<<"Introduzca valor de la columna 1 "<<endl;
        cin>>c1;
        cout<<"Introduzca valor de la fila 2 "<<endl;
        cin>>f2;
        cout<<"Introduzca valor de la columna 2 "<<endl;
        cin>>c2;
        Zoom(origen,destino,f1,c1,f2,c2);
        break;
    case 2:
        int  min, max;
        cout<<"Has seleccionado Contraste"<<endl;
        cout<<"Introduzca valor del nuevo minimo entre 0-255"<<endl;
        cin>>min;
        cout<<"Introduzca valor del nuevo maximo entre 0-255"<<endl;
        cin>>max;
        Contraste(origen,destino,(unsigned char)min,(unsigned char)max);
        break;
    case 3: 
        cout<<"Has seleccionado Morphing"<<endl;
        Morphing(origen,destino);
        break;
    default:
        break;
    }
    
  cout << endl;
  cout << "Fichero origen: " << origen << endl;
  cout << "Fichero resultado: " << destino << endl;



    return (0);
}