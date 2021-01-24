#include <iostream>
#include <list>
using namespace std;



int main() {
    std::list<int> particles{1,2,3};
    std::list<int>::iterator p;
    int i = 0;
    for(p = particles.begin()++; p != particles.end(); p++) {
        *p = i;
        i++;
    }

    return 0;
}