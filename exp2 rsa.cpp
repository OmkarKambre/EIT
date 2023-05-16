#include <iostream>
#include <cmath>
using namespace std;
//corrected by chatgpt
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int p = 3, q = 11;
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    cout << "Phi: " << phi << endl;

    int e;

    cout << "Enter a number greater than 1 and less than " << phi << " that is coprime to " << phi << ": ";
    cin >> e;

    // Verify that e and phi are coprime
    if (gcd(e, phi) != 1) {
        cout << "Invalid value of e. It should be coprime to Phi." << endl;
        return 0;
    }

    int d = 1;
    while (((d * e) % phi) != 1)
        d++;

    cout << "D: " << d << endl;

    int message;
    cout << "Enter the message to be encrypted (as an integer): ";
    cin >> message;

    // Encryption: c = (message ^ e) % n
    int c = pow(message, e);
    c = fmod(c, n);
    cout << "Encrypted data: " << c << endl;

    // Decryption: message = (c ^ d) % n
    int decrypted_message = pow(c, d);
    decrypted_message = fmod(decrypted_message, n);
    cout << "Decrypted data: " << decrypted_message << endl;

    return 0;
}
