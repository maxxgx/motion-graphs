#ifndef GRAPHICS_GLEXTENSIONS_HPP
#define GRAPHICS_GLEXTENSIONS_HPP
//This header is all about getting your extensions properly managed.
//It is automatically generated. Don't be editing!

#include <Graphics/Graphics.hpp>
#undef __glext_h_
#undef GL_GLEXT_VERSION
#include "glext.h"
#undef GL_GLEXT_VERSION //and after soas no to conflict with SDL (yes, this is hacky)

//Use this macro to request an extension: (that is, it may be loaded and it
//may not. Check with have().

#define REQUEST_GL_EXTENSION( NAME )  \
using namespace NAME ## _NAMESPACE;   \
namespace {                           \
class NAME ## _RequestClass {         \
public:                               \
	NAME ## _RequestClass() {         \
		NAME ## _INTERNALS::request(); \
	}                                 \
} NAME ## _request;                   \
} //end anon namespace

//Use this macro to require an extension: (code will fail in graphics::init()
//if macro used at global scope, otherwise inside function...)

#define REQUIRE_GL_EXTENSION( NAME )   \
using namespace NAME ## _NAMESPACE;    \
namespace {                            \
class NAME ## _RequireClass {          \
public:                                \
	NAME ## _RequireClass() {          \
		NAME ## _INTERNALS::require(); \
	}                                  \
} NAME ## _require;                    \
} //end anon namespace

//--------------------------------------------

//Now on to the guts of the thing...

//  ...for GL_APPLE_client_storage:
namespace GL_APPLE_client_storage_NAMESPACE {

	extern bool have_APPLE_client_storage(); //<- for your use.

	//internal book-keeping stuff:
	class GL_APPLE_client_storage_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_APPLE_client_storage_NAMESPACE

//  ...for GL_APPLE_element_array:
namespace GL_APPLE_element_array_NAMESPACE {
	extern PFNGLDRAWELEMENTARRAYAPPLEPROC glDrawElementArrayAPPLE;
	extern PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC glDrawRangeElementArrayAPPLE;
	extern PFNGLELEMENTPOINTERAPPLEPROC glElementPointerAPPLE;
	extern PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC glMultiDrawElementArrayAPPLE;
	extern PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC glMultiDrawRangeElementArrayAPPLE;

	extern bool have_APPLE_element_array(); //<- for your use.

	//internal book-keeping stuff:
	class GL_APPLE_element_array_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_APPLE_element_array_NAMESPACE

//  ...for GL_APPLE_fence:
namespace GL_APPLE_fence_NAMESPACE {
	extern PFNGLDELETEFENCESAPPLEPROC glDeleteFencesAPPLE;
	extern PFNGLFINISHFENCEAPPLEPROC glFinishFenceAPPLE;
	extern PFNGLFINISHOBJECTAPPLEPROC glFinishObjectAPPLE;
	extern PFNGLGENFENCESAPPLEPROC glGenFencesAPPLE;
	extern PFNGLISFENCEAPPLEPROC glIsFenceAPPLE;
	extern PFNGLSETFENCEAPPLEPROC glSetFenceAPPLE;
	extern PFNGLTESTFENCEAPPLEPROC glTestFenceAPPLE;
	extern PFNGLTESTOBJECTAPPLEPROC glTestObjectAPPLE;

	extern bool have_APPLE_fence(); //<- for your use.

	//internal book-keeping stuff:
	class GL_APPLE_fence_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_APPLE_fence_NAMESPACE

//  ...for GL_APPLE_specular_vector:
namespace GL_APPLE_specular_vector_NAMESPACE {

	extern bool have_APPLE_specular_vector(); //<- for your use.

	//internal book-keeping stuff:
	class GL_APPLE_specular_vector_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_APPLE_specular_vector_NAMESPACE

//  ...for GL_APPLE_transform_hint:
namespace GL_APPLE_transform_hint_NAMESPACE {

	extern bool have_APPLE_transform_hint(); //<- for your use.

	//internal book-keeping stuff:
	class GL_APPLE_transform_hint_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_APPLE_transform_hint_NAMESPACE

//  ...for GL_APPLE_vertex_array_object:
namespace GL_APPLE_vertex_array_object_NAMESPACE {
	extern PFNGLBINDVERTEXARRAYAPPLEPROC glBindVertexArrayAPPLE;
	extern PFNGLDELETEVERTEXARRAYSAPPLEPROC glDeleteVertexArraysAPPLE;
	extern PFNGLGENVERTEXARRAYSAPPLEPROC glGenVertexArraysAPPLE;
	extern PFNGLISVERTEXARRAYAPPLEPROC glIsVertexArrayAPPLE;

	extern bool have_APPLE_vertex_array_object(); //<- for your use.

	//internal book-keeping stuff:
	class GL_APPLE_vertex_array_object_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_APPLE_vertex_array_object_NAMESPACE

//  ...for GL_APPLE_vertex_array_range:
namespace GL_APPLE_vertex_array_range_NAMESPACE {
	extern PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC glFlushVertexArrayRangeAPPLE;
	extern PFNGLVERTEXARRAYPARAMETERIAPPLEPROC glVertexArrayParameteriAPPLE;
	extern PFNGLVERTEXARRAYRANGEAPPLEPROC glVertexArrayRangeAPPLE;

	extern bool have_APPLE_vertex_array_range(); //<- for your use.

	//internal book-keeping stuff:
	class GL_APPLE_vertex_array_range_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_APPLE_vertex_array_range_NAMESPACE

//  ...for GL_APPLE_ycbcr_422:
namespace GL_APPLE_ycbcr_422_NAMESPACE {

	extern bool have_APPLE_ycbcr_422(); //<- for your use.

	//internal book-keeping stuff:
	class GL_APPLE_ycbcr_422_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_APPLE_ycbcr_422_NAMESPACE

//  ...for GL_ARB_color_buffer_float:
namespace GL_ARB_color_buffer_float_NAMESPACE {
	extern PFNGLCLAMPCOLORARBPROC glClampColorARB;

