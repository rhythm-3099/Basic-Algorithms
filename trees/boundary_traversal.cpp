// WOOF!!
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
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

struct Node {
    struct Node* left;
    struct Node* right;
    int data;
};

// print leftmost nodes top down manner, then print the leaf nodes from left to right, and finally print the rightmost nodes from bottom to top

void printBoundaryLeft(Node* root){
    if(!root)
        return;

    if(root->left){
        cout<<root->data<<" ";
        printBoundaryLeft(root->left);
    } else if(root->right){
        cout<<root->data<<" ";
        printBoundaryLeft(root->right);
    }
}

void printLeaves(Node* root){
    if(!root)
        return;
    printLeaves(root->left);
    if(!root->left && !root->right){
        cout<<root->data<<" ";
    }
    printLeaves(root->right);
}

void printBoundaryRight(Node* root){
    if(!root)
        return;

    if(root->right){
        printBoundaryRight(root->right);
        cout<<root->data<<" ";
    } else if(root->left){
        printBoundaryRight(root->left);
        cout<<root->data<<" ";
    }
}

// first call printBoundaryLeft, then call printLeaves and finally call printBoundaryRight 

