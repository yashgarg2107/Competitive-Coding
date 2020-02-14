// Implementation of algorithm for finding two closest pair of points.

// Implementation when dist computation are done with squares of euclidean dist.
struct pt {
    ll x, y, id;
};

struct cmp_x {
    bool operator()(const pt & a, const pt & b) const {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
};

struct cmp_y {
    bool operator()(const pt & a, const pt & b) const {
        return a.y < b.y;
    }
};

ll n;
vector<pt> a;

ll mindist;
pair<ll, ll> best_pair;

void upd_ans(const pt & a, const pt & b) {
    ll dist = ((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    if (dist < mindist) {
        mindist = dist;
        best_pair = {a.id, b.id};
    }
}

vector<pt> t;

void rec(ll l, ll r) {
    if (r - l <= 3) {
        for (ll i = l; i < r; ++i) {
            for (ll j = i + 1; j < r; ++j) {
                upd_ans(a[i], a[j]);
            }
        }
        sort(a.begin() + l, a.begin() + r, cmp_y());
        return;
    }

    ll m = (l + r) >> 1;
    ll midx = a[m].x;
    rec(l, m);
    rec(m, r);

    merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r, t.begin(), cmp_y());
    copy(t.begin(), t.begin() + r - l, a.begin() + l);

    ll tsz = 0;
    for (ll i = l; i < r; ++i) {
        if (abs((a[i].x - midx)*(a[i].x - midx)) < mindist) {
            for (ll j = tsz - 1; j >= 0 && (a[i].y - t[j].y)*(a[i].y - t[j].y) < mindist; --j)
                upd_ans(a[i], t[j]);
            t[tsz++] = a[i];
        }
    }
}

// Usage in main function :
// t.resize(n);
// sort(a.begin(), a.end(), cmp_x());
// mindist = INF;
// rec(0, n);


// Implementation when dist computation are done with simply euclidean dist.
struct pt {
    ll x, y, id;
};

struct cmp_x {
    bool operator()(const pt & a, const pt & b) const {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
};

struct cmp_y {
    bool operator()(const pt & a, const pt & b) const {
        return a.y < b.y;
    }
};

ll n;
vector<pt> a;

db mindist;
pair<ll, ll> best_pair;

void upd_ans(const pt & a, const pt & b) {
    db dist = sqrtl((db)((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)));
    if (dist < mindist) {
        mindist = dist;
        best_pair = {a.id, b.id};
    }
}

vector<pt> t;
void rec(ll l, ll r) {
    if (r - l <= 3) {
        for (ll i = l; i < r; ++i) {
            for (ll j = i + 1; j < r; ++j) {
                upd_ans(a[i], a[j]);
            }
        }
        sort(a.begin() + l, a.begin() + r, cmp_y());
        return;
    }

    ll m = (l + r) >> 1;
    ll midx = a[m].x;
    rec(l, m);
    rec(m, r);

    merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r, t.begin(), cmp_y());
    copy(t.begin(), t.begin() + r - l, a.begin() + l);

    ll tsz = 0;
    for (ll i = l; i < r; ++i) {
        if (abs(a[i].x - midx) < mindist) {
            for (ll j = tsz - 1; j >= 0 && (a[i].y - t[j].y) < mindist; --j)
                upd_ans(a[i], t[j]);
            t[tsz++] = a[i];
        }
    }
}