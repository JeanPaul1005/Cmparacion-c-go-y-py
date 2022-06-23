#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::cout; 
using std::cin;
using std::endl;
using std::ifstream;
using namespace std;

int main(){
	
	ofstream archivo;
	string nombreArchivo = "Datos50000.txt";
	
	archivo.open(nombreArchivo.c_str(),ios::out); 
	
	if(archivo.fail()){ 
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}	
	
	for(int i = 0; i < 50000; i++){
		fflush(stdin);
		int n = rand()%1001; 
		archivo<<n<<endl;
	}
	
	/*
	vector<int> datos;
	ifstream archivo;
	string texto;
	
	archivo.open("C:\\Users\\LAB-C\\Downloads\\Gerador LP\\DatosGenerados.txt",ios::in);//Abrimos el archivo en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	while(!archivo.eof()){ //mientras no sea final del archivo
		getline(archivo,texto);
		int num =  atoi(texto.c_str()); 
		datos.push_back(num);
	}
	archivo.close(); //Cerramos el archivo
	*/
	
	
	
}

