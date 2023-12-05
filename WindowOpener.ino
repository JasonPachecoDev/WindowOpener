
#include <Stepper.h>
#include <TimeLib.h>

int stepsPerRev = 2048;
int motSpeed = 10;
int lastHour = -1;
Stepper myStepper(stepsPerRev, 8,10,9,11);


void setup() 
{
  Serial.begin(9600);
  myStepper.setSpeed(motSpeed);
  setTime(14, 59, 54, 2, 12, 2023);
  Serial.println("Setup complete");
}

void loop() 
{
  int currentHour = hour();

  if (currentHour == 6 && currentHour != lastHour)
  {
    StepperFunc();
  }
  if (currentHour == 22 && currentHour != lastHour)
  {
    StepperFunc();
  }

  delay(1000);
}

void StepperFunc() 
{
  Serial.println("StepperFunc triggered at: " + String(hour()) + ":" + String(minute()) + ":" + String(second()));
  myStepper.step(-stepsPerRev * 4);
  Serial.println("Success");
  lastHour = hour();
} 
