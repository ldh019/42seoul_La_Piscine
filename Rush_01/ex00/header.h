#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>

int	g_a[4][4];
int	g_boxcount[4][4];
int	g_error;

void	recursive(int y, int x);
void	print(void);
int		finish_row_left(int y);
int		finish_row_right(int y);
int		finish_col_up(void);
int		finish_col_down(void);

#endif