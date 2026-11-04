#pragma once
#ifdef __cplusplus
extern "C" {
#endif

// tick 由 present 路径调用；内部串行化。退出时 close 等待绘图线程退出，永久阻止再次打开。
void input_panel_tick(void);
void input_panel_close(void);
#ifdef __cplusplus
}
#endif
