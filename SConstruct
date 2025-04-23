#!/usr/bin/env python
import os
import sys

# 导入godot-cpp
env = SConscript("godot-cpp/SConstruct")

build_dir = "build/objs"
if not os.path.exists(build_dir):
    os.makedirs(build_dir)

#把目标生成到build_dir
env.VariantDir(build_dir,".",duplicate=0)

# 增加源代码文件
env.Append(CPPPATH=["src/","src/enemy","src/player"])
sources = Glob("src/*.cc")+ Glob("src/**/*.cc") 
#设置共享库
library = env.SharedLibrary(
    "game_core/bin/libgdplayer{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
    source=[os.path.join(build_dir, os.path.relpath(str(src), ".")) for src in sources],

)
Default(library)
