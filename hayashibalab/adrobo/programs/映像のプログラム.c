// 映像のプログラム

#include "mbed.h"
#include "adrobo.h"
#include "Motor.h"
#include "QEI.h"
#include "./path_data.h"

BusOut led(LED5, LED4, LED3, LED2, LED1);
Ticker control;
Motor motor_left(MOTOR11, MOTOR12);
Motor motor_right(MOTOR21, MOTOR22);
BusIn in(GPIO1, GPIO2, GPIO3, GPIO4, GPIO5);
QEI qei_left(GPIO1, GPIO2, NC, 48, QEI::X4_ENCODING);
QEI qei_right(GPIO3, GPIO4, NC, 48, QEI::X4_ENCODING);

double speed_left_ref = 0, speed_right_ref = 0;
double speed_left_lpf = 0, speed_right_lpf = 0;
int t_cnt = 0;
int vpath_idx = 0;

const double sampling_time = 0.02;
const double move_per_pulse = 0.0005;
double i_left = 0, i_right = 0;
const double kir = 10, kpr = 5 * 0.8;
const double kil = 10 * 0.995, kpl = 5 * 0.8;

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
    double speed_left = - move_per_pulse * enc_left / sampling_time;
    double speed_right = move_per_pulse * enc_right / sampling_time;
    speed_left_lpf = low_pass_filter(speed_left, speed_left_lpf, 0.4);
    speed_right_lpf = low_pass_filter(speed_right, speed_right_lpf, 0.4);
    if(t_cnt == 5)
    {
        vpath_idx++;
        t_cnt = 0;
    }
    if(vpath_idx < MaxNum)
    {
        speed_right_ref = (double) velo_data[vpath_idx * 2] / 1000;
        speed_left_ref = (double) velo_data[vpath_idx * 2] / 1000;
    }
    else
    {
        speed_right_ref = 0;
        speed_left_ref = 0;
    }
    double delta_speed_left = speed_left_ref - speed_left_lpf;
    double delta_speed_right = speed_right_ref - speed_right_lpf;
    i_left += delta_speed_left * sampling_time;
    i_right += delta_speed_right * sampling_time;
    motor_left = kp * delta_speed_left + ki * i_left;
    motor_right = kp * delta_speed_right + ki * i_right;
    t_cnt++;
}

int main()
{
    in.mode(PullUp);
    motor_left.setMaxRatio(1.0); /* 初期設定が最大出力は 25％か 100％に設定*/
    motor_right.setMaxRatio(1.0);
    control.attach(&control_handler, sampling_time);
    led = 1;

    while(1)
    {
        led = led ^ 1;
        wait(0.1);
    }
}






