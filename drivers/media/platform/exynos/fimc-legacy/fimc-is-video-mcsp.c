/*
 * Samsung Exynos5 SoC series FIMC-IS driver
 *
 * exynos5 fimc-is video functions
 *
 * Copyright (c) 2015 Samsung Electronics Co., Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/module.h>
#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/interrupt.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <video/videonode.h>
#include <media/exynos_mc.h>
#include <asm/cacheflush.h>
#include <asm/pgtable.h>
#include <linux/firmware.h>
#include <linux/dma-mapping.h>
#include <linux/scatterlist.h>
#include <linux/videodev2_exynos_camera.h>
#include <linux/v4l2-mediabus.h>
#include <linux/bug.h>

#include "fimc-is-core.h"
#include "fimc-is-cmd.h"
#include "fimc-is-regs.h"
#include "fimc-is-err.h"
#include "fimc-is-video.h"

const struct v4l2_file_operations fimc_is_mxp_video_fops;
const struct v4l2_ioctl_ops fimc_is_mxp_video_ioctl_ops;
const struct vb2_ops fimc_is_mxp_qops;

int fimc_is_m0p_video_probe(void *data)
{
	int ret = 0;
	struct fimc_is_core *core;
	struct fimc_is_video *video;

	BUG_ON(!data);

	core = (struct fimc_is_core *)data;
	video = &core->video_m0p;
	video->resourcemgr = &core->resourcemgr;

	if (!core->pdev) {
		probe_err("pdev is NULL");
		ret = -EINVAL;
		goto p_err;
	}

	ret = fimc_is_video_probe(video,
		FIMC_IS_VIDEO_MXP_NAME(0),
		FIMC_IS_VIDEO_M0P_NUM,
		VFL_DIR_RX,
		&core->resourcemgr.mem,
		&core->v4l2_dev,
		&fimc_is_mxp_video_fops,
		&fimc_is_mxp_video_ioctl_ops);
	if (ret)
		dev_err(&core->pdev->dev, "%s is fail(%d)\n", __func__, ret);

p_err:
	return ret;
}

int fimc_is_m1p_video_probe(void *data)
{
	int ret = 0;
	struct fimc_is_core *core;
	struct fimc_is_video *video;

	BUG_ON(!data);

	core = (struct fimc_is_core *)data;
	video = &core->video_m1p;
	video->resourcemgr = &core->resourcemgr;

	if (!core->pdev) {
		probe_err("pdev is NULL");
		ret = -EINVAL;
		goto p_err;
	}

	ret = fimc_is_video_probe(video,
		FIMC_IS_VIDEO_MXP_NAME(1),
		FIMC_IS_VIDEO_M1P_NUM,
		VFL_DIR_RX,
		&core->resourcemgr.mem,
		&core->v4l2_dev,
		&fimc_is_mxp_video_fops,
		&fimc_is_mxp_video_ioctl_ops);
	if (ret)
		dev_err(&core->pdev->dev, "%s is fail(%d)\n", __func__, ret);

p_err:
	return ret;
}

int fimc_is_m2p_video_probe(void *data)
{
	int ret = 0;
	struct fimc_is_core *core;
	struct fimc_is_video *video;

	BUG_ON(!data);

	core = (struct fimc_is_core *)data;
	video = &core->video_m2p;
	video->resourcemgr = &core->resourcemgr;

	if (!core->pdev) {
		probe_err("pdev is NULL");
		ret = -EINVAL;
		goto p_err;
	}

	ret = fimc_is_video_probe(video,
		FIMC_IS_VIDEO_MXP_NAME(2),
		FIMC_IS_VIDEO_M2P_NUM,
		VFL_DIR_RX,
		&core->resourcemgr.mem,
		&core->v4l2_dev,
		&fimc_is_mxp_video_fops,
		&fimc_is_mxp_video_ioctl_ops);
	if (ret)
		dev_err(&core->pdev->dev, "%s is fail(%d)\n", __func__, ret);

p_err:
	return ret;
}

int fimc_is_m3p_video_probe(void *data)
{
	int ret = 0;
	struct fimc_is_core *core;
	struct fimc_is_video *video;

	BUG_ON(!data);

	core = (struct fimc_is_core *)data;
	video = &core->video_m3p;
	video->resourcemgr = &core->resourcemgr;

	if (!core->pdev) {
		probe_err("pdev is NULL");
		ret = -EINVAL;
		goto p_err;
	}

	ret = fimc_is_video_probe(video,
		FIMC_IS_VIDEO_MXP_NAME(3),
		FIMC_IS_VIDEO_M3P_NUM,
		VFL_DIR_RX,
		&core->resourcemgr.mem,
		&core->v4l2_dev,
		&fimc_is_mxp_video_fops,
		&fimc_is_mxp_video_ioctl_ops);
	if (ret)
		dev_err(&core->pdev->dev, "%s is fail(%d)\n", __func__, ret);

p_err:
	return ret;
}

int fimc_is_m4p_video_probe(void *data)
{
	int ret = 0;
	struct fimc_is_core *core;
	struct fimc_is_video *video;

	BUG_ON(!data);

	core = (struct fimc_is_core *)data;
	video = &core->video_m4p;
	video->resourcemgr = &core->resourcemgr;

	if (!core->pdev) {
		probe_err("pdev is NULL");
		ret = -EINVAL;
		goto p_err;
	}

	ret = fimc_is_video_probe(video,
		FIMC_IS_VIDEO_MXP_NAME(4),
		FIMC_IS_VIDEO_M4P_NUM,
		VFL_DIR_RX,
		&core->resourcemgr.mem,
		&core->v4l2_dev,
		&fimc_is_mxp_video_fops,
		&fimc_is_mxp_video_ioctl_ops);
	if (ret)
		dev_err(&core->pdev->dev, "%s is fail(%d)\n", __func__, ret);

p_err:
	return ret;
}

int fimc_is_m5p_video_probe(void *data)
{
	int ret = 0;
	struct fimc_is_core *core;
	struct fimc_is_video *video;

	BUG_ON(!data);

	core = (struct fimc_is_core *)data;
	video = &core->video_m5p;
	video->resourcemgr = &core->resourcemgr;

	if (!core->pdev) {
		probe_err("pdev is NULL");
		ret = -EINVAL;
		goto p_err;
	}

	ret = fimc_is_video_probe(video,
		FIMC_IS_VIDEO_MXP_NAME(5),
		FIMC_IS_VIDEO_M5P_NUM,
		VFL_DIR_RX,
		&core->resourcemgr.mem,
		&core->v4l2_dev,
		&fimc_is_mxp_video_fops,
		&fimc_is_mxp_video_ioctl_ops);
	if (ret)
		dev_err(&core->pdev->dev, "%s is fail(%d)\n", __func__, ret);

p_err:
	return ret;
}

/*
 * =============================================================================
 * Video File Opertation
 * =============================================================================
 */

