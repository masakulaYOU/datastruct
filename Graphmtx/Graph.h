const int defaultVertices = 20; //��󶥵���

template <class T, class E>
class Graph
{
protected:
    int maxVertices;    //ͼ����󶥵���
    int numEdges;       //��ǰ����
    int numVertices;    //��ǰ������
    virtual int getVertexPos(T vertex) = 0; //��������vertex��ͼ�е�λ��
public:
    const E maxWeight = 99999;
    // Graph(int sz = defaultVertices);
    // ~Graph();
    bool GraphEmpty() const { return (numEdges == 0) ? true : false; } //��ͼ��
    bool GraphFull() const { return (numVertices == maxVertices || numEdges == maxVertices * (maxVertices - 1) / 2) ? true : false; } // �б���
    int numberOfVertices() {  return numVertices; } //��������
    int numberOfEdges() {return numEdges;}          //������

    virtual T getValue(int i) = 0;  //ȡ����i��ֵ���������򷵻�0
    virtual E getWeight(int v1, int v2) = 0;    //ȡ��(v1, v2)�ϵ�Ȩֵ
    virtual int getFirstNeighbor(int v) = 0;    //ȡ����v�ĵ�һ���ڽӶ���
    virtual int getNextNeighbor(int v, int w) = 0; //ȡ�ڽӶ���w����һ���ڽӶ���
    virtual bool insertVertex(const T& vertex) = 0;//����һ������
    virtual bool insertEdge(int v1, int v2, E cost) = 0;//����һ���ߣ�ȨΪcost
    virtual bool removeVertex(int v) = 0;   //ɾ������v������������ı�
    virtual bool removeEdge(int v1, int v2) = 0;//ɾ����
};
