#include "ClapTrap.hpp"


ClapTrap::ClapTrap(): name("default"), hit_pts(10), energy_pts(10), attack_dmg(0)
{
    std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "ClapTrap Copy Constructor called" << std::endl;
    *this = copy;
}

ClapTrap::ClapTrap(std::string name): name(name), hit_pts(10), energy_pts(10), attack_dmg(0)
{
    std::cout << "ClapTrap Constructor for the name " << name << " called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Deconstructor for " << name << " called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
    std::cout << "ClapTrap Assignation operator called" << std::endl;
    this->name = src.name;
    this->hit_pts = src.hit_pts;
    this->energy_pts = src.energy_pts;
    this->attack_dmg = src.attack_dmg;
    return *this;
}

void	ClapTrap::attack(const std::string &target)
{
    if (this->energy_pts > 0 && this->hit_pts > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_dmg << " points of damage!" << std::endl;
        this->energy_pts--;
    }
    else if (this->energy_pts == 0)
        std::cout << "ClapTrap " << this->name << " is not able to attack " << target << ", because he has no energy points left." << std::endl;
    else
        std::cout << "ClapTrap " << this->name << " is not able to attack " << target << ", because he has not enough hit points." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_pts > amount)
        this->hit_pts -= amount;
    else if (this->hit_pts > 0)
        this->hit_pts = 0;
    else
    {
        std::cout << "ClapTrap " << this->name << " is already dead, stop beating it." << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " was attacked and lost " << amount << " hit points, he now has " << this->hit_pts << " hit points." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energy_pts > 0 && this->hit_pts > 0 && this->hit_pts + amount <= 10)
    {
        this->hit_pts += amount;
        std::cout << "ClapTrap " << this->name << " repaired itself and gained " << amount << " of hit points, he now has " << this->hit_pts << "hit points." << std::endl;
        this->energy_pts--;
    }
    else if (this->energy_pts == 0)
        std::cout << "ClapTrap " << this->name << " is not able to repair itself, because he doesn't have enough energy points." << std::endl;
    else if (this->hit_pts == 0)
        std::cout << "ClapTrap " << this->name << " is not able to repair itself, because he doesn't have enough hit points." << std::endl;
    else
        std::cout << "ClapTrap " << this->name << " can't be repaired to have more than 10 hit points." << std::endl;
}