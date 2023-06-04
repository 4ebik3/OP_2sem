#ifndef LABA_5_2_QUEUEEXCEPTION_H
#define LABA_5_2_QUEUEEXCEPTION_H
#include <exception>
#include <iostream>

class QueueException : std::exception {
private:
    std::string error;
public:
    explicit QueueException(std::string &error) {
        this->error = error;
    }
    std::string what() {
        return error;
    }
};

#endif //LABA_5_2_QUEUEEXCEPTION_H
