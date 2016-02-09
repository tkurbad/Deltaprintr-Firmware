#ifndef CONFIGURATION_BASIC_H
#define CONFIGURATION_BASIC_H

// This meta configuration file is used to decide what actual basic
// configuration will be used during compile time.
// Read the comments below to decide which one you want/need.

//===========================================================================
//==================== DeltaPrintr Configuration Choices ====================
//===========================================================================

// The Deltaprintr comes with FSR sensors for automatic bed levelling.
//
// In the standard setup, these are connected to the thermistor input for
// the heated bed on the Azteeg X3 motherboard.
// However, if you want to use a heated bed with your Deltaprintr, you
// have to free up this thermistor input and instead connect the FSRs to
// the (unused) input of the second hotend.
//
// To choose between the two options, include one of the following two
// configuration files.
// Any further adjustments should be made in the respective Configuration.h
// then.
//
// For automatic bed levelling with FSRs connected to the BED THERMISTOR
// INPUT (the default), uncomment the following include statement and comment
// the next one.
//
//#include "dp_config/fsr_bed/Configuration.h"

// For automatic bed levelling with FSRs connected to the THERMISTOR INPUT
// OF THE SECOND HOTEND (labeled '???' on the motherboard), comment the
// above include statement and uncomment the following.
//
#include "dp_config/fsr_temp1/Configuration.h"

#endif //__CONFIGURATION_BASIC_H
