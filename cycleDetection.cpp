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
bool undirdfs(vi v[], int i, int n, vector<bool> &vis)
{
    stack<pair<int, int>> s;
    vis[i] = true;
    s.push({i, -1});
    while (!s.empty())
    {
        int node = s.top().first, parent = s.top().second;
        s.pop();
        for (auto nei : v[node])
        {
            if (!vis[nei])
            {
                vis[nei] = true;
                s.push({nei, node});
            }
            else if (nei != parent)
                return true;
        }
    }
    return false;
}
bool undirbfs(vi v[], int i, int n, vector<bool> &vis)
{
    queue<pair<int, int>> q;
    q.push({i, -1});
    vis[i] = true;
    while (!q.empty())
    {
        int node = q.front().first, parent = q.front().second;
        q.pop();
        for (auto nei : v[node])
        {
            if (!vis[nei])
            {
                vis[nei] = true;
                q.push({nei, node});
            }
            else if (nei != parent)
                return true;
        }
    }
    return false;
}
void undir()
{
    int n, m;
    cin >> n >> m;
    vi v[n];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        v[a].pb(b);
        v[b].pb(a);
    }
    vector<bool> vis(n, false);
    int numCycles = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (undirdfs(v, i, n, vis))
                cout << "YES", ++numCycles;
        }
    }
    cout << numCycles;
}
bool dirdfs(vi v[], int i, vector<int> &vis)
{
    // states: 0->not visited| 1->visited | 2->visited+visited in current traversal
    stack<int> s;
    vis[i] = 2;
    s.push(i);
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        for (auto nei : v[node])
        {
            if (!vis[nei])
            {
                vis[nei] = 1;
                s.push(nei);
            }
            else if (vis[nei] == 2)
                return true;
        }
    }
    return false;
}
bool dirbfs(vi v[], int n, vector<int> &indegree)
{
    // here we use converse of topo sort
    // if we find a topo sort of size n it means there exists a vali topo sort and hence no cycle else it means there is
    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto nei : v[node])
        {
            if (--indegree[nei] == 0)
                q.push(nei);
        }
    }
    return !(ans.size() == n);
}
void dir()
{
    int n, m;
    cin >> n >> m;
    vi v[n];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a].pb(b);
    }
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            if (dirdfs(v, i, vis))
                cout << "yes";
    }
}

int main()
{
    FIO;

    dir();

    return 0;
}