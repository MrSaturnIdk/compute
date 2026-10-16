# Compute
A stupid and detereministic shell calculator
## Install
```sh
git clone https://github.com/MrSaturnIdk/compute.git
cd compute
mkdir build
cd build
cmake ..
cmake --build .
sudo cmake --install .
```
## Usage
Just run `compute -h` or `compute --help` or `compute /h`
## Errors
### Handled
- Nothing passed: `compute`
- No numbers passed to function: `compute -a`
- Not enough numbers passed to function (must be two): `compute -a 1`
- Invalid function: `compute meep`
### Unhandled
- Number is not number: `compute -a burger ham`: Will silently become `compute -a 0 0`
- Divide by `0`: `compute -d 1 0`: Behavior depends on OS implementation
## What is an invalid number
- Obvious: `abc`
- Using colons: `123,456`
- Decimal point isn't `.`: `1,1`
- Non-ASCII number: (I can't really showcase this)

> [!WARNING]
> `1 2` is different from `"1 2"`.
>
> `1 2` is interepreted as **2 arguments**, `1` and `2`, and they will be added
> `"1 2"` will be interpreted as **1 argument**.
> The parser will see `1` and then see whitespace after `1`, and so will ignore after `1`,
> resulting in it being truncated to `1`.
>
> Similarly, `21 4 5 29` will be truncated to `21` and `2 0 8 6` will be truncated to `2`.
## License & Copyright
Copyright (c) 2026 MrSaturnIdk.

Licensed under the [AGPL-3.0-or-later](LICENSE).
