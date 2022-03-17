//=====[Libraries]=============================================================

#include "irrigation_system.h"

#include "buttons.h"
#include "user_interface.h"
#include "non_blocking_delay.h"
#include "moisture_sensor.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

static nonBlockingDelay_t irrigationSystemDelay;

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void irrigationSystemInit()
{
    tickInit();
    buttonsInit();
    userInterfaceInit();
    moistureSensorInit();
    nonBlockingDelayInit( &irrigationSystemDelay, SYSTEM_TIME_INCREMENT_MS );
}

void irrigationSystemUpdate()
{
    if( nonBlockingDelayRead(&irrigationSystemDelay) ) {
        buttonsUpdate();
        userInterfaceUpdate();
        moistureSensorUpdate();
    }
}

//=====[Implementations of private functions]==================================
