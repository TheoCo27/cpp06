/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:56:44 by theog             #+#    #+#             */
/*   Updated: 2025/06/28 22:10:57 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}
Serializer::~Serializer(){}
Serializer::Serializer(const Serializer& copy){
    (void)copy;
}
Serializer& Serializer::operator=(const Serializer &copy){
    (void)copy;
    return(*this);
}

uintptr_t Serializer::serialize(Data* ptr){
    return(reinterpret_cast<uintptr_t>(ptr));
}
Data* Serializer::deserialize(uintptr_t raw){
    return(reinterpret_cast<Data*>(raw));
}