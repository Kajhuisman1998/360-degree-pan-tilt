#include <Stepper.h>

// define number of steps per revolution
int const STEPPER_STEPS = 32;

// define stepper motor 1 control pins
int const STEPPER_M1_IN1 = 8;  // Digital
int const STEPPER_M1_IN2 = 9;  // Digital
int const STEPPER_M1_IN3 = 10; // Digital
int const STEPPER_M1_IN4 = 11; // Digital

// define stepper motor 2 control pins
int const STEPPER_M2_IN1 = 4; // Digital
int const STEPPER_M2_IN2 = 5; // Digital
int const STEPPER_M2_IN3 = 6; // Digital
int const STEPPER_M2_IN4 = 7; // Digital

int const STEPPER_SPEED_LO = 50;      // Minimum speed (rpm)
int const STEPPER_SPEED_HI = 450;     // Maximum speed (rpm)
int const STEPPER_STEPS_PER_TICK = 1; // Steps to take per loop

// joystick pot output is connected to Arduino A0
int const CONTROL_PIN_X = A0;
int const CONTROL_PIN_Y = A1;

int const CONTROL_MIN = 0;       // Minimum controller value
int const CONTROL_MAX = 1023;    // Maximum controller value
int const CONTROL_DEADZONE = 15; // between 0 and (CONTROL_MAX / 2)

// initialize stepper library
Stepper stepperX(STEPPER_STEPS, STEPPER_M1_IN4, STEPPER_M1_IN2, STEPPER_M1_IN3, STEPPER_M1_IN1);
Stepper stepperY(STEPPER_STEPS, STEPPER_M2_IN4, STEPPER_M2_IN2, STEPPER_M2_IN3, STEPPER_M2_IN1);

void setup()
{
  
}

void loop()
{
  // read analog xue from the potentiometer
  // Als je een remote controller wilt gebruiken,
  // Zorg dan dat deze twee waarden tussen CONTROL_MIN en CONTROL_MAX zijn
  int direction_x = analogRead(CONTROL_PIN_X);
  int direction_y = analogRead(CONTROL_PIN_Y);

  int control_median = CONTROL_MAX / 2;

  // * BEGIN MOTOR X ***********************
  int control_x_absolute = abs(direction_x - control_median);
  int x_step_to = direction_x < control_median ? -STEPPER_STEPS_PER_TICK : STEPPER_STEPS_PER_TICK;

  if (control_x_absolute <= CONTROL_DEADZONE)
  {
    digitalWrite(STEPPER_M1_IN1, LOW);
    digitalWrite(STEPPER_M1_IN2, LOW);
    digitalWrite(STEPPER_M1_IN3, LOW);
    digitalWrite(STEPPER_M1_IN4, LOW);
  }
  else
  {
    int speed_x = map(control_x_absolute,
                    0,
                    control_median,
                    STEPPER_SPEED_LO,
                    STEPPER_SPEED_HI);

    stepperX.setSpeed(speed_x);
    stepperX.step(x_step_to);
  }
  // * EIND MOTOR X ***********************

  // * BEGIN MOTOR X ***********************
  int control_y_absolute = abs(direction_y - control_median);
  int y_step_to = direction_y < control_median ? -STEPPER_STEPS_PER_TICK : STEPPER_STEPS_PER_TICK;

  if (control_y_absolute <= CONTROL_DEADZONE)
  {
    digitalWrite(STEPPER_M2_IN1, LOW);
    digitalWrite(STEPPER_M2_IN2, LOW);
    digitalWrite(STEPPER_M2_IN3, LOW);
    digitalWrite(STEPPER_M2_IN4, LOW);
  }
  else
  {
    int speed_y = map(control_y_absolute,
                    0,
                    control_median,
                    STEPPER_SPEED_LO,
                    STEPPER_SPEED_HI);

    stepperY.setSpeed(speed_y);
    stepperY.step(y_step_to);
  }
  // * EIND MOTOR X ***********************
}
