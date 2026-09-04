// GFG => Delete all occurrences of a key in DLL

// Optimal Solution =>
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
// Structure of the doubly linked list  Node 
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
class Solution {
  public:
    Node* deleteAllOccurOfX(Node* head, int x) {
        Node* temp = head;
        while(temp != nullptr){
            if(temp -> data == x){
              Node* front = temp -> next;
              if(temp == head) head = front;
              else{
                Node* prev = temp -> prev;
                prev -> next = front;
                if(front) front -> prev = prev;
              }
              temp = front;
            }
            else temp = temp -> next;
        }
        return head;
    }
};

// Traverse the doubly linked list.
//
// If the current node contains x,
// remove it from the list.
//
// If the node is the head,
// update head to the next node.
//
// Otherwise, connect the previous node
// with the next node.
//
// Update the prev pointer of the next node
// if it exists.
//
// Move temp to the next node after deletion.