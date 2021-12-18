#include "mbed.h"
#include "QEI.h"
#include "adrobo.h"
#include "Motor.h"
#include "ReceiverIR.h"
ReceiverIR  Ir_RX(PA_0);
RemoteIR::Format format;
uint8_t buf[32];
uint32_t bitcount;
BusOut led(LED1, LED2, LED3, LED4,LED5);
BusIn in(PA_8, PA_9, PA_10, PA_11);
QEI qei_left(PA_8, PA_9, NC, 48, QEI::X4_ENCODING);
QEI qei_right(PA_10, PA_11, NC, 48, QEI::X4_ENCODING);
Motor motor_left(MOTOR11,MOTOR12);
Motor motor_right(MOTOR21,MOTOR22);
double speed_left_ref = 0.2, speed_right_ref = 0.2;
double speed_left_lpf = 0.0, speed_right_lpf = 0.0;
const double sampling_time = 0.020;
const double move_per_pulse = 0.0005;
double i_left = 0.0, i_right = 0.0;
double ki = 0.0, kp = 1.0;
static double speed_left,speed_right;
static double delta_speed_left,delta_speed_right;
double low_pass_filter(double val, double pre_val, double gamma) {
return gamma * pre_val + (1.0 - gamma) * val;
}
void control_handler() {
    int enc_left = qei_left.getPulses();
    int enc_right = qei_right.getPulses();
    qei_left.reset();
    qei_right.reset();
    speed_left = -move_per_pulse * enc_left / sampling_time;
    speed_right = move_per_pulse * enc_right / sampling_time;
    speed_left_lpf = low_pass_filter(speed_left, speed_left_lpf, 0.4);
    speed_right_lpf = low_pass_filter(speed_right, speed_right_lpf, 0.4);
    delta_speed_left = speed_left_ref - speed_left_lpf;
    delta_speed_right = speed_right_ref - speed_right_lpf;
    i_left += delta_speed_left * sampling_time;
    i_right += delta_speed_right * sampling_time;
    motor_left = kp * delta_speed_left + ki * i_left;
    motor_right = kp * delta_speed_right + ki * i_right;
    }
void init(){
    led = 0b00000;
    printf("\n");
    //赤外線入力
    while(1){
        if (Ir_RX.getState() == ReceiverIR::Received) {
            // コード受信
            bitcount = Ir_RX.getData(&format, buf, sizeof(buf) * 8);
            if(bitcount < 1) continue;
            switch(buf[2]){
                case 0x47:
                    led = 0b00100;
                    printf("P:%.2f\tI:%.2f\r\n",kp,ki);
                    return;
                case 0x45:
                    led = 0b10000;
                    kp += 0.1;
                    break;
                case 0x46:
                    led = 0b00001;
                    kp -= 0.1;
                    break;
                case 0x44:
                    led = 0b01000;
                    ki += 0.1;
                    break;
                case 0x40:
                    led = 0b00010;
                    ki -= 0.1;
                    break;
            }
                wait_us(100*1000);
                led = 0b00000;
        }
    }
    }
Ticker control;
int main() {
    init();
    in.mode(PullUp);
    motor_left.setMaxRatio(1.0);
    motor_right.setMaxRatio(1.0);
    control.attach(&control_handler, sampling_time);
    while(1){
        if (Ir_RX.getState() == ReceiverIR::Received) {
                bitcount = Ir_RX.getData(&format, buf, sizeof(buf) * 8);
                if(bitcount < 1) continue;
                switch(buf[2]){
                    case 0x47:
                        NVIC_SystemReset();
                        break;
                }
        }
        printf("l:%.3f\tr:%.3f\r\n",delta_speed_left,delta_speed_right);
    }
    }
