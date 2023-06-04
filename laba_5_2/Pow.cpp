#include "myPowException.h"

template <typename number, typename power>
number myPow(number T, power E){
    try{
        if(sizeof(E) != 4){
            throw myPowException((std::string &) "powerNotInt");
        }
        number step = T;
        for (int i = 1; i < E; ++i) {
            T *= step;
        }
        return T;
    }
    catch (myPowException& exception){
        std::cerr << exception.what() << "\n";
        return -1;
    }
}