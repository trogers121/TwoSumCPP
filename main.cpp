#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>

using namespace std;




vector<int> twoSum(vector<int>& nums, int target);

int main(){

    vector<int> testArray = {2,7,11,15, 16, 1, -6, 32};
    int target = 18;
    vector<int> solution;
    try{
    solution = twoSum(testArray, target);
    }
    catch(exception e){
        cout << "Exception caught" << endl;
    }
    cout << "Solution --> [ " << solution[0] << ", " << solution[1] << "]" << endl;

    return 0;
}
/*
 * Helper Functions 
 */

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> indices;
    vector<int>::iterator it;
    unordered_map<int, int> lookUpTable;
    //Check if vector is empty
    if(!nums.empty()){
        for(int i = 0; i < nums.size(); i++){
            int addend = target - nums[i];
            
            unordered_map<int,int>::const_iterator indexOfAddend = lookUpTable.find(addend);
            // cout << "Index = " << indexOfAddend;
            if(!(indexOfAddend == lookUpTable.end())){
                it = indices.begin();
                it = indices.insert(it, i);
                it = indices.insert(it, indexOfAddend->second); 
                cout << "Solution found" << endl;
                break;
            } 
            else{
                // cout << "Not found" << endl;
                // cout << nums[i] << " + " << addend << " = " << target << endl;
            }
            lookUpTable.insert({ nums[i], i });
        }
    }
    else{
        throw std::invalid_argument("Input vector is empty");
    }
    if(indices.empty()){
        throw std::invalid_argument("Solution not found");
    }

    return indices;
}

