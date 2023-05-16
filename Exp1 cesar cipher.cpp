#include <bits/stdc++.h>
using namespace std;

string caesar_cipher_encrypt(string message, int shift) {
    string encrypted_message;
    for(int i = 0; i < message.length(); i++) {
        encrypted_message += char(int(message[i]) + shift);
    }
    cout << "Encrypted Message = " << encrypted_message << endl;
    return encrypted_message;
}

void caesar_cipher_decrypt(string encrypted_message, int shift) {
    string decrypted_message;
    for(int i = 0; i < encrypted_message.length(); i++) {
        decrypted_message += char(int(encrypted_message[i]) - shift);
    }
    cout << "Decrypted Message = " << decrypted_message << endl;
}

string sub_cipher_encrypt(string message, string alpha, string sub_table) {
    string encrypted_message;
    for(int i = 0; i < message.length(); i++) {
        if(message[i] == ' ')
                encrypted_message += ' ';
        for(int j = 0; j < alpha.length(); j++) {
            if(message[i] == alpha[j])
                encrypted_message += sub_table[j];
        }
    }
    cout << "Encrypted Message = " << encrypted_message << endl;
    return encrypted_message;
}

string sub_cipher_decrypt(string encrypted_message, string alpha, string sub_table) {
    string decrypted_message;
     for(int i = 0; i < encrypted_message.length(); i++) {
        if(encrypted_message[i] == ' ')
            decrypted_message += ' ';
        for(int j = 0; j < alpha.length(); j++) {
            if(encrypted_message[i] == sub_table[j])
                decrypted_message += alpha[j];
        }
    }
    cout << "Decrypted Message = " << decrypted_message << endl;
    return decrypted_message;
}

void row_col_transpos_encrypt(string message) {

    stringstream ss(message);
    string word;
    string inp[100];
    char mess[100][100];
    int idx1 = 0, idx2 = 0;
    while (ss >> word) {
        inp[idx1] = word;
        idx1 += 1;
    }

    for(int i=0; i<idx1; i++) {
        for(int j=0; j<inp[i].length(); j++) {
            mess[i][j] = inp[i][j];
        }
    }

    for(int i=0; i<idx1; i++) {
        for(int j=0; j<inp[i].length(); j++) {
            cout << mess[i][j] << " ";
        }
        cout << endl;
    }

    // getting max
    char encrypted_message[100][100];
    int max = 0;
    for(int i=0; i<idx1; i++) {
        if(inp[i].length() > max) {
            max = inp[i].length();
        }
    }
    cout << "Max: " << max << endl;

    // transpose
    for(int i=0; i<idx1; i++) {
        for(int j=0; j<max; j++) {
            encrypted_message[j][i] = mess[i][j];
        }
    }

    string enc_message;
    for(int i=0; i<max; i++) {
        for(int j=0; j<idx1; j++) {
            enc_message += encrypted_message[i][j];
            cout << encrypted_message[i][j] << " ";
        }
        enc_message += " ";
        cout << endl;
    }

    cout << "Encrypted Message: " << enc_message << endl;

}

void row_col_transpos_decrypt(string message) {
    // hw eo lr ll od
    stringstream ss(message);
    string word;
    string inp[100];
    char mess[100][100];
    int idx1 = 0, idx2 = 0;


    while (ss >> word) {
        inp[idx1] = word;
        idx1 += 1;
    }

    for(int i=0; i<idx1; i++) {
        for(int j=0; j<inp[i].length(); j++) {
            mess[i][j] = inp[i][j];
        }
    }

    for(int i=0; i<idx1; i++) {
        for(int j=0; j<inp[i].length(); j++) {
            cout << mess[i][j] << " ";
        }
        cout << endl;
    }

    // getting max
    char encrypted_message[100][100];
    int max = 0;
    for(int i=0; i<idx1; i++) {
        if(inp[i].length() > max) {
            max = inp[i].length();
        }
    }
    cout << "Max: " << max << endl;

    // transpose
    for(int i=0; i<idx1; i++) {
        for(int j=0; j<max; j++) {
            encrypted_message[j][i] = mess[i][j];
        }
    }

    string dec_message;
    for(int i=0; i<max; i++) {
        for(int j=0; j<idx1; j++) {
            dec_message += encrypted_message[i][j];
            cout << encrypted_message[i][j] << " ";
        }
        dec_message += " ";
        cout << endl;
    }

    cout << "Decrypted Message: " << dec_message << endl;

}

int main() {

    string output;

    while(1) {
        cout << "1. Caesar Cipher \n";
        cout << "2. Substitution Cipher \n";
        cout << "3. Row column Transposition \n";
        cout << "4. Exit \n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch(choice) {
            case 1:
                {

                int s;
                cout << "Enter the shift size: ";
                cin >> s;

                cout << "1. Encrypt \n";
                cout << "2. Decrypt \n";
                cout << "Enter your choice: ";
                int choice;
                cin >> choice;
                if(choice == 1) {
                    string message;
                    cout << "Enter the message to be encrypted: ";
                    cin >> message;
                    output = caesar_cipher_encrypt(message, s);
                    int n;
                    cout << "Press (1) if you want to decrypt else (0): ";
                    cin >> n;
                    if(n == 1) {
                        caesar_cipher_decrypt(output, s);
                    }
                }else {
                    string message;
                    cout << "Enter the message to be decrypted: ";
                    cin >> message;
                    caesar_cipher_decrypt(message, s);
                }
                break;
                }

            case 2:
                {
                    string sub_table;
                    string alpha = "abcdefghijklmnopqrstuvwxyz";
                    // cout << "Enter the substitution string: ";
                    // cin >> sub_table;
                    sub_table = "qwertyuiopasdfghjklzxcvbnm";

                    cout << "1. Encrypt \n";
                    cout << "2. Decrypt \n";
                    cout << "Enter your choice: ";
                    int c;
                    cin >> c;
                    if(c == 1) {
                        string message;
                        cout << "Enter the message to be encrypted: ";
                        fflush(stdin);
                        getline(cin, message);
                        output = sub_cipher_encrypt(message, alpha, sub_table);
                        int n;
                        cout << "Press (1) if you want to decrypt else (0): ";
                        cin >> n;
                        if(n == 1) {
                            sub_cipher_decrypt(output, alpha, sub_table);
                        }
                    }else {
                        string message;
                        cout << "Enter the message to be decrypted: ";
                        cin >> message;
                        sub_cipher_decrypt(message, alpha, sub_table);
                    }
                    break;
                }

            case 3:
                {

                cout << "1. Encrypt \n";
                cout << "2. Decrypt \n";
                cout << "Enter your choice: ";
                int ch;
                cin >> ch;
                if(ch == 1) {
                    string message;
                    cout << "Enter the message to be encrypted: ";
                    fflush(stdin);
                    getline(cin, message);
                    row_col_transpos_encrypt(message);
                }else {
                    string message;
                    cout << "Enter the message to be decrypted: ";
                    fflush(stdin);
                    getline(cin, message);
                    row_col_transpos_decrypt(message);
                }
                break;
                }

            case 4:
                exit(0);

            default:
                cout << "Invalid choice \n";
                break;
        }
    }

    return 0;
}
