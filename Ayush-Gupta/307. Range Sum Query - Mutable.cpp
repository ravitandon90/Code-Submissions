class BITTree{
	public:
	vector<int> cnt;
	BITTree(int n): cnt(n+1, 0){
	}

	void update(int i, int delt){
		while(i < cnt.size()){
			cnt[i] += delt;
			i += i & (-i);
		}
	}

	int construct(int a){
		int sum = 0;
		while (a > 0){
			sum += cnt[a];
			a -= a & (-a);
		}
		return sum;
	}
};


class NumArray {
public:
	BITTree Tree;
	vector<int> num;
	NumArray(vector<int>& nums): Tree(nums.size()){
		int n = nums.size();
		num = nums;

		for(int i = 0; i < n; i ++){
			Tree.update(i + 1, num[i]);
		}
	}

	void update(int i, int val) {
		Tree.update(i + 1, val - num[i]);
		num[i] = val;
	}

	int sumRange(int i, int j) {
		return Tree.construct(j + 1) - Tree.construct(i);
	}
};