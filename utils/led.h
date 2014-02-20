#include <base.h>

#ifndef LED_HEADER
#define LED_HEADER

#define LED_ON      0
#define LED_OFF     1

class Led: public BaseGadget {
    public:
        virtual void init();
        virtual void handle();
        void turn_on();
        void turn_off();
        void toggle();
        void blink(int);
        bool is_blinking();
        int pin;
    protected:
        int _state;
        int _interval;
        int _last_blink;
};

#endif
