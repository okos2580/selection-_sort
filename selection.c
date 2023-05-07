/*
�̸�:������
�й�:202210423
���α׷� ��:selection.c
���α׷� ��¥:2023.5.07(��)
���α׷� ����:���ù����˰���
*/
#define _CRT_SECURE_NO_WARNINGS
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
    FILE* inputFile = fopen("data.txt", "r");
    FILE* outputFile = fopen("result.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return 1;
    }

    int n;
    fscanf(inputFile, "%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }

    int k;
    fscanf(inputFile, "%d", &k);

    int result = select(arr, 0, n - 1, k - 1);
    fprintf(outputFile, "%d��°�� ���� ��: %d\n", k, result);

    fclose(inputFile);
    fclose(outputFile);
    free(arr);
    return 0;
}
