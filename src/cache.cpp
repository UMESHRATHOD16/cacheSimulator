#include "cache.h"

Cache::Cache(int size, int blockSize, int ways) {
    this->size = size ;
    this->blockSize = blockSize;
    this->ways = ways;

    sets.resize(size, vector<CacheLine>(ways));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < ways; j++) {
            sets[i][j].tag = -1;
            sets[i][j].valid = false;
        }
    }
}

bool Cache::access(int address){

    int offset = address % blockSize;
    int blockNumber = address / blockSize;
    int index = blockNumber % size;
    int tag = blockNumber / size;

    // Search inside set for HIT
    for (int i = 0; i < ways; i++) {
        if (sets[index][i].valid &&
            sets[index][i].tag == tag) {

            return true; // HIT
        }
    }

    // Search for empty line
    for (int i = 0; i < ways; i++) {
        if (!sets[index][i].valid) {

            sets[index][i].tag = tag;
            sets[index][i].valid = true;

            return false; // MISS
        }
    }

    // If set full → replace first line (temporary)
    sets[index][0].tag = tag;

    return false;
}

vector<vector<CacheLine>> Cache::getCache() {
    return sets;
}