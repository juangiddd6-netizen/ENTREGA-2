#include <iostream>
using namespace std;

int collatzSteps(long long n) {
    int steps = 0;

    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;

        steps++;
    }

    return steps;
}

int main() {
    long long n;
    cout << "Ingrese un numero positivo: ";
    cin >> n;

    cout << "Numero de pasos: " << collatzSteps(n) << endl;

    return 0;
}