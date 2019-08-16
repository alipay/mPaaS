//
// Created by Erwin on 16/3/18.
//

#ifndef IJKMEDIA_IJKTOOLS_LIBTOOL_H
#define IJKMEDIA_IJKTOOLS_LIBTOOL_H

#include <stdint.h>
#include <pthread.h>
#include <stddef.h>
#include "engine_types.h"


//For picture util
//extern int picture_compress(PictureOption *opt, jpeg_lib_type use_type);
extern int picture_compress_to_file(PictureOption *opt);

//For audio process(ns/agc)
/*clock_rate:采样率
 *samples_per_frame:每次采样的frame大小,最好为160的整数倍
 *channel_count:声道数
 *webrtc_agc_mode:建议配置为:Fixed_Digital_Gain */
extern void *create_instance(unsigned clock_rate,
                             unsigned samples_per_frame,
                             int channel_count, webrtc_agc_mode agc_mode);

extern int exec_ns_agc(void *state, int16_t *sample_frm);

extern void instance_destroy(void *state);

#endif //IJKMEDIA_IJKTOOLS_LIBTOOL_H