static int fimc_is_mxp_video_open(struct file *file)
{
	int ret = 0;
	int ret_err = 0;
	struct fimc_is_video *video;
	struct fimc_is_video_ctx *vctx;
	struct fimc_is_device_ischain *device;
	struct fimc_is_resourcemgr *resourcemgr;
	char name[FIMC_IS_STR_LEN];

	vctx = NULL;
	device = NULL;
	video = video_drvdata(file);
	resourcemgr = video->resourcemgr;
	if (!resourcemgr) {
		err("resourcemgr is NULL");
		ret = -EINVAL;
		goto err_resource_null;
	}

	ret = fimc_is_resource_open(resourcemgr, RESOURCE_TYPE_ISCHAIN, (void **)&device);
	if (ret) {
		err("fimc_is_resource_open is fail(%d)", ret);
		goto err_resource_open;
	}

	if (!device) {
		err("device is NULL");
		ret = -EINVAL;
		goto err_device_null;
	}

	minfo("[M%dP:V] %s\n", device, GET_MXP_ID(video), __func__);

	snprintf(name, sizeof(name), "M%dP", GET_MXP_ID(video));
	ret = open_vctx(file, video, &vctx, device->instance, FRAMEMGR_ID_M0P << GET_MXP_ID(video), name);
	if (ret) {
		merr("open_vctx is fail(%d)", device, ret);
		goto err_vctx_open;
	}

	ret = fimc_is_video_open(vctx,
		device,
		VIDEO_MXP_READY_BUFFERS,
		video,
		&fimc_is_mxp_qops,
		&fimc_is_ischain_subdev_ops);
	if (ret) {
		merr("fimc_is_video_open is fail(%d)", device, ret);
		goto err_video_open;
	}

	ret = fimc_is_ischain_subdev_open(device, vctx);
	if (ret) {
		merr("fimc_is_ischain_subdev_open is fail(%d)", device, ret);
		goto err_ischain_open;
	}

	return 0;

err_ischain_open:
	ret_err = fimc_is_video_close(vctx);
	if (ret_err)
		merr("fimc_is_video_close is fail(%d)", device, ret_err);
err_video_open:
	ret_err = close_vctx(file, video, vctx);
	if (ret_err < 0)
		merr("close_vctx is fail(%d)", device, ret_err);
err_vctx_open:
err_device_null:
err_resource_open:
err_resource_null:
	return ret;
}

