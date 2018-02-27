/*
 *bodfs:Boot-Only Disk's File System
 *这个英文的使用也许有些小问题，但是大概的意思懂了就好:)
 *此程序是一个创建，编辑bodfs格式映像文件，以及对其进行添加，删除文件等操作
 *详见bodfs官方文档:bodfsmaker使用手册 bodfsv1.0技术手册
 */

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

//有关文件操作的标识符
#define PERMISSION_DENIND -1
#define CLOSE_ERROR 1

typedef struct{
    uint16_t magicNumber;//标识“我是bodfs”永远是0x1AE3
    uint16_t version;//当前版本为0x0001
    uint16_t fileEntrySize;//文件入口头区的大小(byte)
    uint16_t fileEntryCount;//文件入口头的数量
    uint16_t fileEntrySectorCount;//文件入口头区占了几个扇区
    uint16_t firstFreeFileEntry;//第一个空闲文件入口头
    uint16_t firstFreeSector;//第一个空闲文件内容扇区
}ArgumentTable;
