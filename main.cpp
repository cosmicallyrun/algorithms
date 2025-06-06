#include <cstddef> 
#include <iterator>
template <typename Item>
class Deque {
private:
    struct Node {
        Item data;
        Node* next;
        Node* prev;
    };
    Node* start;
    Node* end;
    std::size_t currentSize;

public:
    Deque(){
        start=nullptr;
        end=nullptr;
        currentSize=0;
    };
    ~Deque();
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
    };
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
return 1;
};
