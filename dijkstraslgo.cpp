#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define fl(i, l, r, k) for (int i = l; i < r; i += k)
#define vi vector<int>
#define vc vector<char>
#define fe(i, v) for (int i : v)
#define pb push_back
#define pp pop_back
#define in(n) cin >> n
#define out(n) cout << n
#define mii map<int, int>
#define umii unordered_map<int, int>
#define mci map<char, int>
#define pqi priority_queue<int>
#define rpqi priority_queue<int, vector<int>, greater<int>>
#define pii pair<int, int>
#define pci pair<char, int>
#define vpii vector<pair<int, int>>
#define sti stack<int>
#define stc stack<char>
#define qi queue<int>
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define sor(v) sort(all(v))
#define readd(a, n) fl(i, 0, n, 1) cin >> a[i];
#define writee(a) fl(i, 0, n, 1) cout << a[i];
#define ln cout << nl;
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &i : v)
        cin >> i;
    return in;
}
#define sp ' '
template <typename T>
void printArr(vector<T> &v)
{
    for (auto &i : v)
        cout << i << ' ';
}
// per aspera ad astra
int ans(vpii v[], int n, int source, int des)
{
    // vector<bool> vis(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({source, 0});
    vi distanceTo(n, INT_MAX);
    distanceTo[source] = 0;
    vi from(n, -1);

    while (!q.empty())
    {
        int node = q.top().first, dis = q.top().second; // current distance
        q.pop();
        for (auto nei : v[node])
        {
            int ind = nei.first, dist = nei.second;
            if (distanceTo[node] + dist < distanceTo[ind])
            {
                distanceTo[ind] = distanceTo[node] + dist;
                q.push({ind, distanceTo[ind]});
                from[ind] = node;
            }
        }
    }
    int i = des;
    stack<int> s;
    while (from[i] != -1)
    {
        s.push(i);
        i = from[i];
    }
    s.push(source);
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << nl;
    return distanceTo[des];
    // tc=O((n+e)*logn) sc=O(n)
}
void solve()
{
    // d's algo can be used for finding shortest path in both directed and undirected graphs both cyclic and acyclic
    int n;
    cin >> n;
    int edg;
    cin >> edg;
    vpii v[n];
    for (int i = 0; i < edg; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].pb({b, w});
        v[b].pb({a, w});
    }
    cout << ans(v, n, 8, 4);
}
int main()
{
    FIO;

    solve();

    return 0;
}