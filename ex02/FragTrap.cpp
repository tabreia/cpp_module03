#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    this->hit_pts = 100;
    this->energy_pts = 100;
    this->attack_dmg = 30;
    std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
    std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->hit_pts = 100;
    this->energy_pts = 100;
    this->attack_dmg = 30;
    std::cout << "FragTrap Constructor for the name " << this->name << " called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Deconstructor for " << this->name << " called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
    std::cout << "FragTrap Assignation operator called" << std::endl;
    this->name = src.name;
    this->hit_pts = src.hit_pts;
    this->energy_pts = src.energy_pts;
    this->attack_dmg = src.attack_dmg;
    return *this;
}

void	FragTrap::highFiveGuys(void)
{
    std::cout << "FragTrap " << this->name << " gives a high five!!!" << std::endl;
}