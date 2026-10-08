#!/usr/bin/env bash
set -euo pipefail
sudo apt update
sudo apt install -y build-essential cmake ninja-build pkg-config libpipewire-0.3-dev libvulkan-dev glslc vulkan-tools git
mkdir -p third_party models
if [ ! -d third_party/whisper.cpp/.git ]; then git clone --depth 1 https://github.com/ggml-org/whisper.cpp third_party/whisper.cpp; fi
bash third_party/whisper.cpp/models/download-ggml-model.sh tiny.en
cp third_party/whisper.cpp/models/ggml-tiny.en.bin models/
