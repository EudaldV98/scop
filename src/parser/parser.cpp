/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:02:41 by jvaquer           #+#    #+#             */
/*   Updated: 2023/01/30 15:51:40 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser/parser.hpp"
#include <fstream>

bool	getVertices(std::string line, std::vector<Vec3> &tmp_vertices)
{
	std::istringstream v(line.substr(2));
	double x, y, z;
	v >> x;
	v >> y;
	v >> z;
	Vec3 tmp_vert(x, y, z);
	tmp_vertices.push_back(tmp_vert);
	return true;
}

bool	getVertexTexture(std::string line, std::vector<Vec2> &tmp_uvs)
{
	std::istringstream v(line.substr(3));
	double x, y;
	v >> x;
	v >> y;
	Vec2 tmp_uv(x, y);
	tmp_uvs.push_back(tmp_uv);
	return true;
}

bool	getNormals(std::string line, std::vector<Vec3> &tmp_normals)
{
	std::istringstream v(line.substr(3));
	double x, y, z;
	v >> x;
	v >> y;
	v >> z;
	Vec3 tmp_normal(x, y, z);
	tmp_normals.push_back(tmp_normal);
	return true;
}

bool	getFaces(std::string line, std::vector<unsigned int> &vertexIndices, std::vector<unsigned int> &uvIndices, std::vector<unsigned int> &normalIndices)
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
	return true;
}

bool loadOBJ(const char *path, std::vector<Vec3> &out_vertices, std::vector<Vec2> &out_uvs, std::vector <Vec3> &out_normals)
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
			getVertices(line, tmp_vertices);
		}
		else if (line.substr(0, 2) == "vt")
		{
			getVertexTexture(line, tmp_uvs);
		}
		else if (line.substr(0, 2) == "vn")
		{
			getNormals(line, tmp_normals);
		}
		else if (line.substr(0, 2) == "f ")
		{
			getFaces(line, vertexIndices, uvIndices, normalIndices);
		}

		// std::cout << "VERTICES:" << std::endl;
		// for (int i = 0; i < tmp_vertices.size(); i++)
		// 	std::cout << tmp_vertices[i].x << " " << tmp_vertices[i].y << " " << tmp_vertices[i].z << std::endl;
		// std::cout << std::endl;
		
		// std::cout << "VERTEX TEXTURES:" << std::endl;
		// for (int i = 0; i < tmp_uvs.size(); i++)
		// 	std::cout << tmp_uvs[i].x << " " << tmp_uvs[i].y << std::endl;
		// std::cout << std::endl;

		// std::cout << "NORMALS:" << std::endl;
		// for (int i = 0; i < tmp_normals.size(); i++)
		// 	std::cout << tmp_normals[i].x << " " << tmp_normals[i].y << " " << tmp_normals[i].z << std::endl;
		// std::cout << std::endl;
	}
	for (unsigned int i = 0; i < vertexIndices.size(); i++)
	{
		unsigned int vIdx = vertexIndices[i];
		Vec3 vertex = tmp_vertices[vIdx - 1];
		out_vertices.push_back(vertex);
	}

	for (unsigned int i = 0; i < uvIndices.size(); i++)
	{
		unsigned int uvIdx = uvIndices[i];
		Vec2 uv = tmp_uvs[uvIdx - 1];
		out_uvs.push_back(uv);
	}

	for (unsigned int i = 0; i < normalIndices.size(); i++)
	{
		unsigned int nIdx = normalIndices[i];
		Vec3 normal = tmp_normals[nIdx - 1];
		out_normals.push_back(normal);
	}
	return true;
}