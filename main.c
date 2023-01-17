#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void ft_intcmp(int c1, int c2)
{
	if (c1 == c2)
		printf("status: success\n");
	else
		printf("status: failure\n");	
}

void ft_isalpha_checker(int c)
{
	// #は表示されない(エスケープ文字だからargcに含まれないため)
	printf("isalpha: %d\n", isalpha(c));
	printf("ft_isalpha: %d\n", ft_isalpha(c));
	ft_intcmp(isalpha(c), ft_isalpha(c));
}

void ft_isdigit_checker(int c)
{
	// argument must be representable as unsigned charってどういう意味
	// 多分オーバーフローは考慮しなくていいってこと
	printf("isdigit : %d\n", isdigit(c));
	printf("ft_isdigit : %d\n", ft_isdigit(c));
	ft_intcmp(isdigit(c), ft_isdigit(c));
}

void ft_isalnum_checker(int c)
{
	printf("isalnum: %d\n", isalnum(c));
	printf("ft_isalnum: %d\n", ft_isalnum(c));
	ft_intcmp(isalnum(c), ft_isalnum(c));
}

void ft_isascii_checker(int c)
{
	// Test of ft_isascii() octalとは？？？？ ascii以外の入力を受け取るためにatoiを使ってます
	printf("isascii: %d\n", isascii(c));
	printf("ft_isascii: %d\n", ft_isascii(c));
	ft_intcmp(isascii(c), ft_isascii(c));
}

void ft_isprint_checker(int c)
{
	printf("isprint: %d\n", ft_isprint(c));
	printf("ft_isprint: %d\n", ft_isprint(c));
	ft_intcmp(isprint(c), ft_isprint(c));
}

void ft_strlen_checker(char *c)
{
	printf("strlen: %lu\n", strlen(c));
	printf("ft_strlen: %lu\n", ft_strlen(c));
	ft_intcmp(strlen(c), ft_strlen(c));
}

void ft_memset_checker(void *b, int c, size_t len)
{
	// len（書き換えるバイト数）がb（書き換える対象の文字列）のバイト数よりも大きい場合
	// 本家ではterm-256colorというエラーが出ますが気にしなくもいいのかな？？普通にセグフォで本来コンパイルできない説？
	void *dup = strdup(b);
	printf("memset: %s\n", (unsigned char*)memset(b, c, len));
	printf("ft_memset: %s\n", (unsigned char*)ft_memset(dup, c, len));
	if (strcmp(b, dup) == 0)
		printf("status: success\n");
	else
		printf("status: failure\n");
}

// ft_bzeroを確認するために0が来ても止まらないstrcmpを自作する、文字数分だけ確認する
int ft_bzerocmp(void *s1, void *s2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char*)s1 != *(unsigned char*)s2)
		{
			// printf("s1: %c, s2: %c\n", *(unsigned char*)s1, *(unsigned char*)s2);
			return (0);
		}
		s1++;
		s2++;
	}
	return (1);
}

void ft_bzero_checker(void *s, size_t n)
{
	int count = strlen(s);
	void *dup = strdup(s);
	bzero(s, n);
	ft_bzero(dup, n);
	printf("bzero from head: %s\n", (unsigned char*)s); // printf()はnullが来るまでポインタを動かして表示する。bzero()でcount分までnullで埋めているので何も表示されない。
	printf("bzero from count+1: %s\n", (unsigned char*)&s[n]); // bzeroでcount分null文字を入れてcount+1番目からは元のまま。インデックスは0からスタートなのでcountでcount+1番目にアクセスできてcount+1番目以降の元の文字列が表示される。
	printf("ft_bzero from head: %s\n", (unsigned char*)dup);
	printf("ft_bzero from count+1: %s\n", (unsigned char*)&dup[n]);
	if (ft_bzerocmp(s, dup, count))
		printf("status: success\n");
	else
		printf("status: failure\n");
}

void ft_memcpy_checker(char *restrict dst, const void *restrict src, size_t n)
{
	void *dstdup = strdup(dst);
	void *srcdup = strdup(src);
	printf("memcpy: %s\n", (unsigned char*)memcpy(dst, src, n));
	printf("ft_memcpy: %s\n", (unsigned char*)ft_memcpy(dstdup, srcdup, n));
	if (strcmp(dst, dstdup) == 0)
		printf("status: success\n");
	else
		printf("status; failure\n");
}

void ft_memmove_checker(void *str)
{
	str++;
	// char dst1[] = "ABCDEF";
	char src1[] = "0123456";
	// char dst2[] = "ABCDEF";
	char src2[] = "0123456";
	int len = 2;
	printf("memmove: %s\n", (unsigned char*)memmove(src1+2, src1, len));
	printf("ft_memmove: %s\n", (unsigned char*)ft_memmove(src2+2, src2, len));
}

