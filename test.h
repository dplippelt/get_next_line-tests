/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:29:13 by dlippelt          #+#    #+#             */
/*   Updated: 2024/11/18 11:34:44 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# ifndef BONUS
#  define BONUS 0
# endif

# if !BONUS
#  include "/home/dlippelt/codam/main/get_next_line/2/get_next_line.h" //change for eval
# else
#  include "/home/dlippelt/codam/main/get_next_line/2/get_next_line_bonus.h" //change for eval
# endif

#endif
