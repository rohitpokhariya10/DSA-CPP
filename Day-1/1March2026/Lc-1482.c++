//1482. Minimum Number of Days to Make m Bouquets
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool helper(vector<int>& bloomDay, int randomDay, int m, int k) {
        int bouquet = 0;
        int count = 0;

        for (int i = 0; i < bloomDay.size(); i++) {

            if (bloomDay[i] <= randomDay) {
                count++;

                if (count == k) {
                    bouquet++;
                    count = 0;
                }
            } 
            else {
                count = 0;   // adjacency break
            }

            if (bouquet >= m) return true;
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        if ((long long)m * k > bloomDay.size())
            return -1;

        int s = 1;
        int e = *max_element(bloomDay.begin(), bloomDay.end());

        while (s <= e) {

            int mid = s + (e - s) / 2;

            if (helper(bloomDay, mid, m, k)) {
                e = mid - 1;
            } 
            else {
                s = mid + 1;
            }
        }

        return s;
    }
};

int main() {

    Solution obj;

    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;

    int result = obj.minDays(bloomDay, m, k);

    cout << "Minimum days required: " << result << endl;

    return 0;
}