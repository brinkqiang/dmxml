#include "dmxml.h"
#include <iostream>
#include <sstream>

std::string GetXMLDoc()
{
	pugi::xml_document doc;
	pugi::xml_node coder = doc.append_child("coder");
	pugi::xml_attribute name = coder.append_attribute("name");
	name.set_value("MsgPerformance");
	pugi::xml_attribute version = coder.append_attribute("version");
	version.set_value("1_0");
	pugi::xml_node datas = coder.append_child("datas");
	pugi::xml_node Msgs = datas.append_child("Msgs");

	for (int i = 0; i < 2; i++)
	{
		pugi::xml_node Msg = Msgs.append_child("Msg");

		pugi::xml_node MsgID = Msg.append_child("MsgID");
		MsgID.append_child(pugi::node_pcdata).set_value("1");
		pugi::xml_node LastTime = Msg.append_child("LastTime");
		LastTime.append_child(pugi::node_pcdata).set_value("2");
		pugi::xml_node MaxTime = Msg.append_child("MaxTime");
		MaxTime.append_child(pugi::node_pcdata).set_value("3");
		pugi::xml_node AvgTime = Msg.append_child("AvgTime");
		AvgTime.append_child(pugi::node_pcdata).set_value("4");
		pugi::xml_node TotalTime = Msg.append_child("TotalTime");
		TotalTime.append_child(pugi::node_pcdata).set_value("5");
		pugi::xml_node MsgCount = Msg.append_child("MsgCount");
		MsgCount.append_child(pugi::node_pcdata).set_value("6");
		pugi::xml_node TotalMsgSize = Msg.append_child("TotalMsgSize");
		TotalMsgSize.append_child(pugi::node_pcdata).set_value("7");
	}

	pugi::xml_node MsgLast = datas.append_child("MsgLast");
	MsgLast.append_child(pugi::node_pcdata).set_value("8");
	std::stringstream ss;
	doc.save(ss);
	return ss.str();
}

std::string SetXMLDoc(const std::string& strDoc)
{
	pugi::xml_document doc;
	doc.load_buffer(strDoc.data(), strDoc.size());

	pugi::xml_node coder = doc.child("coder");
	pugi::xml_attribute name = coder.attribute("name");
	pugi::xml_attribute version = coder.attribute("version");
	pugi::xml_node datas = coder.child("datas");
	pugi::xml_node Msgs = datas.child("Msgs");

	pugi::xml_object_range<pugi::xml_named_node_iterator> Msg = Msgs.children("Msg");
	pugi::xml_named_node_iterator It = Msg.begin();
	for (int i = 0; It != Msg.end(); ++i, ++It)
	{
		pugi::xml_node MsgID = (*It).child("MsgID");
		pugi::xml_node LastTime = (*It).child("LastTime");
		pugi::xml_node MaxTime = (*It).child("MaxTime");
		pugi::xml_node AvgTime = (*It).child("AvgTime");
		pugi::xml_node TotalTime = (*It).child("TotalTime");
		pugi::xml_node MsgCount = (*It).child("MsgCount");
		pugi::xml_node TotalMsgSize = (*It).child("TotalMsgSize");
	}
	pugi::xml_node MsgLast = datas.child("MsgLast");

	std::stringstream ss;
	doc.save(ss);

	return ss.str();
}

int main(int argc, char* argv[])
{
	std::string strDoc = GetXMLDoc();
	std::cout << strDoc << std::endl;
	std::string strNew = SetXMLDoc(strDoc);
	std::cout << strNew << std::endl;
	return 0;
}
