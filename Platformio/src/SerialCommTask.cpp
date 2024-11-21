#include "SerialCommTask.h"
#include "ContainerProp.h"

SerialCommTask::SerialCommTask(ContainerProp container){
    this->container = container;
    MsgService.init();
}

void SerialCommTask::init(int period){
    Task::init(period);   
}

void SerialCommTask::tick(){
    if (container.isAllarmOn() || container.isFull()){
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
    if (MsgService.isMsgAvailable()) {
        const String message = "L" + (String)this->container.getWasteLevel() + "T" + (String)this->container.getTempLevel();
        MsgService.sendMsg(message);   
    }
}
