#include "cache.h"

Cache :: Cache(int size){
    this->size = size ;

    lines.resize(size);

    for( auto x: lines){
        x.tag = -1 ;
        x.valid = false ;
    }
}

bool Cache :: access(int address){
    int index = address % size ;

    if(lines[index].valid && lines[index].tag == address){
        return true // hit case
    }

    lines[index].tag = address ;
    lines[index].valid = true ;

    return false // miss case
}