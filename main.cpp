#include "header.hpp"

int main(){
    try {
        std::map<std::string, std::unique_ptr<Fabric>> fabrics;

        fabrics["Hori"] = std::make_unique<FabricVectHori>();
        fabrics["Vert"] = std::make_unique<FabricVectVert>();

        std::string filename="data.txt";

        std::vector<std::shared_ptr<CVector>> vectors;

        vectors = reading_from_file(filename, fabrics);

        for(std::vector<std::shared_ptr<CVector>>::iterator it=vectors.begin(); it != vectors.end(); it++){
           (*it)->output();
        }

    //-----------------------------------------------------

        std::vector<double> tmp1(6);
        std::vector<double> tmp2(6);

        for(size_t i=0; i<6;++i){ tmp1[i]=1;tmp2[i]=2; }

        CVectorVert a = CVectorVert(tmp1);
        CVectorVert b = CVectorVert(tmp2);

        CVectorVert c;
        c = a+b;

        std::cout<<c.get_length()<<"\n";
        c.rewrite_file("fileout.txt");
        c.push_back(12);

        std::cout<<c.get_length()<<"\n";

        c.output();

        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << e.what();
        return 1;
    }
}
