/*
�̸�:������
�й�:202210423
���α׷� ��:selection.c
���α׷� ��¥:2023.5.07(ȭ)
���α׷� ����:���ù����˰���
*/
#include <stdio.h>
#include <stdlib.h>

// �迭�� ���Ҹ� ��ȯ�ϴ� �Լ�
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// �迭�� �Ǻ��� �������� �����ϴ� �Լ�
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

// ���� ���� �˰����� ����Ͽ� ���� ������ �ذ��ϴ� �Լ�
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
    printf("�迭�� ũ�⸦ �Է��ϼ���: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    printf("�迭�� ��Ҹ� �Է��ϼ���: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    printf("ã���� �ϴ� k��° ���� ���� �Է��ϼ���: ");
    scanf("%d", &k);

    int result = select(arr, 0, n - 1, k - 1);
    printf("%d��°�� ���� ��: %d\n", k, result);

    free(arr);
    return 0;
}

