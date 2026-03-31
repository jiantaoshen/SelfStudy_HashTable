#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> TwoSum(vector<int> &nums, int target) 
{
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (hash.find(complement) != hash.end()) {
            return {hash[complement], i};
        }
        hash[nums[i]] = i;
    }
    // Return an empty vector if no solution is found
    return {};
}

int main()
{
    vector<int> nums = {3, 9, 4, 6, 1};
    int target = 6;

    vector<int> result = TwoSum(nums, target);

    if (!result.empty()) cout << "[" << result[0] << "," << result[1] << "]";
    else cout << "No answer.";
}


