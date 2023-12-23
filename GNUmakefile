VOC = /opt/voc/bin/voc
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir_path := $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
ifndef BUILD
BUILD="build"
endif
build_dir_path := $(mkfile_dir_path)/$(BUILD)
current_dir := $(notdir $(patsubst %/,%,$(dir $(mkfile_path))))
BLD := $(mkfile_dir_path)/build
DPD  =  deps
ifndef DPS
DPS := $(mkfile_dir_path)/$(DPD)
endif
all: get_deps build_deps build_Modules

get_deps:
	#no deps
	#mkdir -p $(DPS)
	#if [ -d $(DPS)/strutils ]; then cd $(DPS)/strutils; git pull; cd -; else cd $(DPS); git clone https://github.com/norayr/strutils; cd -; fi

build_deps:
	mkdir -p $(BUILD)
	cd $(BUILD)
	#make -f $(DPS)/strutils/GNUmakefile BUILD=$(BUILD)

build_Modules:
	cd $(BUILD) && $(VOC) -s $(mkfile_dir_path)/src/DynamicArray.Mod
	cd $(BUILD) && $(VOC) -s $(mkfile_dir_path)/src/Map.Mod
	cd $(BUILD) && $(VOC) -s $(mkfile_dir_path)/src/HashMap.Mod

tests:
	cd $(BUILD) && $(VOC) $(mkfile_dir_path)/test/DynamicArrayTest.Mod -m
	cd $(BUILD) && $(VOC) $(mkfile_dir_path)/test/MapTest.Mod -m
	cd $(BUILD) && $(VOC) $(mkfile_dir_path)/test/HashMapTest.Mod -m
	#build/testStrUtils

clean:
	if [ -d "$(BUILD)" ]; then rm -rf $(BLD); fi
