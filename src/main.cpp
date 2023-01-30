/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:51:42 by jvaquer           #+#    #+#             */
/*   Updated: 2023/01/30 17:03:16 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.hpp"
#include "../inc/scop.hpp"

int     main(void)
{
	// Read our .obj file
	Scop scop;
	std::vector<Vec3> vertices;
	std::vector<Vec2> uvs;
	std::vector<Vec3> normals; // Won't be used at the moment.
	bool res = loadOBJ("../resources/test.obj", vertices, uvs, normals);
	scop.render(vertices);
	return 0;
}