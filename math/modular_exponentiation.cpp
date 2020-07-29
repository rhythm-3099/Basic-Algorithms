int modularExponentiation(int x, int n, int m){  // to calculate x raise to n mod m
    int result=1;
    while(n>0){
        if(n%2){                                 // if n is odd, then we find x*(x raise to n/2)
            result = ((result%m)*(x%m))%m;       // if n is even, then we find ((x*x) raise to n/2)
        }
        x=(x*x)%m;
        n/=2;
    }
    return result;
}