#ifndef TEST_DATA_H
#define TEST_DATA_H

#include <string>
#include <vector>
#include <map>
using namespace std;

// Test case structure
struct TestCase {
    string input;
    string expectedOutput;
    string description;
    string category;
};

// Test data container class
class TestDataProvider {
private:
    vector<TestCase> testCases;
    map<string, vector<TestCase>> categorizedTests;
    
public:
    TestDataProvider() {
        loadTestData();
        categorizeTests();
    }
    
    // Load all predefined test cases
    void loadTestData() {
        // Basic string reversal tests
        testCases.push_back({"hello", "olleh", "Simple word", "Basic"});
        testCases.push_back({"world", "dlrow", "Another simple word", "Basic"});
        testCases.push_back({"a", "a", "Single character", "Basic"});
        testCases.push_back({"", "", "Empty string", "Edge Case"});
        
        // Palindromes (should reverse to themselves or similar)
        testCases.push_back({"racecar", "racecar", "Palindrome word", "Palindrome"});
        testCases.push_back({"madam", "madam", "Another palindrome", "Palindrome"});
        testCases.push_back({"level", "level", "Palindrome level", "Palindrome"});
        testCases.push_back({"radar", "radar", "Palindrome radar", "Palindrome"});
        
        // Numbers as strings
        testCases.push_back({"12345", "54321", "Number sequence", "Numbers"});
        testCases.push_back({"987654321", "123456789", "Large number", "Numbers"});
        testCases.push_back({"1001", "1001", "Palindromic number", "Numbers"});
        
        // Special characters
        testCases.push_back({"hello!", "!olleh", "Word with exclamation", "Special Characters"});
        testCases.push_back({"@#$%", "%$#@", "Only symbols", "Special Characters"});
        testCases.push_back({"test123", "321tset", "Mixed alphanumeric", "Special Characters"});
        
        // Longer strings
        testCases.push_back({"programming", "gnimmargorP", "Long word", "Long Strings"});
        testCases.push_back({"abcdefghijklmnopqrstuvwxyz", "zyxwvutsrqponmlkjihgfedcba", "Full alphabet", "Long Strings"});
        testCases.push_back({"The quick brown fox", "xof nworb kciuq ehT", "Sentence with spaces", "Long Strings"});
        
        // Performance test cases
        testCases.push_back({string(100, 'a'), string(100, 'a'), "100 same characters", "Performance"});
        testCases.push_back({string(1000, 'x'), string(1000, 'x'), "1000 same characters", "Performance"});
        
        // Edge cases
        testCases.push_back({"  ", "  ", "Only spaces", "Edge Case"});
        testCases.push_back({"\n", "\n", "Newline character", "Edge Case"});
        testCases.push_back({"\t", "\t", "Tab character", "Edge Case"});
        
        // Real-world examples
        testCases.push_back({"GitHub", "buHtiG", "Brand name", "Real World"});
        testCases.push_back({"OpenAI", "IAnepO", "Company name", "Real World"});
        testCases.push_back({"JavaScript", "tpircSavaJ", "Programming language", "Real World"});
    }
    
    // Categorize tests by type
    void categorizeTests() {
        for (const auto& test : testCases) {
            categorizedTests[test.category].push_back(test);
        }
    }
    
    // Get all test cases
    vector<TestCase> getAllTests() const {
        return testCases;
    }
    
    // Get tests by category
    vector<TestCase> getTestsByCategory(const string& category) const {
        auto it = categorizedTests.find(category);
        if (it != categorizedTests.end()) {
            return it->second;
        }
        return {};
    }
    
    // Get available categories
    vector<string> getCategories() const {
        vector<string> categories;
        for (const auto& pair : categorizedTests) {
            categories.push_back(pair.first);
        }
        return categories;
    }
    
    // Get test case by index
    TestCase getTestCase(int index) const {
        if (index >= 0 && index < testCases.size()) {
            return testCases[index];
        }
        return {"", "", "Invalid index", "Error"};
    }
    
    // Get total number of test cases
    int getTotalTestCount() const {
        return testCases.size();
    }
    
    // Add custom test case
    void addTestCase(const string& input, const string& expected, 
                    const string& description, const string& category = "Custom") {
        testCases.push_back({input, expected, description, category});
        categorizedTests[category].push_back(testCases.back());
    }
    
    // Display all available tests
    void displayAllTests() const {
        cout << "\n📋 AVAILABLE TEST CASES (" << testCases.size() << " total)" << endl;
        cout << string(80, '=') << endl;
        
        for (size_t i = 0; i < testCases.size(); i++) {
            const auto& test = testCases[i];
            cout << "[" << (i + 1) << "] " << test.description 
                 << " (" << test.category << ")" << endl;
            cout << "    Input: \"" << test.input << "\"" << endl;
            cout << "    Expected: \"" << test.expectedOutput << "\"" << endl;
            cout << endl;
        }
    }
    
    // Display tests by category
    void displayTestsByCategory() const {
        for (const auto& pair : categorizedTests) {
            cout << "\n📁 " << pair.first << " Tests (" << pair.second.size() << " cases):" << endl;
            cout << string(50, '-') << endl;
            
            for (size_t i = 0; i < pair.second.size(); i++) {
                const auto& test = pair.second[i];
                cout << "  [" << (i + 1) << "] " << test.description << endl;
                cout << "      Input: \"" << test.input << "\" → Expected: \"" 
                     << test.expectedOutput << "\"" << endl;
            }
        }
    }
    
    // Get performance test cases (for benchmarking)
    vector<TestCase> getPerformanceTests() const {
        return getTestsByCategory("Performance");
    }
    
    // Generate random test cases
    void generateRandomTests(int count = 10) {
        srand(time(nullptr));
        
        for (int i = 0; i < count; i++) {
            string randomStr = "";
            int length = rand() % 20 + 1; // 1 to 20 characters
            
            for (int j = 0; j < length; j++) {
                randomStr += char('a' + rand() % 26);
            }
            
            string reversed = randomStr;
            reverse(reversed.begin(), reversed.end());
            
            addTestCase(randomStr, reversed, 
                       "Random string " + to_string(i + 1), "Random");
        }
    }
};

#endif // TEST_DATA_H