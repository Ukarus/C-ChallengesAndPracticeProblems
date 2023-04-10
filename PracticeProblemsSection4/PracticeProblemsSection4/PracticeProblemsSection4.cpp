// PracticeProblemsSection4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /*int n;
    cout << "Enter number: ";
    cin >> n;

    int r = n % 2;
    switch (r)
    {
        case 0:
            cout << "It's even";
            break;
        default:
            cout << "It's odd";
            break;
    }*/

    //Problem 1: Write a program that inputs a character and outputs whether or not it is in the alphabet or not.

    int option;
    cout << "Problem 1 - Character is in alphabet\n";
    cout << "Problem 2 - Biggest and lowest of 3 numbers\n";
    cout << "Problem 3 - Triangle checker\n";
    cout << "Problem 4 - Consonant or vowel\n";
    cout << "Enter an option: ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        char c;
        cout << "Enter a character: ";
        cin >> c;
        int asciiCode = int(c);

        if ((asciiCode >= 65 && asciiCode <= 90) || (asciiCode >= 97 && asciiCode <= 122)) {
            cout << "It's in the alphabet\n";
        }
        else {

            cout << "It's not in the alphabet\n";
        }
        break;
    }
    case 2: 
    {
        // Problem 2: Write a program that takes in 3 numbers and outputs the biggest number and the smallest number.
        int n1, n2, n3;
        cout << "Enter 3 numbers: ";
        cin >> n1 >> n2 >> n3;
        int biggest;
        int lowest;
        // case 1: n1 is the biggest
        if (n1 > n2 && n1 > n3) {
            biggest = n1;
            lowest = n2 > n3 ? n3 : n2;
        }
        // case 2: n2 is the biggest
        else if (n2 > n1 and n2 > n3) {
            biggest = n2;
            lowest = n1 > n3 ? n3 : n1;
        }
        // case 3 n3 is the biggest
        else {
            biggest = n3;
            lowest = n2 > n1 ? n1 : n2;
        }
        cout << "The biggest number is: " << biggest << endl;
        cout << "The lowest number is: " << lowest << endl;
    }
    case 3:
    {
        //Problem 3: Write a program that enters 3 sides of a triangle checks whether the triangle is valid or not.
        // Remember that a triangle is valid if and only if the sum of any two sides is greater than the third side.
        int s1, s2, s3;

        cout << "Enter three sides of a triangle: ";
        cin >> s1 >> s2 >> s3;

        if (s1 <= 0 || s2 <= 0 || s3 <= 0) {
            cout << "A triangle can't a negative or zero side" << endl;
            break;
        }

        if ( (s1 + s2 > s3) || (s2 + s3 > s1) || (s1 + s3 > s2) ) {
            cout << "It's a valid triangle\n";
        }
        else {
            cout << "It's not a valid triangle\n";
        }
        break;
    }
    case 4:
    {
        //Problem 4: Write a program to enter any alphabet and check whether alphabet is vowel or consonant using switch case.
        char c;
        cout << "Enter a character (in lowercase): ";
        cin >> c; 

        // convert it to lowercase to handle both cases
        c = std::tolower(c);
        // cout << c << endl;;

        switch (c)
        {
        case 'a':
        {
            cout << "It's the a vowel\n";
            break;
        }
        case 'e':
        {
            cout << "It's the e vowel\n";
            break;
        }
        case 'i':
        {
            cout << "It's the i vowel\n";
            break;
        }
        case 'o':
        {
            cout << "It's the o vowel\n";
            break;
        }
        case 'u':
        {
            cout << "It's the u vowel\n";
            break;
        }
        default:
            cout << "It's a consonant\n";
            break;
        }
    }

    default:
        break;
    }



    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
