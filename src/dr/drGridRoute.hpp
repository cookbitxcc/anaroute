/**
 * @file   drGridRoute.hpp
 * @brief  Detailed Routing - Grid Based Routing
 * @author Hao Chen
 * @date   02/01/2020
 *
 **/

#ifndef _DR_GRID_ROUTE_HPP_
#define _DR_GRID_ROUTE_HPP_

#include "drMgr.hpp"
#include "src/geo/spatial.hpp"
#include "src/ds/pqueue.hpp"

PROJECT_NAMESPACE_START

class DrGridRoute {
  friend class DrGridAstar;
 public:
  DrGridRoute(CirDB& c, DrMgr& dr, DrcMgr& drc)
    : _cir(c), _drMgr(dr), _drc(drc),
      _vSpatialHistoryMaps(c.lef().numLayers()) {}
  ~DrGridRoute() {}

  void solve();

 private:
  CirDB&    _cir;
  DrMgr&    _drMgr;
  DrcMgr&   _drc;
  
  Vector_t<SpatialMap<Int_t, Int_t>> _vSpatialHistoryMaps;

  /////////////////////////////////////////
  //    Private structs                  //
  /////////////////////////////////////////
  struct Net_Cmp {
    bool operator() (const Net* pn1, const Net* pn2) {
      //Int_t c1 = pinWeight      * pn1->numPins() +
                 //symWeight      * pn1->hasSymNet() +
                 //selfSymWeight  * pn1->bSelfSym() +
                 //failWeight     * pn1->drFailCnt() +
                 //PGWeight       * pn1->bPowerGround();
      //Int_t c2 = pinWeight      * pn2->numPins() +
                 //symWeight      * pn2->hasSymNet() +
                 //selfSymWeight  * pn2->bSelfSym() +
                 //failWeight     * pn2->drFailCnt() +
                 //PGWeight       * pn2->bPowerGround();
      //return c1 < c2;
      if (pn1->bPowerGround() != pn2->bPowerGround()) {
        return pn1->bPowerGround() > pn2->bPowerGround();
      }
      else if (pn1->bSelfSym() != pn2->bSelfSym()) {
        return pn1->bSelfSym() < pn2->bSelfSym();
      }
      else if (pn1->hasSymNet() != pn2->hasSymNet()) {
        return pn1->hasSymNet() < pn2->hasSymNet();
      }
      else if (pn1->bbox().hpwl() != pn2->bbox().hpwl()) {
        return pn1->bbox().hpwl() > pn2->bbox().hpwl();
      }
      else if (pn1->drFailCnt() != pn2->drFailCnt()) {
        return pn1->drFailCnt() < pn2->drFailCnt();
      }
      else if (pn1->numPins() != pn2->numPins()) {
        return pn1->numPins() < pn2->numPins();
      }
      return true;
    }
    //Int_t pinWeight = 1;
    //Int_t symWeight = 10;
    //Int_t selfSymWeight = 10;
    //Int_t failWeight = 20;
    //Int_t PGWeight = -5000;
  };

  struct Param {
    Int_t maxSymTry = 3;
    Int_t maxSelfSymTry = 3;
    Int_t maxIteration = 6;
    Int_t maxIteration2 = 4;
  } _param;
  
  /////////////////////////////////////////
  //    Private functions                //
  /////////////////////////////////////////
  void addUnroutedNetsToPQ(PairingHeap<Net*, Net_Cmp>& pq);

  void checkSymSelfSym(const Net& net, bool& bSym, bool& bSelfSym);

  bool runNRR(PairingHeap<Net*, Net_Cmp>& pq, const Int_t maxIteration);

  bool routeSingleNet(Net& n, const bool bSym, const bool bSelfSym, const bool bStrictDRC);

  bool checkDRC();
  bool checkSingleNetDRC(const Net& net);
  
  void ripupSingleNet(Net& n);
  
  void addWireHistoryCost(const Int_t cost, const Int_t layerIdx, const Box<Int_t>& wire);
  void addViaHistoryCost(const Int_t cost, const Int_t x, const Int_t y, const LefVia& via);

  bool bSatisfySymCondition(const Net& net);
  bool bSatisfySelfSymCondition(const Net& net);

};

PROJECT_NAMESPACE_END

#endif /// _DR_GRID_ROUTE_HPP_
