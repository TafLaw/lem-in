#include "lem_in.h"

char	*ft_strreturn(const char *hay, const char *needle)
{
	//unsigned int	i;
	//unsigned int	j;
	char **sp;

	sp = ft_strsplit((char*)hay, '-');
	if (ft_strcmp(sp[0], needle) == 0)
	{
		return ((char *)needle);
	}
	else if (ft_strcmp(sp[1], needle) == 0)
	{
		return ((char *)needle);
	}

//	i = 0;
	/*
	while (hay[i] != '\0')
	{
		j = 0;
		while (hay[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)needle);
		}
		i++;
	}*/
	return ((char *)hay);
}