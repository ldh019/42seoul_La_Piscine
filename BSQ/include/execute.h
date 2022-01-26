/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:05:55 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/26 14:41:36 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

void	execute(int **map, t_pair a);
void	return_file_content(char *file_name, char *letter, t_pair *size);
void	print(int **map, char *letter, t_pair a);
int		check_map(int **map, t_pair size);
void	make_map(char *filename, int **map, char *letter, t_pair *size);
void	fill_map(int *ans, int **map);

#endif