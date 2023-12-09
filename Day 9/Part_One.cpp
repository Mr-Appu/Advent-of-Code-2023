#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int MOD =  1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e10;

void compute()
{

}

int ans;
int n;

int fun(vector <int> &arr)
{
    if(arr.size() == 0) return 0;

    vector <int> new_arr;

    map <int, int> mp;
    for(int i=1; i<arr.size(); i++)
    {
        new_arr.push_back(arr[i] - arr[i-1]);
        mp[arr[i] - arr[i-1]]++;
    }

    if(mp.size() == 1) return new_arr[0] + arr[arr.size() - 1];

    return arr[arr.size() - 1] + fun(new_arr);
}

void solve()
{
    n = 21;

    vector <int> arr(n);  
    for(int i=0; i<n ;i++) cin >> arr[i];

    ans += fun(arr);

    cout << ans << '\n';
}
 
signed main(void) 
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 200;
    // cin >> t;

    compute();
    
    for(int i=0;i<t;i++)
    {
        // cout << "Case #" << i+1 << ": "; // Kick Start
        solve();
    }

	return 0;
}
