#pragma once

#include "visitor.h"

class Painter : public Visitor
{
    public:
    Painter();
    

    void process_circle(Circle*);
    void process_rect(Rect*);
    void process_group(Group*);


    private:
    double total_offset_x, total_offset_y;

};