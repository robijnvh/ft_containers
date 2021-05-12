/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   traits.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/30 13:54:58 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/05/12 15:42:09 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRAITS_HPP
#define TRAITS_HPP

namespace ft {

    struct output_iterator_tag{};
    struct input_iterator_tag{};
    struct forward_iterator_tag : public input_iterator_tag{};
    struct bidirectional_iterator_tag : public forward_iterator_tag{};
    struct random_access_iterator_tag : public bidirectional_iterator_tag{};

    template<bool B, class T = void> // if is_input_iterator == false, return nothing and fail
    struct enable_if {};

    template<class T> // if is_input_iterator == true, return type and continue function
    struct enable_if<true, T>
    { typedef T type; };

    template<typename T, typename C = typename T::iterator_category> // first check if input_iterator is valid
    struct is_input_iterator {
        typedef char yes[1];
        typedef char no[2];

        static yes& test(std::input_iterator_tag);
        static no& test(...);

        static const bool value = (sizeof(test(C())) == sizeof(yes)); // returns empty(false) or type(true)
    };
}

#endif