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
int shortestPath(vi v[], int n, int source, int destination)
{
    int dis = INT_MAX;
    vector<bool> vis(n, false);
    queue<pair<int, int>> q;
    q.push({source, 0});
    while (!q.empty())
    {
        int node = q.front().first, disThis = q.front().second;
        q.pop();
        vis[node] = true;
        if (node == destination)
            dis = min(dis, disThis);
        for (int nei : v[node])
        {
            if (!vis[nei])
            {
                vis[nei] = true;
                q.push({nei, disThis + 1});
            }
        }
    }
    return dis;
}
void solve()
{
    int n;
    cin >> n;
    int edg;
    cin >> edg;
    vi v[n];
    for (int i = 0; i < edg; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    cout << shortestPath(v, n, 2, 6);
}
int main()
{
    FIO;

    solve();

    return 0;
}