// https://practice.geeksforgeeks.org/problems/combination-sum-part-2/0
// Given an array of integers A and a sum B, find all unique combinations in A where the sum is equal to B.

// Each number in A may only be used once in the combination.

#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<ll> >ans;
vector<ll>a;
vector<ll>curr;

void rec(ll target, ll index){
    ll n=a.size();
    if(target==0){
        ans.push_back(curr);
        return;
    }
    if(target<0){
        return;
    }
    for(int i=index;i<a.size();i++){
        if(i==index || a[i]!=a[i-1]){
            curr.push_back(a[i]);
            rec(target-a[i],i+1);
            curr.pop_back();
        }
    }
}


int main() {
    ll i,j,k,n,m,t;
    cin>>t;
    while(t--){
        cin>>n;
        a.clear();
        for(i=0;i<n;i++){
            cin>>k;
            a.push_back(k);
        }
            
        sort(a.begin(),a.end());
        ans.clear();
        ll target;
        cin>>target;
        rec(target, 0);
        if(ans.empty()){
            cout<<"Empty\n";
            continue;
        }
        for(i=0;i<ans.size();i++){
            cout<<"(";
            for(j=0;j<ans[i].size()-1;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<ans[i][ans[i].size()-1]<<")";
        }
        cout<<endl;
    }
	return 0;
}