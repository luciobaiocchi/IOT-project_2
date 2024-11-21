package model;

import utilities.CommChannel;
import utilities.SerialCommChannel;
import utilities.State;

public class Loop extends Thread{
    private CommChannel channel;

    public Loop(){

    }

    public void run() {


        try {
            channel = new SerialCommChannel("/dev/cu.usbserial-10", 9600);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }


        while(true){
        }
    }
}
