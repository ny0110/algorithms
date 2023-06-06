#include <iostream>

using namespace std;

int extendedGCD(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return gcd;
}

int main() {
    int a, b;
    cout << "Введите первый номер: ";
    cin >> a;
    cout << "Введите второй номер: ";
    cin >> b;
    int x, y;
    int gcd = extendedGCD(a, b, x, y);
    cout << "НОД: " << gcd << endl;
    cout << "Равные коэффициенты: " << x << " и " << y << endl;
    return 0;
}