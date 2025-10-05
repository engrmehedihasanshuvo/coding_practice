#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string &s)
{

    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {
        if (s[left] != s[right])
        {
            return 0;
        }
        left++;
        right--;
    }

    return 1;
}

int isPalindrome2(string &s)
{
    int len = s.length();
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int ispalindrome3(string &s, int left, int right)
{

    if (left >= right)
        return 1;
    if (s[left] != s[right])
        return 0;
    return ispalindrome3(s, left + 1, right - 1);
}

// Optimized version with early length check
int isPalindrome4(const string &s)
{
    int len = s.length();
    if (len <= 1) return 1; // Empty or single char is palindrome
    
    // Direct comparison without extra variables
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - 1 - i])
            return 0;
    }
    return 1;
}

// Memory-efficient version (no string copying)
int isPalindrome5(const char* s)
{
    if (!s) return 1;
    int len = strlen(s);
    if (len <= 1) return 1;
    
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - 1 - i])
            return 0;
    }
    return 1;
}

int main()
{
    string test;
    int type;
    while (true)
    {
        cout << "Enter Type:" << endl;
        cout << "1 = Iterative (two-pointer)" << endl;
        cout << "2 = Loop-based" << endl; 
        cout << "3 = Recursive" << endl;
        cout << "4 = Optimized" << endl;
        cout << "5 = C-string version" << endl;
        cout << "Choice (1-5, or any other to exit): ";
        cin >> type;
        if(type<1 || type>5) break;
        cout << "Enter a string: ";
        cin >> test;
        if (type == 1)
        {
            if (isPalindrome(test))
            {
                cout << "The string is a palindrome" << endl;
            }else{
                cout << "The string is not a palindrome" << endl;
            }
        }
        else if (type == 2)
        {
            if (isPalindrome2(test))
            {
                cout << "The string is a palindrome" << endl;
            }else{
                cout << "The string is not a palindrome" << endl;
            }
        }
        else if (type == 3)
        {
            if (ispalindrome3(test, 0, test.length() - 1))
            {
                cout << "The string is a palindrome" << endl;
            }else{
                cout << "The string is not a palindrome" << endl;
            }
        }
        else if (type == 4)
        {
            if (isPalindrome4(test))
            {
                cout << "The string is a palindrome" << endl;
            }else{
                cout << "The string is not a palindrome" << endl;
            }
        }
        else if (type == 5)
        {
            if (isPalindrome5(test.c_str()))
            {
                cout << "The string is a palindrome" << endl;
            }else{
                cout << "The string is not a palindrome" << endl;
            }
        }
        else
        {
            cout << "Invalid type selected." << endl;
        }
    }

    return 0;
}