#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct nodetype {
	string symbol;
	int frequency;
	nodetype* left;
	nodetype* right;
};

//pq <자료형, 구조체(벡터), 비교연산자>

struct compare {
	bool operator()(nodetype* a, nodetype* b) {
		return a->frequency > b->frequency;
	}
};

void display(nodetype* p, string s) {
	if (p) {
		if (p->symbol!="~") { cout << p->symbol << " : " << s << endl; }
		display(p->left, s + "0");
		display(p->right, s + "1");
	}
}

string data1[] = { "Z","A","B","C","D","E","F" };
int freq1[] = { 27,15,12,9,5,10,11 };
string data2[] = { "Z","ABC","ABCC","AB","A","B","BABA" };
int freq2[] = { 27,12,7,19,35,40,15 };

void Huffman(string data[], int freq[], int size) {
	priority_queue <nodetype*, vector<nodetype*>, compare> pq;
	for (int i = 0; i < size; i++) {
		pq.push(new nodetype{ data[i], freq[i] });
	}

	for (int i = 0; i < size - 1; i++) {
		nodetype* p = pq.top();
		pq.pop();
		nodetype* q = pq.top();
		pq.pop();
		nodetype* r = new nodetype{ "~", p->frequency + q->frequency };
		r->left = p;
		r->right = q;
		r->frequency = p->frequency + q->frequency;
		pq.push(r);
	}
	display(pq.top(), "");
}

int main() {
	//ex1;
	for (int i = 0; i < 7; i++) {
		cout << "| " << data1[i] << ", " << freq1[i] << " |";
	}
	printf("\n");
	Huffman(data1, freq1, 7);
	
	//ex2
	printf("\n");
	for (int i = 0; i < 7; i++) {
		cout << "| " << data2[i] << ", " << freq2[i] << " |";
	}
	printf("\n");
	Huffman(data2, freq2, 7);
}