#include <iostream>
#include <vector>
#include <climits>

using namespace std;

pair<int,vector<int>> calc_length_subarr(int target, vector<int>&nums)
{
    int min_length = INT_MAX;
    int window_sum = 0;
    int left = 0;
    int right = 0;
    int start_idx = 0;
    int n = nums.size();

    // iterate through the array
    for(right = 0 ; right < n ; right ++ )
    {
        window_sum += nums[right];
        while(window_sum >= target)
        {
            int current_length = right - left + 1;
            if (current_length < min_length)
            {
                min_length = current_length;
                start_idx = left;
            }
            window_sum -= nums[left];
            left++;       
        }
    }

    if(min_length == INT_MAX)
    {
        return {0, {0}};
    }   
    vector<int> min_subarr(nums.begin() + start_idx, nums.begin() + start_idx + min_length);
    return {min_length, min_subarr};
}


int main()
{
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    auto result = calc_length_subarr(target, nums);
    if(result.first == 0)
    {
        cout << "Length: 0, No valid subarray" << endl;
    }
    else
    {
        cout << "Length: " << result.first << ", Subarray: ";
        for(int num : result.second)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}