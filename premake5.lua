-- premake5.lua
workspace "Bomberman"
   configurations { "Debug", "Release" }

   platforms { "x32", "x64" }

	platforms {
      "x32",
      "x64"
   }

   filter "platforms:x32"
      architecture "x32"

   filter "platforms:x64"
      architecture "x64"   

   project "Bomberman"
      kind "ConsoleApp"
      language "C++"

      targetdir "bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
      objdir    "build/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"

      MATH_PATH = "src/math/"
      GAME_PATH = "src/game/"
      files {
         MATH_PATH .. "**.h", MATH_PATH .. "**.cpp",
         GAME_PATH .. "**.h", GAME_PATH .. "**.cpp",
      }

      links {
         "SDL2"
      }

      includedirs {
         MATH_PATH,
         GAME_PATH,
         "3rd",
         "3rd/SDL2/include",
      }

      filter "system:windows"
         libdirs { "3rd/SDl2/lib/x64" }
         -- copy a file from the objects directory to the target directory
         prebuildcommands {
            "{COPY} 3rd/SDL2/lib/x64/SDL2.dll %{cfg.targetdir}"
         } 
 
      filter "configurations:Debug"
         defines { "DEBUG" }
         symbols "On"

      filter "configurations:Release"
         defines { "NDEBUG" }
         optimize "On"

 
