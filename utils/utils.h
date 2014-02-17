class BaseGadget {
    public:
        virtual void init();
        virtual int handle();
};

class EventHandler {
    public:
        EventHandler();
        void handle();
        void add_gadget(BaseGadget *gadget);
        void add_timeout(int timeout, void * callback);

    protected:
        int _pin;
        int _state;
};



#define BUTTON_RELEASED 0
#define BUTTON_PRESSED 1

class ButtonHandler: public BaseGadget {
    public:
        void init(int pin);
        int handle();
        bool is_pressed();
        virtual void pressed();
        virtual void released();

    protected:
        int _pin;
        int _state;
};


#define LED_ON      0
#define LED_OFF     1

class Led: public BaseGadget {
    public:
        void init(int pin);
        int handle();
        void turn_on();
        void turn_off();
        void toggle();
        void blink(int);
        bool is_blinking();
    protected:
        int _pin;
        int _state;
        int _interval;
        int _last_blink;
};
