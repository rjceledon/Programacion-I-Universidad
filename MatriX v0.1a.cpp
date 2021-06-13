#include<iostream>
using namespace std;
/*Diseñado por: Ing. Ricardo Celedon
Maracaibo, Venezuela 12/04/21*/

void edades(int f, int c)
{
    int edadSucursal[f][c];
    int acumEdades = 0;
    int acumPar = 0;
    int acumImpar = 0;
    for(int s = 0; s < c; s++)
    {
        cout << "\nSUCURSAL (" << s + 1 << "/" << c << ")\n";
        for(int t = 0; t < f; t++)
        {
            do
            {
                cout << "Ingrese edad Trabajador (" << t + 1 << "/" << f << "): ";
                cin >> edadSucursal[t][s];
            }
            while(!((edadSucursal[t][s] < 66) && (edadSucursal[t][s] > 17)));
            acumEdades = acumEdades + edadSucursal[t][s];
            if((edadSucursal[t][s] % 2) == 0)
            {
                acumPar = acumPar + edadSucursal[t][s];
            }
            else
            {
                acumImpar = acumImpar + edadSucursal[t][s];
            }
        }
    }
    cout << "\nEl promedio de edades es: " << acumEdades / (f * c);
    cout << "\nLa Suma de edades pares es: " << acumPar;
    cout << "\nLa Suma de edades impares es: " << acumImpar;
}

void identidad(int orden)
{
    cout << "Generando matriz identidad de orden " << orden << ":\n\n";
    int ident[orden][orden];
    int traza = 0;
    int acumExt = 0;
    int contExt = 0;
    for(int c = 0; c < orden; c++)
    {
        for(int f = 0; f < orden; f++)
        {
            if(f==c)
            {
                ident[f][c] = 1;
            }
            else
            {
                ident[f][c] = 0;
            }
            cout << ident[f][c] << " ";
        }
        cout << "\n";
    }
    cout << "\nCalculando resultados...\n";
    for(int c = 0; c < orden; c++)
    {
        for(int f = 0; f < orden; f++)
        {
            if(f==c)
            {
                traza = traza + ident[f][c];
            }
            else
            {
                contExt++;
                acumExt = acumExt + ident[f][c];
            }
        }
    }
    cout << "\nLa traza o suma de diagonal principal es: " << traza;
    cout << "\nEl promedio de elementos fuera de la diagonal principal es: " << acumExt / contExt;
}

int main()
{
    int opcion, n, m;
    bool salir = false;
    int ordIdent = 6;
    cout << "Bienvenido a MatriX v0.1a!\n\n";
    do
    {
        cout << "### MENU\n";
        cout << "1) MatriX Edades\n2) MatriX Identidad\n3) Salir\n\n";
        do
        {
            cout << "Elija una opcion (1/2/3): ";
            cin >> opcion;
        }
        while(!((opcion == 1) || (opcion == 2) || (opcion == 3)));
        switch(opcion)
        {
            case 1:
                cout << "\nIntroduzca la cantidad de trabajadores por sucursal: ";
                cin >> n;
                cout << "Introduzca la cantidad de sucursales: ";
                cin >> m;
                edades(n, m);
                cout << "\n\n";
                break;
            case 2:
                cout << "\n";
                identidad(ordIdent);
                cout << "\n\n";
                break;
            case 3:
                salir = true;
                break;
        }
    }
    while(salir == false);
    cout << "\n\nGracias por usar MatriX v0.1a!\n\n";
    return 0;
}
