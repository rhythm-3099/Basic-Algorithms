/*returns min element from stack*/
int _stack :: getMin()
{
    if(s.empty()){
        minEle=INT_MAX;
        return -1;
    }
    return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
    if(s.empty()){
        minEle = INT_MAX;
        return -1;
    }
    int t=s.top();
    int k;
    s.pop();
    if(t>=minEle){
        ;
    } else {
        k=minEle;
        minEle = 2*minEle-t;
        return k;
    }
    
    return t;
}

/*push element x into the stack*/
void _stack::push(int x)
{
    if(s.empty()){
        minEle = x;
        s.push(x);
        return;
    }
    if(x<minEle){
       s.push(2*x-minEle);
       minEle = x;
   } else {
       s.push(x);
   }
}
