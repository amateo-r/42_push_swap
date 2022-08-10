/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions_handlers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:00:30 by amateo-r          #+#    #+#             */
/*   Updated: 2022/05/12 14:21:33 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libps.h"

/**
 * DESCRIPTION:
 * Check if input parameters are sorted.
 * RETURN:
 * If the input is sorted return 0 else 1.
 * PARAMETERS:
 * @param	int		argc	Number of input parameters.
 * @param	char	**argv	Input parameters.
 */
int	chk_issorted(char **argv, int k)
{
	int	flag;
	int	i;

	flag = 0;
	i = 1 - k;
	while(!flag && argv[i + 1] != 0)
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			flag = 1;
		i++;
	}
	
	// printf("Sorted %d\n", flag);
	return (flag);
}

/**
 * DESCRIPTION:
 * Check if the input parameters are integers.
 * RETURN:
 * If the input values aren't integers return 0 else 1.
 * PARAMATERS:
 * @param	char	**argv	Input paramters.
 * @param	int		k		Special case where all is a string instead
 * 							of individual inputs.
 */
int	chk_numbers(char **argv, int k)
{
	int	flag;
	int	i;

	flag = 1;
	i = 0 - k;
	while (argv[++i] && flag)
	{
		if (ft_strlen(argv[i]) == 11 && ft_strncmp(argv[i], \
			"-2147483648", 11) > 0)
			flag = 0;
		else if (ft_strlen(argv[i]) > 11)
			flag = 0;
		else if (ft_strlen(argv[i]) == 10 && ft_strncmp(argv[i], \
			"2147483647", 10) > 0)
			flag = 0;
		else if (ft_atoi(argv[i]) == -1 && ft_strncmp(argv[i], "-1", 2) != 0)
			flag = 0;
		else if (ft_atoi(argv[i]) == 0 && ft_strncmp(argv[i], "0", 1) != 0)
			flag = 0;
	}
	// printf("Numbers %d\n", flag);
	return (flag);
}

/**
 * DESCRIPTION:
 * Check if theres is duplicated number between input parameters.
 * RETURN:
 * If there is at least one duplicated number return 0 else 1.
 * PARAMETERS:
 * @param	char	**argv	Input parameters.
 * @param	int		k		Special case where all is a string instead
 * 							of individual inputs.
 */
int	chk_duplicated(char **argv, int k)
{
	int	i;
	int	j;
	int	flag;

	i = 0 - k;
	j = 0;
	flag = 1;
	while (argv[++i] && flag)
	{
		j = i;
		while (argv[++j] && flag)
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				flag = 0;
	}
	// printf("Duplicated %d\n", flag);
	return (flag);
}

/**
 * DESCRIPTION:
 * Free memory allocated from matrix.
 * PARMETERES:
 * @param	char	**matrix	Input numbers.
 */
void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while(matrix[++i] != 0)
		free(matrix[i]);
	free(matrix);
	return ;
}
/**
 * DESCRIPTION:
 * Manage all possible exceptions from the input paramenters.
 * RETURN:
 * If there aren't errors return 1 else 0.
 * PARAMETERS:
 * @param	int		argc	Number of input parameters.
 * @param	char	**argv	Input parameters.
 * @param	int		k		Special case where all is a string instead
 * 							of individual inputs.
 */
int	input_manager(int argc, char **argv, int k)
{
	char	**matrix;
	int		exc;

	if (argc <= 1)
		return (0);
	else if (argc == 2 && !k)
	{
		matrix = ft_split(argv[1], ' ');
		exc = input_manager(argc, matrix, 1);
		free_matrix(matrix);
		return (exc);
	}
	else
	{
		if (!chk_numbers(argv, k))
			return (0);
		else if (!chk_duplicated(argv, k))
			return (0);
		else if (!chk_issorted(argv, k))
			return (0);
	}
	return (1);
}
