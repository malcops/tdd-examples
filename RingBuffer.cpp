#include "RingBuffer.hpp"
#include <iostream>
#include <assert.h>

template <typename T>
RingBuffer<T>::RingBuffer(unsigned length){
    buffer = new T[length]();
    capacity = length;
    headIdx = 0;
    tailIdx = 0;
    full = 0;
}

template <typename T>
RingBuffer<T>::~RingBuffer(){
    delete[] buffer;
}

template <typename T>
void RingBuffer<T>::printBuffer(){
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

template <typename T>
void RingBuffer<T>::insert(T val){
    assert(!this->bufferFull());
    buffer[tailIdx] = val;
    tailIdx++;
    tailIdx = tailIdx % capacity;
    if (tailIdx == headIdx && !full){
        full = 1;
    }
}

template <typename T>
T RingBuffer<T>::pop(){
    assert(!this->bufferEmpty());
    unsigned retVal = buffer[headIdx];
    headIdx++;
    headIdx = headIdx % capacity;
    full = 0;
    return retVal;
}

template <typename T>
bool RingBuffer<T>::bufferEmpty(){
    return (tailIdx == headIdx && !full);
}

template <typename T>
bool RingBuffer<T>::bufferFull(){
    return full;
}

template <typename T>
unsigned RingBuffer<T>::numberOfElements(){
    if (full){
        return capacity;
    } else{
        return abs(headIdx - tailIdx);
    }
}

template <typename T>
unsigned RingBuffer<T>::maxCapacity(){
    return capacity;
}

template<typename T>
T RingBuffer<T>::getBufferAt(unsigned idx){
    assert(idx < this->maxCapacity());
    return buffer[idx];
}

template <typename T>
unsigned RingBuffer<T>::getHeadIdx(){
    return headIdx;
}

template <typename T>
unsigned RingBuffer<T>::getTailIdx(){
    return tailIdx;
}

template <typename T>
void RingBuffer<T>::resetBuffer(){
    headIdx = 0;
    tailIdx = 0;
    full = 0;
}


template class RingBuffer<unsigned>;
template class RingBuffer<float>;