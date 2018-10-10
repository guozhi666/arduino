int FlameSensor = A5;       //定义火焰传感器接口为模拟接口5
int Beep = 7;               //定义蜂鸣器接口为数字接口7
int Value = 0;              //定义数字变量

void setup()
{
  pinMode(Beep, OUTPUT);        //定义蜂鸣器接口为输出接口
  pinMode(FlameSensor, INPUT);  
  Serial.begin(9600);           //设定波特率为9600
}

void loop()
{
  Value = analogRead(FlameSensor);  //读取火焰传感器的模拟值
  Serial.println(Value);            //输出模拟值
  if (Value >= 600)                 //设置蜂鸣器响应的临界值
  {
    digitalWrite(Beep, HIGH);
  }
  else
  {
    digitalWrite(Beep, LOW);
  }
}
