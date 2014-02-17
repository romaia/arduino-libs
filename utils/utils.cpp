#include <Arduino.h>
#include <utils.h>


EventHandler::EventHandler(){}

void EventHandler::add_gadget(BaseGadget *gadget) {
}

void BaseGadget::init() {}



/*
 *  Button
 *
 */

void ButtonHandler::init(int pin) {
    Serial.println("button init");
    _pin = pin;
    _state = BUTTON_RELEASED;
    pinMode(_pin, INPUT);
}

int ButtonHandler::handle() {
    int value = digitalRead(_pin);

    if (_state == BUTTON_RELEASED && value == HIGH) {
        _state = BUTTON_PRESSED;
        pressed();
    }
    else if (_state == BUTTON_PRESSED && value == LOW){
        _state = BUTTON_RELEASED;
        released();
    }
}

bool ButtonHandler::is_pressed() {
    return _state == BUTTON_PRESSED;
}

void ButtonHandler::pressed() {}
void ButtonHandler::released() {}


/*
 *  LED
 *
 */

void Led::init(int pin) {
    _pin = pin;
    _state = LED_OFF;
    pinMode(pin, OUTPUT);
}


void Led::turn_on() {
    _state = LED_ON;
    digitalWrite(_pin, HIGH);
}

void Led::turn_off() {
    _state = LED_OFF;
    digitalWrite(_pin, LOW);
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

int Led::handle() {
    if (_interval <= 0)
        return 0;

    int now = millis();
    if ((now - _last_blink) >= _interval) {
        _last_blink = now;
        toggle();
    }
}

