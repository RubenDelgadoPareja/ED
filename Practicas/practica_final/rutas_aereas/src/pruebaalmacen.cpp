#include <iostream>
#include <cmath>
#include <fstream>
#include "almacen_rutas.h"
using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
    cout<<"Dime el nombre del fichero de entrada"<<endl;
    return 0;
  }
  ifstream f(argv[1]);
  if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }

  cout<<"Llega hasta aqui"<<endl;
  Almacen_Rutas Ar;
  f>>Ar;
  cout<<Ar;
}