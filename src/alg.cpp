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
  int left = 0, right = len - 1, count = 0;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      count++;
      int lv = arr[left], rv = arr[right];
      while (left < right && arr[left] == lv) left++;
      while (left < right && arr[right] == rv) right--;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int BinarySearch(int* arr, int left, int right, int value) {
  int first = -1, _left = left, _right = right;
  while (_left <= _right) {
    int mid = _left + (_right - _left) / 2;
    if (arr[mid] >= value) {
      _right = mid - 1;
      if (arr[mid] == value) first = mid;
    } else {
      _left = mid + 1;
    }
  }
  if (first == -1) return 0;
  int last = first;
  _left = first;
  _right = right;
  while (_left <= _right) {
    int mid = _left + (_right - _left) / 2;
    if (arr[mid] <= value) {
      _left = mid + 1;
      if (arr[mid] == value) last = mid;
    } else {
      _right = mid - 1;
    }
  }
  return last - first + 1;
}

int countPairs3(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    if (i > 0 && arr[i] == arr[i - 1]) continue;
    int complement = value - arr[i];
    count += BinarySearch(arr, i + 1, len - 1, complement);
  }
  return count;
}
