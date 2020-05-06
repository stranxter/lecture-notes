#pragma once

#include "figure.h"
#include "rect.h"
#include "circle.h"
#include "group.h"

class Visitor
{
    public:
    virtual void process_circle(Circle*)=0;
    virtual void process_rect(Rect*)=0;
    virtual void process_group(Group*)=0;

};