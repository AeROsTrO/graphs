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
void dfs(vi v[], int source, vector<bool> &vis)
{
    // int c=0;

    stack<int> s;
    s.push(source);
    while (!s.empty())
    {
        int x = s.top();
        s.pop();
        vis[x] = true;
        for (int nei : v[x])
        {
            if (!vis[nei])
            {
                s.push(nei);
                vis[nei] = true;
            }
        }
    }
    // return c;
}
int connectedComponents(vi v[], int n)
{
    vector<bool> vis(n, false);
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(v, i, vis), num++;
    }
    return num;
}
int dfsL(vi v[], int source, vector<bool> &vis)
{
    stack<int> s;
    int c = 1;
    s.push(source);
    while (!s.empty())
    {
        int x = s.top();
        s.pop();
        vis[x] = true;
        for (int nei : v[x])
        {
            if (!vis[nei])
            {
                vis[nei] = true;
                ++c;
                s.push(nei);
            }
        }
    }
    return c;
}
int largestComponent(vi v[], int n)
{
    int ma = 0;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            ma = max(ma, dfsL(v, i, vis));
    }
    return ma;
}
// island count
// given a binary grid of 0 and 1 0 representing water and 1 representing land fidn the number of islands, islands are formed when land is connected and surrounded by water
void dfss(vector<vector<char>> &v, int cx, int cy, vector<vector<bool>> &vis)
{
    stack<pair<int, int>> s;
    int m = v.size(), n = v[0].size();
    s.push({cx, cy});
    // int c=1;
    while (!s.empty())
    {
        int x = s.top().first, y = s.top().second;
        s.pop();
        vis[x][y] = true;
        if (x + 1 < m)
        {
            if (v[x + 1][y] == '1' and !vis[x + 1][y])
            {
                s.push({x + 1, y});
                vis[x + 1][y] = true;
            }
        }
        if (y + 1 < n)
        {
            if (v[x][y + 1] == '1' and !vis[x][y + 1])
            {
                vis[x][y + 1] = true;
                s.push({x, y + 1});
            }
        }
        if (x - 1 >= 0)
        {
            if (v[x - 1][y] == '1' and !vis[x - 1][y])
            {
                vis[x - 1][y] = true;
                s.push({x - 1, y});
            }
        }
        if (y - 1 >= 0)
        {
            if (v[x][y - 1] == '1' and !vis[x][y - 1])
            {
                vis[x][y - 1] = true;
                s.push({x, y - 1});
            }
        }
    }
    // return c;
}
int numIslands(vector<vector<char>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '0' || vis[i][j])
                continue;
            else
            {
                dfss(grid, i, j, vis);
                ++ans;
            }
        }
    }
    return ans;
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
    cout << largestComponent(v, n);
}
int main()
{
    FIO;

    solve();

    return 0;
}