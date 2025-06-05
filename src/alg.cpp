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

int findValue(int* arr, int left, int right, int key) {
  while (left <= right) {
    int mid = (left + right) >> 1;
    if (arr[mid] == key)
      return mid;
    else if (arr[mid] < key)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return -1;
}

int countPairs3(int* arr, int len, int value) {
  int pairs = 0;
  for (int i = 0; i < len - 1; ++i) {
    if (i > 0 && arr[i] == arr[i - 1]) continue;
    int complement = value - arr[i];
    int idx = findValue(arr, i + 1, len - 1, complement);
    if (idx != -1) {
      pairs++;
      while (idx + 1 < len && arr[idx] == arr[idx + 1]) idx++;
    }
  }
  return pairs;
}

