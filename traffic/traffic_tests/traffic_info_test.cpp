#include "testing/testing.hpp"

#include "traffic/speed_groups.hpp"
#include "traffic/traffic_info.hpp"

#include "std/algorithm.hpp"

namespace traffic
{
namespace
{
SpeedGroup GetSpeedGroup(TrafficInfo::Coloring const & coloring,
                         TrafficInfo::RoadSegmentId const & fid)
{
  auto const it = coloring.find(fid);
  if (it == coloring.cend())
    return SpeedGroup::Unknown;
  return it->second;
}
}  // namespace

UNIT_TEST(TrafficInfo_RemoteFile)
{
  TrafficInfo r;
  TEST(r.ReceiveTrafficData(), ());
}

UNIT_TEST(TrafficInfo_Serialization)
{
  TrafficInfo::Coloring coloring = {
      {TrafficInfo::RoadSegmentId(0, 0, 0), SpeedGroup::G0},
      {TrafficInfo::RoadSegmentId(1000, 1, 1), SpeedGroup::G1},
      {TrafficInfo::RoadSegmentId(1000000, 0, 0), SpeedGroup::G5},
      {TrafficInfo::RoadSegmentId(4294967295, 32767, 1), SpeedGroup::TempBlock},
  };

  vector<uint8_t> buf;
  TrafficInfo::SerializeTrafficData(coloring, buf);

  TrafficInfo::Coloring deserializedColoring;
  TrafficInfo::DeserializeTrafficData(buf, deserializedColoring);

  TEST_EQUAL(coloring.size(), deserializedColoring.size(), ());

  for (auto const & p : coloring)
  {
    auto const g1 = p.second;
    auto const g2 = GetSpeedGroup(deserializedColoring, p.first);
    TEST_EQUAL(g1, g2, ());
  }
}
}  // namespace traffic
