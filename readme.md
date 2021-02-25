# Quantum Mechanical Keyboard Firmware

This is my QMK Fork for the massdrop alt keyboard. It probably wouldn't be wise to directly build and flash my keyboard, but maybe this layout may give you some ideas for your keyboards.

The layout used for my layout is colemak mod dh wide ansi.

The easiest way to build the board is using Docker. 
First, get the docker container with `docker pull qmkfm/qmk_firmware`.
Then, on Linux distros you can directly run `./util/docker_build.sh massdrop/alt:matkam7`. On Windows, you can run `'C:\Program Files\Git\bin\bash.exe' --cd="." .\util\docker_build.sh massdrop/alt:matkam7`.

To flash, run `./mdloader_windows.exe --first --download massdrop_alt_matkam7.bin --restart` and press the key combination to enter bootloader mode (FN + Z on my layout).

## QMK Firmware project:

This is a keyboard firmware based on the [tmk\_keyboard firmware](https://github.com/tmk/tmk_keyboard) with some useful features for Atmel AVR and ARM controllers, and more specifically, the [OLKB product line](https://olkb.com), the [ErgoDox EZ](https://ergodox-ez.com) keyboard, and the [Clueboard product line](https://clueboard.co).

## Documentation

* [See the official documentation on docs.qmk.fm](https://docs.qmk.fm)

The docs are powered by [Docsify](https://docsify.js.org/) and hosted on [GitHub](/docs/). They are also viewable offline; see [Previewing the Documentation](https://docs.qmk.fm/#/contributing?id=previewing-the-documentation) for more details.

You can request changes by making a fork and opening a [pull request](https://github.com/qmk/qmk_firmware/pulls), or by clicking the "Edit this page" link at the bottom of any page.

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.
