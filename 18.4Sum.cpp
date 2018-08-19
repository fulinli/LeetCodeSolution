// debug 屡次失败，最后发现是由于在判断nums[l]==nums[l+1]时越界，加上l+1!=n这条限制后通过
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int a;
        int val;
        vector<int> t(4);
        int n = nums.size();
        a = target;
        if(n < 4){
            return res;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i++){
            //cout<<"i = "<<i<<endl;
            for(int j = i + 1; j < n - 2; j++){
                //cout<<"j = "<<j<<endl;
                for(int k = j + 1; k < n - 1; k++){
                    //cout<<"k = "<<k<<endl;
                    int l = k + 1;
                    //cout<<"l = "<<l<<endl;
                    while(l < n)
                    {
                        
                        val = nums[i] + nums[j] + nums[k] + nums[l];
                        if(l+1 != n && nums[l]==nums[l+1]){
                            l++;
                        
                            continue;
                        }
                        if(nums[k]==nums[k+1] && k+1 != l){
                            k++;
                           
                            continue;
                        }
                        if(nums[j]==nums[j+1] && j+1 != k){
                            j++;
                          
                            continue;
                        }
                        if(nums[i]==nums[i+1] && i+1 != j){
                            i++;
                       
                            continue;
                        }
                        if(val == a){
                            t[0] = nums[i];
                            t[1] = nums[j];
                            t[2] = nums[k];
                            t[3] = nums[l];
                            cout<<"t = "<<t[0]<<t[1]<<t[2]<<t[3]<<endl;
                            res.push_back(t);
                        }
                        l++;
                    }
                }
            }
        }
        return res;
    }
};