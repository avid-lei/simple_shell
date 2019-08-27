#include "header.h"


char *_strdup(char *str)
{

	char *ar;
	unsigned int i;
	unsigned int length = 0;

	if (str == NULL)
		return (NULL);

	for (length = 0; str[length] != '\0'; length++)
		;
	length++;

	if (length < 1)
		return (NULL);

	ar = malloc((length + 1) * sizeof(char));

	if (ar == NULL)
	{
		free(ar);
		return (NULL);
	}

	for (i = 0; i < length; i++)
		ar[i] = str[i];

	ar[i] = '\0';

	return (ar);



}


int _strlen(char *s)
{
	int count;
	for (count = 0; s[count] != '\0'; count++)
	;
		return (count);
}


char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*src != '\0')
	{
		*(dest + i) = *(src);
		i++;
		src++;

	}
	*(dest + i) = '\0';
	return (dest);
}



char *_strcat(char *dest, char *src)
{
	int length = 0;
	char *temp = dest;

	while (*temp != '\0')
	{
		temp++;
		length++;
	}
	while (*src)
	{
		*temp = *src;
		temp++;
		src++;
		length++;

	}
	*temp = '\0';
	temp = temp - length;
	return (dest);

}


int _strcmp(char *s1, char *s2)
{
	int comp;

	while (*s1 == *s2)
	{
		s1++;
		s2++;
		if (*s1 == '\0')
			return (0);
	}
	comp = *s1 - *s2;
	return (comp);

}

int _strncmp(char *s1, char *s2, size_t n)
{
	int comp;
	size_t x = 0;

	while (*s1 == *s2)
	{
		s1++;
		s2++;
		x++;
		if (*s1 == '\0' || x == n)
			return (0);
	}
	comp = *s1 - *s2;
	return (comp);

}
