// return the count of the number of intervals to be removed so that all the intervals become non-overlapping
ll eraseOverlappingIntervals(vector<pair<ll,ll> >a){
    ll i,j,k,n=a.size();
    sort(a.begin(),a.end());
    ll count=0;
    ll left=0,right=1;
    while(right<n){
        if(a[left].second <= a[right].first){
            left=right;
            right++;
        } else if(a[left].second <= a[right].second){
            count++;
            right++;
        } else if(a[left].second > a[right].second){
            count++;
            left = right;
            right++;
        }
    }
    return count;
}