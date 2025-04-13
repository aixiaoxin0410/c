#include <vector>
#include <climits>
#include <iostream>

using namespace std;

pair<int, vector<int>> minSubArrayLen(int target, vector<int>& nums) {
    int minLength = INT_MAX;
    int windowSum = 0;
    int left = 0;
    int startIdx = 0;
    int n = nums.size();

    for (int right = 0; right < n; right++) {
        windowSum += nums[right];

        while (windowSum >= target) {
            int currentLength = right - left + 1;
            if (currentLength < minLength) {
                minLength = currentLength;
                startIdx = left;
            }
            windowSum -= nums[left];
            left++;
        }
    }

    if (minLength == INT_MAX) {
        return {0, {0}}; // 没有解时返回 {0, {0}}
    }
    vector<int> minSubarray(nums.begin() + startIdx, nums.begin() + startIdx + minLength);
    return {minLength, minSubarray};
}

int main() {
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    int target1 = 7;
    auto result1 = minSubArrayLen(target1, nums1);
    if (result1.first == 0) {
        cout << "Length: 0, No valid subarray" << endl;
    } else {
        cout << "Length: " << result1.first << ", Subarray: ";
        for (int num : result1.second) {
            cout << num << " ";
        }
        cout << endl;
    }

    vector<int> nums2 = {1, 1, 1, 1, 1, 1};
    int target2 = 11;
    auto result2 = minSubArrayLen(target2, nums2);
    if (result2.first == 0) {
        cout << "Length: 0, No valid subarray" << endl;
    } else {
        cout << "Length: " << result2.first << ", Subarray: ";
        for (int num : result2.second) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}