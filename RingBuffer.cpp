#include "RingBuffer.hpp"
#include <iostream>
#include <assert.h>

#ifdef FULL_FLAG_IMPLEMENTATION

RingBuffer::RingBuffer(unsigned length){
    buffer = new unsigned[length]();
    capacity = length;
    headIdx = 0;
    tailIdx = 0;
    full = 0;
}

RingBuffer::~RingBuffer(){
    delete[] buffer;
}

void RingBuffer::printBuffer(){
    std::cout << "full:  " << this->bufferFull() << std::endl;
    std::cout << "empty: " << this->bufferEmpty() << std::endl;
    for (auto it = 0; it < capacity; it++){
        if (it == this->getHeadIdx() && it == this->getTailIdx()){
            std::cout << this->getBufferAt(it) << " " << "< head < tail" << std::endl;
        } else if (it == this->getHeadIdx()){
            std::cout << this->getBufferAt(it) << " " << "< head" << std::endl;
        } else if (it == this->getTailIdx()){
            std::cout << this->getBufferAt(it) << " " << "< tail" << std::endl;
        } else{
            std::cout << this->getBufferAt(it) << std::endl;
        }
    }
    std::cout << std::endl;
}

void RingBuffer::insert(unsigned val){
    assert(!this->bufferFull());
    buffer[tailIdx] = val;
    tailIdx++;
    tailIdx = tailIdx % capacity;
    if (tailIdx == headIdx && !full){
        full = 1;
    }
}

unsigned RingBuffer::pop(){
    assert(!this->bufferEmpty());
    unsigned retVal = buffer[headIdx];
    headIdx++;
    headIdx = headIdx % capacity;
    full = 0;
    return retVal;
}

bool RingBuffer::bufferEmpty(){
    return (tailIdx == headIdx && !full);
}

bool RingBuffer::bufferFull(){
    return full;
}

unsigned RingBuffer::numberOfElements(){
    if (full){
        return capacity;
    } else{
        return abs(headIdx - tailIdx);
    }
}

unsigned RingBuffer::maxCapacity(){
    return capacity;
}

unsigned RingBuffer::getBufferAt(unsigned idx){
    assert(idx < this->maxCapacity());
    return buffer[idx];
}

unsigned RingBuffer::getHeadIdx(){
    return headIdx;
}

unsigned RingBuffer::getTailIdx(){
    return tailIdx;
}

void RingBuffer::resetBuffer(){
    headIdx = 0;
    tailIdx = 0;
    full = 0;
}

#else

RingBuffer::RingBuffer(unsigned length){
    buffer = new unsigned[length+1]();
    capacity = length;
    headIdx = 1;
    tailIdx = 1;
}

RingBuffer::~RingBuffer(){
    delete[] buffer;
}

void RingBuffer::printBuffer(){
    std::cout << "full:  " << this->bufferFull() << std::endl;
    std::cout << "empty: " << this->bufferEmpty() << std::endl;
    for (auto it = 0; it < capacity + 1; it++){
        if (it == this->getHeadIdx() && it == this->getTailIdx()){
            std::cout << this->getBufferAt(it) << " " << "< head < tail" << std::endl;
        } else if (it == this->getHeadIdx()){
            std::cout << this->getBufferAt(it) << " " << "< head" << std::endl;
        } else if (it == this->getTailIdx()){
            std::cout << this->getBufferAt(it) << " " << "< tail" << std::endl;
        } else{
            std::cout << this->getBufferAt(it) << std::endl;
        }
    }
    std::cout << std::endl;
}

void RingBuffer::insert(unsigned val){
    assert(!this->bufferFull());
    buffer[tailIdx] = val;
    tailIdx = (tailIdx + 1) % (capacity + 1);
}

unsigned RingBuffer::pop(){
    assert(!this->bufferEmpty());
    unsigned ret = buffer[headIdx];
    headIdx = (headIdx + 1) % (capacity + 1);
    return ret;
}

bool RingBuffer::bufferEmpty(){
    return tailIdx == headIdx;
}

bool RingBuffer::bufferFull(){
    return ((tailIdx + 1) % (capacity + 1)) == headIdx;
}

unsigned RingBuffer::numberOfElements(){

    if (tailIdx >= headIdx){
        return tailIdx - headIdx;
    } else {
        return tailIdx + ((capacity + 1) - headIdx);
    }

    return abs(tailIdx - headIdx);
}

unsigned RingBuffer::maxCapacity(){
    return capacity;
}

unsigned RingBuffer::getBufferAt(unsigned idx){
    assert(idx < this->maxCapacity() + 1);
    return buffer[idx];
}

unsigned RingBuffer::getHeadIdx(){
    return headIdx;
}

unsigned RingBuffer::getTailIdx(){
    return tailIdx;
}

void RingBuffer::resetBuffer(){
    headIdx = 0;
    tailIdx = 0;
}

#endif