#ifndef __SWARM_TYPES_H__
#define __SWARM_TYPES_H__

#ifdef sun4
#define __BIG_ENDIAN__
#else /* ix86 / alpha / arm32 */
#define __LITTLE_ENDIAN__
#endif

#ifdef WIN32
#include <windows.h>
#endif

/* int is 32 bit on all platforms */


#ifndef WIN32
#include <inttypes.h>
#else
typedef signed char               int8_t;
typedef unsigned char             uint8_t;
typedef short                     int16_t;
typedef int                       int32_t;
typedef unsigned short            uint16_t;
typedef unsigned int              uint32_t;
typedef INT64			  int64_t;
typedef UINT64                    uint64_t;
#endif

#if 0
#ifndef __int8_t_defined
typedef short                     int16_t;
typedef int                       int32_t;
#endif /* __int8_t_defined */
typedef unsigned short            uint16_t;
typedef unsigned int              uint32_t;

#ifndef WIN32
#ifndef __int8_t_defined 
typedef long long int             int64_t;
#endif /* __int8_t_defined */
typedef unsigned long long int    uint64_t;
#else
typedef INT64			  int64_t;
typedef UINT64                    uint64_t;
#endif // !WIN32
#endif

typedef int                       bool_t;

#ifndef WIN32
#define FALSE  0
#define TRUE   !FALSE
#endif

#endif /* __SWARM_TYPES_H__ */
