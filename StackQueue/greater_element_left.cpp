#include<bits/stdc++.h>
#define ll long long
using namespace std;

void next_greater(vector<ll>a, int n){
    ll i,j,k;
    stack<int>s;
    vector<ll>ans;
    for(i=n-1;i>=0;i--){
        if(s.empty())
            ans.push_back(-1);
        else if(!s.empty() && s.top()>a[i])
            ans.push_back(s.top()); 
        else if(!s.empty() && s.top()<=a[i]){
            while(!s.empty() && s.top()<=a[i]){
                s.pop();
            }
            if(s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top());
        }
        s.push(a[i]);
    }
    reverse(ans.begin(),ans.end());
    for(i=0;i<n;i++)
        cout<<ans[i]<<" ";
}

int main(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    next_greater(a,n);
    return 0;
}