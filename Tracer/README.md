## Info
This is a program built for VU graphics course (CS3258).  
Tiff IO and ray tracing functionalities are mainly used in this project.

# GraphicsVU
This is a Repo built for computer graphics class taught at VU  
Author: Lingfeng Li
Organization: Vanderbilt University
Last Date Modified: 23/Apr/2019

## Project Description  
This is a project for class CS 3258 "Computer Graphics".
Initial distribution (openGL, main.cpp) was given by Professor Bobby Bodenheimer.
It is designed to be a semester-long project.
The purpose of this project is to study basic computer graphics, algorithms, and ray-tracing.
The command line tool supports reading, writing and giving info for baseline Tiff images
Two different draw 3D graphics modes are supported:
* 2D Drawing with Matrices Transformation (Based on legacy code)
* 3D Modeling with Ray Tracing


## Currently supported commands
### Commands for basic functionality and TIFF images
    read filename  
        read commands from file given by filename, lines start with # will be ignored

    move x y z
        dummy command with 3 input parameters

    draw x y z
        dummy command with 3 input parameters

    color x y z
        dummy command with 3 input parameters

    quit
        command to exit the command line tool and clean up memory

    pause sec
        pause the program for sec seconds

    tiffstat filename
        display all info and tags from the tiff file given by filename
        print error message if the file is not a TIFF file
        With improved support for private tags

    tiffread filename
        draw the tiff image from the file given by filename
        print error message if the file is not a TIFF file

    tiffwrite filemame x0 y0 xc yc      (verbose)
        **Need to have other tiff commands to work with**
        write a tiff file from box with image corners (x0, y0) and (xc, yc)
        from already read-in image, and output to location specified by filename

    tiffwrite                           (succinct)
        write current screen to "output.tif" file

    tiffwrite filename                  (mixed)
        write current screen to file with filename specified.

    refresh
        refresh display in case rendering malfunctioned.

    resize x-ratio y-ratio
        Resize the original image with given dimension

    zoom ratio
        Zoom in or out the image given the ratio.

    Border borderMode
        Select different border mode used in resize and zoom command.
        borderMode is identified by the first letter of the second parameter.
        Available option:
        z/Z: out of bound access retrieve value 0. (default)
        f/F: out of bound access retrieve the border pixel value.
        c/C: out of bound access retrieve the reflected pixel value from image.

    Select filterType radius
        Select different filter for resize and zoom commamd.
        filterType is identified by the first letter of the second parameter
        radius is an optional parameter that set the radius of filterType
        Available option:
        l/L: LanczosFilter, (Default)
        g/G: GaussianFilter
        m/M: MitchellFilter
        s/S: SplineFilter
        t/T: TentFilter
        c/C: CatmullFilter
        b/B: BoxFilter

### The following commands are for 2D Transformation. Developed based on legacy code.
    Pop
        pop the top of the matrix stack.

    Push
        duplicate current top matrix

    Translate x, y, z
        translate the origin by the vector (x, y, z)

    Scale sx, sy, sz
        scale in x by sx , etc.

    Rotate θ ax, ay, az
        rotate θ degrees about the axis (ax , ay , az )

    Ortho left, right, bottom, top, near, far
        implement an orthographic projection.

    Perspective verticalFovAngle, aspectRatio_W_to_H, near, far
        implement a perspective transform.

    Lookat fx, fy, fz, ax, ay, az, ux, uy, uz
        Change the camera point of view. The parameters of this command are not clear.
        Refer to legacy code(3D.c) and commands under /scripts to know more.

    Vertex x, y, z
        Draw a line between two points. Use the command twice to draw a line
         by specifying two end points of a line.

    Reset
        Clears the screen and the matrix strack

