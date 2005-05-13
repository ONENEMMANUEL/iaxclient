/* Copyright (C) 2002 Jean-Marc Valin 
   File: mics.c
   Various utility routines for Speex

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:
   
   - Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
   
   - Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
   
   - Neither the name of the Xiph.org Foundation nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.
   
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "misc.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef RELEASE
void print_vec(float *vec, int len, char *name)
{
   int i;
   printf ("%s ", name);
   for (i=0;i<len;i++)
      printf (" %f", vec[i]);
   printf ("\n");
}
#endif

#ifdef FIXED_DEBUG
long long spx_mips=0;
#endif


spx_uint32_t be_int(spx_uint32_t i)
{
   spx_uint32_t ret=i;
#ifndef WORDS_BIGENDIAN
   ret =  i>>24;
   ret += (i>>8)&0x0000ff00;
   ret += (i<<8)&0x00ff0000;
   ret += (i<<24);
#endif
   return ret;
}

spx_uint32_t le_int(spx_uint32_t i)
{
   spx_uint32_t ret=i;
#ifdef WORDS_BIGENDIAN
   ret =  i>>24;
   ret += (i>>8)&0x0000ff00;
   ret += (i<<8)&0x00ff0000;
   ret += (i<<24);
#endif
   return ret;
}

#if BYTES_PER_CHAR == 2
void speex_memcpy_bytes(char *dst, char *src, int nbytes)
{
  int i;
  int nchars = nbytes/BYTES_PER_CHAR;
  for (i=0;i<nchars;i++)
    dst[i]=src[i];
  if (nbytes & 1) {
    /* copy in the last byte */
    int last_i = nchars;
    char last_dst_char = dst[last_i];
    char last_src_char = src[last_i];
    last_dst_char &= 0xff00;
    last_dst_char |= (last_src_char & 0x00ff);
    dst[last_i] = last_dst_char;
  }
}
void speex_memset_bytes(char *dst, char c, int nbytes)
{
  int i;
  spx_int16_t cc = ((c << 8) | c);
  int nchars = nbytes/BYTES_PER_CHAR;
  for (i=0;i<nchars;i++)
    dst[i]=cc;
  if (nbytes & 1) {
    /* copy in the last byte */
    int last_i = nchars;
    char last_dst_char = dst[last_i];
    last_dst_char &= 0xff00;
    last_dst_char |= (c & 0x00ff);
    dst[last_i] = last_dst_char;
  }
}
#else
void speex_memcpy_bytes(char *dst, char *src, int nbytes)
{
  memcpy(dst, src, nbytes);
}
void speex_memset_bytes(char *dst, char src, int nbytes)
{
  memset(dst, src, nbytes);
}
#endif

void *speex_alloc (int size)
{
   return calloc(size,1);
}

void *speex_realloc (void *ptr, int size)
{
   return realloc(ptr, size);
}

void speex_free (void *ptr)
{
   free(ptr);
}

void *speex_move (void *dest, void *src, int n)
{
   return memmove(dest,src,n);
}

void speex_error(const char *str)
{
   fprintf (stderr, "Fatal error: %s\n", str);
   exit(1);
}

void speex_warning(const char *str)
{
   fprintf (stderr, "warning: %s\n", str);
}

void speex_warning_int(const char *str, int val)
{
   fprintf (stderr, "warning: %s %d\n", str, val);
}

void speex_rand_vec(float std, spx_sig_t *data, int len)
{
   int i;
   for (i=0;i<len;i++)
      data[i]+=SIG_SCALING*3*std*((((float)rand())/RAND_MAX)-.5);
}

float speex_rand(float std)
{
   return 3*std*((((float)rand())/RAND_MAX)-.5);
}

void _speex_putc(int ch, void *file)
{
   FILE *f = (FILE *)file;
   fprintf(f, "%c", ch);
}
