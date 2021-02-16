#include <iostream>
#include "diccionario.h"



/*Operator<<. Obsérvese el uso de 2 tipos diferentes de iteradores. Uno sobre 
listas de listas y otro sobre listas
*/
ostream & operator<<(ostream & os, const Diccionario<string,string> & D){
	  
	  //list<data<string,string> >::const_iterator it;
	  Diccionario<string,string>::const_iterator it;
	  
	  for (it=D.begin(); it!=D.end(); ++it){
	  
		    list<string>::const_iterator it_s;
		    
		    os<<endl<<(*it).clave<<endl<<" informacion asociada:"<<endl;
		    for (it_s=(*it).info_asoci.begin();it_s!=(*it).info_asoci.end();++it_s){
			      os<<(*it_s)<<endl;
		    }
		    os<<"**************************************"<<endl;
	  }
	  
	  return os;
}

/*Operator >>. El formato de la entrada es:
     numero de claves en la primera linea
     clave-iésima retorno de carro
     numero de informaciones asociadas en la siguiente linea
     y en cada linea obviamente la informacion asociada
*/

istream & operator >>(istream & is,Diccionario<string,string> &D){
	  int np;
	  is>>np;
	  is.ignore();//quitamos \n
	  Diccionario<string,string> Daux;
	  for (int i=0;i<np; i++){
		    string clave;

		    getline(is,clave); 
		    
		    int ns;
		    is>>ns; 
		    is.ignore();//quitamos \n
		    list<string>laux;
		    for (int j=0;j<ns; j++){
			      string s;
			      getline(is,s);
			      
			      // cout<<"Significado leido "<<s<<endl;
			      laux.insert(laux.end(),s);
		    }
		    Daux.Insertar(clave,laux);		      
		    
	  }
	  D=Daux;
	  return is;
}

/*Recorre la lista de información asociada a una clave y la imprime*/
void EscribeSigni(const list<string>&l){		 
	  list<string>::const_iterator it_s;
	  
	  for (it_s=l.begin();it_s!=l.end();++it_s){
		    cout<<*it_s<<endl;
	  }
}	


list<string> BusquedaPorLetra(char letra, const Diccionario<string,string> &D){
	Diccionario<string,string>::const_iterator it = D.begin();
	list<string> lista;
	string clave;
	bool encontrado = false;
	while(!encontrado && it != D.end()){
		clave = (*it).clave;
		if(clave.front() == letra){
			encontrado = true;
			lista.push_back(clave);
		}
		++it;
	}
	while(encontrado && it != D.end()){
		clave = (*it).clave;
		if(clave.front() == letra){
			lista.push_back(clave);
		}
		else
		{
			encontrado = false;
		}
		
		++it;
	}
	return lista;
}

void ImprimirAlreves(const Diccionario<string,string> &D) {
	if (D.size()== 0) return;
	Diccionario<string,string>::const_iterator it = D.end();

	do {
		--it;
		list<string>::const_iterator it_s;

		cout<<endl<<(*it).clave<<endl<<" informacion asociada:"<<endl;
		for(it_s=(*it).info_asoci.begin();it_s!=(*it).info_asoci.end();++it_s){
			cout<<(*it_s)<<endl;
		}
		cout<<"*************************************************"<<endl;
	}while(it!=D.begin());
}

string BusquedaPorDefinicion(list<string> def,const Diccionario<string,string> &D){
	Diccionario<string,string>::const_iterator it = D.begin();
	list<string>::const_iterator it_s;
	list<string>::const_iterator it_d = def.begin();
	bool encontrado = false;
	string clave;
	while(it != D.end() && !encontrado){
		for(it_s=(*it).info_asoci.begin();it_s!=(*it).info_asoci.end();++it_s){
			
			if((*it_s) == (*it_d)){
				clave = (*it).clave;
				encontrado = true;
			}
		}
		++it;
	}

	if(!encontrado)
		clave = "No se encontró";

	return clave;

}

void BorraDefinicion(string clave, Diccionario<string,string> &D){
	//Diccionario<string,string>::iterator it = D.begin();
	typename list<data<string,string> >::iterator it;

	if(D.Esta_Clave(clave,it)){
		(*it).info_asoci.clear();
	}
	else{
		cout<<"No existe la clave"<<endl;
	}
}




/*Lee un diccioario e imprime datos asociados a una clave. 
Hay un fichero ejemplo de prueba: data.txt.Para lanzar el programa con ese fichero se escribe: 
                  ./usodiccionario < data.txt 
*/
int main(){
 Diccionario<string,string> D;

cin>>D;
cout<<D;

string a;

cout<<"Introduce una palabra"<<endl;
cin>>a;

list<string>l=D.getInfo_Asoc(a);

if (l.size()>0)
	  EscribeSigni(l);


cout<<endl<<"Imprimiendo al reves ... "<<endl;
ImprimirAlreves(D);

cout<<endl<<"Buscando por primera letra C: "<<endl;
char letra = 'C';
list<string> busqueda = BusquedaPorLetra(letra, D);

if (busqueda.size()>0)
	EscribeSigni(busqueda);


list<string> definicion = l;
cout<<endl<<"Buscamos por definicion :"<<endl;
if (definicion.size()>0)
	  EscribeSigni(definicion);
cout<<endl<<"Palabra: "<<endl;
cout<<BusquedaPorDefinicion(definicion,D)<<endl;


cout<<endl<<"Eliminamos la definicion de la palabra Compilador"<<endl;
BorraDefinicion("Compilador", D);
cout<<D;







}

