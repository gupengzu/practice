#include "basisWidget.h"

basisWidget::basisWidget(int x, int y, int w, int h)
    :m_x(x), m_y(y), m_w(w), m_h(h)
{
}

int basisWidget::width()
{
    return m_w;
}

int basisWidget::height()
{
    return m_h;
}

void basisWidget::setFixedSize(int w, int h)
{
    this->m_w = w;
    this->m_h = h;
}

int basisWidget::x()
{
    return m_x;
}

int basisWidget::y()
{
    return m_y;
}

void basisWidget::move(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}
