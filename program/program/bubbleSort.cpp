#include<iostream>
using namespace std;
void bubbleSort(int* arr,int n);
int main() {
	int n;
	cout << "Enter the number of elements" << endl;
	cin >> n;
	cout << "input element" << endl;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		int k;
		cin>>k;
		arr[i] = k;
	}
	bubbleSort(arr,n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	delete arr;
	return 0;
}
void bubbleSort(int* arr,int len) {
	for (int i = 0; i < len-1; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}