#include "my_string.h"
/**
 * @brief my_strlen
 * function calculates the length of a given string
 * @param str: It represents the string variable whose length we have to find.
 * @return my_size_t: This function returns the length of string passed.
 */
my_size_t my_strlen(const char *str) {
  my_size_t count = 0;
  if (str) {
    for (; *str; str++) {
      count++;
    }
  }
  return count;
}
/**
 * @brief my_strcpy
 * Function is used to copy one string to another
 * @param dest: Pointer to the destination array where the content is to be
 * copied.
 * @param src: string which will be copied.
 * @return char*: After copying the source string to the destination string, the
 * strcpy() function returns a pointer to the destination string.
 */
char *my_strcpy(char *dest, const char *src) {
  my_size_t number = 0;
  my_size_t n = my_strlen(src) + 1;  // fxd
  for (number = 0; number < n; number++) {
    dest[number] = src[number];
  }
  return dest;
}

/**
 * @brief my_strncpy
 * The strncpy() function is similar to strcpy() function, except that at most n
 * bytes of src are copied. If there is no NULL character among the first n
 * character of src, the string placed in dest will not be NULL-terminated.
 * @param dest: Pointer to the destination array where the content is to be
 * copied.
 * @param src: The string which will be copied.
 * @param n: The first n character copied from src to dest.
 * @return char*: It returns a pointer to the destination string.
 */
char *my_strncpy(char *dest, const char *src, my_size_t n) {
  my_size_t num = 0;
  my_size_t x = my_strlen(src) + 1;  // fxd
  for (num = 0; num < n && num < x; num++) {
    dest[num] = src[num];
  }
  for (; num < n; num++) {
    dest[num] = '\0';
  }
  return dest;
}

/**
 * @brief my_strchr
 * Function finds the first occurrence of a character in a string. The character
 * c can be the null character (\0); the ending null character of string is
 * included in the search.
 * @param str: specifies the pointer to the null terminated string to be
 * searched for.
 * @param c: specifies the character to be search for.
 * @return char*: function returns a pointer to the first occurrence of c that
 * is converted to a character in string. The function returns NULL if the
 * specified character is not found.
 */
char *my_strchr(const char *str, int c) {
  char *result = MY_NULL;
  my_size_t s1 = my_strlen(str) + 1;  // fxd
  while (s1) {
    if (*str == c) {
      result = (char *)str;
      break;
    }
    s1--;
    str++;
  }
  return result;
}
/**
 * @brief my_strrchr
 * function locates the last occurrence of a character in a string.
 * It returns a pointer to the last occurrence in the string. The terminating
 * null character is considered part of the C string.
 * @param str: specifies the pointer to the null terminated string to be
 * searched for.
 * @param c: specifies the character to be search for.
 * @return char*: The function returns a pointer to the last location of C in
 * string, if the C is found. If not found, it returns a null pointer.
 */
char *my_strrchr(const char *str, int c) {
  char *result = MY_NULL;
  my_size_t rev = my_strlen(str);
  char *k = (char *)str + rev;
  while (k >= str) {
    if (*k == c) {
      result = k;
      break;
    }
    k--;
  }
  return result;
}
/**
 * @brief my_strpbrk
 * This function finds the first character in the string s1 that matches any
 * character specified in s2 (It excludes terminating null-characters).
 * @param str1: string to be scanned.
 * @param str2: string containing the characters to match.
 * @return char*: It returns a pointer to the character in str1 that
 * matches one of the characters in str2, else returns NULL.
 */
char *my_strpbrk(const char *str1, const char *str2) {
  char *res = MY_NULL;
  char *temp = (char *)str1;
  while (*temp) {
    if (my_strchr(str2, *temp)) {
      res = temp;
      break;
    }
    temp++;
  }
  return res;
}
/**
 * @brief my_strcat
 * This function appends the string pointed to by src to the end of the string
 * pointed to by dest. It will append a copy of the source string in the
 * destination string. plus a terminating Null character. The initial character
 * of the string(src) overwrites the Null-character present at the end of the
 * string(dest).
 * @param dest: This is a pointer to the destination array, which should contain
 * a C string, and should be large enough to contain the concatenated resulting
 * string.
 * @param src: This is the string to be appended. This should not overlap the
 * destination.
 * @return char*: The strcat() function returns dest, the pointer to the
 * destination string.
 */
