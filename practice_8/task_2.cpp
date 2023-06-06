#include<iostream>
#include<cmath>

using namespace std;

int gcd(int a, int h) {
    int temp;
    while (1) {
        temp = a % h;
        if (temp == 0) {
            return h;
        }
        a = h;
        h = temp;
    }
}

int main() {
    // Выбираем два случайных простых числа p и q
    int p = 3;
    int q = 11;

    // Вычисляем модуль n
    int n = p * q;

    // Вычисляем значение функции Эйлера
    int phi = (p - 1) * (q - 1);

    // Выбираем целое число e, взаимно простое со значением функции phi
    int e = 3;

    // Проверяем, чтобы значение e было меньше phi
    while (e < phi) {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }

    // Вычисляем число d, обратное число e
    int k = 1;
    int d = (1 + (k * phi)) / e;

    int msg = 25;

    cout << "Данные сообщения = " << msg << endl;

    // Шифрование. c = (msg ^ e) % n
    int c = pow(msg, e);
    c = c % n;
    cout << "Зашифрованные данные = " << c << endl;

    // Расшифровка. m = (c ^ d) % n
    int m = pow(c, d);
    m = m % n;
    cout << "Оригинальное сообщение = " << m;

    return 0;
}