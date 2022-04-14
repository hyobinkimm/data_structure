#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int next_[50];

void InitNext(const char* p) { // ���� ��Ī�� ���� ���� ��Ȳ���� ���λ�/���̻簡 ��ġ�� �ִ� ����
	int i, j, M = strlen(p);
	next_[0] = -1;
	
	for (i = 0, j = -1; i < M; i++, j++) {
		//next_[i] = j;
		next_[i] = (p[i] == p[j]) ? next_[j] : j;
		while (j >= 0 && p[i] != p[j]) {
			j = next_[j];
		}
	}
}


int KMP(const char* p, const char* t) {
	int M = strlen(p); int N = strlen(t);
	int i, j;
	InitNext(p); // next �迭 ���� (prefix, suffix)
	
	for (i = 0, j = 0; i < N && j < M; i++, j++) {
		while (j >= 0 && t[i] != p[j]) {
			j = next_[j]; // ������ ���س��� �迭���� �����ͼ� ���
		}
	}
	if (j == M) {
		return i - M; // index �����ؼ� ��ȯ
	}
	else {
		return i;
	}	
}

int main() {
	// while�� �ȿ��� KMP ���ƾߵ� �ε��� �Űܰ��鼭 ,,
	// �ε��� �������� while�� ���������� ,,

	const char* text_1 = "ababababcababababcaabbabababcaab";
	const char* pattern_1 = "abababca";
	const char* text_2 = "This class is an algorithm design class. Therefore, students will have time to learn about algorithms and implement each algorithm themselves.";
	const char* pattern_2 = "algorithm";
	
	int M = strlen(pattern_1); int N = strlen(text_1);
	int pos = 0; int index = 0; int previous = 0;
	cout << text_1 << endl;
	while (1) {
		pos = KMP(pattern_1, text_1 + index);
		pos += previous;
		index = pos + M;
		if (index <= N)printf("������ �߻��� ��ġ : %d\n", index - M);
		else break;
		previous = index;
	}

	M = strlen(pattern_2); N = strlen(text_2);
	cout << text_2 << endl;
	pos = 0; index = 0; previous = 0;
	while (1) {
		pos = KMP(pattern_2, text_2 + index);
		pos += previous;
		index = pos + M;
		if (index <= N)printf("������ �߻��� ��ġ :%d\n", index - M);
		else break;
		previous = index;
	}
	
}