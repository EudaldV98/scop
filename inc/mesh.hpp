/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:48:07 by jvaquer           #+#    #+#             */
/*   Updated: 2023/01/30 15:46:32 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_HPP
# define MESH_HPP

#include "utils.hpp"

class Mesh
{
    private:
        std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
        std::vector<Vec3> tmp_vertices;
        std::vector<Vec2> tmp_uvs;
        std::vector<Vec3> tmp_normals;
        
        std::vector<Vec3> out_vertices;
        std::vector<Vec2> out_uvs;
        std::vector <Vec3>  out_normals
    
    public:
        Mesh(/* args */);
        void loadObj(const char *path);
        ~Mesh();
};

#endif