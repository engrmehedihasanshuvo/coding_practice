#ifndef TEST_DATA_H
#define TEST_DATA_H

#include <string>
#include <vector>
#include <map>
using namespace std;

// Test case structure
struct TestCase {
    string input;
};

// Test data container class
class TestDataProvider {
private:
    vector<TestCase> testCases;
    
public:
    TestDataProvider() {
        loadTestData();
    }
    
    // Load all predefined test cases
    void loadTestData() {
        // Space separated words - Basic cases
        testCases.push_back({"hello shuvo khan"});
        testCases.push_back({"world is dangerous"});
        testCases.push_back({"programming is fun"});
        testCases.push_back({"coding makes life easier"});
        testCases.push_back({"computer science student"});
        
        // Space separated - Names and places
        testCases.push_back({"john doe developer"});
        testCases.push_back({"alice bob charlie"});
        testCases.push_back({"new york city"});
        testCases.push_back({"united states america"});
        testCases.push_back({"london bridge falling"});
        
        // Space separated - Technical terms
        testCases.push_back({"machine learning algorithm"});
        testCases.push_back({"artificial intelligence future"});
        testCases.push_back({"data structure implementation"});
        testCases.push_back({"software engineering principles"});
        testCases.push_back({"web development framework"});
        
        // Space separated - Daily life
        testCases.push_back({"morning coffee routine"});
        testCases.push_back({"weekend family time"});
        testCases.push_back({"summer vacation plans"});
        testCases.push_back({"birthday party celebration"});
        testCases.push_back({"grocery shopping list"});
        
        // Space separated - Mixed length
        testCases.push_back({"a b c"});
        testCases.push_back({"one two"});
        testCases.push_back({"first second third fourth fifth"});
        testCases.push_back({"university computer science department building"});
        testCases.push_back({"international business management conference speaker"});
        
        // Edge cases
        testCases.push_back({"a"});
        testCases.push_back({""});
        testCases.push_back({"single"});
        testCases.push_back({" "});
        testCases.push_back({"  "});
        testCases.push_back({"word "});
        testCases.push_back({" word"});
        
        // Numbers with spaces
        testCases.push_back({"12345"});
        testCases.push_back({"123 456 789"});
        testCases.push_back({"1 2 3 4 5"});

    }
    
    
    // Get all test cases
    vector<TestCase> getAllTests() const {
        return testCases;
    }
    

    
    // Get test case by index
    TestCase getTestCase(int index) const {
        if (index >= 0 && index < testCases.size()) {
            return testCases[index];
        }
        return {""};
    }
    
    // Get total number of test cases
    int getTotalTestCount() const {
        return testCases.size();
    }
    

    
    // Display all available tests
    void displayAllTests() const {
        cout << "\n📋 AVAILABLE TEST CASES (" << testCases.size() << " total)" << endl;
        cout << string(80, '=') << endl;
        
        for (size_t i = 0; i < testCases.size(); i++) {
            const auto& test = testCases[i];
            cout << "    Input: \"" << test.input << "\"" << endl;
            cout << endl;
        }
    }
    
};

#endif // TEST_DATA_H