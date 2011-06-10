/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import lejos.nxt.*;
import lejos.nxt.remote.*;
import java.io.*;
import java.net.*;
import java.util.regex.*;

/**
 */
public class BTExecutorEx {
    private LightSensor light = null;
    private SoundSensor sound = null;
    private TouchSensor touch = null;
    private UltrasonicSensor ultra = null;

    private RemoteMotor[] rd = new RemoteMotor[3];
//    private RemoteBattery battery = null;
    private ServerSocket serv;

    //private
    private BTExecutorEx() throws Throwable
    {
        light = new LightSensor(SensorPort.S1);
        //sound = new SoundSensor(SensorPort.S2);
        touch = new TouchSensor(SensorPort.S3);
        ultra = new UltrasonicSensor(SensorPort.S4);

        rd[ 0 ] = Motor.A;
        rd[ 1 ] = Motor.C;
        rd[ 2 ] = Motor.B;

//        battery = new RemoteBattery();
        light.setFloodlight(false);

        serv = new ServerSocket(20042, 10);
        Socket sock = serv.accept();
        BufferedReader recv = new BufferedReader(new InputStreamReader(sock.getInputStream()));
        PrintStream send = new PrintStream(sock.getOutputStream());
        rd[ 0 ].regulateSpeed(true);
        rd[ 1 ].regulateSpeed(true);


        boolean q = true;
        do {
            /*System.out.println( "L: " + light.getLightValue() );
            //System.out.println( "S: " + sound.readValue() );
            System.out.println( "T: " + touch.isPressed() );
            System.out.println( "U: " + ultra.getDistance() );*/
            System.out.println( "B: " + Battery.getVoltage() );
            /*System.out.println();
            rd[ 0 ].setPower( light.getLightValue() );
            rd[ 0 ].forward();
            q = !touch.isPressed();*/
            String cmd = recv.readLine();
            String sensName, answer;
            if( cmd == null || cmd.length() <= 1 ) {
                System.out.println("Oops");
                break;
            }
            System.out.println(cmd);
            System.out.println(cmd.charAt(0));
            answer = null;
            switch( cmd.charAt(0) ) {
            case 'G':
                sensName = cmd.substring(1);
                if( sensName.equals("RD_0") ) {
                    rd[ 0 ].getPower();
                } else if( sensName.equals("RD_1") ) {
                    rd[ 1 ].getPower();
                } else if( sensName.equals("ST") ) {
                    answer = touch.isPressed() ? "1" : "0";
                } else if( sensName.equals("SL") ) {
                    answer = "" + ( light.getLightValue() / 100.0 );
                } else if( sensName.equals("SD") ) {
                    answer = "" + ( ultra.getDistance() / 100.0 );
                } else if( sensName.equals("SC") ) {
                    answer = "" + ( Battery.getVoltage() );
                }
                break;
            case 'S':
                Pattern p = Pattern.compile("^.(\\w+)=(-?[\\d\\.]+)");
                Matcher m = p.matcher(cmd);
                answer = "ERR";
                if( m.matches() ) {
                    String name = m.group(1);
                    String svalue = m.group(2);
                    System.out.println( "!!" + name + "===" + svalue );
                    double value = Double.parseDouble(svalue);
                    if( name.equals("RD_0") ) {
                        rd[ 0 ].setPower( (int) ( value * 100.0 ) );
                        rd[ 0 ].forward();
                        answer = "OK";
                    } else if( name.equals("RD_1") ) {
                        rd[ 1 ].setPower( (int) ( value * 100.0 ) );
                        rd[ 1 ].forward();
                        answer = "OK";
                    }
                }
                break;
            }
            if( answer != null ) {
                send.println(answer);
                System.out.println(answer);
                send.flush();
                //sock.getOutputStream().flush();
            } else {
                System.out.println("!!!!");
            }
        } while( q );
        rd[ 0 ].stop();
        rd[ 0 ].flt();
        ultra.off();
        //light.setFloodlight(false);
    }

    public static void main(String[] args)
    {
        try {
            new BTExecutor();
        }
        catch( Throwable ex ) {
            ex.printStackTrace( System.out );
        }
    }
}

