# Safety-Critical OpenGL Verification Framework

This repository serves as a testing portfolio for safety-critical graphics drivers, focusing on memory safety and state verification under DO-178C guidelines.

## 📊 Requirements Traceability Matrix (RTM)

| Requirement ID | Description | Test Case | Status |
| :--- | :--- | :--- | :--- |
| **LLR-GRAPHICS-002** | Driver must handle hardware initialization failures gracefully. | `test_llr_002_pipeline_success` | PASS |
| **LLR-GRAPHICS-002** | Driver must clear OpenGL VBO allocations upon initialization failure to prevent memory leaks. | `test_llr_002_resource_leak_check` | FAIL (Bug Logged) |

## 📉 Structural Code Coverage (DO-178C Compliance)
To satisfy DO-178C statement coverage requirements, this project uses **OpenCppCoverage** on Windows to measure test completeness.

* **Analysis Execution:** GoogleTest binaries run directly inside OpenCppCoverage to trace code lines executed during testing.
* **Target Objective:** Achieve 100% code statement coverage across `safety_display.c` to ensure no dead or hidden execution paths exist.
* **Reports:** HTML reports are auto-generated on every commit via the GitHub Actions CI pipeline.
