# ==============================================================================
# Binaries and/or source for the following packages or projects are presented under one or more of the following open
# source licenses:
# Makefile       The OpenLane Dataset Authors        Apache License, Version 2.0
# 
# See:
# https://github.com/cocodataset/cocoapi/blob/master/PythonAPI/Makefile
# https://github.com/cocodataset/cocoapi/blob/master/license.txt
#
# Copyright (c) 2022, The OpenLane Dataset Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ==============================================================================

all:
    # install pycocotools locally
	python3 setup.py build_ext --inplace
	rm -rf build

install:
	# install pycocotools to the Python site-packages
	python3 setup.py build_ext install
	rm -rf build

clean:
	rm -rf build
	rm pycocotools/_mask.cpython-38-x86_64-linux-gnu.so