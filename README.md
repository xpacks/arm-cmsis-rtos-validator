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

However, things can be further automated and the most convenient way is
to **add it as a dependency** to the project via **xpm**.

### Install with xpm/npm

Along with the source files, this project also includes a
`package.json` file with the metadata that allows it to be identified as an
**xpm/npm** package so that it can be directly installed from GitHub.

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

@warning
Be sure **xpm** is not installed with administrative rights.

#### xpm

This project can be installed as a package from GitHub with:

```sh
cd my-project
xpm init # Unless a package.json is already present

xpm install github:xpacks/arm-cmsis-rtos-validator#1.0.0-1 --save-dev --copy

ls -l xpacks/@xpacks/arm-cmsis-rtos-validator
```

#### npm

The package can also be installed with [npm](https://docs.npmjs.com)
or related, but
the features specific to C/C++ projects will not be available;
therefore, at least for consistency reasons, it is recommended
to use **xpm**.

### Add as a Git submodule

Besides manually copying the relevant files to the target
project, which will later require extra maintenance efforts to keep the
project up to date, a more convenient
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

TBD

### Status

The **xpacks/arm-cmsis-rtos-validator** source library is fully functional,
but starting with mid 2023 it was marked as end-of-life and
is not recommended for new designs.

A new package will be available in the `@xpack-3rd-party` scope,
as part of µOS++ IVe.

## License

The original content is released under the
[MIT License](https://opensource.org/licenses/MIT/),
with all rights reserved to
[Liviu Ionescu](https://github.com/ilg-ul).
