#pragma once


template <typename TYPE>
TYPE map_value(TYPE value, TYPE in_min, TYPE in_max, TYPE out_min, TYPE out_max) {
    
    double range_in = (double)(in_max) - (double)(in_min);
    double range_out = (double)(out_max) - (double)(out_min);
    double shifted = ((double)(value) - (double)(in_min));

    double normalized = shifted / range_in;
    double mapped = normalized * range_out + (double)(out_min);

    return (TYPE)(mapped);
}