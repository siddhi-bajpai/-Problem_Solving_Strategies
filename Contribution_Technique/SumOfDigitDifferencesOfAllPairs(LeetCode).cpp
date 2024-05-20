#include<bits/stdc++.h>
using namespace std;
//Question Link:https://leetcode.com/problems/sum-of-digit-differences-of-all-pairs/description/

// Solution :
class Solution {
public:
    //Using contribution technique.
    long long sumDigitDifferences(vector<int>& nums) {
        vector<string> num;
        for(auto it:nums){
            num.push_back(to_string(it));
        }
        int n=nums.size();
        int len=num[0].length();

        long long ans=0;
        
        for(int i=0;i<len;i++){
            //Frequecy vector to store the frequencies of eaach digit(0-9) for that index of all the strings in the vector
            vector<int> freq(10,0);
            for(auto v:num){
                freq[v[i]-'0']++;
            }
            long long contribution=0;
            for(int j=0;j<10;j++){
                contribution+=freq[j]*(n-freq[j]);
            }
            contribution/=2;
            ans+=contribution;
        }
        return ans;
    }
};