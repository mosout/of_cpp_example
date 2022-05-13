## Export a model
```
pip install -f https://staging.oneflow.info/branch/master/cpu --pre oneflow
pip install flowvision
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