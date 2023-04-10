#include "FloatInput.h"
#include <iostream>
using namespace std;

void FloatInput::EnterFloats()
{
    float f1;
    float f2;

    cout << "Please enter two floats with a space in between: ";
    cin >> f1 >> f2;

    cout << "First float is: " << f1 << endl;
    cout << "Second float is: " << f2 << endl;
}
