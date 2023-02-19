load("//3rdparty/python:pytest.bzl", "pytest_test")
load("@pip_deps//:requirements.bzl", pip_deps = "requirement")

cc_binary(
    name = "collatz",
    srcs = ["collatz.cpp"],
)

cc_binary(
    name = "collatz_multiple",
    srcs = ["collatz_multiple.cpp"],
)

pytest_test(
  name = "collatz_test",
  srcs = ["collatz_test.py"],
  data = [":collatz"],
)

pytest_test(
  name = "collatz_multiple_test",
  srcs = ["collatz_multiple_test.py"],
  data = [":collatz_multiple", "a006577-1000.txt"],
)