static int fimc_is_mxp_video_close(struct file *file)
{
	int ret = 0;
	int refcount;
	struct fimc_is_video_ctx *vctx = file->private_data;
	struct fimc_is_video *video;
	struct fimc_is_device_ischain *device;

	BUG_ON(!file);
	BUG_ON(!vctx);
	BUG_ON(!GET_VIDEO(vctx));
	BUG_ON(!GET_DEVICE(vctx));

	video = GET_VIDEO(vctx);
	device = GET_DEVICE(vctx);

	ret = fimc_is_ischain_subdev_close(device, vctx);
	if (ret)
		merr("fimc_is_ischain_subdev_close is fail(%d)", device, ret);

	ret = fimc_is_video_close(vctx);
	if (ret)
		merr("fimc_is_video_close is fail(%d)", device, ret);

	refcount = close_vctx(file, video, vctx);
	if (refcount < 0)
		merr("close_vctx is fail(%d)", device, refcount);

	minfo("[M%dP:V] %s(%d,%d):%d\n", device, GET_MXP_ID(video), __func__, atomic_read(&device->open_cnt), refcount, ret);

	return ret;
}

static unsigned int fimc_is_mxp_video_poll(struct file *file,
	struct poll_table_struct *wait)
{
	u32 ret = 0;
	struct fimc_is_video_ctx *vctx = file->private_data;

	ret = fimc_is_video_poll(file, vctx, wait);

	return ret;
}

static int fimc_is_mxp_video_mmap(struct file *file,
	struct vm_area_struct *vma)
{
	int ret = 0;
	struct fimc_is_video_ctx *vctx = file->private_data;

	ret = fimc_is_video_mmap(file, vctx, vma);
	if (ret)
		merr("fimc_is_video_mmap is fail(%d)", vctx, ret);

	return ret;
}

const struct v4l2_file_operations fimc_is_mxp_video_fops = {
	.owner		= THIS_MODULE,
	.open		= fimc_is_mxp_video_open,
	.release	= fimc_is_mxp_video_close,
	.poll		= fimc_is_mxp_video_poll,
	.unlocked_ioctl	= video_ioctl2,
	.mmap		= fimc_is_mxp_video_mmap,
};

/*
 * =============================================================================
 * Video Ioctl Opertation
 * =============================================================================
 */

