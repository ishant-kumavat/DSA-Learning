// Implement Queue using Linked List

// push() -> O(1)
// pop()  -> O(1)
// top()  -> O(1)
// size() -> O(1)
// print() -> O(n)
//
// Space Complexity -> O(n)

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val){
            data = val;
            next = nullptr;
        }
};
class Queue{
    public:
        Node* st;
        Node* ed;
        int len = 0;
        Queue(){
            st = ed = nullptr;
        }
        void push(int val){
            Node* newnode = new Node(val);
            if(st == nullptr){
                st = ed = newnode;
            }
            else{
                ed->next = newnode;
                ed = newnode;
            }
            len++;
        }
        void pop(){
            if(st == nullptr){
                cout << "Queue is empty so deletion is not done" << endl;
                return;
            }

            if(st == ed){
                st = ed = nullptr;
                len--;
                return;
            }

            Node* del = st;
            st = st->next;
            del->next = nullptr;
            delete del;
            len--;
        }
        void top(){
            if(st == nullptr) {cout << "Queue is empty so top element is not here" << endl; return;}
            cout << "Top element is : " << st -> data << endl;
        }
        void size(){
            cout << "Size is : " << len << endl;
        }
        void print(){
            Node* temp = st;
            while(temp != nullptr){
                cout << temp -> data << " ";
                temp = temp -> next;
            }
            cout << endl;
        }
};

int main()
{
    Queue q;
    q.push(23);
    q.push(11);
    q.push(10);
    q.pop();
    q.top();
    q.pop();
    q.top();
    q.push(33);
    q.size();
    q.print();
    return 0;
}

// Queue follows FIFO (First In, First Out).
//
// `st` -> Front of the queue
// `ed` -> Rear of the queue
//
// push() -> Insert at rear
// pop()  -> Delete from front