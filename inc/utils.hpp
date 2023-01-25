/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:42:33 by jvaquer           #+#    #+#             */
/*   Updated: 2023/01/25 10:23:48 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <glad/glad.h>
# include <GLFW/glfw3.h>
# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <iostream>
# include <cerrno>
# include <cmath>
# include <vector>

# include "vec3.hpp"
# include "vec2.hpp"
# include "parser/parser.hpp"

void	framebuffer_size_callback(GLFWwindow* window, int width, int height);
void 	processInput(GLFWwindow *window);

// settings
const	unsigned int SCR_WIDTH = 800;
const	unsigned int SCR_HEIGHT = 800;

void	processInput(GLFWwindow *window);
void	framebuffer_size_callback(GLFWwindow* window, int width, int height);

#endif