#include <Arduino.h>
#include <led.h>


/*
 *  LED
 *
 */

void Led::init() {
    _state = LED_OFF;
    pinMode(this->pin, OUTPUT);
}


void Led::turn_on() {
    _state = LED_ON;
    digitalWrite(this->pin, HIGH);
}

void Led::turn_off() {
    _state = LED_OFF;
    digitalWrite(this->pin, LOW);
}

void Led::toggle() {
    if (_state == LED_OFF)
        turn_on();
    else
        turn_off();
}

void Led::blink(int interval) {
    _interval = interval;
    _last_blink = 0;
}

bool Led::is_blinking() {
    return _interval > 0;
}

void Led::handle() {
    if (_interval <= 0)
        return;

    int now = millis();
    if ((now - _last_blink) >= _interval) {
        _last_blink = now;
        toggle();
    }
}