static int fimc_is_mxp_video_querycap(struct file *file, void *fh,
	struct v4l2_capability *cap)
{
	struct fimc_is_video *video = video_drvdata(file);

	BUG_ON(!cap);
	BUG_ON(!video);

	snprintf(cap->driver, sizeof(cap->driver), "%s", video->vd.name);
	snprintf(cap->card, sizeof(cap->card), "%s", video->vd.name);
	cap->capabilities |= V4L2_CAP_STREAMING
			| V4L2_CAP_VIDEO_CAPTURE
			| V4L2_CAP_VIDEO_CAPTURE_MPLANE;
	cap->device_caps |= cap->capabilities;

	return 0;
}

static int fimc_is_mxp_video_enum_fmt_mplane(struct file *file, void *priv,
	struct v4l2_fmtdesc *f)
{
	dbg("%s\n", __func__);
	return 0;
}

static int fimc_is_mxp_video_get_format_mplane(struct file *file, void *fh,
	struct v4l2_format *format)
{
	dbg("%s\n", __func__);
	return 0;
}

static int fimc_is_mxp_video_set_format_mplane(struct file *file, void *fh,
	struct v4l2_format *format)
{
		int ret = 0;
	struct fimc_is_video_ctx *vctx = file->private_data;

	BUG_ON(!vctx);
	BUG_ON(!format);

	mdbgv_mxp("%s\n", vctx, __func__);

	ret = fimc_is_video_set_format_mplane(file, vctx, format);
	if (ret) {
		merr("fimc_is_video_set_format_mplane is fail(%d)", vctx, ret);
		goto p_err;
	}

p_err:
	return ret;
}

static int fimc_is_mxp_video_try_format_mplane(struct file *file, void *fh,
	struct v4l2_format *format)
{
	dbg("%s\n", __func__);
	return 0;
}

static int fimc_is_mxp_video_cropcap(struct file *file, void *fh,
	struct v4l2_cropcap *cropcap)
{
	dbg("%s\n", __func__);
	return 0;
}

static int fimc_is_mxp_video_get_crop(struct file *file, void *fh,
	struct v4l2_crop *crop)
{
	dbg("%s\n", __func__);
	return 0;
}

static int fimc_is_mxp_video_set_crop(struct file *file, void *fh,
	const struct v4l2_crop *crop)
{
	dbg("%s\n", __func__);
	return 0;
}

static int fimc_is_mxp_video_reqbufs(struct file *file, void *priv,
	struct v4l2_requestbuffers *buf)
{
	int ret = 0;
	struct fimc_is_video_ctx *vctx = file->private_data;
	struct fimc_is_device_ischain *device;
	struct fimc_is_subdev *leader, *subdev;

	BUG_ON(!vctx);
	BUG_ON(!GET_DEVICE(vctx));
	BUG_ON(!GET_VIDEO(vctx));

	mdbgv_mxp("%s(buffers : %d)\n", vctx, __func__, buf->count);

	device = GET_DEVICE(vctx);
	subdev = vctx->subdev;
	leader = subdev->leader;
	if (leader && test_bit(FIMC_IS_SUBDEV_START, &leader->state)) {
		err("leader%d still running, subdev%d req is not applied", leader->id, subdev->id);
		ret = -EINVAL;
		goto p_err;
	}

	ret = fimc_is_video_reqbufs(file, vctx, buf);
	if (ret) {
		merr("fimc_is_video_reqbufs is fail(%d)", device, ret);
		goto p_err;
	}

 p_err:
	return ret;
}

static int fimc_is_mxp_video_querybuf(struct file *file, void *priv,
	struct v4l2_buffer *buf)
{
	int ret;
	struct fimc_is_video_ctx *vctx = file->private_data;

	mdbgv_mxp("%s\n", vctx, __func__);

	ret = fimc_is_video_querybuf(file, vctx, buf);
	if (ret)
		merr("fimc_is_video_querybuf is fail(%d)", vctx, ret);

	return ret;
}

