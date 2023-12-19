#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int MOD =  1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e10;

void compute()
{

}

void solve()
{   
    int n; cin >> n;
    int ans = 0;

    vector <pair<int, int>> points;
    points.push_back({0, 0});
    int x = 0, y = 0;

    map <char, pair<int, int>> mp;
    mp['R'] = {0, 1};
    mp['L'] = {0, -1};
    mp['U'] = {1, 0};
    mp['D'] = {-1, 0};

    int perimeter = 0;

    for(int i=0; i<n; i++)
    {
        char dir; cin >> dir;
        int temp; cin >> temp;
        string color; cin >> color;

        perimeter += temp;

        x += mp[dir].first * temp;
        y += mp[dir].second * temp;

        points.push_back({x, y});
    }

    // Shoelace Theorem
    int area = 0;
    for(int i=1; i<points.size(); i++)
    {
        area += ((points[i].first * points[(i+1)%(n+1)].second) - (points[i].second * points[(i+1)%(n+1)].first));
    }
  
    // Pick's Theorem
    // A = i + b/2 - 1
    // i = A - b/2 + 1

    // ans = i + b = A + b/2 + 1
    area = area*0.5;
    cout << area + perimeter + 1 << '\n';
}

signed main(void) 
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;

    compute();
    
    for(int i=0;i<t;i++)
    {
        // cout << "Case #" << i+1 << ": "; // Kick Start
        solve();
    }

	return 0;
}
