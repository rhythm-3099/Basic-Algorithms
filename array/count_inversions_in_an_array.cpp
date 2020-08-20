// WOOF!!
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define str string
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FILL(a,b) memset((a),(b),sizeof((a)))
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define minQueue priority_queue<ll,vector<ll>,greater<ll> > 
#define maxQueue priority_queue<ll,vector<ll>,less<ll> > 
#define deb1(x) cout<<#x<<" : "<<x<<endl;
#define deb2(x,y) cout<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl;
#define deb3(x,y,z) cout<<#x<<" : "<<x<<"   "<<#y<<" : "<<y<<"  "<<#z<<" : "<<z<<endl;
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define READ freopen("input.txt","r",stdin);
#define WRITE freopen("output.txt","w",stdout);
#define RANDOM srand(time(NULL));
#define MOD 1000000007
#define NAX 1000005
#define INF LONG_LONG_MAX
#define MINF LONG_LONG_MIN

/*
	Given the array, find the number of inversions in the array.
*/
ll inversionCount;
void merge(ll a[], ll l, ll m, ll r){
    ll i,j,k;
    ll n1=m-l+1;
    ll n2=r-m;
    
    ll L[n1],R[n2];
    for(i=0;i<n1;i++)
        L[i]=a[l+i];
    for(i=0;i<n2;i++)
        R[i]=a[m+1+i];
        
    i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            a[k]=L[i];
            i++;
        } else {
            a[k]=R[j];
            ll x = n1-(upper_bound(L,L+n1,R[j])-L);
            inversionCount+=x;
            j++;
        }
        k++;
    }
    
    while(i<n1){
        a[k]=L[i];
        i++,k++;
    }
    
    while(j<n2){
        a[k]=R[j];
        j++,k++;
    }
}

void merge_sort(ll a[], ll lo, ll hi){
	//ll inversionCount=0;
	if(lo<hi){
		ll mid=lo+(hi-lo)/2;
		merge_sort(a,lo,mid);
		merge_sort(a,mid+1,hi);
		merge(a,lo,mid,hi);
	}
	//return inversionCount;
}


int main()
{
    FAST;
    ll i,j,k,n,m,t,x;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++){
    	cin>>a[i];;
    }
    inversionCount=0;
   	merge_sort(a,0,n-1);
   	for(i=0;i<n;i++)
   		cout<<a[i]<<" ";
   	cout<<inversionCount<<endl;
    return 0;
}