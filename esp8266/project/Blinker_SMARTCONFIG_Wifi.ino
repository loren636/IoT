/*
项目说明：1、可通过公众号"安信可科技"->"应用开发" -> "微信配网" 设置WiFi信息 
         2、也可以通过Android版本的"点灯blinker"APP "开发者"->"SmartConfig" 配置WiFi信息
*/
#define BLINKER_WIFI
#define BLINKER_ESP_SMARTCONFIG

#include <Blinker.h>


char auth[] = "0a56555a9f05";
//char ssid[] = "SHHJ";
//char pswd[] = "hujiao.2022";

// 新建组件对象
BlinkerButton Button1("btn-abc");
BlinkerNumber Number1("num-abc");

int counter = 0;

// 按下按键即会执行该函数
void button1_callback(const String & state)
{
    BLINKER_LOG("get button state: ", state);
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

// 如果未绑定的组件被触发，则会执行其中内容
void dataRead(const String & data)
{
    BLINKER_LOG("Blinker readString: ", data);
    counter++;
    Number1.print(counter);
}

void setup()
{
    // 初始化串口
    Serial.begin(115200);
    BLINKER_DEBUG.stream(Serial);
    BLINKER_DEBUG.debugAll();

    // 初始化有LED的IO
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    // 初始化blinker
    //Blinker.begin(auth, ssid, pswd);
    Blinker.begin(auth);
    Blinker.attachData(dataRead);

    Button1.attach(button1_callback);
}

void loop() {
    Blinker.run();
}
