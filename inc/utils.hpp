/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:42:33 by jvaquer           #+#    #+#             */
/*   Updated: 2022/12/01 10:49:07 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <glad/glad.h>
# include <GLFW/glfw3.h>
# include <iostream>

void	framebuffer_size_callback(GLFWwindow* window, int width, int height);
void 	processInput(GLFWwindow *window);

// settings
const	unsigned int SCR_WIDTH = 800;
const	unsigned int SCR_HEIGHT = 800;

void	processInput(GLFWwindow *window);
void	framebuffer_size_callback(GLFWwindow* window, int width, int height);

#endif