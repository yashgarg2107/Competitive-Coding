// Line geometry functions.

template <typename T>
struct line {
    T a, b, c;
    line() {}
    line(T a, T b, T c): a(a), b(b), c(c) {}
};

// Equation of line passing through 2 points. 
// P and Q should not be equal.
line<ll> find_line(point2d<ll> P, point2d<ll> Q) {
    ll A = P.y - Q.y;
    ll B = Q.x - P.x;
    ll C = -A*P.x - B*P.y;

    // Normalize wrt value and sign.
    ll g = __gcd(abs(A), __gcd(abs(B), abs(C)));
    assert(g!=0);
    A /= g, B /= g, C/=g;
    
    if(A<0 || (A==0 && B<0)) {
        A *= -1, B *= -1, C *= -1;
    }
    return line<ll> (A,B,C);
}

template <typename T, typename U>
db line_dist(line<T> l, pt<U> p) {
    return abs(l.a*p.x + l.b*p.y + l.c)/sqrtl((db)(l.a*l.a + l.b*l.b));
}

line<db> line_conv(line<ll> l) {
	return line<db>(l.a, l.b, l.c);
}

template <typename T>
vector<T> line_to_vec(line<T> &l) {
    return vector<T> {l.a, l.b, l.c};
}

template <typename T>
line<T> vec_to_line(vector<T> &l) {
    return line<T> {l[0], l[1], l[2]};
}

// TODO(yash): Line segment for doubles and its normalization.

// Compare struct for line key.
struct Compare {
    bool operator()(const line<ll> &l1, const line<ll> &l2) {
        if(l1.a<l2.a) return 1;
        if(l1.a==l2.a && l1.b<l2.b) return 1;
        if(l1.a==l2.a && l1.b==l2.b && l1.c<l2.c) return 1;
        return 0;
    }
};

// Finding the intersection of two lines.

template <typename T>
ll sgn(const T& x) { return x >= 0 ? (x ? 1 : 0) : -1; }

template <typename T> 
T det(T a, T b, T c, T d) { return a*d - b*c; }

template <typename T> 
bool intersect(line<T> m, line<T> n, point2d<db> &res) {
    T zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < EPS)
        return false;
    res.x = -det(m.c, m.b, n.c, n.b) / (db)zn;
    res.y = -det(m.a, m.c, n.a, n.c) / (db)zn;
    return true;
}

template <typename T>
bool parallel(line<T> m, line<T> n) { return abs(det(m.a, m.b, n.a, n.b)) < EPS; }

template <typename T>
bool equivalent(line<T> m, line<T> n) {
    return abs(det(m.a, m.b, n.a, n.b)) < EPS
        && abs(det(m.a, m.c, n.a, n.c)) < EPS
        && abs(det(m.b, m.c, n.b, n.c)) < EPS;
}

// Find if two line segments defined by integer points intersect.
bool inter1(ll a, ll b, ll c, ll d) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    return max(a, c) <= min(b, d);
}

bool check_inter(const pt<ll>& a, const pt<ll>& b, const pt<ll>& c, const pt<ll>& d) {
    if (cross_diff(c, a, d) == 0 && cross_diff(c, b, d) == 0)
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);

    return sgn(cross_diff(a,b,c)) != sgn(cross_diff(a,b,d)) &&
           sgn(cross_diff(c,d,a)) != sgn(cross_diff(c,d,b));
}


// Length of union of segments.

ll length_union(const vector<pair<ll, ll>> &a) {
    ll n = a.size();
    vector<pair<ll, bool>> x(n*2);
    for (ll i = 0; i < n; i++) {
        x[i*2] = {a[i].first, false};
        x[i*2+1] = {a[i].second, true};
    }

    sort(x.begin(), x.end());

    ll result = 0;
    ll c = 0;
    for (ll i = 0; i < n * 2; i++) {
        if (i > 0 && x[i].first > x[i-1].first && c > 0)
            result += x[i].first - x[i-1].first;
        if (x[i].second)
            c--;
        else
            c++;
    }
    return result;
}