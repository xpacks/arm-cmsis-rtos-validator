[![GitHub issues](https://img.shields.io/github/issues/xpack-3rd-party/arm-cmsis-rtos-validator.svg)](https://github.com/xpack-3rd-party/arm-cmsis-rtos-validator-xpack/issues/)
[![GitHub pulls](https://img.shields.io/github/issues-pr/xpack-3rd-party/arm-cmsis-rtos-validator.svg)](https://github.com/xpack-3rd-party/arm-cmsis-rtos-validator-xpack/pulls)

# Maintainer info

## Project repository

The project is hosted on GitHub:

- <https://github.com/xpack-3rd-party/arm-cmsis-rtos-validator-xpack.git>

To clone the stable branch (`xpack`), run the following commands in a
terminal (on Windows use the _Git Bash_ console):

```sh
rm -rf ~/Work/xpack-3rd-party/arm-cmsis-rtos-validator-xpack.git && \
mkdir -p ~/Work/xpack-3rd-party && \
git clone \
  https://github.com/xpack-3rd-party/arm-cmsis-rtos-validator-xpack.git \
  ~/Work/xpack-3rd-party/arm-cmsis-rtos-validator-xpack.git
```

For development purposes, clone the `xpack-development` branch:

```sh
rm -rf ~/Work/xpack-3rd-party/arm-cmsis-rtos-validator-xpack.git && \
mkdir -p ~/Work/xpack-3rd-party && \
git clone \
  --branch xpack-development \
  https://github.com/xpack-3rd-party/arm-cmsis-rtos-validator-xpack.git \
  ~/Work/xpack-3rd-party/arm-cmsis-rtos-validator-xpack.git
```

## Prerequisites

A recent [xpm](https://xpack.github.io/xpm/), which is a portable
[Node.js](https://nodejs.org/) command line application.

## How to make new releases

### Release schedule

There are no fixed releases, the project aims to follow the upstream releases.

### Check Git

In the `xpack-3rd-party/arm-cmsis-rtos-validator-xpack` Git repo:

- switch to the `xpack-development` branch
- if needed, merge the `xpack` branch

No need to add a tag here, it'll be added when the release is created.

### Increase the version

Determine the upstream version (like `1.0.0`)

- <https://arm-software.github.io/CMSIS_5/RTOS/html/rtosValidation.html>

Update the`package.json` file; add an extra digit in the
pre-release field, and initially also add `.pre`,
for example `1.0.0-5.pre`.

### Fix possible open issues

Check GitHub issues and pull requests:

- <https://github.com/xpack-3rd-party/arm-cmsis-rtos-validator-xpack/issues/>

and fix them; assign them to a milestone (like `1.0.0-5`).

### Update `README-MAINTAINER-XPACK.md`

Update the `README-MAINTAINER-XPACK.md` file to reflect the changes
related to the new version.

### Update `CHANGELOG-XPACK.md`

- open the `CHANGELOG-XPACK.md` file
- check if all previous fixed issues are in
- add a new entry like _\* v1.0.0-5_
- commit with a message like _prepare v1.0.0-5_

### Push changes

- commit and push

### Commit the new version

- select the `xpack-development` branch
- commit all changes
- `npm pack` and check the content of the archive, which should list
  only `package.json`, `README.md`, `LICENSE`, `CHANGELOG-XPACK.md`,
  the `doxygen-awesome-*.js` and `doxygen-custom/*` files;
  possibly adjust `.npmignore`
- `npm version 1.0.0-5`
- push the `xpack-development` branch to GitHub
- the `postversion` npm script should also update tags via `git push origin --tags`

### Update the repo

When the package is considered stable:

- with a Git client (VS Code is fine)
- merge `xpack-development` into `xpack`
- push to GitHub
- select `xpack-development`
