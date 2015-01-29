#include "../../testing/testing.hpp"

#include "../route_track.hpp"

UNIT_TEST(clipArrowBodyAndGetArrowDirection)
{
  /// test 1
  {
    vector<m2::PointD> ptsTurn = {m2::PointD(4452766.0004956936, -8008660.158053305),
                                  m2::PointD(4452767.909028396, -8008670.0188056063),
                                  m2::PointD(4452768.5452059628, -8008681.4700018261),
                                  m2::PointD(4452765.6824069088, -8008693.8754644003),
                                  m2::PointD(4452759.3206312312, -8008705.6447494039),
                                  m2::PointD(4452746.2789910901, -8008720.9130110294),
                                  m2::PointD(4452746.2789910901, -8008720.9130110294),
                                  m2::PointD(4452670.8919493081, -8008780.7137024049),
                                  m2::PointD(4452631.7670288859, -8008811.5683144433),
                                  m2::PointD(4452567.5130945379, -8008863.0986974351)};
    pair<m2::PointD, m2::PointD> arrowDirection;
    bool result = clipArrowBodyAndGetArrowDirection(ptsTurn, arrowDirection, 5, 13., 13., 19.);

    TEST(result, ());

    TEST(m2::AlmostEqual(arrowDirection.first, m2::PointD(4452740.7948958352, -8008725.2632638067)), ());
    TEST(m2::AlmostEqual(arrowDirection.second, m2::PointD(4452736.0942427581, -8008728.9920519013)), ());

    TEST_EQUAL(ptsTurn.size(), 4, ());
    if (ptsTurn.size() == 4)
    {
      TEST(m2::AlmostEqual(ptsTurn[0], m2::PointD(4452754.7223071428, -8008711.0281532137)), ());
      TEST(m2::AlmostEqual(ptsTurn[1], m2::PointD(4452746.2789910901, -8008720.9130110294)), ());
      TEST(m2::AlmostEqual(ptsTurn[2], m2::PointD(4452746.2789910901, -8008720.9130110294)), ());
      TEST(m2::AlmostEqual(ptsTurn[3], m2::PointD(4452736.0942427581, -8008728.9920519013)), ());
    }
  }
  /// test 2
  {
    vector<m2::PointD> ptsTurn = {m2::PointD(12914322.855819134, -23248364.915229369),
                                  m2::PointD(12914293.14321561, -23248301.411821831),
                                  m2::PointD(12914293.14321561, -23248301.411821831),
                                  m2::PointD(12913951.625143414, -23247594.377110228),
                                  m2::PointD(12913951.625143414, -23247594.377110228),
                                  m2::PointD(12913554.725762228, -23246680.585511677),
                                  m2::PointD(12913554.725762228, -23246680.585511677),
                                  m2::PointD(12913622.106354846, -23246649.202769905),
                                  m2::PointD(12913891.628725335, -23246525.517846469),
                                  m2::PointD(12913891.628725335, -23246525.517846469),
                                  m2::PointD(12914043.927325094, -23246455.368188392),
                                  m2::PointD(12914043.927325094, -23246455.368188392),
                                  m2::PointD(12914123.307201328, -23246418.447315723),
                                  m2::PointD(12914474.05549168, -23246248.611301452),
                                  m2::PointD(12914474.05549168, -23246248.611301452),
                                  m2::PointD(12916033.962361945, -23245541.576589838),
                                  m2::PointD(12916319.957645988, -23245411.846770275)};
    pair<m2::PointD, m2::PointD> arrowDirection;
    bool result = clipArrowBodyAndGetArrowDirection(ptsTurn, arrowDirection, 5, 13., 13., 19.);

    TEST(result, ());

    TEST(m2::AlmostEqual(arrowDirection.first, m2::PointD(12913561.071263125, -23246677.630072903)), ());
    TEST(m2::AlmostEqual(arrowDirection.second, m2::PointD(12913566.510263896, -23246675.096839666)), ());

    TEST_EQUAL(ptsTurn.size(), 4, ());
    if (ptsTurn.size() == 4)
    {
      TEST(m2::AlmostEqual(ptsTurn[0], m2::PointD(12913559.904797219, -23246692.509336423)), ());
      TEST(m2::AlmostEqual(ptsTurn[1], m2::PointD(12913554.725762228, -23246680.585511677)), ());
      TEST(m2::AlmostEqual(ptsTurn[2], m2::PointD(12913554.725762228, -23246680.585511677)), ());
      TEST(m2::AlmostEqual(ptsTurn[3], m2::PointD(12913566.510263896, -23246675.096839666)), ());
    }
  }
  /// test 3
  {
    vector<m2::PointD> ptsTurn = {m2::PointD(8815765.3299729209, -15869538.380037762),
                                  m2::PointD(8815545.8558755163, -15869644.271852948),
                                  m2::PointD(8815493.5605482981, -15869666.954163551),
                                  m2::PointD(8815493.5605482981, -15869666.954163551),
                                  m2::PointD(8815429.2940016072, -15869529.600171586),
                                  m2::PointD(8815429.2940016072, -15869529.600171586),
                                  m2::PointD(8815196.1702537816, -15869046.971007187),
                                  m2::PointD(8815196.1702537816, -15869046.971007187),
                                  m2::PointD(8815012.9423559866, -15868625.120730862)};
    pair<m2::PointD, m2::PointD> arrowDirection;
    bool result = clipArrowBodyAndGetArrowDirection(ptsTurn, arrowDirection, 2, 5., 13., 14.);

    TEST(result, ());

    TEST(m2::AlmostEqual(arrowDirection.first, m2::PointD(8815488.4750074092, -15869656.085066356)), ());
    TEST(m2::AlmostEqual(arrowDirection.second, m2::PointD(8815488.051212335, -15869655.179308256)), ());

    TEST_EQUAL(ptsTurn.size(), 4, ());
    if (ptsTurn.size() == 4)
    {
      TEST(m2::AlmostEqual(ptsTurn[0], m2::PointD(8815498.1476540733, -15869664.964575503)), ());
      TEST(m2::AlmostEqual(ptsTurn[1], m2::PointD(8815493.5605482981, -15869666.954163551)), ());
      TEST(m2::AlmostEqual(ptsTurn[2], m2::PointD(8815493.5605482981, -15869666.954163551)), ());
      TEST(m2::AlmostEqual(ptsTurn[3], m2::PointD(8815488.051212335, -15869655.179308256)), ());
    }
  }
}