char *my_strcat(char *dest, const char *src) {
  my_strcpy(dest + my_strlen(dest), src);
  return dest;
}
/**
 * @brief my_strncat
 * This function appends not more than n characters from the string pointed to
 * by src to the end of the string pointed to by dest plus a terminating
 * Null-character. The initial character of the string(src) overwrites the
 * Null-character present at the end of a string(dest). Thus, the length of the
 * string(dest) becomes strlen(dest)+n. But, if the length of the string(src) is
 * less than n, only the content up to the terminating null-character is copied
 * and the length of the string(dest) becomes strlen(src) + strlen(dest).
 * @param dest: the string where we want to append.
 * @param src: the string from which ‘n’ characters are going to append.
 * @param n: represents a maximum number of characters to be appended. size_t is
 * an unsigned integral type.
 * @return char*: The strncat() function shall return the pointer to the
 * string(dest).
 */
char *my_strncat(char *dest, const char *src, my_size_t n) {
  my_strncpy(dest + my_strlen(dest), src, n);
  return dest;
}
/**
 * @brief my_strspn
 * function returns the length of the initial substring of the string pointed to
 * by str1 that is made up of only those character contained in the string
 * pointed to by str2.
 * @param str1: string to be scanned.
 * @param str2: string containing the characters to match.
 * @return my_size_t: This functionreturns the number of charactersin the
 * initial segment of str1 which consist only of characters from str2.
 */
my_size_t my_strspn(const char *str1, const char *str2) {
  my_size_t i, j;
  int flag = 0;
  my_size_t res = 0;
  for (i = 0; str1[i] != '\0'; i++) {
    for (j = 0; str2[j] != str1[i]; j++) {
      if (str2[j] == '\0') {
        flag = 1;
        break;
      }
    }
    res++;
    if (flag == 1) {
      res = i;
      break;
    }
  }
  return res;
}
/**
 * @brief my_strtok
 * The function is used in tokenizing a string based on a delimiter.
 * @param str: Pointer to input string.
 * @param sep: Pointer to delimeter, it used for delim the string in selected
 * position.
 * @return char*: Returns a pointer to the next token if present, if the next
 * token is not present it returns NULL.
 */
char *my_strtok(char *str, const char *sep) {
  static char *buffer;
  char *token = MY_NULL;
  if (str) {
    buffer = str;
    while (*buffer && my_strchr(sep, *buffer)) {
      *buffer++ = '\0';
    }
  }
  if (buffer && *buffer) {
    str = buffer;
    while (*buffer && !my_strchr(sep, *buffer)) {
      ++buffer;
    }
    while (*buffer && my_strchr(sep, *buffer)) {
      *buffer++ = '\0';
    }
    token = str;
  }
  return token;
}
/**
 * @brief my_strstr
 * This function takes two strings s1 and s2 as an argument and finds the first
 * occurrence of the sub-string s2 in the string s1.
 * @param haystack: This is the main string to be examined.
 * @param needle: This is the sub-string to be searched in haystack string.
 * @return char*: This function returns a pointer points to the first character
 * of the found needle in haystack otherwise a null pointer if needle is not
 * present in haystack. If s2 points to an empty string, s1 is returned.
 */
char *my_strstr(const char *haystack, const char *needle) {
  char *str = MY_NULL;
  if (my_strlen(needle) == 0) {
    str = (char *)haystack;
  } else {
    while (*haystack) {
      if (*haystack == *needle) {
        char *p_str = (char *)haystack;
        char *pp_str = (char *)needle;
        while (*pp_str && *p_str == *pp_str &&
               my_strlen(haystack) >= my_strlen(needle)) {
          pp_str++;
          p_str++;
        }
        if (*pp_str == '\0') {
          str = (char *)haystack;
          break;
        }
      }
      haystack++;
    }
  }
  return str;
}
/**
 * @brief my_memcmp
 * Function is used to copy a block of data from a source address to a
 * destination address.
 * @param str1: Pointer to block of memory.
 * @param str2: Pointer to block of memory.
 * @param n: Maximum numbers of bytes to compare.
 * @return int: it returns an integer.
 */
