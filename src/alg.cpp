int countPairs1(int* numbers, int length, int target) {
  int pairCount = 0;
  for (int first = 0; first < length - 1; first++) {
    for (int second = first + 1; second < length; second++) {
      if (numbers[first] + numbers[second] == target) {
        pairCount += 1;
      }
    }
  }
  return pairCount;
}

int countPairs2(int* numbers, int length, int target) {
  int pairCount = 0;
  for (int first = 0; first < length - 1; first++) {
    for (int second = length - 1; second > first; second--) {
      if (numbers[first] + numbers[second] == target) {
        pairCount += 1;
      }
    }
  }
  return pairCount;
}

int countPairs3(int* numbers, int length, int target) {
  int pairCount = 0;
  for (int first = 0; first < length - 1; first++) {
    int left = first, right = length;
    while (1 < right - left) {
      int middle = (left + right) / 2;
      if (numbers[first] + numbers[middle] == target) {
        pairCount++;
        int next = middle + 1;
        while (numbers[first] + numbers[next] == target && next < right) {
          pairCount++;
          next++;
        }
        next = middle - 1;
        while (numbers[first] + numbers[next] == target && next > left) {
          pairCount++;
          next--;
        }
        break;
      }
      if (numbers[first] + numbers[middle] > target) {
        right = middle;
      } else {
        left = middle;
      }
    }
  }
  return pairCount;
}
