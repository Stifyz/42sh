#include "autocomplete.h"

int main(int ac, char**av)
{
  if(ac > 1)
    autocomplete(av[1]);
  return (0);
}
