class Solution {
public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		vector<double> res;
		multiset<double> ms(nums.begin(), nums.begin() + k);
		for (int i = k; ; ++i) {
			auto mid = next(ms.begin(), k / 2);
			res.push_back((*mid + *prev(mid, 1 - k % 2)) / 2);
			if (i == nums.size()) return res;
			ms.insert(nums[i]);
			ms.erase(ms.lower_bound(nums[i - k]));
		}
	}
};

//leecode 480 