/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lai-elho <lai-elho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:34:58 by lai-elho          #+#    #+#             */
/*   Updated: 2025/05/08 22:34:59 by lai-elho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    FragTrap ft("Warrior");

    ft.attack("enemy");
    ft.takeDamage(25);
    ft.beRepaired(20);
    ft.highFivesGuys();

    return 0;
}
