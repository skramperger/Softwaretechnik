// BitMapReader

#include <stdio.h>
#include <stdlib.h>
#include <ctoy.h>
#include "../util/img_util.c"


struct m_image buffer = M_IMAGE_IDENTITY();

typedef struct tagMEMPTR{
   uint8_t *ptr;
   size_t   size;
}  MEMPTR;

typedef struct tagBITMAPFILEHEADER {
   uint16_t *bfType;
   uint32_t *bfSize;
   uint32_t *bfReserved;
   uint32_t *bfOfBits;
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
   uint32_t *biSize;
   int32_t  *biWidth;
   int32_t  *biHeight;
   uint16_t *biPlanes;
   uint16_t *biBitCount;
   uint32_t *biCompression;
   uint32_t *biSizeImage;
   int32_t  *biXPelsPerMeter;
   int32_t  *biYPelsPerMeter;
   uint32_t *biClrUsed;
   uint32_t *biClrImportant;
} BITMAPINFOHEADER;

MEMPTR mp;
BITMAPFILEHEADER bmfh;
BITMAPINFOHEADER bmih;


//copies a file into memory
//@param filename the filename to be read
//@return object containing pointer and size of the memory segment
MEMPTR readFileToMemory(const char * filename){
   FILE* fp = fopen(filename, "rb");
   if(fseek(fp,0L, SEEK_END) != 0){
      printf("fseek failed\n");
      fclose(fp);
      return;
   }

   size_t size = ftell(fp);
   rewind(fp);

   MEMPTR mm;
   mm.ptr = malloc(size);
   mm.size = size;

   fread(mm.ptr, size, 1, fp);
   fclose(fp);
   return mm;
}

uint32_t readWORDSyncSafe(uint8_t *data, size_t offset){
   // Bitmap die dafür sorgt, dass die ersten 4 Binär Zahlen 0 sind -> & 0x0FFFFFF
}

uint16_t readWORD (uint8_t *data, size_t offset){
   return (data[offset+1] <<8) | data[offset];
}

uint8_t readBYTE(uint8_t *data, size_t offset) {
   return data[offset];      // oder return data[offset];  return *(data + offset); 
}

uint16_t readDWORD (uint8_t *data, size_t offset){
   return (data[offset+3] <<24) | (data[offset+2] << 16) | (data[offset+1] << 8) | data[offset];
}

int32_t readLONG( uint8_t *data, size_t offset) {
   return readDWORD(data, offset);
}

void assBMFHPtr(uint8_t *data){      // assign BMFH Pointer
   bmfh.bfType = (uint16_t*)data;
   bmfh.bfSize = (uint32_t*)(data+2);
   bmfh.bfReserved = (uint32_t*)(data+6);
   bmfh.bfOfBits = (uint32_t*)(data+10);
}

void assBMIHPtr(uint8_t *data){
   bmih.biSize = (uint32_t*)(data+14);
   bmih.biWidth = (int32_t*)(data+18);
   bmih.biHeight = (int32_t*)(data+22);
   bmih.biPlanes = (uint16_t*)(data+26);
   bmih.biBitCount = (uint16_t*)(data+28);
   bmih.biCompression = (uint32_t*)(data+30);
   bmih.biSizeImage = (uint32_t*)(data+34);
   bmih.biXPelsPerMeter = (int32_t*)(data+38);
   bmih.biYPelsPerMeter = (int32_t*)(data+42);
   bmih.biClrUsed = (uint32_t*)(data+46);
   bmih.biClrImportant = (uint32_t*)(data+50);
}

void prnBMFH(){
  printf("bfType (WORD): %02x\n", *bmfh.bfType);
  printf("bfSize (DWORD): %02d\n", *bmfh.bfSize);
  printf("bfReservedSize (WORD): %02x\n", *bmfh.bfReserved);
  printf("bfOfBits (DWORD): %02d\n", *bmfh.bfOfBits);
}

void prnBMIH() {
  printf("biSize (DWORD): %02x\n", *bmih.biSize);
  printf("biWidth (LONG): %02d\n", *bmih.biWidth);
  printf("biHeight (LONG): %02x\n", *bmih.biHeight);
  printf("biPlanes (WORD): %02d\n", *bmih.biPlanes);
  printf("biBitCount (WORD): %02x\n", *bmih.biBitCount);
  printf("biCompression (DWORD): %02d\n", *bmih.biCompression);
  printf("biSizeImage (DWORD): %02x\n", *bmih.biSizeImage);
  printf("biXPelsPerMeter (LONG): %02d\n", *bmih.biXPelsPerMeter);
  printf("biYPelsPerMeter (LONG): %02d\n", *bmih.biYPelsPerMeter);
  printf("biClrUsed (DWORD): %02d\n", *bmih.biClrUsed);
  printf("biClrImportant (DWORD): %02d\n", *bmih.biClrImportant);
}

void ctoy_begin(void)
{

   char byteTeller = NULL;  
   printf("Hello 7ACELI!\n");
   ctoy_window_title("Hello World!");
   ctoy_window_size(512, 512);

   MEMPTR mp = readFileToMemory("data/tetris.bmp");


   /* -- old file readings
   MEMPTR mp = readFileToMemory("data/revision2013.mp3");


   if (readBYTE(mp.ptr, 0) == 0x49 && readBYTE(mp.ptr, 1) == 0x44 && readBYTE(mp.ptr, 2) == 0x33){
      printf("ID3v2 Header found.\n");
   }

   // Version teller
   printf("Version: %d\n", readBYTE(mp.ptr, 3));

   // Following bytes
   for (int i = 0; i < 4; i++){
      byteTeller += readBYTE(mp.ptr, 4+i); 
   }
   printf("Following Bytes: %x", byteTeller);
   //printf("%02x", readBYTE(mp.ptr, 0));
   */

  assBMFHPtr(mp.ptr);
  prnBMFH();
  assBMIHPtr(mp.ptr);
  prnBMIH();

}

void ctoy_end(void)
{
   m_image_destroy(&buffer);
}

void ctoy_main_loop(void)
{

   // exit
   if (ctoy_key_press(CTOY_KEY_Q)) {
      exit(EXIT_SUCCESS);
      return;
   }

   ctoy_swap_buffer(&buffer);
}
