#ifndef _LAYOUTSTRATEGY_
#define _LAYOUTSTRATEGY_

#include <vector>
#include "Geometry.h"

class LayoutStrategy {
  public:
    virtual ~LayoutStrategy() = 0;

    virtual void unfocus() = 0;
    virtual void focus(const Point &p) = 0;

    virtual int widgetAt(const Point &x) const = 0;
    virtual bool atHoverZone(const Point &x) const = 0;

    virtual Size frameSize() const = 0;
};


class WaveLayout : public LayoutStrategy {
  public:

    WaveLayout(size_t num_widgets, size_t widget_size = 32,
               size_t num_anim = 3, float zoom_factor = 1.8,
               float jump_factor = 1.0);

    void unfocus();
    void focus(const Point &p);

    int widgetAt(const Point &x) const;
    bool atHoverZone(const Point &x) const;

    const Rect & widgetLayout(size_t idx) const;
    const Rect & dockLayout() const;

    Size frameSize() const;

  private:
    size_t widget_size;
    size_t widget_dist;
    size_t num_animated;
    float zoom_factor;
    float jump_factor;

    size_t widget_unit() const;
    float scaled_unit() const;
    size_t side_num_anim() const;
    size_t widget_offset() const;

    size_t bar_x() const;
    size_t bar_y() const;
    size_t bar_width() const;
    size_t bar_height() const;

    float _upgrowth() const;
    float _dngrowth() const;

    std::vector<Point> position;
    std::vector<Rect> bounds;
};


class CoverflowLayout : public LayoutStrategy {
};

#endif /* _LAYOUTSTRATEGY_ */

/* vim: set sw=2 sts=2 : */
