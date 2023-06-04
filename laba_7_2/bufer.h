#ifndef LABA_7_2_BUFER_H
#define LABA_7_2_BUFER_H

#include "iostream"

template <class T>
class circleBuffer {
public:
    class iterator{
    private:
        T *pointer;
    public:
        iterator() : pointer(nullptr){};
        iterator(T *t) : pointer(t){};
        iterator(const iterator &t) : pointer(t.pointer){};

        T& operator *() const{ return *pointer; }
        T* operator ->() const{ return pointer; }
        T& operator [](T difference){ return pointer[difference]; }

        iterator operator +(const T difference){ return iterator(pointer + difference); }
        iterator operator -(const T difference){ return iterator(pointer - difference); }
        iterator operator +=(const T difference){ pointer += difference; return *this; }
        iterator operator -=(const T difference){ pointer -= difference; return *this; }

        iterator operator ++(){pointer++; return *this;}
        iterator operator --(){pointer--; return *this;}

        const iterator* operator ++(T){
            const iterator *tmp(*this);
            pointer++;
            return tmp;
        }
        const iterator* operator --(T){
            const iterator *tmp(*this);
            pointer--;
            return tmp;
        }

        bool operator ==(iterator const &t){ return pointer == t.pointer; }
        bool operator !=(iterator const &t){ return pointer != t.pointer; }
        bool operator > (iterator const &t){ return pointer > t.pointer; }
        bool operator >= (iterator const &t){ return pointer >= t.pointer; }
        bool operator < (iterator const &t){ return pointer < t.pointer; }
        bool operator <= (iterator const &t){ return pointer <= t.pointer; }

    };
private:
    size_t size, currentSize;
    size_t first, last;
    bool circle;
    T* array;
public:
    explicit circleBuffer(size_t size){
        this->size = size; currentSize = 0;
        first = 0; last = 0; circle = false;
        array = new T[size];
        for(size_t i = 0; i < size; ++i){ array[i] = 0; }
    }
    explicit circleBuffer(size_t size, T value){
        this->size = size; currentSize = 0;
        first = 0; last = 0; circle = false;
        array = new T[size];
        for(size_t i = 0; i < size; ++i){ array[i] = value; }
    }

    iterator begin(){ return iterator(array); }
    iterator end(){ return  iterator(&array[size]); }

    T& operator[](size_t index){
        if(index >= size){ throw std::out_of_range("Out of range"); }
        return array[index];
    }
    void resize(size_t newSize){
        T *tmp = array;
        array = new T[newSize];
        for(int i = 0; i < newSize; ++i){
            if(i < size){ array[i] = tmp[i]; }
            else{ array[i] = 0; }
        }
        size = newSize;
    }

    void pushBack(T value){
        if(last == first && circle){ throw std::out_of_range("Out of range"); }
        array[last++] = value;
        last %= size;
        if(last == 0){ circle = true; }
        ++currentSize;
    }
    void popBack(){
        if(!circle && first == last){ throw std::out_of_range("Out of range"); }
        if(last == 0){ last = size - 1; circle = false; }
        else{ --last; }
        --currentSize;
    }

    void pushFront(T value){
        if(first == last && circle) { throw std::out_of_range("Out of range"); }
        if(first == 0){
            first = size; circle = true;
        }
        array[--first] = value;
        ++currentSize;
    }
    void popFront(){
        if(!circle && first == last) { throw std::out_of_range("Out of range"); }
        if((first + 1) % size == 0) { circle = false; }
        first = (first + 1) % size;
        --currentSize;
    }

    void insert(iterator index, T value){
        if(last == first && circle || currentSize >= size){ throw std::out_of_range("Out of range"); }
        ++currentSize;
        while (index <= end()){
            T lastValue = *index;
            *index = value;
            ++index;
            value = lastValue;
        }
    }
    void erase(iterator index){
        if(!circle && first == last || currentSize <= 0){ throw std::out_of_range("Out of range"); }
        --currentSize;
        while (index <= end()){
            T lastValue = *(index + 1);
            *index = lastValue;
            ++index;
        }
    }
    ~circleBuffer(){
        free(array);
    };
};



#endif //LABA_7_2_BUFER_H
