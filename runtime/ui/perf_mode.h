#pragma once
#include <string.h>

// 展示与采样独立：off + 独立窗口不会在游戏内绘制浮层。
static inline int perf_display_mode(const char *value) {
    return value && !strcmp(value, "full") ? 2 : value && !strcmp(value, "fps") ? 1 : 0;
}
static inline int perf_sampling_mode(int display, int window_active) { return window_active ? 2 : display; }
