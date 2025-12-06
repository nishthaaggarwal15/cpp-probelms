#include <bits/stdc++.h>
using namespace std;

int n;
pair<double, double> p[101];

double sq(double x)
{
    return x * x;
}

double cost(int x, int y)
{
    double dist = sqrt(sq(p[x].first - p[y].first) + sq(p[x].second - p[y].second));
    return sin(dist);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }

    vector<vector<double>> dp(n, vector<double>(n, 0));
    for (int len = 3; len <= n; len++)
    { // polygon length, starting with triangle , quadiratelera till complete polygon
        for (int l = 0; l + len - 1 < n; l++)
        {
            int r = l + len - 1;
            if (len == 3)
            { // triangle, no triangulation needed
                dp[l][r] = 0;
                continue;
            }
            double ans = 1e18;
            // trying all possible middle points
            for (int x = l + 1; x <= r - 1; x++)
            {
                if (x == l + 1)
                {
                    // single triangle as it doesnt have any left side
                    ans = min(ans, cost(l + 1, r) + dp[l + 1][r]);
                }
                else if (x == r - 1)
                {
                    ans = min(ans, cost(l, r - 1) + dp[l][r - 1]);
                }
                else
                {
                    ans = min(ans, cost(l, x) + cost(r, x) + dp[l][x] + dp[r][x]);
                }
            }

            dp[l][r] = ans;
        }
    }

    cout << fixed << setprecision(6) << dp[0][n - 1] << endl;
    return 0;
}
