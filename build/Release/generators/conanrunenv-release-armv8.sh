script_folder="/Users/jackson/Documents/Terris/Terris/build/Release/generators"
echo "echo Restoring environment" > "$script_folder/deactivate_conanrunenv-release-armv8.sh"
for v in LD_LIBRARY_PATH DYLD_LIBRARY_PATH
do
   is_defined="true"
   value=$(printenv $v) || is_defined="" || true
   if [ -n "$value" ] || [ -n "$is_defined" ]
   then
       echo export "$v='$value'" >> "$script_folder/deactivate_conanrunenv-release-armv8.sh"
   else
       echo unset $v >> "$script_folder/deactivate_conanrunenv-release-armv8.sh"
   fi
done

export LD_LIBRARY_PATH="/Users/jackson/.conan2/p/b/rayli4530d4d0bbb97/p/lib:/Users/jackson/.conan2/p/b/glfwee77cc6b0deda/p/lib:/Users/jackson/.conan2/p/b/zlib5d629da551ada/p/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
export DYLD_LIBRARY_PATH="/Users/jackson/.conan2/p/b/rayli4530d4d0bbb97/p/lib:/Users/jackson/.conan2/p/b/glfwee77cc6b0deda/p/lib:/Users/jackson/.conan2/p/b/zlib5d629da551ada/p/lib${DYLD_LIBRARY_PATH:+:$DYLD_LIBRARY_PATH}"