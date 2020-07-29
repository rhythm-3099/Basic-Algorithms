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

struct MinHeap {
	int *harr;
	int capacity, heap_size;
	MinHeap(int cap) {
		heap_size=0;
		capacity = cap;
		harr = new int[cap];
	}
	int extractMin();
	void deleteKey(int i);
	void insertKey(int k);
	int parent(int i);
	int left(int i);
	int right(int i);
	void minHipify();
};

int MinHeap::parent(int i){
	return (i-1)/2;
}

int MinHeap::left(int i){
	return 2*i+1;
}

int MinHeap::right(int i){
	return 2*i+2;
}

int MinHeap::extractMin(){
	if(heap_size==0){
		return INT_MIN;
	}
	if(heap_size==1){
		heap_size--;
		return harr[0];
	}

	int root=harr[0];
	harr[0]=harr[heap_size-1];
	heap_size--;
	minHipify(0);
	return root;
}

void MinHeap::insertKey(int k){
	int i = heap_size;
	heap_size++;
	harr[i]=k;
	while(i>0 && harr[parent(i)]>harr[i]){
		swap(&harr[i], &harr[parent[i]]);
		i=parent(i);
	}
}

void MinHeap::minHipify(int i){
	int lf = left(i);
	int rt = right(i);
	int smallest = i;
	if(l<heap_size && harr[l] < harr[i]) smallest = l;
	if(r<heap_size && harr[r] < harr[i]) smallest = r;
	if(smallest!=i){
		swap(harr[i],harr[smallest]);
		minHipify(smallest);
	}
}

void MinHeap::decreaseKey(int i, int new_val){
	harr[i]=new_val;
	while(i>0 && harr[parent(i)] > harr[i]){
		swap(harr[i],harr[parent(i)]);
		i=parent(i);
	}
}

void deleteKey(ll i){
    decreaseKey(i,INT_MIN);
    extractMin();
}



int main()
{
    FAST;
    ll i,j,k,n,m,t;
    str s;
    
    
    return 0;
}