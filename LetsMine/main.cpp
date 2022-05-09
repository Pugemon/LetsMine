//
//  main.cpp
//  LetsMine
//
//  Created by Pugemon on 08.05.22.
//  Copyright © 2022 Pugemon. All rights reserved.
//

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


int main()
{
	//Инициализация GLFW
	glfwInit();
		if (!glfwInit())
		{
			std::cout << "Failed to initialisation GLFW" << std::endl;
		}
	
	//Настройка GLFW
	//Задается минимальная требуемая версия OpenGL.
	//Мажорная
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//Минорная
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//Установка профайла для которого создается контекст
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//Выключение возможности изменения размера окна
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE); // Mac
#endif
	
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
		if (window == nullptr)
		{
			std::cout << "Failed to create GLFW window!" << std::endl;
			glfwTerminate();
			return -1;
		}
	glfwMakeContextCurrent(window);
	
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}
	
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	
	glfwTerminate();
	return 0;
}
