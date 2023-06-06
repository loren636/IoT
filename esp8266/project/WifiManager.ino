/*
此项目引用太极创客 http://www.taichi-maker.com/homepage/esp8266-nodemcu-iot/iot-c/esp8266-tips/wifimanager/
测试WiFiManager库所配置的ESP8266的确可以连接到互联网，并从互联网上的网络服务器获取信息
并将信息保存到eebrom闪存中，供下次自动连接
*/
#include <ESP8266WiFi.h>          
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         

void setup() {
    Serial.begin(115200);       
    // 建立WiFiManager对象
    WiFiManager wifiManager;
    
    // 自动连接WiFi。以下语句的参数是连接ESP8266时的WiFi名称
    wifiManager.autoConnect("AutoConnectAP");
    
    // 如果您希望该WiFi添加密码，可以使用以下语句：
    // wifiManager.autoConnect("AutoConnectAP", "12345678");
    // 以上语句中的12345678是连接AutoConnectAP的密码
    
    // WiFi连接成功后将通过串口监视器输出连接成功信息 
    Serial.println(""); 
    Serial.print("ESP8266 Connected to ");
    Serial.println(WiFi.SSID());              // WiFi名称
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP());           // IP
}
 
void loop() {}
