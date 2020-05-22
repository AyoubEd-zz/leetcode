int maxSubArray(vector<int> &nums){
	int j = -1;
	int mx = INT_MIN;
	int sum = 0;

	while(++j < nums.size()) {
		sum += nums[j];
		mx= max(mx, sum);
		if(sum<=0) sum = 0;
	}

	return mx;
}
