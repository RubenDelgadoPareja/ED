// Autores : Rubén Delgado Pareja y Alberto Loṕez Jiménez

#include <iostream>
#include "imagen.h"
#include "imagenES.h"
#include <math.h>

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
        for(int i=0; i<filas; i++)
            img[i] = new byte[cols];
    }
};
Imagen::Imagen(int filas,int cols, const unsigned char * vector){
    if(filas > 0 && cols > 0){
        this->filas = filas;
        this->cols = cols;
        img = new byte*[filas];
        for(int i=0; i<filas; i++)
            img[i] = new byte[cols];

        int k=0;
        for(int i=0; i<filas; i++){
            for(int j=0; j<cols; j++){
                img[i][j]=vector[k];
                k++;
            }
        }

    }
}

Imagen::~Imagen(){
    this->filas = 0;
    this->cols = 0;
    this->limpiar();
};

unsigned char * Imagen::Convertir(){
    unsigned char * imagen = new unsigned char[this->num_filas()*this->num_columnas()];

    int k=0;
    for(int i=0; i<this->num_filas(); i++){
        for(int j=0; j<this->num_columnas();j++){
            imagen[k] = this->valor_pixel(i,j);
            k++;
        }
    }
    return imagen;
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
bool Imagen::operator==(const Imagen & J){
    bool valor = true;

    if( this->cols == J.cols && this->filas == J.filas ){
        for(int i=0; i<this->filas && valor; i++){
            for(int j=0; j<this->cols && valor ; j++){
                if(this->valor_pixel(i,j) != J.valor_pixel(i,j))
                    valor = false;
            }   
        }
    } 
    else 
        valor = false;
    
    return valor;
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
    // Leemos la imagen del fichero de entrada y la almacenamos en el vector de bytes
    imagen = LeerImagenPGM(entrada,nf,nc);

    if (!imagen){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        exit (1);
    }
    //Creamos una instancia de clase Imagen con el vector de bytes
    Imagen img(nf,nc,imagen);

    // Recorremos las posiciones de la imagen y modificamos en el caso de que el valor no se encuentre en el intervalo 
   for (int i=0; i<nf; i++){
        for(int j=0; j<nc; j++){
            if( img.valor_pixel(i,j) < T1 || img.valor_pixel(i,j) > T2  )
                img.asigna_pixel(i,j,255);      // Dejamos en blanco (255) los que no estén  en el intervalo
        }
    }

    //Escribimos la imagen en el fichero de salida
    if (EscribirImagenPGM(salida, img.Convertir(), nf,nc))
        cout  << "La imagen se guardo en " << salida << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        exit (2);
    }

    delete [] imagen;
};


void Zoom(const char* entrada, const char* salida, int f1, int c1, int f2, int c2) {

	int nf = 0 , nc = 0;
	double media = 0;
    int cont_1 = 0, cont_2 = 0;
	int nfil = f2 - f1 + 1;
	int ncol = c2 - c1 + 1;
	unsigned char* img;

	if (nfil == ncol) { //Requisitos para hacer zoom, que sea cuadrada


        // Leemos el tipo de imagen
		TipoImagen tipo = LeerTipoImagen(entrada);

        // Leemos la imagen del fichero de entrada y la almacenamos en el vector de bytes
		img = LeerImagenPGM(entrada, nf, nc);

        //creamos una instancia de la clase Imagen con los datos del vector que guarda la imagen
		Imagen imagen(nf, nc, img);
	
        //creamos una imagen auxiliar vacia para guardar la parte donde haremos zoom
		Imagen aux(nfil, ncol);
        cont_1 = 0;
		for (int i = f1; i <= f2; i++) { 
			for (int j = c1; j <= c2; j++) { 
				aux.asigna_pixel(cont_1, cont_2, imagen.valor_pixel(i,j));  // Rellenamos la imagen con la parte del zoom
				cont_2++;
			}
			cont_2=0;
			cont_1++;
		}

		//en caso de ser una imagen PGM podremos interpolar 
		if (tipo == IMG_PGM) {
			
			//Creamos otra imagen auxiliar vacia para interpolar las columnas
			Imagen aux_col(aux.num_filas(),2*aux.num_columnas() - 1);

			cont_1 = 0;
            cont_2 = 0;
			
			for (int i = 0; i < aux.num_filas() - 1; i++) {
				for (int j = 0; j < aux.num_columnas() - 1; j++) { 
                    // Interoplamos las columnas
					media = (aux.valor_pixel(i, j) + aux.valor_pixel(i, j+1))/2;  
					aux_col.asigna_pixel(cont_1, cont_2, aux.valor_pixel(i, j));
					cont_2++;
					aux_col.asigna_pixel(cont_1, cont_2, round(media));
					cont_2++;
					aux_col.asigna_pixel(cont_1, cont_2, aux.valor_pixel(i, j+1)); 	
				}
				cont_2 = 0;
				cont_1++;
			}

			Imagen aux_filas(2*aux.num_filas() - 1, aux_col.num_columnas());


			//Creamos otra imagen auxiliar para interpolar las filas
			media = 0;
            cont_1 = 0;
            cont_2 = 0;
			for (int i = 0; i < aux_col.num_columnas() - 1; i++) {
				for (int j = 0; j < aux_col.num_filas() - 1; j++) {
                    //Interpolamos las filas
					media = (aux_col.valor_pixel(j, i) + aux_col.valor_pixel(j+1, i))/2;
					aux_filas.asigna_pixel(cont_1, cont_2, aux_col.valor_pixel(j, i));
					cont_1++;					
					aux_filas.asigna_pixel(cont_1, cont_2, round(media));
					cont_1++;
					aux_filas.asigna_pixel(cont_1, cont_2, aux_col.valor_pixel(j+1, i)); 
				}
				cont_1 = 0;
				cont_2++;
			}
			
            //Escribimos la imagen en el fichero de salida
			EscribirImagenPGM(salida, aux_filas.Convertir(), aux_filas.num_filas(), aux_filas.num_columnas()); 
		}

	}
	delete[] img;

    
};

