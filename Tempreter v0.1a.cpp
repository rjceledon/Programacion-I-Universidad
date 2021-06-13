#include <iostream>

using namespace std;

// Diseñado por: Ing. Ricardo Celedon
// Maracaibo, Venezuela, 24/03/2021

int main()
{
    float temp[10]; //Vector que almacenara las temperaturas
    float tempMax, tempMin, tempProm; //Variables de calculo
    bool salir = false; //Para salir del programa
    char sino; //Eleccion de dos valores

    cout << "Bienvenido a Tempreter v0.1a!\n\n";

    do //Ciclo principal del programa
    {
        tempProm = 0; //Inicializacion de promedio en cada ciclo

        cout << "Por favor introduzca 10 temperaturas obtenidas:\n\n";

        for (int t = 1; t <= 10; t++) //Ciclo de lectura de datos y almacenado en vector
        {
            cout << "(" << t << "/10) -> ";
            cin >> temp[t - 1];
        }

        tempMax = tempMin = temp[0]; //Inicializacion tomando el primer valor

        for (int m = 0; m < 10; m++) //Ciclo de analisis de vector
        {
            if (temp[m] > tempMax) //Condicion de mayor que
            {
                tempMax = temp[m];
            }

            if (temp[m] < tempMin) //Condicion de menor que
            {
                tempMin = temp[m];
            }

            tempProm += temp[m]; //Acumulacion de datos en variable para promedio
        }

        tempProm = tempProm / 10; //Calculo de promedio

        cout << "\n\nLa Maxima temperatura obtenida fue de: " << tempMax;
        cout << "\nLa minima temperatura obtenida fue de: " << tempMin;
        cout << "\nEl promedio de temperatura fue de: " << tempProm << "\n\n";

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

    cout << "\n\n\nGracias por usar Tempreter v0.1a!\n\n";

    return 0;
}
