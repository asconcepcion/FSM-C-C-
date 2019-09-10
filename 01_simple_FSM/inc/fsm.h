#ifndef FSM_H
#define FSM_H

/* "inlined" methods of Fsm class */
#define FsmCtor(me_, init_) ((me_)->state__ = (State)(init_))
#define FsmTran(me_, targ_) ((me_)->state__ = (State)(targ_))
#define FsmInit(me_, e_) (*(me_)->state__)((me_), (e_))
#define FsmDispatch(me_, e_) (*(me_)->state__)((me_), (e_))

typedef short Signal;
typedef struct Event Event;
typedef struct Fsm Fsm;
typedef void (*State)(Fsm*, Event const*);

/* Event base class */
struct Event {
	Signal sig;
};
/* Finite State Machine (FSM) base class */
struct Fsm {
	State state__; /* the current state */
};

#endif /* FSM_H */
