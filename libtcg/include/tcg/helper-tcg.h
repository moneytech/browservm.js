/* Helper file for declaring TCG helper functions.
   This one defines data structures private to tcg.c.  */

#ifndef HELPER_TCG_H
#define HELPER_TCG_H

#include "helper-head.h"

/* Need one more level of indirection before stringification
   to get all the macros expanded first.  */
#define str(s) #s

#if defined(__EMSCRIPTEN__) || TARGET_LONG_BITS == 32

#define HELPER_WR(name) glue(name,_wrapper)

#define DEF_HELPER_FLAGS_0(NAME, FLAGS, ret) \
    {.func = HELPER_WR(NAME), .name = str(NAME), .flags = FLAGS | dh_callflag(ret), .sizemask = dh_sizemask(ret, 0)},

#define DEF_HELPER_FLAGS_1(NAME, FLAGS, ret, t1) \
    {.func = HELPER_WR(NAME),                       \
     .name = str(NAME),                          \
     .flags = FLAGS | dh_callflag(ret),          \
     .sizemask = dh_sizemask(ret, 0) | dh_sizemask(t1, 1)},

#define DEF_HELPER_FLAGS_2(NAME, FLAGS, ret, t1, t2) \
    {.func = HELPER_WR(NAME),                           \
     .name = str(NAME),                              \
     .flags = FLAGS | dh_callflag(ret),              \
     .sizemask = dh_sizemask(ret, 0) | dh_sizemask(t1, 1) | dh_sizemask(t2, 2)},

#define DEF_HELPER_FLAGS_3(NAME, FLAGS, ret, t1, t2, t3) \
    {.func = HELPER_WR(NAME),                               \
     .name = str(NAME),                                  \
     .flags = FLAGS | dh_callflag(ret),                  \
     .sizemask = dh_sizemask(ret, 0) | dh_sizemask(t1, 1) | dh_sizemask(t2, 2) | dh_sizemask(t3, 3)},

#define DEF_HELPER_FLAGS_4(NAME, FLAGS, ret, t1, t2, t3, t4) \
    {.func = HELPER_WR(NAME),                                   \
     .name = str(NAME),                                      \
     .flags = FLAGS | dh_callflag(ret),                      \
     .sizemask =                                             \
         dh_sizemask(ret, 0) | dh_sizemask(t1, 1) | dh_sizemask(t2, 2) | dh_sizemask(t3, 3) | dh_sizemask(t4, 4)},

#define DEF_HELPER_FLAGS_5(NAME, FLAGS, ret, t1, t2, t3, t4, t5)                                      \
    {.func = HELPER_WR(NAME),                                                                            \
     .name = str(NAME),                                                                               \
     .flags = FLAGS | dh_callflag(ret),                                                               \
     .sizemask = dh_sizemask(ret, 0) | dh_sizemask(t1, 1) | dh_sizemask(t2, 2) | dh_sizemask(t3, 3) | \
                 dh_sizemask(t4, 4) | dh_sizemask(t5, 5)},

#define DEF_HELPER_FLAGS_6(NAME, FLAGS, ret, t1, t2, t3, t4, t5, t6)                                  \
    {.func = HELPER_WR(NAME),                                                                            \
     .name = str(NAME),                                                                               \
     .flags = FLAGS | dh_callflag(ret),                                                               \
     .sizemask = dh_sizemask(ret, 0) | dh_sizemask(t1, 1) | dh_sizemask(t2, 2) | dh_sizemask(t3, 3) | \
                 dh_sizemask(t4, 4) | dh_sizemask(t5, 5) | dh_sizemask(t6, 6)},

#else /* Without BINARYEN */

#define DEF_HELPER_FLAGS_0(NAME, FLAGS, ret) \
    {.func = HELPER(NAME), .name = str(NAME), .flags = FLAGS | dh_callflag(ret), .sizemask = dh_sizemask(ret, 0)},

#define DEF_HELPER_FLAGS_1(NAME, FLAGS, ret, t1) \
    {.func = HELPER(NAME),                       \
     .name = str(NAME),                          \
     .flags = FLAGS | dh_callflag(ret),          \
     .sizemask = dh_sizemask(ret, 0) | dh_sizemask(t1, 1)},

#define DEF_HELPER_FLAGS_2(NAME, FLAGS, ret, t1, t2) \
    {.func = HELPER(NAME),                           \
     .name = str(NAME),                              \
     .flags = FLAGS | dh_callflag(ret),              \
     .sizemask = dh_sizemask(ret, 0) | dh_sizemask(t1, 1) | dh_sizemask(t2, 2)},

#define DEF_HELPER_FLAGS_3(NAME, FLAGS, ret, t1, t2, t3) \
    {.func = HELPER(NAME),                               \
     .name = str(NAME),                                  \
     .flags = FLAGS | dh_callflag(ret),                  \
     .sizemask = dh_sizemask(ret, 0) | dh_sizemask(t1, 1) | dh_sizemask(t2, 2) | dh_sizemask(t3, 3)},

#define DEF_HELPER_FLAGS_4(NAME, FLAGS, ret, t1, t2, t3, t4) \
    {.func = HELPER(NAME),                                   \
     .name = str(NAME),                                      \
     .flags = FLAGS | dh_callflag(ret),                      \
     .sizemask =                                             \
         dh_sizemask(ret, 0) | dh_sizemask(t1, 1) | dh_sizemask(t2, 2) | dh_sizemask(t3, 3) | dh_sizemask(t4, 4)},

#define DEF_HELPER_FLAGS_5(NAME, FLAGS, ret, t1, t2, t3, t4, t5)                                      \
    {.func = HELPER(NAME),                                                                            \
     .name = str(NAME),                                                                               \
     .flags = FLAGS | dh_callflag(ret),                                                               \
     .sizemask = dh_sizemask(ret, 0) | dh_sizemask(t1, 1) | dh_sizemask(t2, 2) | dh_sizemask(t3, 3) | \
                 dh_sizemask(t4, 4) | dh_sizemask(t5, 5)},

#define DEF_HELPER_FLAGS_6(NAME, FLAGS, ret, t1, t2, t3, t4, t5, t6)                                  \
    {.func = HELPER(NAME),                                                                            \
     .name = str(NAME),                                                                               \
     .flags = FLAGS | dh_callflag(ret),                                                               \
     .sizemask = dh_sizemask(ret, 0) | dh_sizemask(t1, 1) | dh_sizemask(t2, 2) | dh_sizemask(t3, 3) | \
                 dh_sizemask(t4, 4) | dh_sizemask(t5, 5) | dh_sizemask(t6, 6)},

#endif /* BINARYEN */

#include <tcg/helper.h>
#include <tcg/tcg-runtime.h>

#undef str
#undef DEF_HELPER_FLAGS_0
#undef DEF_HELPER_FLAGS_1
#undef DEF_HELPER_FLAGS_2
#undef DEF_HELPER_FLAGS_3
#undef DEF_HELPER_FLAGS_4
#undef DEF_HELPER_FLAGS_5
#undef DEF_HELPER_FLAGS_6

#endif /* HELPER_TCG_H */
