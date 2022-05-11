void BinarySearch(int start, int end, int key) {
	if (start > end) {
		return;
	}

	int mid = (start + end) / 2; // 반갈

	if (A[mid] == key) { // 찾았으면
		printf("%d",A[mid]);
		return;
	}
	else if (A[mid] > key) {
		return BinarySearch(start, mid-1, key);
	}
	else {
		return BinarySearch(mid+1, end, key);
	}
}
