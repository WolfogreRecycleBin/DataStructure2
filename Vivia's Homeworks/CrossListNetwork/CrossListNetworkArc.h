#ifndef __CROSS_LIST_NETWORK_ARC_H__
#define __CROSS_LIST_NETWORK_ARC_H__

#include "Assistance.h"

template <class WeightType>
struct CrossListNetworkArc
{
	mutable Status arc_tag;
	WeightType weight;
	int tail_vex;
	CrossListNetworkArc<WeightType> *tail_next_arc;
	int head_vex;
	CrossListNetworkArc<WeightType> *head_next_arc;

	CrossListNetworkArc();
	CrossListNetworkArc(int tail_v,
						int head_v,
						WeightType w,
						CrossListNetworkArc<WeightType> *tail_next = NULL,
						CrossListNetworkArc<WeightType> *head_next = NULL);
};

template <class WeightType>
CrossListNetworkArc<WeightType>::CrossListNetworkArc()
{
	arc_tag = UNVISITED;
	tail_vex = head_vex = -1;
	tail_next_arc = head_next_arc = NULL;
}

template <class WeightType>
CrossListNetworkArc<WeightType>::CrossListNetworkArc(int tail_v,
													int head_v,
													WeightType w,
													CrossListNetworkArc<WeightType> *tail_next,
													CrossListNetworkArc<WeightType> *head_next)
{
	arc_tag = UNVISITED;
	tail_vex = tail_v;
	head_vex = head_v;
	weight = w;
    tail_next_arc = tail_next;
    head_next_arc = head_next;
}
#endif
