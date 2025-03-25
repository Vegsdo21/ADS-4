// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
    int result = 0;
    for (int firstIndex = 0; firstIndex < len - 1; firstIndex++) {
        for (int j = firstIndex + 1; j < len; j++) {
            if (arr[firstIndex] + arr[j] == value) {
                result++;
            }
        }
    }
    return result;
}

int countPairs2(int* arr, int len, int value) {
    int result = 0;
    for (int left = 0; left < len - 1; left++) {
        for (int right = len - 1; right > left; right--) {
            if (arr[left] + arr[right] == value) {
                result++;
            }
        }
    }
    return result;
}

int countPairs3(const int* arr, int len, int value) {
    int count = 0;
    int left = 0, right = len - 1;
    while (left < right) {
        int mainSum = arr[left] + arr[right];
        if (mainSum == value) {
            count++;
            left++;
            right--;
        } else if (mainSum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}
