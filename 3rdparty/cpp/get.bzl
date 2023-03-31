load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")

def get_cpp_externals():
    http_file(
        name = "CLI11",
        downloaded_file_path = "CLI11.hpp",
        urls = ["https://github.com/CLIUtils/CLI11/releases/download/v1.9.1/CLI11.hpp"],
        sha256 = "52a3bc829a000fb26645328c9093b014e08547dde50c66d4316aef624046dc4b",
    )

    http_archive(
      name = "com_google_googletest",
      urls = ["https://github.com/google/googletest/archive/5ab508a01f9eb089207ee87fd547d290da39d015.zip"],
      strip_prefix = "googletest-5ab508a01f9eb089207ee87fd547d290da39d015",
    )
