// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int pairCounter = 0;
  for (int first = 0; first < len; ++first) {
      for (int second = first + 1; second < len; ++second) {
          if (arr[first] + arr[second] == value) {
              pairCounter++;
          }
      }
  }
  return pairCounter;
}

int countPairs2(int* arr, int len, int value) {
  int pairCounter = 0;
  int rightBound = len - 1;
  while (rightBound > 0 && arr[rightBound] > value) {
      rightBound--;
  }
  for (int left = 0; left < len; left++) {
      for (int right = rightBound; right > left; right--) {
          if (arr[left] + arr[right] == value) {
              pairCounter++;
          }
      }
  }
  return pairCounter;
}

int countPairs3(int* arr, int len, int value) {
  int pairCounter = 0;
  for (int index = 0; index < len; index++) {
      int searchVal = value - arr[index];
      int left = index + 1, right = len - 1, lower = -1, upper = -1;
      while (left <= right) {
          int mid = left + (right - left) / 2;
          if (arr[mid] >= searchVal) {
              right = mid - 1;
              if (arr[mid] == searchVal) lower = mid;
          } else {
              left = mid + 1;
          }
      }
      if (lower == -1) continue;
      left = lower;
      right = len - 1;
      while (left <= right) {
          int mid = left + (right - left) / 2;
          if (arr[mid] <= searchVal) {
              left = mid + 1;
              if (arr[mid] == searchVal) upper = mid;
          } else {
              right = mid - 1;
          }
      }
      pairCounter += (upper - lower + 1);
  }
  return pairCounter;
}
