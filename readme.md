# Quantum Mechanical Keyboard Firmware

This is my QMK Fork for the ZSA Moonlander keyboard. It probably wouldn't be wise to directly build and flash my keyboard, but maybe this layout may give you some ideas for your keyboards.

The layout used for my layout is colemak mod dh wide ansi.

The easiest way to build the board is using Docker. 
First, get the docker container with `docker pull qmkfm/qmk_firmware`.
Then, on Linux distros you can directly run `./util/docker_build.sh moonlander:matkam7`. On Windows, you can run `& 'C:\Program Files\Git\bin\bash.exe' --cd="." .\util\docker_build.sh moonlander:matkam7`.

To flash on Windows, run the flasher tool in the Wally folder `.\Wally\Wally.exe`.

## Documentation

* [See the official documentation on docs.qmk.fm](https://docs.qmk.fm)

The docs are powered by [Docsify](https://docsify.js.org/) and hosted on [GitHub](/docs/). They are also viewable offline; see [Previewing the Documentation](https://docs.qmk.fm/#/contributing?id=previewing-the-documentation) for more details.

You can request changes by making a fork and opening a [pull request](https://github.com/qmk/qmk_firmware/pulls), or by clicking the "Edit this page" link at the bottom of any page.

## Supported Keyboards

* [Planck](/keyboards/planck/)
* [Preonic](/keyboards/preonic/)
* [ErgoDox EZ](/keyboards/ergodox_ez/)
* [Clueboard](/keyboards/clueboard/)
* [Cluepad](/keyboards/clueboard/17/)
* [Atreus](/keyboards/atreus/)

The project also includes community support for [lots of other keyboards](/keyboards/).

## Maintainers

QMK is developed and maintained by Jack Humbert of OLKB with contributions from the community, and of course, [Hasu](https://github.com/tmk). The OLKB product firmwares are maintained by [Jack Humbert](https://github.com/jackhumbert), the Ergodox EZ by [ZSA Technology Labs](https://github.com/zsa), the Clueboard by [Zach White](https://github.com/skullydazed), and the Atreus by [Phil Hagelberg](https://github.com/technomancy).

## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.
