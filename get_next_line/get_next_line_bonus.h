/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:21:27 by djo               #+#    #+#             */
/*   Updated: 2024/11/03 21:08:10 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int		ft_strlen(char *str);
char	*ft_join(char *str1, char *str2);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elementCount, size_t elementSize);
char	*ft_strchr(const char *string, int searchedChar);

char	*ft_next(char *buffer);
char	*ft_line_to_put(char *buffer);
char	*read_buffer(int fd, char *buf);
char	*get_next_line(int fd);

#endif
