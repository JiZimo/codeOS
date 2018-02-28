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

#define MAGICNUMBER 0x1AE3
#define CUR_VERSION 0x0001

/*大小端转换*/
#define U8TO16(U81,U82) U81##U82

#define U16HIGHBIT(U16)\
    (uint8_t)((uint16_t)(U16)>>(sizeof(uint8_t)))

/*将sector中的每个元素清零*/
void clearSector(uint8_t sector[]);

/*将一个扇区写入image中的第index个扇区*/
void writeSector(FILE *image,uint8_t sector[],uint16_t index);

/*读在file中由index指引的512字节*/
void readSector(FILE *file,uint8_t sector[],uint16_t index);

/*将ArguumentTable写入虚拟扇区中*/
void writeTable(uint8_t sector[],ArgumentTable table);
