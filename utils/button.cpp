#include <Arduino.h>
#include <button.h>

/*
 *  Button
 *
 */


void Button::init() {
    _state = BUTTON_RELEASED;
    pinMode(this->pin, INPUT);
}

void Button::handle() {
    int value = digitalRead(this->pin);

    if (_state == BUTTON_RELEASED && value == HIGH) {
        _state = BUTTON_PRESSED;
        pressed();
    }
    else if (_state == BUTTON_PRESSED && value == LOW){
        _state = BUTTON_RELEASED;
        released();
    }
}

bool Button::is_pressed() {
    return _state == BUTTON_PRESSED;
}

void Button::pressed() {}
void Button::released() {}



