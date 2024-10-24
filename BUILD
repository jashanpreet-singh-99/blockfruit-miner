# define configuration for release or debug
config_setting(
    name = "release",
    values = {
        "compilation_mode": "opt",
    },
)

config_setting(
    name = "debug",
    values = {
        "compilation_mode": "dbg",
    },
)

# Add external libraries
cc_library(
    name = "terminal_lib",
    srcs = ["utils/terminal.cpp"],
    hdrs = ["utils/terminal.h"],
    visibility = ["//visibility:public"],
)


cc_binary(
    name = "BlockFruit",
    srcs = ["main.cpp"],
    deps = [":terminal_lib"],
    copts = select({
        ":release": ["-O2", "-DNDEBUG"],
        ":debug": ["-g", "-DDEBUG"],
        "//conditions:default": [],
    }),
    linkopts = select({
        ":release": ["-s"],
        ":debug": [],
        "//conditions:default": [],
    }),
)

