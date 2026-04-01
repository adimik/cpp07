/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:48:30 by didimitr          #+#    #+#             */
/*   Updated: 2026/03/16 19:13:36 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
T min(T a, T b) {
    if(b <= a)
        return(b);
    return(a);
}

template <typename T>
T max(T a, T b) {
    if(b >= a)
        return(b);
    return(a);
}

template <typename T>
void swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}