static int fimc_is_mxp_video_qbuf(struct file *file, void *priv,
	struct v4l2_buffer *buf)
{
	int ret = 0;
	struct fimc_is_video_ctx *vctx = file->private_data;

	mvdbgs(3, "%s(index : %d)\n", vctx, &vctx->queue, __func__, buf->index);

	ret = CALL_VOPS(vctx, qbuf, buf);

	if (ret)
		merr("qbuf is fail(%d)", vctx, ret);

	return ret;
}

static int fimc_is_mxp_video_dqbuf(struct file *file, void *priv,
	struct v4l2_buffer *buf)
{
	int ret = 0;
	struct fimc_is_video_ctx *vctx = file->private_data;
	bool blocking = file->f_flags & O_NONBLOCK;

	mvdbgs(3, "%s\n", vctx, &vctx->queue, __func__);

	ret = CALL_VOPS(vctx, dqbuf, buf, blocking);
	if (ret)
		merr("dqbuf is fail(%d)", vctx, ret);

	/* hwfc reset during dqbuf timing */
	fimc_is_hw_s_ctrl(vctx, vctx->video->id, HW_S_CTRL_HWFC_IDX_RESET, (void *)1);

	return ret;
}

static int fimc_is_mxp_video_streamon(struct file *file, void *priv,
	enum v4l2_buf_type type)
{
	int ret = 0;
	struct fimc_is_video_ctx *vctx = file->private_data;

	mdbgv_mxp("%s\n", vctx, __func__);

	ret = fimc_is_video_streamon(file, vctx, type);
	if (ret)
		merr("fimc_is_video_streamon is fail(%d)", vctx, ret);

	return ret;
}

static int fimc_is_mxp_video_streamoff(struct file *file, void *priv,
	enum v4l2_buf_type type)
{
	int ret = 0;
	struct fimc_is_video_ctx *vctx = file->private_data;

	mdbgv_mxp("%s\n", vctx, __func__);

	ret = fimc_is_video_streamoff(file, vctx, type);
	if (ret)
		merr("fimc_is_video_streamoff is fail(%d)", vctx, ret);

	return ret;
}

static int fimc_is_mxp_video_enum_input(struct file *file, void *priv,
	struct v4l2_input *input)
{
	/* Todo: add enum input control code */
	return 0;
}

static int fimc_is_mxp_video_g_input(struct file *file, void *priv,
	unsigned int *input)
{
	dbg("%s\n", __func__);
	return 0;
}

static int fimc_is_mxp_video_s_input(struct file *file, void *priv,
	unsigned int input)
{
	int ret = 0;
	struct fimc_is_video_ctx *vctx = file->private_data;

	BUG_ON(!vctx);

	ret = fimc_is_video_s_input(file, vctx);
	if (ret) {
		merr("fimc_is_video_s_input is fail(%d)", vctx, ret);
		goto p_err;
	}

p_err:
	return ret;
}

static int fimc_is_mxp_video_g_ctrl(struct file *file, void *priv,
	struct v4l2_control *ctrl)
{
	int ret = 0;
	struct fimc_is_video_ctx *vctx = file->private_data;
	struct fimc_is_framemgr *framemgr;

	BUG_ON(!vctx);
	BUG_ON(!ctrl);

	mdbgv_mxp("%s\n", vctx, __func__);

	framemgr = GET_FRAMEMGR(vctx);

	switch (ctrl->id) {
	case V4L2_CID_IS_G_COMPLETES:
		ctrl->value = framemgr->queued_count[FS_COMPLETE];
		break;
	default:
		err("unsupported ioctl(%d)\n", ctrl->id);
		ret = -EINVAL;
		break;
	}

	return ret;
}

static int fimc_is_mxp_video_g_ext_ctrl(struct file *file, void *priv,
	struct v4l2_ext_controls *ctrls)
{
	return 0;
}

