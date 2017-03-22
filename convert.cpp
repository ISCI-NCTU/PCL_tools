#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

int
main (int argc, char** argv)
{
    bool binary = true;

    if(argc < 3) 
    {
        std::cerr << "Usage:" << std::endl;
        std::cerr << argv[0] << " [-a] input.ply output.pcd" << std::endl;
        std::cerr << "\t-a\tASCII output" << std::endl;
        return (1);
    }

    if(argc == 4) 
    {
        if(strncmp(argv[1],"-a",2) != 0) 
        {
            std::cerr << "Error: unknown option!" << std::endl;
            return (1);
        }
        else 
        {
            binary = false;
            argv += 1;
        }
    }

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

    pcl::PLYReader reader;
    reader.read<pcl::PointXYZ> (argv[1], *cloud);

    std::cerr << "Read cloud: " << std::endl;
    std::cerr << *cloud << std::endl;

    pcl::PCDWriter pcdwriter;
    pcdwriter.write<pcl::PointXYZ> (argv[2], *cloud, binary);


    pcl::visualization::CloudViewer viewer("Simple Cloud Viewer");
    viewer.showCloud(cloud);
    while (!viewer.wasStopped()){}

    return (0);
}



