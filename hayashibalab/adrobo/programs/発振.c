// 発振させたプログラム

#include "mbed.h"
#include "adrobo.h"
#include "Motor.h"
#include "QEI.h"

BusOut led(LED1,LED2,LED3,LED4);
Motor motor_left(MOTOR11,MOTOR12);
Motor motor_right(MOTOR21,MOTOR22);
BusIn in(GPIO5, GPIO4, GPIO3, GPIO2, GPIO1);
QEI qei_left(GPIO1, GPIO2, NC, 48, QEI::X4_ENCODING);
QEI qei_right(GPIO3, GPIO4, NC, 48, QEI::X4_ENCODING);

Ticker control;

double speed_left_ref = 0.2, speed_right_ref = 0.2;   // Default:0.2 // 目標値
double speed_left_lpf = 0.0, speed_right_lpf = 0.0; // 現在の値
const double sampling_time = 0.020;
const double move_per_pulse = 0.0005;
double i_left = 0.0, i_right = 0.0;
const double kir = 0.0, kpr = 6.5 * 0.8;
const double kil = 0.0, kpl = 6.5 * 0.8;

/*
発振条件
92% => kp = 7.0
*/

double low_pass_filter(double val, double pre_val, double gamma)
{
    return gamma * pre_val + (1.0 - gamma) * val;
}

void control_handler()
{
    int enc_left = qei_left.getPulses();
    int enc_right = qei_right.getPulses();
    qei_left.reset();
    qei_right.reset();
    double speed_left = -move_per_pulse * enc_left / sampling_time;
    double speed_right = move_per_pulse * enc_right / sampling_time;
    speed_left_lpf = low_pass_filter(speed_left, speed_left_lpf, 0.4);
    speed_right_lpf = low_pass_filter(speed_right, speed_right_lpf, 0.4);
    double delta_speed_left = speed_left_ref - speed_left_lpf;
    double delta_speed_right = speed_right_ref - speed_right_lpf;
    i_left += delta_speed_left * sampling_time;
    i_right += delta_speed_right * sampling_time;
    motor_left = (kpl * delta_speed_left + kil * i_left);
    motor_right = (kpr * delta_speed_right + kir * i_right);
}

int main()
{
    in.mode(PullUp);
//    float i= 1.0 * 0.35, k = 1.0 * 0.35;
    motor_left.setMaxRatio(1.0); /* 初期設定が最大出力は 25％か 100％に設定*/
    motor_right.setMaxRatio(1.0);
    control.attach(&control_handler, sampling_time);
    led = 1;

    while(1)
    {
        int enc_left = qei_left.getPulses();
        int enc_right = qei_right.getPulses();
        qei_left.reset();
        qei_right.reset();
        double speed_left = move_per_pulse * enc_left / sampling_time;
        double speed_right = move_per_pulse * enc_right / sampling_time;
        
        printf("%f %f\r\n",speed_left, -speed_right);
        
//        motor_left = i;
//        motor_right = k;

        speed_left = speed_right = 0;
        wait(0.1);
    }
}


