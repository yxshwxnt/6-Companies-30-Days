// Rotate Function 
// Problem Link: https://leetcode.com/problems/rotate-function/description/ 


class Solution {
public: 
//sorting wont work coz we have to rotate it 
    int maxRotateFunction(vector<int>& nums) {
        int sum=0,original=0;  
        int n=nums.size(); 
        for(int i=0;i<n;i++){
            sum+=nums[i];     //sum of nums 
            original+=(i*nums[i]); //F(0)
        } 
        int mx=original; 
        //simple tabulation || DP 
        for(int i=n-1;i>=0;i--){   
            original += sum - (nums[i]*n);   //rotation hora hai, n[i] will be last elem evry time
            mx=max(mx,original); 
        }
        return mx; 
    }
};