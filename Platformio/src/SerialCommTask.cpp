#include "SerialCommTask.h"

SerialCommTask::SerialCommTask(){
    MsgService.init();
}

void SerialCommTask::init(int period){
    Task::init(period);   
}

void SerialCommTask::tick(){
    if (currentState == TMP_ALLARM || currentState == CONTAINER_FULL){
        receive();
    }else{
        send();
    }
}

void SerialCommTask::receive(){
    if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();    
        if (msg->getContent() == (String)currentState){
            currentState = GATE_AVAILABLE;
        }
        delete msg;
    }

}

void SerialCommTask::send(){

}
