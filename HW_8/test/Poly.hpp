#ifndef POLY_HPP_
#define POLY_HPP_

#include <stdlib.h>
#include <vector>
#include <iostream>

template<typename T>
class Poly {
public:

  /* Default constructor */
  Poly(){_coeffs.emplace_back(0);};

  /* Constructor for a poly that's a constant number */
  Poly( T constant ){_coeffs.emplace_back(constant);};

  /* Given a vector of coefficients */
  Poly( const std::vector<T> & coeffs ){_coeffs=coeffs;};

  /* Given an rvalue reference of a vector of coefficients */
  Poly( std::vector<T> && coeffs ){
    std::vector<T> temp=coeffs;
    _coeffs=temp;
    };

  /* Given an array of coefficients with size of the array*/
  Poly( T * coeffs, size_t numberCoeffs ){
    for(int i=0;i<numberCoeffs;i++){
      _coeffs.emplace_back(coeffs[i]);
    }
  };

  /* Given an initializer_list */
  Poly( std::initializer_list<T> coeffs ){
    for(auto iter=coeffs.begin();iter!=coeffs.end();iter++){
      _coeffs.emplace_back(*iter);
    }
  };

  virtual ~Poly(){
    _coeffs.clear();
  };

  /* Copying constructor */
  Poly( const Poly<T> & poly ){
    _coeffs=poly.getCoeffs();
  };

  /* Copying constructor with rvalue reference */
  Poly( Poly<T> && poly ){
    _coeffs=poly.getCoeffs();
  };

  /* Assignment operator */
  Poly<T>& operator=( const Poly<T> & poly ){
    _coeffs=poly.getCoeffs();
    return this;
  };
  
  /* Assignment operator with rvalue reference */
  Poly<T>& operator=( Poly<T> && poly ){
    _coeffs=poly.getCoeffs();
    return poly;
  };

  Poly<T> operator+( const Poly<T> & rhs ) const{
    std::vector<T> temp1=_coeffs;
    std::vector<T> temp2=rhs.getCoeffs();
    if(temp1.size()>temp2.size()){
      temp2.resize(temp1.size());
    }
    else
    {
      temp1.resize(temp2.size());
    }
    for(int i=0;i<temp1.size();i++){
      temp1[i]+=temp2[i];
    }
    //delete the useless 0 in the end
    while (*(temp1.end()-1)==0)
    {
      temp1.pop_back();
    }
    
    Poly<T> result(temp1);
    return result;
  };
  Poly<T> operator-( const Poly<T> & rhs ) const{
    std::vector<T> temp1=_coeffs;
    std::vector<T> temp2=rhs.getCoeffs();
    if(temp1.size()>temp2.size()){
      temp2.resize(temp1.size());
    }
    else
    {
      temp1.resize(temp2.size());
    }
    for(int i=0;i<temp1.size();i++){
      temp1[i]-=temp2[i];
    }
    //delete the useless 0 in the end
    while (*(temp1.end()-1)==0)
    {
      temp1.pop_back();
    }

    Poly<T> result(temp1);
    return result;
  };
  Poly<T> operator*( const Poly<T> & rhs ) const{

    std::vector<T> result;
    result.resize(_coeffs.size()+rhs.getCoeffs().size());

    for(int i=0;i<_coeffs.size();i++){
      for(int j=0;j<rhs.getCoeffs().size();j++){
        result[i+j]+=_coeffs[i]*rhs.getCoeffs()[j];
      }
    }
    //delete the useless 0 in the end
    while (*(result.end()-1)==0)
    {
      result.pop_back();
    }

    Poly<T> m_poly(result);
    return m_poly;
  };
  Poly<T> & operator+=( const Poly<T> & rhs ){
    *this=*this+rhs;
    return *this;
  };
  Poly<T> & operator-=( const Poly<T> & rhs ){
    *this=*this-rhs;
    return *this;
  };
  Poly<T> & operator*=( const Poly<T> & rhs ){
    *this=*this*rhs;
    return *this;
  };

  T eval( T param ) const{
    T sum=0;
    for(int i=1;i<_coeffs.size();i++){
      T temp=param;
      for(int j=1;j<i;j++){
        temp=temp*param;
      }
      sum+=temp*_coeffs[i];
    }
    sum+=_coeffs[0];
    return sum;
  };

  Poly<T> der() const{
    std::vector<T> temp;
    for(int i=0;i<_coeffs.size()-1;i++){
      temp.emplace_back(_coeffs[i+1]*(i+1));
    }
    Poly<T> result(temp);
    return result;
  };

  std::pair<T,T> operator()( T param ) const{
    std::pair<T,T> result(eval(param),der().eval(param));
    return result;
  };

  std::vector<T> getCoeffs() const {return _coeffs;}

private:
  std::vector<T> _coeffs;
};


#endif