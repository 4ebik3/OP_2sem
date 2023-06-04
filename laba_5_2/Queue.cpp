#include "QueueException.h"

template<int N, typename type>
class my_queue {
private:
    struct node {
        type data;
        node *child;
    };
    int size;
    node *first, *last;
public:
    my_queue() {
        size = 0;
        first = nullptr;
        last = nullptr;
    }

    void push(type data) {
        try {
            if (this->size >= N) {
                throw QueueException((std::string &) "OutOfRange");
            } else {
                ++this->size;
                node *newNode = new node;
                newNode->data = data;
                newNode->child = nullptr;

                if (this->first == nullptr) {
                    this->first = newNode;
                    this->last = newNode;
                } else {
                    this->last->child = newNode;
                    this->last = newNode;
                }
            }
        }
        catch (QueueException &exception) {
            std::cerr << exception.what() << "\n";
        }
    }

    void pop() {
        try {
            if (this->size == 0) {
                throw QueueException((std::string &) "QueueIsEmpty");
            } else {
                --this->size;
                node *deleteNode = this->first;
                this->first = this->first->child;
                delete deleteNode;
            }
        } catch (QueueException &exception) {
            std::cerr << exception.what() << "\n";
        }
    }

    ~my_queue() {
        while (this->size > 0) {
            --this->size;
            node *deleteNode = this > first;
            this->first = this->first->child;
            delete deleteNode;
        }
    }
};