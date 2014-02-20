#include <base.h>

#ifndef MANAGER_HEADER
#define MANAGER_HEADER

class EventManager {
    public:
        EventManager();
        void handle();
        void add_gadget(BaseGadget* gadget);
        void add_timeout(int timeout, bool (*callback)());

    protected:
        int total_gadgets;
        BaseGadget* gadgets[20];

        int total_timeouts;
        bool (*callbacks[20])();
        int timeouts[20];
        int last_call[20];
};


#endif
