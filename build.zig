const std = @import("std");
const stdout = std.io.getStdOut().writer();
const print = @import("std").debug.print;

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
};

const iflags = [_][]const u8{
    "-I", "src",
    "-I", "example/src",
    "-I", "vendor/glad/include",
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

pub fn build_add_run(b: *std.Build, exe: *Step.Compile, comptime name: []const u8) void {
    const run_cmd = b.addRunArtifact(exe);
    run_cmd.step.dependOn(b.getInstallStep());
    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = b.step("run:" ++ name, "Run the " ++ name);
    run_step.dependOn(&run_cmd.step);
}

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const core_flags = [_][]const u8{
        "-DEXPORT",
    };
    const core = b.addStaticLibrary(.{
        .name = "core",
        .target = target,
        .optimize = optimize,
    });
    core.addCSourceFile("src/os/os.c", &core_flags ++ flags ++ iflags);
    core.linkSystemLibrary("c");
    core.linkLibC();
    platform_settings(core, target);
    b.installArtifact(core);

    const example_flags = [_][]const u8{};
    const example_name = "example";
    const example = b.addExecutable(.{
        .name = example_name,
        .target = target,
        .optimize = optimize,
    });
    example.addCSourceFile("example/src/example.c", &example_flags ++ flags ++ iflags);
    example.linkSystemLibrary("c");
    example.linkSystemLibrary("core");
    example.addLibraryPath("zig-out/lib");
    example.linkLibC();
    platform_settings(example, target);
    // b.installArtifact(example);

    // `zig build run -- arg1 arg2 etc`
    // build_add_run(b, example, example_name);
}
