#include <iostream>
#include <cmath>
using namespace std;

int P[31][31]; // 배낭 무게가 최대 30이므로,, index 0은 사용하지 않음
int Weight; // 배낭 무게 

int knapsack(int n, int W[], int V[]) { // 보석의 개수, 무게 배열, 가치 배열
	int maximum = -1; // 가방에 담은 보석의 최대 가치를 나타냄
	for (int i = 1; i <= n; i++) { // 보석의 개수만큼 반복
		for (int w = 1; w <= Weight; w++) { // 배낭 무게만큼 반복
			if (W[i] <= w) { // 허용 무게를 넘지 않을 때
				P[i][w] = max(P[i - 1][w], V[i] + P[i - 1][w - W[i]]);
				// i번째 보석을 넣지 않았을 때와 넣었을 때를 비교하여 최댓값을 넣음
			}
			else { // 허용 무게를 초과하므로 보석을 넣지 않음
				P[i][w] = P[i - 1][w]; // i번째 보석을 넣지 않음
			}
			// p[i][w] = 처음부터 i번째의 물건을 탐색하고 배낭의 용량이 w일 때 배낭에 들어간 물건의 최대 가치
		}
	}

	return P[n][Weight];
	// 최댓값은 당연히 처음부터 끝까지 물건을 탐색하고 배낭의 용량이 Weight일 때의 P값
}
int main() {
	Weight = 15;
	int W1[7] = { 0,5,10,7,3,4,11 };
	int V1[7] = { 0,5,7,10,6,8,20 };

	cout << "입력 1에 대하여 가방에 담은 보석의 최대 가치 : " << knapsack(6, W1, V1) << endl;

	memset(P, 0, sizeof(P)); // 초기화

	Weight = 30;
	int W2[9] = { 0,3,7,8,5,6,13,11,2 };
	int V2[9] = { 0,5,7,10,6,8,20,18,5 };

	cout << "입력 2에 대하여 가방에 담은 보석의 최대 가치 : "<< knapsack(8, W2, V2);
}
