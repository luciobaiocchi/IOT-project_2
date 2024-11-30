#include "SerialCommTask.h"
#include "ContainerProp.h"

SerialCommTask::SerialCommTask(ContainerProp& container) : container(container){
    MsgService.init();
    this->msgFullSent = false;
    this->msgAllarmSent = false;
}

void SerialCommTask::init(int period){
    Task::init(period);   
}


void SerialCommTask::tick(){
    if (container.isFull() && !this->msgFullSent){
        msgFullSent = true;
        MsgService.sendMsg("F");   
    }
    if (container.isAllarmOn() && !this->msgAllarmSent){
        msgFullSent = true;
        MsgService.sendMsg("A");   
    }
    if (container.genericAllarm()){
        receive();
    }else{
        send();
    }
}

void SerialCommTask::receive(){
    if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();    
        if (container.isAllarmOn() && msg->getContent() == "R" ){
            this->msgAllarmSent = false;
            this->container.restoreAllarm();
        }else if(container.isFull() && msg->getContent() == "E"){
            this->msgFullSent = false;
            this->container.emptyContainer();
        }
    delete msg;
  }

}

void SerialCommTask::send(){
    String message = "L" + (String)this->container.getWasteLevel() + "T" + (String)this->container.getTempLevel();
    MsgService.sendMsg(message);
}
