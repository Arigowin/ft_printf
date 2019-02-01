
char		*ft_strcat(char *s1, const char *s2)
{
	char	*save_ptr;

	save_ptr = s1;
	while (s1 && *s1)
		s1++;
	while (s2 && *s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	if (s1)
		*s1 = '\0';
	return (save_ptr);
}
