/* $Id: d_mos6.model,v 26.133 2009/11/26 04:58:04 al Exp $ -*- C++ -*-
 * Copyright (C) 2001 Albert Davis
 * Author: Albert Davis <aldavis@gnu.org>
 *
 * This file is part of "Gnucap", the Gnu Circuit Analysis Package
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *------------------------------------------------------------------
 * mos model equations: spice level 6 equivalent
 */
/* This file is automatically generated. DO NOT EDIT */
#ifndef D_MOS6_H_INCLUDED
#define D_MOS6_H_INCLUDED

#include "d_mos123.h"
#include "u_sdp.h"
#include "e_node.h"
#include "e_subckt.h"
#include "e_model.h"
/*--------------------------------------------------------------------------*/
class SDP_BUILT_IN_MOS6
  :public SDP_BUILT_IN_MOS123{
public:
  explicit SDP_BUILT_IN_MOS6(const COMMON_COMPONENT* c) : SDP_BUILT_IN_MOS123(c) {init(c);}
  void init(const COMMON_COMPONENT*);
public:
};
/*--------------------------------------------------------------------------*/
class DEV_BUILT_IN_MOS;
class TDP_BUILT_IN_MOS6
  :public TDP_BUILT_IN_MOS123{
public:
  explicit TDP_BUILT_IN_MOS6(const DEV_BUILT_IN_MOS*);
public:
  double phi;	// 
  double beta;	// 
  double vbi;	// 
};
/*--------------------------------------------------------------------------*/
class MODEL_BUILT_IN_MOS6
  :public MODEL_BUILT_IN_MOS123{
protected:
  explicit MODEL_BUILT_IN_MOS6(const MODEL_BUILT_IN_MOS6& p);
public:
  explicit MODEL_BUILT_IN_MOS6(const BASE_SUBCKT*);
  ~MODEL_BUILT_IN_MOS6() {--_count;}
public: // override virtual
  std::string dev_type()const;
  void      set_dev_type(const std::string& nt);
  CARD*     clone()const {return new MODEL_BUILT_IN_MOS6(*this);}
  void      precalc_first();
  void      precalc_last();
  SDP_CARD* new_sdp(COMMON_COMPONENT* c)const;
  void      set_param_by_index(int, std::string&, int);
  bool      param_is_printable(int)const;
  std::string param_name(int)const;
  std::string param_name(int,int)const;
  std::string param_value(int)const;
  int param_count()const {return (18 + MODEL_BUILT_IN_MOS123::param_count());}
  bool      is_valid(const COMPONENT*)const;
  void      tr_eval(COMPONENT*)const;
public: // not virtual
  static int count() {return _count;}
private: // strictly internal
  static int _count;
public: // input parameters
  PARAMETER<double> kv;	// Saturation voltage factor
  PARAMETER<double> nv;	// Saturation voltage coeff.
  PARAMETER<double> kc;	// Saturation current factor
  PARAMETER<double> nc;	// Saturation current coeff.
  PARAMETER<double> nvth;	// Threshold voltage coeff.
  PARAMETER<double> ps;	// Sat. current modification  par.
  PARAMETER<double> gamma1;	// Bulk threshold parameter 1
  PARAMETER<double> sigma;	// Static feedback effect par.
  PARAMETER<double> lambda0;	// Channel length modulation param
  PARAMETER<double> lambda1;	// Channel length modulation param. 1
public: // calculated parameters
  bool calc_kc;	// 
};
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
#endif
