package model;

import utilities.CommChannel;
import utilities.SerialCommChannel;
import utilities.State;

public class Loop extends Thread{
    private CommChannel channel;
    private State currentState;


    public Loop(){}


    public void run() {


        try {
            channel = new SerialCommChannel("COM3", 9600);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }


        while(true){


        }
    }
}
