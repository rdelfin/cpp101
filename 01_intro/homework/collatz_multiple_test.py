from typing import Tuple, List
import subprocess


def _run_collatz_raw(stdin: str, timeout_s: float = 100) -> Tuple[int, str]:
    proc = subprocess.Popen(
        "01_intro/homework/collatz_multiple",
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
    )
    input_bytes = stdin.encode("utf-8")
    outs, _ = proc.communicate(input_bytes, timeout=timeout_s)
    return (proc.wait(0.1), outs.decode("utf-8"))


def _run_collatz(numbers: List[int], timeout_s: float = 100) -> Tuple[int, List[int]]:
    stdin = f"{len(numbers)}\n" + "".join(f"{n}\n" for n in numbers)
    (exit_code, outs) = _run_collatz_raw(stdin, timeout_s)
    out_list = [int(l) for l in outs.splitlines() if l.isdigit()]
    return (exit_code, out_list)


def test_nonsense():
    # This should exit basically immediately
    (exit_code, output) = _run_collatz_raw("this is nonsense\n", timeout_s=1)
    assert exit_code != 0


def test_negatives():
    # This should exit basically immediately
    (exit_code, output) = _run_collatz([-10, 10, 12], timeout_s=1)
    assert exit_code != 0


def test_negatives_elsewhere():
    # This should exit basically immediately
    (exit_code, output) = _run_collatz([1, 2, 3, -14], timeout_s=1)
    assert exit_code != 0


def test_zero():
    # This should exit basically immediately
    (exit_code, output) = _run_collatz([0, 5, 3], timeout_s=1)
    assert exit_code != 0


def test_zero_elsewhere():
    # This should exit basically immediately
    (exit_code, output) = _run_collatz([2, 4, 0], timeout_s=1)
    assert exit_code != 0


def test_five():
    (exit_code, output) = _run_collatz([5])
    assert exit_code == 0
    assert output == [5]


def test_repeated():
    (exit_code, output) = _run_collatz([5, 5, 10])
    assert exit_code == 0
    assert output == [5, 5, 6]


def test_oeis_sequence():
    # Load in the OEIS sequence we generated
    with open("01_intro/homework/a006577-1000.txt") as f:
        data = f.readlines()
    oeis_sequence = [int(n) for n in data]
    # Run collatz with n between 1 and 1000 inclusive
    (exit_code, output) = _run_collatz(list(range(1, 1001)))
    assert exit_code == 0
    assert output == oeis_sequence
