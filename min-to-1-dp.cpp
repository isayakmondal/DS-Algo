#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

//Simple Recursion
int min_to_1(int no)
{
    if (no <= 1)
    {
        return 0;
    }
    int count1{INT_MAX}, count2{INT_MAX}, count3{INT_MAX};

    count1 = min_to_1(no - 1);
    if (no % 2 == 0)
    {

        count2 = min_to_1((no / 2));
    }
    if (no % 3 == 0)
    {
        count3 = min_to_1((no / 3));
    }

    return min(count1, min(count2, count3)) + 1;
}

//Using DP(Memoization)

int min_to_1_memoization(int no, vector<int> dp)
{
    if (no <= 1)
    {
        return 0;
    }
    if (dp[no] != -1)
    {
        return dp[no];
    }

    int count1{INT_MAX}, count2{INT_MAX}, count3{INT_MAX};

    count1 = min_to_1_memoization(no - 1, dp);
    if (no % 2 == 0)
    {

        count2 = min_to_1_memoization((no / 2), dp);
    }
    if (no % 3 == 0)
    {
        count3 = min_to_1_memoization((no / 3), dp);
    }

    dp[no] = min(count1, min(count2, count3)) + 1;

    return dp[no];
}

//Using DP(Tabulation)

int min_to_1_tabulation(int n)
{
    int *dp = new int[n + 1];

    dp[0] = dp[1] = 0;

    for (int i = 2; i <=n; i++)
    {
        dp[i]=dp[i-1]+1;

        if(i%2==0){
            dp[i]=min(dp[i],dp[i/2]+1);
        }
         if(i%3==0){
            dp[i]=min(dp[i],dp[i/3]+1);
        }
    }
  
    int output = dp[n];
    delete[] dp;
    return output;
}

int main(int argc, char const *argv[])
{
    int no;
    cin >> no;
    // int count = 0;
    // count = min_to_1(no);
    // cout << count << endl;

    // int *dp = new int [no+1]{-1};
    vector<int> dp(no + 1, -1);

    // cout<<min_to_1_memoization(no,dp)<<endl;
    cout << min_to_1_tabulation(no) << endl;

    return 0;
}
