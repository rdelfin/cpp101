from typing import Tuple, List
import subprocess


def _run_collatz_raw(stdin: str, timeout_s: float = 100) -> Tuple[int, str]:
    proc = subprocess.Popen(
        "01_intro/homework/collatz", stdin=subprocess.PIPE, stdout=subprocess.PIPE
    )
    input_bytes = stdin.encode("utf-8")
    outs, _ = proc.communicate(input_bytes, timeout=timeout_s)
    return (proc.wait(0.1), outs.decode("utf-8"))


def _run_collatz(number: int, timeout_s: float = 100) -> Tuple[int, List[int]]:
    (exit_code, outs) = _run_collatz_raw(f"{number}\n", timeout_s)
    out_list = [int(l) for l in outs.splitlines() if l.isdigit()]
    return (exit_code, out_list)


def test_nonsense():
    # This should exit basically immediately
    (exit_code, output) = _run_collatz_raw("this is nonsense\n", timeout_s=1)
    assert exit_code != 0


def test_negative():
    # This should exit basically immediately
    (exit_code, output) = _run_collatz(-10, timeout_s=1)
    assert exit_code != 0


def test_zero():
    # This should exit basically immediately
    (exit_code, output) = _run_collatz(0, timeout_s=1)
    assert exit_code != 0


def test_one():
    (exit_code, output) = _run_collatz(1)
    assert exit_code == 0
    assert output == [1]


def test_five():
    (exit_code, output) = _run_collatz(5)
    assert exit_code == 0
    assert output == [5, 16, 8, 4, 2, 1]


def test_very_long():
    (exit_code, output) = _run_collatz(73)
    assert exit_code == 0
    assert output == [
        73,
        220,
        110,
        55,
        166,
        83,
        250,
        125,
        376,
        188,
        94,
        47,
        142,
        71,
        214,
        107,
        322,
        161,
        484,
        242,
        121,
        364,
        182,
        91,
        274,
        137,
        412,
        206,
        103,
        310,
        155,
        466,
        233,
        700,
        350,
        175,
        526,
        263,
        790,
        395,
        1186,
        593,
        1780,
        890,
        445,
        1336,
        668,
        334,
        167,
        502,
        251,
        754,
        377,
        1132,
        566,
        283,
        850,
        425,
        1276,
        638,
        319,
        958,
        479,
        1438,
        719,
        2158,
        1079,
        3238,
        1619,
        4858,
        2429,
        7288,
        3644,
        1822,
        911,
        2734,
        1367,
        4102,
        2051,
        6154,
        3077,
        9232,
        4616,
        2308,
        1154,
        577,
        1732,
        866,
        433,
        1300,
        650,
        325,
        976,
        488,
        244,
        122,
        61,
        184,
        92,
        46,
        23,
        70,
        35,
        106,
        53,
        160,
        80,
        40,
        20,
        10,
        5,
        16,
        8,
        4,
        2,
        1,
    ]