int my_memcmp(const void *str1, const void *str2, my_size_t n) {
  char *first = (char *)str1;
  char *second = (char *)str2;
  my_size_t i;
  int result = 0;
  for (i = 0; i < n; i++) {
    if (*first != *second) {
      result = *first - *second;
      break;
    }
    first++;
    second++;
  }
  return result;
}
/**
 * @brief my_memchr
 * Function which will search for the first occurrence of a character in a
specified number of characters
 * @param str Pointer to the object to be searched for
 * @param c Character to search for
 * @param n Number of character to be searched for
 * @return void* If the character is found, the memchr() function returns a
pointer to the location of the character, otherwise returns null pointer
 */
void *my_memchr(const void *str, int c, my_size_t n) {
  my_size_t i;
  char *s1 = (char *)str;
  void *result = MY_NULL;
  my_size_t x = my_strlen(str) + 1;  // fxd
  for (i = 0; i < n && i < x; i++) {
    if (*(s1 + i) == c) {
      result = (void *)(s1 + i);
      break;
    }
  }
  return result;
}
/**
 * @brief my_numcount
 * calculates number of digits.
 * @param n: input digit.
 * @return int: returns number of symbols in digit.
 */
int my_numcount(int n) {
  int result = 0;
  while (n) {
    n /= 10;
    result++;
  }
  return result;
}
/**
 * @brief my_capacity
 * calculates digit capacity
 * @param n: number of symbols by previous func.
 * @return int: returns digit capacity.
 */
int my_capacity(int n) {
  int result = 1;
  for (int i = 0; i < n - 1; i++) {
    result *= 10;
  }
  return result;
}
/**
 * @brief my_segmentation
 * segmentation code number to capacity
 * @param str
 * @param c
 */
void my_segmentation(char *str, char c) {
  str += my_strlen(str);
  *str = c;
  str++;
  *str = '\0';
}
/**
 * @brief add_digit_to_str
 * return unknown error when stdin input was incorrect
 * @param str
 * @param digit
 * @return char*: return string with number of error;
 */
char *add_digit_to_str(char *str, int digit) {
  char *s1 = str;
  while (*str != ' ') str++;
  ++str;
  while (*str != ' ') str++;
  *(++str) = '\0';
  int c = my_numcount(digit);
  if (digit < 0) {
    my_segmentation(str, '-');
    digit *= -1;
  }
  c = my_capacity(c);
  while (c) {
    char sym = digit / c + '0';
    my_segmentation(str, sym);
    digit %= c;
    c /= 10;
  }
  return s1;
}
/**
 * @brief my_strerror
 * Function gives some errors by their numbers.
 * @param errnum: number of error.
 * @return char*: returns text of error.
 */
char *my_strerror(int errnum) {
  err;
  static char *itog;
#if __APPLE__
#define STR_ERR_STR static char std_error[50] = "Unknown error: "
#elif __linux__
#define STR_ERR_STR static char std_error[50] = "Unknown error "
#endif
  if (errnum < 0 || errnum > err_count) {
    STR_ERR_STR;
    itog = add_digit_to_str(std_error, errnum);
  } else {
    itog = (char *)errlist[errnum];
  }
  return itog;
}
/**
 * @brief my_memcpy
 * Function used to copy a block of memory from a location to another.
 * @param dest: This is pointer to the destination array where the content is to
 * be copied, type-casted to a pointer of type void*.
 * @param src: This is pointer to the source of data to be copied, type-casted
 * to a pointer of type void*.
 * @param n: This is the number of bytes to be copied.
 * @return void*: This function returns a pointer to destination, which is str1.
 */
