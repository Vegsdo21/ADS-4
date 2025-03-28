// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int totalPairs = 0;
    for (int idx1 = 0; idx1 < len; ++idx1) {
        for (int idx2 = idx1 + 1; idx2 < len; ++idx2) {
            if (arr[idx1] + arr[idx2] == value) {
                totalPairs++;
            }
        }
    }
    return totalPairs;
  }
  
  int countPairs2(int* arr, int len, int value) {
    int totalPairs = 0;
    int upperLimit = len - 1;
    while (upperLimit > 0 && arr[upperLimit] > value) {
        upperLimit--;
    }
    for (int lowerIdx = 0; lowerIdx < len; lowerIdx++) {
        for (int upperIdx = upperLimit; upperIdx > lowerIdx; upperIdx--) {
            if (arr[lowerIdx] + arr[upperIdx] == value) {
                totalPairs++;
            }
        }
    }
    return totalPairs;
  }
  
  int locateFirstOccurrence(int* arr, int start, int end, int key) {
    int position = -1;
    while (start <= end) {
        int midpoint = start + (end - start) / 2;
        if (arr[midpoint] == key) {
            position = midpoint;
            end = midpoint - 1;
        } else if (arr[midpoint] < key) {
            start = midpoint + 1;
        } else {
            end = midpoint - 1;
        }
    }
    return position;
  }
  
  int locateLastOccurrence(int* arr, int start, int end, int key) {
    int position = -1;
    while (start <= end) {
        int midpoint = start + (end - start) / 2;
        if (arr[midpoint] == key) {
            position = midpoint;
            start = midpoint + 1;
        } else if (arr[midpoint] < key) {
            start = midpoint + 1;
        } else {
            end = midpoint - 1;
        }
    }
    return position;
  }
  
  int countPairs3(int* arr, int len, int value) {
    int totalPairs = 0;
    for (int idx = 0; idx < len; idx++) {
        int compl = value - arr[idx];
        int firstIdx = locateFirstOccurrence(arr, idx + 1, len - 1, compl);
        if (firstIdx != -1) {
            int lastIdx = locateLastOccurrence(arr, idx + 1, len - 1, compl);
            totalPairs += (lastIdx - firstIdx + 1);
        }
    }
    return totalPairs;
  }
