#include <bits/stdc++.h>
#define ll long long
using namespace std;

void heapify(ll a[], ll n, ll i);

void heapSort(ll a[],ll n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

void heapify(ll a[], ll n, ll i){
    ll largest = i;
    ll l = 2*i+1;
    ll r = 2*i+2;
    if(l<n && a[largest]<a[l]){
        largest=l;
    }
    if(r<n && a[largest]<a[r]){
        largest=r;
    }
    if(largest!=i){
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }
}

int main(){
    ll i,j,k,n;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    heapSort(a,n);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
