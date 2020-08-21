#include <cstring>
#include <cstdlib>
#include <Components/Alarm/AlarmController.h>
#include <SystemTask/SystemTask.h>

using namespace Pinetime::Controllers;

void xtimerCallback(TimerHandle_t xTimer){
    NRF_LOG_INFO("TIMER CALLED ");
    auto alarm = static_cast<AlarmController *>(pvTimerGetTimerID(xTimer));
    alarm ->alarmCallback();
}

AlarmController::AlarmController(Pinetime::System::SystemTask& systemTask, 
    Pinetime::Controllers::VibrationMotorController& vibrationmotor) : 
    systemTask{systemTask}, vibrationmotor{vibrationmotor} {

}

bool AlarmController::setxTimer(int diff) {
    alarmTimer = xTimerCreate ("alarmTimer", pdMS_TO_TICKS(diff*60*1000), pdFALSE, this, xtimerCallback);
    if(alarmTimer != NULL){
        xTimerStart(alarmTimer, 0);
        NRF_LOG_INFO("alarm started");
        return true;
    }
    else{
        return false;
    }

}

void AlarmController::alarmCallback() {
    NRF_LOG_INFO("vibration motor turned on");
    vibrationmotor.TurnOn();
    systemTask.PushMessage(Pinetime::System::SystemTask::Messages::OnAlarmGoOff);
}

