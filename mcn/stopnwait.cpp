#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void sender();
void receiver(int frame);

int main() {
    sender();
    return 0;
}

void sender() {
    int frame = 0;
    char ch;
    srand(time(0)); // for simulating random ACK loss

    while (true) {
        cout << "\nSender: Sending frame " << frame << endl;
        receiver(frame);

        cout << "Sender: Waiting for ACK..." << endl;
        bool ackLost = (rand() % 4 == 0); // 25% chance ACK is lost

        if (!ackLost) {
            cout << "Sender: ACK " << frame << " received" << endl;
            frame = (frame + 1) % 2; // Alternate frame number
        } else {
            cout << "Sender: ACK lost! Resending frame " << frame << endl;
            continue; // resend same frame
        }

        cout << "Send next frame? (y/n): ";
        cin >> ch;
        if (ch != 'y' && ch != 'Y') break;
    }
}

void receiver(int frame) {
    cout << "Receiver: Frame " << frame << " received successfully" << endl;
    cout << "Receiver: Sending ACK " << frame << endl;
}