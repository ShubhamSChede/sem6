#include <iostream>
using namespace std;

// Encode 4-bit data into 7-bit Hamming code
void encode(int d[4], int h[7]) {
    h[2] = d[0]; // D1
    h[4] = d[1]; // D2
    h[5] = d[2]; // D3
    h[6] = d[3]; // D4

    h[0] = h[2] ^ h[4] ^ h[6]; // P1
    h[1] = h[2] ^ h[5] ^ h[6]; // P2
    h[3] = h[4] ^ h[5] ^ h[6]; // P4
}

// Check and correct received Hamming code
void check(int r[7]) {
    int p1 = r[0] ^ r[2] ^ r[4] ^ r[6];
    int p2 = r[1] ^ r[2] ^ r[5] ^ r[6];
    int p4 = r[3] ^ r[4] ^ r[5] ^ r[6];

    int errorPos = p4 * 4 + p2 * 2 + p1;

    if (errorPos == 0) {
        cout << "No error in received data.\n";
    } else {
        cout << "Error at bit " << errorPos << ", correcting...\n";
        r[errorPos - 1] ^= 1; // Flip the wrong bit
        cout << "Corrected data: ";
        for (int i = 0; i < 7; i++) cout << r[i];
        cout << endl;
    }
}

int main() {
    int d[4], h[7], r[7];

    cout << "Enter 4 data bits: ";
    for (int i = 0; i < 4; i++) cin >> d[i];

    encode(d, h);

    cout << "Encoded Hamming code: ";
    for (int i = 0; i < 7; i++) cout << h[i];
    cout << endl;

    cout << "Enter received 7 bits: ";
    for (int i = 0; i < 7; i++) cin >> r[i];

    check(r);

    return 0;
}