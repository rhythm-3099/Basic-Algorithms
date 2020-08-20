// given an array, find the next permutation of the array elements
class Solution {
public:
    void nextPermutation(vector<int>& A) {
        if(A.size()<=1)
            return;
        
        int i=A.size()-2;
        while(i>=0 && A[i]>=A[i+1])
            i--;
        if(i<0){
            reverse(A.begin(),A.end());
            return; 
        }
        if(i>=0){
            int j=A.size()-1;
            while(A[j] <= A[i])
                j--;
            swap(A[j],A[i]);
        }
        reverse(A.begin()+i+1, A.end());
    }
    
};