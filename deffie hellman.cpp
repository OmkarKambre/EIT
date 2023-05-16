#include<bits/stdc++.h>
using namespace std;

int main() {
    int p = 3, g = 17, key_1, key_2;
    cout << "Enter the 1st Key: ";
    cin >> key_1;

    cout << "Enter the 2nd Key: ";
    cin >> key_2;

    int A = pow(g, key_1);
    int B = pow(g, key_2);

    A = A % p;
    B = B % p;

    cout << "A = " << A << endl;
    cout << "B = " << B << endl;

    int X1 = pow(B, key_1);
    int X2 = pow(A, key_2);

    int x_1 = X1 % p;
    int x_2 = X2 % p;

    cout << "X1 = " << X1 << endl;
    cout << "X2 = " << X2 << endl;

    cout << "x_1 = " << x_1 << endl;
    cout << "x_2 = " << x_2 << endl;

    return 0;
}
