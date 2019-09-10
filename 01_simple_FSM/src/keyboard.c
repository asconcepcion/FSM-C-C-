#include <keyboard.h>

#include <ctype.h>
#include <stdio.h>

static void Keyboard_initial(Keyboard* me, Event const* e);
static void Keyboard_default(Keyboard* me, Event const* e);
static void Keyboard_shifted(Keyboard* me, Event const* e);

static void Keyboard_initial(Keyboard* me, Event const* e)
{
	/* ... initialization of Keyboard attributes */
	printf("Keyboard initialized");
	FsmTran((Fsm*)me, &Keyboard_default);
}

static void Keyboard_default(Keyboard* me, Event const* e)
{
	switch (e->sig) {
	case SHIFT_DEPRESSED_SIG:
		printf("default::SHIFT_DEPRESSED");
		FsmTran((Fsm*)me, &Keyboard_shifted);
		break;
	case ANY_KEY_SIG:
		printf("key %c", (char)tolower(((KeyboardEvt*)e)->code));
		break;
	}
}

static void Keyboard_shifted(Keyboard* me, Event const* e)
{
	switch (e->sig) {
	case SHIFT_RELEASED_SIG:
		printf("shifted::SHIFT_RELEASED");
		FsmTran((Fsm*)me, &Keyboard_default);
		break;
	case ANY_KEY_SIG:
		printf("key %c", (char)toupper(((KeyboardEvt*)e)->code));
		break;
	}
}

void KeyboardCtor(Keyboard* me)
{
	FsmCtor(&me->super_, &Keyboard_initial);
}

void KeyboardInit(Keyboard* me)
{
	FsmInit((Fsm*)me, 0);
}

inline void KeyboardDispatch(Keyboard* me, KeyboardEvt* e)
{
	FsmDispatch((Fsm*)me, (Event*)e); /* dispatch */
}
