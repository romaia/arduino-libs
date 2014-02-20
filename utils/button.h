#include <base.h>

#ifndef BUTTON_HEADER
#define BUTTON_HEADER

#define BUTTON_RELEASED 0
#define BUTTON_PRESSED 1

class Button: public BaseGadget {
    public:
        virtual void init();
        virtual void handle();
        virtual void pressed();
        virtual void released();
        bool is_pressed();
        int pin;

    protected:
        int _state;
};

#endif
