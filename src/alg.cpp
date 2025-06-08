// Copyright 2021 NNTU-CS
#include <algorithm>

int countPairs1(int *arr, int len, int value) {
  std::sort(arr, arr + len);
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
  std::sort(arr, arr + len);
  int l = 0, r = len - 1, count = 0;
  while (l < r) {
    int sum = arr[l] + arr[r];
    if (sum < value) {
      l++;
    } else if (sum > value) {
      r--;
    } else {
      if (arr[l] == arr[r]) {
        int n = r - l + 1;
        count += n * (n - 1) / 2;
        break;
      }
      int lv = arr[l], rv = arr[r];
      int cntL = 0, cntR = 0;
      while (l <= r && arr[l] == lv) {
        cntL++;
        l++;
      }
      while (r >= l && arr[r] == rv) {
        cntR++;
        r--;
      }
      count += cntL * cntR;
    }
  }
  return count;
}

int findFirst(int *arr, int left, int right, int target) {
  int pos = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] < target) {
      left = mid + 1;
    } else {
      if (arr[mid] == target) pos = mid;
      right = mid - 1;
    }
  }
  return pos;
}

int findLast(int *arr, int left, int right, int target) {
  int pos = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] > target) {
      right = mid - 1;
    } else {
      if (arr[mid] == target) pos = mid;
      left = mid + 1;
    }
  }
  return pos;
}

int countPairs3(int *arr, int len, int value) {
  std::sort(arr, arr + len);
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    int complement = value - arr[i];
    int first = findFirst(arr, i + 1, len - 1, complement);
    if (first != -1) {
      int last = findLast(arr, i + 1, len - 1, complement);
      count += (last - first + 1);
    }
  }
  return count;
}
