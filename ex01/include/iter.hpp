/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:21:09 by didimitr          #+#    #+#             */
/*   Updated: 2026/03/11 14:34:52 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T, typename F>
void iter(T* ptr, const int len, F fun) {
    if(ptr == NULL || len <= 0)
        return;
    for (int i = 0; i < len; i++)
    {
        fun(ptr[i]);
    }
}