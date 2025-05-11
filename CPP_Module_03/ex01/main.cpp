/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lai-elho <lai-elho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:35:33 by lai-elho          #+#    #+#             */
/*   Updated: 2025/05/08 22:35:34 by lai-elho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    ScavTrap st("Guardian");
    st.attack("intruder");
    st.takeDamage(20);
    st.beRepaired(15);
    st.guardGate();
    return 0;
}
