/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lerpi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 02:49:33 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/28 04:47:06 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int      ft_lerpi(int first, int second, double p)
{
    if (first == second)
        return (first);
    return ((int)(first + (second - first) * p));
}