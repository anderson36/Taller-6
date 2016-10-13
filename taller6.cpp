/*Autor: Jhon Anderson Sanchez
Funcion del programa: Taller # 6 Matrices
Fecha:11/10/2016*/

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cmath>
#define MAX 5

using namespace std;

//declaracion de matriz
void llenarMatriz(int[MAX][MAX], int LM);
void mostrarMatriz(int[MAX][MAX], int LM);
void transpuestaM(int [MAX][MAX], int [][MAX],int LM);
void mostrarT(int [MAX][MAX],int LM);
int determinante(int matriz[MAX][MAX],int LM );
int cofactor(int matriz[MAX][MAX], int LM, int fila, int columna);
void Pausa ();

int main(){
    int matriz [MAX][MAX];
    int T[MAX][MAX];
    int opcion;
    int LM;

      cout << "Ingresa la longitud de la matriz (maximo " << MAX << "): ";
   cin >> LM;
   while (LM < 0 || LM > MAX) {
      cout << "\nLa lonngitud de la matriz no puede ser mayor que " << MAX << endl;
      cout << "Ingrese nuevamente la longitud  de la matriz: ";
      cin >> LM;
      }
    do{
    cout << "Menu Principal" << endl;
    cout << "Marque una opcion del menu" << endl;
    cout << "1.Llenar matriz" << endl;
    cout << "2.Mostrar matriz" << endl;
    cout << "3.Traspuesta de una Matriz" << endl;
    cout << "4.Determinante matriz" << endl;
    cout << "0.Salir" << endl;
    cin >> opcion;

    }while(opcion>4 || opcion<0);
    //llamado a las funciones en switch
    switch(opcion){

        case 0: cout << "Has finalazido el programa " << endl;
                cout << " Muchas gracias"<< endl;
        exit(0);
        case 1: cout << "Llenar matriz" << endl;
            llenarMatriz(matriz,LM);
            mostrarMatriz(matriz,LM);
            Pausa ();
            main();
        break;
        case 2: cout << "Mostrar matriz" << endl;
            llenarMatriz(matriz,LM);
            mostrarMatriz(matriz,LM);
            Pausa ();
            main();
        break;
        case 3: cout << "has seleccionado la transpuesta de una metriz" << endl;
                llenarMatriz(matriz,LM);
                transpuestaM(matriz, T,LM);
                cout<<"Matriz Original"<<endl;
                mostrarMatriz(matriz,LM);
                cout<<"Matriz Transpuesta"<<endl;
                mostrarT(T,LM);
                Pausa ();
                main();
        break;
        case 4: cout << "Determinante matriz" << endl;
            llenarMatriz(matriz,LM);
            mostrarMatriz(matriz,LM);
            cout << "La determinante es = "<< determinante(matriz,LM) << endl;
            Pausa ();
            main();
        break;
        default: cout << "Opcion no valida" << endl;

    }
    return 0;
}

// determinacion de las funciones
// se realizan todas los operaciones
void llenarMatriz(int matriz[MAX][MAX],int LM){
    for (int j=0;j<LM;j++) {
        for (int i=0;i<LM;i++) {
               matriz [j][i]=rand ()%100;

               cout << matriz [j][i]<< "\t";

    }
    cout << endl;
    }
    cout << endl << "Matriz llenada con exito" << endl << endl << endl;
}
void mostrarMatriz(int matriz[MAX][MAX],int LM){
    for (int j=0;j<LM;j++) {
        for (int i=0;i<LM;i++) {
              cout << matriz [j][i]<< "\t";

    }
    cout << endl << endl;
    }
}

void transpuestaM(int matriz[MAX][MAX], int T[MAX][MAX], int LM){
    for(int j = 0; j < LM; j++){
        for(int i = 0; i < LM; i++){
           T[j][i] = matriz[i][j];
        }
    }
    cout << endl;
}

void mostrarT(int T[MAX][MAX], int LM){
    for(int j = 0; j < LM; j++){
        for(int i = 0; i < LM; i++){
            cout<<T[j][i]<< "\t";
        }
        cout<<endl;
    }
}
int determinante(int matriz[MAX][MAX], int LM)
{
   int det = 0.0;

   if (LM == 1) {
      det = matriz[0][0];
   } else {
      for (int j = 0; j < LM; j++) {
         det = det + matriz[0][j] * cofactor(matriz, LM, 0, j);
      }
   }

   return det;
}


int cofactor(int matriz[MAX][MAX], int LM, int fila, int columna)
{
   int submatriz[MAX][MAX];
   int n = LM - 1;

   int x = 0;
   int y = 0;
   for (int i = 0; i < LM; i++) {
      for (int j = 0; j < LM; j++) {
         if (i != fila && j != columna) {
            submatriz[x][y] = matriz[i][j];
            y++;
            if (y >= n) {
               x++;
               y = 0;
            }
         }
      }
   }

   return pow(-1.0, fila + columna) * determinante(submatriz, n);
}

void Pausa ()
{
cout << "Pulse una tecla para continuar...";
if (!getch ())
getch ();
cout << endl;
}
