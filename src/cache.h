#ifndef CACHE_H
#define CACHE_H

#include <vector>
using namespace std;

struct CacheLine {      // this is only one cacheLine (precisely one slot in cache:)
    int tag;            // value of that particular c_line
    bool valid;         // is it filled or not
};

class Cache {   // this is whole cache block
private:
    int size;       // number of slots
    int blockSize;
    vector<CacheLine> lines;    // actual storage

public:
    Cache(int size, int blockSize);        // creates a cache block with this constructor of size size
    bool access(int address);   // this function is for 
    vector<CacheLine> getCache();
};

#endif

// this header just creates a structure for both cache block and cache line