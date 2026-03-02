#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:

    /*
        Helper Function:
        Given a divisor 'm', calculate the total sum after dividing
        each element by 'm' and taking ceiling value.

        Example:
        nums = [1,2,5], m = 2

        ceil(1/2) = 1
        ceil(2/2) = 1
        ceil(5/2) = 3

        total = 1 + 1 + 3 = 5
    */
    int helper(vector<int>& nums, int m) {
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {

            // Ceiling division formula:
            // ceil(a / b) = (a + b - 1) / b
            sum += (nums[i] + m - 1) / m;
        }

        return sum;
    }


    /*
        Main Function:
        We need to find the smallest divisor such that:

        sum( ceil(nums[i] / divisor) ) <= threshold

        This is a Binary Search on Answer problem.
    */
    int smallestDivisor(vector<int>& nums, int threshold) {

        // Minimum possible divisor = 1
        int s = 1;

        // Maximum possible divisor = max element in array
        int e = *max_element(nums.begin(), nums.end());

        int ans = e;   // worst case answer

        while(s <= e) {

            // Mid is current divisor we are testing
            int m = (s + e) / 2;

            // Calculate sum using this divisor
            int possibleSum = helper(nums, m);

            if(possibleSum <= threshold) {
                // Valid divisor found
                // Try to find smaller one
                ans = m;
                e = m - 1;
            }
            else {
                // Sum too large, need bigger divisor
                s = m + 1;
            }
        }

        return ans;
    }
};


int main() {
    Solution obj;

    vector<int> nums = {1,2,5,9};
    int threshold = 6;

    cout << "Smallest Divisor: "
         << obj.smallestDivisor(nums, threshold);

    return 0;
}