// LeetCode 234 => ** Palindrome Linked List **

// 1). Brute Force Approach => Using extra space
//     Time Complexity : O(n)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    bool check_palindrome(vector<int>& vec){
        int i = 0, j = vec.size() - 1;
        while(i < j){
            if(vec[i] != vec[j]) return false;
            i++;j--;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        ListNode* temp = head;
        while(temp != nullptr){
            vec.push_back(temp -> val);
            temp = temp -> next;
        }
        return check_palindrome(vec);
    }
};

// 2). Optimal Solution => Using Tortoise and Hare 
//     Time Complexity : O(n)
//     Space Complexity : O(1)

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverse_LL(ListNode* temp){
        if(temp == nullptr || temp -> next == nullptr) return temp;
        ListNode* prev = temp;
        ListNode* curr = temp -> next;
        prev -> next = nullptr;
        while(curr != nullptr){
            ListNode* front = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        fast = reverse_LL(slow);
        ListNode* temp = fast; 
        slow = head;
        while(fast != nullptr){
            if(slow -> val != fast -> val){
                reverse_LL(temp);
                return false;
            }
            slow = slow -> next;
            fast = fast -> next;
        }
        reverse_LL(temp);
        return true;
    }
};
// Find the middle of the linked list
// using slow and fast pointers.
//
// Reverse the second half.
//
// Compare the first half
// with the reversed second half.
//
// If all values match,
// the list is a palindrome.
//
// Restore the reversed second half
// before returning the result.