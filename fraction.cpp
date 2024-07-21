#include <iostream>
#include <math.h>

using namespace std;

struct fraction
{
    int n; // numerator: tử số
    int d; // denominator: mẫu số
};


void showFraction(string message, fraction f)
{
    cout << message << f.n << '/' << f.d << '\n';
}


fraction addFractions(fraction f1, fraction f2)
{
    fraction res;
    res.n = f1.n * f2.d + f2.n * f1.d;
    res.d = f1.d * f2.d;

    return res;
}


int main()
{
    
    fraction a, b;

    a.n = 1;
    a.d = 4;
    showFraction("a = ", a);

    b.n = 3;
    b.d = 4;
    showFraction("b = ", b);

    fraction sum = addFractions(a, b);
    showFraction("Sum = ", sum);

    return 0;
}
