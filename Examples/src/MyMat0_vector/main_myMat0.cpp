#include <iostream>
#include <vector>
#include <fstream>
#include "MyMat0.hpp"


int main()
{
  using namespace LinearAlgebra;
  // I create two matrices
  MyMat0 a(COLUMNMAJOR);
  //MyMat0 a;
  a.resize(3,4);
  MyMat0 b(5,5);

  b.fillRandom();
  a(0,0)=5;
  a(1,1)=10;
  a(2,2)=20;

  //! file to output the matrix
  std::ofstream ofile;
  ofile.open("Matrix.dat");
  std::cout<<"Some output is in the file Matrix.dat"<<std::endl;
  /// I want a certain format and precision
  ofile.setf(std::ios_base::scientific, std::ios_base::floatfield);
  ofile.precision(16);
  std::cout<<"MATRIX a:"<<std::endl;
  a.showMe(); //On screen (default is cout)
  a.showMe(ofile); //Matrix stored on file
  std::cout<<"Matrix b"<<std::endl;
  b.showMe(); 
  b.showMe(ofile); //on file

  ofile.close();// close file

  std::vector<double> va(4,1.0);
  std::vector<double> res(a*va);
  std::cout<<"result of a*[";
  for (std::vector<double>::iterator it=va.begin();it<va.end()-1;
       ++it)std::cout<<*it<<",";
  std::cout<<*(va.end()-1)<<"]^T =";
  std::cout<<"[";
  for (std::vector<double>::iterator i=res.begin();i<res.end()-1;++i)std::cout<<*i<<", ";
  std::cout<<*(res.end()-1)<<"]"<<std::endl;
}
