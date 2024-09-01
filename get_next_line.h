/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:07:32 by madao-da          #+#    #+#             */
/*   Updated: 2024/08/26 11:29:07 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> /*read/write/close*/
# include <stdio.h> /*NULL*/
# include <stdlib.h> /*malloc/calloc/free*/
# include <fcntl.h> /*O_RDONLY*/

char	*ft_strdup(char *str);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
int		ft_check_newline(char *str);
char	*ft_save_in_temp(char *receive, char *str);
char	*ft_broom(char *str);
void	*ft_clean(char **buffer, char **str);
void	*ft_memalloc(size_t nitems, size_t size);

#endif