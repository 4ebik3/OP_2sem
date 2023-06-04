#ifndef LABA_3_2_MAIN_H
#define LABA_3_2_MAIN_H

class Square {
private:
    float x, y;
    float side;
    float corner;
public:
    Square(float x, float y, float side, float corner);

    bool operator==(Square &t) const;
    bool operator>(Square &t) const;
    bool operator<(Square &t) const;
    bool operator>=(Square &t) const;
    bool operator<=(Square &t) const;

    Square operator* (float t);
    Square operator+ (const float t[2]) const;

    void getSquare() const;
};

class stack {
private:
    int *arr;
    int end;
    int size;
    int sizeMax;
public:
    explicit stack(int t);

    stack *operator<<(int t);

    void operator>>(int &t);

    void print();
};

#endif //LABA_3_2_MAIN_H