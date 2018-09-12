
#include "dmos.h"
#include "dmutil.h"
#include "dmtypes.h"
#include "dmformat.h"
#include "pugixml.hpp"

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
        LastTime.append_child(node_pcdata).set_value(1);
        xml_node MaxTime = Msg.append_child("MaxTime");
        MaxTime.append_child(node_pcdata).set_value(1);
        xml_node AvgTime = Msg.append_child("AvgTime");
        AvgTime.append_child(node_pcdata).set_value(1);
        xml_node TotalTime = Msg.append_child("TotalTime");
        TotalTime.append_child(node_pcdata).set_value(1);
        xml_node MsgCount = Msg.append_child("MsgCount");
        MsgCount.append_child(node_pcdata).set_value(1);
        xml_node TotalMsgSize = Msg.append_child("TotalMsgSize");
        TotalMsgSize.append_child(node_pcdata).set_value(1);
    }

    xml_node MsgLast = datas.append_child("MsgLast");
    std::stringstream ss;
    doc.save(ss);
    return ss.str();
}

int main( int argc, char* argv[] ) {
    std::string strDoc = GetXMLDoc();

    return 0;
}
