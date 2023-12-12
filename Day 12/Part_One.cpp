// Solution inspired from : https://www.youtube.com/watch?v=EYn0Al6rKFQ 

#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int MOD =  1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e10;

void compute()
{

}

int fun(int i, string &str, int j, vector <int> &arr,int left)
{
    if(i == str.length()) 
    {
        if(j == arr.size() && left == 0) return 1;
        else return 0;
    }

    if(j > arr.size()) return 0;

    int total = 0;

    if(str[i] == '.')
    {
        if(left == 0) 
        {
            if(j < arr.size()) total += fun(i+1, str, j+1, arr, arr[j]);
            total += fun(i+1, str, j, arr, 0);
        }
    }
    else if(str[i] == '#')
    {
        if(left > 0) total += fun(i+1, str, j, arr, left-1);
    }
    else if(str[i] == '?')
    {
        if(left == 0) 
        {
            if(j < arr.size()) total += fun(i+1, str, j+1, arr, arr[j]);
            total += fun(i+1, str, j, arr, 0);
        }

        if(left > 0) total += fun(i+1, str, j, arr, left-1);
    }

    return total;
}

int part_1_ans = 0;

void solve()
{
    string str; cin >> str; str = "." + str;
    string digit; cin >> digit; digit += ",";

    vector <int> arr;

    int temp = 0;
    for(int i=0; i<=digit.size(); i++)
    {
        if(digit[i] == ',') 
        {
            arr.push_back(temp);
            temp = 0;
        }
        else temp = temp*10 + digit[i] - '0'; 
    }

    part_1_ans += fun(0, str, 0, arr, 0);
}
 
signed main(void) 
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1000;
    // cin >> t;

    compute();
    
    for(int i=0;i<t;i++)
    {
        // cout << "Case #" << i+1 << ": "; // Kick Start
        solve();
    }

    cout << part_1_ans << '\n';

	return 0;
}
