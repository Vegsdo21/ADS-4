// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    if (i > 0 && arr[i] == arr[i - 1]) continue;
    for (int j = i + 1; j < len; ++j) {
      if (j > i + 1 && arr[j] == arr[j - 1]) continue;
      int sum = arr[i] + arr[j];
      if (sum == value) {
        count++;
      } else if (sum > value) {
        break;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int left = 0;
  int right = len - 1;
  int count = 0;

  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      count++;
      int leftVal = arr[left];
      int rightVal = arr[right];
      while (left < right && arr[left] == leftVal) left++;
      while (left < right && arr[right] == rightVal) right--;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
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
