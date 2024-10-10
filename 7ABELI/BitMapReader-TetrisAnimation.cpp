// BitMapReader-Tetris Animation
// Takes a bitmap file and loops through all collective pictures to create an animation


#include <stdio.h>
#include <stdlib.h>
#include <ctoy.h>
#include "../util/img_util.c"

#define COMP 3
#define SCALE 100   // verändert die Größe der Animation

struct m_image buffer = M_IMAGE_IDENTITY();

typedef struct tagMEMPTR{
  uint8_t *ptr;
  size_t   size;
} MEMPTR;

MEMPTR mp;

typedef struct tagBITMAPFILEHEADER {
  uint16_t *bfType;
  uint32_t *bfSize;
  uint32_t *bfReserved;
  uint32_t *bfOffBits;
} BITMAPFILEHEADER;

BITMAPFILEHEADER bmfh;

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

BITMAPINFOHEADER bmih;



//copies a file into the memory
//@param filename the filename to be read
//@return object containig pointer and size of the memory segment
MEMPTR readFileToMemory(const char * filename){
  FILE *fp = fopen(filename, "rb"); 
   
  if(fseek(fp,0L, SEEK_END) != 0){
    //fprintf(stderr, "fseek failed\n");
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


uint8_t readBYTE( uint8_t *data, size_t offset ){
  return data[offset];
}

uint16_t readWORD( uint8_t *data, size_t offset ){
  return (data[offset+1] << 8) | data[offset];
}

uint32_t readDWORD( uint8_t *data, size_t offset ){
  return (data[offset+3] << 24) | (data[offset+2] << 16) | (data[offset+1] << 8) | data[offset];
}

int32_t readLONG( uint8_t *data, size_t offset ){
  return readDWORD(data, offset);
}

void assBMHPtr(uint8_t *data){
  bmfh.bfType = (uint16_t*)data;
  bmfh.bfSize = (uint32_t*)(data+2);
  bmfh.bfReserved = (uint32_t*)(data+6);
  bmfh.bfOffBits = (uint32_t*)(data+10);
  
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

void prnBMH(){
   printf("bfType (WORD) %02x\n",*bmfh.bfType);
   printf("bfSize (DWORD) %d\n",*bmfh.bfSize);
   printf("bfReserved (DWORD) %d\n",*bmfh.bfReserved);
   printf("bfOffBits (DWORD) %d\n",*bmfh.bfOffBits);
   
   printf("biSize (DWORD) %d\n",*bmih.biSize);
   printf("biWidth (LONG) %d\n",*bmih.biWidth);
   printf("biHeight (LONG) %d\n",*bmih.biHeight);
   printf("biPlanes (WORD) %d\n",*bmih.biPlanes);
   printf("biBitCount (WORD) %d\n",*bmih.biBitCount);
   printf("biCompression (DWORD) %d\n",*bmih.biCompression);
   printf("biSizeImage (DWORD) %d\n",*bmih.biSizeImage);
   printf("biXPelsPerMeter (LONG) %d\n",*bmih.biXPelsPerMeter);
   printf("biYPelsPerMeter (LONG) %d\n",*bmih.biYPelsPerMeter);
   printf("biClrUsed (DWORD) %d\n",*bmih.biClrUsed);
   printf("biClrImportant (DWORD) %d\n",*bmih.biClrImportant);
}

void drawSingleImage(uint8_t *data){
  size_t bfSize = *bmfh.bfSize;
  size_t biWidth = *bmih.biWidth;
  size_t biHeight = *bmih.biHeight;

  m_image_destroy(&buffer);
  m_image_create(&buffer, M_UBYTE, biWidth, biHeight, COMP);

  for (size_t y = 0; y < biHeight; y++){
    for (size_t x = 0; x < biWidth; x++){
      uint8_t * fbpixel = (uint8_t *) buffer.data + (y*biWidth + x) *COMP;
      uint32_t pixel = readDWORD(data, bfSize - (((y+1)*biWidth - x) *COMP));

      fbpixel[0] = pixel >> 16;
      fbpixel[1] = pixel >> 8;
      fbpixel[2] = pixel >> 0;
  
    }
  } 
  ctoy_window_size(biWidth*SCALE, biHeight*SCALE);
}

size_t drawSingleFrame(uint8_t *data, uint32_t frIndex, int32_t frWidth, int32_t frHeight) {
  size_t bfSize = *bmfh.bfSize;
  size_t biWidth = *bmih.biWidth;
  size_t biHeight = *bmih.biHeight;


  m_image_destroy(&buffer);
  m_image_create(&buffer, M_UBYTE, frWidth, frHeight, COMP);

  size_t noX = biWidth / frWidth;
  size_t noY = biHeight / frHeight;

  if (biWidth % frWidth != 0 || biHeight % frHeight != 0) {
    printf("Picture misaligment!\n");
  }

  if (frIndex > bfSize / (COMP * frWidth * frHeight)){
    printf("frame is outside of memory\n");
    return;
  }

  size_t xoff = (frIndex % noX) * frWidth;
  size_t yoff = (frIndex / noX) * frWidth;

  for (size_t y = 0; y < frHeight; y++){
    for (size_t x = 0; x < frWidth; x++){
      uint8_t * fbpixel = (uint8_t *) buffer.data + (y*frWidth + x) *COMP;
      uint32_t pixel = readDWORD(data, bfSize - (((y+1+yoff)*biWidth - (x+xoff)) *COMP));

      fbpixel[0] = pixel >> 16;
      fbpixel[1] = pixel >> 8;
      fbpixel[2] = pixel >> 0;
    }

  }
  ctoy_window_size(frWidth*SCALE, frHeight*SCALE);

  return noX * noY;
}

uint8_t frameIdx;


  //FIXME Animation darstellen
void ctoy_begin(void)
{
   printf("Hello 7ACELI!\n");
   ctoy_window_title("Hello World!");
   ctoy_window_size(512, 512);
   
   mp = readFileToMemory("data/tetris.bmp");
   
   assBMHPtr(mp.ptr);
   prnBMH();
   frameIdx = 0;
   
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

   size_t temp = drawSingleFrame(mp.ptr, frameIdx, 8, 8);

   if (++frameIdx >= temp){
    frameIdx = 0;
   }

   ctoy_swap_buffer(&buffer);
   ctoy_sleep(0,100000000);
}
