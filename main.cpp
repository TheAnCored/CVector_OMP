#include "header.hpp"

int main(){
   // try {
        // std::map<std::string, std::unique_ptr<Fabric>> fabrics;

        // fabrics["Hori"] = std::make_unique<FabricVectHori>();
        // fabrics["Vert"] = std::make_unique<FabricVectVert>();

        // std::string filename="data.txt";

        // std::vector<std::shared_ptr<CVector>> vectors;

        // vectors = reading_from_file(filename, fabrics);

        // for(std::vector<std::shared_ptr<CVector>>::iterator it=vectors.begin(); it != vectors.end(); it++){
        //    (*it)->output();
        // }

    //-----------------------------------------------------
        unsigned int length=0;
        std::cout<<" Введите длину векторов: "; std::cin>>length; std::cout<<std::endl;

        std::vector<double> tmp1(length,1);
        std::vector<double> tmp2(length,2);

        //for(size_t i=0; i<6;++i){ tmp1[i]=1;tmp2[i]=2; }

        CVectorVert a = CVectorVert(tmp1);
        CVectorVert b = CVectorVert(tmp2);

        CVectorVert c;
        
        auto start_time = std::chrono::high_resolution_clock::now(); 
        c = a+b;
        auto end_time = std::chrono::high_resolution_clock::now(); 

        std::chrono::duration<double> serial_duration = end_time-start_time;

        CVectorVert d;

        start_time = std::chrono::high_resolution_clock::now();
        d = addition(a,b);
        end_time = std::chrono::high_resolution_clock::now(); 
        std::chrono::duration<double> parallel_duration = end_time - start_time; 

        std::cout << "Serial duration: "<< serial_duration.count() << " seconds"<< std::endl; 
        std::cout << "Parallel duration: "<< parallel_duration.count() << " seconds"<< std::endl; 
        std::cout << "Speedup: "<< serial_duration.count()  / parallel_duration.count() << std::endl; 

        return 0;
    
    // catch (const std::exception& e) {
    //     std::cerr << e.what();
    //     return 1;
    // }
}