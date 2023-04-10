// PracticeProblemsSection10.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
void PrintArray(int* dynamicArray, int size);
int* CreateDynamicArray(int capacity, int& size);
void DeleteDynamicArray(int* dynamicArray, int& size);
bool InsertElement(int* dynamicArray, int element, int& size, int& capacity);
void DeleteElement(int* dynamicArray, int elementIndex, int& size);
void ResizeDynamicArray(int** dynamicArray, int size, int newCapacity);

int main()
{
    
    /*
        int x = 5;
        int* xPtr = new int;
        xPtr = &x;

        cout << *xPtr << endl;

        delete xPtr;
        xPtr = NULL;
    */
    int size = 0;
    int capacity = 20;
    cout << "Size of dynamic array is: " << size << endl;
    int* dynamicArray = CreateDynamicArray(capacity, size);
    //PrintArray(dynamicArray, size);
    for (int i = 0; i < 5; i++)
    {
        InsertElement(dynamicArray, i + 1, size, capacity);

    }
    //InsertElement(dynamicArray, 2, size, capacity);
    PrintArray(dynamicArray, size);
    cout << "Size of dynamic array is: " << size << endl;
    DeleteElement(dynamicArray, 2, size);
    PrintArray(dynamicArray, size);

    ResizeDynamicArray(&dynamicArray, size, 30);
    PrintArray(dynamicArray, size);

    return 0;
}


int* CreateDynamicArray(int capacity, int& size)
{
    size = 0;
    int * newArray = new int[capacity];

    for (int i = 0; i < capacity; i++)
    {
        newArray[i] = 0;
    }
    return newArray;
}

void DeleteDynamicArray(int* dynamicArray, int& size)
{
    delete[]dynamicArray;
    dynamicArray = nullptr;
    size = 0;
}

bool InsertElement(int* dynamicArray, int element, int& size, int& capacity)
{
    if (size + 1 > capacity)
    {
        return false;
    }
    //cout << *dynamicArray << endl;

    // 5 elements
    // capacity 10
    /*
        0, 1, 2, 3, 4
    */
    dynamicArray[size] = element;
    size = size + 1;

    return true;
}

void DeleteElement(int* dynamicArray, int elementIndex, int& size)
{
    for (int i = elementIndex; i < size - 1; i++)
    {
        dynamicArray[i] = dynamicArray[i + 1];
    }
    size--;
}

/*
 void ResizeDynamicArray(int** dynamicArray, int size, int newCapacity);

    ResizeDynamicArray should resize the array to be newCapacity. 
    All the previous elements in the dynamic array should remain in tact and in the order they were in beforehand.
*/

void ResizeDynamicArray(int** dynamicArray, int size, int newCapacity)
{
    int* newArray = new int[newCapacity];
    int previousSize = size;
    for (int i = size; i >= 0; i--)
    {
        newArray[i] = (*dynamicArray)[i];
    }
    DeleteDynamicArray(*dynamicArray, size);
    *dynamicArray = newArray;
    size = previousSize;
}

void PrintArray(int* dynamicArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << dynamicArray[i] << endl;
    }
}

    /*
    *   Problem: Create a dynamic array of integers that can be resized every time the array is full. There should be 5 functions that will be used with this dynamic array:

        int * CreateDynamicArray(int capacity, int& size);

        This will do the first creation of the dynamic array based on the capacity passed in to the CreateDynamicArray function. Size should be set to 0

        void DeleteDynamicArray(int* dynamicArray, int &size);

        DeleteDynamicArray will actually delete the memory created by CreateDynamicArray. Size should be set to 0

        void InsertElement(int** dynamicArray, int element, int & size, int& capacity);

        InsertElement will add a new element to the end of the array and increase the size by 1. It should return false if it doesn't have the capacity to add the new element and true otherwise.

        void DeleteElement(int* dynamicArray, int elementIndex, int & size);

        DeleteElement will remove the element at elementIndex. There should be no empty spaces between elements. The dynamic array should not be resized.

        void ResizeDynamicArray(int** dynamicArray, int size, int newCapacity);

        ResizeDynamicArray should resize the array to be newCapacity. All the previous elements in the dynamic array should remain in tact and in the order they were in beforehand. 

        Make sure there are no memory leaks anywhere in the code!
    */


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
