// https://practice.geeksforgeeks.org/problems/rearrange-characters/0

//Given a string S with repeated characters (only lowercase). The task is to rearrange characters in a string such that no two adjacent characters are same.

//3
// geeksforgeeks -> 1
// bbbabaaacd    -> 1
// bbbbb         -> 0

// Logic: Maintain a max priority queue and insert pair<freq,char> into it. Remove the pair that is current and add after the next pair

#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool checker(string s){
    priority_queue<pair<ll,char> >pq;
    pair<ll,char>temp,prev;
    prev ={-1,'#'};
    ll count[26];
    memset(count,0,sizeof(count));
    for(int i=0;i<s.size();i++)
        count[s[i]-'a']++;
    for(int i=0;i<26;i++){
        if(count[i]>0){
            pq.push({count[i],'a'+i});
        }
    }
    ll n=s.size();
    s="";
    while(!pq.empty()){
        temp = pq.top();
        pq.pop();
        s+=temp.second;
        if(prev.first>0){
            pq.push(prev);
        }
        temp = {temp.first-1,temp.second};
        prev = temp;
    }
    if(n==s.size())
        return true;
    return false;
}

int main() {
    ll i,j,k,n,m,t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<checker(s)<<endl;
    }
	return 0;
}