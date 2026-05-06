#include <iostream>
#include <vector>
#include "cache.h"
using namespace std;

int main() {
    int cacheSize = 4;
    int blockSize = 4;

    Cache cache(cacheSize, blockSize);

    vector<int> access = {1, 2, 3, 1, 4, 5};

    int hits = 0;

    cout << "Access sequence:\n";

    for (int addr : access) {

        bool isHit = cache.access(addr);
        int offset = addr % blockSize;
        int blockNumber = addr / blockSize;
        int index = blockNumber % cacheSize;
        int tag = blockNumber / cacheSize;

        cout << "\nAddress: " << addr << endl;

        cout << "Block Number: " << blockNumber << endl;

        cout << "Tag: " << tag
            << " | Index: " << index
            << " | Offset: " << offset << endl;

        cout << (isHit ? "Cache HIT" : "Cache MISS") << endl;

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