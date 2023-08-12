#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,fma,popcnt,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>   // ac-library  #### CAREFUL on CodeForces
    using namespace atcoder; // ac-library
    std::ostream &operator<<(std::ostream &os, const modint998244353 &a) {return os<<a.val();}
    std::ostream &operator<<(std::ostream &os, const modint1000000007 &a) {return os<<a.val();}
#endif
// # Type Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T,U>;
template<class T> using max_heap = priority_queue<T>;
template<class T> using min_heap = priority_queue<T,vector<T>,greater<T>>;
// # Repeat Macros
#define OVERLOADER(_1,_2,_3,NAME,...) NAME
#define REP2(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define REP(i,n) REP2(i,0,n)
#define rep(...) OVERLOADER(__VA_ARGS__,REP2,REP)(__VA_ARGS__)
#define repd(i,a,b) for (ll i = (ll)(b)-1; i >= (ll)(a); --i)
// # Abbreviation Macros
#define pb push_back
#define eb emplace_back
#define ALL(a) begin(a),end(a)
#define RALL(a) a.rbegin(),a.rend()
// # Fast IO and IO Settings
struct IO_Setting{IO_Setting(){cin.tie(nullptr);cerr<<fixed<<setprecision(3);}}io_setting;
// # Input Overloads
template<class T,class U> istream& operator>>(istream& is,P<T,U>&t){return is>>t.first>>t.second;}
template<class T> istream& operator>>(istream& is,V<T>&v){for(T& e:v) is>>e; return is;}
// # Output Overloads
template<class T,class U> ostream& operator<<(ostream& os,const P<T,U>& t){return os<<t.first<<' '<<t.second;}
template<class T> ostream& operator<<(ostream& os,const V<T>& v) {int ss=v.size(); rep(ii,ss) {os<<v[ii]<<(ii+1==ss?"":" ");} return os;}
// # Function Definition
template<class T, class U> inline bool chmin(T &a, U b) { if(a>b) {a=b; return 1;} return 0;}
template<class T, class U> inline bool chmax(T &a, U b) { if(a<b) {a=b; return 1;} return 0;}
ll max (ll lhs, ll rhs) {return std::max<ll>(lhs, rhs);}
ll min (ll lhs, ll rhs) {return std::min<ll>(lhs, rhs);}
template<class Container> Container reversed(const Container& v) {return Container(v.rbegin(), v.rend());}
template<class Container> Container sorted(const Container& v, bool rev=false) {Container r = v; rev ? sort(r.rbegin(), r.rend()) : sort(r.begin(), r.end()); return r;}
template<class T>void uniqify(V<T>& v){v.erase(unique(ALL(v)),v.end());}
template<class T>V<T> compress(V<T>& v){V<T>vals=v;sort(ALL(vals));uniqify(vals);rep(i,v.size())v[i]=lower_bound(ALL(vals),v[i])-vals.begin();return vals;}
template<class T>V<T> sum_array(const V<T>& v) {int n=v.size(); V<T> sum(n+1); rep(i,n) sum[i+1]=sum[i]+v[i]; return sum;}
template<class T>inline void drop(T&& x) { cout << x << endl; exit(0); }
inline void yesno(bool f) { cout << (f ? "Yes" : "No") << '\n'; }
// # Constant Definition
constexpr char ENDL = '\n';
constexpr ll INF = (1LL<<30)-1; // 問題毎にfit
constexpr ll INFLL = (1LL<<62)-1; // 問題毎にfit
const ld PI = acos(static_cast<long double>(-1));
// constexpr int dy[]={0, 1, 0, -1};
// constexpr int dx[]={1, 0, -1, 0};
// constexpr int dy[]={0, 1, 1, 1, 0, -1, -1, -1};
// constexpr int dx[]={1, 1, 0, -1, -1, -1, 0, 1};
// # Debug Macro
#ifdef LOCAL
    #include "debug_print.hpp"
    #define debug(...) debug_impl(__LINE__, __VA_ARGS__)
    #define debug_impl(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
    #define debug(...) (static_cast<void>(0))
