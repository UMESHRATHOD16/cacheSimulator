#include <iostream>
#include <vector>
#include "cache.h"
using namespace std;

int main() {
    int cacheSize = 4;

    Cache cache(cacheSize);

    vector<int> access = {1, 2, 3, 1, 4, 5};

    int hits = 0;

    cout << "Access sequence:\n";

    for (int addr : access) {
        bool isHit = cache.access(addr);

        cout << addr << " -> " << (isHit ? "Hit" : "Miss") << endl;

        if (isHit) hits++;

            vector<CacheLine> current = cache.getCache();

    cout << "Cache: ";
    for (int i = 0; i < cacheSize; i++) {
        cout << "[";
        if (current[i].valid)
            cout << current[i].tag;
        else
            cout << "-";
        cout << "] ";
    }
    cout << endl;
    }

    cout << "\nTotal Hits: " << hits << endl;
    cout << "Hit Rate: " << (float)hits / access.size() << endl;



    return 0;
}