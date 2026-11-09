/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:19:37 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/19 16:19:39 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define ARG_NUM "philo take only numeric argument !"
# define OVERFLOW "to high value !"

char	**parsing(char **argv);
int		checkargv(char **argv);

#endif
