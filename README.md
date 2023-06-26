[![GitHub package.json version](https://img.shields.io/github/package-json/v/xpacks/arm-cmsis-rtos-validator)](https://github.com/xpacks/arm-cmsis-rtos-validator/blob/xpack/package.json)
[![GitHub tag (latest by date)](https://img.shields.io/github/v/tag/xpacks/arm-cmsis-rtos-validator)](https://github.com/xpacks/arm-cmsis-rtos-validator/tags/)
[![npm (scoped)](https://img.shields.io/npm/v/@xpacks/arm-cmsis-rtos-validator.svg?color=blue)](https://www.npmjs.com/package/@xpacks/arm-cmsis-rtos-validator/)
[![license](https://img.shields.io/github/license/xpacks/arm-cmsis-rtos-validator)](https://github.com/xpacks/arm-cmsis-rtos-validator/blob/xpack/LICENSE)

# A source code library with the Arm CMSIS RTOS validator

This project provides a convenient way to integrate the
[ARM::CMSIS-RTOS_Validation Pack](https://arm-software.github.io/CMSIS_5/RTOS/html/rtosValidation.html)
into the xpm/npm ecosystem, by allowing to install it as a package dependency.

The open-source project is hosted on GitHub as
[xpacks/arm-cmsis-rtos-validator](https://github.com/xpacks/arm-cmsis-rtos-validator).

## Install

This project is available from the `npmjs.com` registry as the package
[`@xpacks/arm-cmsis-rtos-validator`](https://www.npmjs.com/package/@xpacks/arm-cmsis-rtos-validator),
and the easiest way to add it to a project is via
**xpm** or **npm**; it can also be used as any Git project, but for
this better use the upstream project.

### Prerequisites

A recent [xpm](https://xpack.github.io/xpm/),
which is a portable [Node.js](https://nodejs.org/) command line application.

It is recommended to update to the latest version with:

```sh
npm install --global xpm@latest
```

For details please follow the instructions in the
[xPack install](https://xpack.github.io/install/) page.

### xpm

To install this project as a dependency in xPack projects,
use **xpm**:

```sh
cd my-project
xpm init # Unless a package.json is already present

xpm install @xpacks/arm-cmsis-rtos-validator@latest

ls -l xpacks/@xpacks/arm-cmsis-rtos-validator
```

### npm

To install the project as a dependency in **npm** projects:

```sh
cd my-project
npm init # Unless a package.json is already present

npm install @xpacks/arm-cmsis-rtos-validator@latest --save-dev

ls -l node_module/@xpacks/arm-cmsis-rtos-validator
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
