// Implement Queue using Arrays

#include <bits/stdc++.h>
using namespace std;

class Queue{
    public:
        int st = -1;
        int ed = -1;
        int arr[5];
        int capacity = 5;
        int size = 0;
        void push(int x){
            if(size == capacity) {
                cout << "Queue is Full" << endl;
                return;
            }
            if(st == -1) st = ed = 0;
            else ed = (ed + 1) % capacity;
            arr[ed] = x;
            size ++;
        }
        void pop(){
            if(size == 0) {cout << "Queue is Empty so no more pop operation will performed" << endl; return ;}
            if(st == ed) st = ed = -1;
            else st = (st + 1) % capacity;
            size --;
        }
        void top(){
            if(size == 0) {cout << "Queue is empty so top element is not exist" << endl; return ;}
            cout << "Top element is : " << arr[st] << endl;
        }
        void length(){
            cout << "Size is : " << size << endl;
        }
        void print(){
            for(int i = 0; i < size; i++){
                cout << arr[(st + i) % capacity] << " ";
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
    q.length();
    q.print();
    return 0;
}

// Implement Circular Queue using Array
//
// Queue follows FIFO (First In, First Out).
//
// `st` stores the index of the front element.
// `ed` stores the index of the rear element.
// `size` stores the current number of elements.
//
// Circular behavior:
// After reaching the last index, the rear/front
// wraps around using modulo (%) operator.
//
// Empty Queue  -> size == 0
// Full Queue   -> size == capacity