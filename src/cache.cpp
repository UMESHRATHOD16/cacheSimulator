#include "cache.h"

Cache::Cache(int size, int blockSize) {
    this->size = size ;
    this->blockSize = blockSize;

    lines.resize(size);

    for( auto x: lines){
        x.tag = -1 ;
        x.valid = false ;
    }
}

bool Cache :: access(int address){

    int offset = address % blockSize;
    int blockNumber = address / blockSize;
    int index = blockNumber % size;
    int tag = blockNumber / size;

    if(lines[index].valid && lines[index].tag == tag){
        return true; // hit case
    }

    lines[index].tag = tag;
    lines[index].valid = true ;

    return false; // miss case
}

vector<CacheLine> Cache::getCache() {
    return lines;
}