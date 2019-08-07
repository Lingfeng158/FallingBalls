//
// Created by Lingfeng Li on 8/6/19.
//

#include <cstdlib>
#include <dirent.h>
#include <iostream>
#include <vector>

/**
 * enter directory name and return list of dir in vector
 * return empty list if dir is invalid
 * @param dir
 * @return
 */
std::vector<std::string> listdir(std::string dir){
    DIR* dp=opendir(dir.c_str());
    if(dp==NULL)
        return std::vector<std::string>();
    struct dirent *dirp;
    std::vector<std::string> result;
    while(dirp=readdir(dp)){
        if(std::string(dirp->d_name)!="."&&std::string(dirp->d_name)!="..")
            result.push_back(dirp->d_name);
    }

    closedir(dp);
    return result;
}

int main(int argc, char** argv){
    std::string dir="../txt";
    std::vector<std::string> a=listdir(dir);
    for(std::vector<std::string>::iterator it=a.begin();it!=a.end();it++){
        std::string cmd="../Tracer/tracer read ../txt/"+ (*it);
        std::system(cmd.c_str());
    }
    //create video.mp4 at parent folder
    std::system("ffmpeg -framerate 25 -i ../Images/%04d.tif ../video.mp4");
}