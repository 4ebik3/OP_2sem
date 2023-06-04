#ifndef LABA_5_2_MYPOWEXCEPTION_H
#define LABA_5_2_MYPOWEXCEPTION_H
#include <exception>
#include <iostream>

class myPowException : std::exception {
private:
    std::string error;
public:
    explicit myPowException(std::string &error){
        this->error = error;
    }
    std::string what() {
        return error;
    }
};

#endif //LABA_5_2_MYPOWEXCEPTION_H
