#include <stdio.h>

int main (void)

{
  int sample[5] = {55, 7, 78, 12, 42};	// array of samples to be sorted
  
  // some variable taken for the process
  int i = 0;
  int j = 0;
  int n = 0;
  int swap = 0;
  
  // printing the values in the sample array
  for(n = 0; n < 5; n++)
  {
    printf("%d ", sample[n]);
  }
  
  // sorting process occurs here
  // it checks the current number/position and next number/position in the array until all the values have been sorted
  // logic : if current number/position is bigger than the next number/position, then swap otherwise next number/position becomes current number/position
  
  for(i = 0; i < n - 1; i++)
  {
    for(j = 0; j < n - i - 1; j++ )
    {
		if(sample[j] > sample[j+1])
        {
          swap = sample[j];
          sample[j] = sample[j+1];
          sample[j+1] = swap;
        }
    }
  }


printf("\n");
	
  // print the sorted values in the sample array
  
  for(n = 0; n < 5; n++)
  {
    printf("%d ", sample[n]);
  }

  return 0;
}

