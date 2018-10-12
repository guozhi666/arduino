#include <LiquidCrystal.h>
#include <DallasTemperature.h>
#include <OneWire.h>

#define ONE_WIRE_BUS 8
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//设置接口
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

void setup(void)
{
  lcd.begin(16, 2);  //初始化LCD

  delay(1000); //延时1000ms
  sensors.begin();
}

void loop(void)
{
  sensors.requestTemperatures(); // Send the command to get temperatures
  lcd.clear(); //清屏
  lcd.setCursor(0,0);
  lcd.print("Local Temperature");
  lcd.setCursor(0, 1) ; //设置光标位置为第二行第一个位置
  lcd.print(" is ");
  lcd.setCursor(5, 1) ;
  lcd.print( sensors.getTempCByIndex(0)); //获取温度
  //  delay(1000);
  lcd.print((char)223); //显示o符号
  lcd.print("C"); //显示字母C
  delay(1000);
}

