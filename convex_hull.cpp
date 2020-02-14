// Implementation of convex hull using Graham scan method.

struct compare_pt {
    bool operator()(const pt<ll> &a, const pt<ll> &b) {
        return a.x < b.x || (a.x==b.x && a.y<b.y);
    }
};

bool clockwise(pt<ll> p1, pt<ll> p2, pt<ll> p3) { return cross(p2-p1, p3-p2) < 0; }
bool counter_clockwise(pt<ll> p1, pt<ll> p2, pt<ll> p3) { return cross(p2-p1, p3-p2) > 0; }

vector<pt<ll>> hull;

void convex_hull(vector<pt<ll>> &A){
    ////// Also reverse if counterclockwise order required.

    // To handle duplicates.
    set<pt<ll>, compare_pt> seta;
    for(auto i:A) seta.insert(i);

    A.clear();
    for(auto i:seta) A.pb(i);

    ll n = A.size();
    if(n==1) {hull = A; return;}
    auto a = A[0], b = A[n-1];

    vv<pt<ll>> upper, lower;
    upper.pb(a); lower.pb(a); 

    for(ll i=1;i<n;i++) {
        if(i==n-1 || clockwise(a,A[i],b)) {
            while(upper.size()>=2 && 
                  !clockwise(
                    upper[upper.size()-2],
                    upper[upper.size()-1],
                    A[i]))
                upper.pop_back();
            
            upper.pb(A[i]);
        }
        
        // No need to take the ones that lie on line between a and b.
        
        if(i==n-1 || counter_clockwise(a,A[i],b)) {
            while(lower.size()>=2 && 
                  !counter_clockwise(
                    lower[lower.size()-2],
                    lower[lower.size()-1],
                    A[i]))
                lower.pop_back();

            lower.pb(A[i]);
        }
    }

    for(ll i=0;i<upper.size();i++)
        hull.pb(upper[i]);

    for(ll i = lower.size()-2;i>=1;i--)
        hull.pb(lower[i]);
}