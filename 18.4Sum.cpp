class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int val;
        vector<int> t;
        int n = nums.size();
        if(n < 4){
            return vector<vector<int>>;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i++){
            for(int j = i + 1; j < n - 2; j++){
                for(int k = j + 1; k < n - 1; k++){
                    for(int l = k + 1; l < n; l++){
                        val = nums[i] + nums[j] + nums[k] + nums[l];
                        if(nums[l]==nums[l+1]){
                            l++;
                            continue;
                        }
                        if(nums[k]==nums[k+1]){
                            k++;
                            continue;
                        }
                        if(nums[j]==nums[j+1]){
                            j++;
                            continue;
                        }
                        if(nums[i]==nums[i+1]){
                            i++;
                            continue;
                        }
                        if(val == target){
                            t.push_back(nums[i]);
                            t.push_back(nums[j]);
                            t.push_back(nums[k]);
                            t.push_back(nums[l]);
                            res.push_back(t);
                        }
                        t.clear();
                    }
                }
            }
        }
        return res;
    }
};