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
    int left = i + 1;
    int right = len - 1;
    int target = value - arr[i];
    while (left <= right) {
      int mid = (left + right) / 2;
      if (arr[mid] == target) {
        count++;
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
