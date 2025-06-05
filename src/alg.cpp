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

int findValue(int *array, int left, int right, int key)
{
  while (left <= right)
  {
    int center = (left + right) >> 1;
    if (array[center] == key)
      return center;
    if (array[center] < key)
      left = center + 1;
    else
      right = center - 1;
  }
  return -1;
}

int countPairs3(int *input, int size, int target)
{
  int pairs = 0;
  for (int p = 0; p < size - 1; ++p)
  {
    int companion = target - input[p];
    int idx = findValue(input, p + 1, size - 1, companion);
    if (idx >= 0 && input[p] + input[idx] == target)
    {
      ++pairs;
    }
  }
  return pairs;
}
