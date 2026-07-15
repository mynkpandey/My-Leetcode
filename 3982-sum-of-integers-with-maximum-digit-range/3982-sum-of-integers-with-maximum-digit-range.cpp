class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int> range(nums.size());
        int best = -1;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            if (x == 0) {
                range[i] = 0;
            } else {
                int mn = 9, mx = 0;
                while (x) {
                    int d = x % 10;
                    mn = min(mn, d);
                    mx = max(mx, d);
                    x /= 10;
                }
                range[i] = mx - mn;
            }

            best = max(best, range[i]);
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            if (range[i] == best)
                sum += nums[i];

        return sum;
    }
};