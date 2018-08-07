class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res, val, temp, diff;
        int n = nums.size();
        
        if(n < 3){
            return 0;
        }
        res = nums[0] + nums[1] + nums[2];
        diff = abs(res - target);
        for(int i = 0; i < n - 2; i++){
            for(int j = i + 1; j < n - 1; j++){
                for(int k = j + 1; k < n; k++){
                    val = nums[i] + nums[j] + nums[k];
                    temp = abs(val - target);
                    if(temp < diff){
                        diff = temp;
                        res = val;
                    }
                }
            }
        }
        return res;
    }
};