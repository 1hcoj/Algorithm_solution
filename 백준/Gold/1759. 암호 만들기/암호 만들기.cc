#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<char> cs;
string answer = "";
int L, C, vowels_num = 0, consonant_num = 0, last_vowel_index = -1, last_consonant_index = -1;
char vowels[5] = {'a','e','i','o','u'};

bool is_promising(int depth,int node) {
	if (depth != L) {
		if (vowels_num == 0 && node > last_vowel_index || (consonant_num < 2 && node > last_consonant_index)) {
			return false;
		}
	}else {
		if ((vowels_num < 1 || consonant_num < 2)) {
			return false;
		}
	}
	return true;
}

bool is_vowel(char c) {
	for (int i = 0; i < 5; i++) {
		if (vowels[i] == c) return true;
	}
	return false;
}

void dfs(int depth,int node) {
	if (!is_promising(depth,node)) return;
	if (depth == L) {
		cout << answer << '\n';
		return;
	}

	for (int i = node; i < C; i++) {
		if (is_vowel(cs[i])) vowels_num++; else consonant_num++;
		answer += cs[i];
		dfs(depth + 1, i + 1);
		if (is_vowel(cs[i])) vowels_num--;  else consonant_num--;
		answer.erase(answer.end() - 1);
	}
}

int main() {
	cin >> L >> C;
	cs = vector<char>(C);
	for (int i = 0; i < C; i++) {
		cin >> cs[i];
	}
	sort(cs.begin(), cs.end());

	auto it = find_if(cs.rbegin(), cs.rend(), [](char c1) {
		return is_vowel(c1);
		});
	if (it != cs.rend()) {
		last_vowel_index = cs.rend() - it - 1;
	}
	it = find_if(cs.rbegin(), cs.rend(), [](char c1) {
		return !is_vowel(c1);
		});
	if (it != cs.rend()) {
		last_consonant_index = cs.rend() - it - 1;
	}
	
	dfs(0, 0);

}