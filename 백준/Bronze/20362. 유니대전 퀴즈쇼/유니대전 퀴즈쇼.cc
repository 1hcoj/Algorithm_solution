#include <iostream>
#include <map>
using namespace std;

int main(){
    map<string,int> maps;
    int N;
    string correctPerson,person,answer;
    cin >> N >> correctPerson;
    
    for (int i =0;i<N;i++){
        cin >> person >> answer;
        if (person != correctPerson) maps[answer]++;
        else {
            cout << maps[answer] << endl;
            break;
        }
    }
}