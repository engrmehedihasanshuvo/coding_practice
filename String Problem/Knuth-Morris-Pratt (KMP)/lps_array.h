#include <bits/stdc++.h>

using namespace std;

vector<int> computeLPSArray(string &pattern)
{

    int n = pattern.size();
    vector<int> lps(n, 0);

    // length of the previous longest prefix suffix
    int len = 0, i = 1;
    while (i < n)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}