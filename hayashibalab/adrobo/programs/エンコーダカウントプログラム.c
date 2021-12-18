// エンコーダカウントプログラム

#include "mbed.h"
#include "Motor.h"
#include "adrobo.h"
#include "QEI.h"

BusOut led(LED1,LED2,LED3,LED4);
BusIn in(GPIO5, GPIO4, GPIO3, GPIO2, GPIO1);
QEI qei_left(GPIO1, GPIO2, NC, 48, QEI::X4_ENCODING);
QEI qei_right(GPIO3, GPIO4, NC, 48, QEI::X4_ENCODING);
Motor motor_left(MOTOR11,MOTOR12);
Motor motor_right(MOTOR21,MOTOR22);

const double sampling_time = 0.020;
const double move_per_pulse = 0.0005;

int main()
{
    in.mode(PullUp);
    float i= 1.0 * 0.35, k = 1.0 * 0.35;
    motor_left.setMaxRatio(1.0); /* 初期設定が最大出力は 25％か 100％に設定*/
    motor_right.setMaxRatio(1.0);

    while(1)
    {
        int enc_left = qei_left.getPulses();
        int enc_right = qei_right.getPulses();
        qei_left.reset();
        qei_right.reset();
        double speed_left = move_per_pulse * enc_left / sampling_time;
        double speed_right = move_per_pulse * enc_right / sampling_time;
        
        printf("%f %f\r\n",speed_left, -speed_right);
        
        motor_left = i;
        motor_right = k;

        speed_left = speed_right = 0;
        wait(0.1);
    }
}
