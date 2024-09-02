#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
#define rep(i, l, r) for(ll i = (l); i <= (r); ++i)
#define rep_(i, l, r) for(ll i = (l); i >= (r); --i)
#define endl '\n'
const ll N = 1e5 +7, P = 1e9 + 7, Inf = 1e18;
struct Seg{
	ll u, v, l, r;
}s[N];
bool cmp1(Seg a, Seg b) {
	return min(a.v,a.r) < max(b.v,b.r);
}
bool cmp2(Seg a, Seg b) {
	return max(a.u,a.l) < min(b.u,b.l);
}
struct Node{
	ll l, r, mx, tag;
}t[N << 3], g[N << 3];
ll lson(ll x) { return x << 1; }
ll rson(ll x){ return x << 1 | 1;}

void pushup(ll c) {
	t[c].mx = max(t[lson(c)].mx,t[rson(c)].mx);
}

void build(ll c, ll l, ll r) {
	t[c] = {l,r,0,0};
	if(l == r) {
		t[c].mx = l;
		return;
	}
	ll mid = l + r >> 1;
	build(lson(c), l, mid);
	build(rson(c), mid + 1, r);
	pushup(c);
}

bool ck(ll c,ll l,ll r) {
	return !(t[c].l > r || t[c].r < l);
}

void pushdown(ll c) {
	t[lson(c)].mx = max(t[lson(c)].mx, t[c].tag);
	t[lson(c)].tag = max(t[lson(c)].tag, t[c].tag);
	t[rson(c)].mx = max(t[rson(c)].mx, t[c].tag);
	t[rson(c)].tag = max(t[rson(c)].tag, t[c].tag);
}

ll query_seg(ll c,ll ql, ll qr) {
	ll l = t[c].l,r = t[c].r;
	if(ql <= l && r <= qr) return t[c].mx;
	pushdown(c);
	ll mid = l + r >> 1;
	ll ans = 0;
	if(ck(lson(c),ql,qr)) ans =max(ans,query_seg(lson(c),ql,qr));
	if(ck(rson(c),ql,qr)) ans =max(ans,query_seg(rson(c),ql,qr));
	pushup(c);
	return ans;
}

void update(ll c, ll ul,ll ur ,ll val) {
	ll l = t[c].l,r = t[c].r;
	if(ul <= l && r <= ur) {
		t[c].mx = max(t[c].mx,val);
		t[c].tag = max(t[c].tag,val);
		return;
	}
	pushdown(c);
	if(ck(lson(c),ul,ur)) update(lson(c), ul,ur,val);
	if(ck(rson(c),ul,ur)) update(rson(c), ul,ur,val);
	pushup(c);
}

ll query_p(ll c,ll pos) {
	ll l = t[c].l, r = t[c].r;
	if(l == r) {
		return t[c].mx;
	}
	ll mid = l + r >> 1;
	pushdown(c);
	if(pos <= mid) return query_p(lson(c), pos);
	else return query_p(rson(c), pos);
}




void pushup_(ll c) {
	g[c].mx = min(g[lson(c)].mx,g[rson(c)].mx);
}

void build_(ll c, ll l, ll r) {
	g[c] = {l,r,Inf,Inf};
	if(l == r) {
		g[c].mx = l;
		return;
	}
	ll mid = l + r >> 1;
	build_(lson(c), l, mid);
	build_(rson(c), mid + 1, r);
	pushup_(c);
}

bool ck_(ll c,ll l,ll r) {
	return !(g[c].l > r || g[c].r < l);
}

void pushdown_(ll c) {
	g[lson(c)].mx = min(g[lson(c)].mx, g[c].tag);
	g[lson(c)].tag = min(g[lson(c)].tag, g[c].tag);
	g[rson(c)].mx = min(g[rson(c)].mx, g[c].tag);
	g[rson(c)].tag = min(g[rson(c)].tag, g[c].tag);
}

ll query_seg_(ll c,ll ql, ll qr) {
	ll l = g[c].l,r = g[c].r;
	if(ql <= l && r <= qr) return g[c].mx;
	pushdown_(c);
	ll mid = l + r >> 1;
	ll ans = Inf;
	if(ck(lson(c),ql,qr)) ans =min(ans,query_seg_(lson(c),ql,qr));
	if(ck(rson(c),ql,qr)) ans =min(ans,query_seg_(rson(c),ql,qr));
	pushup_(c);
	return ans;
}

void update_(ll c, ll ul,ll ur ,ll val) {
	ll l = g[c].l,r = g[c].r;
	if(ul <= l && r <= ur) {
		g[c].mx = min(g[c].mx,val);
		g[c].tag = min(g[c].tag,val);
		return;
	}
	pushdown_(c);
	if(ck_(lson(c),ul,ur)) update_(lson(c), ul,ur,val);
	if(ck_(rson(c),ul,ur)) update_(rson(c), ul,ur,val);
	pushup_(c);
}

ll query_p_(ll c,ll pos) {
	ll l = g[c].l, r = g[c].r;
	if(l == r) {
		return g[c].mx;
	}
	ll mid = l + r >> 1;
	pushdown_(c);
	if(pos <= mid) return query_p_(lson(c), pos);
	else return query_p_(rson(c), pos);
}
	
void solve() {
	ll n, m; cin >> n >> m;
	build(1, 1, n);
	build_(1, 1, n);
	rep(i, 1, m) cin >> s[i].u >> s[i].v >> s[i].l >> s[i].r;
	sort(s + 1, s + m + 1, cmp1);
	rep_(i, m, 1) {
		ll mx = query_seg(1, s[i].l, s[i].r);
		update(1,s[i].u,s[i].v, mx);
	}

	sort(s + 1, s + m + 1, cmp2);
	rep(i, 1, m) {
		ll mx = query_seg_(1, s[i].l, s[i].r);
		update_(1,s[i].u,s[i].v, mx);
	}

	rep(i, 1, n) cout << query_p_(1, i) << " " <<  query_p(1, i) <<  endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T(1); 
	cin >> T;
	while (T--) solve();
	return 0;
}
