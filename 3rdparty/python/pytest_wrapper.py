import sys
import pytest

# if using 'bazel test ...'
if __name__ == "__main__":
    sys.exit(pytest.main([__file__, "--verbose"] + sys.argv[1:]))
