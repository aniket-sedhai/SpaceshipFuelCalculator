//
//  main.cpp
//  SpaceshipFuelCalculator
//
//  Created by Aniket Sedhai on 6/16/24.
//

#include <iostream>
#include <stdint.h>

uint32_t calculate_total_launch_mass(uint32_t spaceship_mass);

int main(void) 
{
    int32_t spaceship_mass;
    while(1)
    {
        std::cout << "Enter mass for spaceship [-1 to quit]: ";
        std::cin >> spaceship_mass;
        
        /*check if the input is invalid*/
        if (std::cin.fail())
        {
            std::cout << "Invalid input!!!" << std::endl;
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else /*in case of valid integer input, do the following*/
        {
            /*quit if the user entered -1*/
            if (spaceship_mass == -1)
            {
                return 0;
            }
            /*if the user entered a 0 or positive value, calculate the total fuel required*/
            else if (spaceship_mass >= 0)
            {
                std::cout << "Total fuel required to launch: " << 
                calculate_total_launch_mass(spaceship_mass) << std::endl << std::endl;
            }
            /*if the user entered any integer < -1*/
            else
            {
                std::cout << "Invalid input!!!" << std::endl;
            }
        }
    }
    
    return 0;
}

/**
 * @brief This method calculates the total mass at lauch of a spaceship,
 * which includes the mass of the spaceship and the fuel it uses.
 *
 * @param[in] spaceship_mass - mass of the spaceship
 *
 * @return total_launch_mass - the toal mass during lauch of the spaceship.
 */
uint32_t calculate_total_launch_mass(uint32_t spaceship_mass)
{
    uint32_t total_launch_mass = 0;
    uint32_t one_fifth_mass = 0;
    int32_t fuel_mass = 0;
    
    /*calculate the one fifth of the fuel mass*/
    one_fifth_mass = spaceship_mass/5;
    
    fuel_mass = one_fifth_mass - 22;
    if (fuel_mass < 0)
    {
        fuel_mass = 0;
    }
    
    total_launch_mass = spaceship_mass + fuel_mass;
    
    return total_launch_mass;
}
