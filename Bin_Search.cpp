int bin_search(int to_find,int n){
    int lo=0,hi=n-1;
    while(hi-lo > 1){
        int mid= (lo+hi)/2;
        if(v[mid] < to_find){
            lo = mid+1;
        }
        else{
            hi = mid;
        }
    }
    if(v[lo] == to_find) return lo;
    else if(v[hi] == to_find) return hi;
    else return -1;
}
