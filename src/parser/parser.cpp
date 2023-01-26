/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:02:41 by jvaquer           #+#    #+#             */
/*   Updated: 2023/01/26 13:57:28 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser/parser.hpp"
#include <fstream>

bool loadOBJ(const char *path, std::vector<Vec3> & out_vertices, std::vector<Vec2> & out_uvs, std::vector <Vec3> & out_normals)
{
	std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
	std::vector<Vec3> tmp_vertices;
	std::vector<Vec2> tmp_uvs;
	std::vector<Vec3> tmp_normals;

	std::cout << "\nParser\n" << std::endl;
	std::ifstream	file(path);
	if (!file)
	{
		std::cerr << "Cannot open" << path << std::endl;
		exit(1);
	}
	
	std::string		line;
	while(std::getline(file, line))
	{
		if (line.substr(0,2) == "v ")
		{
			// std::cout << line << std::endl;
			std::istringstream v(line.substr(2));
			double x, y, z;
			v >> x;
			v >> y;
			v >> z;
			Vec3 tmp_vert(x, y, z);
			// std::cout << tmp_vert.x << " " << tmp_vert.y << " " << tmp_vert.z << std::endl;
			tmp_vertices.push_back(tmp_vert);
			// std::cout << std::endl;
		}
		else if (line.substr(0, 2) == "vt")
		{
			// std::cout << line << std::endl;
			std::istringstream v(line.substr(3));
			double x, y;
			v >> x;
			v >> y;
			Vec2 tmp_uv(x, y);
			// std::cout << tmp_uv.x << " " << tmp_uv.y << std::endl;
			tmp_uvs.push_back(tmp_uv);
			// std::cout << std::endl;
		}
		else if (line.substr(0, 2) == "vn")
		{
			std::cout << line << std::endl;
			std::istringstream v(line.substr(3));
			double x, y, z;
			v >> x;
			v >> y;
			v >> z;
			Vec3 tmp_normal(x, y, z);
			std::cout << tmp_normal.x << " " << tmp_normal.y << " " << tmp_normal.z << std::endl;
			tmp_normals.push_back(tmp_normal);
			std::cout << std::endl;
		}
		else if (line.substr(0, 2) == "f ")
		{
			unsigned int vertexIdx[3], uvIdx[3], normalIdx[3];
			const char *line_buf = line.c_str();
			int match = sscanf(line_buf, "f %d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIdx[0], &uvIdx[0], &normalIdx[0], &vertexIdx[1], &uvIdx[1], &normalIdx[1], &vertexIdx[2], &uvIdx[2], &normalIdx[2]);
			if (match != 9)
			{
				std::cerr << "Error: File corrupted." << std::endl;
				exit(1);
			}
			vertexIndices.push_back(vertexIdx[0]);
			vertexIndices.push_back(vertexIdx[1]);
			vertexIndices.push_back(vertexIdx[2]);
			uvIndices.push_back(vertexIdx[0]);
			uvIndices.push_back(vertexIdx[1]);
			uvIndices.push_back(vertexIdx[2]);
			normalIndices.push_back(normalIdx[0]);
			normalIndices.push_back(normalIdx[1]);
			normalIndices.push_back(normalIdx[2]);
		}
	}
	return true;
}