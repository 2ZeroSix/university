cmake_minimum_required(VERSION 3.8)
project(GraphicsEngine)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Sources/GraphicsEngine/GraphicsApi/DirectX11/DX11.h
        Sources/GraphicsEngine/GraphicsApi/DirectX11/DX11ConstantBuffer.cpp
        Sources/GraphicsEngine/GraphicsApi/DirectX11/DX11ConstantBuffer.h
        Sources/GraphicsEngine/GraphicsApi/DirectX11/DX11GraphicsEngine.cpp
        Sources/GraphicsEngine/GraphicsApi/DirectX11/DX11GraphicsEngine.h
        Sources/GraphicsEngine/GraphicsApi/DirectX11/DX11GraphicsEngineContext.h
        Sources/GraphicsEngine/GraphicsApi/DirectX11/DX11GraphicsEngineFabric.cpp
        Sources/GraphicsEngine/GraphicsApi/DirectX11/DX11GraphicsEngineFabric.h
        Sources/GraphicsEngine/GraphicsApi/DirectX11/DX11GUI.cpp
        Sources/GraphicsEngine/GraphicsApi/DirectX11/DX11GUI.h
        Sources/GraphicsEngine/GraphicsApi/DirectX11/DX11Material.cpp
        Sources/GraphicsEngine/GraphicsApi/DirectX11/DX11Material.h
        Sources/GraphicsEngine/GraphicsApi/DirectX11/DX11Mesh.cpp
        Sources/GraphicsEngine/GraphicsApi/DirectX11/DX11Mesh.h
        Sources/GraphicsEngine/GraphicsApi/DirectX11/DX11PixelShader.cpp
        Sources/GraphicsEngine/GraphicsApi/DirectX11/DX11PixelShader.h
        Sources/GraphicsEngine/GraphicsApi/DirectX11/DX11Texture2D.cpp
        Sources/GraphicsEngine/GraphicsApi/DirectX11/DX11Texture2D.h
        Sources/GraphicsEngine/GraphicsApi/DirectX11/DX11VertexShader.cpp
        Sources/GraphicsEngine/GraphicsApi/DirectX11/DX11VertexShader.h
        Sources/GraphicsEngine/GraphicsApi/DirectX9/DX9.h
        Sources/GraphicsEngine/GraphicsApi/DirectX9/DX9Convert.h
        Sources/GraphicsEngine/GraphicsApi/DirectX9/DX9FixedFunctionPipeline.cpp
        Sources/GraphicsEngine/GraphicsApi/DirectX9/DX9FixedFunctionPipeline.h
        Sources/GraphicsEngine/GraphicsApi/DirectX9/DX9GraphicsEngine.cpp
        Sources/GraphicsEngine/GraphicsApi/DirectX9/DX9GraphicsEngine.h
        Sources/GraphicsEngine/GraphicsApi/DirectX9/DX9GraphicsEngineContext.h
        Sources/GraphicsEngine/GraphicsApi/DirectX9/DX9GraphicsEngineFabric.cpp
        Sources/GraphicsEngine/GraphicsApi/DirectX9/DX9GraphicsEngineFabric.h
        Sources/GraphicsEngine/GraphicsApi/DirectX9/DX9GUI.cpp
        Sources/GraphicsEngine/GraphicsApi/DirectX9/DX9GUI.h
        Sources/GraphicsEngine/GraphicsApi/DirectX9/DX9Material.cpp
        Sources/GraphicsEngine/GraphicsApi/DirectX9/DX9Material.h
        Sources/GraphicsEngine/GraphicsApi/DirectX9/DX9Mesh.cpp
        Sources/GraphicsEngine/GraphicsApi/DirectX9/DX9Mesh.h
        Sources/GraphicsEngine/GraphicsApi/DirectX9/DX9PixelShader.cpp
        Sources/GraphicsEngine/GraphicsApi/DirectX9/DX9PixelShader.h
        Sources/GraphicsEngine/GraphicsApi/DirectX9/DX9Texture2D.cpp
        Sources/GraphicsEngine/GraphicsApi/DirectX9/DX9Texture2D.h
        Sources/GraphicsEngine/GraphicsApi/DirectX9/DX9VertexShader.cpp
        Sources/GraphicsEngine/GraphicsApi/DirectX9/DX9VertexShader.h
        Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20.h
        Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20Convert.h
        Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20GraphicsEngine.cpp
        Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20GraphicsEngine.cpp.bak
        Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20GraphicsEngine.h
        Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20GraphicsEngineFabric.cpp
        Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20GraphicsEngineFabric.h
        Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20GUI.cpp
        Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20GUI.h
        Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20Input.cpp
        Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20Input.h
        Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20Material.cpp
        Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20Material.h
        Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20Mesh.cpp
        Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20Mesh.h
        Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20Texture2D.cpp
        Sources/GraphicsEngine/GraphicsApi/OpenGL20/GL20Texture2D.h
        Sources/GraphicsEngine/GraphicsApi/FixedFunctionPipelineImpl.h
        Sources/GraphicsEngine/GraphicsApi/GraphicsEngineContext.h
        Sources/GraphicsEngine/GraphicsApi/GraphicsEngineFabricImpl.h
        Sources/GraphicsEngine/GraphicsApi/GraphicsEngineImpl.h
        Sources/GraphicsEngine/GraphicsApi/GUIImpl.h
        Sources/GraphicsEngine/GraphicsApi/MaterialImpl.h
        Sources/GraphicsEngine/GraphicsApi/MeshImpl.h
        Sources/GraphicsEngine/GraphicsApi/PixelShaderImpl.h
        Sources/GraphicsEngine/GraphicsApi/Texture2DImpl.h
        Sources/GraphicsEngine/GraphicsApi/VertexShaderImpl.h
        Sources/GraphicsEngine/Internal/InternalInput.cpp
        Sources/GraphicsEngine/Internal/InternalInput.h
        Sources/GraphicsEngine/Materials/Material.cpp
        Sources/GraphicsEngine/Materials/Material.h
        Sources/GraphicsEngine/Materials/MaterialDiffuse.cpp
        Sources/GraphicsEngine/Materials/MaterialDiffuse.h
        Sources/GraphicsEngine/Materials/MaterialSand.cpp
        Sources/GraphicsEngine/Materials/MaterialSand.h
        Sources/GraphicsEngine/Materials/MaterialTask01.cpp
        Sources/GraphicsEngine/Materials/MaterialTask01.h
        Sources/GraphicsEngine/Materials/MaterialUnlit.cpp
        Sources/GraphicsEngine/Materials/MaterialUnlit.h
        Sources/GraphicsEngine/Meshes/Mesh.cpp
        Sources/GraphicsEngine/Meshes/Mesh.h
        Sources/GraphicsEngine/Meshes/MeshCube.cpp
        Sources/GraphicsEngine/Meshes/MeshCube.h
        Sources/GraphicsEngine/Meshes/MeshCylinder.cpp
        Sources/GraphicsEngine/Meshes/MeshCylinder.h
        Sources/GraphicsEngine/Meshes/MeshObjFile.cpp
        Sources/GraphicsEngine/Meshes/MeshObjFile.h
        Sources/GraphicsEngine/Meshes/MeshQuad.cpp
        Sources/GraphicsEngine/Meshes/MeshQuad.h
        Sources/GraphicsEngine/Meshes/MeshSphere.cpp
        Sources/GraphicsEngine/Meshes/MeshSphere.h
        Sources/GraphicsEngine/Meshes/MeshTriangle.cpp
        Sources/GraphicsEngine/Meshes/MeshTriangle.h
        Sources/GraphicsEngine/PlatformApi/Windows/WinInput.cpp
        Sources/GraphicsEngine/PlatformApi/Windows/WinInput.h
        Sources/GraphicsEngine/PlatformApi/Windows/WinWindow.cpp
        Sources/GraphicsEngine/PlatformApi/Windows/WinWindow.h
        Sources/GraphicsEngine/PlatformApi/Platform.h
        Sources/GraphicsEngine/Shaders/DX11/ShaderDiffuse.fx
        Sources/GraphicsEngine/Shaders/DX11/ShaderSand.fx
        Sources/GraphicsEngine/Shaders/DX11/ShaderUnlit.fx
        Sources/GraphicsEngine/Shaders/DX9/ShaderDiffuse.ps
        Sources/GraphicsEngine/Shaders/DX9/ShaderDiffuse.vs
        Sources/GraphicsEngine/Shaders/DX9/ShaderSand.ps
        Sources/GraphicsEngine/Shaders/DX9/ShaderSand.vs
        Sources/GraphicsEngine/Shaders/DX9/ShaderUnlit.ps
        Sources/GraphicsEngine/Shaders/DX9/ShaderUnlit.vs
        Sources/GraphicsEngine/Shaders/GL20/ShaderDiffuse.fs
        Sources/GraphicsEngine/Shaders/GL20/ShaderDiffuse.vs
        Sources/GraphicsEngine/Shaders/GL20/ShaderSand.fs
        Sources/GraphicsEngine/Shaders/GL20/ShaderSand.vs
        Sources/GraphicsEngine/Shaders/GL20/ShaderUnlit.fs
        Sources/GraphicsEngine/Shaders/GL20/ShaderUnlit.vs
        Sources/GraphicsEngine/Application.cpp
        Sources/GraphicsEngine/Application.h
        Sources/GraphicsEngine/Camera.cpp
        Sources/GraphicsEngine/Camera.h
        Sources/GraphicsEngine/Component.h
        Sources/GraphicsEngine/Directory.cpp
        Sources/GraphicsEngine/Directory.h
        Sources/GraphicsEngine/File.h
        Sources/GraphicsEngine/GraphicsEngine.cpp
        Sources/GraphicsEngine/GraphicsEngine.h
        Sources/GraphicsEngine/GraphicsEngineFabric.cpp
        Sources/GraphicsEngine/GraphicsEngineFabric.h
        Sources/GraphicsEngine/GUI.cpp
        Sources/GraphicsEngine/GUI.h
        Sources/GraphicsEngine/Input.cpp
        Sources/GraphicsEngine/Input.h
        Sources/GraphicsEngine/KeyCode.h
        Sources/GraphicsEngine/Light.h
        Sources/GraphicsEngine/Math.h
        Sources/GraphicsEngine/MathConstants.h
        Sources/GraphicsEngine/MathUtils.h
        Sources/GraphicsEngine/Matrix4x4.h
        Sources/GraphicsEngine/Object.cpp
        Sources/GraphicsEngine/Object.h
        Sources/GraphicsEngine/Rect.h
        Sources/GraphicsEngine/resource.h
        Sources/GraphicsEngine/Scene.cpp
        Sources/GraphicsEngine/Scene.h
        Sources/GraphicsEngine/SceneUtils.h
        Sources/GraphicsEngine/Screen.cpp
        Sources/GraphicsEngine/Screen.h
        Sources/GraphicsEngine/Texture2D.cpp
        Sources/GraphicsEngine/Texture2D.h
        Sources/GraphicsEngine/Time.cpp
        Sources/GraphicsEngine/Time.h
        Sources/GraphicsEngine/Transform.cpp
        Sources/GraphicsEngine/Transform.h
        Sources/GraphicsEngine/tstring.h
        Sources/GraphicsEngine/Vector3.cpp
        Sources/GraphicsEngine/Vector3.h
        Sources/GraphicsEngine/Vector4.h
        Sources/Tasks/CameraController.h
        Sources/Tasks/ObjectRotator.h
        Sources/Tasks/Task.h
        Sources/Tasks/Task01.h
        Sources/Tasks/Task04.h
        Sources/Tasks/Task05_01.h
        Sources/Tasks/Task08.h
        Sources/main.cpp Sources/Tasks/Task02.h Sources/GraphicsEngine/Materials/MaterialCubeSphere.h Sources/GraphicsEngine/Materials/MaterialCubeSphere.cpp Sources/GraphicsEngine/Materials/MaterialCylinderTwist.cpp Sources/GraphicsEngine/Materials/MaterialCylinderTwist.h Sources/GraphicsEngine/Materials/Stageable.h Sources/GraphicsEngine/LightSpot.h Sources/GraphicsEngine/LightPoint.h Sources/GraphicsEngine/LightDirect.h)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

