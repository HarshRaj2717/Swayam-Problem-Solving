// Problem : https://leetcode.com/problems/search-in-rotated-sorted-array/

#include<bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target) {
    int s = 0, e = nums.size() - 1;
    int m = s + (e - s) / 2;
    while(s <= e){
        if(nums[m] == target) return m;
        if(nums[m] >= nums[s]){
            if(nums[s] <= target && target < nums[m]){
                e = m - 1;
            }
            else{
                s = m + 1;
            }
        }
        else{
            if(nums[m] < target && target <= nums[e]){
                s = m + 1;
            }
            else{
                e = m - 1;
            }
        }
        m = s + (e - s) / 2;
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int target;
    cin >> target;

    cout << search(nums, target) << endl;

    return 0;
}