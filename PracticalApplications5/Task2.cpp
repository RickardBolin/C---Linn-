
// Moved the srand to only be called once before the for-loop. When used inside the
// for loop with "time(0)", we will initiate the random sequence on the same seed
// every iteration of the loop since time(0) will be the same during the execution of
// the program. Now, it will work if we don't run the program more than once each second.

// Not sure if the "cin.get()" in the end was intended or not, but I chose to comment
// it out to make the program a bit more convenient to use.


#include <iostream>
#include <ctime>

using namespace std;
enum Coin {
    Tails, Heads
};

int main() {
    int frequency0 = 0, frequency1 = 0;
    Coin face;
    // Moved this out from the for-loop. Does not work if you run the
    // program more than once each second though.
    srand(time(0));

    for (int counter = 1; counter <= 10; ++counter) {
        face = Coin(rand() % 2);
        switch (face) {
            case Tails:
                ++frequency0;
                break;
            case Heads:
                ++frequency1;
                break;
        }
    }
    cout << "Tails were rolled " << frequency0 << " times" << endl;
    cout << "Heads were rolled " << frequency1 << " times" << endl;
    //cin.get();
    return 0;
}
