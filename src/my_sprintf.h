#ifndef _SRC_MY_SPRINTF_H_
#define _SRC_MY_SPRINTF_H_
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int my_sprintf(char *str, const char *format, ...);
char *check_flags(char *flagplus, char *flagminus, char *flagspace, char *c);
char *check_weight_or_accur(char *c);
long int str_in_digit(char *string_weight);
char *check_lenght(char *c, char *lenght);
char *int_in_str(char *buffer_int, int int_or_not, long long int tmp_int,
                 char flagminus, char flagplus, char flagspace, long int weight,
                 long int accur);
int length_int(long long int tmp_number);
char *float_in_str(char *buffer_int, long double tmp_float, char flagminus,
                   char flagplus, char flagspace, long int weight,
                   long int accur);

#endif  // _SRC_MY_SPRINTF_H_