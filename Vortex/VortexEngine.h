#pragma once

// --- Libraries -------------------------------
#include <string>
#include <sstream>
#include <fstream>
// ---------------------------------------------


// --- Core ------------------------------------
#include "src/Core/Core.h"
// ---------------------------------------------


// --- Application -----------------------------
#include "src/Core/Application.h"
#include "src/Core/Window.h"
#include "src/Core/Events.h"
// ---------------------------------------------


// --- glfw ------------------------------------
#include <glfw3.h>
// ---------------------------------------------


// --- glew ------------------------------------
#include <GL/glew.h>
// ---------------------------------------------


// --- Math ------------------------------------
#include "src/Vendor/glm/glm.hpp"
using namespace glm;
#include "src/Vendor/glm/gtc/matrix_transform.hpp"
#include "src/Vendor/glm/gtc/constants.hpp"
// ---------------------------------------------


// --- Graphics --------------------------------
#include "src/Graphics/GraphicsCore.h"
#include "src/Graphics/Renderer/Renderer.h"
#include "src/Graphics/Renderer/Buffer.h"
#include "src/Graphics/Renderer/VertexArray.h"
#include "src/Graphics/Renderer/ShaderProgram.h"
#include "src/Graphics/Renderer/VertexBufferLayout.h"
#include "src/Graphics/Texture.h"
#include "src/Graphics/Camera.h"
// ---------------------------------------------