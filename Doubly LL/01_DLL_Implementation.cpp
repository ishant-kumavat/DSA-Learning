// Doubly Linked List
// Each node contains:
// 1. data  -> stores the value
// 2. next  -> points to the next node
// 3. back  -> points to the previous node

#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* back;
        Node(int val){
            data = val;
            next = nullptr;
            back = nullptr;
        }
};
class List{
    public:
    Node* head = nullptr;
    void pop_back(){
        if(head == nullptr) return;
        if(head -> next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while(temp -> next != nullptr){
            temp = temp -> next; 
        }
        Node* pre = temp -> back;
        pre -> next = nullptr;
        temp -> back = nullptr;
        delete temp;
    }
    void pop_front(){
        if(head == NULL) return;
        if(head -> next == NULL){
            Node* temp = head;
            delete temp;
            head = NULL;return;
        }
        Node* temp = head -> next;
        head -> next = NULL;
        temp -> back = NULL;
        delete head;
        head = temp;
    }
    void push_back(int val){
        if(head == nullptr){
            Node* newNode = new Node(val);
            head = newNode;
            return;
        }
        if(head -> next == nullptr){
            Node* newNode = new Node(val);
            newNode -> back = head;
            head -> next = newNode;
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        while(temp -> next != nullptr){
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode -> back = temp;
        return;
    }
    void push_front(int val){
        if(head == nullptr){
            Node* newNode = new Node(val);
            head = newNode;
            return;
        }
        Node* newNode = new Node(val);
        newNode -> next = head;
        head -> back = newNode;
        head = newNode;
        return;
    }
    void insert_before_tail(int val){
        if(head == nullptr || head -> next == nullptr) return push_front(val);
        Node* temp = head;
        while(temp -> next != nullptr){
            temp = temp -> next;
        }
        Node* newNode = new Node(val);
        Node* pre = temp -> back;
        pre -> next = newNode;
        newNode -> back = pre;
        temp -> back = newNode;
        newNode -> next = temp;
    }
    void delete_node(Node* temp){
        if(temp == nullptr) return;
        if(temp == head){
            head = temp -> next;
            if(head != nullptr)
            head -> back = nullptr;
            delete temp;
            return;
        }
        if(temp -> next == nullptr){
            Node* pre = temp -> back;
            pre -> next = nullptr;
            delete temp;
            return;
        }
        Node* pre = temp -> back;
        Node* nxt = temp -> next;
        pre -> next = nxt;
        nxt -> back = pre;
        delete temp;
    }
    void before_kth_node(int val, int pos){
        if(head == nullptr || pos <= 0) {
            cout << "Enter Valid Position\n";
            return;
        }
        if(pos == 1) return push_front(val);
        Node* temp = head;
        int cnt = 1;
        while(cnt != pos){
            cnt ++;
            temp = temp -> next;
            if(temp == nullptr){
                if(cnt == pos) return push_back(val);
                else {
                    cout<<"Enter Valid Position\n";
                    return;
                }
            } 
        }
        Node* newNode = new Node(val);
        Node* pre = temp -> back;
        pre -> next = newNode;
        newNode -> back = pre;
        temp -> back = newNode;
        newNode -> next = temp;
    }
    void insertgivennode(int val, int x){
        Node* temp = head;
        while(temp != nullptr && temp -> data != val){
            temp = temp -> next;
        }
        if(temp == nullptr){
            cout << "Node not found\n";
            return;
        }
        if(temp == head){
            return push_front(x);
        }
        Node* newNode = new Node(x);
        Node* pre = temp -> back;
        pre -> next = newNode;
        newNode -> back = pre;
        newNode -> next = temp;
        temp -> back = newNode;
    }
    void Array_to_LL(vector<int>& nums){
        if(nums.empty()){
            head = nullptr;
            return;
        }
        Node* newNode = new Node(nums[0]);
        head = newNode;
        Node* temp = head;
        for(int i = 1; i < nums.size(); i++){
            Node* newNode = new Node(nums[i]);
            temp -> next = newNode;
            newNode -> back = temp;
            temp = newNode;
        }
    }
    void print(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp -> data << " ";
            temp = temp -> next;
        }
        cout<<endl;
    }
};
int main(){
    vector<int>nums = {30, 43, 41, 90};
    List ll;
    ll.Array_to_LL(nums);
    ll.pop_back();
    ll.push_front(22);
    ll.before_kth_node(21, 2);
    ll.insertgivennode(33, 6);
    ll.print();
}

// Doubly Linked List Implementation
//
// Supports:
// - Push Front
// - Push Back
// - Pop Front
// - Pop Back
// - Insert Before Tail
// - Insert Before Kth Node
// - Insert Before Given Node
// - Delete Given Node
// - Array to Linked List
// - Print Linked List