### The following commands are for basic ray tracing mode
    Screen nx ny
        Set screen with width and height

    Orthocamera
        Use ortho camera mode

    Background
        Set background color

    Sphere R cx cy cz ar ag ab rr rg rb (sr sg sb)
        Set Sphere given parameter (R)adius, (c)enter, (a)mbient light
        (r)eflection light, (s)pecular light

    Triangle ux uy uz vx vy vz wx wy wz ar ag ab rr rg rb (sr sg sb)
        Set triangle given parameter (u) vertex, (v) vertex, (w) vertex,
        (a)mbient light, (r)eflection light, (s)pecular light

    Box ux uy uz vx vy vz ar ag ab rr rg rb (sr sg sb)
        Set box given parameter (u) vertex, (v) vertex,
        (a)mbient light, (r)eflection light, (s)pecular light
        u and v vertex are the front lower left and back upper right
        vertices that specify a box.
        Box is axis-aligned
        
    Plane nx ny nz px py pz ar ag ab rr rg rb sr sg sb
        Set a plane given (n)ormal and (p)oint on plain. 
        With (a)mbient, (r)eflect, and (s)pecular colors.

    Light lr  lg  lb  dx  dy  dz
        Set light source at infinity given parameter
        (l)ight color, (d)irection of light

    Clear
        Clear the screen and data structure

    Trace
        Trace and draw the whole scene



## Data structure representation in the project  
    checkImage: a global matrix to store image data, dimension = 1024*1024*3

    class Image: a singleton class that stores all information about the image file
        in use, including its file descriptor to access it (read-only) contains a
        pointer ImageInfo array to store all tags.

    class ImageInfo: An abstract data container for storing individual tag
        information for Tiff image, uses inheritance and templates to accommodate
        different data types.

    class ImageInfoDetail: A class template that inherits from ImageInfo and store
        tag info according to
        their types.

    class ImageInfoFactory: A utility class that only takes care of creating
        ImageInfoDetail objects, and return the pointer to the object.

    class ImageProc: A class that stores old and new x,y dimension, filter type,
        and border handling mode for doing discrete-continuous convolution in order
        to reconstruct and resample images.

    class ImageProcConfig: A singleton class that stores borderMode and filterType
        information for ImageProc.

    file Filters: contains genericFilter abstract base class and other concrete
        filters that derive from it:
        LanczosFilter: Default Filter, radius = 2
        GaussianFilter
        MitchellFilter
        SplineFilter
        TentFilter
        CatmullFilter
        BoxFilter
        HammingFilter

    class checkImageAccess: The purpose of this class is to provide easy access to
        checkImage 3D array by masking it as 1D array, support 1D array random access.
        Include different border handling modes.

    class helper: A class that contains universal helper functions.

    class MatrixStack: A class that is developed based on legacy code provided
        by Professor Bobby. The legacy code exists in src/LegacyCMD as 3D.c
        The representation of a simple model that is widely used in contemporary
        real-time graphics industry

    class Vector: A template class able to mimic computation of mathematical vectors
        in multiple dimensions.
        The class definition and implementation are done by Professor G. Hemingway at
        Vanderbilt University. My implementation can be found at CS3251 assignment 6.

    class Shapes: A pure virtual abstract class that models the basic structure of
        creation of shapes.
        Triangle, Box, Sphere, Plane:  Derived polymorphism-ready class, contains implementation
            for hit detection. The classes use Vector<3U> as representation of vectors.
        Struct Color with overloaded operateors, RayInfo (for information tracing) are provided.


    class RayTrace: A singleton class that uses Shapes to construct scenes, does necessary
        setups for ray tracing and performs ray tracing. The combined Vector, Shapes,
        and RayTrace classes constitute of a simplified model for ray tracing, which is
        prevalent in animation industry and RTX.
        Struct Cam (for global camera) and Lit (for light source) are provided to
        facilitate management.

### Note
    The makefile is located in foler /src. It is created for macOS system.
    Makefile.C and Makefile.origin are templates for Linux.
    Modify them to compile the project in different environment.

### Extra Credit Info
    The Following feature(s) have been added:
        Plane
        Specular Triangle and Box


### Question:
    The way to compare between different file descriptor?
    Why polymorphism + inheritance's base class destructor when using default
    will give error "derived class destructor more lax than base"?
