#include <iostream>

using namespace std;

// Diseñado por: Ing. Ricardo Celedon
// Maracaibo, Venezuela, 24/03/2021

int main()
{
    float vector[10]; //Vector de almacenamiento
    float prueba;
    bool salir = false; //Para salir del programa
    bool valido;
    char sino; //Eleccion de dos valores

    cout << "Bienvenido a Positipar v0.1a!\n\n";

    do //Ciclo principal del programa
    {
        cout << "Por favor introduzca 10 valores\n";
        cout << "Los valores en posicion 0 y pares solo aceptaran valores positivos enteros\n";
        cout << "Las posiciones impares solo aceptaran valores negativos\n\n";

        for (int i = 0; i < 10; i++) //Ciclo de lectura de datos y almacenado en vector
        {
            do
            {
                cout << "(" << i << "/9) -> "; //Muestra la posicion actual (indice)
                cin >> prueba; //Se guarda el valor en el indice definido

                //Se valida si el indice es par, si el valor es positivo, y si al restarle su parte entera quedan 0 decimales
                if (((i % 2) == 0) && (prueba >= 0) && (prueba-(int)prueba == 0))
                {
                    valido = true;
                    vector[i] = prueba;
                }
                //Se valida si el indice es impar, y si el valor es negativo
                else if (((i % 2) != 0) && (prueba < 0))
                {
                    valido = true;
                    vector[i] = prueba;
                }
                else //Si nada de eso se cumple, muestra error y vuelve a pedir el valor hasta que sea valido
                {
                    cout << "Error! ";
                    valido = false;
                }
            }
            while (valido == false);

        }

        cout << "\n\n";
        do //Ciclo de validacion de eleccion s/n
        {
            cout << "Desea volver a empezar? (s/n): ";
            cin >> sino;
        }
        while (!((sino == 'n') || (sino == 's')));

        if (sino == 's')
        {
            system("cls"); //Limpia la pantalla y se reinicia el ciclo principal
        }
        else
        {
            salir = true; //Rompe el ciclo principal
        }

    }
    while (salir == false);

    cout << "\n\n\nGracias por usar Positipar v0.1a!\n\n";

    return 0;
}
