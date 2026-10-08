#!/usr/bin/env bash
set -euo pipefail
exec ./build/classroom-translator --config config/default.conf "$@"