#endif

// Vector2DUtil.cpp
#include <algorithm>
#include <vector>

template <typename T>
std::vector<std::vector<T>> transposed(const std::vector<std::vector<T>>& v) {
    size_t n = v.size(), m = v.front().size();
    std::vector<std::vector<T>> ret(m, std::vector<T>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ret[i][j] = v[j][i];
        }
    }
    return ret;
}

template <typename T>
std::vector<std::vector<T>> clockwise_rotated(
    const std::vector<std::vector<T>>& v) {
    int n = v.size(), m = v.front().size();
    std::vector<std::vector<T>> ret(m, std::vector<T>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ret[i][j] = v[n - j - 1][i];
        }
    }

    return ret;
}

template <typename T>
std::vector<std::vector<T>> counterclockwise_rotated(
    const std::vector<std::vector<T>>& v) {
    int n = v.size(), m = v.front().size();
    std::vector<std::vector<T>> ret(m, std::vector<T>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ret[i][j] = v[j][m - i - 1];
        }
    }

    return ret;
}

template <typename T>
std::vector<std::vector<T>> trimmed(const std::vector<std::vector<T>>& v,
                                    T&& t = T{}) {
    auto w = v;
    for (int rot_num = 0; rot_num < 4; rot_num++) {
        while (!w.empty() && std::all_of(w.back().begin(), w.back().end(),
                                         [&t](T u) { return u == t; })) {
            // trim bottom line
            w.pop_back();
        }

        w = clockwise_rotated(w);
    }
    return w;
}

struct Timer {
    static constexpr int64_t CYCLES_PER_SEC = 
    #ifdef LOCAL
        1100000000LL;
    #else
        2800000000LL; // コードテストでは3e9 (3GHz)
    #endif

    static constexpr double TIME_LIMIT = 4.8;
	int64_t start;
	Timer() { reset(); }
	void reset() { start = getCycle(); }
    /// @brief add `a` seconds to the timer.
	void plus(double a) { start -= (a * CYCLES_PER_SEC); }
	/// @brief get seconds from the start.
	double get() { return (double)(getCycle() - start) / CYCLES_PER_SEC; }
    bool is_in_time() { return get() < TIME_LIMIT; }
	inline int64_t getCycle() {
		uint32_t low, high;
		__asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
		return ((int64_t)low) | ((int64_t)high << 32);
	}
} TIMER;

// # Random
struct Random {
private:
    int seed;
public:
    Random(int64_t seed = TIMER.getCycle()) : seed(seed & std::numeric_limits<int>::max()) {}

    // xor shift 128
    unsigned int rand_int() {
        static unsigned int x = 123456789;
        static unsigned int y = 362436069;
        static unsigned int z = 521288629;
        // static unsigned int w = 88675123;
        static unsigned int w = seed;
        unsigned int t;

        t = x ^ (x << 11);
        x = y; y = z; z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    }
    unsigned int rand_int(int r) {
        assert(r > 0);
        return rand_int() % r;
    }
    // random int between [l, r)
    unsigned int rand_int(int l, int r) {
        return l + rand_int(r - l);
    }
    double rand_prob() { 
        static constexpr unsigned int _INF = 1U << 31;
        return (rand_int() & _INF) / (double)_INF;
    }
} RAND;


struct Point;

namespace Const {
    int L;
    int N;
    int S;
    V<Point> Hole;

    void init() {
        cin >> L >> N >> S;
        Hole.resize(N);
        cin >> Hole;
    }
    template<typename T>
    void safe_inc_index(T& x) {
        if(x < L - 1) ++x;
        else x = 0;
    }

    template<typename T>
    T safe_inced_index(T x) {
        return (x < L - 1 ? x + 1 : T(0));
    }
}
using Const::L, Const::N, Const::S, Const::Hole, Const::safe_inc_index, Const::safe_inced_index;

