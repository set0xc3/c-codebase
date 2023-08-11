<h1 align="center">C code base</h1>

## Depts
- sdl2
- mingw-w64

## Build linux
```sheel
zig build -Dtarget=x86_64-native-gnu
```

## Build windows
```sheel
zig build -Dtarget=x86_64-windows-gnu
```

## Run sandbox
```sheel
zig build run:sandbox
```
