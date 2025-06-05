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
        for (int upperIdx = upperLimit;
             upperIdx > lowerIdx; upperIdx--) {
            if (arr[lowerIdx] + arr[upperIdx] == value) {
                totalPairs++;
            }
        }
    }
    return totalPairs;
}

int findBound(int* arr, int left, int right, int target, bool searchFirst) {
  while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] < target) {
      left = mid + 1;
    } else if (arr[mid] > target) {
      right = mid - 1;
    } else {
      if (searchFirst) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
  }
  return searchFirst ? left : right;
}

int countPairs3(int* arr, int len, int value) {
  int total = 0;
  for (int i = 0; i < len - 1; ++i) {
    if (i > 0 && arr[i] == arr[i - 1]) continue;
    int complement = value - arr[i];
    int firstIdx = findBound(arr, i + 1, len - 1, complement, true);
    int lastIdx = findBound(arr, i + 1, len - 1, complement, false);
    if (firstIdx <= lastIdx && firstIdx < len && arr[firstIdx] == complement && arr[lastIdx] == complement) {
      total += (lastIdx - firstIdx + 1);
    }
  }
  return total;
}
