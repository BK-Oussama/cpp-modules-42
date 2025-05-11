/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lai-elho <lai-elho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:36:02 by lai-elho          #+#    #+#             */
/*   Updated: 2025/05/08 22:36:03 by lai-elho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap ct1("Bender");
    ct1.attack("Leela");
    ct1.takeDamage(5);
    ct1.beRepaired(3);
    ct1.attack("Fry");
    ct1.takeDamage(10);
    ct1.beRepaired(5);
    return 0;
}
