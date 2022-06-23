#include <bits/stdc++.h>
#include <ctime> 

using namespace std;

//función para realizar el intercambio
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//algoritmo
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1); 
 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        
        int pi = partition(arr, low, high);
 
      
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
//---------------------------------------------------
// Funcion para imprimir array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main() {
	unsigned t0, t1; // variables para el tiempo

    int datos[50000] = {0}; // arreglo que contendrá los datos del txt
	ifstream archivo;  //archivo
	string texto; //texto que se lee
	int i = 0; //var para ir colocando los valores a Datos

	archivo.open("Datos50000.txt",ios::in);//Abrimos el archivo en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";// Si existe un error
		exit(1);
	}
	while(!archivo.eof()){ //mientras no sea final del archivo
		getline(archivo,texto); //obtenemos la linea en la variabe texto
		int num =  atoi(texto.c_str());   // convertimos el string a int
		datos[i] = num;  //Ingresamos el valor al array
		i++;  // incrementamos contador
	}
	archivo.close(); //Cerramos el archivo
    int n = sizeof(datos) / sizeof(datos[0]);
    t0 = clock();//tiempo de inicio
	quickSort(datos, 0, n-1);  // Corremos la función
	t1 = clock(); //tiempo de fin 
	double time = (double(t1-t0)/CLOCKS_PER_SEC);// Obtenemos la diferencia entre el tiempo inicial y final

	cout << "El tiempo transcurrido es: " << time << endl;
    //printArray(datos, 50000); // imprimir datos

}