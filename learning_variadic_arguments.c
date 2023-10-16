#include <stdarg.h>
#include <stdio.h>

// va_start - initialise the vector, a va_list object that you can use to access each argument after the flag.
// va_arg - take the next argument.
// ap is a pointer but doesn't have *, because va_list is already defined as a pointer.

float average(int n, ...)
{
  va_list ap; //pointer to object that contain all info - argumment pointer. it's pointing to n.
  int total;
  int i;

  va_start(ap, n); // a macro, we want to skip the n, with the n we are saying how many arguments we have there.
  total = 0;
  i = 0;

  while (i < n)
  {
    total += va_arg(ap, int);
    i++;
  }
  return ((float)total / n);
}

int main()
{
  float average_age;
                      //this 5 is a flag and the other numbers are the actual arguments.
  average_age = average(5, 18, 45, 32, 100, 7);
  printf("the average age of those 5 people is %f\n", average_age);
}
