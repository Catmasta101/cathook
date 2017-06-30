/*
 * textfile.cpp
 *
 *  Created on: Jan 24, 2017
 *      Author: nullifiedcat
 */

#include "textfile.h"

#include "common.h"

#include "beforecheaders.h"
#include <fstream>
#include "aftercheaders.h"

#include <stdio.h>

TextFile::TextFile()
	: lines {} {}

void TextFile::Load(std::string name) {
	std::string filename = format("cathook/", name);
	std::ifstream file(filename, std::ios::in);
	if (file.bad()) {
		logging::Info("Could not open the file: %s", filename.c_str());
		return;
	}
	lines.clear();
	for (std::string line; std::getline(file, line);) {
		lines.push_back(line);
	}
}

size_t TextFile::LineCount() const {
	return lines.size();
}

const std::string& TextFile::Line(size_t id) const {
	return lines.at(id);
}
