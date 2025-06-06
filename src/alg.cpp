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

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    if (i > 0 && arr[i] == arr[i - 1]) continue;
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    int low = -1, l = left, r = right;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (arr[m] < target)
        l = m + 1;
      else {
        if (arr[m] == target)
          low = m;
        r = m - 1;
      }
    }
    if (low == -1) continue;
    int high = low, l2 = low, r2 = right;
    while (l2 <= r2) {
      int m = l2 + (r2 - l2) / 2;
      if (arr[m] > target)
        r2 = m - 1;
      else {
        if (arr[m] == target)
          high = m;
        l2 = m + 1;
      }
    }
    count += (high - low + 1);
  }
  return count;
}
