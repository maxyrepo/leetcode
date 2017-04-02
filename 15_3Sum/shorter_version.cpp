vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    for (auto i = 0; i < nums.size();) {
        auto target = -nums[i];
        int l = i + 1, u = nums.size() - 1;

        while (l < u) {
            auto sum = nums[l] + nums[u];

            if (sum < target)
                while (nums[++l] == nums[l - 1]);  // Processing duplicates of Number 2
            else if (sum > target)
                while (nums[--u] == nums[u + 1]);  // Processing duplicates of Number 3
            else {
                result.push_back(vector<int>{nums[i], nums[l], nums[u]});
                while (nums[++l] == nums[l - 1]);  // Processing duplicates of Number 2
                while (nums[--u] == nums[u + 1]);  // Processing duplicates of Number 3
            } 

        }

        // Processing duplicates of Number 1
        while (nums[++i] == nums[i - 1]);
    }

    return result;
}
