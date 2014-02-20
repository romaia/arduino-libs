#include <Arduino.h>
#include <manager.h>


EventManager::EventManager():
    total_gadgets(0),
    total_timeouts(0)
{}

void EventManager::add_gadget(BaseGadget* gadget) {
    gadget->init();
    this->gadgets[this->total_gadgets] = gadget;
    this->total_gadgets++;
}

void EventManager::handle() {
    for (int i=0; i<this->total_gadgets; i++) {
        this->gadgets[i]->handle();
    }

    for (int i=0; i < this->total_timeouts; i++) {
        int last_call = this->last_call[i];
        // Dont call this again
        if (last_call < 0)
            continue;

        // Not yet time to call
        if (millis() - last_call < this->timeouts[i])
            continue;

        bool call_again = (*this->callbacks[i])();
        // TODO: Remove this from the list
        if (!call_again)
            this->last_call[i] = -1;
        else
            this->last_call[i] = millis();

    }
}


void EventManager::add_timeout(int timeout, bool (*callback)()) {
    Serial.println("add_timeout");
    this->timeouts[this->total_timeouts] = timeout;
    this->callbacks[this->total_timeouts] = callback;
    this->last_call[this->total_timeouts] = millis();
    this->total_timeouts++;
}
