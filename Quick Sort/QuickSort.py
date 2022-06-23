import time
#Algoritmoooooo
def partition(array, low, high):
 
  pivot = array[high]
 
  i = low - 1
 
  for j in range(low, high):
    if array[j] <= pivot:
      i = i + 1
 
      (array[i], array[j]) = (array[j], array[i])
 
  (array[i + 1], array[high]) = (array[high], array[i + 1])
 
  return array, i + 1
 
def quick_sort(array, low, high):
  if low < high:
 
    array, p = partition(array, low, high) 
    array = quick_sort(array, low, p - 1) 
    array = quick_sort(array, p + 1, high)
    
  return array

#-----------------------------------------------------------------


archivo = open("Datos50000.txt", "r", encoding='utf-8') #Se abre el archivo
datos = [] #variable que almacenará los datos del txt
#Leemos los datos
while(True):
    linea = archivo.readline() #Lee la linea
    if not linea:
        break #Si ya no existe la linea, entonces corta el bucle
            
    datos.append(int(linea.strip()))#Convertimos a entero y lo agregamos al array
archivo.close #Cerramos el archivo

#Corremos el algoritmo
start = time.time() #tiempo de inicio
arr = quick_sort(datos, 0, len(datos)-1)
end = time.time() #tiempo de fin

#Imprimimos el arreglo
for i in range(1, len(arr)):
    print(arr[i])
    
print(end-start) #Imprimos el tiempo que se demoró (end - start)
         

         
