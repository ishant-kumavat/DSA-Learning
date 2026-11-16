// LeetCode 901 => ** Online Stock Span **

// 1). Approach 1 => Monotonic Stack (Using Vector)
//     Time Complexity : O(1) amortized per next() call
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class StockSpanner {
public:
    vector<int> vec;
    vector<int> st;  
    
    StockSpanner() {  
    }

    int next(int price) {
        vec.push_back(price);

        while(!st.empty() && vec[st.back()] <= price) st.pop_back();
        
        int x = (st.empty()) ? vec.size() : vec.size() - st.back() - 1;
        st.push_back(vec.size() - 1);
        
        return x; 
    }
};

// 2). Approach 2 => Monotonic Stack (Price + Span Pair)
//     Time Complexity : O(1) amortized per next() call
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class StockSpanner {
public:
    stack<pair<int, int>> st;

    StockSpanner() {
    }

    int next(int price) {
       int span = 1;
       
       while(!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
       }
       
       st.push({price, span});
       
       return span;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// Maintain a monotonic decreasing stack of {price, span}.
//
// Initialize the current span as 1.
//
// While the top price is less than or equal to
// the current price, add its stored span and pop it.
//
// Push the current price along with its calculated span.
//
// Return the current span