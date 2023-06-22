/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2016-2023 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/mit/.
 */

/*
 * This file is part of the CMSIS++ proposal, intended as a CMSIS
 * replacement for C++ applications.
 */

#ifndef CMSIS_PLUS_RTOS_OS_APP_CONFIG_H_
#define CMSIS_PLUS_RTOS_OS_APP_CONFIG_H_

// ----------------------------------------------------------------------------

#if defined(DEBUG)
#define OS_INTEGER_SYSTICK_FREQUENCY_HZ                     (1000)
#else
#define OS_INTEGER_SYSTICK_FREQUENCY_HZ                     (1000)
#endif

#if defined(__ARM_EABI__)

#define OS_INTEGER_RTOS_DEFAULT_STACK_SIZE_BYTES (1500)
#define OS_INTEGER_RTOS_MIN_STACK_SIZE_BYTES (1000)

#if 1
// Disable all interrupts from 15 to 4, keep 3-2-1 enabled
#define OS_INTEGER_RTOS_CRITICAL_SECTION_INTERRUPT_PRIORITY (4)
#endif

#else

#define OS_USE_TRACE_POSIX_STDOUT

#endif

#define OS_INCLUDE_RTOS_STATISTICS_THREAD_CONTEXT_SWITCHES  (1)
#define OS_INCLUDE_RTOS_STATISTICS_THREAD_CPU_CYCLES        (1)

// ----------------------------------------------------------------------------

#if defined(USE_FREERTOS)

// Request the inclusion of a custom implementations.
#define OS_USE_RTOS_PORT_SCHEDULER                      (1)

#if 1
#define OS_USE_RTOS_PORT_TIMER                          (1)
//#define OS_USE_RTOS_PORT_CLOCK_SYSTICK_WAIT_FOR        (1)
#define OS_USE_RTOS_PORT_MUTEX                          (1)
#define OS_USE_RTOS_PORT_SEMAPHORE                      (1)
#define OS_USE_RTOS_PORT_MESSAGE_QUEUE                  (1)
#define OS_USE_RTOS_PORT_EVENT_FLAGS                    (1)
#endif

#endif /* defined(USE_FREERTOS) */

// ----------------------------------------------------------------------------

#if defined(TRACE)

#define OS_TRACE_RTOS_CLOCKS
#define OS_TRACE_RTOS_CONDVAR
#define OS_TRACE_RTOS_EVFLAGS
#define OS_TRACE_RTOS_MEMPOOL
#define OS_TRACE_RTOS_MQUEUE
#define OS_TRACE_RTOS_MUTEX
#define OS_TRACE_RTOS_SCHEDULER
#define OS_TRACE_RTOS_SEMAPHORE
#define OS_TRACE_RTOS_THREAD
#define OS_TRACE_RTOS_THREAD_FLAGS
#define OS_TRACE_RTOS_TIMER

#define OS_TRACE_LIBC_MALLOC
#define OS_TRACE_LIBC_ATEXIT
#define OS_TRACE_LIBCPP_OPERATOR_NEW
#define OS_TRACE_LIBCPP_MEMORY_RESOURCE

#if !defined(__ARM_EABI__)
#define OS_TRACE_RTOS_RTC_TICK
#define OS_TRACE_RTOS_LISTS
#define OS_TRACE_RTOS_THREAD_CONTEXT
#else
//#define OS_TRACE_RTOS_SYSCLOCK_TICK
#define OS_TRACE_RTOS_RTC_TICK
//#define OS_TRACE_RTOS_LISTS
//#define OS_TRACE_RTOS_THREAD_CONTEXT

#endif

#else

// #define OS_TRACE_RTOS_THREAD
#define OS_TRACE_RTOS_RTC_TICK

#endif

#define OS_INCLUDE_RTOS_THREAD_PUBLIC_FLAGS_CLEAR
#define OS_BOOL_RTOS_THREAD_IDLE_PRIORITY_BELOW_IDLE

// ----------------------------------------------------------------------------

#endif /* CMSIS_PLUS_RTOS_OS_APP_CONFIG_H_ */
