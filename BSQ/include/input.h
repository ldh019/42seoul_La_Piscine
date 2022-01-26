/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:08:32 by jiikang           #+#    #+#             */
/*   Updated: 2022/01/26 14:37:33 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# define BUFF_SIZE 3000

int		check_map(int **map, t_pair size);
int		read_row_line(char *filename);
int		read_one_line(int fd, char *return_line, int line_length, int flag);
int		check_letter_is_valid(char *letter);
int		char_to_int(char *num);
int		check_letter(char a, char *letter);
void	put_line(char *temp, int **map, char *letter, int num);
void	make_map(char *filename, int **map, char *letter, t_pair *size);
int		make_letter(char *letter, char *buff, int length);
void	make_pair(t_pair *size, int row, int column);
void	return_file_content(char *filename, char *letter, t_pair *size);

#endif