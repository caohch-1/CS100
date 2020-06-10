#ifndef FUNCTIONAL_FORMS_HPP_
#define FUNCTIONAL_FORMS_HPP_

#include <stdlib.h>
#include <math.h>
#include <iostream>

/* For all lambda functions below, if you are not clear how they work, please refer to the given example for details. */


/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1+f2)(m) as first, and (d(f1+f2)/dx)(m) as second.
 */
auto derSum = []( auto f1, auto f2 ){
  //add your code here ...
  return [=](auto m){
    std::pair<double,double> result(f1(m).first+f2(m).first,f1(m).second+f2(m).second);
    return result;
  };
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1-f2)(m) as first, and (d(f1-f2)/dx)(m) as second.
 */
auto derSub = []( auto f1, auto f2 ){
  //add your code here ...
  return [=](auto m){
    std::pair<double,double> result(f1(m).first-f2(m).first,f1(m).second-f2(m).second);
    return result;
  };
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1*f2)(m) as first, and (d(f1*f2)/dx)(m) as second.
 */
auto derMul = []( auto f1, auto f2 ){
  //add your code here ...
  return [=](auto m){
    std::pair<double,double> result(f1(m).first*f2(m).first,f1(m).second*f2(m).first+f2(m).second*f1(m).first);
    return result;
  };
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1/f2)(m) as first, and (d(f1/f2)/dx)(m) as second.
 */
auto derDiv = []( auto f1, auto f2 ){
  //add your code here ...
  return [=](auto m){
    std::pair<double,double> result(f1(m).first/f2(m).first , (f1(m).second*f2(m).first - f2(m).second*f1(m).first) / (f2(m).first*f2(m).first));
    return result;
  };
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1(f2))(m) as first, and (d(f1(f2))/dx)(m) as second.
 */
auto derComp = []( auto f1, auto f2 ){
  //add your code here ...
  return [=](auto m){
    std::pair<double,double> result(f1(f2(m).first).first , f1(f2(m).first).second*f2(m).second);
    return result;
  };
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has [(f1)(m)]^exp as first, and (d(f1^exp)/dx)(m) as second.
 */
auto derPow = []( auto f, int exp ) {
  //add your code here ...
  return [=](auto m){
    double lval=1;
    for(int i=0;i<exp;i++){
      lval*=f(m).first;
    }

    double rval=1;
    for(int i=0;i<exp-1;i++){
      rval*=f(m).first;
    }
    rval*=exp*f(m).second;

    std::pair<double,double> result( lval,rval );
    return result;
  };
};

#endif