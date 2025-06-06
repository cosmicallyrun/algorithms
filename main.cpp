#include <cstddef> 
#include <iterator>
#include <iostream>
using namespace std;
#include <stdio.h>
template <typename Item>
class Deque {
private:
    struct Node {
        Item data;
        Node* next;
        Node* prev;
    };
    Node* start = nullptr;
    Node* end = nullptr;
    std::size_t currentSize = 0;

public:
    Deque(){}
    ~Deque(){
        while (start!=nullptr){
            removeFirst();
        }
    }
    bool isEmpty() {
        return start==nullptr;
    };
    std::size_t size() {
        return currentSize;
    };
    void addFirst(const Item& item){
        Node* newNode = new Node{item, start, nullptr};
        if (start!=nullptr){
                start->prev=newNode;
        }else{
            end=newNode;
        };
        start=newNode;
        currentSize++;
    }
    void addLast(const Item& item){
        Node* newNode = new Node{item, nullptr, end};
        if (end!=nullptr){
            end->next=newNode;
        }else{
            start=newNode;
        };
        end=newNode;
        currentSize++;
    }
    Item removeFirst(){
        if (!isEmpty()){
             Node* oldStart = start;
             Item data = oldStart->data;
             start = start->next;
             if (start!=nullptr){
                start->prev=nullptr;
             }else{
                end=nullptr;
             }
             delete oldStart;
             currentSize--;
             return data;
        } 
         abort();
    };
    Item removeLast(){
        if (!isEmpty()){
             Node* oldEnd = end;
             Item data = oldEnd->data;
             end = end->prev;
             if (start!=nullptr){
                end->next=nullptr;
             }else{
                start=nullptr;
             }
             delete oldEnd;
             currentSize--;
             return data;
        };
    };
};

int main(){
    Deque<int> dq{};

    dq.addFirst(5);
    for (int i = 4; i >= 0; --i)
        dq.addFirst(i);
    for (int i = 6; i < 10; ++i)
        dq.addLast(i);
    
    while (!dq.isEmpty()) {
        auto data = dq.removeFirst();
        printf("%d",data); 

    }

    return 0;
};