void *my_memcpy(void *dest, const void *src, my_size_t n) {
  char *first = (char *)dest;
  char *second = (char *)src;
  while (n--) {
    *first++ = *second++;
  }
  return (void *)dest;
}
/**
 * @brief my_memmove
 * function copies n characters from str2 to str1, but for overlapping memory
 * blocks, memmove() is a safer approach than memcpy().
 * @param dest: This is a pointer to the destination array where the content is
 * to be copied, type-casted to a pointer of type void*.
 * @param src: This is a pointer to the source of data to be copied, type-casted
 * to a pointer of type void*.
 * @param n: This is the number of bytes to be copied.
 * @return void*: his function returns a pointer to the destination, which is
 * str1.
 */
void *my_memmove(void *dest, const void *src, my_size_t n) {
  char *tmp = MY_NULL;
  char *pdest = (char *)dest;
  const char *psrc = (const char *)src;
  tmp = (char *)malloc(sizeof(char) * n);
  my_size_t i = 0;
  for (i = 0; i < n; i++) {
    tmp[i] = psrc[i];
  }
  for (i = 0; i < n; i++) {
    pdest[i] = tmp[i];
  }
  if (tmp) {
    free(tmp);
  }
  return (void *)dest;
}
/**
 * @brief my_strcmp
 * This function takes two strings as arguments and compare these two strings
 * lexicographically.
 * @param str1: This is the first string to be compared.
 * @param str2: This is the second string to be compared.
 * @return int: This function can return three different integer values.
 */
int my_strcmp(const char *str1, const char *str2) {
  char *first = (char *)str1;
  char *second = (char *)str2;
  int result = 0;
  while (*first != '\0' && *second != '\0') {
    if (*first != *second) {
      break;
    }
    first++;
    second++;
  }
  result = *first - *second;
  return result;
}
/**
 * @brief my_strncmp
 * This function takes two strings and a number num as arguments and compare at
 * most first num bytes of both the strings.
 * @param str1: string to be compared.
 * @param str2: string to be compared.
 * @param n: Maximum number of characters to compare.
 * @return int: function return three different types of integer values
 */
int my_strncmp(const char *str1, const char *str2, my_size_t n) {
  char *first = (char *)str1;
  char *second = (char *)str2;
  int result = 0;
  while ((*first || *second) && n) {
    if (*first != *second) {
      break;
    }
    n--;
    first++;
    second++;
  }
  if (n != 0) {
    result = *first - *second;
  } else {
    result = 0;
  }
  return result;
}
/**
 * @brief my_memset
 * function used to fill a block of memory with a particular value.
 * @param str: Starting address of memory to be filled
 * @param c: Value to be filled
 * @param n: Number of bytes to be filled starting from ptr to be filled
 * @return void*:  The memset() function returns str, the pointer to the
 * destination string.
 */
void *my_memset(void *str, int c, my_size_t n) {
  char *pstr = (char *)str;
  my_size_t i = 0;
  while (n-- && pstr) {
    pstr[i] = c;
    i++;
  }
  return (void *)pstr;
}
/**
 * @brief my_strcspn
 * function calculates the length of the number of characters before the 1st
 * occurrence of character present in both the string.
 * @param str1: The Target string in which search has to be made.
 * @param str2: Argument string containing characters to match in target string.
 * @return my_size_t: This function returns the number of characters before the
 * 1st occurrence of character present in both the string.
 */
my_size_t my_strcspn(const char *str1, const char *str2) {
  my_size_t result = 0;
  char *res = my_strpbrk(str1, str2);
  if (res != MY_NULL) {
    result = my_strlen(str1) - my_strlen(res);
  } else {
    result = my_strlen(str1);
  }
  return result;
}
/**
 * @brief my_to_upper
 * function is used to convert lowercase alphabet to uppercase.
 * i.e. If the string passed is a lowercase alphabet then the toupper() function
 * converts a lowercase alphabet to an uppercase alphabet.
 * @param str: This represents the string to be converted to uppercase.
 * @return void*: This function returns the uppercase string corresponding to
 * the str.
 */
