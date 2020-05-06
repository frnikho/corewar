/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** header file
*/

#ifndef MY_H
#define MY_H

int my_compute_factorial_it(int nb);
int my_compute_factorial_rec(int nb);
int my_compute_power_it(int nb, int p);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int convert_into_integer(char c);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isalpha(char c);
int my_islowcase(char c);
int my_isneg(int n);
int my_isnum(char c);
int my_isstrempty(char const *str);
int my_isupcase(char c);
int my_print_alpha(void);
void my_putchar(char c);
int my_print_revalpha(void);
int my_put_nbr(int nb);
void my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_strcmp2(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char *my_strdup(char const *str);
void my_strerr(char *str);
char **my_str_to_word_array(char *str);

int my_getnbr_index(char const *str, int start_index);

void *my_putnbr_base(int nbr, char const *base);
int get_int_length(int nbr);
int my_isprintable(char c);

void my_put_float(float nb);
void my_put_nfloat(float nb, int length);

char **str_array(char *str);
char **str_array_key(char *str, char key);
char *str_cat(char *one, char *two);
int str_start_with(char *str, char *start_with);
int str_is_equals(char const *str1, char const *str2);
char *str_clean(char *str);

void array_add(char **array, char *value);
void array_remove(char **array, char *value);
int get_array_size(char **array);
char **array_cpy(char **array);
void array_clean(char **array);
int array_length(char **array);

int str_contains(char *str, char *word);

char **str_split(char *c, char split);
char *str_cat_char(char *one , char c);

#endif