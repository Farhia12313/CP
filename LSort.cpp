#include<bits/stdc++.h>
using namespace std;
int n,m;
bool compare(int a ,int b){
    int modA = a % m;
    int modB = b % m;
    if(modA != modB){
        return modA < modB;
    }
    bool isOddA = ( a % 2 != 0);
    bool isOddB = ( b % 2 != 0);
    if(isOddA != isOddB){
        return isOddA;
    }
    if(isOddA){
        return a > b;
    }
    return a < b;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n >> m && (n != 0 || m != 0)){
        vector<int> numbers(n);
        for(int i=0;i<n;i++){
            cin >> numbers[i];
        }
         sort(numbers.begin(), numbers.end(), compare);
        
        cout << n << " " << m << "\n";
        for (int i = 0; i < n; i++) {
            cout << numbers[i] << "\n";
        }
    }
      cout << "0 0\n";
      return 0;
}