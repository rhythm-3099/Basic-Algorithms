// WOOF!!
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
#define ll long long
#define ld long double

// given different testcases, l & r, find all the prime numbers between l & r including them

// simple sieve
vector<int> sieve(){
	bool isPrime[MAX_NUM];
	memset(isPrime,true,sizeof(isPrime));
	isPrime[0]=false;
	isPrime[1]=false;
	for(int i=2;i*i<=MAX_NUM;i++){
		if(isPrime[i]){
			for(int j=i*i;j<=MAX_NUM;j+=i){
				isPrime[j]=false;
			}
		}
	}
	vector<int>primes;
	for(int i=2;i<MAX_NUM;i++){
		if(isPrime[i]){
			primes.push_back(i);
		}
	}
	return primes;
}

// main function for the segmented sieve
void printPrimes(ll l, ll r, vector<int>primes){
	bool isPrime[r-l+1];
	memset(isPrime,true,sizeof(isPrime));
	for(ll i=0;primes[i]*primes[i]<=r;i++){
		ll currPrime = primes[i];

		// just smaller or equal value to l
		ll base = (l/currPrime)*currPrime;
		if(base<currPrime){
			base+=currPrime;
		}

		// mark all multiples within L to R as false
		for(ll j=base;j<=r;j+=currPrime){
			isPrime[j-l]=false;
		}

		// There maybe a case where base is itself a prime number
		if(base==currPrime){
			isPrime[base-l]=true;
		}
	}

	for(ll i=0;i<=r-l;i++){
		if(isPrime[i]){
			cout<<i+l<<endl;
		}
	}
}

int main(){
    FAST;
    ll i,j,k,n,m,t;
    vector<int>primes = sieve();
    cin>>t;
    while(t--){
    	ll l,r;
    	cin>>l>>r;
    	printPrimes(l,r,primes);
    }
    return 0;
}