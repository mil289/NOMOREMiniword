#include "hdocumentmodel.h"

#include "QFile.h"
#include "QTextStream.h"
#include <QtGlobal>

HDocumentModel::HDocumentModel()
{
}

HDocumentModel::~HDocumentModel()
{
    //QList<QList<char*>*> mLogicLine;
    //i是指向第n个元素的指针，故传*iu给其他函数
  for (auto i = mLogicLine.begin(); i != mLogicLine.end(); i++)
  {
    destructLogicLine(*i);
    delete *i;
  }
}

/*!
 * \brief 释放逻辑行占用的堆内存
 * \param ptrLList 指向存储堆结构的链表头指针
 *
 * 注意我并不会删除容器。请在调用我之后手动对容器进行删除。 此处容器指
 * QList<char*>* 中的QList ，即存储堆内存的链表。
 */
HDocumentModel::destructLogicLine(QList<char*>* ptrLLList)
{
  for (auto j = ptrLLList->begin(); j != ptrLLList->end(); j++) {
    delete[] * j;
  }
}

/*
 * 读文件
 * 读一行处理一行
 * 处理包括：新建逻辑行并建立好链表的顺序
 * 读完返回，让control调view去显示刚存好的逻辑行链表
*/
HDocumentModel::ReadDocument()
{
    QFile file("in.txt");
    if(!file.open(QIODevice::ReadOnly))
        return;

    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line=in.readLine();
        CreateLL(line);
    }
}

QList<char*>& CreateLL(QString line,int pos)//在pos行加入一个逻辑行
{
    //checkStatus();
    auto newLine = constructNewLine(Line);//QString 转换成 QList<char*>
    mLogicLine.insert(pos, newLine);
    //mCurStatus = qMakePair(pos, HLLCreated);
    //emit modelChanged();
    return *newLine;
}

/*
 * 根据传来的QString创建新逻辑行，并插入最后逻辑行链表的最后
 * 重载函数
*/
QList<char*>& CreateLL(QString line)//默认往后续一个逻辑行
{
    return CreateLL(line,mLogicLine.size());//需要增加
}

QList<char*>* HDocumentModel::constructNewLine(QString Line) const
{
  auto newLine = new QList<char*>;
  //前方高能
  //QString->ByteArray
  QByteArray tBArray = Line.toUtf8();//解码为UTF8
  const char* tPos = tBArray.data();
  const char* const ptrBegin = tPos;

  //一堆char->char【100】
  while (tPos - ptrBegin < tBArray.size())
  {
    char* const t = new char[100];
    int i = 0;
    for (i = 0; i < 99 && tPos - ptrBegin < tBArray.size(); i++) //char数组未完&&原Array未完
    {
      *(t + i) = *(tPos++);
    }
    *(t + i) = 0;//每个char[]的最后一位都是0(不论是否填充完）
    newLine->append(t);//在newLine结尾填充char[] t
  }
  return newLine;
}
