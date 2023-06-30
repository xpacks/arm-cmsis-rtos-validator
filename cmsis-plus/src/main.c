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

#include "cmsis_rv.h"

#include <cmsis-plus/rtos/os-c-api.h>
#include <cmsis-plus/diag/trace.h>

#if defined(__APPLE__) || defined(__linux__)

#include <signal.h>
#include <unistd.h>

void
sigusr1_init (void);

#endif

int
//os_main (int argc, char* argv[])
os_main (int argc __attribute__((unused)), char* argv[] __attribute__((unused)))
{
#if defined(__APPLE__)  || defined(__linux__)
  sigusr1_init ();
#endif

  return cmsis_rv ();
}

// extern void
// (*TST_IRQHandler) (void);

#if defined(__ARM_EABI__)

void
ARM_CMSIS_VALIDATOR_IRQHandler (void);

void
ARM_CMSIS_VALIDATOR_IRQHandler (void)
  {
    if (TST_IRQHandler != NULL)
      {
        TST_IRQHandler ();
        return;
      }
    __asm__ volatile ("bkpt 0");
    for (;;)
    ;
  }

#elif defined(__APPLE__) || defined(__linux__)

extern uint32_t signal_nesting;

static sigset_t sigusr1_set;

void
sigusr1_handler (int signum);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"

void
sigusr1_init (void)
{
  struct sigaction sa;
  sigemptyset(&sa.sa_mask);
  sigaddset(&sa.sa_mask, SIGALRM);
#if defined(__APPLE__)
  sa.__sigaction_u.__sa_handler = sigusr1_handler;
#elif defined(__linux__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
#endif
  sa.sa_handler = sigusr1_handler;
#pragma GCC diagnostic pop
#else
#error Unsupported platform.
#endif

  // restart system on signal return
  sa.sa_flags = SA_RESTART;
  sigaction (SIGUSR1, &sa, NULL);

  sigemptyset(&sigusr1_set);
  sigaddset(&sigusr1_set, SIGUSR1);

  sigprocmask (SIG_BLOCK, &sigusr1_set, NULL);
}

#pragma GCC diagnostic pop

void
sigusr1_handler (int signum)
{
  if (signum == SIGUSR1)
    {
      if (TST_IRQHandler != NULL)
        {
          signal_nesting++;
          TST_IRQHandler ();
          signal_nesting--;
        }
    }
  else
    {
      char q = '?';
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
      write (2, &q, 1);
#pragma GCC diagnostic pop
    }
}

void
NVIC_DisableIRQ (int i);

void
NVIC_EnableIRQ (int i);

void
NVIC_SetPendingIRQ (int i);

void
NVIC_DisableIRQ (int i __attribute__((unused)))
{
#if defined(TRACE)
  // trace_printf ("%s()\n", __func__);
#endif
  sigprocmask (SIG_BLOCK, &sigusr1_set, NULL);
}

void
NVIC_EnableIRQ (int i __attribute__((unused)))
{
#if defined(TRACE)
  // trace_printf ("%s()\n", __func__);
#endif
  sigprocmask (SIG_UNBLOCK, &sigusr1_set, NULL);
}

void
NVIC_SetPendingIRQ (int i __attribute__((unused)))
{
#if defined(TRACE)
  // trace_printf ("%s()\n", __func__);
#endif
  kill (getpid (), SIGUSR1);
}

#endif
