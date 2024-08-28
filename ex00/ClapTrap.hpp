#pragma once

#include <string>
#include <iostream>


class ClapTrap
{
    private:
        std::string name;
        unsigned int hit_pts;
        unsigned int energy_pts;
        unsigned int attack_dmg;

    public:

        ClapTrap();
        ClapTrap(const ClapTrap &copy);
        ClapTrap(std::string name);

        ~ClapTrap();

        ClapTrap &operator=(const ClapTrap &src);

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};