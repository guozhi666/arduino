int ledPin = 13;            //定义LED接口为13
int delayTime = 1000;       //定义延时1为1000ms
int delayTime2 = 3000;      //定义延时2为3000ms
void setup()
{
  pinMode(ledPin, OUTPUT);  //定义13接口为输出接口
}

void loop()
{
  for (int count = 0; count <5; count++)   
  {
    flash(delayTime);       //调用flash函数，灯光闪烁5次为一循环，每循环延时3S
  }
  delay(delayTime2);
}

void flash(int delayTime3)  //自定义函数，便于调用方法
{
  digitalWrite(ledPin,HIGH);    //高电平
  delay(delayTime3);
  digitalWrite(ledPin, LOW);    //低电平
  delay(delayTime3);
}

