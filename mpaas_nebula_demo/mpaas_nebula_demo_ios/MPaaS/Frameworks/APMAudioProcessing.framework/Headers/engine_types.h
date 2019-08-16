//
// Created by Erwin on 16/3/18.
//

#ifndef IJKMEDIA_IJKTOOLS_DEFINE_TYPES_H
#define IJKMEDIA_IJKTOOLS_DEFINE_TYPES_H

#include <stdint.h>
#include <pthread.h>
#include <stddef.h>

//For queue
#define QUEUE_DEFAULT_CAPACITY 50

typedef enum queue_error_type {
    QUEUE_ERROR_ALLOC_MEMORY_FAILED = 1,
    QUEUE_ERROR_OUTOF_CAPACITY,
} queue_error_type;

typedef enum jpeg_lib_type {
    FFMPEG_ENCODE_LIBYUV_SCALE = 0,
    JPEG_TURBO_ENCODE_LIBYUV_SCALE,
    FFMPEG_ENCODE_FFMPEG_SCALE,
    JPEG_TURBO_DECODE_FFMPEG_ENCODE_FFMPEG_SCALE
} jpeg_lib_type;

typedef enum queue_item_data_type {
    ITEM_DATA_TYPE_VIDEO = 0,
    ITEM_DATA_TYPE_AUDIO,
    ITEM_DATA_TYPE_VIDEO_HARDWARE,
    ITEM_DATA_TYPE_VIDEO_BEAUTY,
    ITEM_DATA_TYPE_VIDEO_OMX_YUV,
    ITEM_DATA_TYPE_VIDEO_OMX_SURFACE,   //The video Drain output command without buffer
} queue_item_data_type;

typedef struct _queue_item {
    void *data;
    size_t sz;
    int64_t pts;
    int rotation;
    int mirror;
    queue_item_data_type item_type;
    struct _queue_item *next;
} QUEUE_ITEM;

typedef struct _queue {
    size_t numitems;
    QUEUE_ITEM *items;
    size_t capacity;
    pthread_mutex_t modify_mutex;
    pthread_cond_t can_read;
    int stop_flag;
    int start_flag;
    int frist_pack_flag;
} QUEUE;


//For audio_echo_cancel
typedef enum webrtc_agc_mode {
    UNCHANGED = 0,
    Adaptive_Analog_Automatic_Gain_Control,
    Adaptive_Digital_Automatic_Gain_Control,
    Fixed_Digital_Gain
} webrtc_agc_mode;

#define BUF_LEN            160
#define ACEM_RES_BUF_LEN   8192
#define ACEM_BUF_SAMPLE_SIZE   4096

typedef short sample;

typedef struct webrtc_ec {
    void *aecm_inst;
    void *ns_inst;
    void *agc_inst;
    webrtc_agc_mode agc_mode;
    int channel_count;
    unsigned samples_per_frame;
    unsigned clock_rate;
    unsigned subframe_len;
    sample tmp_buf[BUF_LEN];
    sample tmp_buf2[BUF_LEN];
    sample res_buf[ACEM_RES_BUF_LEN];
    int res_buf_offset;
    sample near_buf[ACEM_BUF_SAMPLE_SIZE];
    int near_buf_offset;
    sample far_buf[ACEM_BUF_SAMPLE_SIZE];
    int far_buf_offset;
} webrtc_ec;

typedef struct webrtc_nsagc {
    void *ns_inst;
    void *agc_inst;
    webrtc_agc_mode agc_mode;
    int channel_count;
    unsigned samples_per_frame;
    unsigned clock_rate;
    unsigned subframe_len;
    sample src_buf[BUF_LEN];
    sample dst_buf[BUF_LEN];
} webrtc_nsagc;

//For video_util
typedef struct NativeVideoInfo {
    int width;
    int height;
    int video_bit_rate;
    int video_pix_fmt;
    int video_encode_id;
    int audio_encode_id;
    int audio_bit_rate;
    int duration;
    int rotation;
    float fps;
    int is_succeed;
} NativeVideoInfo;

//For video_common

typedef struct VideoOption {
    int width;
    int height;
    int bit_rate;

    const char *src_path;
    const char *dst_path;
} VideoOption;


//For picture_common
#define MAX_SIDE_DIMENSION  1280
typedef enum picture_compress_level {
    SIZE_MODE = 0,
    QUALITY
} picture_compress_level;

typedef struct PictureOption {
    int input_width;
    int input_height;

    int fixed_width;
    int fixed_height;

    int crop_x;
    int crop_y;
    int crop_width;
    int crop_height;
//    MaxVisibility   (0, "最大居中模式，已其中一条边确认另外一边，最大可视"),
//    TopAlign        (1, "上对齐"),
//    DownAlign       (2, "下对齐"),
//    LeftAlign       (3, "左对齐"),
//    RightAlign      (4, "右对齐"),
//    Manual          (5, "手动模式，抠图");
    int crop_mode;
    int output_width;
    int output_height;
    int adjusted_output;
    picture_compress_level compress_level;

    int disable_scale;
    int max_dimension;
    int min_dimension;

    int rotate;
    int need_mirror;
    int need_scale;
    int bitmap_pix_fmt;

    const char *src_path;
    const char *dst_path;

    //日志开启
    int log_debug;
    //开启性能收据收集
    int log_perf;

} PictureOption;

#define SIZE_MODE_Q     125
#define QUALITY_Q 95

typedef enum picture_error_type {
    PIXELS_ERROR = -100,
    MALLOC_ERROR = -10,
    ENCODE_ERROR = -2,
    DECODE_ERROR = -3,
    IO_ERROR = -1,
    PIXFMT_ERROR = -4
} picture_error_type;

//For AECM
#define AECM_FRAME_LEN     1024 * 2

// Recommended settings for particular audio routes. In general, the louder
// the echo is expected to be, the higher this value should be set. The
// preferred setting may vary from device to device.
typedef enum aecm_routing_mode {
    kQuietEarpieceOrHeadset = 0,
    kEarpiece,
    kLoudEarpiece,
    kSpeakerphone,
    kLoudSpeakerphone
} aecm_routing_mode;

//For picture auto quality
enum SrcPixFormat {
    SRC_PIX_FMT_YUV420P = 0,    ///< planar YUV 4:2:0, 12bpp, (1 Cr & Cb sample per 2x2 Y samples)
    SRC_PIX_FMT_RGBA,           ///< packed RGBA 8:8:8:8, 32bpp, RGBARGBA...
};

enum NetworkEnv {
    NET_ENV_3G4G = 0,
    NET_ENV_WIFI,
};

#endif //IJKMEDIA_IJKTOOLS_DEFINE_TYPES_H