IF (WIN32)
    FIND_PATH( FREEIMAGE_INCLUDE_DIRS FreeImage.h
        ${FREEIMAGE_ROOT_DIR}/include
        ${FREEIMAGE_ROOT_DIR}
        DOC "The directory where FreeImage.h resides")
    FIND_LIBRARY( FREEIMAGE_LIBRARY
        NAMES FreeImage freeimage
        PATHS
        ${FREEIMAGE_ROOT_DIR}/lib
        ${FREEIMAGE_ROOT_DIR})
ELSE (WIN32)
    FIND_PATH( FREEIMAGE_INCLUDE_DIRS FreeImage.h
        /usr/include
        /usr/local/include
        /sw/include
        /opt/local/include
        DOC "The directory where FreeImage.h resides")
    FIND_LIBRARY( FREEIMAGE_LIBRARY
        NAMES FreeImage freeimage libfreeimage libfreeimage-3.15.2
        PATHS
        /usr/lib64
        /usr/lib
        /usr/local/lib64
        /usr/local/lib
        /sw/lib
        /opt/local/lib
        DOC "The FreeImage library")
ENDIF (WIN32)


include_directories(Sources ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${FREEIMAGE_INCLUDE_DIRS})

add_executable(GraphicsEngine ${SOURCE_FILES} )
target_link_libraries(GraphicsEngine ${OPENGL_LIBRARIES}
        ${GLUT_LIBRARY} ${GLEW_LIBRARY} ${FREEIMAGE_LIBRARY})
