#include <bits/stdc++.h>
#include "practice 1 search pattern.h"

int main()
{
    string txt = "aabaacaadaabaaba";
    string pat = "aaba";
    vector<int> res= search(pat,txt);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }

    return 0;
}