#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	map<int, int> the_other;
	vector<int> res(2);
	for (int i = 0; i < nums.size(); ++i) {
		int diff = target - nums[i];
		if (the_other.find(diff) != the_other.end()) {
			res[0] = i;
			res[1] = the_other[diff];
			if (res[0] > res[1]) {
				swap(res[0], res[1]);
			}
			break;
		}
		the_other[nums[i]] = i;
	}

        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 3};
    int target = 6;
    vector<int> res = s.twoSum(nums, target);
    std::cout << res[0] << "\t" << res[1] << std::endl;
    return 0;
}
