int ft_atoi(const char *str)
{
	// return (int)strtol(str, (char **)NULL, 10);
	size_t neg_flg;
	unsigned long num;

	neg_flg = 0;
	num = 0;
	while (isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg_flg = 1;
		str++;
	}
	while (isdigit(*str))
	{
		num = (num * 10) + (*str - '0');
		str++;
		printf("num: %lu\n", num);
	}
	if (num > LONG_MAX)
	{
		if (neg_flg)
			return ((int)LONG_MIN);
		else
			return ((int)LONG_MAX);
	}
	if (neg_flg)
	{
		return (-num);
	}
	return (num);
}