#include <bits/stdc++.h>
using namespace std;

//[Naive Approach] Using Stack - O(n) Time and O(n) Space 
string reverseWordNaiveApproach(string &s)
{
    // Push all words separated by dots into a stack, then pop each word one by one and append it back to form the reversed string.

    stack<string> st;
    string result="";

    for(int i=0;i<s.size();i++){
          // If we see a dot, we push the
        // previously seen word into the stack.
        if(s[i]!=' ') result+=s[i];
        else if(!result.empty()){
            st.push(result);
            result="";
        }
    }
      // Last word remaining, add it to stack
    if(!result.empty()){
        st.push(result);
    }
    result="";
    // Now add from top to bottom of the stack
    while(!st.empty()){
        result+=st.top();
        st.pop();
        if(!st.empty()) result+=" ";
    }
    return result;
}

//[Expected Approach] Using Two Pointer - O(n) Time and O(1) Space 
string reverseWordUsingTwoPointer(string &s){
    reverse(s.begin(),s.end());
    string temp="";
    string newSentence="";
    int n=s.size();

    for(int i=0;i<n;i++){
        if(s[i]!=' '){
            // go to the beginning of the word
            temp=" ";
            // go to the end of the word
            int j=i;
            while (j<n && s[j]!=' ')
            {
                temp+=s[j++];
            }
            reverse(temp.begin(), temp.end());
            newSentence+=temp;
            // move to the next word
            i=j;
        }
    }

    return newSentence;
}

// Using inbuilt library functions - O(n) Time and O(n) Space
string reverseWordInbuildLibrary(string & s){
    vector<string> words;
    stringstream ss(s);
    string word;
    while (getline(ss,word,' '))
    {
        if(!word.empty()) words.push_back(word);
    }

    reverse(words.begin(),words.end());
    string result;
    for(int i=0;i< words.size();i++){
        if(i>0) result+=" ";
        result+=words[i];
    }
    return result;
    
}