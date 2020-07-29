#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll i,j,k,n,m,t;
    cin>>t;
    while(t--){
        cin>>n>>k; 
        vector<ll>a(n);
        deque<ll>dq;
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        for(i=0;i<k;i++){
            while(!dq.empty() && a[i]>a[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(i=k;i<n;i++){
            cout<<a[dq.front()]<<" ";
            if(i-dq.front()==k){
                dq.pop_front();
            }
            while(!dq.empty() && a[i]>a[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        cout<<a[dq.front()]<<endl;
    }
	return 0;
}