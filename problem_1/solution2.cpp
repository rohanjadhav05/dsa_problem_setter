#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <sstream>

using namespace std;

class solution2{

    public:
        bool pairWithSum(const vector<int>& arr, int sum){
            unordered_set<int> set;
            for(int i = 0; i < arr.size(); i++){
                if(set.find(arr[i]) != set.end()){
                    return true;
                }
                else{
                    set.insert(sum - arr[i]);
                }
            }
            return false;
        }
};

int main(){
    ifstream file("test.txt");
    if(!file.is_open()){
        cerr << "Unable to open test cases file." << endl;
        return 1;
    }

    solution2 sol;
    string line;
    while(getline(file, line)){
        istringstream iss(line);
        int size;
        iss >> size;

        vector<int> arr(size);
        for(int i = 0; i < size; i++){
            iss >> arr[i];
        }
        int sum;
        iss >> sum;
        
        string expectedStr;
        iss >> expectedStr;
        bool expected = (expectedStr == "true");
        bool ans = sol.pairWithSum(arr, sum);
        if(ans == expected){
            cout << "Test Case Passed " << endl;
        }else{
            cout << "Test Case Failed, Expected : " << expected << ", Output : " << ans << ")" << endl;
        }
    }
    file.close();
    return 0;
} 