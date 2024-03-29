/*-----------------------------------------------------------------------------
 *      Name:         DV_Report.h 
 *      Purpose:      Report statistics and layout header
 *----------------------------------------------------------------------------
 *      Copyright(c) KEIL - An ARM Company
 *----------------------------------------------------------------------------*/
#ifndef RV_REPORT_H__
#define RV_REPORT_H__

#include "RV_Config.h"
#include "RV_Typedefs.h"

/*-----------------------------------------------------------------------------
 * Test report global definitions
 *----------------------------------------------------------------------------*/
 
#define REP_TC_FAIL 0
#define REP_TC_WARN 1
#define REP_TC_PASS 2
#define REP_TC_NOEX 3

/* Test case result definition */
typedef enum {
  PASSED = 0,
  WARNING,
  FAILED,
  NOT_EXECUTED
} TC_RES;

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wpadded"
#elif defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wpadded"
#endif

/* Assertion result info */
typedef struct {
  const char    *module;                  /* Module name                        */
  uint32_t       line;                    /* Assertion line                     */
} AS_INFO;

/* Test case callback interface definition */
typedef struct {
  BOOL (* Result) (TC_RES res);
  BOOL (* Dbgi)   (TC_RES res, const char *fn, uint32_t ln, char *desc);
} TC_ITF;

/* Assert interface to the report */
extern TC_ITF tcitf;

/* Assertion result buffer */
typedef struct {
AS_INFO passed[BUFFER_ASSERTIONS];  
AS_INFO failed[BUFFER_ASSERTIONS];  
AS_INFO warnings[BUFFER_ASSERTIONS];  
} AS_T_INFO;

/* Assertion statistics */
typedef struct {
  uint32_t passed;           /* Total assertions passed                  */
  uint32_t failed;           /* Total assertions failed                  */
  uint32_t warnings;         /* Total assertions warnings                */
  AS_T_INFO info;            /* Detailed assertion info                  */
} AS_STAT;

/* Test global statistics */
typedef struct {
  uint32_t  tests;           /* Total test cases count                   */
  uint32_t  executed;        /* Total test cases executed                */
  uint32_t  passed;          /* Total test cases passed                  */
  uint32_t  failed;          /* Total test cases failed                  */
  uint32_t  warnings;        /* Total test cases warnings                */
  AS_STAT   assertions;      /* Total assertions statistics              */
} TEST_REPORT;

/* Test report interface */
typedef struct {
  BOOL (* Init)     (void);
  BOOL (* Open)     (const char *title, const char *date, const char *time, const char *fn);
  BOOL (* Close)    (void);  
  BOOL (* Open_TC)  (uint32_t num, const char *fn);
  BOOL (* Close_TC) (void);
} REPORT_ITF;

#pragma GCC diagnostic pop

/* Test report statistics */
extern TEST_REPORT  tr;

/* Test report interface */
extern REPORT_ITF   ritf;

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wreserved-identifier"
#elif defined(__GNUC__)
#endif

/* Assertions and test results */
extern uint32_t __set_result (const char *fn, uint32_t ln, TC_RES res, char* desc);
extern uint32_t __assert_true (const char *fn, uint32_t ln, uint32_t cond);

#pragma GCC diagnostic pop

#endif /* RV_REPORT_H__ */
