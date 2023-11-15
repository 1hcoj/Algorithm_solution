#include <iostream>
#include <map>

using namespace std;

int main(){
    int N,h,v,sum=0;
    cin >> N;
    map<int,int> heights;
    for (int i = 0;i<N;i++){
        cin >> h;
        heights[h]++;
    }
    for (const auto&[key,value] : heights){
        v = (value >2) ? 2 : value;
        sum += v;
    }
    cout << sum << endl;
}