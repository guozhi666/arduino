#include<LiquidCrystal.h>       //引用自带的库
#include<OneWire.h>             //调用arduino单总线库
#include<DallasTemperature.h>   //调用ds18b20温度传感器库

#define ONE_WIRE_BUS 2                  //设置单总线数据I/O口为2引脚
OneWire temp(ONE_WIRE_BUS);             //初始化一个单总线类
DallasTemperature sensors(&temp);       //初始化一个温度传感器类
LiquidCrystal lcd(12, 11, 9, 8, 7, 6);  //初始化一个LiquidCrystal，RS为12引脚，E为11引脚，9-6为数据输入引脚
float temperature = 0;                  //设置温度为浮点变量

void setup()
{
  Serial.begin(9600);                   //初始化串口
  sensors.begin();                      //初始化温度传感器
  lcd.begin(16, 2);                     //初始化LED
  lcd.print("Arduino world");           
  delay(1000);
}

void loop()
{
  sensors.requestTemperatures();            //对温度传感器发出温度请求
  temperature = sensors.getTempCByIndex(0); //读取传感器数据，以摄氏度单位赋值
  delay(100);
  temperature = (temperature*10);           
  lcd.clear();                              //清屏
  lcd.print("temperature is");
  lcd.setCursor(0, 1);                      //设置光标位置为第二行第一个位置
  lcd.print((long)temperature/10);          //显示温度整数位
  lcd.print(".");
  lcd.print((long)temperature%10);
  lcd.print((char)223);                     
  lcd.print("C");
  delay(1000);
}
