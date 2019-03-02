
template <class T>
class Set
{
    virtual void makeEmpty() = 0;
    virtual bool addMember(const T x) = 0;
    virtual bool delMember(const T x) = 0;
    virtual Set<T>& intersectWith(const Set<T>& R) = 0; // 集合的交运算
    virtual Set<T>& unionWith(const Set<T>& R) = 0;     // 集合的并运算
    virtual Set<T>& differenceFrom(const Set<T>& R) = 0;// 集合的差运算
    virtual bool Contains(const T x) = 0;               // 判断是否是集合的成员
    virtual bool subSet(const Set<T>& R) = 0;           // 判断是否是集合的子集
    virtual bool operator ==  (const Set<T>& R) = 0;    // 判断集合是否相等
};
