// PracticeProblemsSection3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "FahrenheitConverter.h"
#include "TimeYearConverter.h"
#include <string>
using namespace std;

int main()
{

    int option;
    cout << "1 - Day converter " << endl;
    cout << "2 - Currency " << endl;
    cout << "3 - Time converter to hh:mm:ss " << endl;
    cout << "4 - Fahrenheit to celsius " << endl;
    cout << "Enter option: ";
    cin >> option;

    switch (option)
    {
        case 1:
        {
            //Problem 1: Write a program to input number of days from user and convert it to years, weeks and days.Ignore leap years.
            int days;
            TimeYearConverter tc;
            cout << "Enter days: ";
            cin >> days;

            tc.ToYears(days);
            break;
        }
        case 2:
        {
            /*Problem 2: Write a program that takes a floating point number and outputs the minimum amount of currency denominations needed to make up that number.
            Eg.If the user input 45.78
            then the output would be :

            4 ten dollar bills
                1 five dollar bills
                0 two dollar bills
                0 one dollar bills
                3 twenty five cent pieces
                0 ten cent pieces
                0 five cent pieces
                3 one cent pieces
            */

            float n;
            cout << "Enter number: ";
            cin >> n;

            float whole = floor(n);
            // decimal rounded to two decimals and converted to a whole number
            // so 0.78 -> 78 to make calculations with the cents
            float decimal = ceil( (n - whole) * 100);
            cout << whole << endl;
            cout << decimal << endl;

            // ten dollar bills
            int db = n / 10;
            int fivebills = (n - (db * 10)) / 5;
            int twobills = (n - (db * 10) - (fivebills * 5)) / 2;
            int oneb = (n - (db * 10 + fivebills * 5 + twobills * 2));
            int twentyfive = decimal / 25;
            int tencent = (decimal - (twentyfive * 25)) / 10;
            int fivecent = (decimal - (twentyfive * 25 + tencent * 10) ) / 5;
            int onecent = (decimal - (twentyfive * 25 + tencent * 10 + fivecent * 5) );


            //int onebills = 
            cout << db << " ten dollar bills" << endl;
            cout << fivebills << " five dollar bills" << endl;
            cout << twobills << " two dollar bills" << endl;
            cout << oneb << " one dollar bills" << endl;
            cout << twentyfive << " twenty five cent pieces" << endl;
            cout << tencent << " ten cent pieces" << endl;
            cout << fivecent << " five cent pieces" << endl;
            cout << onecent << " one cent pieces" << endl;
            break;
        }
        case 3:
        {
            /*
            Problem 3: Write a program that takes in a number of seconds and outputs the time in this format : hh::mm::ss where hh is the hours, mm is the minutes, and ss is the seconds.
            */
            int seconds;
            cout << "Enter number of seconds: ";
            cin >> seconds;

            int hours = seconds / 3600;
            int minutes = (seconds - (hours * 3600)) / 60;
            int remainingSeconds = seconds - (hours * 3600 + minutes * 60);

            string h_text = hours < 10 ? "0" + to_string(hours) : to_string(hours);
            string m_text = minutes < 10 ? "0" + to_string(minutes) : to_string(minutes);
            string s_text = remainingSeconds < 10 ? "0" + to_string(remainingSeconds) : to_string(remainingSeconds);
            cout << h_text << ":" << m_text << ":" << s_text << endl;
            break;

        }
        case 4:
        {
            float fTemp;
            FahrenheitConverter fc;
            cout << "Enter fahrenheit temperature: \n";
            cin >> fTemp;

            cout << "The temperature in celsius is: " << fc.ConvertToCelsius(fTemp) << endl;
            break;
        }
        default:
            cout << "Not a valid option";
            break;
    }

    /*float n1, n2, n3;
    cout << "Enter three numbers: ";
    cin >> n1 >> n2 >> n3;

    cout << "The average of the three numbers is : " << (n1 + n2 + n3) / 3;*/

  /*  char c;

    cout << "Enter a character: ";
    cin >> c;

    cout << "The character in ascii is: " << int(c) << endl;*/

  


    
    
    
    

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
