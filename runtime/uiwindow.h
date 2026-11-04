#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct UiWindow UiWindow;
typedef void (*UiWindowDrawFn)(void *user, void *dc, int w, int h);

// 调用者拥有句柄并串行操作；用户关闭窗口后也必须调用 close。
// 每个窗口独立线程绘制；绘制回调不能调用 close，也不能获取 present 或队列锁。
// 框架保留后备缓冲区，内容未变时可跳绘；尺寸变化时回调必须重画。
UiWindow *uiwindow_open(const char *title, int w, int h, int hz, UiWindowDrawFn draw, void *user);
// 请求退出、join 绘制线程并释放句柄；不能在绘制回调中调用。
void uiwindow_close(UiWindow *win);
int uiwindow_is_open(const UiWindow *win);
// 消费用户关闭通知；程序调用 close 不产生该通知。
int uiwindow_take_close_requested(UiWindow *win);
void uiwindow_repaint(UiWindow *win);
// 复制 UTF-8 标题；拥有者线程与绘制回调均可调用。
void uiwindow_set_title(UiWindow *win, const char *title);

#ifdef __cplusplus
}
#endif
