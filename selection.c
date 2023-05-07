/*
이름:김태정
학번:202210423
프로그램 명:selection.c
프로그램 날짜:2023.5.07(화)
프로그램 설명:선택문제알고리즘
*/
#include <stdio.h>
#include <stdlib.h>

// 배열의 원소를 교환하는 함수
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 배열을 피봇을 기준으로 분할하는 함수
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// 분할 정복 알고리즘을 사용하여 선택 문제를 해결하는 함수
int select(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivotIndex = partition(arr, low, high);

    if (k == pivotIndex) {
        return arr[k];
    }
    else if (k < pivotIndex) {
        return select(arr, low, pivotIndex - 1, k);
    }
    else {
        return select(arr, pivotIndex + 1, high, k);
    }
}

int main() {
    int n;
    printf("배열의 크기를 입력하세요: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    printf("배열의 요소를 입력하세요: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    printf("찾고자 하는 k번째 작은 값을 입력하세요: ");
    scanf("%d", &k);

    int result = select(arr, 0, n - 1, k - 1);
    printf("%d번째로 작은 값: %d\n", k, result);

    free(arr);
    return 0;
}

