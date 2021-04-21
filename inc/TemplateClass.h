#ifndef TEMPLATECLASS_H
#define TEMPLATECLASS_H

#include<vector>
using namespace std;
template<class T>
class TemplateClass{
    private:
        vector<T> elems;
    public:
        void push(T const& );
        void pop();
        T top() const;

        bool empty() const{
            return elems.empty();
        }
};
//Please remembering that the template have to wirte into .h file,
//It can not wirte to other external file
//Can also wirte some similar file in ~/Desktop/NameSpaceExample
template <class T>
void TemplateClass<T>::push(T const & elem){
    elems.push_back(elem); 
}

template<class T>
void TemplateClass<T>::pop(){
    if(elems.empty()){
        throw out_of_range("TemplateClass<>::pop(): empty stack"); 
    }

    elems.pop_back();
}

template<class T>
T TemplateClass<T>::top() const{
    if(elems.empty()){
        throw out_of_range("Template<>::pop(): empty stack"); 
    }

    return elems.back();
}

#endif 