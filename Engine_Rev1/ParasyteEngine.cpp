
#include "ParasyteEngine.h"






void ParasyteEngine::LoadScene(Scene* scene)
{}






void ParasyteEngine::StartUp() 
{
	//Setup GLFW Window Context
	//Initialize GLFW Init
	Utils::Log(LogType::Info, "Initializing GLFW...");
	if (!glfwInit())
	{
		Utils::Log(LogType::Error, "Failed to initialize GLFW");
		return;
	}
	Utils::Log("Success\n");
	
	//Setup Window Context
	SetupWindow();

	//Initialize Engine Modules/Managers
	
	

}

static const GLfloat g_vertex_buffer_data[] = {
	-1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	0.0f,  1.0f, 0.0f,
};

void ParasyteEngine::Run() 
{
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	//Create Vertex Array Object
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);





	// This will identify our vertex buffer
	GLuint vertexbuffer;
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	//Load Shaders
	GLuint programID = Utils::LoadShaders("Shaders/SimpleVertexShader.vert", "Shaders/SimpleFragmentShader.frag");

	//Game Loop
	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);


	do {
		this->Update();
		this->Render(programID,vertexbuffer);
		glfwPollEvents();
	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

}


void ParasyteEngine::Update() 
{

}



void ParasyteEngine::Render(GLuint programID, GLuint vertexBuffer)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Switch to Shader
	glUseProgram(programID);
	
	
	//Plot Geometry
	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);


	
	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
	glDisableVertexAttribArray(0);


	

	
	// Swap buffers
	glfwSwapBuffers(window);
}



void ParasyteEngine::ShutDown() {}
void ParasyteEngine::SetupWindow() 
{
	//GLFW window setup
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

	this->window = glfwCreateWindow(1024, 768, "ParasyteEngine", NULL, NULL);
	Utils::Log(LogType::Info, "Initializing GLFW Window...");
	if (window == NULL)
	{
		Utils::Log(LogType::Error, "Failed to open GLFW window.");
		glfwTerminate();
		return;
	}
	Utils::Log("Success\n");


	glfwMakeContextCurrent(window); // Initialize GLEW
	glewExperimental = true; // Needed in core profile

	Utils::Log(LogType::Info, "Initializing GLEW...");
	if (glewInit() != GLEW_OK) {
		Utils::Log(LogType::Error, "Failed to initialize GLEW");
		return;
	}
	Utils::Log("Success\n");
}

ParasyteEngine::ParasyteEngine() {}
ParasyteEngine::~ParasyteEngine() {}