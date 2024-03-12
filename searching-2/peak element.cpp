class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        if(arr.size()==1 || arr[0]>arr[1]) return 0;
        if (arr[arr.size()-1]>arr[arr.size()-2]) return arr.size()-1;
        int lo = 1;
        int hi = arr.size()-2;
        while(lo<=hi) {
            int mid = (lo+hi)/2;
            if (arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
            else if(arr[mid]<arr[mid+1]) lo=mid+1;
            else if(arr[mid]<arr[mid-1]) hi=mid-1;
        }
        return -1;
    }
};