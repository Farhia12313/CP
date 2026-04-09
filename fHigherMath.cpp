#include<bits/stdc++.h>
using namespace std;
void solve(int caseNum){
    vector<int> sides(3);
    for(int i=0;i < 3;i++){
        cin >> sides[i];
    }
    sort(sides.begin(),sides.end());
    if((sides[0] * sides[0] + sides[1] * sides[1]) == (sides[2] * sides[2])){
        cout <<"Case " << caseNum << ": yes" <<endl; 
    }
    else{
        cout <<"Case " << caseNum <<": no" << endl;
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    if(cin >> t){
        for(int i=1;i <= t; i++){
            solve(i);
        }
    }
    return 0;
}