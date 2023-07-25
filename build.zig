const std = @import("std");
const Step = std.build.Step;
const CrossTarget = std.zig.CrossTarget;

const flags = [_][]const u8{
    // "-pedantic",
    "-Wall",
    "-Wextra",
    "-Werror",
    "-Wuninitialized",

    "-Wno-unused-parameter",
    "-Wno-unused-variable",
    "-Wno-unused-but-set-variable",
    "-Wno-macro-redefined",
    "-Wno-attributes",
    "-Wno-incompatible-library-redeclaration",

    "-gen-cdb-fragment-path",
    "cdb",
    "-std=c11",
    "-E",
    "-DEXPORT",
};

const iflags = [_][]const u8{
    "-Icore/src",
};

pub fn platform_settings(step: *Step.Compile, target: CrossTarget) void {
    if (target.os_tag.? == .linux) {
        step.addIncludePath("/usr/include");
        step.addLibraryPath("/usr/lib");
        step.linkSystemLibrary("c");
        step.linkSystemLibrary("m");
        step.linkSystemLibrary("uuid");
        step.linkSystemLibrary("SDL2");
    } else if (target.os_tag.? == .windows) {
        step.addIncludePath("/usr/x86_64-w64-mingw32/include");
        step.addLibraryPath("/usr/x86_64-w64-mingw32/bin");
        step.addLibraryPath("/usr/x86_64-w64-mingw32/lib");
        step.linkSystemLibrary("user32");
        step.linkSystemLibrary("gdi32");
        step.linkSystemLibrary("winmm");
        step.linkSystemLibrary("setupapi");
        step.linkSystemLibrary("oleaut32");
        step.linkSystemLibrary("ole32");
        step.linkSystemLibrary("imm32");
        step.linkSystemLibrary("version");
        step.linkSystemLibrary("SDL2");
        step.linkSystemLibrary("SDL2main");
    }
}

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const lib_core = b.addStaticLibrary(.{
        .name = "core",
        .target = target,
        .optimize = optimize,
    });
    lib_core.addCSourceFile("core/src/core/core.c", &flags ++ iflags);
    lib_core.linkSystemLibrary("c");
    lib_core.linkLibC();
    platform_settings(lib_core, target);
    b.installArtifact(lib_core);
}
