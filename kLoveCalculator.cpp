#include<bits/stdc++.h>
using namespace std;
int getSingleDigitSum(int n){
    while(n>=10){
        int sum =0;
        while(n>0){
            sum+=n%10;
            n/=10;
        } 
        n=sum;
    }
    return n;
}
int calculateValue(string name){
    int totalSum = 0;
    for(char c: name){
        if(isalpha(c)){
            totalSum += tolower(c) - 'a' + 1;
        }
    }
    return getSingleDigitSum(totalSum);
}
int main(){
    string name1,name2;
    while(getline(cin,name1) && getline(cin,name2)){
        int val1=calculateValue(name1);
        int val2 = calculateValue(name2);
        double result;
        if(val1 == 0 && val2 == 0){
            cout << fixed << setprecision(2) << 0.00 << " %" << endl;
            continue;
        }
        if(val1>val2){
            result = (double)val2/(double)val1 * 100.0;
            
        }
        else{
             result = (double)val1/(double)val2 * 100.0;

        }
        cout << fixed << setprecision(2) << result <<" %" << endl;
    }
    return 0;
}