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
    string nav; cin >> nav;
    int n = nav.length();

    unordered_map <string, pair<string, string>> mp;
    for(int i=0; i<798; i++)
    {
        string a, dummy, b1, b2;
        cin >> a >> dummy >> b1 >> b2;

        mp[a] = {b1.substr(1, 3), b2.substr(0, 3)};
    }

    int step = 0;
    string node = "AAA";

    while(node != "ZZZ")
    {
        int index = step % n;

        if(nav[index] == 'L') node = mp[node].first;
        else node = mp[node].second;

        step++;
    }

    cout << step << '\n';
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
