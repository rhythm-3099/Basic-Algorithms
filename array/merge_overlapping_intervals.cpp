// given a vector of intervals, merge the overlapping intervals
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> >ans;
        sort(intervals.begin(), intervals.end());
        if(intervals.size()==0){
            return ans;
        }
        int i,j,k,n=intervals.size(),left,right;
        left=0,right=1;
        while(right<n){
            if(intervals[left][1]<intervals[right][0]){
                vector<int> temp;
                temp.push_back(intervals[left][0]);
                temp.push_back(intervals[left][1]);
                ans.push_back(temp);
                left=right;
                right++;
            } else if(intervals[left][0]<=intervals[right][0] && intervals[left][1]>=intervals[right][1]){
                right++;
            } else if(intervals[left][0]<=intervals[right][0] && intervals[left][1]<=intervals[right][1]){
                intervals[left][1]=intervals[right][1];
                right++;
            }
        }
        vector<int>temp;
        temp.push_back(intervals[left][0]);
        temp.push_back(intervals[left][1]);
        ans.push_back(temp);
        return ans;
    }
};