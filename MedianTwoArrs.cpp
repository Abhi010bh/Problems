/**
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> finalArray; 
        int l = 0, r = 0;
        double median = 0.0;
        while(l < n1 && r < n2){
            if(nums1[l] <= nums2[r]){
                finalArray.push_back(nums1[l++]);
            }
            else{
                finalArray.push_back(nums2[r++]);
            }
        }
        while(l < n1){
            finalArray.push_back(nums1[l++]);
        }
        while(r < n2){
            finalArray.push_back(nums2[r++]);
        }
        int n3 = finalArray.size();
        if(n3 % 2 != 0){
            median = finalArray[n3 / 2];
        }
        else{
            median = (finalArray[n3 / 2] + finalArray[(n3 / 2) - 1]) / 2.0;
        }

        return median;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double median = solution.findMedianSortedArrays(nums1, nums2);
    cout << "The median is: " << median << endl;

    nums1 = {1, 2};
    nums2 = {3, 4};

    median = solution.findMedianSortedArrays(nums1, nums2);
    cout << "The median is: " << median << endl;

    // Feel free to add more tests or to modify nums1 and nums2 to test different scenarios
    return 0;
}
