/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:56:42 by theog             #+#    #+#             */
/*   Updated: 2025/06/28 22:24:39 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cctype>
#include  <cmath>

struct Data
{
    int content;
};

class Serializer
{
    public:
        Serializer();
        ~Serializer();
        Serializer(const Serializer& copy);
        virtual Serializer& operator=(const Serializer &copy) = 0;
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};