// all important header files needed

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *myconcat(int n, ...) {
  // we cannot have a n argument that is 0 or a neg number otherwise NULL
  if (n <= 0) {
    return NULL;
  }

  // start va_list to store the chars incoming
  va_list args;
  va_start(args, n);

  // src will be what we return. Return null if nothing given.
  // len is how much the size of src is
  char *src = NULL;
  int len = 0;

  // loop through each argument and stop evebtually
  for (int i = 0; i < n; i++) {
    // read each va-argument given and store in str
    char *str = va_arg(args, char *);

    // make sure str is not null, otherwise free src and return a NULL
    if (str == NULL) {
      va_end(args);
      free(src);
      return NULL;
    }

    // slen is the size of the new char that is going to be put in
    int slen = strlen(str);
    // we reallocate a temporary holding block for src to add the new char
    char *temp = realloc(src, len + slen + 1);
    // just making sure temp is not NULL (now argument is given)
    if (temp == NULL) {
      va_end(args);
      free(src);
      return NULL;
    }

    // if it is not NULL, we add the str to src, as we've already reallocated memory
    src = temp;
    strcpy(src + len, str);
    len += slen;
  }

  // end args and return the concated string
  va_end(args);
  return src;
}
