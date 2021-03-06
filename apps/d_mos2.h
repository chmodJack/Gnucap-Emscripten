/* $Id: d_mos2.model,v 26.133 2009/11/26 04:58:04 al Exp $ -*- C++ -*-
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
 * mos model equations: spice level 2 equivalent
 */
/* This file is automatically generated. DO NOT EDIT */
#ifndef D_MOS2_H_INCLUDED
#define D_MOS2_H_INCLUDED

#include "d_mos123.h"
#include "u_sdp.h"
#include "e_node.h"
#include "e_subckt.h"
#include "e_model.h"
/*--------------------------------------------------------------------------*/
class SDP_BUILT_IN_MOS2
  :public SDP_BUILT_IN_MOS123{
public:
  explicit SDP_BUILT_IN_MOS2(const COMMON_COMPONENT* c) : SDP_BUILT_IN_MOS123(c) {init(c);}
  void init(const COMMON_COMPONENT*);
public:
  double relxj;	// 
  double eta_1;	// 
  double eta;	// 
  double eta_2;	// 
};
/*--------------------------------------------------------------------------*/
class DEV_BUILT_IN_MOS;
class TDP_BUILT_IN_MOS2
  :public TDP_BUILT_IN_MOS123{
public:
  explicit TDP_BUILT_IN_MOS2(const DEV_BUILT_IN_MOS*);
public:
  double vt;	// 
  double phi;	// 
  double sqrt_phi;	// 
  double phi_sqrt_phi;	// 
  double beta;	// 
  double uo;	// 
  double vbi;	// 
};
/*--------------------------------------------------------------------------*/
class MODEL_BUILT_IN_MOS2
  :public MODEL_BUILT_IN_MOS123{
protected:
  explicit MODEL_BUILT_IN_MOS2(const MODEL_BUILT_IN_MOS2& p);
public:
  explicit MODEL_BUILT_IN_MOS2(const BASE_SUBCKT*);
  ~MODEL_BUILT_IN_MOS2() {--_count;}
public: // override virtual
  std::string dev_type()const;
  void      set_dev_type(const std::string& nt);
  CARD*     clone()const {return new MODEL_BUILT_IN_MOS2(*this);}
  void      precalc_first();
  void      precalc_last();
  SDP_CARD* new_sdp(COMMON_COMPONENT* c)const;
  void      set_param_by_index(int, std::string&, int);
  bool      param_is_printable(int)const;
  std::string param_name(int)const;
  std::string param_name(int,int)const;
  std::string param_value(int)const;
  int param_count()const {return (16 + MODEL_BUILT_IN_MOS123::param_count());}
  bool      is_valid(const COMPONENT*)const;
  void      tr_eval(COMPONENT*)const;
public: // not virtual
  static int count() {return _count;}
private: // strictly internal
  static int _count;
public: // input parameters
  PARAMETER<double> kp;	// transconductance parameter
  PARAMETER<double> nfs_cm;	// fast surface state density
  PARAMETER<double> vmax;	// max drift velocity of carriers
  PARAMETER<double> neff;	// total channel charge coefficient
  PARAMETER<double> ucrit_cm;	// critical field mobility degradation
  PARAMETER<double> uexp;	// critical field exponent in mob.deg.
  PARAMETER<double> utra;	// transverse field coefficient (not used)
  PARAMETER<double> delta;	// width effect on threshold voltage
public: // calculated parameters
  double nfs;	// 
  double ucrit;	// 
  bool calc_kp;	// 
  double alpha;	// 
  double xd;	// coeffDepLayWidth
  double xwb;	// 
  double vbp;	// 
  double cfsox;	// 
};
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
#endif
