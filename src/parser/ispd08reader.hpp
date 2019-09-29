/**
 * @file   ispd08reader.hpp
 * @brief  ISPD08-like netlist format parser
 * @author Hao Chen
 * @date   09/22/2019
 *
 **/

#ifndef _ISPD08_READER_HPP_
#define _ISPD08_READER_HPP_

#include "src/global/global.hpp"
#include "src/db/dbCir.hpp"

PROJECT_NAMESPACE_START

class Ispd08Reader {
 public:
  Ispd08Reader(CirDB& c)
    : _cir(c), _scale(0) {}
  ~Ispd08Reader() {}
    
  void parse(const String_t& filename);
 private:
  CirDB&  _cir;
  Int_t   _scale; 
  Vector_t<Index_t> _vIdx2RoutingLayerIdx;
  /////////////////////////////////////////
  //    Private functions                //
  /////////////////////////////////////////
  void      setScale();
  void      buildLayerMap();
  Index_t   map2RoutingLayer(const Index_t i);
  /////////////////////////////////////////
  //    Helper functions                 //
  /////////////////////////////////////////
  Int_t to_db_unit(const Int_t n) const;

};

PROJECT_NAMESPACE_END

#endif /// _ISPD08_READER_HPP_
