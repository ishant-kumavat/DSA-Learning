// Implement Stack Using Linked List

// Time Complexity:
// push() -> O(1)
// pop()  -> O(1)
// top()  -> O(1)
// size() -> O(1)
// print() -> O(n)
//
// Space Complexity:
// O(n)

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
class Stack{
    public:
        Node* temp;
        int len = 0;
        Stack(){
            temp = nullptr;
        }
        void push(int val){
            Node* newnode = new Node(val);
            newnode -> next = temp;
            temp = newnode;
            len ++; 
        }
        void pop(){
            if(temp == nullptr){cout << "Stack is empty so deletion is not done.." << endl; return;}
            Node* del = temp;
            temp = temp -> next;
            del -> next = nullptr;
            delete del;
            len --;
        }
        void top(){
            if(temp == nullptr) {cout << "Stack is empty so top element is not exist" << endl; return;}
            cout << "Top element is : " << temp -> data << endl;
        }
        void size(){
            cout << "Size is : " << len << endl;
        }
        void print(){
            Node* cpy = temp;
            while(cpy != nullptr){
                cout << cpy->data << " ";
                cpy = cpy->next;
            }
            cout << endl;
        }
};

int main()
{
    Stack st;
    st.push(23);
    st.push(44);
    st.push(12);
    st.top();
    st.pop();
    st.pop();
    st.pop();
    st.top();
    st.size();
    st.push(21);
    st.print();
    return 0;
}

// Stack follows LIFO (Last In, First Out).

// We use the head node as the TOP of the stack.
//
// push() -> Insert a new node at the beginning.
// pop()  -> Delete the first node.
// top()  -> Access the first node.
//
// Therefore, push(), pop() and top()
// can be performed in O(1) time.