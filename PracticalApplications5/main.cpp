#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    for(int i = 0; i < 100; i++) {

        int totSum = 0;
        int myMove = 0;
        int move = 0;
        while(totSum < 100) {
            cout << "Last move: " << move << "   Total sum: " << totSum << "   My choice: ";
            cin >> myMove;
            cin.clear();
            totSum += myMove;
            bool tryAgain;
            do {
                tryAgain = false;
                move = rand() % 10 + 1;
                if (move + myMove == 11) {
                    tryAgain = true;
                }
            } while(tryAgain);
            totSum += move;


        }
    }
    return 0;
}