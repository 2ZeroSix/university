#include "MeshObjFile.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <functional>

//// A structure for our custom vertex type


//bool ConstructCustomVertex(CUSTOMVERTEX & out,
//						   size_t pIdx, const std::vector<Vector3> & vertices,
//						   size_t nIdx, const std::vector<Vector3> & normals,
//						   size_t tIdx, const std::vector<Vector3> & textCoords)
//{
//	pIdx = pIdx - 1;
//	nIdx = nIdx - 1;
//	tIdx = tIdx - 1;
//
//	if (pIdx < vertices.size() && nIdx < normals.size() && tIdx < textCoords.size())
//	{
//		Vector3 position	= vertices  [pIdx];
//		Vector3 normal		= normals   [nIdx];
//		Vector3 uv1		= textCoords[tIdx];
//
//		out.x	= position.x;
//		out.y	= position.y;
//		out.z	= position.z;
//
//		out.u1	= uv1.x;
//		out.v1	= uv1.y;
//
//		out.nx	= normal.x;
//		out.ny	= normal.y;
//		out.nz	= normal.z;
//
//		return true;
//	}
//
//	return false;
//}
//
//// Our custom FVF, which describes our custom vertex structure
//#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1 | D3DFVF_TEXCOORDSIZE4(0))
//
MeshObjFile::MeshObjFile(std::string pFilepath)
{
	m_pFilepath = pFilepath;
}
struct Vertex{
    Vector3 v;
    Vector3 n;
    Vector3 t;
    int ind;
    bool operator==(const Vertex &rhs) const {
        return v == rhs.v &&
               n == rhs.n &&
               t == rhs.t;
    }

    bool operator!=(const Vertex &rhs) const {
        return !(rhs == *this);
    }
    struct VertexHash {
        size_t operator()(const Vertex& a) const{
            return std::hash<double>()(std::hash<double>()(a.v.x+a.v.y+a.v.z) + std::hash<double>()(a.n.x+a.n.y+a.n.z) + std::hash<double>()(a.t.x+a.t.y+a.t.z));
        }
    };
};
void MeshObjFile::Init()
{
	ReadAllTriangles();

    Mesh::Init();
	std::vector<Vector3> vertices;
	std::vector<Vector3> norms;
	std::vector<Vector3> texcs;
	size_t ind = 0;
    std::unordered_set<Vertex, Vertex::VertexHash> vertexes;
	for (auto& triangle : m_triangles) {
        Vertex vertex{m_vertices[triangle.v1Idx-1], m_normals[triangle.n1Idx-1], Vector3(1.0, 1.0, 1.0) -  m_textCoords[triangle.t1Idx-1]};
        auto iter = vertexes.find(vertex);
        if (iter == vertexes.end()) {
            vertices.emplace_back(vertex.v);
            norms.emplace_back(vertex.n);
            texcs.emplace_back(vertex.t);
            vertex.ind = ind;
            m_indices.emplace_back(ind++);
            vertexes.insert(vertex);
        } else {
            m_indices.emplace_back(iter->ind);
        }
        vertex = Vertex{m_vertices[triangle.v2Idx-1], m_normals[triangle.n2Idx-1], Vector3(1.0, 1.0, 1.0) - m_textCoords[triangle.t2Idx-1]};
        iter = vertexes.find(vertex);
        if (iter == vertexes.end()) {
            vertices.emplace_back(vertex.v);
            norms.emplace_back(vertex.n);
            texcs.emplace_back(vertex.t);
            vertex.ind = ind;
            m_indices.emplace_back(ind++);
            vertexes.insert(vertex);
        } else {
            m_indices.emplace_back(iter->ind);
        }
        vertex = Vertex{m_vertices[triangle.v3Idx-1], m_normals[triangle.n3Idx-1], Vector3(1.0, 1.0, 1.0) - m_textCoords[triangle.t3Idx-1]};
        iter = vertexes.find(vertex);
        if (iter == vertexes.end()) {
            vertices.emplace_back(vertex.v);
            norms.emplace_back(vertex.n);
            texcs.emplace_back(vertex.t);
            vertex.ind = ind;
            m_indices.emplace_back(ind++);
            vertexes.insert(vertex);
        } else {
            m_indices.emplace_back(iter->ind);
        }
//        std::cout << triangle.v1Idx << " " << triangle.v2Idx << " " << triangle.v3Idx << ";"
//                  << triangle.t1Idx << " " << triangle.t2Idx << " " << triangle.t3Idx << ";"
//                  << triangle.n1Idx << " " << triangle.n2Idx << " " << triangle.n3Idx << std::endl;
	}
//    (std::cout << "hi").flush();
//    m_vertices = vertices;
//    m_normals = norms;
//    m_textCoords = texcs;
//    m_colors = std::vector<Vector4>(m_vertices.size(), Vector4(1.0,1.0,1.0,1.0));
    meshImpl->SetVertices(vertices);
    meshImpl->SetNormals(norms);
//    meshImpl->SetColors(m_colors);
    meshImpl->SetUV0(texcs);
    meshImpl->SetIndices(m_indices, MeshTopology::MESH_TOPOLOGY_TRIANGLE_LIST);
    meshImpl->Apply();
    m_vertices.resize(0);
    m_normals.resize(0);
    m_textCoords.resize(0);
    m_indices.resize(0);
}

