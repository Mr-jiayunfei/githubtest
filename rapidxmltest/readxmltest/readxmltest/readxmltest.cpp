// readxmltest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include <rapidxml.hpp>
#include <rapidxml_print.hpp>
#include <rapidxml_utils.hpp>

using namespace rapidxml;

bool ReadXML(const std::string& xml_full_name) {

	bool rv = false;

	try 
	{
		rapidxml::file<> content(xml_full_name.c_str());

		xml_document<> doc;
		doc.parse<0>(content.data());

		xml_node<char>* catelognode = doc.first_node(u8"catalog");
		if (!catelognode) {
			return false;
		}

		for (auto it = catelognode->first_node("book"); it; it = it->next_sibling()) 
		{
			std::string bookid;
			xml_attribute<> *att = it->first_attribute(u8"id");
			if (att) {
				bookid = att->value();
				std::cout << "bookid:" << bookid << std::endl;
			}

			xml_node<char>* authornode = it->first_node(u8"author");
			if (!authornode) {
				return false;
			}
			std::string authorname;
			auto value = authornode->value();
			if (value) {
				if (strlen(value) != 0) {
					authorname = value;
					std::cout << "authorname:" << authorname << std::endl;
				}
			}

			xml_node<char>* titlenode = it->first_node(u8"title");
			if (!titlenode) {
				return false;
			}
			std::string titlename;
			value = titlenode->value();
			if (value) {
				if (strlen(value) != 0) {
					titlename = value;
					std::cout << "titlename:" << titlename << std::endl;
				}
			}

			xml_node<char>* genrenode = it->first_node(u8"genre");
			if (!genrenode) {
				return false;
			}
			std::string genrename;
			value = genrenode->value();
			if (value) {
				if (strlen(value) != 0) {
					genrename = value;
					std::cout << "genrename:" << genrename << std::endl;
				}
			}
			
		}
	}
	catch (const parse_error& e) {
		std::string error_info = u8"解析XML出错，";
		error_info += e.what();
		return false;
	}
	catch (const std::exception& e) {
		std::string error_info = u8"解析XML出错，";
		error_info += e.what();
		return false;
	}
	catch (...) {
		return false;
	}

	return true;
}

bool WriteXML(const std::string& xml_full_name) {

	xml_document<char> doc;

	///声明
	xml_node<> *decl_node = doc.allocate_node(node_declaration);
	decl_node->append_attribute(doc.allocate_attribute(u8"version", u8"1.0"));
	decl_node->append_attribute(doc.allocate_attribute(u8"encoding", u8"UTF-8"));
	doc.append_node(decl_node);

	xml_node<> *catalog_node = doc.allocate_node(node_element,
		u8"catalog");
	doc.append_node(catalog_node);

	for (int i=0;i<3;++i)
	{
		xml_node<> *book_node = doc.allocate_node(node_element, u8"book ");
		book_node->append_attribute(doc.allocate_attribute(u8"id","boolid"));

		xml_node<> *author_node = doc.allocate_node(node_element, u8"author ");
		author_node->append_node(doc.allocate_node(node_data, "","authorname"));
		book_node->append_node(author_node);

		xml_node<> *title_node = doc.allocate_node(node_element, u8"title ");
		title_node->append_node(doc.allocate_node(node_data, "", "titlename"));
		book_node->append_node(title_node);

		xml_node<> *genre_node = doc.allocate_node(node_element, u8"genre ");
		genre_node->append_node(doc.allocate_node(node_data, "", "genrename"));
		book_node->append_node(genre_node);

		catalog_node->append_node(book_node);
	}

	std::ofstream out(xml_full_name);
	out << doc;
	out.close();

	doc.clear();

	return true;
}

bool ModifyNodeValue(const std::string& xml_full_name, const std::string& node_name, const std::string& node_value) {


	rapidxml::file<> content(xml_full_name.c_str());

	xml_document<> doc;
	doc.parse<rapidxml::parse_no_data_nodes>(content.data());

	xml_node<>* catelog_node = doc.first_node(u8"catalog");
	if (!catelog_node) {
		return false;
	}
	xml_node<>* book_node = catelog_node->first_node(u8"book");
	if (!book_node) {
		return false;
	}
	xml_node<>* author_node = book_node->first_node(u8"author");
	if (!author_node) {
		return false;
	}

	const std::string author_name = node_value;
	const char * text = doc.allocate_string(author_name.c_str(), strlen(author_name.c_str()));
	author_node->value(text);

	std::string data;
	rapidxml::print(std::back_inserter(data), doc);

	std::ofstream out(xml_full_name);
	out << data;
	out.close();

}

int main()
{
	ReadXML("E:/Test/github/rapidxmltest/xmltest.xml");
	WriteXML("E:/Test/github/rapidxmltest/writexml.xml"); \
	ModifyNodeValue("E:/Test/github/rapidxmltest/writexml.xml","author","jiayunfei");
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
