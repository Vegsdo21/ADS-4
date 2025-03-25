// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
  int result = 0;
  for (int first = 0; first < len - 1; first++) {
      for (int second = first + 1; second < len; second++) {
          if (arr[first] + arr[second] == value) {
              result += 1;
          }
      }
  }
  return result;
}

int countPairs2(int* arr, int len, int value) {
  int result = 0;
  for (int start = 0; start < len - 1; start++) {
      for (int end = len - 1; end > start; end--) {
          if (arr[start] + arr[end] == value) {
              result += 1;
          }
      }
  }
  return result;
}

int countPairs3(int* arr, int len, int value) {
  int total = 0;
  for (int index = 0; index < len - 1; index++) {
      int left = index + 1, right = len - 1;
      while (left <= right) {
          int middle = left + (right - left) / 2;
          if (arr[index] + arr[middle] == value) {
              total++;
              int forward = middle + 1;
              while (forward <= right &&
                     arr[index] + arr[forward] == value) {
                  total++;
                  forward++;
              }
              int backward = middle - 1;
              while (backward >= left &&
                     arr[index] + arr[backward] == value) {
                  total++;
                  backward--;
              }
              break;
          }
          if (arr[index] + arr[middle] > value) {
              right = middle - 1;
          } else {
              left = middle + 1;
          }
      }
  }
  return total;
}
