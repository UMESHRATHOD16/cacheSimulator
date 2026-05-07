#include <iostream>
#include <vector>
#include "cache.h"

using namespace std;

int main() {

    int cacheSize = 4;
    int blockSize = 4;
    int ways = 2;

    Cache cache(cacheSize, blockSize, ways);

    vector<int> access = {
        1, 2, 3, 4,
        8, 12, 16,
        1, 20, 24
    };

    int hits = 0;
    for (int addr : access) {
        int offset = addr % blockSize;
        int blockNumber = addr / blockSize;
        int index = blockNumber % cacheSize;
        int tag = blockNumber / cacheSize;
        bool isHit = cache.access(addr);
        cout << "\nAddress: " << addr << endl;

        cout << "Block Number: " << blockNumber << endl;

        cout << "Tag: " << tag
             << " | Index: " << index
             << " | Offset: " << offset << endl;

        cout << (isHit ? "Cache HIT" : "Cache MISS") << endl;

        if (isHit)
            hits++;

        vector<vector<CacheLine>> current = cache.getCache();

        cout << "\nCache State:\n";

        for (int i = 0; i < cacheSize; i++) {

            cout << "SET " << i << ": ";

            for (int j = 0; j < ways; j++) {

                cout << "[";

                if (current[i][j].valid)
                    cout << current[i][j].tag;
                else
                    cout << "-";

                cout << "] ";
            }

            cout << endl;
        }
    }

    cout << "\nTotal Hits: " << hits << endl;

    return 0;
}