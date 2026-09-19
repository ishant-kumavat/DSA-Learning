// Implement Stack using Arrays

#include <bits/stdc++.h>
using namespace std;

class Stack{
  public:
    int top = -1;
    int nums[5];
    int capacity = 5;
    void push(int x){
        if((top + 1) == capacity) {
            cout << "Stack is Full" << endl;
            return;
        }
        top ++;
        nums[top] = x;
    }  
    void pop(){
        if(top == -1){
            cout << "Can't pop element because Stack is Empty" << endl;
            return ;
        }
        top --;
    }
    void top_element(){
        if(top == -1){
            cout << "Top element does not exist because Stack is Empty" << endl;
            return ;
        }
        cout << "Top Element is : " << nums[top] << endl;
    }
    void size(){
        cout << "Stack size is : " << (top + 1) << endl; 
    }
    void print(){
        if(top == -1){
            cout << "Stack is Empty" << endl;
            return ;
            
        }
        for(int i = 0; i <= top; i++){
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st;
    st.push(12);
    st.push(22);
    st.push(10);
    st.top_element();
    st.pop();
    st.top_element();
    st.print();
    return 0;
}

// Stack follows LIFO (Last In, First Out).
//
// `top` stores the index of the top element.
//
// Initially, top = -1 means the stack is empty.
//
// Push:
// Increment top and insert the element.
//
// Pop:
// Decrement top to remove the top element.
//
// Top:
// nums[top] gives the current top element.
//
// Size:
// Number of elements = top + 1.
//
// Overflow occurs when the stack is full.
// Underflow occurs when pop/top is performed on an empty stack.