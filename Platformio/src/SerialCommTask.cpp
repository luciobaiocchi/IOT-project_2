#include "SerialCommTask.h"
#include "ContainerProp.h"

SerialCommTask::SerialCommTask(ContainerProp container) : container(container){
    MsgService.init();
}

void SerialCommTask::init(int period){
    Task::init(period);   
}

void SerialCommTask::tick(){
    if (container.genericAllarm()){
        receive();
    }else{
        // send();
    }
}

void SerialCommTask::receive(){
    if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();    
        if (container.isAllarmOn() && msg->getContent() == "RESTORE" ){
            /* Metodo in container per settare l'allarme off*/
        }else if(container.isFull() && msg->getContent() == "EMPTY"){
            /* Metodo per svuotare */
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
