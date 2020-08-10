#ifndef __LGS_COMMON_H_INCLUDE__
#define __LGS_COMMON_H_INCLUDE__

#ifdef __cplusplus
extern "C" {
#endif

/* c header file */
#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <stddef.h>
#include <time.h>
#include <stdarg.h>
#include <time.h>


typedef intptr_t					lgs_int_t;
typedef uintptr_t					lgs_uint_t;


#define LGS_OK						(0)
#define LGS_ERROR					(lgs_int_t)(-1)
#define LGS_AGAIN					(-2)

#define LGS_CONF_OK					(NULL)
#define lGS_CONF_ERROR				(void *)(-1)

#define LF							(u_char) '\n'
#define CR							(u_char) '\r'
#define CRLF						"\r\n"


#define lgs_inline					inline

#define lgs_exit					exit
#define lgs_assert					assert
#define lgs_srand					srand
#define lgs_time					time
#define lgs_rand					rand
#define lgs_main					main
#define lgs_log						printf
#define lgs_print                   fprintf
#define lgs_memset                  memset
#define lgs_strcmp                  strcmp
#define lgs_strlen                  strlen
#define lgs_strcpy                  strcpy


#define lgs_abs(value)              (((value) >= 0) ? (value) : - (value))
#define lgs_max(val1, val2)         ((val1 < val2) ? (val2) : (val1))
#define lgs_min(val1, val2)         ((val1 > val2) ? (val2) : (val1))

#define lgs_container_of(ptr, type, member) (type *) \
									((uint8_t *) ptr - offsetof(type, member))
#define lgs_array_size(a)			(sizeof(a) / sizeof(a[0]))
#define LGS_ARRAY_SIZE(x)			(int)(sizeof(x)/sizeof(x[0]))

void lgs_copy(void *dst, void *src, int size);
void lgs_free(void *p);
void *lgs_malloc(int size);

void lgs_debug_start();
void lgs_debug_stop();

#ifdef __cplusplus
}
#endif

#endif
