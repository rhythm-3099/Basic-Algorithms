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

void merge(int arr[], int l, int m, int r){
	int i,j,k;
	int n1 = m-l+1;	// size of the left array
	int n2 = r-m;	// size of the right array

	int L[n1],R[n2];
	
	// Copying the values from the original array to the temporary arrays
	for(i=0;i<n1;i++)
		L[i] = arr[l+i];

	for(i=0;i<n2;i++)
		R[i] = arr[m+1+i];

	i=0,j=0,k=l;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		} else {
			arr[k]=R[j];
			j++;
		}
		k++;
	}

	// Copying the remaining values to the original array
	while(i<n1){
		arr[k]=L[i];
		i++,k++;
	}

	while(j<n2){
		arr[k]=R[j];
		j++,k++;
	}

}

void partition(int arr[], int l, int r){
	if(r>l){
		int m = l+(r-l)/2;
		partition(arr,l,m);
		partition(arr,m+1,r);
		merge(arr,l,m,r);
	}
}



int main()
{
    FAST;
    ll i,j,k,n,m,t;
    str s;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    	cin>>a[i];
   	partition(a,0,n-1);
   	for(i=0;i<n;i++)
   		cout<<a[i]<<" ";
   	cout<<endl;
    
    return 0;
}