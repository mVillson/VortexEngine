#pragma once

#include "Core.h"
#include "Window.h"
#include <glfw3.h>

namespace vtx {
	class VORTEX_API Event
	{
	protected:
		Window* mWindow;
	public:
		// WindowSetter
		void SetWindow(Window* window) { mWindow = window; }
	};

	class VORTEX_API InputEvent : public Event
	{
	private:
	public:
		// KeyCallbackSetter
		void SetKeyCallbackFunction(void (*callback)(GLFWwindow* window, int key, int scancode, int action, int mods));

		// input
		bool GetKeyDown(int KeyCode);
		bool GetKeyRelease(int KeyCode);
	};

	class VORTEX_API WindowEvent : public Event
	{
	private:
	public:
		// KeyCallbackSetter
		void SetFrameBuffersizeCallback(void (*callback)(GLFWwindow* window, int width, int height));
	};

	struct VORTEX_API Action
	{
		int PRESS = 1;
		int RELEASE = 0;
		int REPEAT = 2;
	};

	struct VORTEX_API KeyCode
	{
		int UNKNOWN = -1;
		int SPACE = 32;
		int APOSTROPHE = 39; /* ' */
		int COMMA = 44; /* , */
		int MINUS = 45; /* - */
		int PERIOD = 46; /* . */
		int SLASH = 47; /* / */
		int ZERO = 48;
		int ONE = 49;
		int TWO = 50;
		int THREE = 51;
		int FOUR = 52;
		int FIVE = 53;
		int SIX = 54;
		int SEVEN = 55;
		int EIGHT = 56;
		int NINE = 57;
		int SEMICOLON = 59; /* ; */
		int EQUAL = 61; /* = */
		int A = 65;
		int B = 66;
		int C = 67;
		int D = 68;
		int E = 69;
		int F = 70;
		int G = 71;
		int H = 72;
		int I = 73;
		int J = 74;
		int K = 75;
		int L = 76;
		int M = 77;
		int N = 78;
		int O = 79;
		int P = 80;
		int Q = 81;
		int R = 82;
		int S = 83;
		int T = 84;
		int U = 85;
		int V = 86;
		int W = 87;
		int X = 88;
		int Y = 89;
		int Z = 90;
		int LEFT_BRACKET = 91; /* [ */
		int BACKSLASH = 92; /* \ */
		int RIGHT_BRACKET = 93; /* ] */
		int GRAVE_ACCENT = 96; /* ` */
		int WORLD_1 = 161; /* non-US #1 */
		int WORLD_2 = 162; /* non-US #2 */
		int ESCAPE = 256;
		int ENTER = 257;
		int TAB = 258;
		int BACKSPACE = 259;
		int INSERT = 260;
		int DELETE = 261;
		int RIGHT = 262;
		int LEFT = 263;
		int DOWN = 264;
		int UP = 265;
		int PAGE_UP = 266;
		int PAGE_DOWN = 267;
		int HOME = 268;
		int END = 269;
		int CAPS_LOCK = 280;
		int SCROLL_LOCK = 281;
		int NUM_LOCK = 282;
		int PRINT_SCREEN = 283;
		int PAUSE = 284;
		int F1 = 290;
		int F2 = 291;
		int F3 = 292;
		int F4 = 293;
		int F5 = 294;
		int F6 = 295;
		int F7 = 296;
		int F8 = 297;
		int F9 = 298;
		int F10 = 299;
		int F11 = 300;
		int F12 = 301;
		int F13 = 302;
		int F14 = 303;
		int F15 = 304;
		int F16 = 305;
		int F17 = 306;
		int F18 = 307;
		int F19 = 308;
		int F20 = 309;
		int F21 = 310;
		int F22 = 311;
		int F23 = 312;
		int F24 = 313;
		int F25 = 314;
		int KP_0 = 320;
		int KP_1 = 321;
		int KP_2 = 322;
		int KP_3 = 323;
		int KP_4 = 324;
		int KP_5 = 325;
		int KP_6 = 326;
		int KP_7 = 327;
		int KP_8 = 328;
		int KP_9 = 329;
		int KP_DECIMAL = 330;
		int KP_DIVIDE = 331;
		int KP_MULTIPLY = 332;
		int KP_SUBTRACT = 333;
		int KP_ADD = 334;
		int KP_ENTER = 335;
		int KP_EQUAL = 336;
		int LEFT_SHIFT = 340;
		int LEFT_CONTROL = 341;
		int LEFT_ALT = 342;
		int LEFT_SUPER = 343;
		int RIGHT_SHIFT = 344;
		int RIGHT_CONTROL = 345;
		int RIGHT_ALT = 346;
		int RIGHT_SUPER = 347;
		int MENU = 348;
	};

}

vtx::InputEvent InputEvent;

vtx::KeyCode KeyCode;

vtx::Action Action;

vtx::WindowEvent WindowEvent;