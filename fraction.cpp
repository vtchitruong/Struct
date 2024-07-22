#include <iostream>
#include <math.h>

using namespace std;


// Khai báo cấu trúc fraction gồm hai thành phần tử và mẫu
struct fraction
{
    int n; // numerator: tử số
    int d; // denominator: mẫu số
};


// Hàm in phân số ra màn hình
void showFraction(string message, fraction f)
{
    cout << message;
    
    if (f.d == 1)
        cout << f.n << '\n';
    else
        cout << f.n << '/' << f.d << '\n';
}


// Hàm tìm ước chung lớn nhất
int gcd(int a, int b)
{
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}


// Hàm rút gọn phân số
fraction reduceFraction(fraction f)
{
    int g = gcd(f.n, f.d);
    
    // Chia tử và mẫu cho cùng một số
    f.n /= g;
    f.d /= g;
    return f;
}


// Hàm cộng hai phân số
fraction addFractions(fraction f1, fraction f2)
{
    fraction res;

    // Thực hiện quy đồng mẫu số
    res.n = f1.n * f2.d + f2.n * f1.d;
    res.d = f1.d * f2.d;

    // Rút gọn phân số
    res = reduceFraction(res);

    return res;
}


// Hàm chia hai phân số
fraction divideFractions(fraction f1, fraction f2)
{
    fraction res;
    
    // Chia phân số là nhân nghịch đảo
    res.n = f1.n * f2.d;
    res.d = f1.d * f2.n;

    // Rút gọn phân số
    res = reduceFraction(res);

    return res;
}


// Hàm chuyển đổi phân số thành số thập phân
double fractionToDecimal(fraction f)
{
    return (double) f.n / f.d;
}


// Hàm so sánh hai phân số
int compareFractions(fraction f1, fraction f2)
{
    // Nhân chéo và so sánh
    int x = f1.n * f2.d;
    int y = f2.n * f1.d;

    if (x < y) return -1;
    if (x == y) return 0;
    return 1;
}


int main()
{    
    fraction a, b;

    // Phân số a
    a.n = 1;
    a.d = 4;
    showFraction("a = ", a);

    // Phân số b
    b.n = 3;
    b.d = 4;
    showFraction("b = ", b);

    // a + b
    fraction s = addFractions(a, b);
    showFraction("Sum = ", s);

    // a : b
    fraction q = divideFractions(a, b);
    showFraction("Quotient = ", q);

    // Chuyển phân số q thành thập phân
    double dec = fractionToDecimal(q);
    cout << "To decimal: " << dec << '\n';

    // Phân số c
    fraction c;
    c.n = 1;
    c.d = 8;

    // So sánh a và c
    int res = compareFractions(a, c);
    
    if (res == -1)
        cout << "a < c";
    else if (res == 0)
        cout << "a = c";
    else
        cout << "a > c";

    return 0;
}