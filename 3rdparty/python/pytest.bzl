"""Wrap pytest"""

load("@rules_python//python:defs.bzl", "py_test")
load("@pip_deps//:requirements.bzl", pip_deps = "requirement")

def pytest_test(name, srcs, deps = [], args = [], data = [], **kwargs):
    """
        Call pytest
    """
    py_test(
        name = name,
        srcs = [
            "//3rdparty/python:pytest_wrapper.py",
        ] + srcs,
        main = "//3rdparty/python:pytest_wrapper.py",
        args = [
            "--capture=no",
        ] + args + ["$(location :%s)" % x for x in srcs],
        python_version = "PY3",
        srcs_version = "PY3",
        deps = deps + [
            pip_deps("pytest"),
            pip_deps("pytest-black"),
            pip_deps("pytest-pylint"),
        ],
        data = data,
        **kwargs
    )
