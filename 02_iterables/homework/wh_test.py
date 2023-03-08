from typing import Tuple, List, Optional, Dict
import subprocess
from test_common import run_binary_raw


def _run_wh_raw(
    stdin: str, args: Optional[List[str]] = None, timeout_s: float = 100
) -> Tuple[int, str]:
    return run_binary_raw("02_iterables/homework/wh", stdin, args, timeout_s)


def _run_wh(
    stdin: str, args: Optional[List[str]] = None, timeout_s: float = 100
) -> Tuple[int, List[Tuple[str, int]]]:
    (exit_code, output) = _run_wh_raw(stdin, args, timeout_s)
    lines = output.splitlines()
    result = []
    for line in lines:
        split = line.split()
        assert len(split) == 2, "Each output line should contain two elements"
        result.append((split[0], int(split[1])))
    return (exit_code, result)


def _is_sorted(items: List[Tuple[str, int]], descending: bool = True) -> bool:
    if len(items) == 0:
        return True
    prev_count = items[0][1]
    for _, count in items:
        if (descending and count > prev_count) or (
            not descending and count < prev_count
        ):
            return False
    return True


def _only_unique_words(items: List[Tuple[str, int]]) -> bool:
    return len(set(word for word, _ in items)) == len(items)


def _lines_to_dict(lines: List[Tuple[str, int]]) -> Dict[str, int]:
    return {word: count for word, count in lines}


# Empty should print nothing (trimmed)
def test_empty():
    (exit_code, output) = _run_wh_raw("")
    assert exit_code == 0
    assert output.strip() == ""


# Simple one-liner with a clear sorted order
def test_simple():
    (exit_code, output_list) = _run_wh("word word word potato potato this\n")
    assert exit_code == 0
    assert output_list == [("word", 3), ("potato", 2), ("this", 1)]


HUMPTY_DUMPTY_DICT = {
    "dumpty": 3,
    "humpty": 3,
    "a": 2,
    "all": 2,
    "king's": 2,
    "the": 2,
    "again": 1,
    "and": 1,
    "back": 1,
    "couldn't": 1,
    "fall": 1,
    "great": 1,
    "had": 1,
    "horses": 1,
    "men": 1,
    "on": 1,
    "put": 1,
    "sat": 1,
    "together": 1,
    "wall": 1,
}


def test_humpty_dumpty():
    with open("02_iterables/homework/test_data/humpty_dumpty_lower_case.txt") as f:
        humpty_dumpty_text = f.read()
    (exit_code, output) = _run_wh(humpty_dumpty_text)
    assert exit_code == 0
    assert _is_sorted(output)
    assert _only_unique_words(output)
    word_dict = _lines_to_dict(output)
    assert word_dict == HUMPTY_DUMPTY_DICT


def test_humpty_dumpty_ordered():
    with open("02_iterables/homework/test_data/humpty_dumpty_lower_case.txt") as f:
        humpty_dumpty_text = f.read()
    (exit_code, output) = _run_wh(humpty_dumpty_text)
    assert exit_code == 0
    assert output == [
        ("dumpty", 3),
        ("humpty", 3),
        ("a", 2),
        ("all", 2),
        ("king's", 2),
        ("the", 2),
        ("again", 1),
        ("and", 1),
        ("back", 1),
        ("couldn't", 1),
        ("fall", 1),
        ("great", 1),
        ("had", 1),
        ("horses", 1),
        ("men", 1),
        ("on", 1),
        ("put", 1),
        ("sat", 1),
        ("together", 1),
        ("wall", 1),
    ]


def test_humpty_dumpty_capitalised():
    with open("02_iterables/homework/test_data/humpty_dumpty_capitalised.txt") as f:
        humpty_dumpty_text = f.read()
    (exit_code, output) = _run_wh(humpty_dumpty_text)
    assert exit_code == 0
    assert _is_sorted(output)
    assert _only_unique_words(output)
    word_dict = _lines_to_dict(output)
    assert word_dict == HUMPTY_DUMPTY_DICT


def test_humpty_dumpty_puncuation():
    with open("02_iterables/homework/test_data/humpty_dumpty_punctuation.txt") as f:
        humpty_dumpty_text = f.read()
    (exit_code, output) = _run_wh(humpty_dumpty_text)
    assert exit_code == 0
    assert _is_sorted(output)
    assert _only_unique_words(output)
    word_dict = _lines_to_dict(output)
    assert word_dict == HUMPTY_DUMPTY_DICT


def test_humpty_dumpty_args_reverse():
    with open("02_iterables/homework/test_data/humpty_dumpty_lower_case.txt") as f:
        humpty_dumpty_text = f.read()
    (exit_code, output) = _run_wh(humpty_dumpty_text, ["-r"])
    assert exit_code == 0
    assert _is_sorted(output, False)
    assert _only_unique_words(output)
    word_dict = _lines_to_dict(output)
    assert word_dict == HUMPTY_DUMPTY_DICT


def test_humpty_dumpty_args_n6():
    with open("02_iterables/homework/test_data/humpty_dumpty_lower_case.txt") as f:
        humpty_dumpty_text = f.read()
    (exit_code, output) = _run_wh(humpty_dumpty_text, ["-n", "6"])
    assert exit_code == 0
    assert _is_sorted(output, False)
    assert _only_unique_words(output)
    word_dict = _lines_to_dict(output)
    assert word_dict == {
        "dumpty": 3,
        "humpty": 3,
        "a": 2,
        "all": 2,
        "king's": 2,
        "the": 2,
    }


def test_humpty_dumpty_args_all():
    with open("02_iterables/homework/test_data/humpty_dumpty_lower_case.txt") as f:
        humpty_dumpty_text = f.read()
    (exit_code, output) = _run_wh(humpty_dumpty_text, ["-n", "14", "-r"])
    assert exit_code == 0
    assert _is_sorted(output, False)
    assert _only_unique_words(output)
    word_dict = _lines_to_dict(output)
    assert word_dict == {
        "again": 1,
        "and": 1,
        "back": 1,
        "couldn't": 1,
        "fall": 1,
        "great": 1,
        "had": 1,
        "horses": 1,
        "men": 1,
        "on": 1,
        "put": 1,
        "sat": 1,
        "together": 1,
        "wall": 1,
    }


def test_book():
    with open("02_iterables/homework/test_data/pg27995.txt") as f:
        book_text = f.read()
    (exit_code, output) = _run_wh(book_text)
    assert exit_code == 0
    assert _is_sorted(output)
    assert _only_unique_words(output)
    word_dict = _lines_to_dict(output)

    with open("02_iterables/homework/test_data/pg27995_results.txt") as f:
        correct_lines = f.readlines()
    correct_word_dict = {line.split()[0]: int(line.split()[1]) for line in correct_lines}
    assert word_dict == correct_word_dict
