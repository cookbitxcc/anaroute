/**
 * @file   polygon2box.hpp
 * @brief  Geometric Utils: Convert polygon90 to boxes
 * @author Hao Chen
 * @date   09/22/2019
 *
 **/

#ifndef _GEO_POLYGON_2_BOX_HPP_
#define _GEO_POLYGON_2_BOX_HPP_

#include "box.hpp"
#include <limbo/geometry/Polygon2Rectangle.h>

namespace limbo {
  namespace geometry {
    ////////////////////////////////////////
    //   point_traits                     //
    ////////////////////////////////////////
    template<typename T>
    struct point_traits<PROJECT_NAMESPACE::Point<T>> {
      // point type
      typedef PROJECT_NAMESPACE::Point<T> point_type;
      // coordinate type
      typedef T coordinate_type;

			/**
     	 * @brief access coordinates 
     	 * @param point a data point 
       * @param orient orientation can be HORIZONTAL(x) or VERTICAL(y)
       * @return x or y coordinate
       */
      static coordinate_type get(const point_type& point, orientation_2d orient) {
        if (orient == HORIZONTAL)
          return point.x();
        else if (orient == VERTICAL)
          return point.y();
        else
          assert(false); 
      }
			/**
			 * @brief set coordinates 
			 * @param point a data point 
			 * @param orient orientation can be HORIZONTAL(x) or VERTICAL(y)
			 * @param value data value 
			 */
			static void set(point_type& point, orientation_2d orient, coordinate_type value) {
        if (orient == HORIZONTAL)
          return point.setX(value);
        else if (orient == VERTICAL)
          return point.setY(value);
        else
          assert(false);
			}
      /**
			 * @brief construct a point object
			 * @param x x coordinate 
			 * @param y y coordinate
			 * @return the point object
			 */
			static point_type construct(coordinate_type x, coordinate_type y) {
        return point_type(x, y);
			}
    };
    ////////////////////////////////////////
    //   rectangle_traits                 //
    ////////////////////////////////////////
    template<typename T>
    struct rectangle_traits<PROJECT_NAMESPACE::Box<T>> {
      // rectangle type
      typedef PROJECT_NAMESPACE::Box<T> rectangle_type;
      // coordinate type
      typedef T coordinate_type;
			
			/**
			 * @brief access coordinates 
			 * @param rect a rectangle object
			 * @param dir can be LEFT (xl), BOTTOM (yl), RIGHT (xh) or TOP (yh)
			 * @return coordinate
			 */
			static coordinate_type get(const rectangle_type& rect, direction_2d dir) {
				switch (dir) {
					case LEFT:
		        return rect.xLo();
					case BOTTOM:
            return rect.yLo();
					case RIGHT:
            return rect.xHi();
					case TOP:
            return rect.yHi();
					default:
            assert(false);
				}
			}
      /**
			 * @brief set coordinates 
			 * @param rect a rectangle object
			 * @param dir can be LEFT (xl), BOTTOM (yl), RIGHT (xh) or TOP (yh)
			 * @param value coordinate value
			 */
			static void set(rectangle_type& rect, direction_2d dir, coordinate_type value) {
        switch (dir) {
          case LEFT:
            rect.setXLo(value);
            break;
          case BOTTOM:
            rect.setYLo(value);
            break;
          case RIGHT:
            rect.setXHi(value);
            break;
          case TOP:
            rect.YHi(value);
            break;
          default:
            assert(false);
        }
			}
      /**
			 * @brief construct rectangle 
			 * @param xl, yl, xh, yh coordinates of rectangle
			 * @return a rectangle object
			 */
			static rectangle_type construct(coordinate_type xl, coordinate_type yl, coordinate_type xh, coordinate_type yh) {
        return rect(xl, yl, xh, yh);
			}
    };

  }
}

PROJECT_NAMESPACE_START

template<typename T>
class Polygon2Box {
 public:
  Polygon2Box(const Vector_t<Point<T>>& vPts, Vector_t<T>& vBoxes)
    : _vPts(vPts), _vBoxes(vBoxes) {
      limbo::geometry::Polygon2Rectangle<std::vector<Point<T>>, std::vector<Box<T>>> p2r(_vBoxes, _vPts.begin(), _vPts.end());
    }
  ~Polygon2Box() {}

 private:
  Vector_t<Point<T>>& _vPts; // points of target polygon
  Vector_t<Box<T>>&   _vBoxes; // results
};

PROJECT_NAMESPACE_END

#endif /// _GEO_POLYGON_2_BOX_HPP_
