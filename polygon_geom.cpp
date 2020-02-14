// Polygon geometry functions.

bool is_square(pll &a, pll &b, pll &c, pll &d) {
    // Check distinct.
    set<pll> seta{a,b,c,d};
    if(seta.size()<4) return 0;

    vv<pll> vec(seta.begin(),seta.end());
    map<ll,ll> dist;

    rep(i,4) rep2(j,i+1,4) {
        ll a = vec[i].fi-vec[j].fi; a = a*a;
        ll b = vec[i].se-vec[j].se; b = b*b;
        dist[a+b]++;
    }

    if(dist.size()!=2) return 0;

    auto it = dist.begin(); ll c1 = it->se;
    it++; ll c2 = it->se;

    if(c1==4 && c2==2) return 1;
    return 0;
}

// Triangle utils.
ll signed_area_parallelogram(pt<ll> p1, pt<ll> p2, pt<ll> p3) { return cross(p2 - p1, p3 - p2); }

db triangle_area(pt<ll> p1, pt<ll> p2, pt<ll> p3) { return abs(signed_area_parallelogram(p1, p2, p3)) / 2.0; }

bool clockwise(pt<ll> p1, pt<ll> p2, pt<ll> p3) { return signed_area_parallelogram(p1, p2, p3) < 0; }

bool counter_clockwise(pt<ll> p1, pt<ll> p2, pt<ll> p3) { return signed_area_parallelogram(p1, p2, p3) > 0; }


// Area of polygon.

// Using every edge and its bounded trapezium by x axis.
template <typename T>
db area(vector<pt<T>>& fig) {
    T res = 0;
    for (ll i = 0; i < fig.size(); i++) {
        auto p = i ? fig[i - 1] : fig.back();
        auto q = fig[i];
        res += (p.x-q.x)*(p.y+q.y);
    }
    return abs(res)/(db)2.0;
}


// TODO(yash): Area of polygon using triangles.

// Finding if a point lies in a polygon. O(logn) per query.
// Assumption : points of polygon are given in counterclockwise order,
// and point to be checked is translated by point[0] first.
// To find if point strictly lies inside just uncomment the commented checks.
bool lexComp(const pt<ll> & l, const pt<ll> & r){
    return l.x < r.x || (l.x == r.x && l.y < r.y);
}

int sgn(long long val){
    return val > 0 ? 1 : (val == 0 ? 0 : -1);
}

vector<pt<ll>> seq;
int n;

bool pointInTriangle(pt<ll> a, pt<ll> b, pt<ll> c, pt<ll> point){
    long long s1 = abs(cross_diff(a, b, c));
    long long s2 = abs(cross_diff(point, a, b)) + abs(cross_diff(point, b, c)) + abs(cross_diff(point, c, a));
    // if(abs(cross_diff(point, a, b)) == 0) return 0;
    return s1 == s2;
}

void prepare(vector<pt<ll>> & points){
    n = points.size();
    int pos = 0;
    for(int i = 1; i < n; i++){
        if(lexComp(points[i], points[pos]))
            pos = i;
    }
    rotate(points.begin(), points.begin() + pos, points.end());

    n--;
    seq.resize(n);
    for(int i = 0; i < n; i++)
        seq[i] = points[i + 1] - points[0];
}

bool pointInConvexPolygon(pt<ll> point){
    if(cross(seq[0], point) != 0 && sgn(cross(seq[0], point)) != sgn(cross(seq[0], seq[n - 1])))
        return false;
    if(cross(seq[n - 1], point) != 0 && sgn(cross(seq[n - 1], point)) != sgn(cross(seq[n - 1], seq[0])))
        return false;

    if(cross(seq[0], point) == 0) return false;
    if(cross(seq[n-1], point) == 0) return false;
        // return sqdist(pt<ll>(0,0), seq[0]) >= sqdist(pt<ll>(0,0), point);

    int l = 0, r = n - 1;
    while(l<r){
        int mid = (l + r)/2;
        if(cross(seq[mid], point) > 0)
            l = mid + 1;
        else r = mid;
    }
    int pos = l;
    return pointInTriangle(seq[pos], seq[pos - 1], pt<ll>(0, 0), point);
}