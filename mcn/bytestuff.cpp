#include <iostream>
#include <vector>
#include <string>
using namespace std;

const string FLAG = "flag";
const string ESC = "esc";

void byteStuffing() {
    int n;
    cout << "Enter number of words: ";
    cin >> n;
    string word, stuffed = FLAG + " ";
    cout << "Enter words:\n";
    for (int i = 0; i < n; i++) {
        cin >> word;
        if (word == FLAG || word == ESC)
            stuffed += ESC + " ";
        stuffed += word + " ";
    }
    stuffed += FLAG;
    cout << "Stuffed: " << stuffed << endl;
}

// void byteDestuffing() {
//     cout << "Enter stuffed frame (end input with 'flag'):\n";
//     string word, result;
//     bool skip = false, started = false;

//     while (cin >> word) {
//         if (word == FLAG && !started) {
//             started = true;
//             continue;
//         }
//         if (word == FLAG && started) break;

//         if (skip) { skip = false; continue; }
//         if (word == ESC) { skip = true; continue; }

//         result += word + " ";
//     }

//     if (!result.empty()) result.pop_back(); // remove last space
//     cout << "Destuffed: " << result << endl;
// }

int main() {
    int choice;
    while (true) {
        cout << "\n1. Stuff\n2. Destuff\n3. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) byteStuffing();
        else if (choice == 2) {
            cin.ignore(); // clear newline
            //byteDestuffing();
        }
        else if (choice == 3) break;
        else cout << "Invalid choice.\n";
    }
    return 0;
}