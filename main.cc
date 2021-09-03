#include <VoxelSpace.h>
#include <Lignum.h>
#include <iostream>
using namespace Lignum;

class SampleSegment;
class SampleBud;

class SampleSegment: public CfTreeSegment<SampleSegment,SampleBud>{
public:
  SampleSegment(const Point& p,const PositionVector& d,
	       const LGMdouble go,const METER l,
		const METER r,const METER rh,Tree<SampleSegment,SampleBud>* tree)
    :CfTreeSegment<SampleSegment,SampleBud>(p,d,go,l,r,rh,tree){}
};
  
class SampleBud: public Bud<SampleSegment,SampleBud>{
public:
    SampleBud(const Point& p, const PositionVector& d, 
          const LGMdouble go, Tree<SampleSegment,SampleBud>* tree)
      :Bud<SampleSegment,SampleBud>(p,d,go,tree){}
};
 
int main(){
  Tree<SampleSegment,SampleBud> t(Point(0,0,0),PositionVector(0,0,1.0));
  SampleSegment s(Point(0,0,0),PositionVector(0,0,1.0),1.0,0.5,0.2,0.2,&t);
  SampleBud b(Point(0,0,0),PositionVector(0,0,1.0),1.0,&t);
  FirmamentWithMask& f = GetFirmament(t);
  VoxelSpace vs = VoxelSpace(Point(0,0,0),0.1,0.1,0.1,100,100,100,f);
  VoxelBox box = vs.getVoxelBox(Point(0,0,0));
  
  std::cout << "1) Size of SampleSegment bytes: " << sizeof(s) << endl;
  std::cout << "2) Size of SampleBud bytes: " << sizeof(b) << endl;
  std::cout << "3) Size of SampleSegment+SampleBud bytes: " << sizeof(s)+sizeof(b) << endl;
  double sgmnt_bud1 = sizeof(s)+sizeof(b);
  double sgmnt_bud2 = 500.0;
  std::cout << "4) Size of 10000 SampleSegment+SampleBud, i.e. Tree (GB): " << 10000*sgmnt_bud1*1e-9 << " vs 500 bytes: " << 10000*sgmnt_bud2*1e-9 << endl;
  std::cout << "5) Size of 3000*10000 SampleSegment+SampleBud, i.e. Forest plot (GB): " << 3000*10000*sgmnt_bud1*1e-9 << " vs 500 bytes: " 
	    << 3000*10000*sgmnt_bud2*1e-9 << endl;
  std::cout << "4) Size of 50000 SampleSegment+SampleBud, i.e. Tree (GB): " << 50000*sgmnt_bud1*1e-9 << " vs 500 bytes: " << 50000*sgmnt_bud2*1e-9
	    << " (MB: )" <<  50000*sgmnt_bud2*1e-6 << endl;
  std::cout << "5) Size of 3000*50000 SampleSegment+SampleBud, i.e. Forest plot (GB): " << 3000*50000*sgmnt_bud1*1e-9 << " vs 500 bytes: "
	    << 3000*50000*sgmnt_bud2*1e-9 << " (MB: )" << 3000*50000*sgmnt_bud2*1e-6 << endl;
  
  std::cout << "1ha (100m x 100m) forest 40m high" <<endl;
  std::cout << "6) Size of VoxelSpace bytes: " << sizeof(vs) << endl;
  std::cout << "7) Size of VoxelBox bytes: " << sizeof(box) << endl;
  
  std::cout << "8) Size of 500*500*200 VoxelSpace (VoxelBox 0.2m x 0.2m x 0.2m)" << " with VoxelBox " << sizeof(box) << " bytes (TB): "
	    << 500.0*500.0*200.0*sizeof(box)*1e-12 << endl;
  std::cout << "9) Size of 500*500*200 VoxelSpace (VoxelBox 0.2m x 0.2m x 0.2m)" << " with VoxelBox " << sizeof(box) << " bytes (GB): "
	    << 500.0*500.0*200.0*sizeof(box)*1e-9<< " (vs 300 bytes): " <<  500.0*500.0*200.0*300*(1e-9) <<  endl;
  std::cout << "10) Size of 1000*1000*400 VoxelSapce (VoxelBox 0.1m x 0.1m x 0.1m)" << " with VoxelBox " << sizeof(box) << " bytes (TB): "
	    << 1000*1000*400*sizeof(box)*1e-12 << endl;
  std::cout << "11) Size of 1000*1000*400 VoxelSpace (VoxelBox 0.1m x 0.1m x 0.1m)" << " with VoxelBox " << sizeof(box) << " bytes (GB): "
	    << 1000*1000*400*sizeof(box)*1e-9 << endl;
  
  std::cout << "1ha (100m x 100m) forest 60m high" <<endl;
  std::cout << "12) Size of 500*500*300 VoxelSpace (VoxelBox 0.2m x 0.2m x 0.2m)" << " with VoxelBox " << sizeof(box) << " bytes (TB): "
	    << 500*500*400*sizeof(box)*1e-12 << endl;
  std::cout << "13) Size of 1000*1000*600 VoxelSpace (VoxelBox 0.1m x 0.1m x 0.1m)" << " with VoxelBox " << sizeof(box) << " bytes (TB): "
	    << 1000*1000*800*sizeof(box)*1e-12 << endl;
  exit(0);
}
  