static int fimc_is_mxp_video_s_ctrl(struct file *file, void *priv,
	struct v4l2_control *ctrl)
{
	int ret = 0;
	struct fimc_is_video_ctx *vctx = file->private_data;

	BUG_ON(!vctx);
	BUG_ON(!ctrl);

	mdbgv_mxp("%s\n", vctx, __func__);

	switch (ctrl->id) {
	default:
		ret = fimc_is_video_s_ctrl(file, vctx, ctrl);
		if (ret) {
			err("fimc_is_video_s_ctrl is fail(%d)", ret);
			goto p_err;
		}
		break;
	}

p_err:
	return ret;
}

const struct v4l2_ioctl_ops fimc_is_mxp_video_ioctl_ops = {
	.vidioc_querycap		= fimc_is_mxp_video_querycap,
	.vidioc_enum_fmt_vid_cap_mplane	= fimc_is_mxp_video_enum_fmt_mplane,
	.vidioc_g_fmt_vid_cap_mplane	= fimc_is_mxp_video_get_format_mplane,
	.vidioc_s_fmt_vid_cap_mplane	= fimc_is_mxp_video_set_format_mplane,
	.vidioc_try_fmt_vid_cap_mplane	= fimc_is_mxp_video_try_format_mplane,
	.vidioc_cropcap			= fimc_is_mxp_video_cropcap,
	.vidioc_g_crop			= fimc_is_mxp_video_get_crop,
	.vidioc_s_crop			= fimc_is_mxp_video_set_crop,
	.vidioc_reqbufs			= fimc_is_mxp_video_reqbufs,
	.vidioc_querybuf		= fimc_is_mxp_video_querybuf,
	.vidioc_qbuf			= fimc_is_mxp_video_qbuf,
	.vidioc_dqbuf			= fimc_is_mxp_video_dqbuf,
	.vidioc_streamon		= fimc_is_mxp_video_streamon,
	.vidioc_streamoff		= fimc_is_mxp_video_streamoff,
	.vidioc_enum_input		= fimc_is_mxp_video_enum_input,
	.vidioc_g_input			= fimc_is_mxp_video_g_input,
	.vidioc_s_input			= fimc_is_mxp_video_s_input,
	.vidioc_g_ctrl			= fimc_is_mxp_video_g_ctrl,
	.vidioc_s_ctrl			= fimc_is_mxp_video_s_ctrl,
	.vidioc_g_ext_ctrls		= fimc_is_mxp_video_g_ext_ctrl,
};

static int fimc_is_mxp_queue_setup(struct vb2_queue *vbq,
	const void *parg,
	unsigned int *num_buffers,
	unsigned int *num_planes,
	unsigned int sizes[],
	void *allocators[])
{
	int ret = 0;
	struct fimc_is_video_ctx *vctx = vbq->drv_priv;
	struct fimc_is_video *video;
	struct fimc_is_queue *queue;

	BUG_ON(!vctx);
	BUG_ON(!vctx->video);

	mdbgv_mxp("%s\n", vctx, __func__);

	video = GET_VIDEO(vctx);
	queue = GET_QUEUE(vctx);

	ret = fimc_is_queue_setup(queue,
		video->alloc_ctx,
		num_planes,
		sizes,
		allocators);
	if (ret)
		merr("fimc_is_queue_setup is fail(%d)", vctx, ret);

	return ret;
}

static int fimc_is_mxp_buffer_prepare(struct vb2_buffer *vb)
{
	return fimc_is_queue_prepare(vb);
}

static inline void fimc_is_mxp_wait_prepare(struct vb2_queue *vbq)
{
	fimc_is_queue_wait_prepare(vbq);
}

static inline void fimc_is_mxp_wait_finish(struct vb2_queue *vbq)
{
	fimc_is_queue_wait_finish(vbq);
}

