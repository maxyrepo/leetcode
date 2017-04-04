#include <iostream>
#include <vector>

using namespace std;

void output(const vector<int> & vec) {
    for(size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << ", ";
    }
    cout << endl;
}

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
	if (nums.size() == 0) {
		return 0;
	}
        int l = 0;
	int r = 0;
	while(r < nums.size()) {
		if (nums[r] != nums[l]) {
			l++;
			nums[l] = nums[r];
		}
		r++;
	}

	return l + 1;
    }
};

int main() {
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(2);

	Solution s;
	cout << s.removeDuplicates(vec) << endl;
	output(vec);
	vector<int> vec2;
	cout << s.removeDuplicates(vec2) << endl;
	output(vec2);
}
