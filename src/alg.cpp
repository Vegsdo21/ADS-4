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

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int currIdx = 0; currIdx < len - 1; currIdx++) {
        int target = value - arr[currIdx];
        int left = currIdx + 1;
        int right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                count++;
                int leftCheck = mid - 1;
                while (leftCheck >= left && arr[leftCheck] == target) {
                    count++;
                    leftCheck--;
                }
                int rightCheck = mid + 1;
                while (rightCheck <= right && arr[rightCheck] == target) {
                    count++;
                    rightCheck++;
                }
                break;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return count;
}
