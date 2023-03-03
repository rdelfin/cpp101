from typing import Tuple, List, Optional
import subprocess


def run_binary_raw(binary: str, stdin: str, args: Optional[List[str]] = None, timeout_s: float = 100) -> Tuple[int, str]:
    if args is None:
        args = list()
    proc = subprocess.Popen(
        [binary] + args,
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
    )
    input_bytes = stdin.encode("utf-8")
    outs, _ = proc.communicate(input_bytes, timeout=timeout_s)
    return (proc.wait(0.1), outs.decode("utf-8"))
