#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
Prints the sizes and possible ranges of four integer data types. 
*/
void print_int_ranges() {
  int short_bytes = sizeof(short); //utilizing 32 bit compiler
  int int_bytes = sizeof(int);
  int uint_bytes = sizeof(int);
  int long_bytes = sizeof(long);

  short short_min = -pow(2,short_bytes*8); //power defined in math.h header file. 
  short short_max = pow(2,short_bytes*8);
  int int_min = -(pow(2,int_bytes*8)/2);
  int int_max = (pow(2,int_bytes*8)/2)-1;
  unsigned int uint_min = 0;
  unsigned int uint_max = pow(2,int_bytes*8)-1;
  long long_min = 1L << long_bytes * 8 - 1;
  long long_max = ~long_min;

  // Keep these exact printf commands :)   
  printf("short is %d bytes or %d bits and ranges from %d to %d\n",
         short_bytes, short_bytes * 8, short_min, short_max);
  printf("int is %d bytes or %d bits and ranges from %d to %d\n",
         int_bytes, int_bytes * 8, int_min, int_max);
  printf("long is %d bytes or %d bits and ranges from %ld to %ld\n",
         long_bytes, long_bytes * 8, long_min, long_max);
  printf("unsigned int is %d bytes or %d bits and ranges from %u to %u\n",
         uint_bytes, uint_bytes * 8, uint_min, uint_max);
}

/*
Takes in an integer value v and a integer bit index i
Returns 1 if bit i in value v equals 1
Returns 0 if bit i in value v equals 0
*/
int is_bit_set(unsigned char v, unsigned char i) { 
  int V;
  if (i >= sizeof(unsigned char) * 8) {
    fprintf(stderr, "Index out of range!\n");
    return 0;
  }
  V = v >> (i - 1); //right shift so the indexed number is at the end
  if (V % 2 == 1) // odd numbers end in 1 in binary, even numbers end in 0
  {
    return 1; //if 1 is the last digit, then after right shift, 1 must have been at the indexed place
  }
  else 
  {
    return 0; //if 0 is the last digit, then after right shift, 0 must have been at the indexed place
  }
}  
/*
Don't touch anything in main!
*/
int main(int argc, char* argv[])
{
  if (argc < 3) {
    fprintf(stderr, "Not enough arguments!\n");
    return -1;  
  }

  print_int_ranges();
  
  unsigned char value = atoi(argv[1]);
  unsigned char bit = atoi(argv[2]);
  int is_set = is_bit_set(value, bit);
  switch(is_set) {
    case 1:
      printf("Bit %u in value %u is set\n", bit, value);
      break;
    case 0:
      printf("Bit %u in value %u is not set\n", bit, value);
      break;
    default:
      fprintf(stderr, "is_bit_set returned an invalid value!\n");
  } 
  
  return 0;
}