void ft_strlcpy_checker(void *src)
{
	// char src1[] = "ABCDEFGH";
	char dst1[7];
	char dst2[7];
	printf("strlcpy: %lu\n", strlcpy(dst1, src, 7));
	printf("strlcpy: %s\n", dst1);
	printf("ft_strlcpy: %lu\n", ft_strlcpy(dst2, src, 7));
	printf("ft_strlcpy: %s\n", dst2);
}

void ft_strlcat_checker(void *str)
{
	str++;
	char buf1[7] = {'a', 'b', 'c', '\0'};
	char buf2[7] = {'a', 'b', 'c', '\0'};
	printf("strlcat: %lu\n", strlcat(buf1, "abcdef", 2));
	printf("strlcat: %s\n", buf1);
	printf("strlcat: %lu\n", ft_strlcat(buf2, "abcdef", 2));
	printf("strlcat: %s\n", buf2);
}

void ft_toupper_checker(int c)
{
	printf("toupper: %c\n", toupper(c));
	printf("ft_toupper: %c\n", ft_toupper(c));
}

void ft_tolower_checker(int c)
{
	printf("tolower: %c\n", tolower(c));
	printf("ft_tolower: %c\n", ft_tolower(c));
}

void ft_strchr_checker(char s)
{
	char target[] = {'a', 'b', 'c', 'd', 'e'}; // オリジナルも動作は未定義になる 
	printf("%s\n", strchr(target, s));
	printf("%s\n", ft_strchr(target, s));
	printf("%d\n", strcmp(strchr(target, s), ft_strchr(target, s)));
}

void ft_strrchr_checker(char s)
{
	s++;
	printf("strrchr: %s\n", strrchr("ABCDEFDG", '\0'));
	printf("ft_strrchr: %s\n", ft_strrchr("ABCDEFDG", '\0'));
}

void ft_strncmp_checker(char *s1, char *s2, int c)
{
	printf("%d\n", strncmp(s1, s2, c));
	printf("%d\n", ft_strncmp(s1, s2, c));
}

void ft_memchr_checker(const void *s, int c, size_t n)
{
	printf("%s\n", (char*)memchr(s, c, n));
	printf("%s\n", (char*)ft_memchr(s, c, n));
}

void ft_memcmp_checker(char *s)
{
	s++;
	printf("%d\n", memcmp("ABCDEF", "ABCEJ", 5));
	printf("%d\n", ft_memcmp("ABCDEF", "ABCEJ", 5));
}

void ft_strnstr_checker(const char *s1, const char *s2, size_t c)
{
	printf("strnstr: %s\n", strnstr(s1, s2, c));
	printf("ft_strnstr: %s\n", ft_strnstr(s1, s2, c));
}

void ft_atoi_checker(const char *str)
{
	printf("%d\n", atoi(str));
	printf("%d\n", ft_atoi(str));
}

void ft_calloc_checker(char *s)
{
	s++;
	printf("calloc: %s\n", (char *)calloc(1, 1));
	printf("ft_calloc: %s\n", (char *)ft_calloc(1, 1));
}

void ft_strdup_checker(char *str)
{
	printf("strdup: %s\n", strdup(str));
	printf("ft_strdup: %s\n", ft_strdup(str));
}

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		// ft_isalpha_checker(argv[1][0]);
		// ft_isdigit_checker(argv[1][0]);
		// ft_isalnum_checker(argv[1][0]);
		// ft_isascii_checker(atoi(argv[1]));
		// ft_isprint_checker(atoi(argv[1]));
		// ft_strlen_checker(argv[1]);
		// ft_memset_checker(argv[1], atoi(argv[2]), atoi(argv[3]));
		// ft_bzero_checker(argv[1], atoi(argv[2]));
		// ft_memcpy_checker(argv[1], argv[2], atoi(argv[3]));
		// ft_memmove_checker(argv[1]);
		// ft_strlcpy_checker(argv[1]);
		// ft_strlcat_checker(argv[1]);
		// ft_toupper_checker(argv[1][0]);
		// ft_tolower_checker(argv[1][0]);
		// ft_strchr_checker(argv[1][0]);
		// ft_strrchr_checker(argv[1][0]);
		
		// char s1[] = {'a', 'b'}; // 71
		// char s2[] = {'a', 'b'}; // -185 why???????
		// ft_strncmp_checker(s1, s2, atoi(argv[1]));
		// ft_memchr_checker(argv[1], argv[2][0], atoi(argv[3]));
		// ft_memcmp_checker(argv[1]);
		// ft_strnstr_checker(argv[1], argv[2], atoi(argv[3]));
		// ft_atoi_checker(argv[1]);
		// ft_calloc_checker(argv[1]);
		ft_strdup_checker(argv[1]);
	}
	return (0);
}