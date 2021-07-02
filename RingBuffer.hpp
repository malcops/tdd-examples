/* Circular Buffer API:
 -> initialize the circular buffer container with a buffer and size
 -> destroy a circular buffer container
 -> reset the circular buffer container
 -> be able to add data to the buffer
 -> be able to get the next value from the buffer
 -> know whether the buffer is full or empty
 -> know the current number of elements in the buffer
 -> know the max capacity of the buffer
*/

class RingBuffer{

    public:
        RingBuffer(unsigned length);
        ~RingBuffer();
        void printBuffer();
        void insert(unsigned val);
        unsigned pop();
        bool bufferEmpty();
        bool bufferFull();
        unsigned numberOfElements();
        unsigned maxCapacity();
        unsigned getBufferAt(unsigned idx);
        unsigned getHeadIdx();
        unsigned getTailIdx();
        void resetBuffer();

    private:
        unsigned capacity;
        unsigned headIdx;
        unsigned tailIdx;
#ifdef FULL_FLAG_IMPLEMENTATION
        unsigned full;
#endif
        unsigned *buffer;
};
