// GFG => Add 1 to a Linked List Number 

// 1). Optimal Solution => Reverse + Carry Propagation
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
// Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
class Solution {
  public:
    int add_one_LL(Node* temp){
        int carry = 1;
        while(temp != nullptr){
            temp -> data += carry;
            if(temp -> data != 10) return 0;
            else temp -> data = 0;
            temp = temp -> next;
        }
        return 1;
    }
    Node* reverse_LL(Node* temp){
        if(temp == nullptr || temp -> next == nullptr) return temp;
        Node* prev = temp;
        temp = temp -> next;
        prev -> next = nullptr;
        while(temp != nullptr){
            Node* front = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        Node* newhead = reverse_LL(head);
        int carry = add_one_LL(newhead);
        head = reverse_LL(newhead);
        if(carry == 1){
            Node* newnode = new Node(1);
            newnode -> next = head;
            head = newnode;
        }
        return head;
    }
};

// Reverse the linked list
// so that the least significant digit
// comes first.
//
// Add 1 to the reversed list
// and propagate the carry.
//
// If a digit becomes 10,
// set it to 0 and continue the carry.
//
// Reverse the list again
// to restore the original order.
//
// If carry is still 1 after processing
// the entire list, create a new node
// with value 1 at the beginning.


// 2). Recursive Solution => Recursion + Carry Propagation
//     Time Complexity : O(n)
//     Space Complexity : O(n) -> Recursive Call Stack

#include <bits/stdc++.h>
using namespace std;
// Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
class Solution {
  public:
    int add_one_LL(Node* temp){
        if(temp == nullptr) return 1;
        int carry = add_one_LL(temp -> next);
        temp -> data += carry;
        if(temp -> data == 10){
            temp -> data = 0;
            return 1;
        }
        return 0;
    }
    Node* addOne(Node* head) {
        int carry = add_one_LL(head);
        if(carry == 1){
            Node* newnode = new Node(1);
            newnode -> next = head;
            head = newnode;
        }
        return head;
    }
};

// Recursively reach the last node
// because the last node contains
// the least significant digit.
//
// The base case returns carry = 1,
// representing the +1 operation.
//
// At every node:
// - Add the received carry.
// - If the digit becomes 10,
//   make it 0 and return carry = 1.
// - Otherwise, return carry = 0.
//
// After processing the first node,
// if carry is still 1,
// create a new node with value 1
// at the beginning.