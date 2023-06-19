#include <stdio.h>
#include <stdlib.h>

// Stock Span Problem

//The stock span problem is a financial problem where we have a
// series of N daily price quotes for a stock and we need to 
//calculate the span of the stock’s price for all N days. The span Si 
//of the stock’s price on a given day i is defined as the maximum
// number of consecutive days just before the given day, for which the
// price of the stock on the current day is less than its price on the
// given day. 

//Input n=7 price[] = [100 80 70 60 85 90]
//Output - 1 1 1 1 4 5

//Naive approach -
//Traverse the input array .For every element visited , traverse the elements
//left to it and increment the span value of it while elements on the left side are
//smaller

//Stacks approach -
//
struct stack{
    int 
}

void calculateSpan(int price[], int n, int S[])
{
    // Create a stack and push index of first
    // element to it
    stack* st;
    st.push(0);
 
    // Span value of first element is always 1
    S[0] = 1;
 
    // Calculate span values for rest of the elements
    for (int i = 1; i < n; i++) {
        // Pop elements from stack while stack is not
        // empty and top of stack is smaller than
        // price[i]
        while (!st.empty() && price[st.top()] <= price[i])
            st.pop();
 
        // If stack becomes empty, then price[i] is
        // greater than all elements on left of it,
        // i.e., price[0], price[1], ..price[i-1].  Else
        // price[i] is greater than elements after
        // top of stack
        S[i] = (st.empty()) ? (i + 1) : (i - st.top());
 
        // Push this element to stack
        st.push(i);
    }

