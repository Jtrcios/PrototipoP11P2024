#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

#define NUMERO_CAMARAS 3
#define NUMERO_MATERIAS 5
#define NUMERO_ANOS 4
#define MAX_MONTO 1000
#define MIN_MONTO 0
#define MAXIMA_LONGITUD_CADENA 1000

void llamaCiclo();
int busquedaAleatorios(int minimo, int maximo);
void llenarMatriz(float matriz[NUMERO_CAMARAS][NUMERO_ANOS + 1]);
void imprimirMatrizLinea();
float imprimirMatriz(float matriz[NUMERO_CAMARAS][NUMERO_ANOS + 1], char alumnos[NUMERO_CAMARAS][MAXIMA_LONGITUD_CADENA], string nombreFacultad);
int main()
{
    srand(getpid());
    llamaCiclo();
    return 0;
}
void llamaCiclo()
{
    float matriz_facultad_1[NUMERO_CAMARAS][NUMERO_ANOS + 1];
    float matriz_facultad_2[NUMERO_CAMARAS][NUMERO_ANOS + 1];
    float matriz_facultad_3[NUMERO_CAMARAS][NUMERO_ANOS + 1];
    float matriz_facultad_4[NUMERO_CAMARAS][NUMERO_ANOS + 1];
    float matriz_facultad_5[NUMERO_CAMARAS][NUMERO_ANOS + 1];
    char opcion;
    bool repetir = true;

    float promedio_facultad_1;
    float promedio_facultad_2;
    float promedio_facultad_3;
    float promedio_facultad_4;
    float promedio_facultad_5;

    char alumnos[NUMERO_CAMARAS][MAXIMA_LONGITUD_CADENA] = {"C.Indust","C.Construcc","C.Transport"};
    do
    {
        system("cls");
        promedio_facultad_1=0;
        promedio_facultad_2=0;
        promedio_facultad_3=0;
        promedio_facultad_4=0;
        promedio_facultad_5=0;
        cout << "*** Comparativo de Empresas: ***" << endl << endl;
        llenarMatriz(matriz_facultad_1);
        promedio_facultad_1 = imprimirMatriz(matriz_facultad_1, alumnos, "Jacinto Mora");
        llenarMatriz(matriz_facultad_2);
        promedio_facultad_2 = imprimirMatriz(matriz_facultad_2, alumnos, "Lonera Lopez");
        llenarMatriz(matriz_facultad_3);
        promedio_facultad_3 = imprimirMatriz(matriz_facultad_3, alumnos, "MegaCorp");
        llenarMatriz(matriz_facultad_4);
        promedio_facultad_4 = imprimirMatriz(matriz_facultad_4, alumnos, "PollitoFeliz");
        llenarMatriz(matriz_facultad_5);
        promedio_facultad_5 = imprimirMatriz(matriz_facultad_5, alumnos, "Sierra S.A");
        if (promedio_facultad_1 > promedio_facultad_2 && promedio_facultad_1 > promedio_facultad_3 && promedio_facultad_1 > promedio_facultad_4 && promedio_facultad_1 > promedio_facultad_5)
        {
            cout << " La Empresa con mejores ventas fue : " << "Jacinto Mora" << " Promedio: " << promedio_facultad_1 << endl;
        } else
        if (promedio_facultad_2 > promedio_facultad_1 && promedio_facultad_2 > promedio_facultad_3 && promedio_facultad_2 > promedio_facultad_4 && promedio_facultad_2 > promedio_facultad_5)
        {
            cout << " La Empresa con mejores ventas fue : " << "Lonera Lopez" << " Promedio: " << promedio_facultad_2 << endl;
        } else
        if (promedio_facultad_3 > promedio_facultad_1 && promedio_facultad_3 > promedio_facultad_2 && promedio_facultad_3 > promedio_facultad_4 && promedio_facultad_3 > promedio_facultad_5)
        {
            cout << " La Empresa con mejores ventas fue : " << "MegaCorp" << " Promedio: " << promedio_facultad_3 << endl;
        } else
        if (promedio_facultad_4 > promedio_facultad_1 && promedio_facultad_4 > promedio_facultad_2 && promedio_facultad_4 > promedio_facultad_3 && promedio_facultad_4 > promedio_facultad_5)
        {
            cout << " La Empresa con mejores ventas fue : " << "PollitoFeliz" << " Promedio: " << promedio_facultad_4 << endl;
        } else
        if (promedio_facultad_5 > promedio_facultad_1 && promedio_facultad_5 > promedio_facultad_2 && promedio_facultad_5 > promedio_facultad_3 && promedio_facultad_5 > promedio_facultad_4)
        {
            cout << " La Empresa con mejores ventas fue : " << "Sierra S.A" << " Promedio: " << promedio_facultad_5 << endl;
        } else
        {
            cout << " Algunas facultades tienen el mismo promedio " << endl << endl;
        }
        cout << "Desea otro calculo (s/n)? ";
        cin >> opcion;
        if (opcion == 'n')
        {
            repetir=false;
        }
    } while (repetir);
}
int busquedaAleatorios(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void llenarMatriz(float matriz[NUMERO_CAMARAS][NUMERO_ANOS + 1])
{
    int y, x;
    for (y = 0; y < NUMERO_CAMARAS; y++)
    {
        float suma = 0;
        int calificacion = 0;
        for (x = 0; x < NUMERO_ANOS; x++)
        {
            if (x == 0 || x == 3)  //primer parcial
            {
                calificacion = busquedaAleatorios(MIN_MONTO, 20);
            } else if (x == 1)  //segundo parcial
            {
                calificacion = busquedaAleatorios(MIN_MONTO, 25);
            } else if (x == 2)  //examen final
            {
                calificacion = busquedaAleatorios(MIN_MONTO, 35);
            }
            suma += (float)calificacion;
            matriz[y][x] = calificacion;
            calificacion=0;
        }
        // Agregar promedio

        matriz[y][NUMERO_ANOS] = suma;
    }
}

void imprimirMatrizLinea()
{
    int x;

    cout << "+-----------ç";
    for (x = 0; x < NUMERO_ANOS + 1; x++)
    {
        cout << "+--------";
    }
    cout << "+\n";
}
float imprimirMatriz(float matriz[NUMERO_CAMARAS][NUMERO_ANOS + 1], char alumnos[NUMERO_CAMARAS][MAXIMA_LONGITUD_CADENA], string nombreFacultad)
{
    //Funciòn que imprime la matriz en pantalla y realizando los calculos necesarios del promedio
    int y, x;

    float promedioMayor = matriz[0][NUMERO_ANOS];
    float promedioMenor = matriz[0][NUMERO_ANOS];
    float totalGeneral = 0;
    float promedioGeneral = 0;
    char alumnoPromedioMayor[MAXIMA_LONGITUD_CADENA];
    char alumnoPromedioMenor[MAXIMA_LONGITUD_CADENA];
    memcpy(alumnoPromedioMayor, alumnos[0], MAXIMA_LONGITUD_CADENA);
    memcpy(alumnoPromedioMenor, alumnos[0], MAXIMA_LONGITUD_CADENA);
    cout << nombreFacultad << endl;
    cout << "(Nota1)=>Primer Parcial  (Nota2)=>Segundo Parcial (Nota3)=>Final (Nota4)=>Actividades" << endl;
    imprimirMatrizLinea();
    cout << setw(9) << "Alumno";
    for (x = 0; x < NUMERO_ANOS; x++)
    {
        cout << setw(9) << "Venta" << x + 1;
    }
    cout << setw(8) << "Tot" << endl;
    imprimirMatrizLinea();
    for (y = 0; y < NUMERO_CAMARAS; y++)
    {
        cout << "!" << setw(8) << alumnos[y] << "!";
        float suma = 0;
        for (x = 0; x < NUMERO_ANOS; x++)
        {
            int calificacion = matriz[y][x];
            cout << setw(9) << calificacion << "!";
        }
        float promedio = matriz[y][NUMERO_ANOS];
        totalGeneral += matriz[y][NUMERO_ANOS];
        if (promedio > promedioMayor)
        {
            promedioMayor = promedio;
            memcpy(alumnoPromedioMayor, alumnos[y], MAXIMA_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor)
        {
            promedioMenor = promedio;
            memcpy(alumnoPromedioMenor, alumnos[y], MAXIMA_LONGITUD_CADENA);
        }
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }
    promedioGeneral = totalGeneral / NUMERO_CAMARAS;
    cout << "Venta mayor: " << setw(10) << alumnoPromedioMayor <<  setw(10) << promedioMayor << endl;
    cout << "Venta menor: " << setw(10) << alumnoPromedioMenor <<  setw(10) << promedioMenor << endl;
    cout << "Promedio ventas : " << setw(10) <<  promedioGeneral << endl << endl;
    return promedioGeneral;
}
