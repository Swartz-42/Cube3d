/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: swartz <swartz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 15:49:30 by aducas       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/25 01:01:03 by swartz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

int ft_isspace(char s)
{
    if (s == ' ' || s == '\t' || s == '\r' || s == '\v' || s == '\f')
        return (1);
    return (0);
}