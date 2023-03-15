#include "my_string.h"

int my_sprintf(char *str, const char *format, ...) {
  str[0] = '\0';
  char *str_1 = calloc(4096, sizeof(char));
  va_list ap;
  va_start(ap, format);
  int my_lengt = 0;
  char *c;
  for (c = (char *)format; *c; c++) {
    if (*c != '%') {
      my_lengt++;
      str_1[my_strlen(str_1)] = *c;
      continue;
    }
    if (*(c + 1) == '%' && *c) {
      my_lengt++;
      str_1[my_strlen(str_1)] = *c;
      c++;
      continue;
    }
    c++;
    char flagplus = -1;
    char flagminus = -1;
    char flagspace = -1;
    long int weight = -1;
    long int accur = -1;
    char lenght = -1;
    c = check_flags(&flagplus, &flagminus, &flagspace, c);
    if (*c >= '0' && *c <= '9') {
      char *string_weight = check_weight_or_accur(c);
      weight = str_in_digit(string_weight);
      my_size_t len_arr = my_strlen(string_weight);
      while (len_arr != 0) {
        len_arr--;
        c++;
      }
    }
    if (*c == '.' && (*(c + 1) == 'f' || *(c + 1) == 'l')) {
      accur = 0;
      c++;
    }
    if (*c == '.' && (*(c + 1) == 's')) {
      accur = 0;
      c++;
    }
    if (*c == '.' && (*(c + 1) == 'd' || *(c + 1) == 'i' || *(c + 1) == 'l' ||
                      *(c + 1) == 'h' || *(c + 1) == 'u')) {
      accur = 0;
      c++;
    }
    if (*c == '.') {
      if (*(c + 1) != 'c') {
        c++;
        char *string_accur = check_weight_or_accur(c);
        accur = str_in_digit(string_accur);
        my_size_t len_accur = my_strlen(string_accur);
        while (len_accur != 0) {
          len_accur--;
          c++;
        }
      } else {
        c++;
      }
    }
    char *p = check_lenght(c, &lenght);
    c = p;
    switch (*c) {
      case 'c': {
        char tmp_sumb;
        tmp_sumb = (char)va_arg(ap, int);
        if (flagminus != '-' && weight != -1) {
          for (long int i = 0; i < weight - 1; i++) {
            str_1[my_strlen(str_1)] = ' ';
            my_lengt++;
          }
        }
        str_1[my_strlen(str_1)] = tmp_sumb;
        my_lengt++;
        if (flagminus == '-' && weight != -1) {
          for (long int i = 0; i < weight - 1; i++) {
            str_1[my_strlen(str_1)] = ' ';
            my_lengt++;
          }
        }
        break;
      }
      case 'i':
      case 'd': {
        long long int tmp_int = 0;
        if (lenght == 'l') {
          tmp_int = (long int)va_arg(ap, long int);
        } else if (lenght == '$') {
          tmp_int = (long long int)va_arg(ap, long long int);
        } else if (lenght == 'h') {
          tmp_int = (short int)va_arg(ap, int);
        } else if (lenght == 'H') {
          tmp_int = (char)va_arg(ap, int);
        } else {
          tmp_int = (int)va_arg(ap, int);
        }
        char buffer_int[200] = "";
        int_in_str(buffer_int, 1, tmp_int, flagminus, flagplus, flagspace,
                   weight, accur);
        my_lengt += my_strlen(buffer_int);
        my_strcat(str_1, buffer_int);
        break;
      }
      case 'f': {
        long double tmp_double = (long double)va_arg(ap, double);
        char buffer_double[200] = "";
        float_in_str(buffer_double, tmp_double, flagminus, flagplus, flagspace,
                     weight, accur);
        my_lengt += my_strlen(buffer_double);
        my_strcat(str_1, buffer_double);
        break;
      }
      case 's': {
        char buffer_str[200] = "";
        int k = 0;
        for (char *tmp_str = va_arg(ap, char *); *tmp_str; tmp_str++) {
          k++;
          if (accur < k && accur >= 0) continue;
          *(buffer_str + k - 1) = *tmp_str;
          my_lengt++;
        }
        int l = my_strlen(buffer_str);
        if (flagminus != '-') {
          for (int i = 0; i < weight - l; ++i) {
            my_strcat(str_1, " ");
            my_lengt++;
          }
        }
        my_strcat(str_1, buffer_str);
        if (flagminus == '-') {
          for (int i = 0; i < weight - l; ++i) {
            my_strcat(str_1, " ");
            my_lengt++;
          }
        }
        break;
      }
      case 'u': {
        unsigned long long int tmp_uint = 0;
        if (lenght == 'l') {
          tmp_uint = (unsigned long int)va_arg(ap, unsigned long int);
        } else if (lenght == '$') {
          tmp_uint = (unsigned long long int)va_arg(ap, unsigned long long int);
        } else if (lenght == 'h') {
          tmp_uint = (unsigned short)va_arg(ap, unsigned int);
        } else if (lenght == 'H') {
          tmp_uint = (unsigned char)va_arg(ap, unsigned int);
        } else {
          tmp_uint = (unsigned int)va_arg(ap, unsigned int);
        }
        char buffer_uint[200] = "";
        flagplus = -1;
        flagspace = -1;
        int_in_str(buffer_uint, 1, (long long int)tmp_uint, flagminus, flagplus,
                   flagspace, weight, accur);
        my_lengt += my_strlen(buffer_uint);
        my_strcat(str_1, buffer_uint);
        break;
      }
      case '%': {
        if (flagminus != '-' && weight != -1) {
          for (long int i = 0; i < weight - 1; i++) {
            str_1[my_strlen(str_1)] = ' ';
            my_lengt++;
          }
        }
        str_1[my_strlen(str_1)] = '%';
        my_lengt++;
        if (flagminus == '-' && weight != -1) {
          for (long int i = 0; i < weight - 1; i++) {
            str_1[my_strlen(str_1)] = ' ';
            my_lengt++;
          }
        }
        break;
      }
      default: {
        str_1[my_strlen(str_1)] = *c;
        break;
      }
    }
  }
  va_end(ap);
  my_strcpy((void *)str, (void *)str_1);
  free(str_1);
  return my_lengt;
}

