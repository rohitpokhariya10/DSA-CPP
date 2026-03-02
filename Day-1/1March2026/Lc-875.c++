//Koko Eating Bananas

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long helper(vector<int>& piles, int m) {
        long long totalHours = 0;

        for (int i = 0; i < piles.size(); i++) {
            // ceil formula
            totalHours += (piles[i] + m - 1) / m;
        }

        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int s = 1;
        int e = *max_element(piles.begin(), piles.end());

        while (s <= e) {

            int mid = s + (e - s) / 2;

            long long reqTime = helper(piles, mid);

            if (reqTime > h) {
                s = mid + 1;   // need bigger speed
            }
            else {
                e = mid - 1;   // try smaller speed
            }
        }

        return s;
    }
};

int main() {

    Solution obj;

    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    int result = obj.minEatingSpeed(piles, h);

    cout << "Minimum Eating Speed: " << result << endl;

    return 0;
}