static int fimc_is_mxp_start_streaming(struct vb2_queue *vbq,
	unsigned int count)
{
	int ret = 0;
	struct fimc_is_video_ctx *vctx = vbq->drv_priv;
	struct fimc_is_queue *queue;
	struct fimc_is_device_ischain *device;

	BUG_ON(!vctx);
	BUG_ON(!GET_DEVICE(vctx));

	mdbgv_mxp("%s\n", vctx, __func__);

	device = GET_DEVICE(vctx);
	queue = GET_QUEUE(vctx);

	ret = fimc_is_queue_start_streaming(queue, device);
	if (ret) {
		merr("fimc_is_queue_start_streaming is fail(%d)", device, ret);
		goto p_err;
	}

p_err:
	return ret;
}

static void fimc_is_mxp_stop_streaming(struct vb2_queue *vbq)
{
	int ret = 0;
	struct fimc_is_video_ctx *vctx = vbq->drv_priv;
	struct fimc_is_queue *queue;
	struct fimc_is_device_ischain *device;

	BUG_ON(!vctx);
	BUG_ON(!GET_DEVICE(vctx));

	mdbgv_mxp("%s\n", vctx, __func__);

	device = GET_DEVICE(vctx);
	queue = GET_QUEUE(vctx);

	ret = fimc_is_queue_stop_streaming(queue, device);
	if (ret) {
		merr("fimc_is_queue_stop_streaming is fail(%d)", device, ret);
		return;
	}
}

static void fimc_is_mxp_buffer_queue(struct vb2_buffer *vb)
{
	int ret = 0;
	struct fimc_is_video_ctx *vctx = vb->vb2_queue->drv_priv;
	struct fimc_is_queue *queue;
	struct fimc_is_video *video;
	struct fimc_is_device_ischain *device;
	struct fimc_is_subdev *subdev;

	BUG_ON(!vctx);
	BUG_ON(!GET_DEVICE(vctx));
	BUG_ON(!GET_VIDEO(vctx));

	mvdbgs(3, "%s(%d)\n", vctx, &vctx->queue, __func__, vb->index);

	device = GET_DEVICE(vctx);
	video = GET_VIDEO(vctx);
	queue = GET_QUEUE(vctx);
	subdev = vctx->subdev;

	ret = fimc_is_queue_buffer_queue(queue, vb);
	if (ret) {
		merr("fimc_is_queue_buffer_queue is fail(%d)", device, ret);
		return;
	}

	ret = fimc_is_subdev_buffer_queue(subdev, vb);
	if (ret) {
		merr("fimc_is_subdev_buffer_queue is fail(%d)", device, ret);
		return;
	}
}

static void fimc_is_mxp_buffer_finish(struct vb2_buffer *vb)
{
	int ret = 0;
	struct fimc_is_video_ctx *vctx = vb->vb2_queue->drv_priv;
	struct fimc_is_device_ischain *device;
	struct fimc_is_subdev *subdev;

	BUG_ON(!vctx);
	BUG_ON(!GET_DEVICE(vctx));

	mvdbgs(3, "%s(%d)\n", vctx, &vctx->queue, __func__, vb->index);

	device = GET_DEVICE(vctx);
	subdev = vctx->subdev;

	ret = fimc_is_subdev_buffer_finish(subdev, vb);
	if (ret) {
		merr("fimc_is_subdev_buffer_finish is fail(%d)", device, ret);
		return;
	}
}

const struct vb2_ops fimc_is_mxp_qops = {
	.queue_setup		= fimc_is_mxp_queue_setup,
	.buf_init		= fimc_is_buffer_init,
	.buf_prepare		= fimc_is_mxp_buffer_prepare,
	.buf_queue		= fimc_is_mxp_buffer_queue,
	.buf_finish		= fimc_is_mxp_buffer_finish,
	.wait_prepare		= fimc_is_mxp_wait_prepare,
	.wait_finish		= fimc_is_mxp_wait_finish,
	.start_streaming	= fimc_is_mxp_start_streaming,
	.stop_streaming		= fimc_is_mxp_stop_streaming,
};