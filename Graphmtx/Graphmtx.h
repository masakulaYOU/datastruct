#include <iostream>
#include "Graph.h"

template <class T, class E>
class Graphmtx;

template <class T, class E>
std::ostream& operator << (std::ostream& os, Graphmtx<T, E>& G);

template <class T, class E>
std::istream& operator >> (std::istream& in, Graphmtx<T, E>& G);

template <class T, class E>
class Graphmtx : public Graph<T, E>
{
    friend std::istream& operator >> <> (std::istream& in, Graphmtx& G);
    friend std::ostream& operator << <> (std::ostream& os, Graphmtx& G);
protected:
    T* verticesList;    //顶点表
    E** edge;           //邻接矩阵
    int getVertexPos(T vertex)
    {
        for(int i = 0; i < this->numVertices; i++)
            if(verticesList[i] == vertex)
                return i;
        return -1;
    }
public:
    Graphmtx(int sz = defaultVertices);
    ~Graphmtx(){ delete[] verticesList; delete[] edge; }
    T getValue(int i) { return i >= 0 && i <= this->numVertices ? verticesList[i] : NULL; }
    E getWeight(int v1, int v2) { return v1 != -1 && v2 != -1 ? edge[v1][v2] : 0; }
    int getFirstNeighbor(int v);        // 取顶点v的第一个邻接顶点
    int getNextNeighbor(int v, int w);  // 取v的邻接顶点w的下一邻接顶点
    bool insertVertex(const T& vertex);
    bool insertEdge(int v1, int v2, E cost);
    bool removeVertex(int v);
    bool removeEdge(int v1, int v2);
};

// 构造函数
template <class T, class E>
Graphmtx<T, E>::Graphmtx(int sz)
{
    this->maxVertices = sz; this->numVertices = 0; this->numEdges = 0;
    int i, j;
    verticesList = new T[this->maxVertices];      // 顶点数组
    edge = (E** ) new E* [this->maxVertices];     // 邻接矩阵数组
    for(i = 0; i < this->maxVertices; i++) edge[i] = new E[this->maxVertices];
    for(i = 0; i < this->maxVertices; i++)
    {
        for(j = 0; j < this->maxVertices; j++)
        {
            edge[i][j] = (i == j) ? 0 : this->maxWeight;
        }
    }
}

// 给出顶点v的第一个邻接顶点的位置，如果找不到则返回-1
template <class T, class E>
int Graphmtx<T, E>::getFirstNeighbor(int v)
{
    if(v != -1)
    {
        for(int col = 0; col < this->numVertices; col++)
        {
            if(edge[v][col] > 0 && edge[v][col] < this->maxWeight) return col;
        }
    }
    return -1;
}

// 给出顶点v的某邻接顶点w的下一个邻接结点
template <class T, class E>
int Graphmtx<T, E>::getNextNeighbor(int v, int w)
{
    if(v != -1 && w != -1)
    {
        for (int col = w + 1; col < this->numVertices; col++)
            if (edge[v][col] > 0 && edge[v][col] < this->maxWeight)
                return col;
    }
    return -1;
}

// 插入一个顶点
template <class T, class E>
bool Graphmtx<T, E>::insertVertex(const T& vertex)
{
    if(this->numVertices == this->maxVertices) return false;    // 顶点表满
    verticesList[this->numVertices++] = vertex;
    return true;
}

//删除顶点v以及与其相关的所有关联的边
template <class T, class E>
bool Graphmtx<T, E>::removeVertex(int v)
{

    if (v < 0 || v >= this->numVertices) return false; //v不在图中
    if (this->numVertices == 1) return false; //只剩一个顶点，不删除
    int i, j;
    verticesList[v] = verticesList[this->numVertices - 1];  // 删除该点
    for(i = 0; i < this->numVertices; i++)
        {
            //std::cout << "#" << i << "  " << this->numEdges << "  " <<edge[i][v] << std::endl;
            if(edge[i][v] > 0 && edge[i][v] < this->maxWeight)
            { this->numEdges--; }
        }
    for(i = 0; i < this->numVertices; i++)
        edge[i][v] = edge[i][this->numVertices - 1]; // 用最后一列填补v列
    this->numVertices--;
    for(j = 0; j < this->numVertices; j++)
        edge[v][j] = edge[this->numVertices][j];      // 最后一行填补v行
    return true;
}

// 插入边
template <class T, class E>
bool Graphmtx<T, E>::insertEdge(int v1, int v2, E cost)
{
    // v1 v2存在且边不存在（最大权值）
    if(v1 > -1 && v1 < this->numVertices && v2 > -1 && v2 < this->numVertices && edge[v1][v2] == this->maxWeight)
    {
        edge[v1][v2] = edge[v2][v1] = cost;
        this->numEdges++;
        return true;
    }
    return false;
}

//删除边
template <class T, class E>
bool Graphmtx<T, E>::removeEdge(int v1, int v2)
{
    // v1 v2存在且边存在
    if (v1 > -1 && v1 < this->numVertices &&
        v2 > -1 && v2 < this->numVertices &&
        edge[v1][v2] > 0 && edge[v1][v2] < this->maxWeight)
    {
        edge[v1][v2] = edge[v2][v1] = this->maxWeight;
        this->numEdges--;
        return true;
    }
    return false;
}


// 输入输出
template <class T, class E>
std::istream& operator >> (std::istream& in, Graphmtx<T, E>& G)
{
    int i, j, k, n, m;
    T e1, e2;
    E weight;
    std::cout << "Input the number of vertex and edges:" << std::endl;
    in >> n >> m;
    for(i = 0; i < n; i++)
    {
        std::cout << "Input the code number of the vertex "<< i + 1 << ": " ;
        in >> e1;
        G.insertVertex(e1);
    }

    i = 0;
    while(i < m)
    {
        std::cout << "Inter the code numbers and weight of the edge "<< i + 1 << "(example: 1 2 10):  "<< std::endl;
        in >> e1 >> e2 >> weight;
        j = G.getVertexPos(e1);
        k = G.getVertexPos(e2);
        if (j == -1 || k == -1) std::cout << "Wrong code, try again!"<< std::endl;
        else { G.insertEdge(j, k, weight); i ++; }
    }
    return in;
}

template <class T, class E>
std::ostream& operator << (std::ostream& os, Graphmtx<T, E>& G)
{
    int i,j,n,m;
    T e1,e2;
    E w;
    n = G.numberOfVertices();
    m = G.numberOfEdges();
    os << "number of vertex: " << n << "\n" << "number of edges: " << m << std::endl;
    os << "edges(vertex1,vertex2,weight): " << std::endl;
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            w = G.getWeight(i, j);
            if (w > 0 && w < G.maxWeight)
            {
                e1 = G.getValue(i);
                e2 = G.getValue(j);
                os << "(" << e1 << "," << e2 << "," << w << ")" << std::endl;
            }
        }
    }
    for(i = 0; i < n;i++)
    {
        for(j = 0; j < n;j++)
        {
            os << G.edge[i][j] << "\t\t";
        }
        os << std::endl;
    }
    return os;
}








