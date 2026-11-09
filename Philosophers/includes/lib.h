/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:19:21 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/22 00:23:24 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "philo.h"

# define MAX_INT 2147483647

int				ft_strlen(char *str);
int				ft_intlen(int integer);
int				ft_tablen(char **tab);

int				ft_atoi(t_data *data, const char *nptr);

void			ft_putstr(char *str);
void			ft_putstr_var(char **var, char *str);

void			ft_putnbr(int n);
void			ft_putnbr_var(char **var, long long n, int i);

void			ft_sleep(t_philo *philo, unsigned int time);

char			**ft_split(char *s, char c);

#endif
