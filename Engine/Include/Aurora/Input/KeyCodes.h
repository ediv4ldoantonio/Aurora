#pragma once

#include <cstdint>

namespace Aurora
{

    using KeyCode = uint16_t;

    namespace Key
    {

        // Unknown

        constexpr KeyCode Unknown = 0;

        // Letters

        constexpr KeyCode A = 'A';
        constexpr KeyCode B = 'B';
        constexpr KeyCode C = 'C';
        constexpr KeyCode D = 'D';
        constexpr KeyCode E = 'E';
        constexpr KeyCode F = 'F';
        constexpr KeyCode G = 'G';
        constexpr KeyCode H = 'H';
        constexpr KeyCode I = 'I';
        constexpr KeyCode J = 'J';
        constexpr KeyCode K = 'K';
        constexpr KeyCode L = 'L';
        constexpr KeyCode M = 'M';
        constexpr KeyCode N = 'N';
        constexpr KeyCode O = 'O';
        constexpr KeyCode P = 'P';
        constexpr KeyCode Q = 'Q';
        constexpr KeyCode R = 'R';
        constexpr KeyCode S = 'S';
        constexpr KeyCode T = 'T';
        constexpr KeyCode U = 'U';
        constexpr KeyCode V = 'V';
        constexpr KeyCode W = 'W';
        constexpr KeyCode X = 'X';
        constexpr KeyCode Y = 'Y';
        constexpr KeyCode Z = 'Z';

        // Numbers

        constexpr KeyCode Num0 = '0';
        constexpr KeyCode Num1 = '1';
        constexpr KeyCode Num2 = '2';
        constexpr KeyCode Num3 = '3';
        constexpr KeyCode Num4 = '4';
        constexpr KeyCode Num5 = '5';
        constexpr KeyCode Num6 = '6';
        constexpr KeyCode Num7 = '7';
        constexpr KeyCode Num8 = '8';
        constexpr KeyCode Num9 = '9';

        // Function keys

        constexpr KeyCode F1 = 256;
        constexpr KeyCode F2 = 257;
        constexpr KeyCode F3 = 258;
        constexpr KeyCode F4 = 259;
        constexpr KeyCode F5 = 260;
        constexpr KeyCode F6 = 261;
        constexpr KeyCode F7 = 262;
        constexpr KeyCode F8 = 263;
        constexpr KeyCode F9 = 264;
        constexpr KeyCode F10 = 265;
        constexpr KeyCode F11 = 266;
        constexpr KeyCode F12 = 267;

        // Modifiers

        constexpr KeyCode LeftShift = 300;
        constexpr KeyCode RightShift = 301;

        constexpr KeyCode LeftControl = 302;
        constexpr KeyCode RightControl = 303;

        constexpr KeyCode LeftAlt = 304;
        constexpr KeyCode RightAlt = 305;

        // Arrows

        constexpr KeyCode Up = 400;
        constexpr KeyCode Down = 401;
        constexpr KeyCode Left = 402;
        constexpr KeyCode Right = 403;

        // Space and common keys

        constexpr KeyCode Space = 500;
        constexpr KeyCode Enter = 501;
        constexpr KeyCode Escape = 502;
        constexpr KeyCode Backspace = 503;
        constexpr KeyCode Tab = 504;

    }

}