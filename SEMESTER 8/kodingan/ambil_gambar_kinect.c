#include <stdio.h>
#include <stdlib.h>
#include <libfreenect.h>
#include <unistd.h>

freenect_context *f_ctx;
freenect_device *f_dev;
int got_rgb = 0;
int got_depth = 0;

void video_cb(freenect_device *dev, void *rgb, uint32_t timestamp) {
    FILE *f = fopen("test.raw", "wb");
    if (f) {
        fwrite(rgb, 1, 640*480*3, f);
        fclose(f);
    }
    got_rgb = 1;
}

void depth_cb(freenect_device *dev, void *v_depth, uint32_t timestamp) {
    uint16_t *depth = (uint16_t*)v_depth;
    FILE *f = fopen("depth.raw", "wb");
    if (f) {
        fwrite(depth, 2, 640*480, f);
        fclose(f);
    }
    got_depth = 1;
}

int main() {
    if (freenect_init(&f_ctx, NULL) < 0) return 1;
    freenect_set_log_level(f_ctx, FREENECT_LOG_FATAL);
    if (freenect_open_device(f_ctx, &f_dev, 0) < 0) return 1;

    freenect_set_depth_callback(f_dev, depth_cb);
    freenect_set_video_callback(f_dev, video_cb);
    
    freenect_set_video_mode(f_dev, freenect_find_video_mode(FREENECT_RESOLUTION_MEDIUM, FREENECT_VIDEO_RGB));
    freenect_set_depth_mode(f_dev, freenect_find_depth_mode(FREENECT_RESOLUTION_MEDIUM, FREENECT_DEPTH_REGISTERED));

    freenect_start_depth(f_dev);
    freenect_start_video(f_dev);

    while ((!got_rgb || !got_depth) && freenect_process_events(f_ctx) >= 0) {
        usleep(10000);
    }

    freenect_stop_depth(f_dev);
    freenect_stop_video(f_dev);
    freenect_close_device(f_dev);
    freenect_shutdown(f_ctx);
    return 0;
}
