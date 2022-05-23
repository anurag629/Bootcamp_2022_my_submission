#include <iostream>
using namespace std;

struct Complex
{
    float real;
    float imag;
};

Complex add(Complex N1, Complex N2)
{
    Complex N3;
    N3.real = N1.real + N2.real;
    N3.imag = N1.imag + N2.imag;
    return N3;
}

int main()
{
    Complex N1, N2, N3;
    cout << "Enter first complex number : ";
    cin >> N1.real >> N1.imag;
    cout << "Enter second complex number : ";
    cin >> N2.real >> N2.imag;
    N3 = add(N1, N2);
    cout << "Result : " << N3.real << " " << N3.imag;
    return 0;
}