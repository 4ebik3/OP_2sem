#ifndef LABA_6_2_FUNTION_H
#define LABA_6_2_FUNTION_H

template <class it, class T>
bool allof(it begin, it end, bool (&predicate)(T)) {
    for (begin; begin != end; ++begin) {
        if (!predicate(*(begin))) {
            return false;
        }
    }
    return true;
}
template <class it, class T>
bool anyof(it begin, it end, bool (&predicate)(T)) {
    for (begin; begin != end; ++begin) {
        if (predicate(*(begin))) {
            return true;
        }
    }
    return false;
}
template <class it, class T>
bool noneof(it begin, it end, bool (&predicate)(T)) {
    for (begin; begin != end; ++begin) {
        if (predicate(*(begin))) {
            return false;
        }
    }
    return true;
}
template <class it, class T>
bool oneof (it begin, it end, bool (&predicate)(T)) {
    int count = 0;
    for (begin; begin != end; ++begin) {
        if (predicate(*(begin))) {
            ++count;
        }
        if (count > 1) {
            return false;
        }
    }
    return true;
}
template <class it, class T>
bool issorted(it begin, it end, bool (&predicate) (T, T)) {
    it step = begin;
    ++step;
    --end;
    for (begin; begin != end; ++step, ++begin) {
        if (!predicate(*(begin), *(step))) {
            return false;
        }
    }
    return true;
}
template <class it, class T>
bool ispartitioned(it begin, it end, bool (&predicate) (T)){
    bool flag1 = true, flag2 = true;
    it iterator1 = begin, iterator2 = end;
    while (iterator1 < iterator2){
        if (!predicate(*(iterator1) && predicate(*(iterator2)))){
            flag1 = true;
        }
        else{
            flag1 = false;
        }
        iterator1++;
        iterator2--;
    }
    while (begin < end){
        if (predicate(*(begin) && !predicate(*(end)))){
            flag1 = true;
        }
        else{
            flag1 = false;
        }
        begin++;
        end--;
    }
    return flag1 | flag2;
}
template <class it, class T>
bool findnot(it begin, it end, T item, bool (&predicate)(T, T)) {
    for (begin; begin != end; ++begin) {
        if (!predicate(item, *(begin))) {
            return *(begin);
        }
    }
    return true;
}
template <class it, class T>
bool findbackward(it begin, it end, T item, bool (&predicate)(T, T)) {
    for (end; end != begin; --end) {
        if (!predicate(item, *(end))) {
            return *(end);
        }
    }
    return true;
}
template <class it, class T>
bool ispalindrom(it begin, it end, bool (&predicate)(T, T)) {
    --end;
    while (begin <= end){
        if (!predicate(*(begin), *(end))) {
            return false;
        }
        ++begin;
        --end;
    }
    return true;
}

template <class T>
bool predicateBelowZero(T a) { return a < 0; }
template <class T>
bool predicateAboveZero(T a){ return a > 0; }
template <class T>
bool predicateZero(T a){ return a == 0; }
template <class T>
bool predicateSorted(T a, T b){ return a < b; }
template <class T>
bool predicateIsPartitioned(T a){ return a > 0; }
template <class T>
bool predicateFindNot(T a, T b){ return a != b; }
template <class T>
bool predicateFindBackward(T a, T b){ return a == b; }
template <class T>
bool predicateIsPalindrome(T a, T b) { return a == b; }

#endif //LABA_6_2_FUNTION_H
