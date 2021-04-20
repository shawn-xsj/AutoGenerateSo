import os
file_path_src = "./src/"
command = "g++ "
parameter = "-shared -fPIC -o lib"
module = "USS"
type = ".so"
for file in os.listdir(file_path_src):
    if file != "IS31_UserMemMap.h":
        command = command + "./src/"+ file +" "
# command = command + "./src/USS.c "+parameter + module + type
command = command +parameter + module + type
print(command)
os.system(command)

