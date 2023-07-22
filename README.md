[![GitHub package.json version](https://img.shields.io/github/package-json/v/xpacks/arm-cmsis-rtos-validator)](https://github.com/xpacks/arm-cmsis-rtos-validator/blob/xpack/package.json)
[![GitHub tag (latest by date)](https://img.shields.io/github/v/tag/xpacks/arm-cmsis-rtos-validator)](https://github.com/xpacks/arm-cmsis-rtos-validator/tags/)

# An xpm/npm package with the Arm CMSIS RTOS validator

This project provides a convenient way to integrate the
[ARM::CMSIS-RTOS_Validation Pack](https://arm-software.github.io/CMSIS_5/RTOS/html/rtosValidation.html)
into the xpm/npm ecosystem, by allowing to install it as a package dependency.

The open-source project is hosted on GitHub as
[xpacks/arm-cmsis-rtos-validator](https://github.com/xpacks/arm-cmsis-rtos-validator).

## Maintainer info

This page is addressed to developers who plan to include this source
library into their own projects.

For maintainer info, please see the
[README-MAINTAINER-XPACK](README-MAINTAINER-XPACK.md) file.

## Install

As a source code library, this project can be integrated into another project
in the traditional way,
by either copying the relevant files into the target project, or by linking
the entire project as a Git submodule.

However, the workflow can be further automated and the most convenient way is
to **add it as a dependency** to the project via **xpm**.

### Install with xpm/npm

Along with the source files, this project also includes a
`package.json` file with the metadata that allows it to be identified as an
**xpm/npm** package that can be installed automatically as a dependency.

#### Prerequisites

A recent [xpm](https://xpack.github.io/xpm/),
which is a portable [Node.js](https://nodejs.org/) command line application
that complements [npm](https://docs.npmjs.com)
with several extra features specific to
**C/C++ projects**.

It is recommended to install/update to the latest version with:

```sh
npm install --global xpm@latest
```

For details please follow the instructions in the
[xPack install](https://xpack.github.io/install/) page.

Warning: Be sure **xpm** is not installed with administrative/root rights.

#### xpm

This source code library can be installed as a sub-folder below `xpacks` with:

```sh
cd my-project
xpm init # Add a package.json if not already present

xpm install github:xpacks/arm-cmsis-rtos-validator#1.0.0-1 --save-dev --copy

ls -l xpacks/@xpacks/arm-cmsis-rtos-validator
```

Note: On Windows use `dir` and back-slashes.

#### npm

The package can also be installed with [npm](https://docs.npmjs.com)
or related, but the content will end in the `node_modules` folder,
along with JavaScript code;
therefore it is recommended to install C/C++ packages via **xpm**.

### Add as a Git submodule

If, for any reason, xpm/npm are not available, it is always possible
to manually copy the relevant files into the target
project. However, this will need extra maintenance to keep the
project up to date.

A more convenient
solution is to link the entire project as a **Git submodule**,
for example below an `xpacks` folder:

```sh
cd my-project
git init # Unless already a Git project
mkdir -p xpacks

git submodule add https://github.com/xpacks/arm-cmsis-rtos-validator.git \
  xpacks/@xpacks/arm-cmsis-rtos-validator
```

## Branches

In addition to the original `main` branch, there are two
xPack specific branches:

- `xpack`, with the latest stable version (default)
- `xpack-develop`, with the current development version
- `originals`, with the original Arm content, reconstructed
  from the distributed archives

All development is done in the `xpack-develop` branch, and contributions via
Pull Requests should be directed to this branch.

When new releases are published, the `xpack-develop` branch is merged
into `xpack`.

When there are new upstream releases:

- upstream `master` is merged into the local `master`
- the local `master` is merged into `xpack-develop`
- the project is tested
- `xpack-develop` is merged into `xpack`

## Developer info

### Overview

The current files were extracted from the
`ARM.CMSIS-RTOS_Validation.1.0.0.pack` archive.

### Status

The **xpacks/arm-cmsis-rtos-validator** source library is fully functional,
but starting with mid 2023 it was marked as end-of-life and
is not recommended for new designs.

A new package will be available in the `@xpack-3rd-party` scope,
as part of µOS++ IVe.

### Build & integration info

To ease the integration of this package into user projects, there
are already made CMake configuration files (see below).

For other build systems, consider the following details:

#### Include folders

The following folders should be passed to the compiler during the build:

- `Include`
- `cmsis-plus/include`

#### Source files

- `cmsis-plus/src/main.c`
- `Source/RV_Framework.c`
- `Source/cmsis_rv.c`
- `Source/RV_Signal.c`
- `Source/RV_Report.c`
- `Source/RV_Thread.c`
- `Source/RV_MailQueue.c`
- `Source/RV_Timer.c`
- `Source/RV_GenWait.c`
- `Source/RV_WaitFunc.c`
- `Source/RV_MemoryPool.c`
- `Source/RV_MsgQueue.c`
- `Source/RV_Mutex.c`
- `Source/RV_Semaphore.c`

#### Preprocessor definitions

- none

#### Compiler options

- none

#### Dependencies

- none

#### CMake

To integrate the **arm-cmsis** source library
into a CMake application,
add this folder to the build:

```cmake
add_subdirectory("xpacks/@xpacks/arm-cmsis-os-validator")`
```

The result is an interface library that can be added as an application
dependency with:

```cmake
target_link_libraries(your-target PRIVATE

  xpacks::arm-cmsis-os-validator
)
```

### Examples

- none

### Known problems

- none

### Limitations

- none

### Tests

- none

## License

The xPack specific content is released under the
[MIT License](https://opensource.org/licenses/mit/)
,
with all rights reserved to
[Liviu Ionescu](https://github.com/ilg-ul).
