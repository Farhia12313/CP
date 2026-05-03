//kadane's algorithm
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    int n;
    cin >> n;
    vector<long long> x(n);
    for(int i=0;i<n;i++) cin >> x[i];
    ll current = x[0];
    ll maxSum = x[0];
    for(int i=1;i<n;i++){
        current = max(current+x[i],x[i]);
        maxSum = max(maxSum,current);
    }
    cout << maxSum << endl;
    return 0;

}