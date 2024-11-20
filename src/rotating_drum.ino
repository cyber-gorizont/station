// ConstantSpeed.pde
// -*- mode: C++ -*-
//
// Shows how to run AccelStepper in the simplest,
// fixed speed mode with no accelerations
/// \author  Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2009 Mike McCauley
// $Id: ConstantSpeed.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

#include <AccelStepper.h>

#define motorStep 14
#define motorDir 12
#define motorEnable 4
AccelStepper stepper(1, motorStep, motorDir);
//AccelStepper stepper; // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

void setup()
{  
   stepper.setMaxSpeed(1000);
   stepper.setAcceleration(500.0);
}

void loop()
{  
   stepper.move(500);
   stepper.runToPosition();
   stepper.run();
   delay(100);
}
