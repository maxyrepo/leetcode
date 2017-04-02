#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int cur_max_container = (r - l)* (height[l] < height[r] ? height[l] : height[r]);
    
        while (l < r) {
            if (height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
    
            int cur_container_size = (r - l)* (height[l] < height[r] ? height[l] : height[r]);
            if (cur_container_size > cur_max_container) {
                cur_max_container = cur_container_size;
            }
        }
    
        return cur_max_container;
    }
};

int main () {
    Solution s;
    vector<int> heights;
    heights.push_back(1);
    heights.push_back(2);
    cout << s.maxArea(heights) << endl;

    return 0;
}
