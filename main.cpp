#include <iostream>
#include <vector>

using namespace std;




vector<int> twoSum(vector<int>& nums, int target);

int main(){

    vector<int> testArray = {2,7,11,15, 16, 3, -6, 32, 1, 17};
    int target = -3;
    vector<int> solution;

    solution = twoSum(testArray, target);

    cout << "Solution --> [ " << solution[0] << ", " << solution[1] << "]" << endl;

    return 0;
}
/*
 * Helper Functions 
 */

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> indices = {-1, -1};
    
    if(!nums.empty()){
        
        //Numbers for finding solution
        int numOne;
        int numTwo = NULL;

        //Indices
        int i;
        int j;
        //Starting with the 0th value in vector, compare the addition of each other value to the target value
        for(i = 0; i < (nums.size() - 1); i++){
            
            numOne = nums[i];
            for(j = i + 1; j<nums.size(); j++){
                //Adds two vals together, and compares to target.
                int sum = numOne + nums[j];
                cout << "Sum of " << numOne << " + " << nums[j] << " = " << sum << endl;
                if( (sum) == target){
                    numTwo = nums[j];
                    break;
                }
                
            }
            
            if(numTwo != NULL){     //Only one solution is needed --> Will need to update the output type if more solutions are wanted
                indices[0] = i;
                indices[1] = j;
                break;
            }
        }
    }
    else{
        
    }
    return indices;
}

