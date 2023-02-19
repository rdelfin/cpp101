load("@rules_python//python:pip.bzl", "compile_pip_requirements")

exports_files(["pytest_wrapper.py"])

compile_pip_requirements(
    name = "requirements",
    extra_args = [
        "--quiet",
        "--resolver=backtracking",
    ],
    requirements_in = "requirements.txt",
    requirements_txt = "requirements.txt.lock",
)
