/*
	This file is part of solidity.

	solidity is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	solidity is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with solidity.  If not, see <http://www.gnu.org/licenses/>.
*/
/** @file IsolOptions.cpp
* @author Mathias L. Baumann <solidity@supradigital.org>
* @date 2019
*/

#include <test/tools/IsolOptions.h>
#include <boost/filesystem.hpp>
#include <string>
#include <iostream>

namespace fs = boost::filesystem;
namespace po = boost::program_options;

namespace dev
{
namespace test
{


std::string getEditorPath()
{
	if (getenv("EDITOR"))
		return getenv("EDITOR");
	else if (fs::exists("/usr/bin/editor"))
		return "/usr/bin/editor";

	return "";
}

IsolOptions::IsolOptions(std::string* _editor)
:CommonOptions(R"(isoltest, tool for interactively managing test contracts.
Usage: isoltest [Options] --ipcpath ipcpath
Interactively validates test contracts.

Allowed options)")
{
	options.add_options()
		("help", po::bool_switch(&showHelp), "Show this help screen.")
		("no-color", po::bool_switch(&formatted), "don't use colors")
		("editor", po::value<std::string>(_editor)->default_value(getEditorPath()), "editor for opening contracts");

}

bool IsolOptions::parse(int _argc, char const* const* _argv)
{
	auto res = CommonOptions::parse(_argc, _argv);

	if (showHelp || !res)
	{
		std::cout << options << std::endl;
		return false;
	}

	return res;
}

}
}
