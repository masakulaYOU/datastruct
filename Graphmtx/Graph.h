const int defaultVertices = 20; //最大顶点数

template <class T, class E>
class Graph
{
protected:
    int maxVertices;    //图中最大顶点数
    int numEdges;       //当前边数
    int numVertices;    //当前顶点数
    virtual int getVertexPos(T vertex) = 0; //给出顶点vertex在图中的位置
public:
    const E maxWeight = 99999;
    // Graph(int sz = defaultVertices);
    // ~Graph();
    bool GraphEmpty() const { return (numEdges == 0) ? true : false; } //判图空
    bool GraphFull() const { return (numVertices == maxVertices || numEdges == maxVertices * (maxVertices - 1) / 2) ? true : false; } // 判表满
    int numberOfVertices() {  return numVertices; } //顶点数量
    int numberOfEdges() {return numEdges;}          //边数量

    virtual T getValue(int i) = 0;  //取顶点i的值，不合理则返回0
    virtual E getWeight(int v1, int v2) = 0;    //取边(v1, v2)上的权值
    virtual int getFirstNeighbor(int v) = 0;    //取顶点v的第一个邻接顶点
    virtual int getNextNeighbor(int v, int w) = 0; //取邻接顶点w的下一个邻接顶点
    virtual bool insertVertex(const T& vertex) = 0;//插入一个顶点
    virtual bool insertEdge(int v1, int v2, E cost) = 0;//插入一条边，权为cost
    virtual bool removeVertex(int v) = 0;   //删除顶点v和所有相关联的边
    virtual bool removeEdge(int v1, int v2) = 0;//删除边
};
