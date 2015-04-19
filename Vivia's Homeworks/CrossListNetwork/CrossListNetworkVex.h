#ifndef __CROSS_LIST_NETWORK_VEX_H__
#define __CROSS_LIST_NETWORK_VEX_H__
template <class ElemType, class WeightType>
struct CrossListNetworkVex
{
	ElemType data;
	CrossListNetworkArc<WeightType> *first_in_arc;
	CrossListNetworkArc<WeightType> *first_out_arc;
	CrossListNetworkVex();
	CrossListNetworkVex(ElemType val,
						CrossListNetworkArc<WeightType> *first_in = NULL,
						CrossListNetworkArc<WeightType> *first_out = NULL);
};

template <class ElemType, class WeightType>
CrossListNetworkVex<ElemType, WeightType>::CrossListNetworkVex()
{
	first_in_arc = NULL;
	first_out_arc = NULL;
}

template <class ElemType, class WeightType>
CrossListNetworkVex<ElemType, WeightType>::CrossListNetworkVex(ElemType val,
																CrossListNetworkArc<WeightType> *first_in,
																CrossListNetworkArc<WeightType> *first_out)
{
	data = val;
	first_in_arc = first_in;
	first_out_arc = first_out;
}
#endif
