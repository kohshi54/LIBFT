#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "ft_header.h"

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		// Test of ft_isalpha() #は表示されない(エスケープ文字だからargcに含まれないため)
		// printf("isalpha: %d\n", isalpha(argv[1][0]));
		// printf("ft_isalpha: %d\n", ft_isalpha(argv[1][0]));

		// Test of ft_isdigit()
		// printf("isdigit : %d\n", isdigit(argv[1][0]));
		// printf("ft_isdigit : %d\n", ft_isdigit(argv[1][0]));

		// Test of ft_isalnum()
		// printf("isalnum: %d\n", isalnum(argv[1][0]));
		// printf("ft_isalnum: %d\n", ft_isalnum(argv[1][0]));

		// Test of ft_isascii() octalとは？？？？ ascii以外の入力を受け取るためatoiを使ってます
		// printf("isascii: %d\n", isascii(atoi(argv[1])));
		// printf("ft_isascii: %d\n", ft_isascii(atoi(argv[1])));

		// Test of ft_isprint ちょっと未完成
		// printf("isprint: %d\n", ft_isprint(argv[1]));
		// printf("ft_isprint: %d\n", ft_isprint(argv[1]));

		// Test of ft_strlen()
		// printf("strlen: %lu\n", strlen(argv[1]));
		// printf("ft_strlen: %lu\n", ft_strlen(argv[1]));

		// Test of ft_memset() 第三引数を文字列の数以上にするとセグフォしますが本家もするので問題ないのかな？？
		// char *buf1= argv[1];
		// char *buf2 = argv[2];
		// memset(buf1, '1', atoi(argv[3]));
		// ft_memset(buf2, '1', atoi(argv[3]));
		// printf("memset   : %s\n", buf1);
		// printf("ft_memset: %s\n", buf2);

		// Test of ft_bzero()
		int count = atoi(argv[1]);
		char s[] = "ABCDEF";
		bzero(s, count);
		printf("bzero from head   : %s\n", s); // printfはnullが来るまでポインタを動かして表示する。bzeroでcount分までnullで埋めているので何も表示されない。
		printf("bzero from count+1: %s\n", &s[count]); // bzeroでcount分null文字を入れてcount+1番目からは元のまま。インデックスは0からスタートなのでcountでcount+1番目にアクセスできてcount+1番目以降の元の文字列が表示される。
		char s2[] = "ABCDEF";
		ft_bzero(s2, count);
		printf("ft_bzero from head   : %s\n", s2);
		printf("ft_bzero from count+1: %s\n", &s2[count]);
	}
	return (0);
}