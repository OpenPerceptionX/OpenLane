/* ============================================================================== 
Binaries and/or source for the following packages or projects are presented under one or more of the following open
source licenses:
maskApi.h       The OpenLane Dataset Authors        Apache License, Version 2.0 

See:
https://github.com/cocodataset/cocoapi/blob/master/common/maskApi.h
https://github.com/cocodataset/cocoapi/blob/master/license.txt

Copyright (c) 2022 The OpenLane Dataset Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
============================================================================== */

#pragma once

typedef unsigned int uint;
typedef unsigned long siz;
typedef unsigned char byte;
typedef double* BB;
typedef struct { siz h, w, m; uint *cnts; } RLE;

/* Initialize/destroy RLE. */
void rleInit( RLE *R, siz h, siz w, siz m, uint *cnts );
void rleFree( RLE *R );

/* Initialize/destroy RLE array. */
void rlesInit( RLE **R, siz n );
void rlesFree( RLE **R, siz n );

/* Encode binary masks using RLE. */
void rleEncode( RLE *R, const byte *mask, siz h, siz w, siz n );

/* Decode binary masks encoded via RLE. */
void rleDecode( const RLE *R, byte *mask, siz n );

/* Compute union or intersection of encoded masks. */
void rleMerge( const RLE *R, RLE *M, siz n, int intersect );

/* Compute area of encoded masks. */
void rleArea( const RLE *R, siz n, uint *a );

/* Compute intersection over union between masks. */
void rleIou( RLE *dt, RLE *gt, siz m, siz n, byte *iscrowd, double *o );

/* Compute non-maximum suppression between bounding masks */
void rleNms( RLE *dt, siz n, uint *keep, double thr );

/* Compute intersection over union between bounding boxes. */
void bbIou( BB dt, BB gt, siz m, siz n, byte *iscrowd, double *o );

/* Compute non-maximum suppression between bounding boxes */
void bbNms( BB dt, siz n, uint *keep, double thr );

/* Get bounding boxes surrounding encoded masks. */
void rleToBbox( const RLE *R, BB bb, siz n );

/* Convert bounding boxes to encoded masks. */
void rleFrBbox( RLE *R, const BB bb, siz h, siz w, siz n );

/* Convert polygon to encoded mask. */
void rleFrPoly( RLE *R, const double *xy, siz k, siz h, siz w );

/* Get compressed string representation of encoded mask. */
char* rleToString( const RLE *R );

/* Convert from compressed string representation of encoded mask. */
void rleFrString( RLE *R, char *s, siz h, siz w );