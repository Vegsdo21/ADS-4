// Copyright 2021 NNTU-CS
int countPairs1(int *numbers, int size, int targetSum)
{
  int matchCount = 0;
  for (int outer = 0; outer < size; ++outer)
  {
    for (int inner = outer + 1; inner < size; ++inner)
    {
      int currentSum = numbers[outer] + numbers[inner];
      if (currentSum == targetSum)
      {
        matchCount++;
      }
      else if (currentSum > targetSum)
      {
        break;
      }
    }
  }
  return matchCount;
}
int countPairs2(int *arr, int len, int value) {
  return 0;
}
int countPairs3(int *arr, int len, int value) {
  return 0;
}
