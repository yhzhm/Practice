// Created by Hz Yang on 2019.01
class Solution {
public:
	vector<int> specialsort(int N) {
		vector<int> res;
		res.push_back(1);
		for (int i = 2; i <= N; ++i) {
			int l = 0, r = res.size() - 1;
			while (l < r) {
				int mid = l + r + 1 >> 1;
				if (compare(res[mid], i)) l = mid;
				else r = mid - 1;
			}
			res.push_back(i);
			for (int j = res.size() - 2; j > r; j--) swap(res[j], res[j + 1]);
			if (compare(i, res[r])) swap(res[r], res[r + 1]);
		}
		return res;
	}
};

/*
二分找插入位置


 */