void Contraste(const char* entrada, const char* salida, byte min, byte max){


    int nf, nc;
    unsigned char * imagen;
    // Leemos la imagen del fichero de entrada y la almacenamos en el vector de bytes
    imagen = LeerImagenPGM(entrada, nf, nc );

    double menor = 255;
    double mayor = 0;

    //Calculamos el valor max y min de la imagen de entrada 
    // No tiene porqué ser  [0,255]
    for(int i=0; i<nf*nc; i++){
        if( menor > imagen[i])
            menor = imagen[i];
        if( mayor < imagen[i])
            mayor = imagen[i];
    }

    // Almacenamos en una variable la operacion constante
    double constante = (double(max) - double(min))/(mayor - menor);
    double valor = 0;

    // Cremaos una instancia de la clase imagen con el vector de bytes
    Imagen img(nf,nc,imagen);

    for(int i=0; i<nf; i++){
        for(int j=0; j<nc; j++){
            // Calculamos el nuevo valor del byte
            valor = double(min) + ( constante * (double(img.valor_pixel(i,j)) - menor ) );
            img.asigna_pixel(i,j, round(valor));  // Almacenamos el nuevo valor redondeado
        }
    }
    //Escribimos la imagen en el fichero de salida
    EscribirImagenPGM(salida, img.Convertir(), img.num_filas(), img.num_columnas()); 

    delete[] imagen;

};

void Morphing(const char* fichero1, const char* fichero2){

    int nf1, nc1;
    // Creamos la instancia Imagen y almancenamos directamente el vector que se genera del fichero1 de entrada 
    Imagen imagen1(nf1,nc1, LeerImagenPGM(fichero1,nf1,nc1));

    int nf2, nc2;
    // Creamos la instancia Imagen y almancenamos directamente el vector que se genera del fichero2 de entrada
    Imagen imagen2(nf2,nc2, LeerImagenPGM(fichero2,nf2,nc2));

    //Comprobamos que tengan las mismas filas y columnas para poder hacer el morphing
    if(  (nf1 == nf2 ) && (nc1 == nc2 ) ){

        string nombre = "";
        //Recorremos 256 veces como maximo mientra que las imagenes sean distintas
        for(int k=0; k< 256 && !(imagen1==imagen2); k++){

            //Recorremos las filas y columnas de las dos imagenes 
            for(int i=0; i<imagen1.num_filas(); i++){
                for(int j=0; j<imagen1.num_columnas(); j++){
                    // En el caso de que el pixel de la imagen1 sea menor que el de la imagen 2 se le suma 1
                    if(imagen1.valor_pixel(i,j) < imagen2.valor_pixel(i,j))
                        imagen1.asigna_pixel(i,j,imagen1.valor_pixel(i,j) + 1 );
                    // En el caso de que el pixel de la imagen1 sea mayor que el de la imagen 2 se le resta 1
                    else if(imagen1.valor_pixel(i,j) > imagen2.valor_pixel(i,j))
                         imagen1.asigna_pixel(i,j,imagen1.valor_pixel(i,j) - 1 );
                    //En el caso que tengan el mismo valor no se hace nada
                }
            }

            //Creamos un string para modificar el nombre de cada imagen que generamos y le añadimos la extension .pgm
            nombre += to_string(k+1);
            nombre += ".pgm";

            //Hacemos un casting de string a puntero char con c_str()
            const char* salida = nombre.c_str();

            // Escribimos la imagen en el fichero de salida
            EscribirImagenPGM(salida, imagen1.Convertir(), imagen1.num_filas(), imagen1.num_columnas());
            
            //Borramos el string para que no se acumule entre iteraciones, haciendo uso de la funcion clear de la STL
            nombre.clear();

        }

        
    }

};
