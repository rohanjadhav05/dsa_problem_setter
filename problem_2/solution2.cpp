#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

bool areIsomorphic(const string& s, const string& t) {
    if (s.length() != t.length()) {
        return false;
    }
    
    unordered_map<char, char> sToT;
    unordered_map<char, char> tToS;
    
    for (int i = 0; i < s.length(); ++i) {
        char charS = s[i];
        char charT = t[i];
        
        if (sToT.find(charS) == sToT.end() && tToS.find(charT) == tToS.end()) {
            sToT[charS] = charT;
            tToS[charT] = charS;
        } else if (sToT[charS] != charT || tToS[charT] != charS) {
            return false;
        }
    }
    
    return true;
}

int main() {
    ifstream infile("test.txt");
    if (!infile) {
        cerr << "File 'test.txt' not found." << endl;
        return 1;
    }
    
    string line;
    int testCaseNumber = 1;
    while (getline(infile, line)) {
        if (line.empty() || line.substr(0, 2) == "//") {
            continue;
        }
        
        // Extract s, t, and expected output
        size_t pos1 = line.find("\"");
        size_t pos2 = line.find("\"", pos1 + 1);
        string s = line.substr(pos1 + 1, pos2 - pos1 - 1);
        
        size_t pos3 = line.find("\"", pos2 + 1);
        size_t pos4 = line.find("\"", pos3 + 1);
        string t = line.substr(pos3 + 1, pos4 - pos3 - 1);
        
        size_t pos5 = line.find("Output : ");
        if (pos5 == string::npos) {
            cerr << "Invalid format in line: " << line << endl;
            continue;
        }
        
        string outputStr = line.substr(pos5 + 9); // Length of "Output : "
        
        // Convert outputStr to boolean
        bool expectedOutput;
        if (outputStr == "true") {
            expectedOutput = true;
        } else if (outputStr == "false") {
            expectedOutput = false;
        } else {
            cerr << "Invalid expected output in line: " << line << endl;
            continue;
        }

        bool result = areIsomorphic(s, t);
        
        if (result == expectedOutput) {
            cout << "Test Case Passed : " << testCaseNumber << ": s = " << s << ", t = " << t << " -> Output : " << boolalpha << result << endl;
        } else {
            cout << "Test Case Failed : " << testCaseNumber << ": s = " << s << ", t = " << t << " -> " << boolalpha << result << " (Expected: " << expectedOutput << ") [FAILED]" << endl;
        }
        
        testCaseNumber++;
    }
    
    infile.close();
    
    return 0;
}
