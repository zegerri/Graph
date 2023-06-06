#include "MyCurve.h"

double MyCurve::compute_length(int pos)
{
    double result = 0.0;
    auto ps = m_lines.begin() + pos;
    if (ps->size() < 2) {
        // 如果 m_lines[pos] 的大小小于2，则不是曲线，返回 0
        return result;
    }

    // 计算曲线的长度
    for (auto p = ps->begin(); p != (ps->end() - 1); p++)
    {
        double step = 0.1;
        for (double t = 0; t <= 1; t += step) {
            double x0 = p->point.x();
            double y0 = p->point.y();
            double x1 = (p + 1)->point.x();
            double y1 = (p + 1)->point.y();
            double x = x0 * pow(1 - t, 3) + 3 * t * x1 * pow(1 - t, 2) + 3 * pow(t, 2) * (1 - t) * x1 + pow(t, 3) * (p + 2)->point.x();
            double y = y0 * pow(1 - t, 3) + 3 * t * y1 * pow(1 - t, 2) + 3 * pow(t, 2) * (1 - t) * y1 + pow(t, 3) * (p + 2)->point.y();
            double dx = x - p->point.x();
            double dy = y - p->point.y();
            result += sqrt(dx * dx + dy * dy);
            if (t + step > 1 && (p + 2) == ps->end()) {
                dx = (p + 1)->point.x() - x;
                dy = (p + 1)->point.y() - y;
                result += sqrt(dx * dx + dy * dy);
            }
        }
    }

    return result;
}