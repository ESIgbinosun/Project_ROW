#include "ADC.h"
#include <wiringPi.h>
#include <stdio.h>


#define START_BIT   0x04
#define MODE_SINGLE 0x02    // Single-ended mode
#define MODE_DIFF   0x00    // Differential mode


MCP3208::MCP3208(SPI bus, PinName cs)
        : m_cs(cs), m_bus(bus)
{}

MCP3208::~MCP3208() {}


void MCP3208::select() {m_cs = 0;}
void MCP3208::deselect() {m_cs = 1;}


float MCP3208::read_input(int channel)
{
    int command_high = START_BIT | MODE_SINGLE | ((channel & 0x04) >> 2);
    int command_low = (channel & 0x03) << 6;

    select();

    // Odd writing requirements, see the datasheet for details
    m_bus.write(command_high);
    int high_byte = m_bus.write(command_low) & 0x0F;
    int low_byte = m_bus.write(0);

    deselect();

    int conv_result = (high_byte << 8) | low_byte;

    return float(conv_result) / 4096;
}


//
// Created by stefa on 11/01/2022.
//

