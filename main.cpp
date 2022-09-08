/*----------------------------------------------------------
 * Realice un programa que permita almacenar 50 datos
 * aleatorios y los almacene en un arreglo estatico de
 * datos enteros y luego el programa :
 * 1) Imprima los valores mayores al promedio
 * 2) Halle el dato mayor
 * 3) Cuente la cantidad de datos pares y datos impares.
 ---------------------------------------------------------*/

#include <iostream>
using namespace std;

float hallarPromedio( int  *pIniciodelArreglo, int ne );
int hallaElMayor( int  *pI, int ne);
void contar( int *pInicio, int ne, int *nPares, int *nImpares);

int main()
{
    int arreglo[50];
    float promedio;
    int nPares=0, nImpares=0;

    srand(time(nullptr));
    for(int i=0; i<50; i++)
        arreglo[i] = rand() % 100;
    for(int i=0; i<50; i++)
        cout << "arreglo[" << i << "]= " << arreglo[i]  << "\n";
    promedio = hallarPromedio(arreglo, 50);
    cout << "El promedio es: " << promedio << "\n";
    cout << "Valores mayores al promedio\n";
    for(int i=0; i<50; i++)
        if( arreglo[i] > promedio)
            cout << arreglo[i] << "\n";
    int elMayor = hallaElMayor(arreglo, 50);
    cout << "El dato mas grande del arreglo es : " << elMayor << "\n";
    contar(arreglo, 50, &nPares, &nImpares);
    cout << "Numero de datos pares : " << nPares << "\n";
    cout << "Numero de datos impares : " << nImpares << "\n";


    return 0;
}

float hallarPromedio( int  *pIniciodelArreglo, int ne )
{
    float suma=0;
    for(int x=0; x<ne; x++)
        suma = suma + pIniciodelArreglo[x];
    return (suma / ne);
}


int hallaElMayor( int  *pI, int ne)
{
  int mayor= pI[0];
  for(int i=1; i<ne; i++)
      if(pI[i] > mayor)
          mayor = pI[i];
  return mayor;
}

void contar( int *pInicio, int ne, int *nPares, int *nImpares)
{
  for(int i=0; i<ne; i++)
      if( pInicio[i] %2==0)
          *nPares = *nPares + 1;
      else
          *nImpares = *nImpares + 1;
}