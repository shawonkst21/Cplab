#include<bits/stdc++.h>
using namespace std;
using ll =long long;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
const int N = 1e5 + 10;
void faster()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
}
#define testCase \
    int t;       \
    cin >> t;    \
    while (t--)
ll a[N];

struct st {
    #define lc (node << 1)
    #define rc ((node << 1) + 1)
   
    ll t[4 * N], lazy[4 * N];

    st() {
        memset(t, 0, sizeof(t));
        memset(lazy, 0, sizeof(lazy));
    }

    // Function to propagate lazy updates
    inline void push(ll node, ll st, ll en) {
        if (lazy[node] == 0) {
            return;
        }
        t[node] = t[node] + lazy[node] * ((en - st) + 1);
        if (st != en) {
            lazy[lc] = lazy[lc] + lazy[node];
            lazy[rc] = lazy[rc] + lazy[node];
        }
        lazy[node] = 0;
    }

    // Function to combine values for non-leaf nodes
    inline ll combine(ll a, ll b) {
        return a + b; 
    }

    // Function to update node values
    inline void op(ll node) {
        t[node] = t[lc] + t[rc];
    }

    // Build segment tree
    void build(ll node, ll st, ll en) {
        lazy[node] = 0;
        if (st == en) {
            t[node] = a[st];
        } else {
            int mid = (st + en) >> 1;
            build(lc, st, mid);
            build(rc, mid + 1, en);
            op(node);
        }
    }

    // Update segment tree
    void update(ll node, ll st, ll en, ll l, ll r, ll v) {
        push(node, st, en);
        if (st > r || en < l) {
            return;
        }
        if (l <= st && en <= r) {
            lazy[node] = v;
            push(node, st, en);
            return;
        }
        int mid = (st + en) >> 1;
        update(lc, st, mid, l, r, v);
        update(rc, mid + 1, en, l, r, v); 
        op(node);
    }

    // Query segment tree
    ll query(ll node, ll st, ll en, ll l, ll r) {
        push(node, st, en);
        if (st > r || en < l) {
            return 0;
        }
        if (l <= st && en <= r) {
            return t[node];
        }
        int mid = (st + en) >> 1;
        return combine(query(lc, st, mid, l, r), query(rc, mid + 1, en, l, r));
    }

} seg;
int main()
{
	faster();
    testCase
    {
       int n,q;
       cin>>n>>q;
       seg.build(1,1,n);
       while(q--)
       {
        int type;
        cin>>type;
        if(type==0)
        {
            int l,r,val;
            cin>>l>>r>>val;
            seg.update(1,1,n,l,r,val);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<seg.query(1,1,n,l,r)<<endl;
        }
       } 
    }
}