	extern bool have_ARB_color_buffer_float(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_color_buffer_float_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_color_buffer_float_NAMESPACE

//  ...for GL_ARB_depth_texture:
namespace GL_ARB_depth_texture_NAMESPACE {

	extern bool have_ARB_depth_texture(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_depth_texture_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_depth_texture_NAMESPACE

//  ...for GL_ARB_draw_buffers:
namespace GL_ARB_draw_buffers_NAMESPACE {
	extern PFNGLDRAWBUFFERSARBPROC glDrawBuffersARB;

	extern bool have_ARB_draw_buffers(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_draw_buffers_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_draw_buffers_NAMESPACE

//  ...for GL_ARB_fragment_program:
namespace GL_ARB_fragment_program_NAMESPACE {

	extern bool have_ARB_fragment_program(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_fragment_program_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_fragment_program_NAMESPACE

//  ...for GL_ARB_fragment_program_shadow:
namespace GL_ARB_fragment_program_shadow_NAMESPACE {

	extern bool have_ARB_fragment_program_shadow(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_fragment_program_shadow_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_fragment_program_shadow_NAMESPACE

//  ...for GL_ARB_fragment_shader:
namespace GL_ARB_fragment_shader_NAMESPACE {

	extern bool have_ARB_fragment_shader(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_fragment_shader_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_fragment_shader_NAMESPACE

//  ...for GL_ARB_half_float_pixel:
namespace GL_ARB_half_float_pixel_NAMESPACE {

	extern bool have_ARB_half_float_pixel(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_half_float_pixel_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_half_float_pixel_NAMESPACE

//  ...for GL_ARB_imaging:
namespace GL_ARB_imaging_NAMESPACE {

	extern bool have_ARB_imaging(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_imaging_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_imaging_NAMESPACE

//  ...for GL_ARB_matrix_palette:
namespace GL_ARB_matrix_palette_NAMESPACE {
	extern PFNGLCURRENTPALETTEMATRIXARBPROC glCurrentPaletteMatrixARB;
	extern PFNGLMATRIXINDEXPOINTERARBPROC glMatrixIndexPointerARB;
	extern PFNGLMATRIXINDEXUBVARBPROC glMatrixIndexubvARB;
	extern PFNGLMATRIXINDEXUIVARBPROC glMatrixIndexuivARB;
	extern PFNGLMATRIXINDEXUSVARBPROC glMatrixIndexusvARB;

	extern bool have_ARB_matrix_palette(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_matrix_palette_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_matrix_palette_NAMESPACE

//  ...for GL_ARB_multisample:
namespace GL_ARB_multisample_NAMESPACE {
	extern PFNGLSAMPLECOVERAGEARBPROC glSampleCoverageARB;

	extern bool have_ARB_multisample(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_multisample_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_multisample_NAMESPACE

//  ...for GL_ARB_multitexture:
namespace GL_ARB_multitexture_NAMESPACE {
	extern PFNGLACTIVETEXTUREARBPROC glActiveTextureARB;
	extern PFNGLCLIENTACTIVETEXTUREARBPROC glClientActiveTextureARB;
	extern PFNGLMULTITEXCOORD1DARBPROC glMultiTexCoord1dARB;
	extern PFNGLMULTITEXCOORD1DVARBPROC glMultiTexCoord1dvARB;
	extern PFNGLMULTITEXCOORD1FARBPROC glMultiTexCoord1fARB;
	extern PFNGLMULTITEXCOORD1FVARBPROC glMultiTexCoord1fvARB;
	extern PFNGLMULTITEXCOORD1IARBPROC glMultiTexCoord1iARB;
	extern PFNGLMULTITEXCOORD1IVARBPROC glMultiTexCoord1ivARB;
	extern PFNGLMULTITEXCOORD1SARBPROC glMultiTexCoord1sARB;
	extern PFNGLMULTITEXCOORD1SVARBPROC glMultiTexCoord1svARB;
	extern PFNGLMULTITEXCOORD2DARBPROC glMultiTexCoord2dARB;
	extern PFNGLMULTITEXCOORD2DVARBPROC glMultiTexCoord2dvARB;
	extern PFNGLMULTITEXCOORD2FARBPROC glMultiTexCoord2fARB;
	extern PFNGLMULTITEXCOORD2FVARBPROC glMultiTexCoord2fvARB;
	extern PFNGLMULTITEXCOORD2IARBPROC glMultiTexCoord2iARB;
	extern PFNGLMULTITEXCOORD2IVARBPROC glMultiTexCoord2ivARB;
	extern PFNGLMULTITEXCOORD2SARBPROC glMultiTexCoord2sARB;
	extern PFNGLMULTITEXCOORD2SVARBPROC glMultiTexCoord2svARB;
	extern PFNGLMULTITEXCOORD3DARBPROC glMultiTexCoord3dARB;
	extern PFNGLMULTITEXCOORD3DVARBPROC glMultiTexCoord3dvARB;
	extern PFNGLMULTITEXCOORD3FARBPROC glMultiTexCoord3fARB;
	extern PFNGLMULTITEXCOORD3FVARBPROC glMultiTexCoord3fvARB;
	extern PFNGLMULTITEXCOORD3IARBPROC glMultiTexCoord3iARB;
	extern PFNGLMULTITEXCOORD3IVARBPROC glMultiTexCoord3ivARB;
	extern PFNGLMULTITEXCOORD3SARBPROC glMultiTexCoord3sARB;
	extern PFNGLMULTITEXCOORD3SVARBPROC glMultiTexCoord3svARB;
	extern PFNGLMULTITEXCOORD4DARBPROC glMultiTexCoord4dARB;
	extern PFNGLMULTITEXCOORD4DVARBPROC glMultiTexCoord4dvARB;
	extern PFNGLMULTITEXCOORD4FARBPROC glMultiTexCoord4fARB;
	extern PFNGLMULTITEXCOORD4FVARBPROC glMultiTexCoord4fvARB;
	extern PFNGLMULTITEXCOORD4IARBPROC glMultiTexCoord4iARB;
	extern PFNGLMULTITEXCOORD4IVARBPROC glMultiTexCoord4ivARB;
	extern PFNGLMULTITEXCOORD4SARBPROC glMultiTexCoord4sARB;
	extern PFNGLMULTITEXCOORD4SVARBPROC glMultiTexCoord4svARB;

	extern bool have_ARB_multitexture(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_multitexture_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_multitexture_NAMESPACE

//  ...for GL_ARB_occlusion_query:
namespace GL_ARB_occlusion_query_NAMESPACE {
	extern PFNGLBEGINQUERYARBPROC glBeginQueryARB;
	extern PFNGLDELETEQUERIESARBPROC glDeleteQueriesARB;
	extern PFNGLENDQUERYARBPROC glEndQueryARB;
	extern PFNGLGENQUERIESARBPROC glGenQueriesARB;
	extern PFNGLGETQUERYIVARBPROC glGetQueryivARB;
	extern PFNGLGETQUERYOBJECTIVARBPROC glGetQueryObjectivARB;
	extern PFNGLGETQUERYOBJECTUIVARBPROC glGetQueryObjectuivARB;
	extern PFNGLISQUERYARBPROC glIsQueryARB;

	extern bool have_ARB_occlusion_query(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_occlusion_query_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_occlusion_query_NAMESPACE

//  ...for GL_ARB_pixel_buffer_object:
namespace GL_ARB_pixel_buffer_object_NAMESPACE {

	extern bool have_ARB_pixel_buffer_object(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_pixel_buffer_object_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_pixel_buffer_object_NAMESPACE

//  ...for GL_ARB_point_parameters:
namespace GL_ARB_point_parameters_NAMESPACE {
	extern PFNGLPOINTPARAMETERFARBPROC glPointParameterfARB;
	extern PFNGLPOINTPARAMETERFVARBPROC glPointParameterfvARB;

	extern bool have_ARB_point_parameters(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_point_parameters_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_point_parameters_NAMESPACE

//  ...for GL_ARB_point_sprite:
namespace GL_ARB_point_sprite_NAMESPACE {

	extern bool have_ARB_point_sprite(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_point_sprite_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_point_sprite_NAMESPACE

//  ...for GL_ARB_shader_objects:
namespace GL_ARB_shader_objects_NAMESPACE {
	extern PFNGLATTACHOBJECTARBPROC glAttachObjectARB;
	extern PFNGLCOMPILESHADERARBPROC glCompileShaderARB;
	extern PFNGLCREATEPROGRAMOBJECTARBPROC glCreateProgramObjectARB;
	extern PFNGLCREATESHADEROBJECTARBPROC glCreateShaderObjectARB;
	extern PFNGLDELETEOBJECTARBPROC glDeleteObjectARB;
	extern PFNGLDETACHOBJECTARBPROC glDetachObjectARB;
	extern PFNGLGETACTIVEUNIFORMARBPROC glGetActiveUniformARB;
	extern PFNGLGETATTACHEDOBJECTSARBPROC glGetAttachedObjectsARB;
	extern PFNGLGETHANDLEARBPROC glGetHandleARB;
	extern PFNGLGETINFOLOGARBPROC glGetInfoLogARB;
	extern PFNGLGETOBJECTPARAMETERFVARBPROC glGetObjectParameterfvARB;
	extern PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameterivARB;
	extern PFNGLGETSHADERSOURCEARBPROC glGetShaderSourceARB;
	extern PFNGLGETUNIFORMFVARBPROC glGetUniformfvARB;
	extern PFNGLGETUNIFORMIVARBPROC glGetUniformivARB;
	extern PFNGLGETUNIFORMLOCATIONARBPROC glGetUniformLocationARB;
	extern PFNGLLINKPROGRAMARBPROC glLinkProgramARB;
	extern PFNGLSHADERSOURCEARBPROC glShaderSourceARB;
	extern PFNGLUNIFORM1FARBPROC glUniform1fARB;
	extern PFNGLUNIFORM1FVARBPROC glUniform1fvARB;
	extern PFNGLUNIFORM1IARBPROC glUniform1iARB;
	extern PFNGLUNIFORM1IVARBPROC glUniform1ivARB;
	extern PFNGLUNIFORM2FARBPROC glUniform2fARB;
	extern PFNGLUNIFORM2FVARBPROC glUniform2fvARB;
	extern PFNGLUNIFORM2IARBPROC glUniform2iARB;
	extern PFNGLUNIFORM2IVARBPROC glUniform2ivARB;
	extern PFNGLUNIFORM3FARBPROC glUniform3fARB;
	extern PFNGLUNIFORM3FVARBPROC glUniform3fvARB;
	extern PFNGLUNIFORM3IARBPROC glUniform3iARB;
	extern PFNGLUNIFORM3IVARBPROC glUniform3ivARB;
	extern PFNGLUNIFORM4FARBPROC glUniform4fARB;
	extern PFNGLUNIFORM4FVARBPROC glUniform4fvARB;
	extern PFNGLUNIFORM4IARBPROC glUniform4iARB;
	extern PFNGLUNIFORM4IVARBPROC glUniform4ivARB;
	extern PFNGLUNIFORMMATRIX2FVARBPROC glUniformMatrix2fvARB;
	extern PFNGLUNIFORMMATRIX3FVARBPROC glUniformMatrix3fvARB;
	extern PFNGLUNIFORMMATRIX4FVARBPROC glUniformMatrix4fvARB;
	extern PFNGLUSEPROGRAMOBJECTARBPROC glUseProgramObjectARB;
	extern PFNGLVALIDATEPROGRAMARBPROC glValidateProgramARB;

	extern bool have_ARB_shader_objects(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_shader_objects_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_shader_objects_NAMESPACE

//  ...for GL_ARB_shading_language_100:
namespace GL_ARB_shading_language_100_NAMESPACE {

	extern bool have_ARB_shading_language_100(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_shading_language_100_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_shading_language_100_NAMESPACE

//  ...for GL_ARB_shadow:
namespace GL_ARB_shadow_NAMESPACE {

	extern bool have_ARB_shadow(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_shadow_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_shadow_NAMESPACE

//  ...for GL_ARB_shadow_ambient:
namespace GL_ARB_shadow_ambient_NAMESPACE {

	extern bool have_ARB_shadow_ambient(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_shadow_ambient_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_shadow_ambient_NAMESPACE

//  ...for GL_ARB_texture_border_clamp:
namespace GL_ARB_texture_border_clamp_NAMESPACE {

	extern bool have_ARB_texture_border_clamp(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_texture_border_clamp_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_texture_border_clamp_NAMESPACE

//  ...for GL_ARB_texture_compression:
namespace GL_ARB_texture_compression_NAMESPACE {
	extern PFNGLCOMPRESSEDTEXIMAGE1DARBPROC glCompressedTexImage1DARB;
	extern PFNGLCOMPRESSEDTEXIMAGE2DARBPROC glCompressedTexImage2DARB;
	extern PFNGLCOMPRESSEDTEXIMAGE3DARBPROC glCompressedTexImage3DARB;
	extern PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC glCompressedTexSubImage1DARB;
	extern PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC glCompressedTexSubImage2DARB;
	extern PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC glCompressedTexSubImage3DARB;
	extern PFNGLGETCOMPRESSEDTEXIMAGEARBPROC glGetCompressedTexImageARB;

	extern bool have_ARB_texture_compression(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_texture_compression_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_texture_compression_NAMESPACE

//  ...for GL_ARB_texture_cube_map:
namespace GL_ARB_texture_cube_map_NAMESPACE {

	extern bool have_ARB_texture_cube_map(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_texture_cube_map_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_texture_cube_map_NAMESPACE

//  ...for GL_ARB_texture_env_add:
namespace GL_ARB_texture_env_add_NAMESPACE {

	extern bool have_ARB_texture_env_add(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_texture_env_add_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_texture_env_add_NAMESPACE

//  ...for GL_ARB_texture_env_combine:
namespace GL_ARB_texture_env_combine_NAMESPACE {

	extern bool have_ARB_texture_env_combine(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_texture_env_combine_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_texture_env_combine_NAMESPACE

//  ...for GL_ARB_texture_env_crossbar:
namespace GL_ARB_texture_env_crossbar_NAMESPACE {

	extern bool have_ARB_texture_env_crossbar(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_texture_env_crossbar_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_texture_env_crossbar_NAMESPACE

//  ...for GL_ARB_texture_env_dot3:
namespace GL_ARB_texture_env_dot3_NAMESPACE {

	extern bool have_ARB_texture_env_dot3(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_texture_env_dot3_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_texture_env_dot3_NAMESPACE

//  ...for GL_ARB_texture_float:
namespace GL_ARB_texture_float_NAMESPACE {

	extern bool have_ARB_texture_float(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_texture_float_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_texture_float_NAMESPACE

//  ...for GL_ARB_texture_mirrored_repeat:
namespace GL_ARB_texture_mirrored_repeat_NAMESPACE {

	extern bool have_ARB_texture_mirrored_repeat(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_texture_mirrored_repeat_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_texture_mirrored_repeat_NAMESPACE

//  ...for GL_ARB_texture_non_power_of_two:
namespace GL_ARB_texture_non_power_of_two_NAMESPACE {

	extern bool have_ARB_texture_non_power_of_two(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_texture_non_power_of_two_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_texture_non_power_of_two_NAMESPACE

//  ...for GL_ARB_texture_rectangle:
namespace GL_ARB_texture_rectangle_NAMESPACE {

	extern bool have_ARB_texture_rectangle(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_texture_rectangle_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_texture_rectangle_NAMESPACE

//  ...for GL_ARB_transpose_matrix:
namespace GL_ARB_transpose_matrix_NAMESPACE {
	extern PFNGLLOADTRANSPOSEMATRIXDARBPROC glLoadTransposeMatrixdARB;
	extern PFNGLLOADTRANSPOSEMATRIXFARBPROC glLoadTransposeMatrixfARB;
	extern PFNGLMULTTRANSPOSEMATRIXDARBPROC glMultTransposeMatrixdARB;
	extern PFNGLMULTTRANSPOSEMATRIXFARBPROC glMultTransposeMatrixfARB;

	extern bool have_ARB_transpose_matrix(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_transpose_matrix_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_transpose_matrix_NAMESPACE

//  ...for GL_ARB_vertex_blend:
namespace GL_ARB_vertex_blend_NAMESPACE {
	extern PFNGLVERTEXBLENDARBPROC glVertexBlendARB;
	extern PFNGLWEIGHTBVARBPROC glWeightbvARB;
	extern PFNGLWEIGHTDVARBPROC glWeightdvARB;
	extern PFNGLWEIGHTFVARBPROC glWeightfvARB;
	extern PFNGLWEIGHTIVARBPROC glWeightivARB;
	extern PFNGLWEIGHTPOINTERARBPROC glWeightPointerARB;
	extern PFNGLWEIGHTSVARBPROC glWeightsvARB;
	extern PFNGLWEIGHTUBVARBPROC glWeightubvARB;
	extern PFNGLWEIGHTUIVARBPROC glWeightuivARB;
	extern PFNGLWEIGHTUSVARBPROC glWeightusvARB;

	extern bool have_ARB_vertex_blend(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_vertex_blend_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_vertex_blend_NAMESPACE

//  ...for GL_ARB_vertex_buffer_object:
namespace GL_ARB_vertex_buffer_object_NAMESPACE {
	extern PFNGLBINDBUFFERARBPROC glBindBufferARB;
	extern PFNGLBUFFERDATAARBPROC glBufferDataARB;
	extern PFNGLBUFFERSUBDATAARBPROC glBufferSubDataARB;
	extern PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARB;
	extern PFNGLGENBUFFERSARBPROC glGenBuffersARB;
	extern PFNGLGETBUFFERPARAMETERIVARBPROC glGetBufferParameterivARB;
	extern PFNGLGETBUFFERPOINTERVARBPROC glGetBufferPointervARB;
	extern PFNGLGETBUFFERSUBDATAARBPROC glGetBufferSubDataARB;
	extern PFNGLISBUFFERARBPROC glIsBufferARB;
	extern PFNGLMAPBUFFERARBPROC glMapBufferARB;
	extern PFNGLUNMAPBUFFERARBPROC glUnmapBufferARB;

	extern bool have_ARB_vertex_buffer_object(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_vertex_buffer_object_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_vertex_buffer_object_NAMESPACE

//  ...for GL_ARB_vertex_program:
namespace GL_ARB_vertex_program_NAMESPACE {
	extern PFNGLBINDPROGRAMARBPROC glBindProgramARB;
	extern PFNGLDELETEPROGRAMSARBPROC glDeleteProgramsARB;
	extern PFNGLDISABLEVERTEXATTRIBARRAYARBPROC glDisableVertexAttribArrayARB;
	extern PFNGLENABLEVERTEXATTRIBARRAYARBPROC glEnableVertexAttribArrayARB;
	extern PFNGLGENPROGRAMSARBPROC glGenProgramsARB;
	extern PFNGLGETPROGRAMENVPARAMETERDVARBPROC glGetProgramEnvParameterdvARB;
	extern PFNGLGETPROGRAMENVPARAMETERFVARBPROC glGetProgramEnvParameterfvARB;
	extern PFNGLGETPROGRAMIVARBPROC glGetProgramivARB;
	extern PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC glGetProgramLocalParameterdvARB;
	extern PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC glGetProgramLocalParameterfvARB;
	extern PFNGLGETPROGRAMSTRINGARBPROC glGetProgramStringARB;
	extern PFNGLGETVERTEXATTRIBDVARBPROC glGetVertexAttribdvARB;
	extern PFNGLGETVERTEXATTRIBFVARBPROC glGetVertexAttribfvARB;
	extern PFNGLGETVERTEXATTRIBIVARBPROC glGetVertexAttribivARB;
	extern PFNGLGETVERTEXATTRIBPOINTERVARBPROC glGetVertexAttribPointervARB;
	extern PFNGLISPROGRAMARBPROC glIsProgramARB;
	extern PFNGLPROGRAMENVPARAMETER4DARBPROC glProgramEnvParameter4dARB;
	extern PFNGLPROGRAMENVPARAMETER4DVARBPROC glProgramEnvParameter4dvARB;
	extern PFNGLPROGRAMENVPARAMETER4FARBPROC glProgramEnvParameter4fARB;
	extern PFNGLPROGRAMENVPARAMETER4FVARBPROC glProgramEnvParameter4fvARB;
	extern PFNGLPROGRAMLOCALPARAMETER4DARBPROC glProgramLocalParameter4dARB;
	extern PFNGLPROGRAMLOCALPARAMETER4DVARBPROC glProgramLocalParameter4dvARB;
	extern PFNGLPROGRAMLOCALPARAMETER4FARBPROC glProgramLocalParameter4fARB;
	extern PFNGLPROGRAMLOCALPARAMETER4FVARBPROC glProgramLocalParameter4fvARB;
	extern PFNGLPROGRAMSTRINGARBPROC glProgramStringARB;
	extern PFNGLVERTEXATTRIB1DARBPROC glVertexAttrib1dARB;
	extern PFNGLVERTEXATTRIB1DVARBPROC glVertexAttrib1dvARB;
	extern PFNGLVERTEXATTRIB1FARBPROC glVertexAttrib1fARB;
	extern PFNGLVERTEXATTRIB1FVARBPROC glVertexAttrib1fvARB;
	extern PFNGLVERTEXATTRIB1SARBPROC glVertexAttrib1sARB;
	extern PFNGLVERTEXATTRIB1SVARBPROC glVertexAttrib1svARB;
	extern PFNGLVERTEXATTRIB2DARBPROC glVertexAttrib2dARB;
	extern PFNGLVERTEXATTRIB2DVARBPROC glVertexAttrib2dvARB;
	extern PFNGLVERTEXATTRIB2FARBPROC glVertexAttrib2fARB;
	extern PFNGLVERTEXATTRIB2FVARBPROC glVertexAttrib2fvARB;
	extern PFNGLVERTEXATTRIB2SARBPROC glVertexAttrib2sARB;
	extern PFNGLVERTEXATTRIB2SVARBPROC glVertexAttrib2svARB;
	extern PFNGLVERTEXATTRIB3DARBPROC glVertexAttrib3dARB;
	extern PFNGLVERTEXATTRIB3DVARBPROC glVertexAttrib3dvARB;
	extern PFNGLVERTEXATTRIB3FARBPROC glVertexAttrib3fARB;
	extern PFNGLVERTEXATTRIB3FVARBPROC glVertexAttrib3fvARB;
	extern PFNGLVERTEXATTRIB3SARBPROC glVertexAttrib3sARB;
	extern PFNGLVERTEXATTRIB3SVARBPROC glVertexAttrib3svARB;
	extern PFNGLVERTEXATTRIB4BVARBPROC glVertexAttrib4bvARB;
	extern PFNGLVERTEXATTRIB4DARBPROC glVertexAttrib4dARB;
	extern PFNGLVERTEXATTRIB4DVARBPROC glVertexAttrib4dvARB;
	extern PFNGLVERTEXATTRIB4FARBPROC glVertexAttrib4fARB;
	extern PFNGLVERTEXATTRIB4FVARBPROC glVertexAttrib4fvARB;
	extern PFNGLVERTEXATTRIB4IVARBPROC glVertexAttrib4ivARB;
	extern PFNGLVERTEXATTRIB4NBVARBPROC glVertexAttrib4NbvARB;
	extern PFNGLVERTEXATTRIB4NIVARBPROC glVertexAttrib4NivARB;
	extern PFNGLVERTEXATTRIB4NSVARBPROC glVertexAttrib4NsvARB;
	extern PFNGLVERTEXATTRIB4NUBARBPROC glVertexAttrib4NubARB;
	extern PFNGLVERTEXATTRIB4NUBVARBPROC glVertexAttrib4NubvARB;
	extern PFNGLVERTEXATTRIB4NUIVARBPROC glVertexAttrib4NuivARB;
	extern PFNGLVERTEXATTRIB4NUSVARBPROC glVertexAttrib4NusvARB;
	extern PFNGLVERTEXATTRIB4SARBPROC glVertexAttrib4sARB;
	extern PFNGLVERTEXATTRIB4SVARBPROC glVertexAttrib4svARB;
	extern PFNGLVERTEXATTRIB4UBVARBPROC glVertexAttrib4ubvARB;
	extern PFNGLVERTEXATTRIB4UIVARBPROC glVertexAttrib4uivARB;
	extern PFNGLVERTEXATTRIB4USVARBPROC glVertexAttrib4usvARB;
	extern PFNGLVERTEXATTRIBPOINTERARBPROC glVertexAttribPointerARB;

	extern bool have_ARB_vertex_program(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_vertex_program_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_vertex_program_NAMESPACE

//  ...for GL_ARB_vertex_shader:
namespace GL_ARB_vertex_shader_NAMESPACE {
	extern PFNGLBINDATTRIBLOCATIONARBPROC glBindAttribLocationARB;
	extern PFNGLGETACTIVEATTRIBARBPROC glGetActiveAttribARB;
	extern PFNGLGETATTRIBLOCATIONARBPROC glGetAttribLocationARB;

	extern bool have_ARB_vertex_shader(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_vertex_shader_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_vertex_shader_NAMESPACE

//  ...for GL_ARB_window_pos:
namespace GL_ARB_window_pos_NAMESPACE {
	extern PFNGLWINDOWPOS2DARBPROC glWindowPos2dARB;
	extern PFNGLWINDOWPOS2DVARBPROC glWindowPos2dvARB;
	extern PFNGLWINDOWPOS2FARBPROC glWindowPos2fARB;
	extern PFNGLWINDOWPOS2FVARBPROC glWindowPos2fvARB;
	extern PFNGLWINDOWPOS2IARBPROC glWindowPos2iARB;
	extern PFNGLWINDOWPOS2IVARBPROC glWindowPos2ivARB;
	extern PFNGLWINDOWPOS2SARBPROC glWindowPos2sARB;
	extern PFNGLWINDOWPOS2SVARBPROC glWindowPos2svARB;
	extern PFNGLWINDOWPOS3DARBPROC glWindowPos3dARB;
	extern PFNGLWINDOWPOS3DVARBPROC glWindowPos3dvARB;
	extern PFNGLWINDOWPOS3FARBPROC glWindowPos3fARB;
	extern PFNGLWINDOWPOS3FVARBPROC glWindowPos3fvARB;
	extern PFNGLWINDOWPOS3IARBPROC glWindowPos3iARB;
	extern PFNGLWINDOWPOS3IVARBPROC glWindowPos3ivARB;
	extern PFNGLWINDOWPOS3SARBPROC glWindowPos3sARB;
	extern PFNGLWINDOWPOS3SVARBPROC glWindowPos3svARB;

	extern bool have_ARB_window_pos(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ARB_window_pos_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ARB_window_pos_NAMESPACE

//  ...for GL_ATI_draw_buffers:
namespace GL_ATI_draw_buffers_NAMESPACE {
	extern PFNGLDRAWBUFFERSATIPROC glDrawBuffersATI;

	extern bool have_ATI_draw_buffers(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ATI_draw_buffers_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ATI_draw_buffers_NAMESPACE

//  ...for GL_ATI_element_array:
namespace GL_ATI_element_array_NAMESPACE {
	extern PFNGLDRAWELEMENTARRAYATIPROC glDrawElementArrayATI;
	extern PFNGLDRAWRANGEELEMENTARRAYATIPROC glDrawRangeElementArrayATI;
	extern PFNGLELEMENTPOINTERATIPROC glElementPointerATI;

	extern bool have_ATI_element_array(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ATI_element_array_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ATI_element_array_NAMESPACE

//  ...for GL_ATI_envmap_bumpmap:
namespace GL_ATI_envmap_bumpmap_NAMESPACE {
	extern PFNGLGETTEXBUMPPARAMETERFVATIPROC glGetTexBumpParameterfvATI;
	extern PFNGLGETTEXBUMPPARAMETERIVATIPROC glGetTexBumpParameterivATI;
	extern PFNGLTEXBUMPPARAMETERFVATIPROC glTexBumpParameterfvATI;
	extern PFNGLTEXBUMPPARAMETERIVATIPROC glTexBumpParameterivATI;

	extern bool have_ATI_envmap_bumpmap(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ATI_envmap_bumpmap_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ATI_envmap_bumpmap_NAMESPACE

//  ...for GL_ATI_fragment_shader:
namespace GL_ATI_fragment_shader_NAMESPACE {
	extern PFNGLALPHAFRAGMENTOP1ATIPROC glAlphaFragmentOp1ATI;
	extern PFNGLALPHAFRAGMENTOP2ATIPROC glAlphaFragmentOp2ATI;
	extern PFNGLALPHAFRAGMENTOP3ATIPROC glAlphaFragmentOp3ATI;
	extern PFNGLBEGINFRAGMENTSHADERATIPROC glBeginFragmentShaderATI;
	extern PFNGLBINDFRAGMENTSHADERATIPROC glBindFragmentShaderATI;
	extern PFNGLCOLORFRAGMENTOP1ATIPROC glColorFragmentOp1ATI;
	extern PFNGLCOLORFRAGMENTOP2ATIPROC glColorFragmentOp2ATI;
	extern PFNGLCOLORFRAGMENTOP3ATIPROC glColorFragmentOp3ATI;
	extern PFNGLDELETEFRAGMENTSHADERATIPROC glDeleteFragmentShaderATI;
	extern PFNGLENDFRAGMENTSHADERATIPROC glEndFragmentShaderATI;
	extern PFNGLGENFRAGMENTSHADERSATIPROC glGenFragmentShadersATI;
	extern PFNGLPASSTEXCOORDATIPROC glPassTexCoordATI;
	extern PFNGLSAMPLEMAPATIPROC glSampleMapATI;
	extern PFNGLSETFRAGMENTSHADERCONSTANTATIPROC glSetFragmentShaderConstantATI;

	extern bool have_ATI_fragment_shader(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ATI_fragment_shader_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ATI_fragment_shader_NAMESPACE

//  ...for GL_ATI_map_object_buffer:
namespace GL_ATI_map_object_buffer_NAMESPACE {
	extern PFNGLMAPOBJECTBUFFERATIPROC glMapObjectBufferATI;
	extern PFNGLUNMAPOBJECTBUFFERATIPROC glUnmapObjectBufferATI;

	extern bool have_ATI_map_object_buffer(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ATI_map_object_buffer_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ATI_map_object_buffer_NAMESPACE

//  ...for GL_ATI_pixel_format_float:
namespace GL_ATI_pixel_format_float_NAMESPACE {

	extern bool have_ATI_pixel_format_float(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ATI_pixel_format_float_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ATI_pixel_format_float_NAMESPACE

//  ...for GL_ATI_pn_triangles:
namespace GL_ATI_pn_triangles_NAMESPACE {
	extern PFNGLPNTRIANGLESFATIPROC glPNTrianglesfATI;
	extern PFNGLPNTRIANGLESIATIPROC glPNTrianglesiATI;

	extern bool have_ATI_pn_triangles(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ATI_pn_triangles_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ATI_pn_triangles_NAMESPACE

//  ...for GL_ATI_separate_stencil:
namespace GL_ATI_separate_stencil_NAMESPACE {
	extern PFNGLSTENCILFUNCSEPARATEATIPROC glStencilFuncSeparateATI;
	extern PFNGLSTENCILOPSEPARATEATIPROC glStencilOpSeparateATI;

	extern bool have_ATI_separate_stencil(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ATI_separate_stencil_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ATI_separate_stencil_NAMESPACE

//  ...for GL_ATI_text_fragment_shader:
namespace GL_ATI_text_fragment_shader_NAMESPACE {

	extern bool have_ATI_text_fragment_shader(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ATI_text_fragment_shader_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ATI_text_fragment_shader_NAMESPACE

//  ...for GL_ATI_texture_env_combine3:
namespace GL_ATI_texture_env_combine3_NAMESPACE {

	extern bool have_ATI_texture_env_combine3(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ATI_texture_env_combine3_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ATI_texture_env_combine3_NAMESPACE

//  ...for GL_ATI_texture_float:
namespace GL_ATI_texture_float_NAMESPACE {

	extern bool have_ATI_texture_float(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ATI_texture_float_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ATI_texture_float_NAMESPACE

//  ...for GL_ATI_texture_mirror_once:
namespace GL_ATI_texture_mirror_once_NAMESPACE {

	extern bool have_ATI_texture_mirror_once(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ATI_texture_mirror_once_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ATI_texture_mirror_once_NAMESPACE

//  ...for GL_ATI_vertex_array_object:
namespace GL_ATI_vertex_array_object_NAMESPACE {
	extern PFNGLARRAYOBJECTATIPROC glArrayObjectATI;
	extern PFNGLFREEOBJECTBUFFERATIPROC glFreeObjectBufferATI;
	extern PFNGLGETARRAYOBJECTFVATIPROC glGetArrayObjectfvATI;
	extern PFNGLGETARRAYOBJECTIVATIPROC glGetArrayObjectivATI;
	extern PFNGLGETOBJECTBUFFERFVATIPROC glGetObjectBufferfvATI;
	extern PFNGLGETOBJECTBUFFERIVATIPROC glGetObjectBufferivATI;
	extern PFNGLGETVARIANTARRAYOBJECTFVATIPROC glGetVariantArrayObjectfvATI;
	extern PFNGLGETVARIANTARRAYOBJECTIVATIPROC glGetVariantArrayObjectivATI;
	extern PFNGLISOBJECTBUFFERATIPROC glIsObjectBufferATI;
	extern PFNGLNEWOBJECTBUFFERATIPROC glNewObjectBufferATI;
	extern PFNGLUPDATEOBJECTBUFFERATIPROC glUpdateObjectBufferATI;
	extern PFNGLVARIANTARRAYOBJECTATIPROC glVariantArrayObjectATI;

	extern bool have_ATI_vertex_array_object(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ATI_vertex_array_object_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ATI_vertex_array_object_NAMESPACE

//  ...for GL_ATI_vertex_attrib_array_object:
namespace GL_ATI_vertex_attrib_array_object_NAMESPACE {
	extern PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC glGetVertexAttribArrayObjectfvATI;
	extern PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC glGetVertexAttribArrayObjectivATI;
	extern PFNGLVERTEXATTRIBARRAYOBJECTATIPROC glVertexAttribArrayObjectATI;

	extern bool have_ATI_vertex_attrib_array_object(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ATI_vertex_attrib_array_object_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ATI_vertex_attrib_array_object_NAMESPACE

//  ...for GL_ATI_vertex_streams:
namespace GL_ATI_vertex_streams_NAMESPACE {
	extern PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC glClientActiveVertexStreamATI;
	extern PFNGLNORMALSTREAM3BATIPROC glNormalStream3bATI;
	extern PFNGLNORMALSTREAM3BVATIPROC glNormalStream3bvATI;
	extern PFNGLNORMALSTREAM3DATIPROC glNormalStream3dATI;
	extern PFNGLNORMALSTREAM3DVATIPROC glNormalStream3dvATI;
	extern PFNGLNORMALSTREAM3FATIPROC glNormalStream3fATI;
	extern PFNGLNORMALSTREAM3FVATIPROC glNormalStream3fvATI;
	extern PFNGLNORMALSTREAM3IATIPROC glNormalStream3iATI;
	extern PFNGLNORMALSTREAM3IVATIPROC glNormalStream3ivATI;
	extern PFNGLNORMALSTREAM3SATIPROC glNormalStream3sATI;
	extern PFNGLNORMALSTREAM3SVATIPROC glNormalStream3svATI;
	extern PFNGLVERTEXBLENDENVFATIPROC glVertexBlendEnvfATI;
	extern PFNGLVERTEXBLENDENVIATIPROC glVertexBlendEnviATI;
	extern PFNGLVERTEXSTREAM1DATIPROC glVertexStream1dATI;
	extern PFNGLVERTEXSTREAM1DVATIPROC glVertexStream1dvATI;
	extern PFNGLVERTEXSTREAM1FATIPROC glVertexStream1fATI;
	extern PFNGLVERTEXSTREAM1FVATIPROC glVertexStream1fvATI;
	extern PFNGLVERTEXSTREAM1IATIPROC glVertexStream1iATI;
	extern PFNGLVERTEXSTREAM1IVATIPROC glVertexStream1ivATI;
	extern PFNGLVERTEXSTREAM1SATIPROC glVertexStream1sATI;
	extern PFNGLVERTEXSTREAM1SVATIPROC glVertexStream1svATI;
	extern PFNGLVERTEXSTREAM2DATIPROC glVertexStream2dATI;
	extern PFNGLVERTEXSTREAM2DVATIPROC glVertexStream2dvATI;
	extern PFNGLVERTEXSTREAM2FATIPROC glVertexStream2fATI;
	extern PFNGLVERTEXSTREAM2FVATIPROC glVertexStream2fvATI;
	extern PFNGLVERTEXSTREAM2IATIPROC glVertexStream2iATI;
	extern PFNGLVERTEXSTREAM2IVATIPROC glVertexStream2ivATI;
	extern PFNGLVERTEXSTREAM2SATIPROC glVertexStream2sATI;
	extern PFNGLVERTEXSTREAM2SVATIPROC glVertexStream2svATI;
	extern PFNGLVERTEXSTREAM3DATIPROC glVertexStream3dATI;
	extern PFNGLVERTEXSTREAM3DVATIPROC glVertexStream3dvATI;
	extern PFNGLVERTEXSTREAM3FATIPROC glVertexStream3fATI;
	extern PFNGLVERTEXSTREAM3FVATIPROC glVertexStream3fvATI;
	extern PFNGLVERTEXSTREAM3IATIPROC glVertexStream3iATI;
	extern PFNGLVERTEXSTREAM3IVATIPROC glVertexStream3ivATI;
	extern PFNGLVERTEXSTREAM3SATIPROC glVertexStream3sATI;
	extern PFNGLVERTEXSTREAM3SVATIPROC glVertexStream3svATI;
	extern PFNGLVERTEXSTREAM4DATIPROC glVertexStream4dATI;
	extern PFNGLVERTEXSTREAM4DVATIPROC glVertexStream4dvATI;
	extern PFNGLVERTEXSTREAM4FATIPROC glVertexStream4fATI;
	extern PFNGLVERTEXSTREAM4FVATIPROC glVertexStream4fvATI;
	extern PFNGLVERTEXSTREAM4IATIPROC glVertexStream4iATI;
	extern PFNGLVERTEXSTREAM4IVATIPROC glVertexStream4ivATI;
	extern PFNGLVERTEXSTREAM4SATIPROC glVertexStream4sATI;
	extern PFNGLVERTEXSTREAM4SVATIPROC glVertexStream4svATI;

	extern bool have_ATI_vertex_streams(); //<- for your use.

	//internal book-keeping stuff:
	class GL_ATI_vertex_streams_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_ATI_vertex_streams_NAMESPACE

//  ...for GL_EXT_422_pixels:
namespace GL_EXT_422_pixels_NAMESPACE {

	extern bool have_EXT_422_pixels(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_422_pixels_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_422_pixels_NAMESPACE

//  ...for GL_EXT_abgr:
namespace GL_EXT_abgr_NAMESPACE {

	extern bool have_EXT_abgr(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_abgr_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_abgr_NAMESPACE

//  ...for GL_EXT_bgra:
namespace GL_EXT_bgra_NAMESPACE {

	extern bool have_EXT_bgra(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_bgra_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_bgra_NAMESPACE

//  ...for GL_EXT_blend_color:
namespace GL_EXT_blend_color_NAMESPACE {
	extern PFNGLBLENDCOLOREXTPROC glBlendColorEXT;

	extern bool have_EXT_blend_color(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_blend_color_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_blend_color_NAMESPACE

//  ...for GL_EXT_blend_equation_separate:
namespace GL_EXT_blend_equation_separate_NAMESPACE {
	extern PFNGLBLENDEQUATIONSEPARATEEXTPROC glBlendEquationSeparateEXT;

	extern bool have_EXT_blend_equation_separate(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_blend_equation_separate_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_blend_equation_separate_NAMESPACE

//  ...for GL_EXT_blend_func_separate:
namespace GL_EXT_blend_func_separate_NAMESPACE {
	extern PFNGLBLENDFUNCSEPARATEEXTPROC glBlendFuncSeparateEXT;

	extern bool have_EXT_blend_func_separate(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_blend_func_separate_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_blend_func_separate_NAMESPACE

//  ...for GL_EXT_blend_logic_op:
namespace GL_EXT_blend_logic_op_NAMESPACE {

	extern bool have_EXT_blend_logic_op(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_blend_logic_op_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_blend_logic_op_NAMESPACE

//  ...for GL_EXT_blend_minmax:
namespace GL_EXT_blend_minmax_NAMESPACE {
	extern PFNGLBLENDEQUATIONEXTPROC glBlendEquationEXT;

	extern bool have_EXT_blend_minmax(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_blend_minmax_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_blend_minmax_NAMESPACE

//  ...for GL_EXT_blend_subtract:
namespace GL_EXT_blend_subtract_NAMESPACE {

	extern bool have_EXT_blend_subtract(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_blend_subtract_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_blend_subtract_NAMESPACE

//  ...for GL_EXT_clip_volume_hint:
namespace GL_EXT_clip_volume_hint_NAMESPACE {

	extern bool have_EXT_clip_volume_hint(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_clip_volume_hint_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_clip_volume_hint_NAMESPACE

//  ...for GL_EXT_cmyka:
namespace GL_EXT_cmyka_NAMESPACE {

	extern bool have_EXT_cmyka(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_cmyka_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_cmyka_NAMESPACE

//  ...for GL_EXT_color_matrix:
namespace GL_EXT_color_matrix_NAMESPACE {

	extern bool have_EXT_color_matrix(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_color_matrix_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_color_matrix_NAMESPACE

//  ...for GL_EXT_color_subtable:
namespace GL_EXT_color_subtable_NAMESPACE {
	extern PFNGLCOLORSUBTABLEEXTPROC glColorSubTableEXT;
	extern PFNGLCOPYCOLORSUBTABLEEXTPROC glCopyColorSubTableEXT;

	extern bool have_EXT_color_subtable(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_color_subtable_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_color_subtable_NAMESPACE

//  ...for GL_EXT_compiled_vertex_array:
namespace GL_EXT_compiled_vertex_array_NAMESPACE {
	extern PFNGLLOCKARRAYSEXTPROC glLockArraysEXT;
	extern PFNGLUNLOCKARRAYSEXTPROC glUnlockArraysEXT;

	extern bool have_EXT_compiled_vertex_array(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_compiled_vertex_array_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_compiled_vertex_array_NAMESPACE

//  ...for GL_EXT_convolution:
namespace GL_EXT_convolution_NAMESPACE {
	extern PFNGLCONVOLUTIONFILTER1DEXTPROC glConvolutionFilter1DEXT;
	extern PFNGLCONVOLUTIONFILTER2DEXTPROC glConvolutionFilter2DEXT;
	extern PFNGLCONVOLUTIONPARAMETERFEXTPROC glConvolutionParameterfEXT;
	extern PFNGLCONVOLUTIONPARAMETERFVEXTPROC glConvolutionParameterfvEXT;
	extern PFNGLCONVOLUTIONPARAMETERIEXTPROC glConvolutionParameteriEXT;
	extern PFNGLCONVOLUTIONPARAMETERIVEXTPROC glConvolutionParameterivEXT;
	extern PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC glCopyConvolutionFilter1DEXT;
	extern PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC glCopyConvolutionFilter2DEXT;
	extern PFNGLGETCONVOLUTIONFILTEREXTPROC glGetConvolutionFilterEXT;
	extern PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC glGetConvolutionParameterfvEXT;
	extern PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC glGetConvolutionParameterivEXT;
	extern PFNGLGETSEPARABLEFILTEREXTPROC glGetSeparableFilterEXT;
	extern PFNGLSEPARABLEFILTER2DEXTPROC glSeparableFilter2DEXT;

	extern bool have_EXT_convolution(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_convolution_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_convolution_NAMESPACE

//  ...for GL_EXT_coordinate_frame:
namespace GL_EXT_coordinate_frame_NAMESPACE {
	extern PFNGLBINORMAL3BEXTPROC glBinormal3bEXT;
	extern PFNGLBINORMAL3BVEXTPROC glBinormal3bvEXT;
	extern PFNGLBINORMAL3DEXTPROC glBinormal3dEXT;
	extern PFNGLBINORMAL3DVEXTPROC glBinormal3dvEXT;
	extern PFNGLBINORMAL3FEXTPROC glBinormal3fEXT;
	extern PFNGLBINORMAL3FVEXTPROC glBinormal3fvEXT;
	extern PFNGLBINORMAL3IEXTPROC glBinormal3iEXT;
	extern PFNGLBINORMAL3IVEXTPROC glBinormal3ivEXT;
	extern PFNGLBINORMAL3SEXTPROC glBinormal3sEXT;
	extern PFNGLBINORMAL3SVEXTPROC glBinormal3svEXT;
	extern PFNGLBINORMALPOINTEREXTPROC glBinormalPointerEXT;
	extern PFNGLTANGENT3BEXTPROC glTangent3bEXT;
	extern PFNGLTANGENT3BVEXTPROC glTangent3bvEXT;
	extern PFNGLTANGENT3DEXTPROC glTangent3dEXT;
	extern PFNGLTANGENT3DVEXTPROC glTangent3dvEXT;
	extern PFNGLTANGENT3FEXTPROC glTangent3fEXT;
	extern PFNGLTANGENT3FVEXTPROC glTangent3fvEXT;
	extern PFNGLTANGENT3IEXTPROC glTangent3iEXT;
	extern PFNGLTANGENT3IVEXTPROC glTangent3ivEXT;
	extern PFNGLTANGENT3SEXTPROC glTangent3sEXT;
	extern PFNGLTANGENT3SVEXTPROC glTangent3svEXT;
	extern PFNGLTANGENTPOINTEREXTPROC glTangentPointerEXT;

	extern bool have_EXT_coordinate_frame(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_coordinate_frame_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_coordinate_frame_NAMESPACE

//  ...for GL_EXT_copy_texture:
namespace GL_EXT_copy_texture_NAMESPACE {
	extern PFNGLCOPYTEXIMAGE1DEXTPROC glCopyTexImage1DEXT;
	extern PFNGLCOPYTEXIMAGE2DEXTPROC glCopyTexImage2DEXT;
	extern PFNGLCOPYTEXSUBIMAGE1DEXTPROC glCopyTexSubImage1DEXT;
	extern PFNGLCOPYTEXSUBIMAGE2DEXTPROC glCopyTexSubImage2DEXT;
	extern PFNGLCOPYTEXSUBIMAGE3DEXTPROC glCopyTexSubImage3DEXT;

	extern bool have_EXT_copy_texture(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_copy_texture_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_copy_texture_NAMESPACE

//  ...for GL_EXT_cull_vertex:
namespace GL_EXT_cull_vertex_NAMESPACE {
	extern PFNGLCULLPARAMETERDVEXTPROC glCullParameterdvEXT;
	extern PFNGLCULLPARAMETERFVEXTPROC glCullParameterfvEXT;

	extern bool have_EXT_cull_vertex(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_cull_vertex_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_cull_vertex_NAMESPACE

//  ...for GL_EXT_depth_bounds_test:
namespace GL_EXT_depth_bounds_test_NAMESPACE {
	extern PFNGLDEPTHBOUNDSEXTPROC glDepthBoundsEXT;

	extern bool have_EXT_depth_bounds_test(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_depth_bounds_test_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_depth_bounds_test_NAMESPACE

//  ...for GL_EXT_draw_range_elements:
namespace GL_EXT_draw_range_elements_NAMESPACE {
	extern PFNGLDRAWRANGEELEMENTSEXTPROC glDrawRangeElementsEXT;

	extern bool have_EXT_draw_range_elements(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_draw_range_elements_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_draw_range_elements_NAMESPACE

//  ...for GL_EXT_fog_coord:
namespace GL_EXT_fog_coord_NAMESPACE {
	extern PFNGLFOGCOORDDEXTPROC glFogCoorddEXT;
	extern PFNGLFOGCOORDDVEXTPROC glFogCoorddvEXT;
	extern PFNGLFOGCOORDFEXTPROC glFogCoordfEXT;
	extern PFNGLFOGCOORDFVEXTPROC glFogCoordfvEXT;
	extern PFNGLFOGCOORDPOINTEREXTPROC glFogCoordPointerEXT;

	extern bool have_EXT_fog_coord(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_fog_coord_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_fog_coord_NAMESPACE

//  ...for GL_EXT_framebuffer_object:
namespace GL_EXT_framebuffer_object_NAMESPACE {
	extern PFNGLBINDFRAMEBUFFEREXTPROC glBindFramebufferEXT;
	extern PFNGLBINDRENDERBUFFEREXTPROC glBindRenderbufferEXT;
	extern PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC glCheckFramebufferStatusEXT;
	extern PFNGLDELETEFRAMEBUFFERSEXTPROC glDeleteFramebuffersEXT;
	extern PFNGLDELETERENDERBUFFERSEXTPROC glDeleteRenderbuffersEXT;
	extern PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC glFramebufferRenderbufferEXT;
	extern PFNGLFRAMEBUFFERTEXTURE1DEXTPROC glFramebufferTexture1DEXT;
	extern PFNGLFRAMEBUFFERTEXTURE2DEXTPROC glFramebufferTexture2DEXT;
	extern PFNGLFRAMEBUFFERTEXTURE3DEXTPROC glFramebufferTexture3DEXT;
	extern PFNGLGENERATEMIPMAPEXTPROC glGenerateMipmapEXT;
	extern PFNGLGENFRAMEBUFFERSEXTPROC glGenFramebuffersEXT;
	extern PFNGLGENRENDERBUFFERSEXTPROC glGenRenderbuffersEXT;
	extern PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC glGetFramebufferAttachmentParameterivEXT;
	extern PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC glGetRenderbufferParameterivEXT;
	extern PFNGLISFRAMEBUFFEREXTPROC glIsFramebufferEXT;
	extern PFNGLISRENDERBUFFEREXTPROC glIsRenderbufferEXT;
	extern PFNGLRENDERBUFFERSTORAGEEXTPROC glRenderbufferStorageEXT;

	extern bool have_EXT_framebuffer_object(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_framebuffer_object_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_framebuffer_object_NAMESPACE

//  ...for GL_EXT_histogram:
namespace GL_EXT_histogram_NAMESPACE {
	extern PFNGLGETHISTOGRAMEXTPROC glGetHistogramEXT;
	extern PFNGLGETHISTOGRAMPARAMETERFVEXTPROC glGetHistogramParameterfvEXT;
	extern PFNGLGETHISTOGRAMPARAMETERIVEXTPROC glGetHistogramParameterivEXT;
	extern PFNGLGETMINMAXEXTPROC glGetMinmaxEXT;
	extern PFNGLGETMINMAXPARAMETERFVEXTPROC glGetMinmaxParameterfvEXT;
	extern PFNGLGETMINMAXPARAMETERIVEXTPROC glGetMinmaxParameterivEXT;
	extern PFNGLHISTOGRAMEXTPROC glHistogramEXT;
	extern PFNGLMINMAXEXTPROC glMinmaxEXT;
	extern PFNGLRESETHISTOGRAMEXTPROC glResetHistogramEXT;
	extern PFNGLRESETMINMAXEXTPROC glResetMinmaxEXT;

	extern bool have_EXT_histogram(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_histogram_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_histogram_NAMESPACE

//  ...for GL_EXT_index_array_formats:
namespace GL_EXT_index_array_formats_NAMESPACE {

	extern bool have_EXT_index_array_formats(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_index_array_formats_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_index_array_formats_NAMESPACE

//  ...for GL_EXT_index_func:
namespace GL_EXT_index_func_NAMESPACE {
	extern PFNGLINDEXFUNCEXTPROC glIndexFuncEXT;

	extern bool have_EXT_index_func(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_index_func_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_index_func_NAMESPACE

//  ...for GL_EXT_index_material:
namespace GL_EXT_index_material_NAMESPACE {
	extern PFNGLINDEXMATERIALEXTPROC glIndexMaterialEXT;

	extern bool have_EXT_index_material(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_index_material_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_index_material_NAMESPACE

//  ...for GL_EXT_index_texture:
namespace GL_EXT_index_texture_NAMESPACE {

	extern bool have_EXT_index_texture(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_index_texture_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_index_texture_NAMESPACE

//  ...for GL_EXT_light_texture:
namespace GL_EXT_light_texture_NAMESPACE {
	extern PFNGLAPPLYTEXTUREEXTPROC glApplyTextureEXT;
	extern PFNGLTEXTURELIGHTEXTPROC glTextureLightEXT;
	extern PFNGLTEXTUREMATERIALEXTPROC glTextureMaterialEXT;

	extern bool have_EXT_light_texture(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_light_texture_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_light_texture_NAMESPACE

//  ...for GL_EXT_misc_attribute:
namespace GL_EXT_misc_attribute_NAMESPACE {

	extern bool have_EXT_misc_attribute(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_misc_attribute_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_misc_attribute_NAMESPACE

//  ...for GL_EXT_multi_draw_arrays:
namespace GL_EXT_multi_draw_arrays_NAMESPACE {
	extern PFNGLMULTIDRAWARRAYSEXTPROC glMultiDrawArraysEXT;
	extern PFNGLMULTIDRAWELEMENTSEXTPROC glMultiDrawElementsEXT;

	extern bool have_EXT_multi_draw_arrays(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_multi_draw_arrays_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_multi_draw_arrays_NAMESPACE

//  ...for GL_EXT_multisample:
namespace GL_EXT_multisample_NAMESPACE {
	extern PFNGLSAMPLEMASKEXTPROC glSampleMaskEXT;
	extern PFNGLSAMPLEPATTERNEXTPROC glSamplePatternEXT;

	extern bool have_EXT_multisample(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_multisample_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_multisample_NAMESPACE

//  ...for GL_EXT_packed_pixels:
namespace GL_EXT_packed_pixels_NAMESPACE {

	extern bool have_EXT_packed_pixels(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_packed_pixels_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_packed_pixels_NAMESPACE

//  ...for GL_EXT_paletted_texture:
namespace GL_EXT_paletted_texture_NAMESPACE {
	extern PFNGLCOLORTABLEEXTPROC glColorTableEXT;
	extern PFNGLGETCOLORTABLEEXTPROC glGetColorTableEXT;
	extern PFNGLGETCOLORTABLEPARAMETERFVEXTPROC glGetColorTableParameterfvEXT;
	extern PFNGLGETCOLORTABLEPARAMETERIVEXTPROC glGetColorTableParameterivEXT;

	extern bool have_EXT_paletted_texture(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_paletted_texture_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_paletted_texture_NAMESPACE

//  ...for GL_EXT_pixel_buffer_object:
namespace GL_EXT_pixel_buffer_object_NAMESPACE {

	extern bool have_EXT_pixel_buffer_object(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_pixel_buffer_object_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_pixel_buffer_object_NAMESPACE

//  ...for GL_EXT_pixel_transform:
namespace GL_EXT_pixel_transform_NAMESPACE {
	extern PFNGLPIXELTRANSFORMPARAMETERFEXTPROC glPixelTransformParameterfEXT;
	extern PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC glPixelTransformParameterfvEXT;
	extern PFNGLPIXELTRANSFORMPARAMETERIEXTPROC glPixelTransformParameteriEXT;
	extern PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC glPixelTransformParameterivEXT;

	extern bool have_EXT_pixel_transform(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_pixel_transform_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_pixel_transform_NAMESPACE

//  ...for GL_EXT_pixel_transform_color_table:
namespace GL_EXT_pixel_transform_color_table_NAMESPACE {

	extern bool have_EXT_pixel_transform_color_table(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_pixel_transform_color_table_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_pixel_transform_color_table_NAMESPACE

//  ...for GL_EXT_point_parameters:
namespace GL_EXT_point_parameters_NAMESPACE {
	extern PFNGLPOINTPARAMETERFEXTPROC glPointParameterfEXT;
	extern PFNGLPOINTPARAMETERFVEXTPROC glPointParameterfvEXT;

	extern bool have_EXT_point_parameters(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_point_parameters_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_point_parameters_NAMESPACE

//  ...for GL_EXT_polygon_offset:
namespace GL_EXT_polygon_offset_NAMESPACE {
	extern PFNGLPOLYGONOFFSETEXTPROC glPolygonOffsetEXT;

	extern bool have_EXT_polygon_offset(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_polygon_offset_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_polygon_offset_NAMESPACE

//  ...for GL_EXT_rescale_normal:
namespace GL_EXT_rescale_normal_NAMESPACE {

	extern bool have_EXT_rescale_normal(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_rescale_normal_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_rescale_normal_NAMESPACE

//  ...for GL_EXT_secondary_color:
namespace GL_EXT_secondary_color_NAMESPACE {
	extern PFNGLSECONDARYCOLOR3BEXTPROC glSecondaryColor3bEXT;
	extern PFNGLSECONDARYCOLOR3BVEXTPROC glSecondaryColor3bvEXT;
	extern PFNGLSECONDARYCOLOR3DEXTPROC glSecondaryColor3dEXT;
	extern PFNGLSECONDARYCOLOR3DVEXTPROC glSecondaryColor3dvEXT;
	extern PFNGLSECONDARYCOLOR3FEXTPROC glSecondaryColor3fEXT;
	extern PFNGLSECONDARYCOLOR3FVEXTPROC glSecondaryColor3fvEXT;
	extern PFNGLSECONDARYCOLOR3IEXTPROC glSecondaryColor3iEXT;
	extern PFNGLSECONDARYCOLOR3IVEXTPROC glSecondaryColor3ivEXT;
	extern PFNGLSECONDARYCOLOR3SEXTPROC glSecondaryColor3sEXT;
	extern PFNGLSECONDARYCOLOR3SVEXTPROC glSecondaryColor3svEXT;
	extern PFNGLSECONDARYCOLOR3UBEXTPROC glSecondaryColor3ubEXT;
	extern PFNGLSECONDARYCOLOR3UBVEXTPROC glSecondaryColor3ubvEXT;
	extern PFNGLSECONDARYCOLOR3UIEXTPROC glSecondaryColor3uiEXT;
	extern PFNGLSECONDARYCOLOR3UIVEXTPROC glSecondaryColor3uivEXT;
	extern PFNGLSECONDARYCOLOR3USEXTPROC glSecondaryColor3usEXT;
	extern PFNGLSECONDARYCOLOR3USVEXTPROC glSecondaryColor3usvEXT;
	extern PFNGLSECONDARYCOLORPOINTEREXTPROC glSecondaryColorPointerEXT;

	extern bool have_EXT_secondary_color(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_secondary_color_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_secondary_color_NAMESPACE

//  ...for GL_EXT_separate_specular_color:
namespace GL_EXT_separate_specular_color_NAMESPACE {

	extern bool have_EXT_separate_specular_color(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_separate_specular_color_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_separate_specular_color_NAMESPACE

//  ...for GL_EXT_shadow_funcs:
namespace GL_EXT_shadow_funcs_NAMESPACE {

	extern bool have_EXT_shadow_funcs(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_shadow_funcs_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_shadow_funcs_NAMESPACE

//  ...for GL_EXT_shared_texture_palette:
namespace GL_EXT_shared_texture_palette_NAMESPACE {

	extern bool have_EXT_shared_texture_palette(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_shared_texture_palette_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_shared_texture_palette_NAMESPACE

//  ...for GL_EXT_stencil_two_side:
namespace GL_EXT_stencil_two_side_NAMESPACE {
	extern PFNGLACTIVESTENCILFACEEXTPROC glActiveStencilFaceEXT;

	extern bool have_EXT_stencil_two_side(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_stencil_two_side_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_stencil_two_side_NAMESPACE

//  ...for GL_EXT_stencil_wrap:
namespace GL_EXT_stencil_wrap_NAMESPACE {

	extern bool have_EXT_stencil_wrap(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_stencil_wrap_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_stencil_wrap_NAMESPACE

//  ...for GL_EXT_subtexture:
namespace GL_EXT_subtexture_NAMESPACE {
	extern PFNGLTEXSUBIMAGE1DEXTPROC glTexSubImage1DEXT;
	extern PFNGLTEXSUBIMAGE2DEXTPROC glTexSubImage2DEXT;

	extern bool have_EXT_subtexture(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_subtexture_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_subtexture_NAMESPACE

//  ...for GL_EXT_texture:
namespace GL_EXT_texture_NAMESPACE {

	extern bool have_EXT_texture(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_texture_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_texture_NAMESPACE

//  ...for GL_EXT_texture3:
namespace GL_EXT_texture3_NAMESPACE {
	extern PFNGLTEXIMAGE3DEXTPROC glTexImage3DEXT;
	extern PFNGLTEXSUBIMAGE3DEXTPROC glTexSubImage3DEXT;

	extern bool have_EXT_texture3(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_texture3_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_texture3_NAMESPACE

//  ...for GL_EXT_texture_compression_s3tc:
namespace GL_EXT_texture_compression_s3tc_NAMESPACE {

	extern bool have_EXT_texture_compression_s3tc(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_texture_compression_s3tc_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_texture_compression_s3tc_NAMESPACE

//  ...for GL_EXT_texture_cube_map:
namespace GL_EXT_texture_cube_map_NAMESPACE {

	extern bool have_EXT_texture_cube_map(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_texture_cube_map_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_texture_cube_map_NAMESPACE

//  ...for GL_EXT_texture_env_add:
namespace GL_EXT_texture_env_add_NAMESPACE {

	extern bool have_EXT_texture_env_add(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_texture_env_add_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_texture_env_add_NAMESPACE

//  ...for GL_EXT_texture_env_combine:
namespace GL_EXT_texture_env_combine_NAMESPACE {

	extern bool have_EXT_texture_env_combine(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_texture_env_combine_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_texture_env_combine_NAMESPACE

//  ...for GL_EXT_texture_env_dot3:
namespace GL_EXT_texture_env_dot3_NAMESPACE {

	extern bool have_EXT_texture_env_dot3(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_texture_env_dot3_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_texture_env_dot3_NAMESPACE

//  ...for GL_EXT_texture_filter_anisotropic:
namespace GL_EXT_texture_filter_anisotropic_NAMESPACE {

	extern bool have_EXT_texture_filter_anisotropic(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_texture_filter_anisotropic_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_texture_filter_anisotropic_NAMESPACE

//  ...for GL_EXT_texture_lod_bias:
namespace GL_EXT_texture_lod_bias_NAMESPACE {

	extern bool have_EXT_texture_lod_bias(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_texture_lod_bias_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_texture_lod_bias_NAMESPACE

//  ...for GL_EXT_texture_mirror_clamp:
namespace GL_EXT_texture_mirror_clamp_NAMESPACE {

	extern bool have_EXT_texture_mirror_clamp(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_texture_mirror_clamp_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_texture_mirror_clamp_NAMESPACE

//  ...for GL_EXT_texture_object:
namespace GL_EXT_texture_object_NAMESPACE {
	extern PFNGLARETEXTURESRESIDENTEXTPROC glAreTexturesResidentEXT;
	extern PFNGLBINDTEXTUREEXTPROC glBindTextureEXT;
	extern PFNGLDELETETEXTURESEXTPROC glDeleteTexturesEXT;
	extern PFNGLGENTEXTURESEXTPROC glGenTexturesEXT;
	extern PFNGLISTEXTUREEXTPROC glIsTextureEXT;
	extern PFNGLPRIORITIZETEXTURESEXTPROC glPrioritizeTexturesEXT;

	extern bool have_EXT_texture_object(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_texture_object_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_texture_object_NAMESPACE

//  ...for GL_EXT_texture_perturb_normal:
namespace GL_EXT_texture_perturb_normal_NAMESPACE {
	extern PFNGLTEXTURENORMALEXTPROC glTextureNormalEXT;

	extern bool have_EXT_texture_perturb_normal(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_texture_perturb_normal_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_texture_perturb_normal_NAMESPACE

//  ...for GL_EXT_vertex_array:
namespace GL_EXT_vertex_array_NAMESPACE {
	extern PFNGLARRAYELEMENTEXTPROC glArrayElementEXT;
	extern PFNGLCOLORPOINTEREXTPROC glColorPointerEXT;
	extern PFNGLDRAWARRAYSEXTPROC glDrawArraysEXT;
	extern PFNGLEDGEFLAGPOINTEREXTPROC glEdgeFlagPointerEXT;
	extern PFNGLGETPOINTERVEXTPROC glGetPointervEXT;
	extern PFNGLINDEXPOINTEREXTPROC glIndexPointerEXT;
	extern PFNGLNORMALPOINTEREXTPROC glNormalPointerEXT;
	extern PFNGLTEXCOORDPOINTEREXTPROC glTexCoordPointerEXT;
	extern PFNGLVERTEXPOINTEREXTPROC glVertexPointerEXT;

	extern bool have_EXT_vertex_array(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_vertex_array_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_vertex_array_NAMESPACE

//  ...for GL_EXT_vertex_shader:
namespace GL_EXT_vertex_shader_NAMESPACE {
	extern PFNGLBEGINVERTEXSHADEREXTPROC glBeginVertexShaderEXT;
	extern PFNGLBINDLIGHTPARAMETEREXTPROC glBindLightParameterEXT;
	extern PFNGLBINDMATERIALPARAMETEREXTPROC glBindMaterialParameterEXT;
	extern PFNGLBINDPARAMETEREXTPROC glBindParameterEXT;
	extern PFNGLBINDTEXGENPARAMETEREXTPROC glBindTexGenParameterEXT;
	extern PFNGLBINDTEXTUREUNITPARAMETEREXTPROC glBindTextureUnitParameterEXT;
	extern PFNGLBINDVERTEXSHADEREXTPROC glBindVertexShaderEXT;
	extern PFNGLDELETEVERTEXSHADEREXTPROC glDeleteVertexShaderEXT;
	extern PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC glDisableVariantClientStateEXT;
	extern PFNGLENABLEVARIANTCLIENTSTATEEXTPROC glEnableVariantClientStateEXT;
	extern PFNGLENDVERTEXSHADEREXTPROC glEndVertexShaderEXT;
	extern PFNGLEXTRACTCOMPONENTEXTPROC glExtractComponentEXT;
	extern PFNGLGENSYMBOLSEXTPROC glGenSymbolsEXT;
	extern PFNGLGENVERTEXSHADERSEXTPROC glGenVertexShadersEXT;
	extern PFNGLGETINVARIANTBOOLEANVEXTPROC glGetInvariantBooleanvEXT;
	extern PFNGLGETINVARIANTFLOATVEXTPROC glGetInvariantFloatvEXT;
	extern PFNGLGETINVARIANTINTEGERVEXTPROC glGetInvariantIntegervEXT;
	extern PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC glGetLocalConstantBooleanvEXT;
	extern PFNGLGETLOCALCONSTANTFLOATVEXTPROC glGetLocalConstantFloatvEXT;
	extern PFNGLGETLOCALCONSTANTINTEGERVEXTPROC glGetLocalConstantIntegervEXT;
	extern PFNGLGETVARIANTBOOLEANVEXTPROC glGetVariantBooleanvEXT;
	extern PFNGLGETVARIANTFLOATVEXTPROC glGetVariantFloatvEXT;
	extern PFNGLGETVARIANTINTEGERVEXTPROC glGetVariantIntegervEXT;
	extern PFNGLGETVARIANTPOINTERVEXTPROC glGetVariantPointervEXT;
	extern PFNGLINSERTCOMPONENTEXTPROC glInsertComponentEXT;
	extern PFNGLISVARIANTENABLEDEXTPROC glIsVariantEnabledEXT;
	extern PFNGLSETINVARIANTEXTPROC glSetInvariantEXT;
	extern PFNGLSETLOCALCONSTANTEXTPROC glSetLocalConstantEXT;
	extern PFNGLSHADEROP1EXTPROC glShaderOp1EXT;
	extern PFNGLSHADEROP2EXTPROC glShaderOp2EXT;
	extern PFNGLSHADEROP3EXTPROC glShaderOp3EXT;
	extern PFNGLSWIZZLEEXTPROC glSwizzleEXT;
	extern PFNGLVARIANTBVEXTPROC glVariantbvEXT;
	extern PFNGLVARIANTDVEXTPROC glVariantdvEXT;
	extern PFNGLVARIANTFVEXTPROC glVariantfvEXT;
	extern PFNGLVARIANTIVEXTPROC glVariantivEXT;
	extern PFNGLVARIANTPOINTEREXTPROC glVariantPointerEXT;
	extern PFNGLVARIANTSVEXTPROC glVariantsvEXT;
	extern PFNGLVARIANTUBVEXTPROC glVariantubvEXT;
	extern PFNGLVARIANTUIVEXTPROC glVariantuivEXT;
	extern PFNGLVARIANTUSVEXTPROC glVariantusvEXT;
	extern PFNGLWRITEMASKEXTPROC glWriteMaskEXT;

	extern bool have_EXT_vertex_shader(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_vertex_shader_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_vertex_shader_NAMESPACE

//  ...for GL_EXT_vertex_weighting:
namespace GL_EXT_vertex_weighting_NAMESPACE {
	extern PFNGLVERTEXWEIGHTFEXTPROC glVertexWeightfEXT;
	extern PFNGLVERTEXWEIGHTFVEXTPROC glVertexWeightfvEXT;
	extern PFNGLVERTEXWEIGHTPOINTEREXTPROC glVertexWeightPointerEXT;

	extern bool have_EXT_vertex_weighting(); //<- for your use.

	//internal book-keeping stuff:
	class GL_EXT_vertex_weighting_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_EXT_vertex_weighting_NAMESPACE

//  ...for GL_GREMEDY_string_marker:
namespace GL_GREMEDY_string_marker_NAMESPACE {
	extern PFNGLSTRINGMARKERGREMEDYPROC glStringMarkerGREMEDY;

	extern bool have_GREMEDY_string_marker(); //<- for your use.

	//internal book-keeping stuff:
	class GL_GREMEDY_string_marker_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_GREMEDY_string_marker_NAMESPACE

//  ...for GL_HP_convolution_border_modes:
namespace GL_HP_convolution_border_modes_NAMESPACE {

	extern bool have_HP_convolution_border_modes(); //<- for your use.

	//internal book-keeping stuff:
	class GL_HP_convolution_border_modes_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_HP_convolution_border_modes_NAMESPACE

//  ...for GL_HP_image_transform:
namespace GL_HP_image_transform_NAMESPACE {
	extern PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC glGetImageTransformParameterfvHP;
	extern PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC glGetImageTransformParameterivHP;
	extern PFNGLIMAGETRANSFORMPARAMETERFHPPROC glImageTransformParameterfHP;
	extern PFNGLIMAGETRANSFORMPARAMETERFVHPPROC glImageTransformParameterfvHP;
	extern PFNGLIMAGETRANSFORMPARAMETERIHPPROC glImageTransformParameteriHP;
	extern PFNGLIMAGETRANSFORMPARAMETERIVHPPROC glImageTransformParameterivHP;

	extern bool have_HP_image_transform(); //<- for your use.

	//internal book-keeping stuff:
	class GL_HP_image_transform_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_HP_image_transform_NAMESPACE

//  ...for GL_HP_occlusion_test:
namespace GL_HP_occlusion_test_NAMESPACE {

	extern bool have_HP_occlusion_test(); //<- for your use.

	//internal book-keeping stuff:
	class GL_HP_occlusion_test_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_HP_occlusion_test_NAMESPACE

//  ...for GL_HP_texture_lighting:
namespace GL_HP_texture_lighting_NAMESPACE {

	extern bool have_HP_texture_lighting(); //<- for your use.

	//internal book-keeping stuff:
	class GL_HP_texture_lighting_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_HP_texture_lighting_NAMESPACE

//  ...for GL_IBM_cull_vertex:
namespace GL_IBM_cull_vertex_NAMESPACE {

	extern bool have_IBM_cull_vertex(); //<- for your use.

	//internal book-keeping stuff:
	class GL_IBM_cull_vertex_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_IBM_cull_vertex_NAMESPACE

//  ...for GL_IBM_multimode_draw_arrays:
namespace GL_IBM_multimode_draw_arrays_NAMESPACE {
	extern PFNGLMULTIMODEDRAWARRAYSIBMPROC glMultiModeDrawArraysIBM;
	extern PFNGLMULTIMODEDRAWELEMENTSIBMPROC glMultiModeDrawElementsIBM;

	extern bool have_IBM_multimode_draw_arrays(); //<- for your use.

	//internal book-keeping stuff:
	class GL_IBM_multimode_draw_arrays_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_IBM_multimode_draw_arrays_NAMESPACE

//  ...for GL_IBM_rasterpos_clip:
namespace GL_IBM_rasterpos_clip_NAMESPACE {

	extern bool have_IBM_rasterpos_clip(); //<- for your use.

	//internal book-keeping stuff:
	class GL_IBM_rasterpos_clip_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_IBM_rasterpos_clip_NAMESPACE

//  ...for GL_IBM_texture_mirrored_repeat:
namespace GL_IBM_texture_mirrored_repeat_NAMESPACE {

	extern bool have_IBM_texture_mirrored_repeat(); //<- for your use.

	//internal book-keeping stuff:
	class GL_IBM_texture_mirrored_repeat_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_IBM_texture_mirrored_repeat_NAMESPACE

//  ...for GL_IBM_vertex_array_lists:
namespace GL_IBM_vertex_array_lists_NAMESPACE {
	extern PFNGLCOLORPOINTERLISTIBMPROC glColorPointerListIBM;
	extern PFNGLEDGEFLAGPOINTERLISTIBMPROC glEdgeFlagPointerListIBM;
	extern PFNGLFOGCOORDPOINTERLISTIBMPROC glFogCoordPointerListIBM;
	extern PFNGLINDEXPOINTERLISTIBMPROC glIndexPointerListIBM;
	extern PFNGLNORMALPOINTERLISTIBMPROC glNormalPointerListIBM;
	extern PFNGLSECONDARYCOLORPOINTERLISTIBMPROC glSecondaryColorPointerListIBM;
	extern PFNGLTEXCOORDPOINTERLISTIBMPROC glTexCoordPointerListIBM;
	extern PFNGLVERTEXPOINTERLISTIBMPROC glVertexPointerListIBM;

	extern bool have_IBM_vertex_array_lists(); //<- for your use.

	//internal book-keeping stuff:
	class GL_IBM_vertex_array_lists_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_IBM_vertex_array_lists_NAMESPACE

//  ...for GL_INGR_blend_func_separate:
namespace GL_INGR_blend_func_separate_NAMESPACE {
	extern PFNGLBLENDFUNCSEPARATEINGRPROC glBlendFuncSeparateINGR;

	extern bool have_INGR_blend_func_separate(); //<- for your use.

	//internal book-keeping stuff:
	class GL_INGR_blend_func_separate_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_INGR_blend_func_separate_NAMESPACE

//  ...for GL_INGR_color_clamp:
namespace GL_INGR_color_clamp_NAMESPACE {

	extern bool have_INGR_color_clamp(); //<- for your use.

	//internal book-keeping stuff:
	class GL_INGR_color_clamp_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_INGR_color_clamp_NAMESPACE

//  ...for GL_INGR_interlace_read:
namespace GL_INGR_interlace_read_NAMESPACE {

	extern bool have_INGR_interlace_read(); //<- for your use.

	//internal book-keeping stuff:
	class GL_INGR_interlace_read_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_INGR_interlace_read_NAMESPACE

//  ...for GL_INGR_palette_buffer:
namespace GL_INGR_palette_buffer_NAMESPACE {

	extern bool have_INGR_palette_buffer(); //<- for your use.

	//internal book-keeping stuff:
	class GL_INGR_palette_buffer_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_INGR_palette_buffer_NAMESPACE

//  ...for GL_INTEL_parallel_arrays:
namespace GL_INTEL_parallel_arrays_NAMESPACE {
	extern PFNGLCOLORPOINTERVINTELPROC glColorPointervINTEL;
	extern PFNGLNORMALPOINTERVINTELPROC glNormalPointervINTEL;
	extern PFNGLTEXCOORDPOINTERVINTELPROC glTexCoordPointervINTEL;
	extern PFNGLVERTEXPOINTERVINTELPROC glVertexPointervINTEL;

	extern bool have_INTEL_parallel_arrays(); //<- for your use.

	//internal book-keeping stuff:
	class GL_INTEL_parallel_arrays_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_INTEL_parallel_arrays_NAMESPACE

//  ...for GL_INTEL_texture_scissor:
namespace GL_INTEL_texture_scissor_NAMESPACE {

	extern bool have_INTEL_texture_scissor(); //<- for your use.

	//internal book-keeping stuff:
	class GL_INTEL_texture_scissor_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_INTEL_texture_scissor_NAMESPACE

//  ...for GL_MESA_pack_invert:
namespace GL_MESA_pack_invert_NAMESPACE {

	extern bool have_MESA_pack_invert(); //<- for your use.

	//internal book-keeping stuff:
	class GL_MESA_pack_invert_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_MESA_pack_invert_NAMESPACE

//  ...for GL_MESA_resize_buffers:
namespace GL_MESA_resize_buffers_NAMESPACE {
	extern PFNGLRESIZEBUFFERSMESAPROC glResizeBuffersMESA;

	extern bool have_MESA_resize_buffers(); //<- for your use.

	//internal book-keeping stuff:
	class GL_MESA_resize_buffers_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_MESA_resize_buffers_NAMESPACE

//  ...for GL_MESA_window_pos:
namespace GL_MESA_window_pos_NAMESPACE {
	extern PFNGLWINDOWPOS2DMESAPROC glWindowPos2dMESA;
	extern PFNGLWINDOWPOS2DVMESAPROC glWindowPos2dvMESA;
	extern PFNGLWINDOWPOS2FMESAPROC glWindowPos2fMESA;
	extern PFNGLWINDOWPOS2FVMESAPROC glWindowPos2fvMESA;
	extern PFNGLWINDOWPOS2IMESAPROC glWindowPos2iMESA;
	extern PFNGLWINDOWPOS2IVMESAPROC glWindowPos2ivMESA;
	extern PFNGLWINDOWPOS2SMESAPROC glWindowPos2sMESA;
	extern PFNGLWINDOWPOS2SVMESAPROC glWindowPos2svMESA;
	extern PFNGLWINDOWPOS3DMESAPROC glWindowPos3dMESA;
	extern PFNGLWINDOWPOS3DVMESAPROC glWindowPos3dvMESA;
	extern PFNGLWINDOWPOS3FMESAPROC glWindowPos3fMESA;
	extern PFNGLWINDOWPOS3FVMESAPROC glWindowPos3fvMESA;
	extern PFNGLWINDOWPOS3IMESAPROC glWindowPos3iMESA;
	extern PFNGLWINDOWPOS3IVMESAPROC glWindowPos3ivMESA;
	extern PFNGLWINDOWPOS3SMESAPROC glWindowPos3sMESA;
	extern PFNGLWINDOWPOS3SVMESAPROC glWindowPos3svMESA;
	extern PFNGLWINDOWPOS4DMESAPROC glWindowPos4dMESA;
	extern PFNGLWINDOWPOS4DVMESAPROC glWindowPos4dvMESA;
	extern PFNGLWINDOWPOS4FMESAPROC glWindowPos4fMESA;
	extern PFNGLWINDOWPOS4FVMESAPROC glWindowPos4fvMESA;
	extern PFNGLWINDOWPOS4IMESAPROC glWindowPos4iMESA;
	extern PFNGLWINDOWPOS4IVMESAPROC glWindowPos4ivMESA;
	extern PFNGLWINDOWPOS4SMESAPROC glWindowPos4sMESA;
	extern PFNGLWINDOWPOS4SVMESAPROC glWindowPos4svMESA;

	extern bool have_MESA_window_pos(); //<- for your use.

	//internal book-keeping stuff:
	class GL_MESA_window_pos_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_MESA_window_pos_NAMESPACE

//  ...for GL_MESA_ycbcr_texture:
namespace GL_MESA_ycbcr_texture_NAMESPACE {

	extern bool have_MESA_ycbcr_texture(); //<- for your use.

	//internal book-keeping stuff:
	class GL_MESA_ycbcr_texture_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_MESA_ycbcr_texture_NAMESPACE

//  ...for GL_NV_blend_square:
namespace GL_NV_blend_square_NAMESPACE {

	extern bool have_NV_blend_square(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_blend_square_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_blend_square_NAMESPACE

//  ...for GL_NV_copy_depth_to_color:
namespace GL_NV_copy_depth_to_color_NAMESPACE {

	extern bool have_NV_copy_depth_to_color(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_copy_depth_to_color_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_copy_depth_to_color_NAMESPACE

//  ...for GL_NV_depth_clamp:
namespace GL_NV_depth_clamp_NAMESPACE {

	extern bool have_NV_depth_clamp(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_depth_clamp_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_depth_clamp_NAMESPACE

//  ...for GL_NV_evaluators:
namespace GL_NV_evaluators_NAMESPACE {
	extern PFNGLEVALMAPSNVPROC glEvalMapsNV;
	extern PFNGLGETMAPATTRIBPARAMETERFVNVPROC glGetMapAttribParameterfvNV;
	extern PFNGLGETMAPATTRIBPARAMETERIVNVPROC glGetMapAttribParameterivNV;
	extern PFNGLGETMAPCONTROLPOINTSNVPROC glGetMapControlPointsNV;
	extern PFNGLGETMAPPARAMETERFVNVPROC glGetMapParameterfvNV;
	extern PFNGLGETMAPPARAMETERIVNVPROC glGetMapParameterivNV;
	extern PFNGLMAPCONTROLPOINTSNVPROC glMapControlPointsNV;
	extern PFNGLMAPPARAMETERFVNVPROC glMapParameterfvNV;
	extern PFNGLMAPPARAMETERIVNVPROC glMapParameterivNV;

	extern bool have_NV_evaluators(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_evaluators_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_evaluators_NAMESPACE

//  ...for GL_NV_fence:
namespace GL_NV_fence_NAMESPACE {
	extern PFNGLDELETEFENCESNVPROC glDeleteFencesNV;
	extern PFNGLFINISHFENCENVPROC glFinishFenceNV;
	extern PFNGLGENFENCESNVPROC glGenFencesNV;
	extern PFNGLGETFENCEIVNVPROC glGetFenceivNV;
	extern PFNGLISFENCENVPROC glIsFenceNV;
	extern PFNGLSETFENCENVPROC glSetFenceNV;
	extern PFNGLTESTFENCENVPROC glTestFenceNV;

	extern bool have_NV_fence(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_fence_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_fence_NAMESPACE

//  ...for GL_NV_float_buffer:
namespace GL_NV_float_buffer_NAMESPACE {

	extern bool have_NV_float_buffer(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_float_buffer_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_float_buffer_NAMESPACE

//  ...for GL_NV_fog_distance:
namespace GL_NV_fog_distance_NAMESPACE {

	extern bool have_NV_fog_distance(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_fog_distance_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_fog_distance_NAMESPACE

//  ...for GL_NV_fragment_program:
namespace GL_NV_fragment_program_NAMESPACE {
	extern PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC glGetProgramNamedParameterdvNV;
	extern PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC glGetProgramNamedParameterfvNV;
	extern PFNGLPROGRAMNAMEDPARAMETER4DNVPROC glProgramNamedParameter4dNV;
	extern PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC glProgramNamedParameter4dvNV;
	extern PFNGLPROGRAMNAMEDPARAMETER4FNVPROC glProgramNamedParameter4fNV;
	extern PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC glProgramNamedParameter4fvNV;

	extern bool have_NV_fragment_program(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_fragment_program_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_fragment_program_NAMESPACE

//  ...for GL_NV_fragment_program2:
namespace GL_NV_fragment_program2_NAMESPACE {

	extern bool have_NV_fragment_program2(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_fragment_program2_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_fragment_program2_NAMESPACE

//  ...for GL_NV_fragment_program_option:
namespace GL_NV_fragment_program_option_NAMESPACE {

	extern bool have_NV_fragment_program_option(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_fragment_program_option_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_fragment_program_option_NAMESPACE

//  ...for GL_NV_half_float:
namespace GL_NV_half_float_NAMESPACE {
	extern PFNGLCOLOR3HNVPROC glColor3hNV;
	extern PFNGLCOLOR3HVNVPROC glColor3hvNV;
	extern PFNGLCOLOR4HNVPROC glColor4hNV;
	extern PFNGLCOLOR4HVNVPROC glColor4hvNV;
	extern PFNGLFOGCOORDHNVPROC glFogCoordhNV;
	extern PFNGLFOGCOORDHVNVPROC glFogCoordhvNV;
	extern PFNGLMULTITEXCOORD1HNVPROC glMultiTexCoord1hNV;
	extern PFNGLMULTITEXCOORD1HVNVPROC glMultiTexCoord1hvNV;
	extern PFNGLMULTITEXCOORD2HNVPROC glMultiTexCoord2hNV;
	extern PFNGLMULTITEXCOORD2HVNVPROC glMultiTexCoord2hvNV;
	extern PFNGLMULTITEXCOORD3HNVPROC glMultiTexCoord3hNV;
	extern PFNGLMULTITEXCOORD3HVNVPROC glMultiTexCoord3hvNV;
	extern PFNGLMULTITEXCOORD4HNVPROC glMultiTexCoord4hNV;
	extern PFNGLMULTITEXCOORD4HVNVPROC glMultiTexCoord4hvNV;
	extern PFNGLNORMAL3HNVPROC glNormal3hNV;
	extern PFNGLNORMAL3HVNVPROC glNormal3hvNV;
	extern PFNGLSECONDARYCOLOR3HNVPROC glSecondaryColor3hNV;
	extern PFNGLSECONDARYCOLOR3HVNVPROC glSecondaryColor3hvNV;
	extern PFNGLTEXCOORD1HNVPROC glTexCoord1hNV;
	extern PFNGLTEXCOORD1HVNVPROC glTexCoord1hvNV;
	extern PFNGLTEXCOORD2HNVPROC glTexCoord2hNV;
	extern PFNGLTEXCOORD2HVNVPROC glTexCoord2hvNV;
	extern PFNGLTEXCOORD3HNVPROC glTexCoord3hNV;
	extern PFNGLTEXCOORD3HVNVPROC glTexCoord3hvNV;
	extern PFNGLTEXCOORD4HNVPROC glTexCoord4hNV;
	extern PFNGLTEXCOORD4HVNVPROC glTexCoord4hvNV;
	extern PFNGLVERTEX2HNVPROC glVertex2hNV;
	extern PFNGLVERTEX2HVNVPROC glVertex2hvNV;
	extern PFNGLVERTEX3HNVPROC glVertex3hNV;
	extern PFNGLVERTEX3HVNVPROC glVertex3hvNV;
	extern PFNGLVERTEX4HNVPROC glVertex4hNV;
	extern PFNGLVERTEX4HVNVPROC glVertex4hvNV;
	extern PFNGLVERTEXATTRIB1HNVPROC glVertexAttrib1hNV;
	extern PFNGLVERTEXATTRIB1HVNVPROC glVertexAttrib1hvNV;
	extern PFNGLVERTEXATTRIB2HNVPROC glVertexAttrib2hNV;
	extern PFNGLVERTEXATTRIB2HVNVPROC glVertexAttrib2hvNV;
	extern PFNGLVERTEXATTRIB3HNVPROC glVertexAttrib3hNV;
	extern PFNGLVERTEXATTRIB3HVNVPROC glVertexAttrib3hvNV;
	extern PFNGLVERTEXATTRIB4HNVPROC glVertexAttrib4hNV;
	extern PFNGLVERTEXATTRIB4HVNVPROC glVertexAttrib4hvNV;
	extern PFNGLVERTEXATTRIBS1HVNVPROC glVertexAttribs1hvNV;
	extern PFNGLVERTEXATTRIBS2HVNVPROC glVertexAttribs2hvNV;
	extern PFNGLVERTEXATTRIBS3HVNVPROC glVertexAttribs3hvNV;
	extern PFNGLVERTEXATTRIBS4HVNVPROC glVertexAttribs4hvNV;
	extern PFNGLVERTEXWEIGHTHNVPROC glVertexWeighthNV;
	extern PFNGLVERTEXWEIGHTHVNVPROC glVertexWeighthvNV;

	extern bool have_NV_half_float(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_half_float_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_half_float_NAMESPACE

//  ...for GL_NV_light_max_exponent:
namespace GL_NV_light_max_exponent_NAMESPACE {

	extern bool have_NV_light_max_exponent(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_light_max_exponent_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_light_max_exponent_NAMESPACE

//  ...for GL_NV_multisample_filter_hint:
namespace GL_NV_multisample_filter_hint_NAMESPACE {

	extern bool have_NV_multisample_filter_hint(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_multisample_filter_hint_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_multisample_filter_hint_NAMESPACE

//  ...for GL_NV_occlusion_query:
namespace GL_NV_occlusion_query_NAMESPACE {
	extern PFNGLBEGINOCCLUSIONQUERYNVPROC glBeginOcclusionQueryNV;
	extern PFNGLDELETEOCCLUSIONQUERIESNVPROC glDeleteOcclusionQueriesNV;
	extern PFNGLENDOCCLUSIONQUERYNVPROC glEndOcclusionQueryNV;
	extern PFNGLGENOCCLUSIONQUERIESNVPROC glGenOcclusionQueriesNV;
	extern PFNGLGETOCCLUSIONQUERYIVNVPROC glGetOcclusionQueryivNV;
	extern PFNGLGETOCCLUSIONQUERYUIVNVPROC glGetOcclusionQueryuivNV;
	extern PFNGLISOCCLUSIONQUERYNVPROC glIsOcclusionQueryNV;

	extern bool have_NV_occlusion_query(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_occlusion_query_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_occlusion_query_NAMESPACE

//  ...for GL_NV_packed_depth_stencil:
namespace GL_NV_packed_depth_stencil_NAMESPACE {

	extern bool have_NV_packed_depth_stencil(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_packed_depth_stencil_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_packed_depth_stencil_NAMESPACE

//  ...for GL_NV_pixel_data_range:
namespace GL_NV_pixel_data_range_NAMESPACE {
	extern PFNGLFLUSHPIXELDATARANGENVPROC glFlushPixelDataRangeNV;
	extern PFNGLPIXELDATARANGENVPROC glPixelDataRangeNV;

	extern bool have_NV_pixel_data_range(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_pixel_data_range_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_pixel_data_range_NAMESPACE

//  ...for GL_NV_point_sprite:
namespace GL_NV_point_sprite_NAMESPACE {
	extern PFNGLPOINTPARAMETERINVPROC glPointParameteriNV;
	extern PFNGLPOINTPARAMETERIVNVPROC glPointParameterivNV;

	extern bool have_NV_point_sprite(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_point_sprite_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_point_sprite_NAMESPACE

//  ...for GL_NV_primitive_restart:
namespace GL_NV_primitive_restart_NAMESPACE {
	extern PFNGLPRIMITIVERESTARTINDEXNVPROC glPrimitiveRestartIndexNV;
	extern PFNGLPRIMITIVERESTARTNVPROC glPrimitiveRestartNV;

	extern bool have_NV_primitive_restart(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_primitive_restart_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_primitive_restart_NAMESPACE

//  ...for GL_NV_register_combiners:
namespace GL_NV_register_combiners_NAMESPACE {
	extern PFNGLCOMBINERINPUTNVPROC glCombinerInputNV;
	extern PFNGLCOMBINEROUTPUTNVPROC glCombinerOutputNV;
	extern PFNGLCOMBINERPARAMETERFNVPROC glCombinerParameterfNV;
	extern PFNGLCOMBINERPARAMETERFVNVPROC glCombinerParameterfvNV;
	extern PFNGLCOMBINERPARAMETERINVPROC glCombinerParameteriNV;
	extern PFNGLCOMBINERPARAMETERIVNVPROC glCombinerParameterivNV;
	extern PFNGLFINALCOMBINERINPUTNVPROC glFinalCombinerInputNV;
	extern PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC glGetCombinerInputParameterfvNV;
	extern PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC glGetCombinerInputParameterivNV;
	extern PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC glGetCombinerOutputParameterfvNV;
	extern PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC glGetCombinerOutputParameterivNV;
	extern PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC glGetFinalCombinerInputParameterfvNV;
	extern PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC glGetFinalCombinerInputParameterivNV;

	extern bool have_NV_register_combiners(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_register_combiners_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_register_combiners_NAMESPACE

//  ...for GL_NV_register_combiners2:
namespace GL_NV_register_combiners2_NAMESPACE {
	extern PFNGLCOMBINERSTAGEPARAMETERFVNVPROC glCombinerStageParameterfvNV;
	extern PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC glGetCombinerStageParameterfvNV;

	extern bool have_NV_register_combiners2(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_register_combiners2_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_register_combiners2_NAMESPACE

//  ...for GL_NV_texgen_emboss:
namespace GL_NV_texgen_emboss_NAMESPACE {

	extern bool have_NV_texgen_emboss(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_texgen_emboss_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_texgen_emboss_NAMESPACE

//  ...for GL_NV_texgen_reflection:
namespace GL_NV_texgen_reflection_NAMESPACE {

	extern bool have_NV_texgen_reflection(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_texgen_reflection_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_texgen_reflection_NAMESPACE

//  ...for GL_NV_texture_compression_vtc:
namespace GL_NV_texture_compression_vtc_NAMESPACE {

	extern bool have_NV_texture_compression_vtc(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_texture_compression_vtc_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_texture_compression_vtc_NAMESPACE

//  ...for GL_NV_texture_env_combine4:
namespace GL_NV_texture_env_combine4_NAMESPACE {

	extern bool have_NV_texture_env_combine4(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_texture_env_combine4_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_texture_env_combine4_NAMESPACE

//  ...for GL_NV_texture_expand_normal:
namespace GL_NV_texture_expand_normal_NAMESPACE {

	extern bool have_NV_texture_expand_normal(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_texture_expand_normal_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_texture_expand_normal_NAMESPACE

//  ...for GL_NV_texture_rectangle:
namespace GL_NV_texture_rectangle_NAMESPACE {

	extern bool have_NV_texture_rectangle(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_texture_rectangle_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_texture_rectangle_NAMESPACE

//  ...for GL_NV_texture_shader:
namespace GL_NV_texture_shader_NAMESPACE {

	extern bool have_NV_texture_shader(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_texture_shader_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_texture_shader_NAMESPACE

//  ...for GL_NV_texture_shader2:
namespace GL_NV_texture_shader2_NAMESPACE {

	extern bool have_NV_texture_shader2(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_texture_shader2_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_texture_shader2_NAMESPACE

//  ...for GL_NV_texture_shader3:
namespace GL_NV_texture_shader3_NAMESPACE {

	extern bool have_NV_texture_shader3(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_texture_shader3_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_texture_shader3_NAMESPACE

//  ...for GL_NV_vertex_array_range:
namespace GL_NV_vertex_array_range_NAMESPACE {
	extern PFNGLFLUSHVERTEXARRAYRANGENVPROC glFlushVertexArrayRangeNV;
	extern PFNGLVERTEXARRAYRANGENVPROC glVertexArrayRangeNV;

	extern bool have_NV_vertex_array_range(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_vertex_array_range_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_vertex_array_range_NAMESPACE

//  ...for GL_NV_vertex_array_range2:
namespace GL_NV_vertex_array_range2_NAMESPACE {

	extern bool have_NV_vertex_array_range2(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_vertex_array_range2_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_vertex_array_range2_NAMESPACE

//  ...for GL_NV_vertex_program:
namespace GL_NV_vertex_program_NAMESPACE {
	extern PFNGLAREPROGRAMSRESIDENTNVPROC glAreProgramsResidentNV;
	extern PFNGLBINDPROGRAMNVPROC glBindProgramNV;
	extern PFNGLDELETEPROGRAMSNVPROC glDeleteProgramsNV;
	extern PFNGLEXECUTEPROGRAMNVPROC glExecuteProgramNV;
	extern PFNGLGENPROGRAMSNVPROC glGenProgramsNV;
	extern PFNGLGETPROGRAMIVNVPROC glGetProgramivNV;
	extern PFNGLGETPROGRAMPARAMETERDVNVPROC glGetProgramParameterdvNV;
	extern PFNGLGETPROGRAMPARAMETERFVNVPROC glGetProgramParameterfvNV;
	extern PFNGLGETPROGRAMSTRINGNVPROC glGetProgramStringNV;
	extern PFNGLGETTRACKMATRIXIVNVPROC glGetTrackMatrixivNV;
	extern PFNGLGETVERTEXATTRIBDVNVPROC glGetVertexAttribdvNV;
	extern PFNGLGETVERTEXATTRIBFVNVPROC glGetVertexAttribfvNV;
	extern PFNGLGETVERTEXATTRIBIVNVPROC glGetVertexAttribivNV;
	extern PFNGLGETVERTEXATTRIBPOINTERVNVPROC glGetVertexAttribPointervNV;
	extern PFNGLISPROGRAMNVPROC glIsProgramNV;
	extern PFNGLLOADPROGRAMNVPROC glLoadProgramNV;
	extern PFNGLPROGRAMPARAMETER4DNVPROC glProgramParameter4dNV;
	extern PFNGLPROGRAMPARAMETER4DVNVPROC glProgramParameter4dvNV;
	extern PFNGLPROGRAMPARAMETER4FNVPROC glProgramParameter4fNV;
	extern PFNGLPROGRAMPARAMETER4FVNVPROC glProgramParameter4fvNV;
	extern PFNGLPROGRAMPARAMETERS4DVNVPROC glProgramParameters4dvNV;
	extern PFNGLPROGRAMPARAMETERS4FVNVPROC glProgramParameters4fvNV;
	extern PFNGLREQUESTRESIDENTPROGRAMSNVPROC glRequestResidentProgramsNV;
	extern PFNGLTRACKMATRIXNVPROC glTrackMatrixNV;
	extern PFNGLVERTEXATTRIB1DNVPROC glVertexAttrib1dNV;
	extern PFNGLVERTEXATTRIB1DVNVPROC glVertexAttrib1dvNV;
	extern PFNGLVERTEXATTRIB1FNVPROC glVertexAttrib1fNV;
	extern PFNGLVERTEXATTRIB1FVNVPROC glVertexAttrib1fvNV;
	extern PFNGLVERTEXATTRIB1SNVPROC glVertexAttrib1sNV;
	extern PFNGLVERTEXATTRIB1SVNVPROC glVertexAttrib1svNV;
	extern PFNGLVERTEXATTRIB2DNVPROC glVertexAttrib2dNV;
	extern PFNGLVERTEXATTRIB2DVNVPROC glVertexAttrib2dvNV;
	extern PFNGLVERTEXATTRIB2FNVPROC glVertexAttrib2fNV;
	extern PFNGLVERTEXATTRIB2FVNVPROC glVertexAttrib2fvNV;
	extern PFNGLVERTEXATTRIB2SNVPROC glVertexAttrib2sNV;
	extern PFNGLVERTEXATTRIB2SVNVPROC glVertexAttrib2svNV;
	extern PFNGLVERTEXATTRIB3DNVPROC glVertexAttrib3dNV;
	extern PFNGLVERTEXATTRIB3DVNVPROC glVertexAttrib3dvNV;
	extern PFNGLVERTEXATTRIB3FNVPROC glVertexAttrib3fNV;
	extern PFNGLVERTEXATTRIB3FVNVPROC glVertexAttrib3fvNV;
	extern PFNGLVERTEXATTRIB3SNVPROC glVertexAttrib3sNV;
	extern PFNGLVERTEXATTRIB3SVNVPROC glVertexAttrib3svNV;
	extern PFNGLVERTEXATTRIB4DNVPROC glVertexAttrib4dNV;
	extern PFNGLVERTEXATTRIB4DVNVPROC glVertexAttrib4dvNV;
	extern PFNGLVERTEXATTRIB4FNVPROC glVertexAttrib4fNV;
	extern PFNGLVERTEXATTRIB4FVNVPROC glVertexAttrib4fvNV;
	extern PFNGLVERTEXATTRIB4SNVPROC glVertexAttrib4sNV;
	extern PFNGLVERTEXATTRIB4SVNVPROC glVertexAttrib4svNV;
	extern PFNGLVERTEXATTRIB4UBNVPROC glVertexAttrib4ubNV;
	extern PFNGLVERTEXATTRIB4UBVNVPROC glVertexAttrib4ubvNV;
	extern PFNGLVERTEXATTRIBPOINTERNVPROC glVertexAttribPointerNV;
	extern PFNGLVERTEXATTRIBS1DVNVPROC glVertexAttribs1dvNV;
	extern PFNGLVERTEXATTRIBS1FVNVPROC glVertexAttribs1fvNV;
	extern PFNGLVERTEXATTRIBS1SVNVPROC glVertexAttribs1svNV;
	extern PFNGLVERTEXATTRIBS2DVNVPROC glVertexAttribs2dvNV;
	extern PFNGLVERTEXATTRIBS2FVNVPROC glVertexAttribs2fvNV;
	extern PFNGLVERTEXATTRIBS2SVNVPROC glVertexAttribs2svNV;
	extern PFNGLVERTEXATTRIBS3DVNVPROC glVertexAttribs3dvNV;
	extern PFNGLVERTEXATTRIBS3FVNVPROC glVertexAttribs3fvNV;
	extern PFNGLVERTEXATTRIBS3SVNVPROC glVertexAttribs3svNV;
	extern PFNGLVERTEXATTRIBS4DVNVPROC glVertexAttribs4dvNV;
	extern PFNGLVERTEXATTRIBS4FVNVPROC glVertexAttribs4fvNV;
	extern PFNGLVERTEXATTRIBS4SVNVPROC glVertexAttribs4svNV;
	extern PFNGLVERTEXATTRIBS4UBVNVPROC glVertexAttribs4ubvNV;

	extern bool have_NV_vertex_program(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_vertex_program_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_vertex_program_NAMESPACE

//  ...for GL_NV_vertex_program1_1:
namespace GL_NV_vertex_program1_1_NAMESPACE {

	extern bool have_NV_vertex_program1_1(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_vertex_program1_1_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_vertex_program1_1_NAMESPACE

//  ...for GL_NV_vertex_program2:
namespace GL_NV_vertex_program2_NAMESPACE {

	extern bool have_NV_vertex_program2(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_vertex_program2_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_vertex_program2_NAMESPACE

//  ...for GL_NV_vertex_program2_option:
namespace GL_NV_vertex_program2_option_NAMESPACE {

	extern bool have_NV_vertex_program2_option(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_vertex_program2_option_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_vertex_program2_option_NAMESPACE

//  ...for GL_NV_vertex_program3:
namespace GL_NV_vertex_program3_NAMESPACE {

	extern bool have_NV_vertex_program3(); //<- for your use.

	//internal book-keeping stuff:
	class GL_NV_vertex_program3_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_NV_vertex_program3_NAMESPACE

//  ...for GL_OES_read_format:
namespace GL_OES_read_format_NAMESPACE {

	extern bool have_OES_read_format(); //<- for your use.

	//internal book-keeping stuff:
	class GL_OES_read_format_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_OES_read_format_NAMESPACE

//  ...for GL_OML_interlace:
namespace GL_OML_interlace_NAMESPACE {

	extern bool have_OML_interlace(); //<- for your use.

	//internal book-keeping stuff:
	class GL_OML_interlace_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_OML_interlace_NAMESPACE

//  ...for GL_OML_resample:
namespace GL_OML_resample_NAMESPACE {

	extern bool have_OML_resample(); //<- for your use.

	//internal book-keeping stuff:
	class GL_OML_resample_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_OML_resample_NAMESPACE

//  ...for GL_OML_subsample:
namespace GL_OML_subsample_NAMESPACE {

	extern bool have_OML_subsample(); //<- for your use.

	//internal book-keeping stuff:
	class GL_OML_subsample_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_OML_subsample_NAMESPACE

//  ...for GL_PGI_misc_hints:
namespace GL_PGI_misc_hints_NAMESPACE {
	extern PFNGLHINTPGIPROC glHintPGI;

	extern bool have_PGI_misc_hints(); //<- for your use.

	//internal book-keeping stuff:
	class GL_PGI_misc_hints_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_PGI_misc_hints_NAMESPACE

//  ...for GL_PGI_vertex_hints:
namespace GL_PGI_vertex_hints_NAMESPACE {

	extern bool have_PGI_vertex_hints(); //<- for your use.

	//internal book-keeping stuff:
	class GL_PGI_vertex_hints_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_PGI_vertex_hints_NAMESPACE

//  ...for GL_REND_screen_coordinates:
namespace GL_REND_screen_coordinates_NAMESPACE {

	extern bool have_REND_screen_coordinates(); //<- for your use.

	//internal book-keeping stuff:
	class GL_REND_screen_coordinates_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_REND_screen_coordinates_NAMESPACE

//  ...for GL_SGIS_detail_texture:
namespace GL_SGIS_detail_texture_NAMESPACE {
	extern PFNGLDETAILTEXFUNCSGISPROC glDetailTexFuncSGIS;
	extern PFNGLGETDETAILTEXFUNCSGISPROC glGetDetailTexFuncSGIS;

	extern bool have_SGIS_detail_texture(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIS_detail_texture_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIS_detail_texture_NAMESPACE

//  ...for GL_SGIS_fog_function:
namespace GL_SGIS_fog_function_NAMESPACE {
	extern PFNGLFOGFUNCSGISPROC glFogFuncSGIS;
	extern PFNGLGETFOGFUNCSGISPROC glGetFogFuncSGIS;

	extern bool have_SGIS_fog_function(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIS_fog_function_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIS_fog_function_NAMESPACE

//  ...for GL_SGIS_generate_mipmap:
namespace GL_SGIS_generate_mipmap_NAMESPACE {

	extern bool have_SGIS_generate_mipmap(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIS_generate_mipmap_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIS_generate_mipmap_NAMESPACE

//  ...for GL_SGIS_multisample:
namespace GL_SGIS_multisample_NAMESPACE {
	extern PFNGLSAMPLEMASKSGISPROC glSampleMaskSGIS;
	extern PFNGLSAMPLEPATTERNSGISPROC glSamplePatternSGIS;

	extern bool have_SGIS_multisample(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIS_multisample_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIS_multisample_NAMESPACE

//  ...for GL_SGIS_pixel_texture:
namespace GL_SGIS_pixel_texture_NAMESPACE {
	extern PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC glGetPixelTexGenParameterfvSGIS;
	extern PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC glGetPixelTexGenParameterivSGIS;
	extern PFNGLPIXELTEXGENPARAMETERFSGISPROC glPixelTexGenParameterfSGIS;
	extern PFNGLPIXELTEXGENPARAMETERFVSGISPROC glPixelTexGenParameterfvSGIS;
	extern PFNGLPIXELTEXGENPARAMETERISGISPROC glPixelTexGenParameteriSGIS;
	extern PFNGLPIXELTEXGENPARAMETERIVSGISPROC glPixelTexGenParameterivSGIS;

	extern bool have_SGIS_pixel_texture(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIS_pixel_texture_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIS_pixel_texture_NAMESPACE

//  ...for GL_SGIS_point_line_texgen:
namespace GL_SGIS_point_line_texgen_NAMESPACE {

	extern bool have_SGIS_point_line_texgen(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIS_point_line_texgen_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIS_point_line_texgen_NAMESPACE

//  ...for GL_SGIS_point_parameters:
namespace GL_SGIS_point_parameters_NAMESPACE {
	extern PFNGLPOINTPARAMETERFSGISPROC glPointParameterfSGIS;
	extern PFNGLPOINTPARAMETERFVSGISPROC glPointParameterfvSGIS;

	extern bool have_SGIS_point_parameters(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIS_point_parameters_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIS_point_parameters_NAMESPACE

//  ...for GL_SGIS_sharpen_texture:
namespace GL_SGIS_sharpen_texture_NAMESPACE {
	extern PFNGLGETSHARPENTEXFUNCSGISPROC glGetSharpenTexFuncSGIS;
	extern PFNGLSHARPENTEXFUNCSGISPROC glSharpenTexFuncSGIS;

	extern bool have_SGIS_sharpen_texture(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIS_sharpen_texture_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIS_sharpen_texture_NAMESPACE

//  ...for GL_SGIS_texture4:
namespace GL_SGIS_texture4_NAMESPACE {
	extern PFNGLTEXIMAGE4DSGISPROC glTexImage4DSGIS;
	extern PFNGLTEXSUBIMAGE4DSGISPROC glTexSubImage4DSGIS;

	extern bool have_SGIS_texture4(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIS_texture4_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIS_texture4_NAMESPACE

//  ...for GL_SGIS_texture_border_clamp:
namespace GL_SGIS_texture_border_clamp_NAMESPACE {

	extern bool have_SGIS_texture_border_clamp(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIS_texture_border_clamp_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIS_texture_border_clamp_NAMESPACE

//  ...for GL_SGIS_texture_color_mask:
namespace GL_SGIS_texture_color_mask_NAMESPACE {
	extern PFNGLTEXTURECOLORMASKSGISPROC glTextureColorMaskSGIS;

	extern bool have_SGIS_texture_color_mask(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIS_texture_color_mask_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIS_texture_color_mask_NAMESPACE

//  ...for GL_SGIS_texture_edge_clamp:
namespace GL_SGIS_texture_edge_clamp_NAMESPACE {

	extern bool have_SGIS_texture_edge_clamp(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIS_texture_edge_clamp_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIS_texture_edge_clamp_NAMESPACE

//  ...for GL_SGIS_texture_filter4:
namespace GL_SGIS_texture_filter4_NAMESPACE {
	extern PFNGLGETTEXFILTERFUNCSGISPROC glGetTexFilterFuncSGIS;
	extern PFNGLTEXFILTERFUNCSGISPROC glTexFilterFuncSGIS;

	extern bool have_SGIS_texture_filter4(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIS_texture_filter4_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIS_texture_filter4_NAMESPACE

//  ...for GL_SGIS_texture_lod:
namespace GL_SGIS_texture_lod_NAMESPACE {

	extern bool have_SGIS_texture_lod(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIS_texture_lod_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIS_texture_lod_NAMESPACE

//  ...for GL_SGIS_texture_select:
namespace GL_SGIS_texture_select_NAMESPACE {

	extern bool have_SGIS_texture_select(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIS_texture_select_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIS_texture_select_NAMESPACE

//  ...for GL_SGIX_async:
namespace GL_SGIX_async_NAMESPACE {
	extern PFNGLASYNCMARKERSGIXPROC glAsyncMarkerSGIX;
	extern PFNGLDELETEASYNCMARKERSSGIXPROC glDeleteAsyncMarkersSGIX;
	extern PFNGLFINISHASYNCSGIXPROC glFinishAsyncSGIX;
	extern PFNGLGENASYNCMARKERSSGIXPROC glGenAsyncMarkersSGIX;
	extern PFNGLISASYNCMARKERSGIXPROC glIsAsyncMarkerSGIX;
	extern PFNGLPOLLASYNCSGIXPROC glPollAsyncSGIX;

	extern bool have_SGIX_async(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_async_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_async_NAMESPACE

//  ...for GL_SGIX_async_histogram:
namespace GL_SGIX_async_histogram_NAMESPACE {

	extern bool have_SGIX_async_histogram(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_async_histogram_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_async_histogram_NAMESPACE

//  ...for GL_SGIX_async_pixel:
namespace GL_SGIX_async_pixel_NAMESPACE {

	extern bool have_SGIX_async_pixel(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_async_pixel_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_async_pixel_NAMESPACE

//  ...for GL_SGIX_blend_alpha_minmax:
namespace GL_SGIX_blend_alpha_minmax_NAMESPACE {

	extern bool have_SGIX_blend_alpha_minmax(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_blend_alpha_minmax_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_blend_alpha_minmax_NAMESPACE

//  ...for GL_SGIX_calligraphic_fragment:
namespace GL_SGIX_calligraphic_fragment_NAMESPACE {

	extern bool have_SGIX_calligraphic_fragment(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_calligraphic_fragment_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_calligraphic_fragment_NAMESPACE

//  ...for GL_SGIX_clipmap:
namespace GL_SGIX_clipmap_NAMESPACE {

	extern bool have_SGIX_clipmap(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_clipmap_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_clipmap_NAMESPACE

//  ...for GL_SGIX_convolution_accuracy:
namespace GL_SGIX_convolution_accuracy_NAMESPACE {

	extern bool have_SGIX_convolution_accuracy(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_convolution_accuracy_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_convolution_accuracy_NAMESPACE

//  ...for GL_SGIX_depth_pass_instrument:
namespace GL_SGIX_depth_pass_instrument_NAMESPACE {
	extern PFNGLTBUFFERMASK3DFXPROC glTbufferMask3DFX;

	extern bool have_SGIX_depth_pass_instrument(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_depth_pass_instrument_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_depth_pass_instrument_NAMESPACE

//  ...for GL_SGIX_depth_texture:
namespace GL_SGIX_depth_texture_NAMESPACE {

	extern bool have_SGIX_depth_texture(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_depth_texture_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_depth_texture_NAMESPACE

//  ...for GL_SGIX_flush_raster:
namespace GL_SGIX_flush_raster_NAMESPACE {
	extern PFNGLFLUSHRASTERSGIXPROC glFlushRasterSGIX;

	extern bool have_SGIX_flush_raster(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_flush_raster_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_flush_raster_NAMESPACE

//  ...for GL_SGIX_fog_offset:
namespace GL_SGIX_fog_offset_NAMESPACE {

	extern bool have_SGIX_fog_offset(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_fog_offset_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_fog_offset_NAMESPACE

//  ...for GL_SGIX_fog_scale:
namespace GL_SGIX_fog_scale_NAMESPACE {

	extern bool have_SGIX_fog_scale(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_fog_scale_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_fog_scale_NAMESPACE

//  ...for GL_SGIX_fragment_lighting:
namespace GL_SGIX_fragment_lighting_NAMESPACE {
	extern PFNGLFRAGMENTCOLORMATERIALSGIXPROC glFragmentColorMaterialSGIX;
	extern PFNGLFRAGMENTLIGHTFSGIXPROC glFragmentLightfSGIX;
	extern PFNGLFRAGMENTLIGHTFVSGIXPROC glFragmentLightfvSGIX;
	extern PFNGLFRAGMENTLIGHTISGIXPROC glFragmentLightiSGIX;
	extern PFNGLFRAGMENTLIGHTIVSGIXPROC glFragmentLightivSGIX;
	extern PFNGLFRAGMENTLIGHTMODELFSGIXPROC glFragmentLightModelfSGIX;
	extern PFNGLFRAGMENTLIGHTMODELFVSGIXPROC glFragmentLightModelfvSGIX;
	extern PFNGLFRAGMENTLIGHTMODELISGIXPROC glFragmentLightModeliSGIX;
	extern PFNGLFRAGMENTLIGHTMODELIVSGIXPROC glFragmentLightModelivSGIX;
	extern PFNGLFRAGMENTMATERIALFSGIXPROC glFragmentMaterialfSGIX;
	extern PFNGLFRAGMENTMATERIALFVSGIXPROC glFragmentMaterialfvSGIX;
	extern PFNGLFRAGMENTMATERIALISGIXPROC glFragmentMaterialiSGIX;
	extern PFNGLFRAGMENTMATERIALIVSGIXPROC glFragmentMaterialivSGIX;
	extern PFNGLGETFRAGMENTLIGHTFVSGIXPROC glGetFragmentLightfvSGIX;
	extern PFNGLGETFRAGMENTLIGHTIVSGIXPROC glGetFragmentLightivSGIX;
	extern PFNGLGETFRAGMENTMATERIALFVSGIXPROC glGetFragmentMaterialfvSGIX;
	extern PFNGLGETFRAGMENTMATERIALIVSGIXPROC glGetFragmentMaterialivSGIX;
	extern PFNGLLIGHTENVISGIXPROC glLightEnviSGIX;

	extern bool have_SGIX_fragment_lighting(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_fragment_lighting_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_fragment_lighting_NAMESPACE

//  ...for GL_SGIX_framezoom:
namespace GL_SGIX_framezoom_NAMESPACE {
	extern PFNGLFRAMEZOOMSGIXPROC glFrameZoomSGIX;

	extern bool have_SGIX_framezoom(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_framezoom_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_framezoom_NAMESPACE

//  ...for GL_SGIX_igloo_interface:
namespace GL_SGIX_igloo_interface_NAMESPACE {
	extern PFNGLIGLOOINTERFACESGIXPROC glIglooInterfaceSGIX;

	extern bool have_SGIX_igloo_interface(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_igloo_interface_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_igloo_interface_NAMESPACE

//  ...for GL_SGIX_impact_pixel_texture:
namespace GL_SGIX_impact_pixel_texture_NAMESPACE {

	extern bool have_SGIX_impact_pixel_texture(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_impact_pixel_texture_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_impact_pixel_texture_NAMESPACE

//  ...for GL_SGIX_instruments:
namespace GL_SGIX_instruments_NAMESPACE {
	extern PFNGLGETINSTRUMENTSSGIXPROC glGetInstrumentsSGIX;
	extern PFNGLINSTRUMENTSBUFFERSGIXPROC glInstrumentsBufferSGIX;
	extern PFNGLPOLLINSTRUMENTSSGIXPROC glPollInstrumentsSGIX;
	extern PFNGLREADINSTRUMENTSSGIXPROC glReadInstrumentsSGIX;
	extern PFNGLSTARTINSTRUMENTSSGIXPROC glStartInstrumentsSGIX;
	extern PFNGLSTOPINSTRUMENTSSGIXPROC glStopInstrumentsSGIX;

	extern bool have_SGIX_instruments(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_instruments_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_instruments_NAMESPACE

//  ...for GL_SGIX_interlace:
namespace GL_SGIX_interlace_NAMESPACE {

	extern bool have_SGIX_interlace(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_interlace_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_interlace_NAMESPACE

//  ...for GL_SGIX_ir_instrument1:
namespace GL_SGIX_ir_instrument1_NAMESPACE {

	extern bool have_SGIX_ir_instrument1(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_ir_instrument1_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_ir_instrument1_NAMESPACE

//  ...for GL_SGIX_list_priority:
namespace GL_SGIX_list_priority_NAMESPACE {
	extern PFNGLGETLISTPARAMETERFVSGIXPROC glGetListParameterfvSGIX;
	extern PFNGLGETLISTPARAMETERIVSGIXPROC glGetListParameterivSGIX;
	extern PFNGLLISTPARAMETERFSGIXPROC glListParameterfSGIX;
	extern PFNGLLISTPARAMETERFVSGIXPROC glListParameterfvSGIX;
	extern PFNGLLISTPARAMETERISGIXPROC glListParameteriSGIX;
	extern PFNGLLISTPARAMETERIVSGIXPROC glListParameterivSGIX;

	extern bool have_SGIX_list_priority(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_list_priority_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_list_priority_NAMESPACE

//  ...for GL_SGIX_pixel_texture:
namespace GL_SGIX_pixel_texture_NAMESPACE {
	extern PFNGLPIXELTEXGENSGIXPROC glPixelTexGenSGIX;

	extern bool have_SGIX_pixel_texture(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_pixel_texture_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_pixel_texture_NAMESPACE

//  ...for GL_SGIX_pixel_tiles:
namespace GL_SGIX_pixel_tiles_NAMESPACE {

	extern bool have_SGIX_pixel_tiles(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_pixel_tiles_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_pixel_tiles_NAMESPACE

//  ...for GL_SGIX_polynomial_ffd:
namespace GL_SGIX_polynomial_ffd_NAMESPACE {
	extern PFNGLDEFORMATIONMAP3DSGIXPROC glDeformationMap3dSGIX;
	extern PFNGLDEFORMATIONMAP3FSGIXPROC glDeformationMap3fSGIX;
	extern PFNGLDEFORMSGIXPROC glDeformSGIX;
	extern PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC glLoadIdentityDeformationMapSGIX;

	extern bool have_SGIX_polynomial_ffd(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_polynomial_ffd_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_polynomial_ffd_NAMESPACE

//  ...for GL_SGIX_reference_plane:
namespace GL_SGIX_reference_plane_NAMESPACE {
	extern PFNGLREFERENCEPLANESGIXPROC glReferencePlaneSGIX;

	extern bool have_SGIX_reference_plane(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_reference_plane_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_reference_plane_NAMESPACE

//  ...for GL_SGIX_resample:
namespace GL_SGIX_resample_NAMESPACE {

	extern bool have_SGIX_resample(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_resample_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_resample_NAMESPACE

//  ...for GL_SGIX_scalebias_hint:
namespace GL_SGIX_scalebias_hint_NAMESPACE {

	extern bool have_SGIX_scalebias_hint(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_scalebias_hint_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_scalebias_hint_NAMESPACE

//  ...for GL_SGIX_shadow:
namespace GL_SGIX_shadow_NAMESPACE {

	extern bool have_SGIX_shadow(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_shadow_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_shadow_NAMESPACE

//  ...for GL_SGIX_shadow_ambient:
namespace GL_SGIX_shadow_ambient_NAMESPACE {

	extern bool have_SGIX_shadow_ambient(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_shadow_ambient_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_shadow_ambient_NAMESPACE

//  ...for GL_SGIX_sprite:
namespace GL_SGIX_sprite_NAMESPACE {
	extern PFNGLSPRITEPARAMETERFSGIXPROC glSpriteParameterfSGIX;
	extern PFNGLSPRITEPARAMETERFVSGIXPROC glSpriteParameterfvSGIX;
	extern PFNGLSPRITEPARAMETERISGIXPROC glSpriteParameteriSGIX;
	extern PFNGLSPRITEPARAMETERIVSGIXPROC glSpriteParameterivSGIX;

	extern bool have_SGIX_sprite(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_sprite_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_sprite_NAMESPACE

//  ...for GL_SGIX_subsample:
namespace GL_SGIX_subsample_NAMESPACE {

	extern bool have_SGIX_subsample(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_subsample_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_subsample_NAMESPACE

//  ...for GL_SGIX_tag_sample_buffer:
namespace GL_SGIX_tag_sample_buffer_NAMESPACE {
	extern PFNGLTAGSAMPLEBUFFERSGIXPROC glTagSampleBufferSGIX;

	extern bool have_SGIX_tag_sample_buffer(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_tag_sample_buffer_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_tag_sample_buffer_NAMESPACE

//  ...for GL_SGIX_texture_add_env:
namespace GL_SGIX_texture_add_env_NAMESPACE {

	extern bool have_SGIX_texture_add_env(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_texture_add_env_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_texture_add_env_NAMESPACE

//  ...for GL_SGIX_texture_coordinate_clamp:
namespace GL_SGIX_texture_coordinate_clamp_NAMESPACE {

	extern bool have_SGIX_texture_coordinate_clamp(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_texture_coordinate_clamp_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_texture_coordinate_clamp_NAMESPACE

//  ...for GL_SGIX_texture_lod_bias:
namespace GL_SGIX_texture_lod_bias_NAMESPACE {

	extern bool have_SGIX_texture_lod_bias(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_texture_lod_bias_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_texture_lod_bias_NAMESPACE

//  ...for GL_SGIX_texture_multi_buffer:
namespace GL_SGIX_texture_multi_buffer_NAMESPACE {

	extern bool have_SGIX_texture_multi_buffer(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_texture_multi_buffer_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_texture_multi_buffer_NAMESPACE

//  ...for GL_SGIX_texture_scale_bias:
namespace GL_SGIX_texture_scale_bias_NAMESPACE {

	extern bool have_SGIX_texture_scale_bias(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_texture_scale_bias_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_texture_scale_bias_NAMESPACE

//  ...for GL_SGIX_texture_select:
namespace GL_SGIX_texture_select_NAMESPACE {

	extern bool have_SGIX_texture_select(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_texture_select_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_texture_select_NAMESPACE

//  ...for GL_SGIX_vertex_preclip:
namespace GL_SGIX_vertex_preclip_NAMESPACE {

	extern bool have_SGIX_vertex_preclip(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_vertex_preclip_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_vertex_preclip_NAMESPACE

//  ...for GL_SGIX_ycrcb:
namespace GL_SGIX_ycrcb_NAMESPACE {

	extern bool have_SGIX_ycrcb(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_ycrcb_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_ycrcb_NAMESPACE

//  ...for GL_SGIX_ycrcb_subsample:
namespace GL_SGIX_ycrcb_subsample_NAMESPACE {

	extern bool have_SGIX_ycrcb_subsample(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_ycrcb_subsample_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_ycrcb_subsample_NAMESPACE

//  ...for GL_SGIX_ycrcba:
namespace GL_SGIX_ycrcba_NAMESPACE {

	extern bool have_SGIX_ycrcba(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGIX_ycrcba_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGIX_ycrcba_NAMESPACE

//  ...for GL_SGI_color_matrix:
namespace GL_SGI_color_matrix_NAMESPACE {

	extern bool have_SGI_color_matrix(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGI_color_matrix_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGI_color_matrix_NAMESPACE

//  ...for GL_SGI_color_table:
namespace GL_SGI_color_table_NAMESPACE {
	extern PFNGLCOLORTABLEPARAMETERFVSGIPROC glColorTableParameterfvSGI;
	extern PFNGLCOLORTABLEPARAMETERIVSGIPROC glColorTableParameterivSGI;
	extern PFNGLCOLORTABLESGIPROC glColorTableSGI;
	extern PFNGLCOPYCOLORTABLESGIPROC glCopyColorTableSGI;
	extern PFNGLGETCOLORTABLEPARAMETERFVSGIPROC glGetColorTableParameterfvSGI;
	extern PFNGLGETCOLORTABLEPARAMETERIVSGIPROC glGetColorTableParameterivSGI;
	extern PFNGLGETCOLORTABLESGIPROC glGetColorTableSGI;

	extern bool have_SGI_color_table(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGI_color_table_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGI_color_table_NAMESPACE

//  ...for GL_SGI_depth_pass_instrument:
namespace GL_SGI_depth_pass_instrument_NAMESPACE {

	extern bool have_SGI_depth_pass_instrument(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGI_depth_pass_instrument_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGI_depth_pass_instrument_NAMESPACE

//  ...for GL_SGI_texture_color_table:
namespace GL_SGI_texture_color_table_NAMESPACE {

	extern bool have_SGI_texture_color_table(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SGI_texture_color_table_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SGI_texture_color_table_NAMESPACE

//  ...for GL_SUNX_constant_data:
namespace GL_SUNX_constant_data_NAMESPACE {
	extern PFNGLFINISHTEXTURESUNXPROC glFinishTextureSUNX;

	extern bool have_SUNX_constant_data(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SUNX_constant_data_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SUNX_constant_data_NAMESPACE

//  ...for GL_SUN_convolution_border_modes:
namespace GL_SUN_convolution_border_modes_NAMESPACE {

	extern bool have_SUN_convolution_border_modes(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SUN_convolution_border_modes_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SUN_convolution_border_modes_NAMESPACE

//  ...for GL_SUN_global_alpha:
namespace GL_SUN_global_alpha_NAMESPACE {
	extern PFNGLGLOBALALPHAFACTORBSUNPROC glGlobalAlphaFactorbSUN;
	extern PFNGLGLOBALALPHAFACTORDSUNPROC glGlobalAlphaFactordSUN;
	extern PFNGLGLOBALALPHAFACTORFSUNPROC glGlobalAlphaFactorfSUN;
	extern PFNGLGLOBALALPHAFACTORISUNPROC glGlobalAlphaFactoriSUN;
	extern PFNGLGLOBALALPHAFACTORSSUNPROC glGlobalAlphaFactorsSUN;
	extern PFNGLGLOBALALPHAFACTORUBSUNPROC glGlobalAlphaFactorubSUN;
	extern PFNGLGLOBALALPHAFACTORUISUNPROC glGlobalAlphaFactoruiSUN;
	extern PFNGLGLOBALALPHAFACTORUSSUNPROC glGlobalAlphaFactorusSUN;

	extern bool have_SUN_global_alpha(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SUN_global_alpha_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SUN_global_alpha_NAMESPACE

//  ...for GL_SUN_mesh_array:
namespace GL_SUN_mesh_array_NAMESPACE {
	extern PFNGLDRAWMESHARRAYSSUNPROC glDrawMeshArraysSUN;

	extern bool have_SUN_mesh_array(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SUN_mesh_array_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SUN_mesh_array_NAMESPACE

//  ...for GL_SUN_slice_accum:
namespace GL_SUN_slice_accum_NAMESPACE {

	extern bool have_SUN_slice_accum(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SUN_slice_accum_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SUN_slice_accum_NAMESPACE

//  ...for GL_SUN_triangle_list:
namespace GL_SUN_triangle_list_NAMESPACE {
	extern PFNGLREPLACEMENTCODEPOINTERSUNPROC glReplacementCodePointerSUN;
	extern PFNGLREPLACEMENTCODEUBSUNPROC glReplacementCodeubSUN;
	extern PFNGLREPLACEMENTCODEUBVSUNPROC glReplacementCodeubvSUN;
	extern PFNGLREPLACEMENTCODEUISUNPROC glReplacementCodeuiSUN;
	extern PFNGLREPLACEMENTCODEUIVSUNPROC glReplacementCodeuivSUN;
	extern PFNGLREPLACEMENTCODEUSSUNPROC glReplacementCodeusSUN;
	extern PFNGLREPLACEMENTCODEUSVSUNPROC glReplacementCodeusvSUN;

	extern bool have_SUN_triangle_list(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SUN_triangle_list_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SUN_triangle_list_NAMESPACE

//  ...for GL_SUN_vertex:
namespace GL_SUN_vertex_NAMESPACE {
	extern PFNGLCOLOR3FVERTEX3FSUNPROC glColor3fVertex3fSUN;
	extern PFNGLCOLOR3FVERTEX3FVSUNPROC glColor3fVertex3fvSUN;
	extern PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC glColor4fNormal3fVertex3fSUN;
	extern PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC glColor4fNormal3fVertex3fvSUN;
	extern PFNGLCOLOR4UBVERTEX2FSUNPROC glColor4ubVertex2fSUN;
	extern PFNGLCOLOR4UBVERTEX2FVSUNPROC glColor4ubVertex2fvSUN;
	extern PFNGLCOLOR4UBVERTEX3FSUNPROC glColor4ubVertex3fSUN;
	extern PFNGLCOLOR4UBVERTEX3FVSUNPROC glColor4ubVertex3fvSUN;
	extern PFNGLNORMAL3FVERTEX3FSUNPROC glNormal3fVertex3fSUN;
	extern PFNGLNORMAL3FVERTEX3FVSUNPROC glNormal3fVertex3fvSUN;
	extern PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC glReplacementCodeuiColor3fVertex3fSUN;
	extern PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC glReplacementCodeuiColor3fVertex3fvSUN;
	extern PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC glReplacementCodeuiColor4fNormal3fVertex3fSUN;
	extern PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiColor4fNormal3fVertex3fvSUN;
	extern PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC glReplacementCodeuiColor4ubVertex3fSUN;
	extern PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC glReplacementCodeuiColor4ubVertex3fvSUN;
	extern PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC glReplacementCodeuiNormal3fVertex3fSUN;
	extern PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiNormal3fVertex3fvSUN;
	extern PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN;
	extern PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN;
	extern PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN;
	extern PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN;
	extern PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC glReplacementCodeuiTexCoord2fVertex3fSUN;
	extern PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC glReplacementCodeuiTexCoord2fVertex3fvSUN;
	extern PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC glReplacementCodeuiVertex3fSUN;
	extern PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC glReplacementCodeuiVertex3fvSUN;
	extern PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC glTexCoord2fColor3fVertex3fSUN;
	extern PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC glTexCoord2fColor3fVertex3fvSUN;
	extern PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC glTexCoord2fColor4fNormal3fVertex3fSUN;
	extern PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC glTexCoord2fColor4fNormal3fVertex3fvSUN;
	extern PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC glTexCoord2fColor4ubVertex3fSUN;
	extern PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC glTexCoord2fColor4ubVertex3fvSUN;
	extern PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC glTexCoord2fNormal3fVertex3fSUN;
	extern PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC glTexCoord2fNormal3fVertex3fvSUN;
	extern PFNGLTEXCOORD2FVERTEX3FSUNPROC glTexCoord2fVertex3fSUN;
	extern PFNGLTEXCOORD2FVERTEX3FVSUNPROC glTexCoord2fVertex3fvSUN;
	extern PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC glTexCoord4fColor4fNormal3fVertex4fSUN;
	extern PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC glTexCoord4fColor4fNormal3fVertex4fvSUN;
	extern PFNGLTEXCOORD4FVERTEX4FSUNPROC glTexCoord4fVertex4fSUN;
	extern PFNGLTEXCOORD4FVERTEX4FVSUNPROC glTexCoord4fVertex4fvSUN;

	extern bool have_SUN_vertex(); //<- for your use.

	//internal book-keeping stuff:
	class GL_SUN_vertex_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_SUN_vertex_NAMESPACE

//  ...for GL_WIN_phong_shading:
namespace GL_WIN_phong_shading_NAMESPACE {

	extern bool have_WIN_phong_shading(); //<- for your use.

	//internal book-keeping stuff:
	class GL_WIN_phong_shading_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_WIN_phong_shading_NAMESPACE

//  ...for GL_WIN_specular_fog:
namespace GL_WIN_specular_fog_NAMESPACE {

	extern bool have_WIN_specular_fog(); //<- for your use.

	//internal book-keeping stuff:
	class GL_WIN_specular_fog_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //GL_WIN_specular_fog_NAMESPACE
#endif //GRAPHICS_GLEXTENSIONS_HPP
