//
// Created by Raynard omongbale on 24/09/2020.
//

#include <stdio.h>
#include <nfiq.h>
#include <imgdecod.h>


/* Declarations needed to make NIST function calls work */
typedef struct opt_flags_s {
    int verbose;
    int old_mode;
    int has_attribs;
} OPT_FLAGS;

OPT_FLAGS flags = {0, 0, 0};

typedef struct image_dets {
    int ret;
    int type;
    int len;
    int width;
    int height;
    int depth;
    int ippi;
    float conf;
    int nfiq_value;

} IMAGE_DETS;
IMAGE_DETS image = {0,0,0,0,0,0};

/***********************************************************************
************************************************************************
#cat: nfiq - Routine computes NFIQ given an input image.
#cat:             This routine uses default statistics for Z-Normalization
#cat:             and default weights for MLP classification.

   Input:
      image       - Takes in an image variable

   Output:
      nfiq       - resulting NFIQ value

   Return Code:
      Zero        - successful completion
      EMPTY_IMG   - empty image detected (feature vector set to 0's)
************************************************************************/
int nfiq(char *img) {
    unsigned char *imagedata;
    if((image.ret = read_and_decode_grayscale_image(img, &image.type, &imagedata, &image.len, &image.width, &image.height, &image.depth, &image.ippi)))
    {
        if(image.ret == -3) /* UNKNOWN_IMG */
            fprintf(stderr, "Hint: Use -raw for raw images\n");
        exit(image.ret);
    }
    //Compute NFIQ value
    image.ret = comp_nfiq(&image.nfiq_value, &image.conf, imagedata, image.width, image.height, image.depth, image.ippi, &flags.verbose);
    if(image.ret < 0) {
        free(imagedata);
        exit(image.ret);
    }
    return image.nfiq_value;
}

