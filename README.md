#Matrix Multiplication Case
## How to build
```shell
/usr/bin/clang-6.0 -O2 -fno-strict-aliasing -fno-tree-vectorize matmul.cpp
emcc -O2 -s TOTAL_MEMORY=1073741824 -s ALLOW_MEMORY_GROWTH=1 -fno-strict-aliasing matmul.cpp -o mat.html
```
`mat.html`, `mat.js` and ` mat.wasm` are generated files by `emcc`.

## Test environment
- CPU: Intel(R) Core(TM) i7-5960X CPU @ 3.00GHz (8 core)
- OS: Ubuntu 16.04.5 LTS 
- native compiler: clang 6.0.1
- wasm compiler: emscripten 1.38.21 (based on clang 6.0.1)
- Chrome 73.0.3683.75 (64-bit)
- Firefox 65.0 (64-bit)

## Result
 Result  | Native | Chrome	| Firefox
 -------- | :-----------:  | :-----------:  | :-----------:
 time(us)	| 6275382	| 14789000 | 15947000
 time/native time | 1 | 2.36	| 2.54


