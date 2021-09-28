#include <stdio.h>
#include <stdlib.h>
#include "names_st.h"

int main(void) {
  names *candidate = (names *)malloc(sizeof(names));

  get_names(candidate);
  show_names(candidate);

  free(candidate);

  return 0;
}