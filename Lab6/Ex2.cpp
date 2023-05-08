class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;

        vector<pair<int,int>> temp;
        for(auto it:mp)
            temp.push_back({it.second,it.first});

        sort(temp.rbegin(),temp.rend());
        for(int i=0;i<k;i++)
            ans.push_back(temp[i].second);

        return ans;
    } };
