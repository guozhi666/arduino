int pin = 13;               //定义LED灯引脚13
volatile int state = LOW;   //定义初始电位为低电位

void setup()
{
  pinMode(pin, OUTPUT);     //定义13接口为输出接口
  attachInterrupt(0, blink, CHANGE );   //定义中断触发类型为CHANGE，并调用函数 blink，中断号为0，即数字2口，中断号为1是数字3口
}

void loop()
{
  digitalWrite(pin, state); //对指示灯写入状态值
}

void blink()
{
  state = !state;   //状态变量求反
}
