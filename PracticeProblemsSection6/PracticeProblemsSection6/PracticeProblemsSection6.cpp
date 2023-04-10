// PracticeProblemsSection6.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

bool IsPrimeNumber(int num);
int Factorial(int n);

int main()
{
    int option;

    cout << "1 - Prime numbers: \n";
    cout << "2 - Prime numbers in interval: \n";
    cout << "3 - Pascal triangle: \n";
    cout << "Enter an option: ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        int num;
        cout << "Enter a number: ";
        cin >> num;

        bool isPrimeNumber = IsPrimeNumber(num);

        if (isPrimeNumber) {
            cout << "It's a prime number\n";
        }
        else {
            cout << "It's not a prime number\n";
        }
        break;
    }
    case 2:
    {
        /*
            
        Problem 2: Write a function to find all prime numbers between two intervals.
        Eg.

        Input lower limit: 10 
        Input upper limit: 50 
        Output prime numbers between 10-50 are: 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 
        */

        int lowerLimit, upperLimit;
        cout << "Enter lower and upper limit: ";
        cin >> lowerLimit >> upperLimit;

        cout << "Prime numbers between " << lowerLimit << "-" << upperLimit << " are: ";
        for (int i = lowerLimit; i <= upperLimit; i++)
        {
            bool isPrimeNumber = IsPrimeNumber(i);
            if (isPrimeNumber) {
                cout << i << ", ";
            }
        }
        break;
    }
    case 3:
    {
        /*
             Problem 3: Write a program to print pascal triangle up to n rows. 

            Info about pascal triangles: Pascal Triangles

            For example Pascal triangle with 5 rows. 
                1
               1 1
              1 2 1
             1 3 3 1
            1 4 6 4 1
        */

        int n;
        cout << "Enter the height of the triangle: ";
        cin >> n;

        int previous = 1;
        
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < n - i; k++)
            {
                cout << " ";
            }
            for (int j = 0; j < i + 1; j++)
            {
                int entry = Factorial(i) / (Factorial(j) * Factorial(i - j));
                cout << entry << " ";
            }
            cout << endl;
        }

        break;
    }
    default:
        break;
    }
    /*
        Functions Practice

        Problem 1: Write a function that takes in an integer and returns true if the integer is a prime number.

        Problem 2: Write a function to find all prime numbers between two intervals.
        Eg.

        Input lower limit: 10 
        Input upper limit: 50 
        Output prime numbers between 10-50 are: 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 

        Problem 3: Write a program to print pascal triangle up to n rows. 

        Info about pascal triangles: Pascal Triangles

        For example Pascal triangle with 5 rows. 
            1
           1 1
          1 2 1
         1 3 3 1
        1 4 6 4 1
    */
}

int Factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    int i = 0;
    int fact = 1;

    while (i < n )
    {
        fact *= ++i;
    }

    return fact;
}

bool IsPrimeNumber(int num)
{
    // a prime number is divided just by 1 and itself
    int dividers = 0;
    for (int i = 0; i < num; i++)
    {
        int d = i + 1;
        if (num % d == 0)
        {
            dividers++;
        }
    }

    return dividers == 2;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
