#pragma once

#include <FreeRTOS.h>
#include <Components/VibrationMotor/VibrationMotorController.h>
#include <timers.h>

namespace Pinetime {
  namespace System{
    class SystemTask;
  }
  namespace Controllers {
    class AlarmController {
      public:

        AlarmController(Pinetime::System::SystemTask& systemTask, Pinetime::Controllers::VibrationMotorController& vibrationmotor);

        bool setxTimer(int diff);
        void alarmCallback();

      private:
        
        Pinetime::System::SystemTask& systemTask;
        Pinetime::Controllers::VibrationMotorController& vibrationmotor;

        //timer variable declaration
        TimerHandle_t alarmTimer;


    };
  }
}