/**
 * @file src/python/ip/src/gaussian.cc
 * @author <a href="mailto:Nikls.Johansson@idiap.ch">Niklas Johansson</a> 
 * @date Thu 17 Mar 19:12:40 2011 
 *
 * @brief Binds Gaussian smoothing to python
 */

#include <boost/python.hpp>
#include <vector>
#include "ip/Gaussian.h"

using namespace boost::python;
namespace ip = Torch::ip;

static const char* gaussiandoc = "Performs gaussian smoothing";

void bind_ip_gaussian() {
	class_<ip::Gaussian, boost::shared_ptr<ip::Gaussian> >("Gaussian", gaussiandoc, init<optional<const int, const int, const double, const double> >((arg("radius_y")=1, arg("radius_x")=1, arg("sigma_y")=5., arg("sigma_x")=5.), "Creates a gaussian smoother"))
		.def("__call__", (void (ip::Gaussian::*)(const blitz::Array<uint8_t,2>&, blitz::Array<double,2>&))&ip::Gaussian::operator()<uint8_t>, (arg("self"), arg("src"), arg("dst")), "Smooth an image")
		.def("__call__", (void (ip::Gaussian::*)(const blitz::Array<uint16_t,2>&, blitz::Array<double,2>&))&ip::Gaussian::operator()<uint16_t>, (arg("self"), arg("src"), arg("dst")), "Smooth an image")
		.def("__call__", (void (ip::Gaussian::*)(const blitz::Array<double,2>&, blitz::Array<double,2>&))&ip::Gaussian::operator()<double>, (arg("self"), arg("src"), arg("dst")), "Smooth an image")
		;
}
