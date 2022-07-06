

//usr/lib/x86_64-linux-gnu/libapr-1.so.0：对‘uuid_generate@UUID_1.0’未定义的引用
//usr/lib/x86_64-linux-gnu/libSM.so.6：对‘uuid_unparse_lower@UUID_1.0’未定义的引用



# >>> conda initialize >>>
# !! Contents within this block are managed by 'conda init' !!
__conda_setup="$('/home/alexlyg/anaconda3/bin/conda' 'shell.bash' 'hook' 2> /dev/null)"
if [ $? -eq 0 ]; then
    eval "$__conda_setup"
else
    if [ -f "/home/alexlyg/anaconda3/etc/profile.d/conda.sh" ]; then
        . "/home/alexlyg/anaconda3/etc/profile.d/conda.sh"
    else
        export PATH="/home/alexlyg/anaconda3/bin:$PATH"
    fi
fi
unset __conda_setup
# <<< conda initialize <<<







Could NOT find PY_em (missing: PY_EM) 
CMake Error at /opt/ros/noetic/share/catkin/cmake/empy.cmake:30 (message):
  Unable to find either executable 'empy' or Python module 'em'...  try
  installing the package 'python3-empy'
  
  cmake -DPYTHON_EXECUTABLE=/usr/bin/python3 -DCMAKE_BUILD_TYPE=Release -DPLUGIN_STANDARD_QPCL=ON -DPLUGIN_STANDARD_QBROOM=ON -DPLUGIN_STANDARD_QRANSAC_SD=ON -DCCCORELIB_USE_CGAL=ON ..
  
  
  catkin_make -DPYTHON_EXECUTABLE=/usr/bin/python3
  
