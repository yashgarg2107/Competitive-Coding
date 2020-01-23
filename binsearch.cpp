// Variations of Binary Search and applications.


// For problems when we apply binary search to the solution.

bool allok(ll mid, vector<ll> &A, ll m) {
    ll n = A.size();
    ll sum = 0;

    while(j<n) {
       
    }

    if(condition true)
        return 1;
    return 0;
}

// Uage for above function to find min such answer.

int main() {
	   
	ll low=1, high=n;
    
    while(low<=high) {
        ll mid = low+(high-low)/2;
        if(allok(mid,A,m))
            high = mid-1;
        else
            low = mid+1;
    }

    printf("%lld\n",low);
}


// Ceil sqrt function.
// Predicate : numbers such tha mid*mid>=x.
// Find first point where predicate is true.
ll sqroot(ll x) {
    ll low = 1, high = x;
    while(low<high) {
        ll mid = low+(high-low)/2;
        if(mid>x/mid || mid*mid>=x) 
            high = mid;
        else low = mid+1;
    }
    return low;
}

// Floor sqrt function.
// Predicate : numbers such tha mid*mid>x.
// Find last point where predicate is false.
ll sqrt(ll x) {
    ll low = 1, high = x;
    while(low<high) {

        ll mid = low+(high+1-low)/2;
        if(mid>x/mid) high = mid-1;
        else low = mid;
    }
    return low;
}