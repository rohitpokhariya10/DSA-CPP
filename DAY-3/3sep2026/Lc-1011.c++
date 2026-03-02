#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
using namespace std;

class Solution {
public:

    int helper(vector<int>& weights, int m){
        int sum = 0;
        int day = 1;

        for(int i = 0; i < weights.size(); i++){
            if(sum + weights[i] <= m){
                sum += weights[i];
            }
            else{
                day++;
                sum = weights[i];
            }
        }

        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int s = *max_element(weights.begin(), weights.end());
        int e = accumulate(weights.begin(), weights.end(), 0);
        int ans = e;

        while(s <= e){
            int m = (s + e) / 2;

            int minimumDay = helper(weights, m);

            if(minimumDay <= days){
                ans = m;
                e = m - 1;
            }
            else{
                s = m + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> weights = {1,2,3,4,5};
    int days = 3;

    cout << obj.shipWithinDays(weights, days);
    return 0;
}