

#include "pugixml.hpp"
#include <iostream>
#include <sstream>
using namespace pugi;

std::string GetXMLDoc()
{
    xml_document doc;
    xml_node coder = doc.append_child("coder");
    xml_attribute name = coder.append_attribute("name");
    name.set_value("MsgPerformance");
    xml_attribute version = coder.append_attribute("version");
    version.set_value("1_0");
    xml_node datas = coder.append_child("datas");
    xml_node Msgs = datas.append_child("Msgs");
    for (int i=0; i < 2; i++)
    {
        xml_node Msg = Msgs.append_child("Msg");

        xml_node MsgID = Msg.append_child("MsgID");
        MsgID.append_child(node_pcdata).set_value(1);
        xml_node LastTime = Msg.append_child("LastTime");
        LastTime.append_child(node_pcdata).set_value(2);
        xml_node MaxTime = Msg.append_child("MaxTime");
        MaxTime.append_child(node_pcdata).set_value(3);
        xml_node AvgTime = Msg.append_child("AvgTime");
        AvgTime.append_child(node_pcdata).set_value(4);
        xml_node TotalTime = Msg.append_child("TotalTime");
        TotalTime.append_child(node_pcdata).set_value(5);
        xml_node MsgCount = Msg.append_child("MsgCount");
        MsgCount.append_child(node_pcdata).set_value(6);
        xml_node TotalMsgSize = Msg.append_child("TotalMsgSize");
        TotalMsgSize.append_child(node_pcdata).set_value(7);
    }

    xml_node MsgLast = datas.append_child("MsgLast");
    MsgLast.append_child(node_pcdata).set_value(8);
    std::stringstream ss;
    doc.save(ss);
    return ss.str();
}

void SetXMLDoc(const std::string& strDoc)
{
    xml_document doc;
    doc.load_buffer(strDoc.data(), strDoc.size());

    xml_node coder = doc.child("coder");
    xml_attribute name = coder.attribute("name");
    xml_attribute version = coder.attribute("version");
    xml_node datas = coder.child("datas");
    xml_node Msgs = datas.child("Msgs");

    xml_object_range<xml_named_node_iterator> Msg = Msgs.children("Msg");
    xml_named_node_iterator It = Msg.begin();
    for (int i = 0; It != Msg.end(); ++i, ++It)
    {
        xml_node MsgID = (*It).child("MsgID");
        xml_node LastTime = (*It).child("LastTime");
        xml_node MaxTime = (*It).child("MaxTime");
        xml_node AvgTime = (*It).child("AvgTime");
        xml_node TotalTime = (*It).child("TotalTime");
        xml_node MsgCount = (*It).child("MsgCount");
        xml_node TotalMsgSize = (*It).child("TotalMsgSize");
    }
    xml_node MsgLast = datas.child("MsgLast");
}

int main( int argc, char* argv[] ) {
    std::string strDoc = GetXMLDoc();
    std::cout << strDoc;
    SetXMLDoc(strDoc);
    return 0;
}
