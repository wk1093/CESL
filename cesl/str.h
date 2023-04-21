#include "arr.h"
#include "ceslimpl.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// CESL (C Extended Standard Library) String Manipulation Utilities

ceslf(bool endswith(char *str, char *suffix), {
    return ((strlen(str) > strlen(suffix)) &&
            (strcmp(str + strlen(str) - strlen(suffix), suffix) == 0));
});

ceslf(struct StringArray *split_c(const char *stri, char delim),
      { // split by char
          struct StringArray *sa = newStringArray();
          char *str = (char *)malloc(sizeof(char *) * strlen(stri));
          strcpy(str, stri);
          char deliminer[] = {delim};

          char *tok = strtok(str, deliminer);

          while (tok != NULL) {
              sa->push(sa, tok);
              tok = strtok(NULL, " ");
          }
          return sa;
      });

ceslf(struct StringArray *split_cs(const char *stri, const char *delims),
      { // split by chars
          struct StringArray *sa = newStringArray();
          char *str = (char *)malloc(sizeof(char *) * strlen(stri));
          strcpy(str, stri);

          char *tok = strtok(str, delims);

          while (tok != NULL) {
              sa->push(sa, tok);
              tok = strtok(NULL, delims);
          }
          return sa;
      });

ceslf(struct StringArray *split_s(const char *stri, const char *delim),
      { // split by string
          if (strlen(delim) == 1) {
              return split_c(stri, delim[0]);
          }

          struct StringArray *sa = newStringArray();
          char *str = (char *)malloc(sizeof(char *) * strlen(stri));
          strcpy(str, stri);

          int start = 0;
          int end = 0;
          int delim_len = strlen(delim);
          int str_len = strlen(str);

          while (end < str_len) {
              if (strncmp(str + end, delim, delim_len) == 0) {
                  // we found a delim
                  // copy the string from start to end
                  char *substr =
                      (char *)malloc(sizeof(char) * (end - start + 1));
                  strncpy(substr, str + start, end - start);
                  substr[end - start] = '\0';
                  sa->push(sa, substr);
                  start = end + delim_len;
                  end = start;
              } else {
                  end++;
              }

              if (end == str_len) {
                  // we reached the end of the string
                  // copy the string from start to end
                  char *substr =
                      (char *)malloc(sizeof(char) * (end - start + 1));
                  strncpy(substr, str + start, end - start);
                  substr[end - start] = '\0';
                  sa->push(sa, substr);
              }
          }

          for (int i = 0; i < sa->size; i++) {
              if (strlen(sa->get(sa, i)) == 0) {
                  sa->remove(sa, i);
                  i--;
              }
          }

          return sa;
      });

// split by strings
ceslf(struct StringArray *split_ss(const char *stri,
                                   struct StringArray *delims),
      {
          // same as split_s but split by either of the delims
          struct StringArray *sa = newStringArray();
          char *str = (char *)malloc(sizeof(char *) * strlen(stri));
          strcpy(str, stri);

          int start = 0;
          int end = 0;
          int str_len = strlen(str);

          while (end < str_len) {
              bool found = false;
              for (int i = 0; i < delims->size; i++) {
                  char *delim = delims->get(delims, i);
                  int delim_len = strlen(delim);
                  if (strncmp(str + end, delim, delim_len) == 0) {
                      // we found a delim
                      // copy the string from start to end
                      char *substr =
                          (char *)malloc(sizeof(char) * (end - start + 1));
                      strncpy(substr, str + start, end - start);
                      substr[end - start] = '\0';
                      sa->push(sa, substr);
                      start = end + delim_len;
                      end = start;
                      found = true;
                      break;
                  }
              }
              if (!found) {
                  end++;
              }

              if (end == str_len) {
                  // we reached the end of the string
                  // copy the string from start to end
                  char *substr =
                      (char *)malloc(sizeof(char) * (end - start + 1));
                  strncpy(substr, str + start, end - start);
                  substr[end - start] = '\0';
                  sa->push(sa, substr);
              }
          }

          for (int i = 0; i < sa->size; i++) {
              if (strlen(sa->get(sa, i)) == 0) {
                  sa->remove(sa, i);
                  i--;
              }
          }

          return sa;
      });

ceslf(char *replace_c2c(const char *stri, char from, char to),
      { // replace char with char
          char *str = (char *)malloc(sizeof(char *) * strlen(stri));
          strcpy(str, stri);
          for (int i = 0; i < strlen(str); i++) {
              if (str[i] == from) {
                  str[i] = to;
              }
          }
          return str;
      });
ceslf(char *replace_cs2c(const char *stri, const char *from, char to),
      { // replace chars with char
          char *str = (char *)malloc(sizeof(char *) * strlen(stri));
          strcpy(str, stri);
          for (int i = 0; i < strlen(str); i++) {
              if (strncmp(str + i, from, strlen(from)) == 0) {
                  str[i] = to;
              }
          }
          return str;
      });
ceslf(char *replace_c2s(const char *stri, char from, const char *to),
      { // replace char with string
          struct CharArray *ca = newCharArray();

          for (int i = 0; i < strlen(stri); i++) {
              if (stri[i] == from) {
                  for (int j = 0; j < strlen(to); j++) {
                      ca->push(ca, to[j]);
                  }
              } else {
                  ca->push(ca, *stri + i);
              }
          }
          return ca->data;
      });
ceslf(char *replace_cs2s(const char *stri, const char *from, const char *to),
      { // replace chars
        // with string
          struct CharArray *ca = newCharArray();

          for (int i = 0; i < strlen(stri); i++) {
              if (strncmp(stri + i, from, strlen(from)) == 0) {
                  for (int j = 0; j < strlen(to); j++) {
                      ca->push(ca, to[j]);
                  }
                  i += strlen(from) - 1;
              } else {
                  ca->push(ca, *stri + i);
              }
          }
          return ca->data;
      });
// replace string with string
ceslf(char *replace_s2s(const char *stri, const char *from, const char *to), {
    struct CharArray *ca = newCharArray();

    for (int i = 0; i < strlen(stri); i++) {
        if (strncmp(stri + i, from, strlen(from)) == 0) {
            for (int j = 0; j < strlen(to); j++) {
                ca->push(ca, to[j]);
            }
            i += strlen(from) - 1;
        } else {
            ca->push(ca, *stri + i);
        }
    }
    return ca->data;
});

ceslf(char *remove_c(const char *stri, char c), {
    struct CharArray *ca = newCharArray();
    for (int i = 0; i < strlen(stri); i++) {
        if (stri[i] != c) {
            ca->push(ca, stri[i]);
        }
    }
    return ca->data;
});

ceslf(char *remove_s(const char *stri, const char *s), {
    struct CharArray *ca = newCharArray();
    for (int i = 0; i < strlen(stri); i++) {
        if (strncmp(stri + i, s, strlen(s)) != 0) {
            ca->push(ca, stri[i]);
        } else {
            i += strlen(s) - 1;
        }
    }
    return ca->data;
});

ceslf(char *append_s(const char *stri, const char *s), {
    char *str = (char *)malloc(sizeof(char *) * (strlen(stri) + strlen(s) + 1));
    strcpy(str, stri);
    strcat(str, s);
    return str;
});
