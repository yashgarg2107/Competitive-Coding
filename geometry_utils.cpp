// Basic structs and algorithms for computatinal geometry.

// 2D Geometry Functions.

#define pt point2d
template <typename T>
struct point2d {
    T x, y;
    point2d() {}
    point2d(T x, T y): x(x), y(y) {}

    point2d& operator+=(const point2d &t) { x += t.x; y += t.y; return *this; }
    point2d& operator-=(const point2d &t) { x -= t.x; y -= t.y; return *this; }
    point2d& operator*=(T t) { x *= t; y *= t; return *this; }
    point2d& operator/=(T t) { x /= t; y /= t; return *this; }

    bool operator==(const point2d &t) { return (x==t.x) && (y==t.y); }
    point2d operator+(const point2d &t) const { return point2d(*this) += t; }
    point2d operator-(const point2d &t) const { return point2d(*this) -= t; }
    point2d operator*(T t) const { return point2d(*this) *= t; }
    point2d operator/(T t) const { return point2d(*this) /= t; }
};

template <typename T>
T dot(point2d<T> a, point2d<T> b) { return a.x * b.x + a.y * b.y; }

template <typename T>
T norm(point2d<T> a) { return dot(a, a); }

template <typename T>
db abs(point2d<T> a) { return sqrt(norm(a)); }

template <typename T>
db proj(point2d<T> a, point2d<T> b) { return dot(a, b) / abs(b); }

template <typename T>
db angle(point2d<T> a, point2d<T> b) { return acos(dot(a, b) / abs(a) / abs(b)); }

template <typename T>
db angledeg(point2d<T> a, point2d<T> b) {
    db ang = acos(dot(a, b) / abs(a) / abs(b));
    ang *= 180/pi;
    if(ang>180) ang -= 360;
    return ang;
}

template <typename T>
T cross(point2d<T> a, point2d<T> b) { return a.x * b.y - a.y * b.x; }

// Gives sense(direction) of rotation b-c vector to reach a.
template <typename T>
T cross_diff(point2d<T> a, point2d<T> b, point2d<T> c) { return cross(b-a, c-a); }

template <typename T>
T sqdist(pt<T> a, pt<T> b) { return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y); }

template <typename T, typename U>
db dist(pt<T> a, pt<U> b) { return sqrtl((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)); }

bool clockwise(pt<ll> p1, pt<ll> p2, pt<ll> p3) { return cross(p2-p1, p3-p2) < 0; }
bool counter_clockwise(pt<ll> p1, pt<ll> p2, pt<ll> p3) { return cross(p2-p1, p3-p2) > 0; }

point2d<ll> db_ll_conv2d(point2d<db> P) { return point2d<ll> (P.x, P.y); }
point2d<db> ll_db_conv2d(point2d<ll> P) { return point2d<db> (P.x, P.y); }


// 3D Geometry Functions.

#define ptd point3d
template <typename T>
struct point3d {
    T x, y, z;
    point3d() {}
    point3d(T x, T y, T z): x(x), y(y), z(z) {}

    point3d& operator+=(const point3d &t) { x += t.x; y += t.y; z += t.z; return *this; }
    point3d& operator-=(const point3d &t) { x -= t.x; y -= t.y; z -= t.z; return *this; }
    point3d& operator*=(T t) { x *= t; y *= t; z *= t; return *this; }
    point3d& operator/=(T t) { x /= t; y /= t; z /= t; return *this; }

    bool operator==(const point3d &t) { return (x==t.x) && (y==t.y) && (z==t.z); }
    point3d operator+(const point3d &t) const { return point3d(*this) += t; }
    point3d operator-(const point3d &t) const { return point3d(*this) -= t; }
    point3d operator*(T t) const { return point3d(*this) *= t; }
    point3d operator/(T t) const { return point3d(*this) /= t; }
};

template <typename T>
T dot(point3d<T> a, point3d<T> b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

template <typename T>
T norm(point3d<T> a) { return dot(a, a); }

template <typename T>
db abs(point3d<T> a) { return sqrt(norm(a)); }

template <typename T>
db proj(point3d<T> a, point3d<T> b) { return dot(a, b) / abs(b); }

template <typename T>
db angle(point3d<T> a, point3d<T> b) { return acos(dot(a, b) / abs(a) / abs(b)); }

template <typename T>
point3d<T> cross(point3d<T> a, point3d<T> b) { return point3d<T>(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }

template <typename T>
T triple(point3d<T> a, point3d<T> b, point3d<T> c) { return dot(a, cross(b, c)); }

point3d<ll> db_ll_conv3d(point3d<db> P) { return point3d<ll> (P.x, P.y, P.z); }
point3d<db> ll_db_conv3d(point3d<ll> P) { return point3d<db> (P.x, P.y, P.z); }