#include <bits/stdc++.h>
#include "test_data.h"
#include "logic.h"

int main()
{
    TestDataProvider dataProvider;
    string message;
    for (int i = 0; i < dataProvider.getTotalTestCount(); i++)
    {
        message = dataProvider.getAllTests()[i].input;
        cout << "Original Word is: " << message << endl;
        cout << "Reverse Word is: " << reverseWordInbuildLibrary(message);
        cout<<endl<<endl;
    }

    return 0;
}