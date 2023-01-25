/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:54:45 by jvaquer           #+#    #+#             */
/*   Updated: 2023/01/25 10:26:09 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJLOADER_HPP
# define OBJLOADER_HPP

# include "utils.hpp"

bool loadOBJ(const char *path, std::vector<Vec3> & out_vertices, std::vector<Vec2> & out_uvs, std::vector <Vec3> & out_normals);

#endif