void *my_to_upper(const char *str) {
  char *copy_str = MY_NULL;
  copy_str = (char *)malloc((my_strlen(str) + 1) * sizeof(char));
  my_size_t n = my_strlen(str) + 1;
  for (my_size_t i = 0; i < n; i++) {
    copy_str[i] = str[i];
    if (copy_str[i] == '\0') {
      break;
    }
    copy_str[i + 1] = '\0';
  }
  for (int i = 0; copy_str[i] != '\0'; i++) {
    if (copy_str[i] >= 'a' && copy_str[i] <= 'z') {
      copy_str[i] -= 32;
    }
  }
  return (void *)copy_str;
}
/**
 * @brief my_to_lower
 * Function converts every character to lowercase (if there is a lowercase
 * character). If a character does not have a lowercase equivalent, it remains
 * unchanged.
 * @param str: String to be converted to lowercase.
 * @return void*: It return the string value, which is the lowercase equivalent
 * of the string of type.
 */
void *my_to_lower(const char *str) {
  char *copy_str = MY_NULL;
  copy_str = (char *)malloc((my_strlen(str) + 1) * sizeof(char));
  my_size_t n = my_strlen(str) + 1;
  for (my_size_t i = 0; i < n; i++) {
    copy_str[i] = str[i];
    if (copy_str[i] == '\0') {
      break;
    }
    copy_str[i + 1] = '\0';
  }
  for (int i = 0; copy_str[i] != '\0'; i++) {
    if (copy_str[i] >= 'A' && copy_str[i] <= 'Z') {
      copy_str[i] = copy_str[i] + 32;
    }
  }
  return (void *)copy_str;
}
/**
 * @brief my_insert
 * It is used to return a new string in which a specified string is inserted at
 * a specified index position in the current string instance.
 * @param src: The String value to be inserted the type of this parameter
 * @param str: The string for insert new string.
 * @param start_index: It is the index position of current string where the new
 * value will be inserted
 * @return void*: returns new string. If the String value is null, returns
 * MY_NULL.
 */
void *my_insert(const char *src, const char *str, my_size_t start_index) {
  char *result = MY_NULL;
  if (start_index <= my_strlen(src)) {
    char *temp = calloc((my_strlen(src) - start_index + 1), sizeof(char));
    my_size_t j = 0;
    for (my_size_t i = start_index; i < my_strlen(src); i++, j++) {
      temp[j] = src[i];
    }
    temp[j] = '\0';
    result = calloc(my_strlen(str) + my_strlen(src) + 1, sizeof(char));
    char *tt = result;
    for (my_size_t i = 0; i < start_index; i++, tt++) {
      *tt = src[i];
    }
    for (j = 0; j < my_strlen(str); j++, tt++) {
      *tt = str[j];
    }
    for (j = 0; j < my_strlen(temp); j++, tt++) {
      *tt = temp[j];
    }
    if (temp != MY_NULL) {
      free(temp);
    }
  }
  return result;
}
/**
 * @brief my_trim
 * This method is used to removes all leading and trailing white-space
 * characters from the current String object. This method can be overloaded by
 * passing arguments to it.
 * @param src: Input string.
 * @param trim_chars: Symbols whitch will be deleted by right and left side at
 * string.
 * @return void*: returns the string without trim_chars symbols.
 */
void *my_trim(const char *src, const char *trim_chars) {
  char *tmp = MY_NULL;
  if (src != MY_NULL) {
    my_size_t ls = my_strlen(src) + 1;
    tmp = (char *)malloc(ls * sizeof(char));
    my_strcpy(tmp, src);
    if (trim_chars != MY_NULL) {
      for (int i = my_strlen(tmp) - 1;
           i >= 0 && my_strchr(trim_chars, *(tmp + i)) != MY_NULL; --i) {
        *(tmp + i) = '\0';
      }
      while (*tmp != '\0' && my_strchr(trim_chars, *tmp) != MY_NULL) {
        my_memmove(tmp, tmp + 1, my_strlen(tmp));
      }
    }
  }
  return tmp;
}
