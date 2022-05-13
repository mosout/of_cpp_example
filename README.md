## Export a model
```
python export_resnet.py
```
## Build
```
mkdir build && cd build
cmake -DCMAKE_PREFIX_PATH=/path/to/liboneflow_cpp/share ..
make
```
## Test
```
./of_cpp_example /path/to/model
```