# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus/)
# Copyright (c) 2021-2023 Liviu Ionescu. All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/mit/.
#
# -----------------------------------------------------------------------------

# This file is intended to be consumed by applications with:
#
# `add_subdirectory("xpacks/@xpacks/arm-cmsis-os-validator")`
#
# The result is an interface library that can be added to the linker with:
#
# `target_link_libraries(your-target PUBLIC xpacks::arm-cmsis-os-validator)`

# -----------------------------------------------------------------------------
## Preamble ##

# https://cmake.org/cmake/help/v3.20/
cmake_minimum_required(VERSION 3.20)

project(xpacks-arm-cmsis-os-validator
  DESCRIPTION "Arm CMSIS RTOS validator"
)

if(COMMAND xpack_get_package_name_and_version)
  xpack_get_package_name_and_version("${CMAKE_CURRENT_SOURCE_DIR}/package.json")
  message(VERBOSE "Processing xPack ${PACKAGE_JSON_NAME}@${PACKAGE_JSON_VERSION}...")
endif()

# -----------------------------------------------------------------------------
## The project library definitions ##

add_library(xpacks-arm-cmsis-os-validator-interface INTERFACE EXCLUDE_FROM_ALL)

# -----------------------------------------------------------------------------
# Target settings.

target_include_directories(xpacks-arm-cmsis-os-validator-interface INTERFACE
  "Include"
  "cmsis-plus/include"
)

target_sources(xpacks-arm-cmsis-os-validator-interface INTERFACE
  cmsis-plus/src/main.c
  source/RV_Framework.c
  source/cmsis_rv.c
  source/RV_Signal.c
  source/RV_Report.c
  source/RV_Thread.c
  source/RV_MailQueue.c
  source/RV_Timer.c
  source/RV_GenWait.c
  source/RV_WaitFunc.c
  source/RV_MemoryPool.c
  source/RV_MsgQueue.c
  source/RV_Mutex.c
  source/RV_Semaphore.c
)

target_compile_definitions(xpacks-arm-cmsis-os-validator-interface INTERFACE
  # None.
)

target_compile_options(xpacks-arm-cmsis-os-validator-interface INTERFACE
  # None.
)

target_link_libraries(xpacks-arm-cmsis-os-validator-interface INTERFACE
  # None.
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists(xpacks-arm-cmsis-os-validator-interface)
endif()

# -----------------------------------------------------------------------------
# Aliases.

# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library(xpacks::arm-cmsis-os-validator ALIAS xpacks-arm-cmsis-os-validator-interface)
message(VERBOSE "> xpacks::arm-cmsis-os-validator -> xpacks-arm-cmsis-os-validator-interface")

# -----------------------------------------------------------------------------
