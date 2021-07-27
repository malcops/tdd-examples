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

template <typename T>
class RingBuffer{

    public:
        RingBuffer(unsigned length);
        ~RingBuffer();
        void printBuffer();
        void insert(T val);
        T pop();
        bool bufferEmpty();
        bool bufferFull();
        unsigned numberOfElements();
        unsigned maxCapacity();
        T getBufferAt(unsigned idx);
        unsigned getHeadIdx();
        unsigned getTailIdx();
        void resetBuffer();

    private:
        unsigned capacity;
        unsigned headIdx;
        unsigned tailIdx;
        unsigned full;
        T *buffer;
};
