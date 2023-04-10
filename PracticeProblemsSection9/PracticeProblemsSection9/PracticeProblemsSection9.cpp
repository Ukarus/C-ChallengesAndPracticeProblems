// PracticeProblemsSection9.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;


int StringLength(const char* str);
double DotProduct(double v1[], double v2[], int length);
void ReverseString(char str[]);
void ArrayCopy(int source[], int dest[], int length);
void InsertIntoArray(int *arr[], int index, int element, int length);
void DeleteIntoArray(int *arr[], int index, int length);
void PrintArray(int arr[], int length);

int main()
{
    int option = 0;
    cout << "1 - String length\n";
    cout << "2 - Dot Product\n";
    cout << "3 - String reverse\n";
    cout << "4 - Array copy\n";
    cout << "5 - Insert in array at index\n";
    cout << "6 - Delete in array at index\n";
    cout << "Select an option: ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        const char* myString = "Hello World";

        cout << "The length of " << myString << " is: " << StringLength(myString) << endl;
        break;
    }
    case 2:
    {
        double v1[3] = { 2, 4, 6 };
        double v2[3] = { 1, 3, 5 };

        cout << "The dot product is: " << DotProduct(v1, v2, 3) << endl;
    }
    case 3:
    {
        //  Problem 1: Write a function that will reverse a C String. For example if the string was "Hello" it should be reversed to "olleH"
        char myStr[] = "hello";
        ReverseString(myStr);
        cout << myStr << endl;
    } 
    case 4:
    {
        // Problem 2: Write a program to read elements in an array and copy all elements of first array into second array.
        const int ARRAY_SIZE = 5;
        int arrExample[ARRAY_SIZE] = { 1, 2, 3, 4, 5 };
        int dest[ARRAY_SIZE];
        
        ArrayCopy(arrExample, dest, ARRAY_SIZE);

        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            cout << "[" << i << "] = " << dest[i] << endl;
        }
    }
    case 5: 
    {
        /*
            Problem 3: Write a program to insert an element in array at specified position.

            Example: 
            If the elements of array are: 10, 20, 30, 40, 50 
            After inserting 25 at position 3
            Elements of array are: 10, 20, 25, 30, 40, 50 
        */
        const int ARRAY_SIZE = 5;
        int* arr = new int[ARRAY_SIZE];
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            arr[i] = i + 1;
        }

        InsertIntoArray(&arr, 1, 10, ARRAY_SIZE);
        cout << "printing outside insert into array " << endl;
        PrintArray(arr, ARRAY_SIZE + 1);

    }
    case 6: {
        const int ARRAY_SIZE = 5;
        int* arr = new int[ARRAY_SIZE];
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            arr[i] = i + 1;
        }

        DeleteIntoArray(&arr, 1, ARRAY_SIZE);
        cout << "printing outside delete into array " << endl;
        PrintArray(arr, ARRAY_SIZE - 1);
    }
    default:
        break;
    }


    return 0;
}

void ReverseString(char str[])
{
    int length = StringLength(str);

    char temp;

    // Move from begin and end. Keep
    // swapping strings. 
    int j = length - 1;
    for (int i = 0; i < j; i++) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
    // copy the contents of the string 
    // replace starting from first char of the string
    /*
    int length = StringLength(str);
    const int max = 100;
    char copyStr[max];
    strcpy_s(copyStr, str);
    const char* lPtr = (copyStr + length - 1);
    int i = length - 1;
    int j = 0;

    while (i >= 0)
    {
        str[j] = *lPtr;
        j++;
        lPtr--;
        i--;
    }*/
}

double DotProduct(double v1[], double v2[], int length)
{
    double sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += (v1[i] * v2[i]);
    }

    return sum;
}

int StringLength(const char* str)
{
    int length = 0;
    const char* p = str;
    if (str != nullptr)
    {
        while (*p != '\0')
        {
            length++;
            p++;
        }
    }
    return length;
}


void ArrayCopy(int source[], int dest[], int length)
{
    for (int i = 0; i < length; i++)
    {
        dest[i] = source[i];
    }
}

void PrintArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

void InsertIntoArray(int *arr[], int index, int element, int length)
{
    // create an array with length + 1
    int *newArr = new int[length + 1];

    for (int i = 0; i < length + 1; i++)
    {
        if (i >= index)
        {
            if (i == index) {
                newArr[i] = element;
            }
            else
            {
                newArr[i] = (*arr)[i - 1];
            }
        }
        else
        {
            newArr[i] = (*arr)[i];
        }
    }

    delete[] *arr;
    *arr = new int[length + 1];
    for (int i = 0; i < length + 1; i++)
    {
        (*arr)[i] = newArr[i];
    }
    newArr = NULL;
}

void DeleteIntoArray(int* arr[], int index, int length)
{
    /*
       Problem 4: Write a program to delete an element from an array at specified position. 
        The program should also print an error message if the delete position is invalid. There should be no empty elements between the numbers.

        Example: 
        If the array elements are - 10, 20, 30, 40, 50 
        After deleting element at position 2
        Elements of array - 10, 30, 40, 50 
    */ 
    int* copyArr = new int[length - 1];
    for (int i = 0; i < length - 1; i++)
    {
        if (i < index) 
        {
            copyArr[i] = (*arr)[i];
        }
        else if (i >= index) {
            copyArr[i] = (*arr)[i + 1];
        }
    }

    delete[] * arr;
    *arr = new int[length -1];
    for (int i = 0; i < length - 1; i++)
    {
        (*arr)[i] = copyArr[i];
    }
    copyArr = NULL;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
