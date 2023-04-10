// PracticeProblemsSection5.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cmath>
using namespace std;

string BinaryComplement(string num);
void PrintAsciiTable(int from, int to);


int main()
{


    int opt;
    cout << "1 - Cin validation" << endl;
    cout << "2 - Rectangle" << endl;
    cout << "3 - Pyramid" << endl;
    cout << "4 - Binary complement" << endl;
    cout << "5 - Ascii table" << endl;
    cout << "6 - Count of digits in an integer" << endl;
    cout << "7 - Palindrome" << endl;
    cout << "8 - Diamond pattern" << endl;
    cout << "9 - Hollow Diamond pattern" << endl;
    cout << "Enter an option: ";
    cin >> opt;

    switch (opt)
    {
    case 1: 
    {
        int num;
        bool failure;

        const int IGNORE_CHARS = 256;

        do
        {
            failure = false;
            cout << "Please enter a number: ";
            cin >> num;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(IGNORE_CHARS, '\n');
                failure = true;
                cout << "Input error, please try again\n";
            }
        } while (failure);

        cout << "The number you inputted was: " << num << endl;
        break;
    }
    case 2:
    {
        int rows, columns;
        cout << "Enter rows and columns: ";
        cin >> rows >> columns;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << "*";
            }
            cout << "\n";
        }
    }
    case 3:
    {
        int height;
        cout << "Enter height of pyramid: ";
        cin >> height;

        // 1 (1 * 2 - 1)
        // 3 (2 * 2 - 1)
        // 5 (3 * 2 - 1)

        for (int i = 0; i < height; i++)
        {
            // 1: 9 - 1
            // 2: 9 - 3
            // 3: 9 - 5
            int spaces = ((height * 2) - 1) - ((i + 1) * 2 - 1);
            for (int k = 0; k < spaces / 2; k++)
            {
                cout << " ";
            }

            for (int j = 0; j < ((i+1) * 2 - 1); j++)
            {
                cout << "*";
            }

            for (int k = 0; k < spaces / 2; k++)
            {
                cout << " ";
            }
            cout << "\n";
        }
        break;
    }
    case 4:
    {
        string num;
        cout << "Enter binary number: ";
        cin >> num;

        cout << "The complement is: " << BinaryComplement(num) << endl;
        break;
    }
    case 5:
    {
        int from, to;
        cout << "Print ascii table from, to: ";
        cin >> from >> to;

        PrintAsciiTable(from, to);
        break;
    }
    case 6:
    {

        /*
             Problem 3: Write a program to count frequency of digits in an integer. 
            Example: 
            Input num: 116540
            Output: 
            Frequency of 0 = 1 
            Frequency of 1 = 2 
            Frequency of 2 = 0 
            Frequency of 3 = 0 
            Frequency of 4 = 1 
            Frequency of 5 = 1 
            Frequency of 6 = 1 
            Frequency of 7 = 0 
            Frequency of 8 = 0 
            Frequency of 9 = 0 
        */
        int num, n;
        int c0 = 0, c1 = 0, c2 = 0, c3 = 0, c4= 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0;
        cout << "Enter an integer: ";
        cin >> num;
        n = num;

        do
        {
            int digit = n % 10;
            switch (digit)
            {
            case 0:
                c0++;
                break;
            case 1:
                c1++;
                break;
            case 2:
                c2++;
                break;
            case 3:
                c3++;
                break;
            case 4:
                c4++;
                break;
            case 5:
                c5++;
                break;
            case 6:
                c6++;
                break;
            case 7:
                c7++;
                break;
            case 8:
                c8++;
                break;
            case 9:
                c9++;
                break;
            default:
                break;
            }
            n = n / 10;

        } while (n > 0);

        cout << "Frequency of 0: " << c0 << endl;
        cout << "Frequency of 1: " << c1 << endl;
        cout << "Frequency of 2: " << c2 << endl;
        cout << "Frequency of 3: " << c3 << endl;
        cout << "Frequency of 4: " << c4 << endl;
        cout << "Frequency of 5: " << c5 << endl;
        cout << "Frequency of 6: " << c6 << endl;
        cout << "Frequency of 7: " << c7 << endl;
        cout << "Frequency of 8: " << c8 << endl;
        cout << "Frequency of 9: " << c9 << endl;

        break;
    }
    case 7: 
    {
        //Problem 4: Write a program to enter any number and check whether given number is palindrome or not using a for loop.Eg 121 would be a palindrome.
        int num, reversed = 0, exp = 0;
        cout << "Enter a number: ";
        cin >> num;
        int digits = trunc(log10(num)) + 1;
        exp = digits - 1;
        // 1 * 10^0 + 2 * 10^1 + 1 * 10^2

        for (int i = num; i > 0; i = i / 10)
        {
            // use exp starting from highest digit count
            reversed += ((i % 10) * pow(10, exp));
            exp--;
        }
        cout << "original: " << num << endl;
        cout << "reversed: " << reversed << endl;

        if (reversed == num) {
            cout << "It's a palindrome\n";
        }
        else {
            cout << "It's not a palindrome\n";
        }
    }
    case 8:
    {
        int n;
        cout << "Enter size of diamond pattern: ";
        cin >> n;

        // 1 star : 2 * i - 1
        // 3 stars
        // 5 stars
        // 7 stars
        // 9 stars
        // 7 stars
        // 5 stars
        // 3 stars
        // 1 star
        for (int i = 0; i < n; i++)
        {
            int stars = 2 * (i + 1) - 1;
            int spaces = 2 * n - 1 - stars;

            for (int j = 0; j < spaces / 2; j++)
            {
                cout << " ";
            }
            for (int k = 0; k < stars; k++)
            {
                cout << "*";
            }
            for (int j = 0; j < spaces / 2; j++)
            {
                cout << " ";
            }
            cout << endl;
        }

        for (int i = n - 1; i > 0; i--)
        {
            int stars = 2 * i - 1;
            int spaces = 2 * n - 1 - stars;

            for (int j = 0; j < spaces / 2; j++)
            {
                cout << " ";
            }
            for (int k = 0; k < stars; k++)
            {
                cout << "*";
            }
            for (int j = 0; j < spaces / 2; j++)
            {
                cout << " ";
            }
            cout << endl;
        }


        break;
    }
    case 9:
    {
        int n;
        cout << "Enter size of hollow diamond pattern: ";
        cin >> n;

        // 0 spaces 10 stars
        // 2 spaces 8 stars
        // 4 spaces 6 stars
        // 6 spaces 4 stars
        // 8 spaces 2 stars
        // 7 spaces


        for (int i = 0; i < n; i++)
        {
            int spaces = 2 * i;
            int stars = 2 * (n - i);

            for (int j = 0; j < stars / 2; j++)
            {
                cout << "*";
            }
            for (int k = 0; k < spaces; k++)
            {
                cout << " ";
            }
            for (int j = 0; j < stars / 2; j++)
            {
                cout << "*";
            }

            cout << endl;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            int spaces = 2 * i;
            int stars = 2 * (n - i);

            for (int j = 0; j < stars / 2; j++)
            {
                cout << "*";
            }
            for (int k = 0; k < spaces; k++)
            {
                cout << " ";
            }
            for (int j = 0; j < stars / 2; j++)
            {
                cout << "*";
            }

            cout << endl;
        }


        break;
    }
    default:
        break;
    }

    /*
    
        Problem 1: Write a program to read binary number from user and find the one's complement of that binary number.

        Example: 
        Input binary number: 01000011 
        Ones's complement: 10111100 

        Problem 2: Write a program to print ASCII values of all characters using for loop. 

        Example: 
        Output ASCII values: 
        ASCII value of character = 0
        ASCII value of character ☺ = 1
        ASCII value of character ☻ = 2

        Problem 3: Write a program to count frequency of digits in an integer. 

        Example: 
        Input num: 116540
        Output: 
        Frequency of 0 = 1 
        Frequency of 1 = 2 
        Frequency of 2 = 0 
        Frequency of 3 = 0 
        Frequency of 4 = 1 
        Frequency of 5 = 1 
        Frequency of 6 = 1 
        Frequency of 7 = 0 
        Frequency of 8 = 0 
        Frequency of 9 = 0 

        Problem 4: Write a program to enter any number and check whether given number is palindrome or not using a for loop. Eg 121 would be a palindrome. 

        Problem 5: Write a program to print the diamond star(*) pattern based on an input number. 


        Problem 6: Write a program to print hollow diamond star (*) pattern series of n rows using for loop. The pattern for 5 should look like:



    
    */

    

    return 0;
}

/*

//Problem 1: Write a program to read binary number from user and find the one's complement of that binary number.
//
//Example :
//    Input binary number : 01000011
//    Ones's complement: 10111100
*/

string BinaryComplement(string num)
{
    string complement = "";
    int l = num.length();
    for (int i = 0; i < l; i++)
    {
        char c = num[i];
        complement += c == '0' ? '1' : '0';
    }

    return complement;
}

/*
    Problem 2: Write a program to print ASCII values of all characters using for loop. 

    Example: 
    Output ASCII values: 
    ASCII value of character = 0
    ASCII value of character ☺ = 1
    ASCII value of character ☻ = 2
*/
void PrintAsciiTable(int from, int to)
{
    for (int i = from; i <= to; i++)
    {
        cout << "ASCII value of character " << char(i) << " = " << i << endl;
    }
}

/*
Problem 3: Write a program to count frequency of digits in an integer.

Example:
Input num: 116540
Output:
Frequency of 0 = 1
Frequency of 1 = 2
Frequency of 2 = 0
Frequency of 3 = 0
Frequency of 4 = 1
Frequency of 5 = 1
Frequency of 6 = 1
Frequency of 7 = 0
Frequency of 8 = 0
Frequency of 9 = 0
*/

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
