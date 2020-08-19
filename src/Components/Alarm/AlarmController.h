#pragma once

#include <FreeRTOS.h>
#include <Components/VibrationMotor/VibrationMotorController.h>

namespace Pinetime {
  namespace Controllers {
    class AlarmController {
      public:

        AlarmController(Pinetime::System::SystemTask& systemTask, Controllers::VibrationMotorController &vibrationmotor);

        void setxTimer(int diff);
        void alarmCallback();

      private:
        
        Pinetime::System::SystemTask &systemTask;
        Controllers::VibrationMotorController& vibrationmotor;

        //timer variable declaration
        TimerHandle_t alarmTimer;


    };
  }
}