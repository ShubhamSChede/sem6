#include <iostream>
using namespace std;

bool isValid(const string& s) {
    if (s.length() != 4)
        return false;
    return true; // Passed all checks
}


string addBin(const string& a, const string& b) {
    string result = "0000";
    int carry = 0;
    for (int i = 3; i >= 0; i--) {
        int sum = (a[i]-'0') + (b[i]-'0') + carry;
        result[i] = (sum % 2) + '0';
        carry = sum / 2;
    }

    if (carry) { // wrap carry
        for (int i = 3; i >= 0; i--) {
            int sum = (result[i]-'0') + carry;
            result[i] = (sum % 2) + '0';
            carry = sum / 2;
        }
    }
    return result;
}

string onesComp(const string& s) {
    string comp = s;
    for (char& c : comp) c = (c == '0') ? '1' : '0';
    return comp;
}

int main() {
    int choice;
    string a, b, sum, chk;

    do {
        cout << "\n1. Transmit\n2. Receive\n3. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            do { cout << "Enter first 4-bit binary: "; cin >> a; } while (!isValid(a));
            do { cout << "Enter second 4-bit binary: "; cin >> b; } while (!isValid(b));

            sum = addBin(a, b);
            chk = onesComp(sum);

            cout << "Sum: " << sum << "\nChecksum: " << chk << "\nSend: " << a << " " << b << " " << chk << endl;

        } else if (choice == 2) {
            string rchk;
            do { cout << "Enter first: "; cin >> a; } while (!isValid(a));
            do { cout << "Enter second: "; cin >> b; } while (!isValid(b));
            do { cout << "Enter checksum: "; cin >> rchk; } while (!isValid(rchk));

            sum = addBin(a, b);
            string total = addBin(sum, rchk);

            if (total == "1111") cout << "✅ No error. Data: " << a << " " << b << endl;
            else cout << "Error detected!\n";
        }

    } while (choice != 3);

    return 0;
}
