# Prototyping Guide 
In order to create a good documentation the general setup of the `file-tree` has to be understood. Therefor the `file-tree`can be divided into two parts:

- [X] PlatformIO Part
- [X] Documentation Part

## PlatformIO 

The programming part is done in the tree part `/src/`. Here the `main.cpp` file is stored on the top level. 

![src-cpp](https://github.com/ECE-IoT/Prototyping/blob/master/docs/assets/src-cpp.png)

For every new category there should be a appropriate `sub-file-tree` where corresponding topics can be collected. As a starting example the directories `/src/arduino-hardware/`, `/src/arduino-iot-cloud/` and `/src/aws/` have been created. For every new part of prototyping a suited folder in the example directories has to be created, *eg.* `/src/aws/mqtt/`. All relevant files can be saved here (`.cpp`, `.hpp` etc...). 

## Documentation

The documentation part ist done in the tree part `/docs/src/`

![src-docs](https://github.com/ECE-IoT/Prototyping/blob/master/docs/assets/src-docs.png)

Here a mirror directory of the `/src/` is created. That simplifies the overall visual structure. In the corresponding `sub-folder`, *eg.* `/docs/src/aws/mqtt` the necessary **MARKDOWN** `.md` needs to be stored. The Markdown file is used to record all necessary information about the finished prototyping.