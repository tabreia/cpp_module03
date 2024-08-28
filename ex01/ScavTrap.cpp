#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
    this->hit_pts = 100;
    this->energy_pts = 50;
    this->attack_dmg = 20;
    this->guarding_gate = false;
    std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
    this->guarding_gate = copy.guarding_gate;
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    this->hit_pts = 100;
    this->energy_pts = 50;
    this->attack_dmg = 20;
    this->guarding_gate = false;
    std::cout << "ScavTrap Constructor for the name " << this->name << " called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Deconstructor for " << this->name << " called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
    std::cout << "ScavTrap Assignation operator called" << std::endl;
    this->name = src.name;
    this->hit_pts = src.hit_pts;
    this->energy_pts = src.energy_pts;
    this->attack_dmg = src.attack_dmg;
    return *this;
}

void	ScavTrap::attack(const std::string &target)
{
    if (this->energy_pts > 0 && this->hit_pts > 0)
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_dmg << " points of damage!" << std::endl;
        this->energy_pts--;
    }
    else if (this->energy_pts == 0)
        std::cout << "ScavTrap " << this->name << " is not able to attack " << target << ", because he has no energy points left." << std::endl;
    else
        std::cout << "ScavTrap " << this->name << " is not able to attack " << target << ", because he has not enough hit points." << std::endl;
}

void	ScavTrap::guardGate(void)
{
    if (this->guarding_gate == false)
    {
        this->guarding_gate = true;
        std::cout << "ScavTrap " << this->name << " is now guarding the gate." << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->name << " is already guarding the gate." << std::endl;
}