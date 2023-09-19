#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> sale_per;
int N;
vector<vector<int>> users_all;
vector<int> emoticons_all;
vector<int> answer = {-1,-1};
void dfs(int depth){
    if (depth == N){
        int buy_user_num = 0;
        int buy_price = 0;
        for (vector<int> user : users_all){
            int sum = 0;
            for (int i =0;i<sale_per.size();i++){
                int s_p = sale_per[i];
                if (s_p >= user[0]) sum += (emoticons_all[i] - (emoticons_all[i] * s_p)/100 );
            }
            if (sum >= user[1]) buy_user_num++;
            else buy_price += sum;
        }
        if (buy_user_num > answer[0]) {
            answer = {buy_user_num,buy_price};
        }
        else if (buy_user_num == answer[0] && buy_price > answer[1]) answer[1] = buy_price;
        return;
    }
    for (int i =10;i<=40;i+= 10){
        sale_per[depth] = i;
        dfs(depth+1);
        sale_per[depth] = 0;
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    users_all = users;
    emoticons_all = emoticons;
    N = emoticons.size();
    sale_per = vector<int>(N);
    dfs(0);
    return answer;
}