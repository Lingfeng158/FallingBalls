//
// Created by Lingfeng Li on 8/6/19.
//

#include <cstdlib>
#include <dirent.h>
#include <iostream>
#include <vector>
#include <thread>

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

/**
 * creates tif Images using tracer
 * supported for multithreading
 * single thread uses defualt parameter
 * @param procNo the No. of current running thread
 * @param totalProc total No. of running divisions
 */
void createImg(std::vector<std::string> dirList, int procNo=0, int totalProc=1){

    int totalSize=dirList.size();
    int dividedSize=totalSize/totalProc+1;
    for(int index=procNo*dividedSize;index<(procNo+1)*dividedSize;index++){
        if(index<totalSize){
            std::cout<<"from thread NO: "<<procNo<<std::endl;
            std::string cmd="../Tracer/tracer read ../txt/"+ (dirList[index]);
            std::system(cmd.c_str());
        }
    }
//    for(std::vector<std::string>::iterator it=a.begin();it!=a.end();it++){
//        std::string cmd="../Tracer/tracer read ../txt/"+ (*it);
//        std::system(cmd.c_str());
//    }
//    std::cout<<procNo;
}

int main(int argc, char** argv){
    std::string dir="../txt";
    std::vector<std::string> a=listdir(dir);
    //get max thread count
    //-1 for not slow down computer
    int maxThread=std::thread::hardware_concurrency()-1;
    //need to spawn maxThread-1
    std::vector<std::thread> threads;
    for(int i=0;i<maxThread-1;i++){
        threads.push_back(std::thread(createImg, a, i, maxThread));
    }
    try{
        createImg(a, maxThread-1, maxThread);
    }catch(...){
        for(auto& t:threads)
            t.join();
        throw;
    }

    for(auto& t:threads)
        t.join();
    //create video.mp4 at parent folder
    std::system("ffmpeg -framerate 25 -i ../Images/%04d.tif ../video.mp4");
}