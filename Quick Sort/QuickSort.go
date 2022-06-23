package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
	"time"
)

//Algoritmo
func partition(arr []int, low, high int) ([]int, int) {
	pivot := arr[high]
	i := low - 1
	for j := low; j < high; j++ {
		if arr[j] <= pivot {
			i++
			arr[i], arr[j] = arr[j], arr[i]
		}
	}
	arr[i+1], arr[high] = arr[high], arr[i+1]
	return arr, i + 1
}

func quickSort(arr []int, low, high int) []int {
	if low < high {
		var p int
		arr, p = partition(arr, low, high)
		arr = quickSort(arr, low, p-1)
		arr = quickSort(arr, p+1, high)
	}
	return arr
}

//-------------------------------------------------

func main() {
	// Abrimos el archivo
	file, err := os.Open("Datos50000.txt")

	//Por si hubo un error al abrir el archivo
	if err != nil {
		log.Fatalf("Error al abrir el archivo: %s", err)
	}

	//Iniciamos el scanner
	fileScanner := bufio.NewScanner(file)

	//Variable que contendrá los datos leidos del txt
	var datos []int

	// Leemos el archivo linea por linea
	for fileScanner.Scan() {

		lineStr := fileScanner.Text() //obtenemos la cadena

		num, _ := strconv.Atoi(lineStr) //Convertimos la cadena a entero

		datos = append(datos, num) // lo agregamos al array da datos

	}

	// Por si hubo error al leer el archivo
	if err := fileScanner.Err(); err != nil {
		log.Fatalf("Error al leer el archivo: %s", err)
	}

	file.Close() // cerramos el archivo

	//corremos el algoritmo
	s := time.Now() //tiempo inicio
	arrOrdenado := quickSort(datos, 0, len(datos)-1)
	e := time.Since(s) //Teimpos transcurrido hasta el nuevo momento

	//imprimimos el Arreglo Ordenado
	for _, val := range arrOrdenado {
		fmt.Println(val)
	}

	fmt.Println(e)

}
