
#include "ScavTrap.hpp"

int main()
{
    ScavTrap st("lalo");
    st.attack("charles");
    st.takeDamage(20);
    st.beRepaired(15);
    st.guardGate();
    return 0;
}
