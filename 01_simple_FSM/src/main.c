#include <keyboard.h>
#include <stdio.h>

int main()
{
	Keyboard k;
	KeyboardCtor(&k);
	KeyboardInit(&k);
	for (;;) {
		KeyboardEvt ke;
		printf("\nSignal<-");
		ke.code = getc(stdin);
		getc(stdin); /* discard '\n' */
		switch (ke.code) {
		case '^':
			ke.super_.sig = SHIFT_DEPRESSED_SIG;
			break;
		case '6':
			ke.super_.sig = SHIFT_RELEASED_SIG;
			break;
		case '.':
			return 0; /* terminate the test */
		default:
			ke.super_.sig = ANY_KEY_SIG;
			break;
		}
		KeyboardDispatch(&k, &ke); /* dispatch */
	}
	return 0;
}
