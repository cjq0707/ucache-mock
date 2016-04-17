#ifndef _CMOCK_TEST_FOO_H_
#define _CMOCK_TEST_FOO_H_

#ifdef __cplusplus
extern "C" {
#endif
typedef void (*callback)(void);
int foo(callback cb);

#ifdef __cplusplus
}
#endif

#endif
