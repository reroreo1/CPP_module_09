/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:42:01 by rezzahra          #+#    #+#             */
/*   Updated: 2023/03/17 22:42:02 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <iostream>
class RPN{
    private:
        bool numOp;
        std::stack<int> operands;
        double result;
        RPN();
        RPN(const RPN& a);
        RPN& operator=(const RPN& a);
    public:
        RPN(std::string &expression);
        void checkOp(std::string expression);
        void executeOp(char operation);
        ~RPN();
};


#endif