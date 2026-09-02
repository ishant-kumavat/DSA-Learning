// GFG => Delete all occurrences of a key in DLL

#include <bits/stdc++.h>
using namespace std;
// a Node of the doubly linked list
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
        if(head == nullptr || (head -> next == nullptr && head -> data == x)) return nullptr;
        Node* temp = head;
        while(temp != nullptr){
            if(temp -> data == x){
                if(temp == head){
                    head = head -> next;
                }
                Node* last = temp -> prev; 
                Node* front = temp -> next; 
                if(last) last -> next = front;
                if(front) front -> prev = last;
                delete temp;
                temp = front;
            }
            else temp = temp -> next;
        }
        return head;
    }
};