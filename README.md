# A1932 Classroom Translator

面向 Ubuntu 24.04、Core m3-8210Y 与 Intel UHD 617 的小型 C++20 实时英文课堂字幕工具。

## 当前功能
- PipeWire 麦克风采集，目标格式 16 kHz / 单声道 / float32
- 低成本能量 VAD，带 300 ms 预卷、静音挂起及强制切段
- whisper.cpp + GGML Vulkan 英文识别
- 有界队列，过载时丢弃最旧待识别片段
- stdout、命名管道与 UTF-8 文本记录
- Ctrl+C 协作式停止

## 安装与构建
```bash
./scripts/bootstrap.sh
./scripts/build-native.sh
```
用 `vulkaninfo --summary` 确认 UHD 617 可见，然后运行：
```bash
./scripts/run-class.sh
```
另一个终端读取 FIFO：
```bash
cat /tmp/classroom-translator.pipe
```

## 注意
首版刻意只做英文识别。中文翻译应作为低优先级、可丢弃的独立持久进程加入，避免拖慢 OneNote 和英文字幕。当前 VAD 是轻量能量门限，教室噪声较大时请调 `vad.threshold`。

## 验证 Vulkan
启动时 whisper.cpp/ggml 会打印后端信息。请确认其中明确出现 Vulkan 和 Intel UHD 617；若没有，不要假定 GPU 已启用。
