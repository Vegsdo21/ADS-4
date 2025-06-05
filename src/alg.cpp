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
int countPairs2(int *sequence, int count, int desired)
{
    int leftPos = 0;
    int rightPos = count - 1;
    int foundPairs = 0;

    while (leftPos < rightPos)
    {
        int total = sequence[leftPos] + sequence[rightPos];

        if (total == desired)
        {
            foundPairs++;
            leftPos++;
            rightPos--;
        }
        else
        {
            (total < desired) ? leftPos++ : rightPos--;
        }
    }

    return foundPairs;
}

int countPairs3(int *arr, int len, int value) {
  return 0;
}