void MeshObjFile::Deinit()
{
	Mesh::Deinit();
}

void MeshObjFile::ReadAllTriangles()
{
	std::ifstream file;
	file.open(m_pFilepath);

	const std::string vPosition("v ");
	const std::string vNormal("vn");
	const std::string vTextureCoords("vt");
	const std::string vTriangle("f ");
	std::string line;

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			if (line.length() < 2) continue;

			std::string cmd = line.substr(0, 2);
			if (cmd == vPosition)
			{
				// Пример строки cmd: "v -0.5 -0.5 0.5"
				std::string posStr = line.substr(2);
				Vector3 pos;

				if (ReadVector3(posStr, pos))
				{
					m_vertices.push_back(pos);
				}
			}
			else if (cmd == vNormal)
			{
				// Пример строки cmd: "vn 0 0 1"
				std::string normalStr = line.substr(2);
				Vector3 normal;

				if (ReadVector3(normalStr, normal))
				{
					m_normals.push_back(normal);
				}
			}
			else if (cmd == vTextureCoords)
			{
				// Пример строки cmd: "vt 0 0"
				std::string textCoordsStr = line.substr(2);
				Vector3 textCoords;

				if (ReadVector2(textCoordsStr, textCoords))
				{
					m_textCoords.push_back(textCoords);
				}
			}
			else if (cmd == vTriangle)
			{
				// Пример строки cmd: "f 2/2/2 4/4/4 1/1/1"
				std::string triangleStr = line.substr(2);
				TriangleInObjFile triangle{};

				if (ReadTriangle(triangleStr, triangle))
				{

					m_triangles.push_back(triangle);
				}
			} else {
//                std::cout <<  line << std::endl;
            }
		}

		file.close();
	}
}

bool MeshObjFile::ReadVector3(const std::string & line, Vector3 & vec)
{
	// Пример строки: "-0.5 -0.5 0.5"
	std::stringstream ss(line);

	try
	{
		ss >> vec.x >> vec.y >> vec.z;
	}
	catch (...)
	{
        (std::cout << "aaa1" << std::endl).flush();
        return false;
	}

	return true;
}

bool MeshObjFile::ReadVector2(const std::string & line, Vector3 & vec)
{
	// Пример строки: "0 0"
	std::stringstream ss(line);

	try
	{
		ss >> vec.x >> vec.y;
        vec.z = 0;
	}
	catch (...)
	{
        (std::cout << "aaa2" << std::endl).flush();
		return false;
	}

	return true;
}

bool MeshObjFile::ReadTriangle(const std::string & line, TriangleInObjFile & triangle)
{
	// Пример строки: "2/2/2 4/4/4 1/1/1"
	std::stringstream ss(line);

	try
	{
		char ch;

		ss >> triangle.v1Idx >> ch >> triangle.t1Idx >> ch >> triangle.n1Idx
           >> triangle.v2Idx >> ch >> triangle.t2Idx >> ch >> triangle.n2Idx
		   >> triangle.v3Idx >> ch >> triangle.t3Idx >> ch >> triangle.n3Idx;
	}
	catch (...)
	{
        (std::cout << "aaa3" << std::endl).flush();
		return false;
	}

	return true;
}
