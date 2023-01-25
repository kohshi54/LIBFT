static int ft_isupper(int c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

static int ft_islower(int c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

int ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (1);
	return (0);
}