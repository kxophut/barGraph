#ifndef BARGRAPH_H
#define BARGRAPH_H

#include <functional>
#include "IDictionary.h"
#include "Sequence.h"


//Функция построения гистограммы на основе IDictionary
template <typename TKey, typename TElem>
IDictionary<TKey, int>* barGraphBuild(std::function<TKey(TElem)> func, Sequence<TElem> *seq){
    auto res = new IDictionary<TKey, int>();
    auto iter = seq->begin();
    while(iter->isValuable()){
        if(res->ContainsKey(func(iter->GetData()))){
            res->Add(func(iter->GetData()), res->Remove(func(iter->GetData()))+1);
        }
        else res->Add(func(iter->GetData()), 1);
        iter->Next();
    }
    return res;
}
//Функция построения гистограммы на основе IDictionary
template <typename TKey, typename TElem>
IDictionary<TKey, int>* barGraphBuild(IDictionary<TElem, TKey>* dict, Sequence<TElem> *seq){
    auto res = new IDictionary<TKey, int>();
    auto iter = seq->begin();
    while(iter->isValuable()){
        if(res->ContainsKey(dict->Get(iter->GetData()))){
            res->Add(dict->Get(iter->GetData()), res->Remove(dict->Get(iter->GetData()))+1);
        }
        else res->Add(dict->Get(iter->GetData()), 1);
        iter->Next();
    }
    return res;
}


#endif
