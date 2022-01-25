//0 basedindexing
// for more details visit blog Efficent and easy seg,ent trees on codeforces


// this is the codef for dynamic range minimum queries

const int N = 1e5;  // limit for array size
int n;  // array size
int t[(int)4e5];
void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = min(t[i << 1], t[i << 1 | 1]);
}

void modify(int p, int value) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = min(t[p] , t[p ^ 1]);
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = INT_MAX;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, t[l++]);
        if (r & 1) res = min(res, t[--r]);
    }
    return res;
}
void Jai_shree_ganesh(int tt) {
//cout<<"never give up"<<endl;
//cout << "play to win" << endl;
//cout<<"Case #"<<tt<<": ";
    ll  Q;
    cin >> n >> Q;
    vector<ll> v(n + 1);
    for (ll i = 0; i < 40; i++) t[i] = 1e9;
    for (ll i = 0; i < n; i++) {
        cin >> t[n + i];
    }
    //debug(t);
    build();
    while (Q--) {
        int x, a, b;
        cin >> x >> a >> b;
        if (x == 1) {
            modify(a - 1, b);
        }
        else {
            int x = query(a - 1 , b);
            cout << x << "\n";
        }
    }
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    //cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        Jai_shree_ganesh(i);
    }
    return (0);
}
