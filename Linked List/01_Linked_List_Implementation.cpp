// Singly Linked List Implementation

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next; // Pointer to the next node in the linked list.
    // Node class represents
    // a single node of the linked list.
    Node(int val){
        data = val;
        next = NULL;
    }
};
// List class manages
// all linked list operations.
class List{
    Node* head;
    Node* tail;
    public:
    List(){
        head = tail = NULL;
    }
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL) head = tail = newNode;
        else{
            newNode -> next = head;
            head = newNode; 
        }
    }
    void push_back(int val){
        Node* newNode = new Node(val); 
        // Create a new node dynamically.
        // Its constructor initializes
        // data with val and next with NULL.
        if(head == NULL) head = tail = newNode;
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
    void pop_front(){
        if(head == NULL) return;
        else{
            Node* temp = head;
            head = head->next;
            if(head == NULL)
                tail = NULL;
            delete temp;
        }
    }
    void pop_back(){
        if(head == NULL) return;
        else if(head == tail){
            delete head;
            head = tail = NULL;
            return;
        }
        else{
            Node* temp = head;
            while(temp -> next != tail) temp  = temp -> next;
            temp -> next = NULL;
            delete tail;
            tail = temp;
        }
    }
    void insert(int pos, int val){
        if(pos == 0) {
            push_front(val);
            return;
        }
        int cnt = 1;
        Node* temp = head;
        while(cnt != pos){
            if(temp == NULL){
                cout<<"Enter Invalid Index"<<endl;
                return;
            }
            temp = temp -> next;
            cnt++;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        if(temp == tail)
            tail = newNode;
        }
    void search(int val){
        Node* temp = head;
        while(temp != NULL){
            if(temp -> data == val){
                cout<<"Value is Found"<<endl;
                return;
            }
            temp = temp -> next;
        }
        cout<<"Value is Not Found"<<endl;
    }
    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }
};
int main()
{
    List ll;
    ll.push_front(12);
    ll.push_front(22);
    ll.push_back(10);
    ll.push_back(30);
    ll.pop_front();
    ll.pop_back();
    ll.print();
    ll.insert(2, 99);
    ll.search(199);
    ll.print();
    return 0;
}

// Linked List Structure
/*
      Head                                      Tail
    |----------|         |----------|         |----------|
    | Data     |         | Data     |         | Data     |
    | next ptr | ------> | next ptr | ------> | next ptr | ------> NULL
    |----------|         |----------|         |----------|
*/