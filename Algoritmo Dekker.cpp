#include<iostream>
#include<conio.h> //Para usar funcion _getch()
#include<thread> //Para crear hilos de procesos

using namespace std;

bool turnop1 = false; //turno del proceso 1, si es false le toca a p2

void critical(int pn, int value) //Seccion o funcion critica, en este caso imprimir pantalla
{
    cout << "p" << pn << " : " << value << endl;
}

void p1() //Proceso 1
{
    for (int i = 1; i <= 10; i++) //Hara secuencia del 1 al 10
    {
        while (turnop1 == false); //Espera activa siempre que no sea su turno, turnop1 falso
        critical(1,i); //Usar la seccion critica
        turnop1 = false; //Soltar su turno
    }
}

void p2() //Proceso 2
{
    for (int t = -1; t >= -10; t--) //Hara secuencia del -1 al -10
    {
        while (turnop1 == true); //Espera activa siempre que no sea su turno, turno de p1
        critical(2,t); //Usar la seccion critica
        turnop1 = true; //Darle el turno al otro
    }
}



int main() //Principal
{
    cout << "Algoritmo de Exclusion Dekker. URBE 2021\n\n";
    cout << "Realizado por: Ing. Ricardo Celedon\nC.I.: V-24.361.484\n\n";
    cout << "Bienvenido profe, este es un programa con exclusion Dekker en el cual\ndos procesos tendran acceso la impresion en pantalla segun el turno que tengan.\n";
    cout << "Un proceso asignara valores positivos del 1 a l0, \ny el otro proceso valores negativos del -1 al -10.\n";
    cout << "El codigo esta preparado de forma que un proceso,\nprimero espere hasta que se habilite su turno para imprimir en pantalla,\n";
    cout << "luego cambia el valor del valor del turno para el otro proceso, \ny el otro proceso que estaba esperando, hace lo mismo, imprime el valor y asigna el turno al otro.\n\n";
    thread t1(p1); //Crear hilo 1 y ejecutar proceso 1
    thread t2(p2); //Crear hilo 2 y ejecutar proceso 2


    t2.join(); //Sincronizar antes de finalizar
    t1.join(); //Sincronizar antes de finalizar

    cout << "\n\nPresione cualquier tecla para continuar, y gracias por su atencion!...";
    _getch(); //Espera por tecla
    return 0;
}
