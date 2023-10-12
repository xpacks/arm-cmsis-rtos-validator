# Change & release log

Releases in reverse chronological order.

Please check
[GitHub](https://github.com/xpacks/arm-cmsis-rtos-validator/issues)
and close existing issues and pull requests.

## 2023-10-12

* v1.0.0-3
* 3294d19 RV_Signal.c: do not break on delays (posix)
* e25e876 move PRINT() & FLUSH() to header
* e704325 RV_Typedefs.h: __FILENAME__ POSIX path

## 2023-10-11

* 4f3ff02 1.0.0-2
* 7d46b32 prepare v1.0.0-2

## 2023-10-10

* v1.0.0-2
* 3123bf4 silence warnings

## 2023-07-22

* 0f436c2 README updates

## 2023-07-21

* dc81e7a README updates
* 26ed859 README updates

## 2023-07-18

* 0cc0b0c README update

## 2023-07-14

* 1ce3a78 README update
* 8c28517 README update
* 7ff9195 README updates
* 7296bf7 package.json: minXpm 0.16.2

## 2023-07-13

* 083f174 README update
* 8a3378c READMEs updates
* 7b42029 1.0.0-1
* 0d0312b prepare v1.0.0-1

## 2023-07-12

* d9abe85 1.0.0-1.pre.5
* 44d372b cmsis_rv.c: temporarily disable wait functions

## 2023-06-30

* 40bfc16 package.json: 1.0.0-1.pre.4
* be3e890 cosmetics
* d849013 explicit include os-app-config.h
* 210b757 main.c: add ARM_CMSIS_VALIDATOR_IRQHandler

## 2023-06-26

* 527a184 package.json: 1.0.0-1.pre.3
* 1933feb CMakeLists.txt: Source/
* 3945a59 package.json: 1.0.0-1.pre.2
* 2656ae0 silence warnings
* 62b5a8b READMEs updates
* 13a578f package.json: update contributors
* e8b847d package.json: 1.0.0-1.pre.1
* 57747f2 package.json: 1.0.0-1.pre.1
* c864c2b add CMakeLists.txt
* 01878a9 .npmignore update
* ddb57b5 cleanup unused files
* ce4bc5e silence warnings
* 69f41f6 fix __XXX macros
* a7e4ea8 main.c: comment out NVIC traces
* adb0af1 add #if !defined(OS_SKIP_VALIDATOR_INTERRUPTS)
* ad2a868 add conditional WDT_IRQHandler
* 6fb7993 main.c: comment out redundant TST_IRQHandler
* 3d911d1 silence warnings
* ec86f5a Fix __XXX macros

## 2023-06-22

* 015c20e update copyright notice

## 2023-06-05

* b7fcece add package.json and make the project an xPack
