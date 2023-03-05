load("//3rdparty/python:pytest.bzl", "pytest_test")
#load("//test_common")
load("@pip_deps//:requirements.bzl", pip_deps = "requirement")

cc_binary(
    name = "wh",
    srcs = ["wh.cpp"],
    deps = ["//3rdparty/cpp:CLI11"],
)

pytest_test(
  name = "wh_test",
  srcs = ["wh_test.py"],
  #deps = ["//test_common:test_common"],
  data = [
      ":wh",
      "test_data/humpty_dumpty_capitalised.txt",
      "test_data/humpty_dumpty_lower_case.txt",
      "test_data/humpty_dumpty_punctuation.txt",
      "test_data/pg27995_results.txt",
      "test_data/pg27995.txt"
  ],
)
