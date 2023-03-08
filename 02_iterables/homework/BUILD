load("//3rdparty/python:pytest.bzl", "pytest_test")
load("@pip_deps//:requirements.bzl", pip_deps = "requirement")

cc_binary(
    name = "wh",
    srcs = ["wh.cpp"],
    deps = ["//3rdparty/cpp:CLI11"],
)

pytest_test(
  name = "wh_test",
  srcs = ["wh_test.py"],
  deps = ["//test_common"],
  data = [
      ":wh",
  ] + glob(["test_data/*"]),
)
