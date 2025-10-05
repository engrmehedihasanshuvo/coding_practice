#include<bits/stdc++.h>
#include "test_data.h"
#include "logic.h"


int main() {
    TestDataProvider dataProvider;
    
    cout << "🔄 REVERSE STRING WITH AUTOMATED TESTING" << endl;
    cout << "=======================================" << endl;
    
    int choice;
    cout << "\nSelect mode:" << endl;
    cout << "1. 📝 Manual input (original behavior)" << endl;
    cout << "2. 🧪 Test with predefined data" << endl;
    cout << "3. 📊 Run all test cases" << endl;
    cout << "Choice (1-3): ";
    cin >> choice;
    
    if (choice == 1) {
        // Original manual input behavior
        string message;
        cout << "Enter your message: ";
        cin >> message;
        
        cout << "Original String is: " << message << endl;
        cout << "Reverse String is: " << reverseStringBackwardsTraversal(message) << endl;
        
    } else if (choice == 2) {
        // Show available test cases and let user pick
        cout << "\n📋 Available Test Cases:" << endl;
        auto tests = dataProvider.getAllTests();
        
        for (size_t i = 0; i < tests.size(); i++) {
            cout << "[" << (i + 1) << "] " << tests[i].description 
                 << " - Input: \"" << tests[i].input << "\"" << endl;
        }
        
        cout << "\nSelect test case number (1-" << tests.size() << "): ";
        int testChoice;
        cin >> testChoice;
        
        if (testChoice > 0 && testChoice <= tests.size()) {
            TestCase selected = tests[testChoice - 1];
            string input = selected.input;
            string result = reverseStringBackwardsTraversal(input);
            
            cout << "\n🧪 TEST CASE: " << selected.description << endl;
            cout << "📝 Category: " << selected.category << endl;
            cout << "📥 Input: \"" << selected.input << "\"" << endl;
            cout << "📤 Your Output: \"" << result << "\"" << endl;
            cout << "🎯 Expected: \"" << selected.expectedOutput << "\"" << endl;
            cout << "✅ Result: " << (result == selected.expectedOutput ? "PASS" : "FAIL") << endl;
            
            if (result != selected.expectedOutput) {
                cout << "❌ Test failed! Check your algorithm." << endl;
            } else {
                cout << "🎉 Test passed! Great job!" << endl;
            }
        } else {
            cout << "❌ Invalid selection!" << endl;
        }
        
    } else if (choice == 3) {
        // Run all test cases
        cout << "\n🧪 RUNNING ALL TEST CASES..." << endl;
        cout << string(60, '=') << endl;
        
        auto tests = dataProvider.getAllTests();
        int passed = 0;
        int total = tests.size();
        
        for (size_t i = 0; i < tests.size(); i++) {
            TestCase test = tests[i];
            string input = test.input;
            string result = reverseStringBackwardsTraversal(input);
            bool success = (result == test.expectedOutput);
            
            cout << "[" << (i + 1) << "/" << total << "] " 
                 << (success ? "✅" : "❌") << " " << test.description << endl;
            
            if (!success) {
                cout << "   📥 Input: \"" << test.input << "\"" << endl;
                cout << "   📤 Got: \"" << result << "\"" << endl;
                cout << "   🎯 Expected: \"" << test.expectedOutput << "\"" << endl;
            }
            
            if (success) passed++;
        }
        
        cout << string(60, '-') << endl;
        cout << "📊 FINAL RESULTS:" << endl;
        cout << "✅ Passed: " << passed << "/" << total << " (" 
             << (passed * 100 / total) << "%)" << endl;
        cout << "❌ Failed: " << (total - passed) << "/" << total << endl;
        
        if (passed == total) {
            cout << "🎉 ALL TESTS PASSED! Your algorithm works perfectly!" << endl;
        } else {
            cout << "⚠️  Some tests failed. Review your algorithm." << endl;
        }
        
    } else {
        cout << "❌ Invalid choice!" << endl;
    }
    
    return 0;
}