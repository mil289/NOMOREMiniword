#ifndef HDOCUMENTMODEL_H
#define HDOCUMENTMODEL_H

class HDocumentModel
{
private:
    HDocumentModel::HDocumentModel();

    HDocumentModel::~HDocumentModel();


    void destructLogicLine(QList<char*>* ptrLLList);

    QList<QList<char*>*> mLogicLine;

public:
    void ReadDocument();
    QList<char*>& CreateLL(QString line,int pos);//在pos行加入一个逻辑行

    QList<char*>& CreateLL(QString line);//默认往后续一个逻辑行

    QList<char*>* constructNewLine(QString Line) const;
}

#endif // HDOCUMENTMODEL_H
