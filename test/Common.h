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

#pragma once

#include <boost/filesystem/path.hpp>
#include <boost/program_options.hpp>
#include <boost/noncopyable.hpp>

namespace dev
{
namespace test
{

struct CommonOptions: boost::noncopyable
{
	boost::filesystem::path ipcPath;
	boost::filesystem::path testPath;
	bool optimize = false;
	bool disableIPC = false;
	bool disableSMT = false;

	virtual bool parse(int argc, char const* const* argv);
	virtual void validate() const;

protected:
	CommonOptions(std::string caption = "");

	boost::program_options::options_description options;
};

}
}
