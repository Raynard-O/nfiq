//
// Created by Raynard omongbale on 24/09/2020.
//

#ifndef NFIQ_NFIQLIB_H
#define NFIQ_NFIQLIB_H
#ifdef __cplusplus
extern "C" {
#endif

int nfiq(char *);  //Returns image quality value
unsigned char read_decode(char *);
unsigned char nfiq1(unsigned char );
#ifdef __cplusplus
}
#endif

#endif //NFIQ_NFIQLIB_H