char *check_flags(char *flagplus, char *flagminus, char *flagspace, char *c) {
  while (1) {
    if (*c == ' ' || *c == '+' || *c == '-') {
      if (*c == ' ') {
        *flagspace = *c;
      } else if (*c == '+') {
        *flagplus = *c;
      } else if (*c == '-') {
        *flagminus = *c;
      }
      c++;
    } else {
      break;
    }
  }
  return c;
}
char *check_weight_or_accur(char *c) {
  long int i = 0;
  static char string_weight_or_accur[255];
  while (*c >= '0' && *c <= '9') {
    string_weight_or_accur[i] = *c;
    string_weight_or_accur[i + 1] = '\0';
    i++;
    c++;
  }
  return string_weight_or_accur;
}

long int str_in_digit(char *str_number) {
  long int number = 0;
  long int degree = 0;
  long int len_str = (long int)my_strlen(str_number);
  for (long int i = len_str - 1; i >= 0; i--) {
    long int tmp = 0;
    switch (str_number[i]) {
      case '0':
        tmp = 0 * pow(10, degree);
        break;
      case '1':
        tmp = 1 * pow(10, degree);
        break;
      case '2':
        tmp = 2 * pow(10, degree);
        break;
      case '3':
        tmp = 3 * pow(10, degree);
        break;
      case '4':
        tmp = 4 * pow(10, degree);
        break;
      case '5':
        tmp = 5 * pow(10, degree);
        break;
      case '6':
        tmp = 6 * pow(10, degree);
        break;
      case '7':
        tmp = 7 * pow(10, degree);
        break;
      case '8':
        tmp = 8 * pow(10, degree);
        break;
      case '9':
        tmp = 9 * pow(10, degree);
        break;
    }
    number += tmp;
    degree++;
  }
  return number;
}
char *check_lenght(char *c, char *lenght) {
  if (*c == 'l' && *(c + 1) != 'l') {
    *lenght = *c;
    c++;
  } else if (*c == 'h' && *(c + 1) != 'h') {
    *lenght = *c;
    c++;
  } else if (*c == 'l' && *(c + 1) == 'l') {
    *lenght = '$';
    c++;
    c++;
  } else if (*c == 'h' && *(c + 1) == 'h') {
    *lenght = 'H';
    c++;
    c++;
  }
  return c;
}
int length_int(long long int tmp_number) {
  int len_digit = 0;
  if (tmp_number < 0) {
    tmp_number = tmp_number * (-1);
  }
  if (tmp_number == 0) {
    len_digit++;
  }
  while (tmp_number) {
    tmp_number /= 10;
    len_digit++;
  }
  return len_digit;
}
char *int_in_str(char *buffer_int, int int_or_not, long long int tmp_int,
                 char flagminus, char flagplus, char flagspace, long int weight,
                 long int accur) {
  long long int len_digit = (long long int)length_int(tmp_int);
  long long int len_null = len_digit;
  long long int len_float = 0;
  if (int_or_not == 0 && accur != -1) {
    len_float = accur + 1;
  }
  if (accur != -1 && accur > len_digit && int_or_not == 1) {
    len_digit = accur;
  }
  long long int len_with_flag = len_digit;
  if ((flagplus == '+' && tmp_int >= 0) ||
      (flagspace == ' ' && tmp_int >= 0 && flagplus != '+') || (tmp_int < 0)) {
    len_with_flag++;
  }
  if (accur == 0 && int_or_not == 1 && tmp_int == 0) {
    len_with_flag--;
  }
  int position = 0;
  if (flagminus != '-' && weight != -1 && accur == 0 && int_or_not == 0) {
    for (; position < weight - len_with_flag; position++) {
      buffer_int[position] = ' ';
    }
  }
  if (flagminus != '-' && weight != -1) {
    for (; position < weight - len_with_flag - len_float; position++) {
      buffer_int[position] = ' ';
    }
  }
  if (flagspace == ' ' && flagplus != '+' && tmp_int >= 0) {
    buffer_int += position;
    *(buffer_int++) = ' ';
    buffer_int -= position;
  }
  if ((flagplus == '+' && tmp_int >= 0 && flagspace != ' ') ||
      (flagplus == '+' && tmp_int >= 0 && flagspace == ' ')) {
    buffer_int += position;
    *(buffer_int++) = '+';
    buffer_int -= position;
  }
  if (tmp_int < 0) {
    buffer_int += position;
    *(buffer_int++) = '-';
    buffer_int -= position;
    tmp_int = tmp_int * (-1);
  }
  int back = 0;
  if ((tmp_int == 0 && int_or_not == 0) ||
      (tmp_int == 0 && accur != 0 && int_or_not == 1)) {
    buffer_int[position + len_digit - back - 1] = '0';
    back++;
  }
  int qwe = 0;
  while (tmp_int > 0) {
    buffer_int[position + len_digit - back - 1] = (tmp_int % 10) | '0';
    tmp_int = tmp_int / 10;
    back++;
    qwe = 1;
  }
  if (int_or_not == 1) {
    for (int h = 0; h < accur - len_null; h++) {
      buffer_int[position + len_digit - back - 1] = '0';
      back++;
    }
  }
  if (flagminus == '-' && weight != -1 && int_or_not == 1 &&
      (qwe == 1 || accur != 0)) {
    for (; position < weight - len_with_flag; position++) {
      buffer_int[len_digit - 1 + position + 1] = ' ';
    }
  }
  if (flagminus == '-' && weight != -1 && int_or_not == 1 && accur == 0 &&
      tmp_int == 0 && qwe == 0) {
    for (; position < weight - len_with_flag; position++) {
      buffer_int[position] = ' ';
    }
  }
  return buffer_int;
}
char *float_in_str(char *buffer_double, long double tmp_float, char flagminus,
                   char flagplus, char flagspace, long int weight,
                   long int accur) {
  long long int int_float = (long long int)tmp_float;
  int flagg = 0;
  if (accur == 0) {
    int_float = roundl(tmp_float);
    flagg = 1;
  }
  long long int len_whole = (long long int)length_int(int_float);
  if ((flagplus == '+' && int_float >= 0) ||
      (flagspace == ' ' && flagplus != '+' && int_float >= 0) ||
      (int_float < 0)) {
    len_whole++;
  }
  if (accur == -1) {
    accur = 6;
  }
  int_in_str(buffer_double, 0, int_float, flagminus, flagplus, flagspace,
             weight, accur);
  if (accur != 0) {
    my_strcat(buffer_double, ".");
  }
  if (tmp_float < 0.0) {
    tmp_float = tmp_float * (-1.0);
  }
  int pos = my_strlen(buffer_double);
  tmp_float = tmp_float - (long long int)tmp_float;
  for (int i = 0; i < accur; i++, pos++) {
    tmp_float = tmp_float * 10;
    buffer_double[pos] = tmp_float + '0';
    tmp_float = tmp_float - (long long int)tmp_float;
  }
  if (tmp_float * 10 >= 5) {
    int flag = 0;
    int j = 0;
    while ((buffer_double[pos - j - 1] == '9') ||
           (buffer_double[pos - j - 1] == '.')) {
      if (buffer_double[pos - j - 1] == '.') {
        j++;
        flag = 1;
      }
      if (flag == 0) {
        buffer_double[pos - j - 1] = '0';
        j++;
      }
    }
    if ((pos - j - 1 >= 0) && (flagg == 0)) {
      buffer_double[pos - j - 1]++;
    }
  }
  if (flagminus == '-' && weight != -1 && accur == 0) {
    for (int k = 0; k < weight - (len_whole + accur); k++)
      buffer_double[my_strlen(buffer_double)] = ' ';
  }
  if (flagminus == '-' && weight != -1 && accur != 0) {
    for (int k = 0; k < weight - (len_whole + accur + 1); k++)
      buffer_double[my_strlen(buffer_double)] = ' ';
  }
  return buffer_double;
}