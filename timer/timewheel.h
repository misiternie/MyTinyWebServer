#ifndef _MARK_TIMEWHEEL_
#define _MARK_TIMEWHEEL_

#include <stdint.h>

#define TIME_NEAR_SHIFT 8
#define TIME_NEAR (1 << TIME_NEAR_SHIFT)
#define TIME_LEVEL_SHIFT 6
#define TIME_LEVEL (1 << TIME_LEVEL_SHIFT)
#define TIME_NEAR_MASK (TIME_NEAR-1)
#define TIME_LEVEL_MASK (TIME_LEVEL-1)

typedef struct timer_node timer_node_t;
typedef void (*handler_pt) (void *data);

struct timer_node {
	struct timer_node *next;
	void *data;
	uint32_t expire;
    handler_pt callback;
    uint8_t cancel;
	int id; // 此时携带参数
};

timer_node_t* tw_add_timer(int time, handler_pt func, int threadid);

void tw_expire_timer(void);

void tw_del_timer(timer_node_t* node);

void tw_init_timer(void);

void tw_clear_timer();

timer_node_t* tw_modify_timer(int time, timer_node_t* node, handler_pt func, int theadid);

#endif
