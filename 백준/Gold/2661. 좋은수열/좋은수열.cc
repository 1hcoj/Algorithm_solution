#include <iostream>
#include <string>

using namespace std;

int N;

bool is_bad(string seq) {
	for (int i = 1; i <= seq.length() / 2; i++) {
		string back = seq.substr(seq.length() - i);
		string front = seq.substr(seq.length() - i * 2, i);
		if (back == front) return false;
	}
	return true;
}

void solution(string seq,int length) {
	if (!is_bad(seq)) { return; }
	if (length == N) {
		cout << seq; exit(0);
	}
	solution(seq + '1', length + 1);
	solution(seq + '2', length + 1);
	solution(seq + '3', length + 1);

}

int main() {
	cin >> N;
	solution("", 0);
}