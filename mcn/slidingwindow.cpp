#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;

void sendFrames(const vector<int>& frames, int start, int end, int lostFrame) {
    for (int i = start; i <= end; ++i) {
        if (i == lostFrame) {
            cout << "Frame " << frames[i] << " lost!\n";
            continue; // simulate loss
        }
        cout << "Sending Frame " << frames[i] << endl;
        this_thread::sleep_for(chrono::milliseconds(300)); // simulate delay
        cout << "Acknowledgment received for Frame " << frames[i] << endl;
    }
}

int main() {
    int totalFrames, windowSize, lostFrame;

    cout << "Enter total number of frames to send: ";
    cin >> totalFrames;

    cout << "Enter window size: ";
    cin >> windowSize;

    vector<int> frames(totalFrames);
    for (int i = 0; i < totalFrames; ++i) frames[i] = i;

    cout << "Enter the frame number to simulate loss (0 to " << totalFrames - 1 << ", or -1 for no loss): ";
    cin >> lostFrame;

    int i = 0;
    while (i < totalFrames) {
        int end = min(i + windowSize - 1, totalFrames - 1);
        cout << "\n--- Sending window: " << i << " to " << end << " ---\n";
        sendFrames(frames, i, end, lostFrame);

        if (lostFrame >= i && lostFrame <= end) {
            cout << "\nTimeout! Resending from frame " << lostFrame << "...\n";
            i = lostFrame;
            lostFrame = -1; // don't lose it again
        } else {
            i += windowSize;
        }
    }

    cout << "\nAll frames sent and acknowledged successfully.\n";
    return 0;
}
