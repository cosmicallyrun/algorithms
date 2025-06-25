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
class BST {
private:
    struct Node {
        int value;
        Node* parent;
        Node* left;
        Node* right;
    };
    Node* root = nullptr;
    void recPrintInOrder(Node* node){
        if (node==nullptr){
            return;
        }
        recPrintInOrder(node->left);
        std::cout << node -> value << " ";
        recPrintInOrder(node->right);
    }
public:
    BST(){}
    void insert(int val){
        if (!root){
            root = new Node{val,nullptr,nullptr,nullptr};
        } else{
            Node* currentNode = root;
            while(true){
                if (currentNode->value>val){
                    if (currentNode->left !=nullptr){
                        currentNode=currentNode->left;
                    }else{
                        currentNode->left=new Node{val,currentNode,nullptr,nullptr};
                        break;
                    }
                }else if (currentNode->value<val){
                    if (currentNode->right !=nullptr){
                        currentNode=currentNode->right;
                    }else{
                        currentNode->right=new Node{val,currentNode,nullptr,nullptr};
                        break;
                    }
                }else{
                    abort();
                }
            }
        }
    }
    bool contains(int val){
    Node* currentNode = root;
    while (currentNode != nullptr) {
        if (val < currentNode->value) {
            currentNode = currentNode->left;
        } else if (val > currentNode->value) {
            currentNode = currentNode->right;
        } else {
            return true; 
        }
    }
    return false;
    }
    void printInOrder(){
        recPrintInOrder(root);
        std::cout << std::endl; 
    }
};
int main() {
    // Test Case 1: A standard, non-trivial tree
    // ----------------------------------------------------
    std::cout << "--- Test Case 1: Populating a standard tree ---" << std::endl;
    BST my_bst;
    my_bst.insert(20);
    my_bst.insert(10);
    my_bst.insert(30);
    my_bst.insert(5);
    my_bst.insert(15);
    my_bst.insert(25);
    my_bst.insert(35);
    my_bst.insert(1);
    my_bst.insert(18);

    /* The tree should look like this:
                    20
                   /  \
                  10   30
                 / \   / \
                5  15 25  35
               /     \
              1      18
    */

    std::cout << "\n--- Testing printInOrder() ---" << std::endl;
    std::cout << "Expected: 1 5 10 15 18 20 25 30 35" << std::endl;
    std::cout << "Actual:   ";
    my_bst.printInOrder(); // This should print the numbers in sorted order
    std::cout << "---------------------------------\n" << std::endl;


    std::cout << "--- Testing contains() ---" << std::endl;
    std::cout << "Contains 15 (should be true): " << (my_bst.contains(15) ? "true" : "false") << std::endl;
    std::cout << "Contains 1 (root's far left, should be true): " << (my_bst.contains(1) ? "true" : "false") << std::endl;
    std::cout << "Contains 35 (root's far right, should be true): " << (my_bst.contains(35) ? "true" : "false") << std::endl;
    std::cout << "Contains 20 (root, should be true): " << (my_bst.contains(20) ? "true" : "false") << std::endl;
    
    std::cout << "Contains 99 (should be false): " << (my_bst.contains(99) ? "true" : "false") << std::endl;
    std::cout << "Contains 17 (should be false): " << (my_bst.contains(17) ? "true" : "false") << std::endl;
    std::cout << "-----------------------------\n" << std::endl;

    // Test Case 2: An empty tree
    // ----------------------------------------------------
    std::cout << "--- Test Case 2: An empty tree ---" << std::endl;
    BST empty_bst;
    std::cout << "Expected (empty tree): " << std::endl;
    std::cout << "Actual:   ";
    empty_bst.printInOrder();
    std::cout << "Contains 42 (should be false): " << (empty_bst.contains(42) ? "true" : "false") << std::endl;
    std::cout << "---------------------------------\n" << std::endl;


    // Test Case 3: A tree with only one node
    // ----------------------------------------------------
    std::cout << "--- Test Case 3: A single-node tree ---" << std::endl;
    BST single_node_bst;
    single_node_bst.insert(50);
    std::cout << "Expected: 50" << std::endl;
    std::cout << "Actual:   ";
    single_node_bst.printInOrder();
    std::cout << "Contains 50 (should be true): " << (single_node_bst.contains(50) ? "true" : "false") << std::endl;
    std::cout << "Contains 100 (should be false): " << (single_node_bst.contains(100) ? "true" : "false") << std::endl;
    std::cout << "--------------------------------------\n" << std::endl;


    // Test Case 4: Inserting duplicates (if you're aborting)
    // ----------------------------------------------------
    std::cout << "--- Test Case 4: Testing duplicate insertion ---" << std::endl;
    std::cout << "The program should abort if you insert 20 again." << std::endl;
    std::cout << "If you changed your code to ignore duplicates, this will do nothing." << std::endl;
    // Uncomment the next line to test your duplicate handling
    // my_bst.insert(20); 
    std::cout << "Test complete." << std::endl;


    return 0;
}