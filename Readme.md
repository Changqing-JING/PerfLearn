### Install toolings

```shell
sudo apt install python3 graphviz linux-tools-5.15.0-25-generic linux-tools-common google-perftools
sudo pip install gprof2dot
git clone https://github.com/brendangregg/FlameGraph.git
echo "PATH=$(pwd)/FlameGraph:\$PATH" >> ~/.profile
```
