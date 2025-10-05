#include <bits/stdc++.h>
using namespace std;

string reverseStringBackwardsTraversal(string &s)
{
    // Time Complexity O(n) Space Complexity O(n)

    string temp;
    int length = s.length();
    for (int i = length - 1; i >= 0; i--)
    {
        temp += s[i];
    }
    return temp;
}

string reverseStringTwoPointer(string &s)
{

    // Time Complexity O(n); Space Complexity O(1)

    int left = 0, right = s.length() - 1;
    string newString;

    while (left < right)
    {
        swap(s[left], s[right]);
        left++;
        right--;
    }

    return s;
}

string reverseStringRcurrsive(string &s, int left, int right)
{
    // Time Complexity: O(n) where n is length of string
    // Auxiliary Space: O(n)

    if (left >= right)
        return;
    swap(s[left], s[right]);
    return reverseStringRcurrsive(s, left + 1, right - 1);
}

string reverseStringUsigStack(string &s){
    //The idea is to use stack for reversing a string because Stack follows Last In First Out (LIFO) principle. This means the last character you add is the first one you'll take out. So, when we push all the characters of a string into the stack, the last character becomes the first one to pop.  
    // O(n) Time and O(n) Space
    stack<char> st;
    for(int i=0;i<s.size();i++) st.push(s[i]);
    for(int i=0;i<s.size();i++){
        s[i]=st.top();
        st.pop();
    }
    return s;
}

string reverseStringInBuildMethods(string & s){
    // Using Inbuilt methods - O(n) Time and O(1) Space
    reverse(s.begin(), s.end());
    return s;
}