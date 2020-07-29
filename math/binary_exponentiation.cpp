int binaryExponentiation(int x, int n){
    int result=1;
    while(n>0){
        if(x%2){
            result=x*result;
        }
        x=x*x;
        n/=2;
    }
    return result;
}