#include <bits/stdc++.h> 
using std::vector;
using std::max;
using std::min;

int maximumProfit(vector<int> &prices){
    int mini = prices[0];
    int maxProfit = 0;
    for (auto i : prices){
        maxProfit = max(maxProfit,i-mini);
        mini = min(mini,i);
    }
    return maxProfit;
}