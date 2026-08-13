// GeeksforGeeks ** Cycle Length in Linked List **

// Optimal Solution => Tortoise and Hare 
// Time Complexity : O(n)
// Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
// Structure of Linked List Node
class Node {
 public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
class Solution {
  public:
    int lengthOfLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;
        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                int cnt = 1;
                slow = slow -> next;
                while(slow != fast){
                    cnt ++;
                    slow = slow -> next;
                }
                return cnt;
            }
        }
        return 0;
    }
};
// Use slow and fast pointers
// to detect a cycle.
//
// When both pointers meet,
// traverse the cycle once
// and count its nodes.
//
// Return the cycle length.
// If no cycle exists,
// return 0.