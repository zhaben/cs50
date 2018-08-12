# Questions

## What's `stdint.h`?

'stdint' is a header file that standardizes integers (exact-width) across different systems.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Unsigned char, unsigned short, unsigned int, and unsigned long long. Unsigned integers are useful when dealing with values that will always be
non-negative, and these aliases are used to specify the number of bytes across systems.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

A BYTE is 1 byte, a DWORD is 4 bytes, a LONG is 8 bytes, and a WORD is 2 bytes.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first 2 bytes of the BMP file format are the character "B" then the character "M" in ASCII encoding.

## What's the difference between `bfSize` and `biSize`?

bfsize is the size, in bytes, of the whole bmp file, while bisize is the size of the info headers.
bfSize = biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)
bfSize = biSizeImage + 54

since BITMAPFILEHEADER = 40 and BITMAPINFOHEADER = 14

biSizeImage = (biWidth * sizeof(RGBTRIPLE) + padding) * abs(biHeight)

## What does it mean if `biHeight` is negative?

biHeight specifies the height of the bitmap, in pixels.
If biHeight is positive, the bitmap is a bottom-up DIB and its origin is the lower-left corner.
If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.
This is to save space in the header by avoiding the addition of one more field.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount specifies the number of bits per pixel (bpp).
For uncompressed formats, this value is the average number of bits per pixel.
For compressed formats, this value is the implied bit depth of the uncompressed image, after the image has been decoded.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If it can't find the file.
-The file doesn't exist.
-The file is opened in a mode that doesn't allow other accesses.
-The file exists, but I don't have permissions.
-A file exists with the name I gave, but the current directory of the process is not what I expected so the relative pathname fails to find and open the file.

I would have to check the errno code.

## Why is the third argument to `fread` always `1` in our code?

The third argument of fread is 'nmemb', which is the number of elements, each one with a size of size bytes.
The number is always 1 because I am reading in 1 element at a time.

fread(ptr, size, nmemb, source) reads in from source, nmemb number of elements, and store them starting at the address given by ptr.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4
RGBTriple is 3 bytes. (4 - (3 * 3) % 4) % 4 = 3.
3 pixels * 3 bytes per pixel * 3 padding = 12, which is a multiple of 4.

## What does `fseek` do?

fseek moves the position indicator to a different location in the file.

## What is `SEEK_CUR`?

SEEK_CUR moves file pointer position to given location.

## Whodunit?
After changing all of the red pixels to white, I uncovered the message, "It was Professor Plum with the candlestick in the library!""
