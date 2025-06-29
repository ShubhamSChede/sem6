#include <iostream>
#include <string>
using namespace std;

void bitStuffing() {
    string input, output = "FLAG";
    cout << "Enter binary message: ";
    cin >> input;

    int count = 0;
    for (char c : input) {
        output += c;
        count = (c == '1') ? count + 1 : 0;
        if (count == 5) {
            output += '0';
            count = 0;
        }
    }
    output += "FLAG";
    cout << "Stuffed: " << output << endl;
}

void bitDestuffing() {
    string input, output;
    cout << "Enter stuffed message: ";
    cin >> input;

    size_t start = input.find("FLAG") + 4;
    size_t end = input.rfind("FLAG");
    int count = 0;

    for (size_t i = start; i < end; i++) {
        output += input[i];
        count = (input[i] == '1') ? count + 1 : 0;
        if (count == 5 && i + 1 < end && input[i + 1] == '0') i++;
        if (count == 5) count = 0;
    }

    cout << "Destuffed: " << output << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "\n1. Stuff bits\n2. Destuff bits\n3. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) bitStuffing();
        else if (choice == 2) bitDestuffing();
        else if (choice == 3) break;
        else cout << "Invalid!\n";
    }
    return 0;
}