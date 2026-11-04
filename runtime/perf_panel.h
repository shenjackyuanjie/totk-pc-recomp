#pragma once
#ifdef __cplusplus
extern "C" {
#endif
void perf_panel_tick(void);
// 永久停止面板（包括并发 tick），再 join 绘制线程。
void perf_panel_close(void);
int perf_panel_active(void);
#ifdef __cplusplus
}
#endif
