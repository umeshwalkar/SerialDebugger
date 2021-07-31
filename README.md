# SerialDebugger

This is an Arduino Stream class that can be use to dump incomming and outgoing data to another Serial Stream for debugging purpose.
The debugging can be enabled or disabled in runtime.

## How To Use:

```cpp
#include <SerialDebugger.h>

SerialDebugger dbgSerial(Serial1, Serial);

...

void setup() {
    // serial that use for debug
    Serial.begin(115200);
    
    // Serial that need to be monitor
    Serial1.begin(9600);
    
    dbgSerial.println("Hello World!!!");
    
    //now every sent or received character on 'Serial1' will be transmitted to 'Serial' terminal.

}

void loop()
{
    static uint32_t timeout = 0;

    if(millis() - timeout > 300000)
    {
        // disable serial monitoring in runtime when not required.
        dbgSerial.enable(false);

        timeout = millis();
    }
    
    if(millis() - timeout > 300000)
    {
        // enable again serial monitoring in runtime, if required.
        dbgSerial.enable(true);

        timeout = millis();
    }
}
```