struct Point {
    int x, y;
    Point() = default;
    Point(int x, int y) : x(x), y(y) {}
    Point moved(int dx, int dy) {
        return Point((x + dx) % L, (y + dy) % L);
    }
    friend istream& operator>>(istream& is, Point& t) {
        return is >> t.x >> t.y;
    }
};

struct Temperature {
    using value_type = long long;
    static constexpr value_type unsettled = -1;

    V<V<value_type>> t;
    Temperature() : t(L, V<value_type>(L, unsettled)) {}

    V<value_type>& operator[](int i) {return t[i];}
    value_type& athole(int i) {return t[Hole[i].x][Hole[i].y];}

    /// @brief 2次元線形補間 
    Temperature smoothed() {
        Temperature res(*this);

        auto interpolate_x_direction = [&](V<V<value_type>>& v){
            rep(i, L) {
                auto& temp = v[i];
                // 全部unsettled ならやらない
                if(all_of(ALL(temp), [](auto x){return x == unsettled;})) {
                    continue;
                }

                V<int> checked(L);
                // [l, 次の settled) を補間
                for (int l = std::find_if_not(
                                 ALL(temp), [](auto x) { return x == unsettled; }) -
                             temp.begin(),
                         r = safe_inced_index(l);;) {
                    if(checked[l]) break;

                    while(temp[r] == unsettled) safe_inc_index(r);

                    int tl = l, tr = (r <= l ? r + L : r);
                    assert(tl < tr);
                    double coeff = (temp[r] - temp[l]) / (double)(tr - tl);

                    for(int tk = tl; tk < tr; tk++) {
                        int k = (tk >= L ? tk - L : tk);
                        temp[k] = round(temp[l] + coeff * (tk - tl));
                        checked[k] = true;
                    }

                    l = r;
                    r = safe_inced_index(l);
                }
            }
        };

        // x軸方向とy軸方向両方やる
        interpolate_x_direction(res.t);
        res.t = clockwise_rotated(res.t);
        interpolate_x_direction(res.t);
        res.t = counterclockwise_rotated(res.t);
        res.resolve_unsettled();

        return res;
    }

    void resolve_unsettled() {
        for_each(ALL(t), [](V<value_type>& v) {
            for_each(ALL(v), [](value_type& x) {
                if(x == unsettled) x = 0;
            });
        });
    }

    /// @brief settle all the temperature and print to stdout
    void set() {
        // set() must be called only once.
        static bool called = false;
        assert(!called);
        called = true;

        resolve_unsettled();

        rep(i, L) {
            rep(j, L) {
                cout << t[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << flush;
    }
};

using Measurement = Temperature::value_type;

struct Query {
    int i, x, y;
    Query(int i, int x, int y) : i(i), x(x), y(y) {}
    Measurement ask() {
        cout << i << ' ' << x << ' ' << y << endl;
        Measurement res;
        cin >> res;
        if(res == -1) {
            fprintf(stderr, "Invalid value given at measurement input at (i, x, y) = (%d, %d, %d)", i, x, y);
            exit(EXIT_FAILURE);
        }

        return res;
    }
};


struct Solver {
    Solver() { Const::init(); }
    void solve() {
        // Generate Temperature
        Temperature t;
        rep(i, N) {
            t.athole(i) = (1000 / N) * i;
        }

        // 穴以外をsmoothen
        t = t.smoothed();

        t.set();

        // Ask Queries and Estimate
        V<int> estimate(N);
        rep(i, N) {
            int sz = 100;
            V<int> measures(sz);
            rep(nt, sz) {
                Query q((int)i, 0, 0);
                measures[nt] = q.ask();
            }
            double mean = reduce(ALL(measures)) / (double)sz;

            double diffmn = INF;
            rep(j, N) {
                if(chmin(diffmn, abs(t.athole(j) - mean))) estimate[i] = j;
            }
        }

        // Output estimate
        cout << "-1 -1 -1\n";
        for(auto e : estimate) cout << e << '\n';
        cout << flush;
    }
};

int main() {
    Solver solver;
    solver.solve();
}