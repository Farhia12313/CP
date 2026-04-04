#include<bits/stdc++.h>
using namespace std;
void solve(int caseNum){
    int N;
    cin >>N;
    vector<int> heights(N);
    for(int i=0;i<N;i++){
        cin >> heights[i];
    }
    int highjump=0;
    int lowjump=0;
    for(int i=0;i<N-1;i++){
        if(heights[i+1] > heights[i]){
            highjump++;

        }
        else if(heights[i+1]<heights[i]){
            lowjump++;
        }
    }
        cout <<"Case " <<caseNum <<": " << highjump << " " << lowjump << endl;
    }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    
    if(cin >> t){
        for(int i=1;i<=t;i++){
        solve(i);
    }}
    
    return 0;
}