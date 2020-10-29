#include <limits.h>
//
// Created by Raynard omongbale on 2020-10-29.
//

#include "wsqlib.h"
#include <stdio.h>
#include <sys/param.h>
#include <wsq.h>
#include <ihead.h>
#include <img_io.h>
#include <dataio.h>
#include <imgdecod.h>


typedef struct details { /* image parameters */

    int type;
    int olen;        /* Number of bytes in output data. */
    int width;
    int height;
    int depth;
    int ppi;
    float r_bitrate;         /* target bit compression rate (2.25==>5:1, .75==>15:1)\n\n");*/
    char *outext;          // file extension
    int ret;
} IMAGE_DETS;
    IMAGE_DETS IM = {0,0,0,0,0,0,2.25, "wsq"};

int convert_wsq(char *ifile) {
    int ret;
    char ofile[MAXPATHLEN];     /* Input/Output filenames */
    unsigned char *odata;    /* Output data */
    char *comment_text;
    unsigned char *idata;


    if((ret = read_and_decode_grayscale_image(ifile, &IM.type, &idata, &IM.olen, &IM.width, &IM.height, &IM.depth, &IM.ppi)))
    {
        if(ret == -3) /* UNKNOWN_IMG */
            fprintf(stderr, "Hint: Use -raw for raw images\n");
        return ret;
    }

        if (debug > 0)
        fprintf(stdout, "File %s read\n", idata);
//
    /* Encode/compress the image pixmap. */
    if((ret = wsq_encode_mem(&odata, &IM.olen, IM.r_bitrate,
                             idata, IM.width, IM.height, IM.depth, IM.ppi, comment_text))){
        free(idata);
        if(comment_text != (char *)NULL)
            free(comment_text);
        return ret;
    }
    free(idata);
    if(comment_text != (char *)NULL)
        free(comment_text);

    if(debug > 0)
        fprintf(stdout, "Image data encoded, compressed byte length = %d\n",
                IM.olen);

    /* Generate the output filename. */
    fileroot("image");
    sprintf(ofile, "%s.%s", "image", IM.outext);

    if((ret = write_raw_from_memsize(ofile, odata, IM.olen))){
        free(odata);
        return ret;
    }

    if(debug > 0)
        fprintf(stdout, "Image data written to file %s\n", ofile);

    free(odata);

    /* Exit normally. */
    return ret;
}