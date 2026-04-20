/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:21:09 by didimitr          #+#    #+#             */
/*   Updated: 2026/04/20 16:31:46 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T, typename F>
void iter(T* ptr, size_t len, F fun) {
    if(ptr == NULL || len == 0)
        return;
    for (size_t i = 0; i < len; i++)
    {
        fun(ptr[i]);
    }
}