#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <fsm.h>

/* Extend the FSM class */
typedef struct Keyboard Keyboard;
struct Keyboard {
	Fsm super_;
	/* ... other attributes of Keyboard */
};

/* Extend the Event class */
typedef struct KeyboardEvt KeyboardEvt;
struct KeyboardEvt {
	Event super_;
	/* ... other attributes of Keyboard */
	char code;
};

/* signals used by the Keyboard FSM */
enum { SHIFT_DEPRESSED_SIG,
       SHIFT_RELEASED_SIG,
       ANY_KEY_SIG,
};

void KeyboardCtor(Keyboard* me);
void KeyboardInit(Keyboard* me);
void KeyboardDispatch(Keyboard* me, KeyboardEvt* e);

#endif /* KEYBOARD_H */
