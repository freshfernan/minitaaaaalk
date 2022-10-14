/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8bit_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefernan <fefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:14:22 by fefernan          #+#    #+#             */
/*   Updated: 2022/10/13 16:28:43 by fefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int     bitshift;
    char    word;
    
    if (argc != 2)
        return (1);
    word = argv [1][0];
    bitshift = -1;
    printf("%c[%d]: ", word, word);
    while (++bitshift < 8)
    {
        if (word & 0x80 >> bitshift)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
    return (0);
}