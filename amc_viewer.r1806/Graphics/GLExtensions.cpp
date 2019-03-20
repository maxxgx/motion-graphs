//This is auto-generated code, just like GLExtensions.hpp. Watch out!
#include "GLExtensions.hpp"
#include <iostream>
#include <assert.h>

using std::cerr;
using std::endl;

//  ...for GL_APPLE_client_storage:
namespace GL_APPLE_client_storage_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_APPLE_client_storage fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_APPLE_client_storage fails." << endl;
			}
		}
	}
	bool have_APPLE_client_storage() {
		return loaded;
	}
	void GL_APPLE_client_storage_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_APPLE_client_storage_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_APPLE_client_storage_NAMESPACE

//  ...for GL_APPLE_element_array:
namespace GL_APPLE_element_array_NAMESPACE {
PFNGLDRAWELEMENTARRAYAPPLEPROC glDrawElementArrayAPPLE = NULL;
PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC glDrawRangeElementArrayAPPLE = NULL;
PFNGLELEMENTPOINTERAPPLEPROC glElementPointerAPPLE = NULL;
PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC glMultiDrawElementArrayAPPLE = NULL;
PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC glMultiDrawRangeElementArrayAPPLE = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glDrawElementArrayAPPLE = (PFNGLDRAWELEMENTARRAYAPPLEPROC)SDL_GL_GetProcAddress("glDrawElementArrayAPPLE"))
			 && (glDrawRangeElementArrayAPPLE = (PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC)SDL_GL_GetProcAddress("glDrawRangeElementArrayAPPLE"))
			 && (glElementPointerAPPLE = (PFNGLELEMENTPOINTERAPPLEPROC)SDL_GL_GetProcAddress("glElementPointerAPPLE"))
			 && (glMultiDrawElementArrayAPPLE = (PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC)SDL_GL_GetProcAddress("glMultiDrawElementArrayAPPLE"))
			 && (glMultiDrawRangeElementArrayAPPLE = (PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC)SDL_GL_GetProcAddress("glMultiDrawRangeElementArrayAPPLE"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_APPLE_element_array fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_APPLE_element_array fails." << endl;
			}
		}
	}
	bool have_APPLE_element_array() {
		return loaded;
	}
	void GL_APPLE_element_array_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_APPLE_element_array_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_APPLE_element_array_NAMESPACE

//  ...for GL_APPLE_fence:
namespace GL_APPLE_fence_NAMESPACE {
PFNGLDELETEFENCESAPPLEPROC glDeleteFencesAPPLE = NULL;
PFNGLFINISHFENCEAPPLEPROC glFinishFenceAPPLE = NULL;
PFNGLFINISHOBJECTAPPLEPROC glFinishObjectAPPLE = NULL;
PFNGLGENFENCESAPPLEPROC glGenFencesAPPLE = NULL;
PFNGLISFENCEAPPLEPROC glIsFenceAPPLE = NULL;
PFNGLSETFENCEAPPLEPROC glSetFenceAPPLE = NULL;
PFNGLTESTFENCEAPPLEPROC glTestFenceAPPLE = NULL;
PFNGLTESTOBJECTAPPLEPROC glTestObjectAPPLE = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glDeleteFencesAPPLE = (PFNGLDELETEFENCESAPPLEPROC)SDL_GL_GetProcAddress("glDeleteFencesAPPLE"))
			 && (glFinishFenceAPPLE = (PFNGLFINISHFENCEAPPLEPROC)SDL_GL_GetProcAddress("glFinishFenceAPPLE"))
			 && (glFinishObjectAPPLE = (PFNGLFINISHOBJECTAPPLEPROC)SDL_GL_GetProcAddress("glFinishObjectAPPLE"))
			 && (glGenFencesAPPLE = (PFNGLGENFENCESAPPLEPROC)SDL_GL_GetProcAddress("glGenFencesAPPLE"))
			 && (glIsFenceAPPLE = (PFNGLISFENCEAPPLEPROC)SDL_GL_GetProcAddress("glIsFenceAPPLE"))
			 && (glSetFenceAPPLE = (PFNGLSETFENCEAPPLEPROC)SDL_GL_GetProcAddress("glSetFenceAPPLE"))
			 && (glTestFenceAPPLE = (PFNGLTESTFENCEAPPLEPROC)SDL_GL_GetProcAddress("glTestFenceAPPLE"))
			 && (glTestObjectAPPLE = (PFNGLTESTOBJECTAPPLEPROC)SDL_GL_GetProcAddress("glTestObjectAPPLE"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_APPLE_fence fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_APPLE_fence fails." << endl;
			}
		}
	}
	bool have_APPLE_fence() {
		return loaded;
	}
	void GL_APPLE_fence_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_APPLE_fence_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_APPLE_fence_NAMESPACE

//  ...for GL_APPLE_specular_vector:
namespace GL_APPLE_specular_vector_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_APPLE_specular_vector fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_APPLE_specular_vector fails." << endl;
			}
		}
	}
	bool have_APPLE_specular_vector() {
		return loaded;
	}
	void GL_APPLE_specular_vector_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_APPLE_specular_vector_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_APPLE_specular_vector_NAMESPACE

//  ...for GL_APPLE_transform_hint:
namespace GL_APPLE_transform_hint_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_APPLE_transform_hint fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_APPLE_transform_hint fails." << endl;
			}
		}
	}
	bool have_APPLE_transform_hint() {
		return loaded;
	}
	void GL_APPLE_transform_hint_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_APPLE_transform_hint_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_APPLE_transform_hint_NAMESPACE

//  ...for GL_APPLE_vertex_array_object:
namespace GL_APPLE_vertex_array_object_NAMESPACE {
PFNGLBINDVERTEXARRAYAPPLEPROC glBindVertexArrayAPPLE = NULL;
PFNGLDELETEVERTEXARRAYSAPPLEPROC glDeleteVertexArraysAPPLE = NULL;
PFNGLGENVERTEXARRAYSAPPLEPROC glGenVertexArraysAPPLE = NULL;
PFNGLISVERTEXARRAYAPPLEPROC glIsVertexArrayAPPLE = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glBindVertexArrayAPPLE = (PFNGLBINDVERTEXARRAYAPPLEPROC)SDL_GL_GetProcAddress("glBindVertexArrayAPPLE"))
			 && (glDeleteVertexArraysAPPLE = (PFNGLDELETEVERTEXARRAYSAPPLEPROC)SDL_GL_GetProcAddress("glDeleteVertexArraysAPPLE"))
			 && (glGenVertexArraysAPPLE = (PFNGLGENVERTEXARRAYSAPPLEPROC)SDL_GL_GetProcAddress("glGenVertexArraysAPPLE"))
			 && (glIsVertexArrayAPPLE = (PFNGLISVERTEXARRAYAPPLEPROC)SDL_GL_GetProcAddress("glIsVertexArrayAPPLE"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_APPLE_vertex_array_object fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_APPLE_vertex_array_object fails." << endl;
			}
		}
	}
	bool have_APPLE_vertex_array_object() {
		return loaded;
	}
	void GL_APPLE_vertex_array_object_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_APPLE_vertex_array_object_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_APPLE_vertex_array_object_NAMESPACE

//  ...for GL_APPLE_vertex_array_range:
namespace GL_APPLE_vertex_array_range_NAMESPACE {
PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC glFlushVertexArrayRangeAPPLE = NULL;
PFNGLVERTEXARRAYPARAMETERIAPPLEPROC glVertexArrayParameteriAPPLE = NULL;
PFNGLVERTEXARRAYRANGEAPPLEPROC glVertexArrayRangeAPPLE = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glFlushVertexArrayRangeAPPLE = (PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC)SDL_GL_GetProcAddress("glFlushVertexArrayRangeAPPLE"))
			 && (glVertexArrayParameteriAPPLE = (PFNGLVERTEXARRAYPARAMETERIAPPLEPROC)SDL_GL_GetProcAddress("glVertexArrayParameteriAPPLE"))
			 && (glVertexArrayRangeAPPLE = (PFNGLVERTEXARRAYRANGEAPPLEPROC)SDL_GL_GetProcAddress("glVertexArrayRangeAPPLE"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_APPLE_vertex_array_range fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_APPLE_vertex_array_range fails." << endl;
			}
		}
	}
	bool have_APPLE_vertex_array_range() {
		return loaded;
	}
	void GL_APPLE_vertex_array_range_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_APPLE_vertex_array_range_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_APPLE_vertex_array_range_NAMESPACE

//  ...for GL_APPLE_ycbcr_422:
namespace GL_APPLE_ycbcr_422_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_APPLE_ycbcr_422 fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_APPLE_ycbcr_422 fails." << endl;
			}
		}
	}
	bool have_APPLE_ycbcr_422() {
		return loaded;
	}
	void GL_APPLE_ycbcr_422_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_APPLE_ycbcr_422_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_APPLE_ycbcr_422_NAMESPACE

//  ...for GL_ARB_color_buffer_float:
namespace GL_ARB_color_buffer_float_NAMESPACE {
PFNGLCLAMPCOLORARBPROC glClampColorARB = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glClampColorARB = (PFNGLCLAMPCOLORARBPROC)SDL_GL_GetProcAddress("glClampColorARB"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_color_buffer_float fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_color_buffer_float fails." << endl;
			}
		}
	}
	bool have_ARB_color_buffer_float() {
		return loaded;
	}
	void GL_ARB_color_buffer_float_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_color_buffer_float_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_color_buffer_float_NAMESPACE

//  ...for GL_ARB_depth_texture:
namespace GL_ARB_depth_texture_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_depth_texture fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_depth_texture fails." << endl;
			}
		}
	}
	bool have_ARB_depth_texture() {
		return loaded;
	}
	void GL_ARB_depth_texture_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_depth_texture_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_depth_texture_NAMESPACE

//  ...for GL_ARB_draw_buffers:
namespace GL_ARB_draw_buffers_NAMESPACE {
PFNGLDRAWBUFFERSARBPROC glDrawBuffersARB = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glDrawBuffersARB = (PFNGLDRAWBUFFERSARBPROC)SDL_GL_GetProcAddress("glDrawBuffersARB"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_draw_buffers fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_draw_buffers fails." << endl;
			}
		}
	}
	bool have_ARB_draw_buffers() {
		return loaded;
	}
	void GL_ARB_draw_buffers_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_draw_buffers_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_draw_buffers_NAMESPACE

//  ...for GL_ARB_fragment_program:
namespace GL_ARB_fragment_program_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_fragment_program fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_fragment_program fails." << endl;
			}
		}
	}
	bool have_ARB_fragment_program() {
		return loaded;
	}
	void GL_ARB_fragment_program_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_fragment_program_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_fragment_program_NAMESPACE

//  ...for GL_ARB_fragment_program_shadow:
namespace GL_ARB_fragment_program_shadow_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_fragment_program_shadow fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_fragment_program_shadow fails." << endl;
			}
		}
	}
	bool have_ARB_fragment_program_shadow() {
		return loaded;
	}
	void GL_ARB_fragment_program_shadow_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_fragment_program_shadow_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_fragment_program_shadow_NAMESPACE

//  ...for GL_ARB_fragment_shader:
namespace GL_ARB_fragment_shader_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_fragment_shader fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_fragment_shader fails." << endl;
			}
		}
	}
	bool have_ARB_fragment_shader() {
		return loaded;
	}
	void GL_ARB_fragment_shader_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_fragment_shader_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_fragment_shader_NAMESPACE

//  ...for GL_ARB_half_float_pixel:
namespace GL_ARB_half_float_pixel_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_half_float_pixel fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_half_float_pixel fails." << endl;
			}
		}
	}
	bool have_ARB_half_float_pixel() {
		return loaded;
	}
	void GL_ARB_half_float_pixel_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_half_float_pixel_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_half_float_pixel_NAMESPACE

//  ...for GL_ARB_imaging:
namespace GL_ARB_imaging_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_imaging fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_imaging fails." << endl;
			}
		}
	}
	bool have_ARB_imaging() {
		return loaded;
	}
	void GL_ARB_imaging_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_imaging_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_imaging_NAMESPACE

//  ...for GL_ARB_matrix_palette:
namespace GL_ARB_matrix_palette_NAMESPACE {
PFNGLCURRENTPALETTEMATRIXARBPROC glCurrentPaletteMatrixARB = NULL;
PFNGLMATRIXINDEXPOINTERARBPROC glMatrixIndexPointerARB = NULL;
PFNGLMATRIXINDEXUBVARBPROC glMatrixIndexubvARB = NULL;
PFNGLMATRIXINDEXUIVARBPROC glMatrixIndexuivARB = NULL;
PFNGLMATRIXINDEXUSVARBPROC glMatrixIndexusvARB = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glCurrentPaletteMatrixARB = (PFNGLCURRENTPALETTEMATRIXARBPROC)SDL_GL_GetProcAddress("glCurrentPaletteMatrixARB"))
			 && (glMatrixIndexPointerARB = (PFNGLMATRIXINDEXPOINTERARBPROC)SDL_GL_GetProcAddress("glMatrixIndexPointerARB"))
			 && (glMatrixIndexubvARB = (PFNGLMATRIXINDEXUBVARBPROC)SDL_GL_GetProcAddress("glMatrixIndexubvARB"))
			 && (glMatrixIndexuivARB = (PFNGLMATRIXINDEXUIVARBPROC)SDL_GL_GetProcAddress("glMatrixIndexuivARB"))
			 && (glMatrixIndexusvARB = (PFNGLMATRIXINDEXUSVARBPROC)SDL_GL_GetProcAddress("glMatrixIndexusvARB"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_matrix_palette fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_matrix_palette fails." << endl;
			}
		}
	}
	bool have_ARB_matrix_palette() {
		return loaded;
	}
	void GL_ARB_matrix_palette_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_matrix_palette_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_matrix_palette_NAMESPACE

//  ...for GL_ARB_multisample:
namespace GL_ARB_multisample_NAMESPACE {
PFNGLSAMPLECOVERAGEARBPROC glSampleCoverageARB = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glSampleCoverageARB = (PFNGLSAMPLECOVERAGEARBPROC)SDL_GL_GetProcAddress("glSampleCoverageARB"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_multisample fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_multisample fails." << endl;
			}
		}
	}
	bool have_ARB_multisample() {
		return loaded;
	}
	void GL_ARB_multisample_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_multisample_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_multisample_NAMESPACE

//  ...for GL_ARB_multitexture:
namespace GL_ARB_multitexture_NAMESPACE {
PFNGLACTIVETEXTUREARBPROC glActiveTextureARB = NULL;
PFNGLCLIENTACTIVETEXTUREARBPROC glClientActiveTextureARB = NULL;
PFNGLMULTITEXCOORD1DARBPROC glMultiTexCoord1dARB = NULL;
PFNGLMULTITEXCOORD1DVARBPROC glMultiTexCoord1dvARB = NULL;
PFNGLMULTITEXCOORD1FARBPROC glMultiTexCoord1fARB = NULL;
PFNGLMULTITEXCOORD1FVARBPROC glMultiTexCoord1fvARB = NULL;
PFNGLMULTITEXCOORD1IARBPROC glMultiTexCoord1iARB = NULL;
PFNGLMULTITEXCOORD1IVARBPROC glMultiTexCoord1ivARB = NULL;
PFNGLMULTITEXCOORD1SARBPROC glMultiTexCoord1sARB = NULL;
PFNGLMULTITEXCOORD1SVARBPROC glMultiTexCoord1svARB = NULL;
PFNGLMULTITEXCOORD2DARBPROC glMultiTexCoord2dARB = NULL;
PFNGLMULTITEXCOORD2DVARBPROC glMultiTexCoord2dvARB = NULL;
PFNGLMULTITEXCOORD2FARBPROC glMultiTexCoord2fARB = NULL;
PFNGLMULTITEXCOORD2FVARBPROC glMultiTexCoord2fvARB = NULL;
PFNGLMULTITEXCOORD2IARBPROC glMultiTexCoord2iARB = NULL;
PFNGLMULTITEXCOORD2IVARBPROC glMultiTexCoord2ivARB = NULL;
PFNGLMULTITEXCOORD2SARBPROC glMultiTexCoord2sARB = NULL;
PFNGLMULTITEXCOORD2SVARBPROC glMultiTexCoord2svARB = NULL;
PFNGLMULTITEXCOORD3DARBPROC glMultiTexCoord3dARB = NULL;
PFNGLMULTITEXCOORD3DVARBPROC glMultiTexCoord3dvARB = NULL;
PFNGLMULTITEXCOORD3FARBPROC glMultiTexCoord3fARB = NULL;
PFNGLMULTITEXCOORD3FVARBPROC glMultiTexCoord3fvARB = NULL;
PFNGLMULTITEXCOORD3IARBPROC glMultiTexCoord3iARB = NULL;
PFNGLMULTITEXCOORD3IVARBPROC glMultiTexCoord3ivARB = NULL;
PFNGLMULTITEXCOORD3SARBPROC glMultiTexCoord3sARB = NULL;
PFNGLMULTITEXCOORD3SVARBPROC glMultiTexCoord3svARB = NULL;
PFNGLMULTITEXCOORD4DARBPROC glMultiTexCoord4dARB = NULL;
PFNGLMULTITEXCOORD4DVARBPROC glMultiTexCoord4dvARB = NULL;
PFNGLMULTITEXCOORD4FARBPROC glMultiTexCoord4fARB = NULL;
PFNGLMULTITEXCOORD4FVARBPROC glMultiTexCoord4fvARB = NULL;
PFNGLMULTITEXCOORD4IARBPROC glMultiTexCoord4iARB = NULL;
PFNGLMULTITEXCOORD4IVARBPROC glMultiTexCoord4ivARB = NULL;
PFNGLMULTITEXCOORD4SARBPROC glMultiTexCoord4sARB = NULL;
PFNGLMULTITEXCOORD4SVARBPROC glMultiTexCoord4svARB = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glActiveTextureARB = (PFNGLACTIVETEXTUREARBPROC)SDL_GL_GetProcAddress("glActiveTextureARB"))
			 && (glClientActiveTextureARB = (PFNGLCLIENTACTIVETEXTUREARBPROC)SDL_GL_GetProcAddress("glClientActiveTextureARB"))
			 && (glMultiTexCoord1dARB = (PFNGLMULTITEXCOORD1DARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord1dARB"))
			 && (glMultiTexCoord1dvARB = (PFNGLMULTITEXCOORD1DVARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord1dvARB"))
			 && (glMultiTexCoord1fARB = (PFNGLMULTITEXCOORD1FARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord1fARB"))
			 && (glMultiTexCoord1fvARB = (PFNGLMULTITEXCOORD1FVARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord1fvARB"))
			 && (glMultiTexCoord1iARB = (PFNGLMULTITEXCOORD1IARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord1iARB"))
			 && (glMultiTexCoord1ivARB = (PFNGLMULTITEXCOORD1IVARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord1ivARB"))
			 && (glMultiTexCoord1sARB = (PFNGLMULTITEXCOORD1SARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord1sARB"))
			 && (glMultiTexCoord1svARB = (PFNGLMULTITEXCOORD1SVARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord1svARB"))
			 && (glMultiTexCoord2dARB = (PFNGLMULTITEXCOORD2DARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord2dARB"))
			 && (glMultiTexCoord2dvARB = (PFNGLMULTITEXCOORD2DVARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord2dvARB"))
			 && (glMultiTexCoord2fARB = (PFNGLMULTITEXCOORD2FARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord2fARB"))
			 && (glMultiTexCoord2fvARB = (PFNGLMULTITEXCOORD2FVARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord2fvARB"))
			 && (glMultiTexCoord2iARB = (PFNGLMULTITEXCOORD2IARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord2iARB"))
			 && (glMultiTexCoord2ivARB = (PFNGLMULTITEXCOORD2IVARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord2ivARB"))
			 && (glMultiTexCoord2sARB = (PFNGLMULTITEXCOORD2SARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord2sARB"))
			 && (glMultiTexCoord2svARB = (PFNGLMULTITEXCOORD2SVARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord2svARB"))
			 && (glMultiTexCoord3dARB = (PFNGLMULTITEXCOORD3DARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord3dARB"))
			 && (glMultiTexCoord3dvARB = (PFNGLMULTITEXCOORD3DVARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord3dvARB"))
			 && (glMultiTexCoord3fARB = (PFNGLMULTITEXCOORD3FARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord3fARB"))
			 && (glMultiTexCoord3fvARB = (PFNGLMULTITEXCOORD3FVARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord3fvARB"))
			 && (glMultiTexCoord3iARB = (PFNGLMULTITEXCOORD3IARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord3iARB"))
			 && (glMultiTexCoord3ivARB = (PFNGLMULTITEXCOORD3IVARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord3ivARB"))
			 && (glMultiTexCoord3sARB = (PFNGLMULTITEXCOORD3SARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord3sARB"))
			 && (glMultiTexCoord3svARB = (PFNGLMULTITEXCOORD3SVARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord3svARB"))
			 && (glMultiTexCoord4dARB = (PFNGLMULTITEXCOORD4DARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord4dARB"))
			 && (glMultiTexCoord4dvARB = (PFNGLMULTITEXCOORD4DVARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord4dvARB"))
			 && (glMultiTexCoord4fARB = (PFNGLMULTITEXCOORD4FARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord4fARB"))
			 && (glMultiTexCoord4fvARB = (PFNGLMULTITEXCOORD4FVARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord4fvARB"))
			 && (glMultiTexCoord4iARB = (PFNGLMULTITEXCOORD4IARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord4iARB"))
			 && (glMultiTexCoord4ivARB = (PFNGLMULTITEXCOORD4IVARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord4ivARB"))
			 && (glMultiTexCoord4sARB = (PFNGLMULTITEXCOORD4SARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord4sARB"))
			 && (glMultiTexCoord4svARB = (PFNGLMULTITEXCOORD4SVARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord4svARB"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_multitexture fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_multitexture fails." << endl;
			}
		}
	}
	bool have_ARB_multitexture() {
		return loaded;
	}
	void GL_ARB_multitexture_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_multitexture_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_multitexture_NAMESPACE

//  ...for GL_ARB_occlusion_query:
namespace GL_ARB_occlusion_query_NAMESPACE {
PFNGLBEGINQUERYARBPROC glBeginQueryARB = NULL;
PFNGLDELETEQUERIESARBPROC glDeleteQueriesARB = NULL;
PFNGLENDQUERYARBPROC glEndQueryARB = NULL;
PFNGLGENQUERIESARBPROC glGenQueriesARB = NULL;
PFNGLGETQUERYIVARBPROC glGetQueryivARB = NULL;
PFNGLGETQUERYOBJECTIVARBPROC glGetQueryObjectivARB = NULL;
PFNGLGETQUERYOBJECTUIVARBPROC glGetQueryObjectuivARB = NULL;
PFNGLISQUERYARBPROC glIsQueryARB = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glBeginQueryARB = (PFNGLBEGINQUERYARBPROC)SDL_GL_GetProcAddress("glBeginQueryARB"))
			 && (glDeleteQueriesARB = (PFNGLDELETEQUERIESARBPROC)SDL_GL_GetProcAddress("glDeleteQueriesARB"))
			 && (glEndQueryARB = (PFNGLENDQUERYARBPROC)SDL_GL_GetProcAddress("glEndQueryARB"))
			 && (glGenQueriesARB = (PFNGLGENQUERIESARBPROC)SDL_GL_GetProcAddress("glGenQueriesARB"))
			 && (glGetQueryivARB = (PFNGLGETQUERYIVARBPROC)SDL_GL_GetProcAddress("glGetQueryivARB"))
			 && (glGetQueryObjectivARB = (PFNGLGETQUERYOBJECTIVARBPROC)SDL_GL_GetProcAddress("glGetQueryObjectivARB"))
			 && (glGetQueryObjectuivARB = (PFNGLGETQUERYOBJECTUIVARBPROC)SDL_GL_GetProcAddress("glGetQueryObjectuivARB"))
			 && (glIsQueryARB = (PFNGLISQUERYARBPROC)SDL_GL_GetProcAddress("glIsQueryARB"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_occlusion_query fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_occlusion_query fails." << endl;
			}
		}
	}
	bool have_ARB_occlusion_query() {
		return loaded;
	}
	void GL_ARB_occlusion_query_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_occlusion_query_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_occlusion_query_NAMESPACE

//  ...for GL_ARB_pixel_buffer_object:
namespace GL_ARB_pixel_buffer_object_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_pixel_buffer_object fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_pixel_buffer_object fails." << endl;
			}
		}
	}
	bool have_ARB_pixel_buffer_object() {
		return loaded;
	}
	void GL_ARB_pixel_buffer_object_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_pixel_buffer_object_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_pixel_buffer_object_NAMESPACE

//  ...for GL_ARB_point_parameters:
namespace GL_ARB_point_parameters_NAMESPACE {
PFNGLPOINTPARAMETERFARBPROC glPointParameterfARB = NULL;
PFNGLPOINTPARAMETERFVARBPROC glPointParameterfvARB = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glPointParameterfARB = (PFNGLPOINTPARAMETERFARBPROC)SDL_GL_GetProcAddress("glPointParameterfARB"))
			 && (glPointParameterfvARB = (PFNGLPOINTPARAMETERFVARBPROC)SDL_GL_GetProcAddress("glPointParameterfvARB"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_point_parameters fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_point_parameters fails." << endl;
			}
		}
	}
	bool have_ARB_point_parameters() {
		return loaded;
	}
	void GL_ARB_point_parameters_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_point_parameters_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_point_parameters_NAMESPACE

//  ...for GL_ARB_point_sprite:
namespace GL_ARB_point_sprite_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_point_sprite fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_point_sprite fails." << endl;
			}
		}
	}
	bool have_ARB_point_sprite() {
		return loaded;
	}
	void GL_ARB_point_sprite_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_point_sprite_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_point_sprite_NAMESPACE

//  ...for GL_ARB_shader_objects:
namespace GL_ARB_shader_objects_NAMESPACE {
PFNGLATTACHOBJECTARBPROC glAttachObjectARB = NULL;
PFNGLCOMPILESHADERARBPROC glCompileShaderARB = NULL;
PFNGLCREATEPROGRAMOBJECTARBPROC glCreateProgramObjectARB = NULL;
PFNGLCREATESHADEROBJECTARBPROC glCreateShaderObjectARB = NULL;
PFNGLDELETEOBJECTARBPROC glDeleteObjectARB = NULL;
PFNGLDETACHOBJECTARBPROC glDetachObjectARB = NULL;
PFNGLGETACTIVEUNIFORMARBPROC glGetActiveUniformARB = NULL;
PFNGLGETATTACHEDOBJECTSARBPROC glGetAttachedObjectsARB = NULL;
PFNGLGETHANDLEARBPROC glGetHandleARB = NULL;
PFNGLGETINFOLOGARBPROC glGetInfoLogARB = NULL;
PFNGLGETOBJECTPARAMETERFVARBPROC glGetObjectParameterfvARB = NULL;
PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameterivARB = NULL;
PFNGLGETSHADERSOURCEARBPROC glGetShaderSourceARB = NULL;
PFNGLGETUNIFORMFVARBPROC glGetUniformfvARB = NULL;
PFNGLGETUNIFORMIVARBPROC glGetUniformivARB = NULL;
PFNGLGETUNIFORMLOCATIONARBPROC glGetUniformLocationARB = NULL;
PFNGLLINKPROGRAMARBPROC glLinkProgramARB = NULL;
PFNGLSHADERSOURCEARBPROC glShaderSourceARB = NULL;
PFNGLUNIFORM1FARBPROC glUniform1fARB = NULL;
PFNGLUNIFORM1FVARBPROC glUniform1fvARB = NULL;
PFNGLUNIFORM1IARBPROC glUniform1iARB = NULL;
PFNGLUNIFORM1IVARBPROC glUniform1ivARB = NULL;
PFNGLUNIFORM2FARBPROC glUniform2fARB = NULL;
PFNGLUNIFORM2FVARBPROC glUniform2fvARB = NULL;
PFNGLUNIFORM2IARBPROC glUniform2iARB = NULL;
PFNGLUNIFORM2IVARBPROC glUniform2ivARB = NULL;
PFNGLUNIFORM3FARBPROC glUniform3fARB = NULL;
PFNGLUNIFORM3FVARBPROC glUniform3fvARB = NULL;
PFNGLUNIFORM3IARBPROC glUniform3iARB = NULL;
PFNGLUNIFORM3IVARBPROC glUniform3ivARB = NULL;
PFNGLUNIFORM4FARBPROC glUniform4fARB = NULL;
PFNGLUNIFORM4FVARBPROC glUniform4fvARB = NULL;
PFNGLUNIFORM4IARBPROC glUniform4iARB = NULL;
PFNGLUNIFORM4IVARBPROC glUniform4ivARB = NULL;
PFNGLUNIFORMMATRIX2FVARBPROC glUniformMatrix2fvARB = NULL;
PFNGLUNIFORMMATRIX3FVARBPROC glUniformMatrix3fvARB = NULL;
PFNGLUNIFORMMATRIX4FVARBPROC glUniformMatrix4fvARB = NULL;
PFNGLUSEPROGRAMOBJECTARBPROC glUseProgramObjectARB = NULL;
PFNGLVALIDATEPROGRAMARBPROC glValidateProgramARB = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glAttachObjectARB = (PFNGLATTACHOBJECTARBPROC)SDL_GL_GetProcAddress("glAttachObjectARB"))
			 && (glCompileShaderARB = (PFNGLCOMPILESHADERARBPROC)SDL_GL_GetProcAddress("glCompileShaderARB"))
			 && (glCreateProgramObjectARB = (PFNGLCREATEPROGRAMOBJECTARBPROC)SDL_GL_GetProcAddress("glCreateProgramObjectARB"))
			 && (glCreateShaderObjectARB = (PFNGLCREATESHADEROBJECTARBPROC)SDL_GL_GetProcAddress("glCreateShaderObjectARB"))
			 && (glDeleteObjectARB = (PFNGLDELETEOBJECTARBPROC)SDL_GL_GetProcAddress("glDeleteObjectARB"))
			 && (glDetachObjectARB = (PFNGLDETACHOBJECTARBPROC)SDL_GL_GetProcAddress("glDetachObjectARB"))
			 && (glGetActiveUniformARB = (PFNGLGETACTIVEUNIFORMARBPROC)SDL_GL_GetProcAddress("glGetActiveUniformARB"))
			 && (glGetAttachedObjectsARB = (PFNGLGETATTACHEDOBJECTSARBPROC)SDL_GL_GetProcAddress("glGetAttachedObjectsARB"))
			 && (glGetHandleARB = (PFNGLGETHANDLEARBPROC)SDL_GL_GetProcAddress("glGetHandleARB"))
			 && (glGetInfoLogARB = (PFNGLGETINFOLOGARBPROC)SDL_GL_GetProcAddress("glGetInfoLogARB"))
			 && (glGetObjectParameterfvARB = (PFNGLGETOBJECTPARAMETERFVARBPROC)SDL_GL_GetProcAddress("glGetObjectParameterfvARB"))
			 && (glGetObjectParameterivARB = (PFNGLGETOBJECTPARAMETERIVARBPROC)SDL_GL_GetProcAddress("glGetObjectParameterivARB"))
			 && (glGetShaderSourceARB = (PFNGLGETSHADERSOURCEARBPROC)SDL_GL_GetProcAddress("glGetShaderSourceARB"))
			 && (glGetUniformfvARB = (PFNGLGETUNIFORMFVARBPROC)SDL_GL_GetProcAddress("glGetUniformfvARB"))
			 && (glGetUniformivARB = (PFNGLGETUNIFORMIVARBPROC)SDL_GL_GetProcAddress("glGetUniformivARB"))
			 && (glGetUniformLocationARB = (PFNGLGETUNIFORMLOCATIONARBPROC)SDL_GL_GetProcAddress("glGetUniformLocationARB"))
			 && (glLinkProgramARB = (PFNGLLINKPROGRAMARBPROC)SDL_GL_GetProcAddress("glLinkProgramARB"))
			 && (glShaderSourceARB = (PFNGLSHADERSOURCEARBPROC)SDL_GL_GetProcAddress("glShaderSourceARB"))
			 && (glUniform1fARB = (PFNGLUNIFORM1FARBPROC)SDL_GL_GetProcAddress("glUniform1fARB"))
			 && (glUniform1fvARB = (PFNGLUNIFORM1FVARBPROC)SDL_GL_GetProcAddress("glUniform1fvARB"))
			 && (glUniform1iARB = (PFNGLUNIFORM1IARBPROC)SDL_GL_GetProcAddress("glUniform1iARB"))
			 && (glUniform1ivARB = (PFNGLUNIFORM1IVARBPROC)SDL_GL_GetProcAddress("glUniform1ivARB"))
			 && (glUniform2fARB = (PFNGLUNIFORM2FARBPROC)SDL_GL_GetProcAddress("glUniform2fARB"))
			 && (glUniform2fvARB = (PFNGLUNIFORM2FVARBPROC)SDL_GL_GetProcAddress("glUniform2fvARB"))
			 && (glUniform2iARB = (PFNGLUNIFORM2IARBPROC)SDL_GL_GetProcAddress("glUniform2iARB"))
			 && (glUniform2ivARB = (PFNGLUNIFORM2IVARBPROC)SDL_GL_GetProcAddress("glUniform2ivARB"))
			 && (glUniform3fARB = (PFNGLUNIFORM3FARBPROC)SDL_GL_GetProcAddress("glUniform3fARB"))
			 && (glUniform3fvARB = (PFNGLUNIFORM3FVARBPROC)SDL_GL_GetProcAddress("glUniform3fvARB"))
			 && (glUniform3iARB = (PFNGLUNIFORM3IARBPROC)SDL_GL_GetProcAddress("glUniform3iARB"))
			 && (glUniform3ivARB = (PFNGLUNIFORM3IVARBPROC)SDL_GL_GetProcAddress("glUniform3ivARB"))
			 && (glUniform4fARB = (PFNGLUNIFORM4FARBPROC)SDL_GL_GetProcAddress("glUniform4fARB"))
			 && (glUniform4fvARB = (PFNGLUNIFORM4FVARBPROC)SDL_GL_GetProcAddress("glUniform4fvARB"))
			 && (glUniform4iARB = (PFNGLUNIFORM4IARBPROC)SDL_GL_GetProcAddress("glUniform4iARB"))
			 && (glUniform4ivARB = (PFNGLUNIFORM4IVARBPROC)SDL_GL_GetProcAddress("glUniform4ivARB"))
			 && (glUniformMatrix2fvARB = (PFNGLUNIFORMMATRIX2FVARBPROC)SDL_GL_GetProcAddress("glUniformMatrix2fvARB"))
			 && (glUniformMatrix3fvARB = (PFNGLUNIFORMMATRIX3FVARBPROC)SDL_GL_GetProcAddress("glUniformMatrix3fvARB"))
			 && (glUniformMatrix4fvARB = (PFNGLUNIFORMMATRIX4FVARBPROC)SDL_GL_GetProcAddress("glUniformMatrix4fvARB"))
			 && (glUseProgramObjectARB = (PFNGLUSEPROGRAMOBJECTARBPROC)SDL_GL_GetProcAddress("glUseProgramObjectARB"))
			 && (glValidateProgramARB = (PFNGLVALIDATEPROGRAMARBPROC)SDL_GL_GetProcAddress("glValidateProgramARB"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_shader_objects fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_shader_objects fails." << endl;
			}
		}
	}
	bool have_ARB_shader_objects() {
		return loaded;
	}
	void GL_ARB_shader_objects_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_shader_objects_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_shader_objects_NAMESPACE

//  ...for GL_ARB_shading_language_100:
namespace GL_ARB_shading_language_100_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_shading_language_100 fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_shading_language_100 fails." << endl;
			}
		}
	}
	bool have_ARB_shading_language_100() {
		return loaded;
	}
	void GL_ARB_shading_language_100_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_shading_language_100_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_shading_language_100_NAMESPACE

//  ...for GL_ARB_shadow:
namespace GL_ARB_shadow_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_shadow fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_shadow fails." << endl;
			}
		}
	}
	bool have_ARB_shadow() {
		return loaded;
	}
	void GL_ARB_shadow_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_shadow_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_shadow_NAMESPACE

//  ...for GL_ARB_shadow_ambient:
namespace GL_ARB_shadow_ambient_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_shadow_ambient fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_shadow_ambient fails." << endl;
			}
		}
	}
	bool have_ARB_shadow_ambient() {
		return loaded;
	}
	void GL_ARB_shadow_ambient_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_shadow_ambient_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_shadow_ambient_NAMESPACE

//  ...for GL_ARB_texture_border_clamp:
namespace GL_ARB_texture_border_clamp_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_texture_border_clamp fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_texture_border_clamp fails." << endl;
			}
		}
	}
	bool have_ARB_texture_border_clamp() {
		return loaded;
	}
	void GL_ARB_texture_border_clamp_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_texture_border_clamp_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_texture_border_clamp_NAMESPACE

//  ...for GL_ARB_texture_compression:
namespace GL_ARB_texture_compression_NAMESPACE {
PFNGLCOMPRESSEDTEXIMAGE1DARBPROC glCompressedTexImage1DARB = NULL;
PFNGLCOMPRESSEDTEXIMAGE2DARBPROC glCompressedTexImage2DARB = NULL;
PFNGLCOMPRESSEDTEXIMAGE3DARBPROC glCompressedTexImage3DARB = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC glCompressedTexSubImage1DARB = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC glCompressedTexSubImage2DARB = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC glCompressedTexSubImage3DARB = NULL;
PFNGLGETCOMPRESSEDTEXIMAGEARBPROC glGetCompressedTexImageARB = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glCompressedTexImage1DARB = (PFNGLCOMPRESSEDTEXIMAGE1DARBPROC)SDL_GL_GetProcAddress("glCompressedTexImage1DARB"))
			 && (glCompressedTexImage2DARB = (PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)SDL_GL_GetProcAddress("glCompressedTexImage2DARB"))
			 && (glCompressedTexImage3DARB = (PFNGLCOMPRESSEDTEXIMAGE3DARBPROC)SDL_GL_GetProcAddress("glCompressedTexImage3DARB"))
			 && (glCompressedTexSubImage1DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC)SDL_GL_GetProcAddress("glCompressedTexSubImage1DARB"))
			 && (glCompressedTexSubImage2DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC)SDL_GL_GetProcAddress("glCompressedTexSubImage2DARB"))
			 && (glCompressedTexSubImage3DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC)SDL_GL_GetProcAddress("glCompressedTexSubImage3DARB"))
			 && (glGetCompressedTexImageARB = (PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)SDL_GL_GetProcAddress("glGetCompressedTexImageARB"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_texture_compression fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_texture_compression fails." << endl;
			}
		}
	}
	bool have_ARB_texture_compression() {
		return loaded;
	}
	void GL_ARB_texture_compression_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_texture_compression_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_texture_compression_NAMESPACE

//  ...for GL_ARB_texture_cube_map:
namespace GL_ARB_texture_cube_map_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_texture_cube_map fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_texture_cube_map fails." << endl;
			}
		}
	}
	bool have_ARB_texture_cube_map() {
		return loaded;
	}
	void GL_ARB_texture_cube_map_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_texture_cube_map_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_texture_cube_map_NAMESPACE

//  ...for GL_ARB_texture_env_add:
namespace GL_ARB_texture_env_add_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_texture_env_add fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_texture_env_add fails." << endl;
			}
		}
	}
	bool have_ARB_texture_env_add() {
		return loaded;
	}
	void GL_ARB_texture_env_add_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_texture_env_add_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_texture_env_add_NAMESPACE

//  ...for GL_ARB_texture_env_combine:
namespace GL_ARB_texture_env_combine_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_texture_env_combine fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_texture_env_combine fails." << endl;
			}
		}
	}
	bool have_ARB_texture_env_combine() {
		return loaded;
	}
	void GL_ARB_texture_env_combine_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_texture_env_combine_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_texture_env_combine_NAMESPACE

//  ...for GL_ARB_texture_env_crossbar:
namespace GL_ARB_texture_env_crossbar_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_texture_env_crossbar fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_texture_env_crossbar fails." << endl;
			}
		}
	}
	bool have_ARB_texture_env_crossbar() {
		return loaded;
	}
	void GL_ARB_texture_env_crossbar_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_texture_env_crossbar_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_texture_env_crossbar_NAMESPACE

//  ...for GL_ARB_texture_env_dot3:
namespace GL_ARB_texture_env_dot3_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_texture_env_dot3 fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_texture_env_dot3 fails." << endl;
			}
		}
	}
	bool have_ARB_texture_env_dot3() {
		return loaded;
	}
	void GL_ARB_texture_env_dot3_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_texture_env_dot3_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_texture_env_dot3_NAMESPACE

//  ...for GL_ARB_texture_float:
namespace GL_ARB_texture_float_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_texture_float fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_texture_float fails." << endl;
			}
		}
	}
	bool have_ARB_texture_float() {
		return loaded;
	}
	void GL_ARB_texture_float_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_texture_float_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_texture_float_NAMESPACE

//  ...for GL_ARB_texture_mirrored_repeat:
namespace GL_ARB_texture_mirrored_repeat_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_texture_mirrored_repeat fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_texture_mirrored_repeat fails." << endl;
			}
		}
	}
	bool have_ARB_texture_mirrored_repeat() {
		return loaded;
	}
	void GL_ARB_texture_mirrored_repeat_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_texture_mirrored_repeat_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_texture_mirrored_repeat_NAMESPACE

//  ...for GL_ARB_texture_non_power_of_two:
namespace GL_ARB_texture_non_power_of_two_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_texture_non_power_of_two fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_texture_non_power_of_two fails." << endl;
			}
		}
	}
	bool have_ARB_texture_non_power_of_two() {
		return loaded;
	}
	void GL_ARB_texture_non_power_of_two_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_texture_non_power_of_two_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_texture_non_power_of_two_NAMESPACE

//  ...for GL_ARB_texture_rectangle:
namespace GL_ARB_texture_rectangle_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_texture_rectangle fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_texture_rectangle fails." << endl;
			}
		}
	}
	bool have_ARB_texture_rectangle() {
		return loaded;
	}
	void GL_ARB_texture_rectangle_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_texture_rectangle_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_texture_rectangle_NAMESPACE

//  ...for GL_ARB_transpose_matrix:
namespace GL_ARB_transpose_matrix_NAMESPACE {
PFNGLLOADTRANSPOSEMATRIXDARBPROC glLoadTransposeMatrixdARB = NULL;
PFNGLLOADTRANSPOSEMATRIXFARBPROC glLoadTransposeMatrixfARB = NULL;
PFNGLMULTTRANSPOSEMATRIXDARBPROC glMultTransposeMatrixdARB = NULL;
PFNGLMULTTRANSPOSEMATRIXFARBPROC glMultTransposeMatrixfARB = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glLoadTransposeMatrixdARB = (PFNGLLOADTRANSPOSEMATRIXDARBPROC)SDL_GL_GetProcAddress("glLoadTransposeMatrixdARB"))
			 && (glLoadTransposeMatrixfARB = (PFNGLLOADTRANSPOSEMATRIXFARBPROC)SDL_GL_GetProcAddress("glLoadTransposeMatrixfARB"))
			 && (glMultTransposeMatrixdARB = (PFNGLMULTTRANSPOSEMATRIXDARBPROC)SDL_GL_GetProcAddress("glMultTransposeMatrixdARB"))
			 && (glMultTransposeMatrixfARB = (PFNGLMULTTRANSPOSEMATRIXFARBPROC)SDL_GL_GetProcAddress("glMultTransposeMatrixfARB"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_transpose_matrix fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_transpose_matrix fails." << endl;
			}
		}
	}
	bool have_ARB_transpose_matrix() {
		return loaded;
	}
	void GL_ARB_transpose_matrix_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_transpose_matrix_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_transpose_matrix_NAMESPACE

//  ...for GL_ARB_vertex_blend:
namespace GL_ARB_vertex_blend_NAMESPACE {
PFNGLVERTEXBLENDARBPROC glVertexBlendARB = NULL;
PFNGLWEIGHTBVARBPROC glWeightbvARB = NULL;
PFNGLWEIGHTDVARBPROC glWeightdvARB = NULL;
PFNGLWEIGHTFVARBPROC glWeightfvARB = NULL;
PFNGLWEIGHTIVARBPROC glWeightivARB = NULL;
PFNGLWEIGHTPOINTERARBPROC glWeightPointerARB = NULL;
PFNGLWEIGHTSVARBPROC glWeightsvARB = NULL;
PFNGLWEIGHTUBVARBPROC glWeightubvARB = NULL;
PFNGLWEIGHTUIVARBPROC glWeightuivARB = NULL;
PFNGLWEIGHTUSVARBPROC glWeightusvARB = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glVertexBlendARB = (PFNGLVERTEXBLENDARBPROC)SDL_GL_GetProcAddress("glVertexBlendARB"))
			 && (glWeightbvARB = (PFNGLWEIGHTBVARBPROC)SDL_GL_GetProcAddress("glWeightbvARB"))
			 && (glWeightdvARB = (PFNGLWEIGHTDVARBPROC)SDL_GL_GetProcAddress("glWeightdvARB"))
			 && (glWeightfvARB = (PFNGLWEIGHTFVARBPROC)SDL_GL_GetProcAddress("glWeightfvARB"))
			 && (glWeightivARB = (PFNGLWEIGHTIVARBPROC)SDL_GL_GetProcAddress("glWeightivARB"))
			 && (glWeightPointerARB = (PFNGLWEIGHTPOINTERARBPROC)SDL_GL_GetProcAddress("glWeightPointerARB"))
			 && (glWeightsvARB = (PFNGLWEIGHTSVARBPROC)SDL_GL_GetProcAddress("glWeightsvARB"))
			 && (glWeightubvARB = (PFNGLWEIGHTUBVARBPROC)SDL_GL_GetProcAddress("glWeightubvARB"))
			 && (glWeightuivARB = (PFNGLWEIGHTUIVARBPROC)SDL_GL_GetProcAddress("glWeightuivARB"))
			 && (glWeightusvARB = (PFNGLWEIGHTUSVARBPROC)SDL_GL_GetProcAddress("glWeightusvARB"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_vertex_blend fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_vertex_blend fails." << endl;
			}
		}
	}
	bool have_ARB_vertex_blend() {
		return loaded;
	}
	void GL_ARB_vertex_blend_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_vertex_blend_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_vertex_blend_NAMESPACE

//  ...for GL_ARB_vertex_buffer_object:
namespace GL_ARB_vertex_buffer_object_NAMESPACE {
PFNGLBINDBUFFERARBPROC glBindBufferARB = NULL;
PFNGLBUFFERDATAARBPROC glBufferDataARB = NULL;
PFNGLBUFFERSUBDATAARBPROC glBufferSubDataARB = NULL;
PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARB = NULL;
PFNGLGENBUFFERSARBPROC glGenBuffersARB = NULL;
PFNGLGETBUFFERPARAMETERIVARBPROC glGetBufferParameterivARB = NULL;
PFNGLGETBUFFERPOINTERVARBPROC glGetBufferPointervARB = NULL;
PFNGLGETBUFFERSUBDATAARBPROC glGetBufferSubDataARB = NULL;
PFNGLISBUFFERARBPROC glIsBufferARB = NULL;
PFNGLMAPBUFFERARBPROC glMapBufferARB = NULL;
PFNGLUNMAPBUFFERARBPROC glUnmapBufferARB = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glBindBufferARB = (PFNGLBINDBUFFERARBPROC)SDL_GL_GetProcAddress("glBindBufferARB"))
			 && (glBufferDataARB = (PFNGLBUFFERDATAARBPROC)SDL_GL_GetProcAddress("glBufferDataARB"))
			 && (glBufferSubDataARB = (PFNGLBUFFERSUBDATAARBPROC)SDL_GL_GetProcAddress("glBufferSubDataARB"))
			 && (glDeleteBuffersARB = (PFNGLDELETEBUFFERSARBPROC)SDL_GL_GetProcAddress("glDeleteBuffersARB"))
			 && (glGenBuffersARB = (PFNGLGENBUFFERSARBPROC)SDL_GL_GetProcAddress("glGenBuffersARB"))
			 && (glGetBufferParameterivARB = (PFNGLGETBUFFERPARAMETERIVARBPROC)SDL_GL_GetProcAddress("glGetBufferParameterivARB"))
			 && (glGetBufferPointervARB = (PFNGLGETBUFFERPOINTERVARBPROC)SDL_GL_GetProcAddress("glGetBufferPointervARB"))
			 && (glGetBufferSubDataARB = (PFNGLGETBUFFERSUBDATAARBPROC)SDL_GL_GetProcAddress("glGetBufferSubDataARB"))
			 && (glIsBufferARB = (PFNGLISBUFFERARBPROC)SDL_GL_GetProcAddress("glIsBufferARB"))
			 && (glMapBufferARB = (PFNGLMAPBUFFERARBPROC)SDL_GL_GetProcAddress("glMapBufferARB"))
			 && (glUnmapBufferARB = (PFNGLUNMAPBUFFERARBPROC)SDL_GL_GetProcAddress("glUnmapBufferARB"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_vertex_buffer_object fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_vertex_buffer_object fails." << endl;
			}
		}
	}
	bool have_ARB_vertex_buffer_object() {
		return loaded;
	}
	void GL_ARB_vertex_buffer_object_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_vertex_buffer_object_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_vertex_buffer_object_NAMESPACE

//  ...for GL_ARB_vertex_program:
namespace GL_ARB_vertex_program_NAMESPACE {
PFNGLBINDPROGRAMARBPROC glBindProgramARB = NULL;
PFNGLDELETEPROGRAMSARBPROC glDeleteProgramsARB = NULL;
PFNGLDISABLEVERTEXATTRIBARRAYARBPROC glDisableVertexAttribArrayARB = NULL;
PFNGLENABLEVERTEXATTRIBARRAYARBPROC glEnableVertexAttribArrayARB = NULL;
PFNGLGENPROGRAMSARBPROC glGenProgramsARB = NULL;
PFNGLGETPROGRAMENVPARAMETERDVARBPROC glGetProgramEnvParameterdvARB = NULL;
PFNGLGETPROGRAMENVPARAMETERFVARBPROC glGetProgramEnvParameterfvARB = NULL;
PFNGLGETPROGRAMIVARBPROC glGetProgramivARB = NULL;
PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC glGetProgramLocalParameterdvARB = NULL;
PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC glGetProgramLocalParameterfvARB = NULL;
PFNGLGETPROGRAMSTRINGARBPROC glGetProgramStringARB = NULL;
PFNGLGETVERTEXATTRIBDVARBPROC glGetVertexAttribdvARB = NULL;
PFNGLGETVERTEXATTRIBFVARBPROC glGetVertexAttribfvARB = NULL;
PFNGLGETVERTEXATTRIBIVARBPROC glGetVertexAttribivARB = NULL;
PFNGLGETVERTEXATTRIBPOINTERVARBPROC glGetVertexAttribPointervARB = NULL;
PFNGLISPROGRAMARBPROC glIsProgramARB = NULL;
PFNGLPROGRAMENVPARAMETER4DARBPROC glProgramEnvParameter4dARB = NULL;
PFNGLPROGRAMENVPARAMETER4DVARBPROC glProgramEnvParameter4dvARB = NULL;
PFNGLPROGRAMENVPARAMETER4FARBPROC glProgramEnvParameter4fARB = NULL;
PFNGLPROGRAMENVPARAMETER4FVARBPROC glProgramEnvParameter4fvARB = NULL;
PFNGLPROGRAMLOCALPARAMETER4DARBPROC glProgramLocalParameter4dARB = NULL;
PFNGLPROGRAMLOCALPARAMETER4DVARBPROC glProgramLocalParameter4dvARB = NULL;
PFNGLPROGRAMLOCALPARAMETER4FARBPROC glProgramLocalParameter4fARB = NULL;
PFNGLPROGRAMLOCALPARAMETER4FVARBPROC glProgramLocalParameter4fvARB = NULL;
PFNGLPROGRAMSTRINGARBPROC glProgramStringARB = NULL;
PFNGLVERTEXATTRIB1DARBPROC glVertexAttrib1dARB = NULL;
PFNGLVERTEXATTRIB1DVARBPROC glVertexAttrib1dvARB = NULL;
PFNGLVERTEXATTRIB1FARBPROC glVertexAttrib1fARB = NULL;
PFNGLVERTEXATTRIB1FVARBPROC glVertexAttrib1fvARB = NULL;
PFNGLVERTEXATTRIB1SARBPROC glVertexAttrib1sARB = NULL;
PFNGLVERTEXATTRIB1SVARBPROC glVertexAttrib1svARB = NULL;
PFNGLVERTEXATTRIB2DARBPROC glVertexAttrib2dARB = NULL;
PFNGLVERTEXATTRIB2DVARBPROC glVertexAttrib2dvARB = NULL;
PFNGLVERTEXATTRIB2FARBPROC glVertexAttrib2fARB = NULL;
PFNGLVERTEXATTRIB2FVARBPROC glVertexAttrib2fvARB = NULL;
PFNGLVERTEXATTRIB2SARBPROC glVertexAttrib2sARB = NULL;
PFNGLVERTEXATTRIB2SVARBPROC glVertexAttrib2svARB = NULL;
PFNGLVERTEXATTRIB3DARBPROC glVertexAttrib3dARB = NULL;
PFNGLVERTEXATTRIB3DVARBPROC glVertexAttrib3dvARB = NULL;
PFNGLVERTEXATTRIB3FARBPROC glVertexAttrib3fARB = NULL;
PFNGLVERTEXATTRIB3FVARBPROC glVertexAttrib3fvARB = NULL;
PFNGLVERTEXATTRIB3SARBPROC glVertexAttrib3sARB = NULL;
PFNGLVERTEXATTRIB3SVARBPROC glVertexAttrib3svARB = NULL;
PFNGLVERTEXATTRIB4BVARBPROC glVertexAttrib4bvARB = NULL;
PFNGLVERTEXATTRIB4DARBPROC glVertexAttrib4dARB = NULL;
PFNGLVERTEXATTRIB4DVARBPROC glVertexAttrib4dvARB = NULL;
PFNGLVERTEXATTRIB4FARBPROC glVertexAttrib4fARB = NULL;
PFNGLVERTEXATTRIB4FVARBPROC glVertexAttrib4fvARB = NULL;
PFNGLVERTEXATTRIB4IVARBPROC glVertexAttrib4ivARB = NULL;
PFNGLVERTEXATTRIB4NBVARBPROC glVertexAttrib4NbvARB = NULL;
PFNGLVERTEXATTRIB4NIVARBPROC glVertexAttrib4NivARB = NULL;
PFNGLVERTEXATTRIB4NSVARBPROC glVertexAttrib4NsvARB = NULL;
PFNGLVERTEXATTRIB4NUBARBPROC glVertexAttrib4NubARB = NULL;
PFNGLVERTEXATTRIB4NUBVARBPROC glVertexAttrib4NubvARB = NULL;
PFNGLVERTEXATTRIB4NUIVARBPROC glVertexAttrib4NuivARB = NULL;
PFNGLVERTEXATTRIB4NUSVARBPROC glVertexAttrib4NusvARB = NULL;
PFNGLVERTEXATTRIB4SARBPROC glVertexAttrib4sARB = NULL;
PFNGLVERTEXATTRIB4SVARBPROC glVertexAttrib4svARB = NULL;
PFNGLVERTEXATTRIB4UBVARBPROC glVertexAttrib4ubvARB = NULL;
PFNGLVERTEXATTRIB4UIVARBPROC glVertexAttrib4uivARB = NULL;
PFNGLVERTEXATTRIB4USVARBPROC glVertexAttrib4usvARB = NULL;
PFNGLVERTEXATTRIBPOINTERARBPROC glVertexAttribPointerARB = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glBindProgramARB = (PFNGLBINDPROGRAMARBPROC)SDL_GL_GetProcAddress("glBindProgramARB"))
			 && (glDeleteProgramsARB = (PFNGLDELETEPROGRAMSARBPROC)SDL_GL_GetProcAddress("glDeleteProgramsARB"))
			 && (glDisableVertexAttribArrayARB = (PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)SDL_GL_GetProcAddress("glDisableVertexAttribArrayARB"))
			 && (glEnableVertexAttribArrayARB = (PFNGLENABLEVERTEXATTRIBARRAYARBPROC)SDL_GL_GetProcAddress("glEnableVertexAttribArrayARB"))
			 && (glGenProgramsARB = (PFNGLGENPROGRAMSARBPROC)SDL_GL_GetProcAddress("glGenProgramsARB"))
			 && (glGetProgramEnvParameterdvARB = (PFNGLGETPROGRAMENVPARAMETERDVARBPROC)SDL_GL_GetProcAddress("glGetProgramEnvParameterdvARB"))
			 && (glGetProgramEnvParameterfvARB = (PFNGLGETPROGRAMENVPARAMETERFVARBPROC)SDL_GL_GetProcAddress("glGetProgramEnvParameterfvARB"))
			 && (glGetProgramivARB = (PFNGLGETPROGRAMIVARBPROC)SDL_GL_GetProcAddress("glGetProgramivARB"))
			 && (glGetProgramLocalParameterdvARB = (PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC)SDL_GL_GetProcAddress("glGetProgramLocalParameterdvARB"))
			 && (glGetProgramLocalParameterfvARB = (PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC)SDL_GL_GetProcAddress("glGetProgramLocalParameterfvARB"))
			 && (glGetProgramStringARB = (PFNGLGETPROGRAMSTRINGARBPROC)SDL_GL_GetProcAddress("glGetProgramStringARB"))
			 && (glGetVertexAttribdvARB = (PFNGLGETVERTEXATTRIBDVARBPROC)SDL_GL_GetProcAddress("glGetVertexAttribdvARB"))
			 && (glGetVertexAttribfvARB = (PFNGLGETVERTEXATTRIBFVARBPROC)SDL_GL_GetProcAddress("glGetVertexAttribfvARB"))
			 && (glGetVertexAttribivARB = (PFNGLGETVERTEXATTRIBIVARBPROC)SDL_GL_GetProcAddress("glGetVertexAttribivARB"))
			 && (glGetVertexAttribPointervARB = (PFNGLGETVERTEXATTRIBPOINTERVARBPROC)SDL_GL_GetProcAddress("glGetVertexAttribPointervARB"))
			 && (glIsProgramARB = (PFNGLISPROGRAMARBPROC)SDL_GL_GetProcAddress("glIsProgramARB"))
			 && (glProgramEnvParameter4dARB = (PFNGLPROGRAMENVPARAMETER4DARBPROC)SDL_GL_GetProcAddress("glProgramEnvParameter4dARB"))
			 && (glProgramEnvParameter4dvARB = (PFNGLPROGRAMENVPARAMETER4DVARBPROC)SDL_GL_GetProcAddress("glProgramEnvParameter4dvARB"))
			 && (glProgramEnvParameter4fARB = (PFNGLPROGRAMENVPARAMETER4FARBPROC)SDL_GL_GetProcAddress("glProgramEnvParameter4fARB"))
			 && (glProgramEnvParameter4fvARB = (PFNGLPROGRAMENVPARAMETER4FVARBPROC)SDL_GL_GetProcAddress("glProgramEnvParameter4fvARB"))
			 && (glProgramLocalParameter4dARB = (PFNGLPROGRAMLOCALPARAMETER4DARBPROC)SDL_GL_GetProcAddress("glProgramLocalParameter4dARB"))
			 && (glProgramLocalParameter4dvARB = (PFNGLPROGRAMLOCALPARAMETER4DVARBPROC)SDL_GL_GetProcAddress("glProgramLocalParameter4dvARB"))
			 && (glProgramLocalParameter4fARB = (PFNGLPROGRAMLOCALPARAMETER4FARBPROC)SDL_GL_GetProcAddress("glProgramLocalParameter4fARB"))
			 && (glProgramLocalParameter4fvARB = (PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)SDL_GL_GetProcAddress("glProgramLocalParameter4fvARB"))
			 && (glProgramStringARB = (PFNGLPROGRAMSTRINGARBPROC)SDL_GL_GetProcAddress("glProgramStringARB"))
			 && (glVertexAttrib1dARB = (PFNGLVERTEXATTRIB1DARBPROC)SDL_GL_GetProcAddress("glVertexAttrib1dARB"))
			 && (glVertexAttrib1dvARB = (PFNGLVERTEXATTRIB1DVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib1dvARB"))
			 && (glVertexAttrib1fARB = (PFNGLVERTEXATTRIB1FARBPROC)SDL_GL_GetProcAddress("glVertexAttrib1fARB"))
			 && (glVertexAttrib1fvARB = (PFNGLVERTEXATTRIB1FVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib1fvARB"))
			 && (glVertexAttrib1sARB = (PFNGLVERTEXATTRIB1SARBPROC)SDL_GL_GetProcAddress("glVertexAttrib1sARB"))
			 && (glVertexAttrib1svARB = (PFNGLVERTEXATTRIB1SVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib1svARB"))
			 && (glVertexAttrib2dARB = (PFNGLVERTEXATTRIB2DARBPROC)SDL_GL_GetProcAddress("glVertexAttrib2dARB"))
			 && (glVertexAttrib2dvARB = (PFNGLVERTEXATTRIB2DVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib2dvARB"))
			 && (glVertexAttrib2fARB = (PFNGLVERTEXATTRIB2FARBPROC)SDL_GL_GetProcAddress("glVertexAttrib2fARB"))
			 && (glVertexAttrib2fvARB = (PFNGLVERTEXATTRIB2FVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib2fvARB"))
			 && (glVertexAttrib2sARB = (PFNGLVERTEXATTRIB2SARBPROC)SDL_GL_GetProcAddress("glVertexAttrib2sARB"))
			 && (glVertexAttrib2svARB = (PFNGLVERTEXATTRIB2SVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib2svARB"))
			 && (glVertexAttrib3dARB = (PFNGLVERTEXATTRIB3DARBPROC)SDL_GL_GetProcAddress("glVertexAttrib3dARB"))
			 && (glVertexAttrib3dvARB = (PFNGLVERTEXATTRIB3DVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib3dvARB"))
			 && (glVertexAttrib3fARB = (PFNGLVERTEXATTRIB3FARBPROC)SDL_GL_GetProcAddress("glVertexAttrib3fARB"))
			 && (glVertexAttrib3fvARB = (PFNGLVERTEXATTRIB3FVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib3fvARB"))
			 && (glVertexAttrib3sARB = (PFNGLVERTEXATTRIB3SARBPROC)SDL_GL_GetProcAddress("glVertexAttrib3sARB"))
			 && (glVertexAttrib3svARB = (PFNGLVERTEXATTRIB3SVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib3svARB"))
			 && (glVertexAttrib4bvARB = (PFNGLVERTEXATTRIB4BVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib4bvARB"))
			 && (glVertexAttrib4dARB = (PFNGLVERTEXATTRIB4DARBPROC)SDL_GL_GetProcAddress("glVertexAttrib4dARB"))
			 && (glVertexAttrib4dvARB = (PFNGLVERTEXATTRIB4DVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib4dvARB"))
			 && (glVertexAttrib4fARB = (PFNGLVERTEXATTRIB4FARBPROC)SDL_GL_GetProcAddress("glVertexAttrib4fARB"))
			 && (glVertexAttrib4fvARB = (PFNGLVERTEXATTRIB4FVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib4fvARB"))
			 && (glVertexAttrib4ivARB = (PFNGLVERTEXATTRIB4IVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib4ivARB"))
			 && (glVertexAttrib4NbvARB = (PFNGLVERTEXATTRIB4NBVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib4NbvARB"))
			 && (glVertexAttrib4NivARB = (PFNGLVERTEXATTRIB4NIVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib4NivARB"))
			 && (glVertexAttrib4NsvARB = (PFNGLVERTEXATTRIB4NSVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib4NsvARB"))
			 && (glVertexAttrib4NubARB = (PFNGLVERTEXATTRIB4NUBARBPROC)SDL_GL_GetProcAddress("glVertexAttrib4NubARB"))
			 && (glVertexAttrib4NubvARB = (PFNGLVERTEXATTRIB4NUBVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib4NubvARB"))
			 && (glVertexAttrib4NuivARB = (PFNGLVERTEXATTRIB4NUIVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib4NuivARB"))
			 && (glVertexAttrib4NusvARB = (PFNGLVERTEXATTRIB4NUSVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib4NusvARB"))
			 && (glVertexAttrib4sARB = (PFNGLVERTEXATTRIB4SARBPROC)SDL_GL_GetProcAddress("glVertexAttrib4sARB"))
			 && (glVertexAttrib4svARB = (PFNGLVERTEXATTRIB4SVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib4svARB"))
			 && (glVertexAttrib4ubvARB = (PFNGLVERTEXATTRIB4UBVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib4ubvARB"))
			 && (glVertexAttrib4uivARB = (PFNGLVERTEXATTRIB4UIVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib4uivARB"))
			 && (glVertexAttrib4usvARB = (PFNGLVERTEXATTRIB4USVARBPROC)SDL_GL_GetProcAddress("glVertexAttrib4usvARB"))
			 && (glVertexAttribPointerARB = (PFNGLVERTEXATTRIBPOINTERARBPROC)SDL_GL_GetProcAddress("glVertexAttribPointerARB"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_vertex_program fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_vertex_program fails." << endl;
			}
		}
	}
	bool have_ARB_vertex_program() {
		return loaded;
	}
	void GL_ARB_vertex_program_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_vertex_program_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_vertex_program_NAMESPACE

//  ...for GL_ARB_vertex_shader:
namespace GL_ARB_vertex_shader_NAMESPACE {
PFNGLBINDATTRIBLOCATIONARBPROC glBindAttribLocationARB = NULL;
PFNGLGETACTIVEATTRIBARBPROC glGetActiveAttribARB = NULL;
PFNGLGETATTRIBLOCATIONARBPROC glGetAttribLocationARB = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glBindAttribLocationARB = (PFNGLBINDATTRIBLOCATIONARBPROC)SDL_GL_GetProcAddress("glBindAttribLocationARB"))
			 && (glGetActiveAttribARB = (PFNGLGETACTIVEATTRIBARBPROC)SDL_GL_GetProcAddress("glGetActiveAttribARB"))
			 && (glGetAttribLocationARB = (PFNGLGETATTRIBLOCATIONARBPROC)SDL_GL_GetProcAddress("glGetAttribLocationARB"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_vertex_shader fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_vertex_shader fails." << endl;
			}
		}
	}
	bool have_ARB_vertex_shader() {
		return loaded;
	}
	void GL_ARB_vertex_shader_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_vertex_shader_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_vertex_shader_NAMESPACE

//  ...for GL_ARB_window_pos:
namespace GL_ARB_window_pos_NAMESPACE {
PFNGLWINDOWPOS2DARBPROC glWindowPos2dARB = NULL;
PFNGLWINDOWPOS2DVARBPROC glWindowPos2dvARB = NULL;
PFNGLWINDOWPOS2FARBPROC glWindowPos2fARB = NULL;
PFNGLWINDOWPOS2FVARBPROC glWindowPos2fvARB = NULL;
PFNGLWINDOWPOS2IARBPROC glWindowPos2iARB = NULL;
PFNGLWINDOWPOS2IVARBPROC glWindowPos2ivARB = NULL;
PFNGLWINDOWPOS2SARBPROC glWindowPos2sARB = NULL;
PFNGLWINDOWPOS2SVARBPROC glWindowPos2svARB = NULL;
PFNGLWINDOWPOS3DARBPROC glWindowPos3dARB = NULL;
PFNGLWINDOWPOS3DVARBPROC glWindowPos3dvARB = NULL;
PFNGLWINDOWPOS3FARBPROC glWindowPos3fARB = NULL;
PFNGLWINDOWPOS3FVARBPROC glWindowPos3fvARB = NULL;
PFNGLWINDOWPOS3IARBPROC glWindowPos3iARB = NULL;
PFNGLWINDOWPOS3IVARBPROC glWindowPos3ivARB = NULL;
PFNGLWINDOWPOS3SARBPROC glWindowPos3sARB = NULL;
PFNGLWINDOWPOS3SVARBPROC glWindowPos3svARB = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glWindowPos2dARB = (PFNGLWINDOWPOS2DARBPROC)SDL_GL_GetProcAddress("glWindowPos2dARB"))
			 && (glWindowPos2dvARB = (PFNGLWINDOWPOS2DVARBPROC)SDL_GL_GetProcAddress("glWindowPos2dvARB"))
			 && (glWindowPos2fARB = (PFNGLWINDOWPOS2FARBPROC)SDL_GL_GetProcAddress("glWindowPos2fARB"))
			 && (glWindowPos2fvARB = (PFNGLWINDOWPOS2FVARBPROC)SDL_GL_GetProcAddress("glWindowPos2fvARB"))
			 && (glWindowPos2iARB = (PFNGLWINDOWPOS2IARBPROC)SDL_GL_GetProcAddress("glWindowPos2iARB"))
			 && (glWindowPos2ivARB = (PFNGLWINDOWPOS2IVARBPROC)SDL_GL_GetProcAddress("glWindowPos2ivARB"))
			 && (glWindowPos2sARB = (PFNGLWINDOWPOS2SARBPROC)SDL_GL_GetProcAddress("glWindowPos2sARB"))
			 && (glWindowPos2svARB = (PFNGLWINDOWPOS2SVARBPROC)SDL_GL_GetProcAddress("glWindowPos2svARB"))
			 && (glWindowPos3dARB = (PFNGLWINDOWPOS3DARBPROC)SDL_GL_GetProcAddress("glWindowPos3dARB"))
			 && (glWindowPos3dvARB = (PFNGLWINDOWPOS3DVARBPROC)SDL_GL_GetProcAddress("glWindowPos3dvARB"))
			 && (glWindowPos3fARB = (PFNGLWINDOWPOS3FARBPROC)SDL_GL_GetProcAddress("glWindowPos3fARB"))
			 && (glWindowPos3fvARB = (PFNGLWINDOWPOS3FVARBPROC)SDL_GL_GetProcAddress("glWindowPos3fvARB"))
			 && (glWindowPos3iARB = (PFNGLWINDOWPOS3IARBPROC)SDL_GL_GetProcAddress("glWindowPos3iARB"))
			 && (glWindowPos3ivARB = (PFNGLWINDOWPOS3IVARBPROC)SDL_GL_GetProcAddress("glWindowPos3ivARB"))
			 && (glWindowPos3sARB = (PFNGLWINDOWPOS3SARBPROC)SDL_GL_GetProcAddress("glWindowPos3sARB"))
			 && (glWindowPos3svARB = (PFNGLWINDOWPOS3SVARBPROC)SDL_GL_GetProcAddress("glWindowPos3svARB"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ARB_window_pos fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ARB_window_pos fails." << endl;
			}
		}
	}
	bool have_ARB_window_pos() {
		return loaded;
	}
	void GL_ARB_window_pos_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ARB_window_pos_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ARB_window_pos_NAMESPACE

//  ...for GL_ATI_draw_buffers:
namespace GL_ATI_draw_buffers_NAMESPACE {
PFNGLDRAWBUFFERSATIPROC glDrawBuffersATI = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glDrawBuffersATI = (PFNGLDRAWBUFFERSATIPROC)SDL_GL_GetProcAddress("glDrawBuffersATI"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ATI_draw_buffers fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ATI_draw_buffers fails." << endl;
			}
		}
	}
	bool have_ATI_draw_buffers() {
		return loaded;
	}
	void GL_ATI_draw_buffers_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ATI_draw_buffers_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ATI_draw_buffers_NAMESPACE

//  ...for GL_ATI_element_array:
namespace GL_ATI_element_array_NAMESPACE {
PFNGLDRAWELEMENTARRAYATIPROC glDrawElementArrayATI = NULL;
PFNGLDRAWRANGEELEMENTARRAYATIPROC glDrawRangeElementArrayATI = NULL;
PFNGLELEMENTPOINTERATIPROC glElementPointerATI = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glDrawElementArrayATI = (PFNGLDRAWELEMENTARRAYATIPROC)SDL_GL_GetProcAddress("glDrawElementArrayATI"))
			 && (glDrawRangeElementArrayATI = (PFNGLDRAWRANGEELEMENTARRAYATIPROC)SDL_GL_GetProcAddress("glDrawRangeElementArrayATI"))
			 && (glElementPointerATI = (PFNGLELEMENTPOINTERATIPROC)SDL_GL_GetProcAddress("glElementPointerATI"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ATI_element_array fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ATI_element_array fails." << endl;
			}
		}
	}
	bool have_ATI_element_array() {
		return loaded;
	}
	void GL_ATI_element_array_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ATI_element_array_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ATI_element_array_NAMESPACE

//  ...for GL_ATI_envmap_bumpmap:
namespace GL_ATI_envmap_bumpmap_NAMESPACE {
PFNGLGETTEXBUMPPARAMETERFVATIPROC glGetTexBumpParameterfvATI = NULL;
PFNGLGETTEXBUMPPARAMETERIVATIPROC glGetTexBumpParameterivATI = NULL;
PFNGLTEXBUMPPARAMETERFVATIPROC glTexBumpParameterfvATI = NULL;
PFNGLTEXBUMPPARAMETERIVATIPROC glTexBumpParameterivATI = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glGetTexBumpParameterfvATI = (PFNGLGETTEXBUMPPARAMETERFVATIPROC)SDL_GL_GetProcAddress("glGetTexBumpParameterfvATI"))
			 && (glGetTexBumpParameterivATI = (PFNGLGETTEXBUMPPARAMETERIVATIPROC)SDL_GL_GetProcAddress("glGetTexBumpParameterivATI"))
			 && (glTexBumpParameterfvATI = (PFNGLTEXBUMPPARAMETERFVATIPROC)SDL_GL_GetProcAddress("glTexBumpParameterfvATI"))
			 && (glTexBumpParameterivATI = (PFNGLTEXBUMPPARAMETERIVATIPROC)SDL_GL_GetProcAddress("glTexBumpParameterivATI"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ATI_envmap_bumpmap fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ATI_envmap_bumpmap fails." << endl;
			}
		}
	}
	bool have_ATI_envmap_bumpmap() {
		return loaded;
	}
	void GL_ATI_envmap_bumpmap_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ATI_envmap_bumpmap_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ATI_envmap_bumpmap_NAMESPACE

//  ...for GL_ATI_fragment_shader:
namespace GL_ATI_fragment_shader_NAMESPACE {
PFNGLALPHAFRAGMENTOP1ATIPROC glAlphaFragmentOp1ATI = NULL;
PFNGLALPHAFRAGMENTOP2ATIPROC glAlphaFragmentOp2ATI = NULL;
PFNGLALPHAFRAGMENTOP3ATIPROC glAlphaFragmentOp3ATI = NULL;
PFNGLBEGINFRAGMENTSHADERATIPROC glBeginFragmentShaderATI = NULL;
PFNGLBINDFRAGMENTSHADERATIPROC glBindFragmentShaderATI = NULL;
PFNGLCOLORFRAGMENTOP1ATIPROC glColorFragmentOp1ATI = NULL;
PFNGLCOLORFRAGMENTOP2ATIPROC glColorFragmentOp2ATI = NULL;
PFNGLCOLORFRAGMENTOP3ATIPROC glColorFragmentOp3ATI = NULL;
PFNGLDELETEFRAGMENTSHADERATIPROC glDeleteFragmentShaderATI = NULL;
PFNGLENDFRAGMENTSHADERATIPROC glEndFragmentShaderATI = NULL;
PFNGLGENFRAGMENTSHADERSATIPROC glGenFragmentShadersATI = NULL;
PFNGLPASSTEXCOORDATIPROC glPassTexCoordATI = NULL;
PFNGLSAMPLEMAPATIPROC glSampleMapATI = NULL;
PFNGLSETFRAGMENTSHADERCONSTANTATIPROC glSetFragmentShaderConstantATI = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glAlphaFragmentOp1ATI = (PFNGLALPHAFRAGMENTOP1ATIPROC)SDL_GL_GetProcAddress("glAlphaFragmentOp1ATI"))
			 && (glAlphaFragmentOp2ATI = (PFNGLALPHAFRAGMENTOP2ATIPROC)SDL_GL_GetProcAddress("glAlphaFragmentOp2ATI"))
			 && (glAlphaFragmentOp3ATI = (PFNGLALPHAFRAGMENTOP3ATIPROC)SDL_GL_GetProcAddress("glAlphaFragmentOp3ATI"))
			 && (glBeginFragmentShaderATI = (PFNGLBEGINFRAGMENTSHADERATIPROC)SDL_GL_GetProcAddress("glBeginFragmentShaderATI"))
			 && (glBindFragmentShaderATI = (PFNGLBINDFRAGMENTSHADERATIPROC)SDL_GL_GetProcAddress("glBindFragmentShaderATI"))
			 && (glColorFragmentOp1ATI = (PFNGLCOLORFRAGMENTOP1ATIPROC)SDL_GL_GetProcAddress("glColorFragmentOp1ATI"))
			 && (glColorFragmentOp2ATI = (PFNGLCOLORFRAGMENTOP2ATIPROC)SDL_GL_GetProcAddress("glColorFragmentOp2ATI"))
			 && (glColorFragmentOp3ATI = (PFNGLCOLORFRAGMENTOP3ATIPROC)SDL_GL_GetProcAddress("glColorFragmentOp3ATI"))
			 && (glDeleteFragmentShaderATI = (PFNGLDELETEFRAGMENTSHADERATIPROC)SDL_GL_GetProcAddress("glDeleteFragmentShaderATI"))
			 && (glEndFragmentShaderATI = (PFNGLENDFRAGMENTSHADERATIPROC)SDL_GL_GetProcAddress("glEndFragmentShaderATI"))
			 && (glGenFragmentShadersATI = (PFNGLGENFRAGMENTSHADERSATIPROC)SDL_GL_GetProcAddress("glGenFragmentShadersATI"))
			 && (glPassTexCoordATI = (PFNGLPASSTEXCOORDATIPROC)SDL_GL_GetProcAddress("glPassTexCoordATI"))
			 && (glSampleMapATI = (PFNGLSAMPLEMAPATIPROC)SDL_GL_GetProcAddress("glSampleMapATI"))
			 && (glSetFragmentShaderConstantATI = (PFNGLSETFRAGMENTSHADERCONSTANTATIPROC)SDL_GL_GetProcAddress("glSetFragmentShaderConstantATI"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ATI_fragment_shader fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ATI_fragment_shader fails." << endl;
			}
		}
	}
	bool have_ATI_fragment_shader() {
		return loaded;
	}
	void GL_ATI_fragment_shader_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ATI_fragment_shader_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ATI_fragment_shader_NAMESPACE

//  ...for GL_ATI_map_object_buffer:
namespace GL_ATI_map_object_buffer_NAMESPACE {
PFNGLMAPOBJECTBUFFERATIPROC glMapObjectBufferATI = NULL;
PFNGLUNMAPOBJECTBUFFERATIPROC glUnmapObjectBufferATI = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glMapObjectBufferATI = (PFNGLMAPOBJECTBUFFERATIPROC)SDL_GL_GetProcAddress("glMapObjectBufferATI"))
			 && (glUnmapObjectBufferATI = (PFNGLUNMAPOBJECTBUFFERATIPROC)SDL_GL_GetProcAddress("glUnmapObjectBufferATI"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ATI_map_object_buffer fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ATI_map_object_buffer fails." << endl;
			}
		}
	}
	bool have_ATI_map_object_buffer() {
		return loaded;
	}
	void GL_ATI_map_object_buffer_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ATI_map_object_buffer_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ATI_map_object_buffer_NAMESPACE

//  ...for GL_ATI_pixel_format_float:
namespace GL_ATI_pixel_format_float_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ATI_pixel_format_float fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ATI_pixel_format_float fails." << endl;
			}
		}
	}
	bool have_ATI_pixel_format_float() {
		return loaded;
	}
	void GL_ATI_pixel_format_float_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ATI_pixel_format_float_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ATI_pixel_format_float_NAMESPACE

//  ...for GL_ATI_pn_triangles:
namespace GL_ATI_pn_triangles_NAMESPACE {
PFNGLPNTRIANGLESFATIPROC glPNTrianglesfATI = NULL;
PFNGLPNTRIANGLESIATIPROC glPNTrianglesiATI = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glPNTrianglesfATI = (PFNGLPNTRIANGLESFATIPROC)SDL_GL_GetProcAddress("glPNTrianglesfATI"))
			 && (glPNTrianglesiATI = (PFNGLPNTRIANGLESIATIPROC)SDL_GL_GetProcAddress("glPNTrianglesiATI"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ATI_pn_triangles fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ATI_pn_triangles fails." << endl;
			}
		}
	}
	bool have_ATI_pn_triangles() {
		return loaded;
	}
	void GL_ATI_pn_triangles_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ATI_pn_triangles_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ATI_pn_triangles_NAMESPACE

//  ...for GL_ATI_separate_stencil:
namespace GL_ATI_separate_stencil_NAMESPACE {
PFNGLSTENCILFUNCSEPARATEATIPROC glStencilFuncSeparateATI = NULL;
PFNGLSTENCILOPSEPARATEATIPROC glStencilOpSeparateATI = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glStencilFuncSeparateATI = (PFNGLSTENCILFUNCSEPARATEATIPROC)SDL_GL_GetProcAddress("glStencilFuncSeparateATI"))
			 && (glStencilOpSeparateATI = (PFNGLSTENCILOPSEPARATEATIPROC)SDL_GL_GetProcAddress("glStencilOpSeparateATI"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ATI_separate_stencil fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ATI_separate_stencil fails." << endl;
			}
		}
	}
	bool have_ATI_separate_stencil() {
		return loaded;
	}
	void GL_ATI_separate_stencil_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ATI_separate_stencil_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ATI_separate_stencil_NAMESPACE

//  ...for GL_ATI_text_fragment_shader:
namespace GL_ATI_text_fragment_shader_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ATI_text_fragment_shader fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ATI_text_fragment_shader fails." << endl;
			}
		}
	}
	bool have_ATI_text_fragment_shader() {
		return loaded;
	}
	void GL_ATI_text_fragment_shader_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ATI_text_fragment_shader_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ATI_text_fragment_shader_NAMESPACE

//  ...for GL_ATI_texture_env_combine3:
namespace GL_ATI_texture_env_combine3_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ATI_texture_env_combine3 fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ATI_texture_env_combine3 fails." << endl;
			}
		}
	}
	bool have_ATI_texture_env_combine3() {
		return loaded;
	}
	void GL_ATI_texture_env_combine3_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ATI_texture_env_combine3_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ATI_texture_env_combine3_NAMESPACE

//  ...for GL_ATI_texture_float:
namespace GL_ATI_texture_float_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ATI_texture_float fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ATI_texture_float fails." << endl;
			}
		}
	}
	bool have_ATI_texture_float() {
		return loaded;
	}
	void GL_ATI_texture_float_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ATI_texture_float_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ATI_texture_float_NAMESPACE

//  ...for GL_ATI_texture_mirror_once:
namespace GL_ATI_texture_mirror_once_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ATI_texture_mirror_once fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ATI_texture_mirror_once fails." << endl;
			}
		}
	}
	bool have_ATI_texture_mirror_once() {
		return loaded;
	}
	void GL_ATI_texture_mirror_once_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ATI_texture_mirror_once_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ATI_texture_mirror_once_NAMESPACE

//  ...for GL_ATI_vertex_array_object:
namespace GL_ATI_vertex_array_object_NAMESPACE {
PFNGLARRAYOBJECTATIPROC glArrayObjectATI = NULL;
PFNGLFREEOBJECTBUFFERATIPROC glFreeObjectBufferATI = NULL;
PFNGLGETARRAYOBJECTFVATIPROC glGetArrayObjectfvATI = NULL;
PFNGLGETARRAYOBJECTIVATIPROC glGetArrayObjectivATI = NULL;
PFNGLGETOBJECTBUFFERFVATIPROC glGetObjectBufferfvATI = NULL;
PFNGLGETOBJECTBUFFERIVATIPROC glGetObjectBufferivATI = NULL;
PFNGLGETVARIANTARRAYOBJECTFVATIPROC glGetVariantArrayObjectfvATI = NULL;
PFNGLGETVARIANTARRAYOBJECTIVATIPROC glGetVariantArrayObjectivATI = NULL;
PFNGLISOBJECTBUFFERATIPROC glIsObjectBufferATI = NULL;
PFNGLNEWOBJECTBUFFERATIPROC glNewObjectBufferATI = NULL;
PFNGLUPDATEOBJECTBUFFERATIPROC glUpdateObjectBufferATI = NULL;
PFNGLVARIANTARRAYOBJECTATIPROC glVariantArrayObjectATI = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glArrayObjectATI = (PFNGLARRAYOBJECTATIPROC)SDL_GL_GetProcAddress("glArrayObjectATI"))
			 && (glFreeObjectBufferATI = (PFNGLFREEOBJECTBUFFERATIPROC)SDL_GL_GetProcAddress("glFreeObjectBufferATI"))
			 && (glGetArrayObjectfvATI = (PFNGLGETARRAYOBJECTFVATIPROC)SDL_GL_GetProcAddress("glGetArrayObjectfvATI"))
			 && (glGetArrayObjectivATI = (PFNGLGETARRAYOBJECTIVATIPROC)SDL_GL_GetProcAddress("glGetArrayObjectivATI"))
			 && (glGetObjectBufferfvATI = (PFNGLGETOBJECTBUFFERFVATIPROC)SDL_GL_GetProcAddress("glGetObjectBufferfvATI"))
			 && (glGetObjectBufferivATI = (PFNGLGETOBJECTBUFFERIVATIPROC)SDL_GL_GetProcAddress("glGetObjectBufferivATI"))
			 && (glGetVariantArrayObjectfvATI = (PFNGLGETVARIANTARRAYOBJECTFVATIPROC)SDL_GL_GetProcAddress("glGetVariantArrayObjectfvATI"))
			 && (glGetVariantArrayObjectivATI = (PFNGLGETVARIANTARRAYOBJECTIVATIPROC)SDL_GL_GetProcAddress("glGetVariantArrayObjectivATI"))
			 && (glIsObjectBufferATI = (PFNGLISOBJECTBUFFERATIPROC)SDL_GL_GetProcAddress("glIsObjectBufferATI"))
			 && (glNewObjectBufferATI = (PFNGLNEWOBJECTBUFFERATIPROC)SDL_GL_GetProcAddress("glNewObjectBufferATI"))
			 && (glUpdateObjectBufferATI = (PFNGLUPDATEOBJECTBUFFERATIPROC)SDL_GL_GetProcAddress("glUpdateObjectBufferATI"))
			 && (glVariantArrayObjectATI = (PFNGLVARIANTARRAYOBJECTATIPROC)SDL_GL_GetProcAddress("glVariantArrayObjectATI"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ATI_vertex_array_object fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ATI_vertex_array_object fails." << endl;
			}
		}
	}
	bool have_ATI_vertex_array_object() {
		return loaded;
	}
	void GL_ATI_vertex_array_object_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ATI_vertex_array_object_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ATI_vertex_array_object_NAMESPACE

//  ...for GL_ATI_vertex_attrib_array_object:
namespace GL_ATI_vertex_attrib_array_object_NAMESPACE {
PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC glGetVertexAttribArrayObjectfvATI = NULL;
PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC glGetVertexAttribArrayObjectivATI = NULL;
PFNGLVERTEXATTRIBARRAYOBJECTATIPROC glVertexAttribArrayObjectATI = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glGetVertexAttribArrayObjectfvATI = (PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC)SDL_GL_GetProcAddress("glGetVertexAttribArrayObjectfvATI"))
			 && (glGetVertexAttribArrayObjectivATI = (PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC)SDL_GL_GetProcAddress("glGetVertexAttribArrayObjectivATI"))
			 && (glVertexAttribArrayObjectATI = (PFNGLVERTEXATTRIBARRAYOBJECTATIPROC)SDL_GL_GetProcAddress("glVertexAttribArrayObjectATI"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ATI_vertex_attrib_array_object fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ATI_vertex_attrib_array_object fails." << endl;
			}
		}
	}
	bool have_ATI_vertex_attrib_array_object() {
		return loaded;
	}
	void GL_ATI_vertex_attrib_array_object_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ATI_vertex_attrib_array_object_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ATI_vertex_attrib_array_object_NAMESPACE

//  ...for GL_ATI_vertex_streams:
namespace GL_ATI_vertex_streams_NAMESPACE {
PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC glClientActiveVertexStreamATI = NULL;
PFNGLNORMALSTREAM3BATIPROC glNormalStream3bATI = NULL;
PFNGLNORMALSTREAM3BVATIPROC glNormalStream3bvATI = NULL;
PFNGLNORMALSTREAM3DATIPROC glNormalStream3dATI = NULL;
PFNGLNORMALSTREAM3DVATIPROC glNormalStream3dvATI = NULL;
PFNGLNORMALSTREAM3FATIPROC glNormalStream3fATI = NULL;
PFNGLNORMALSTREAM3FVATIPROC glNormalStream3fvATI = NULL;
PFNGLNORMALSTREAM3IATIPROC glNormalStream3iATI = NULL;
PFNGLNORMALSTREAM3IVATIPROC glNormalStream3ivATI = NULL;
PFNGLNORMALSTREAM3SATIPROC glNormalStream3sATI = NULL;
PFNGLNORMALSTREAM3SVATIPROC glNormalStream3svATI = NULL;
PFNGLVERTEXBLENDENVFATIPROC glVertexBlendEnvfATI = NULL;
PFNGLVERTEXBLENDENVIATIPROC glVertexBlendEnviATI = NULL;
PFNGLVERTEXSTREAM1DATIPROC glVertexStream1dATI = NULL;
PFNGLVERTEXSTREAM1DVATIPROC glVertexStream1dvATI = NULL;
PFNGLVERTEXSTREAM1FATIPROC glVertexStream1fATI = NULL;
PFNGLVERTEXSTREAM1FVATIPROC glVertexStream1fvATI = NULL;
PFNGLVERTEXSTREAM1IATIPROC glVertexStream1iATI = NULL;
PFNGLVERTEXSTREAM1IVATIPROC glVertexStream1ivATI = NULL;
PFNGLVERTEXSTREAM1SATIPROC glVertexStream1sATI = NULL;
PFNGLVERTEXSTREAM1SVATIPROC glVertexStream1svATI = NULL;
PFNGLVERTEXSTREAM2DATIPROC glVertexStream2dATI = NULL;
PFNGLVERTEXSTREAM2DVATIPROC glVertexStream2dvATI = NULL;
PFNGLVERTEXSTREAM2FATIPROC glVertexStream2fATI = NULL;
PFNGLVERTEXSTREAM2FVATIPROC glVertexStream2fvATI = NULL;
PFNGLVERTEXSTREAM2IATIPROC glVertexStream2iATI = NULL;
PFNGLVERTEXSTREAM2IVATIPROC glVertexStream2ivATI = NULL;
PFNGLVERTEXSTREAM2SATIPROC glVertexStream2sATI = NULL;
PFNGLVERTEXSTREAM2SVATIPROC glVertexStream2svATI = NULL;
PFNGLVERTEXSTREAM3DATIPROC glVertexStream3dATI = NULL;
PFNGLVERTEXSTREAM3DVATIPROC glVertexStream3dvATI = NULL;
PFNGLVERTEXSTREAM3FATIPROC glVertexStream3fATI = NULL;
PFNGLVERTEXSTREAM3FVATIPROC glVertexStream3fvATI = NULL;
PFNGLVERTEXSTREAM3IATIPROC glVertexStream3iATI = NULL;
PFNGLVERTEXSTREAM3IVATIPROC glVertexStream3ivATI = NULL;
PFNGLVERTEXSTREAM3SATIPROC glVertexStream3sATI = NULL;
PFNGLVERTEXSTREAM3SVATIPROC glVertexStream3svATI = NULL;
PFNGLVERTEXSTREAM4DATIPROC glVertexStream4dATI = NULL;
PFNGLVERTEXSTREAM4DVATIPROC glVertexStream4dvATI = NULL;
PFNGLVERTEXSTREAM4FATIPROC glVertexStream4fATI = NULL;
PFNGLVERTEXSTREAM4FVATIPROC glVertexStream4fvATI = NULL;
PFNGLVERTEXSTREAM4IATIPROC glVertexStream4iATI = NULL;
PFNGLVERTEXSTREAM4IVATIPROC glVertexStream4ivATI = NULL;
PFNGLVERTEXSTREAM4SATIPROC glVertexStream4sATI = NULL;
PFNGLVERTEXSTREAM4SVATIPROC glVertexStream4svATI = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glClientActiveVertexStreamATI = (PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC)SDL_GL_GetProcAddress("glClientActiveVertexStreamATI"))
			 && (glNormalStream3bATI = (PFNGLNORMALSTREAM3BATIPROC)SDL_GL_GetProcAddress("glNormalStream3bATI"))
			 && (glNormalStream3bvATI = (PFNGLNORMALSTREAM3BVATIPROC)SDL_GL_GetProcAddress("glNormalStream3bvATI"))
			 && (glNormalStream3dATI = (PFNGLNORMALSTREAM3DATIPROC)SDL_GL_GetProcAddress("glNormalStream3dATI"))
			 && (glNormalStream3dvATI = (PFNGLNORMALSTREAM3DVATIPROC)SDL_GL_GetProcAddress("glNormalStream3dvATI"))
			 && (glNormalStream3fATI = (PFNGLNORMALSTREAM3FATIPROC)SDL_GL_GetProcAddress("glNormalStream3fATI"))
			 && (glNormalStream3fvATI = (PFNGLNORMALSTREAM3FVATIPROC)SDL_GL_GetProcAddress("glNormalStream3fvATI"))
			 && (glNormalStream3iATI = (PFNGLNORMALSTREAM3IATIPROC)SDL_GL_GetProcAddress("glNormalStream3iATI"))
			 && (glNormalStream3ivATI = (PFNGLNORMALSTREAM3IVATIPROC)SDL_GL_GetProcAddress("glNormalStream3ivATI"))
			 && (glNormalStream3sATI = (PFNGLNORMALSTREAM3SATIPROC)SDL_GL_GetProcAddress("glNormalStream3sATI"))
			 && (glNormalStream3svATI = (PFNGLNORMALSTREAM3SVATIPROC)SDL_GL_GetProcAddress("glNormalStream3svATI"))
			 && (glVertexBlendEnvfATI = (PFNGLVERTEXBLENDENVFATIPROC)SDL_GL_GetProcAddress("glVertexBlendEnvfATI"))
			 && (glVertexBlendEnviATI = (PFNGLVERTEXBLENDENVIATIPROC)SDL_GL_GetProcAddress("glVertexBlendEnviATI"))
			 && (glVertexStream1dATI = (PFNGLVERTEXSTREAM1DATIPROC)SDL_GL_GetProcAddress("glVertexStream1dATI"))
			 && (glVertexStream1dvATI = (PFNGLVERTEXSTREAM1DVATIPROC)SDL_GL_GetProcAddress("glVertexStream1dvATI"))
			 && (glVertexStream1fATI = (PFNGLVERTEXSTREAM1FATIPROC)SDL_GL_GetProcAddress("glVertexStream1fATI"))
			 && (glVertexStream1fvATI = (PFNGLVERTEXSTREAM1FVATIPROC)SDL_GL_GetProcAddress("glVertexStream1fvATI"))
			 && (glVertexStream1iATI = (PFNGLVERTEXSTREAM1IATIPROC)SDL_GL_GetProcAddress("glVertexStream1iATI"))
			 && (glVertexStream1ivATI = (PFNGLVERTEXSTREAM1IVATIPROC)SDL_GL_GetProcAddress("glVertexStream1ivATI"))
			 && (glVertexStream1sATI = (PFNGLVERTEXSTREAM1SATIPROC)SDL_GL_GetProcAddress("glVertexStream1sATI"))
			 && (glVertexStream1svATI = (PFNGLVERTEXSTREAM1SVATIPROC)SDL_GL_GetProcAddress("glVertexStream1svATI"))
			 && (glVertexStream2dATI = (PFNGLVERTEXSTREAM2DATIPROC)SDL_GL_GetProcAddress("glVertexStream2dATI"))
			 && (glVertexStream2dvATI = (PFNGLVERTEXSTREAM2DVATIPROC)SDL_GL_GetProcAddress("glVertexStream2dvATI"))
			 && (glVertexStream2fATI = (PFNGLVERTEXSTREAM2FATIPROC)SDL_GL_GetProcAddress("glVertexStream2fATI"))
			 && (glVertexStream2fvATI = (PFNGLVERTEXSTREAM2FVATIPROC)SDL_GL_GetProcAddress("glVertexStream2fvATI"))
			 && (glVertexStream2iATI = (PFNGLVERTEXSTREAM2IATIPROC)SDL_GL_GetProcAddress("glVertexStream2iATI"))
			 && (glVertexStream2ivATI = (PFNGLVERTEXSTREAM2IVATIPROC)SDL_GL_GetProcAddress("glVertexStream2ivATI"))
			 && (glVertexStream2sATI = (PFNGLVERTEXSTREAM2SATIPROC)SDL_GL_GetProcAddress("glVertexStream2sATI"))
			 && (glVertexStream2svATI = (PFNGLVERTEXSTREAM2SVATIPROC)SDL_GL_GetProcAddress("glVertexStream2svATI"))
			 && (glVertexStream3dATI = (PFNGLVERTEXSTREAM3DATIPROC)SDL_GL_GetProcAddress("glVertexStream3dATI"))
			 && (glVertexStream3dvATI = (PFNGLVERTEXSTREAM3DVATIPROC)SDL_GL_GetProcAddress("glVertexStream3dvATI"))
			 && (glVertexStream3fATI = (PFNGLVERTEXSTREAM3FATIPROC)SDL_GL_GetProcAddress("glVertexStream3fATI"))
			 && (glVertexStream3fvATI = (PFNGLVERTEXSTREAM3FVATIPROC)SDL_GL_GetProcAddress("glVertexStream3fvATI"))
			 && (glVertexStream3iATI = (PFNGLVERTEXSTREAM3IATIPROC)SDL_GL_GetProcAddress("glVertexStream3iATI"))
			 && (glVertexStream3ivATI = (PFNGLVERTEXSTREAM3IVATIPROC)SDL_GL_GetProcAddress("glVertexStream3ivATI"))
			 && (glVertexStream3sATI = (PFNGLVERTEXSTREAM3SATIPROC)SDL_GL_GetProcAddress("glVertexStream3sATI"))
			 && (glVertexStream3svATI = (PFNGLVERTEXSTREAM3SVATIPROC)SDL_GL_GetProcAddress("glVertexStream3svATI"))
			 && (glVertexStream4dATI = (PFNGLVERTEXSTREAM4DATIPROC)SDL_GL_GetProcAddress("glVertexStream4dATI"))
			 && (glVertexStream4dvATI = (PFNGLVERTEXSTREAM4DVATIPROC)SDL_GL_GetProcAddress("glVertexStream4dvATI"))
			 && (glVertexStream4fATI = (PFNGLVERTEXSTREAM4FATIPROC)SDL_GL_GetProcAddress("glVertexStream4fATI"))
			 && (glVertexStream4fvATI = (PFNGLVERTEXSTREAM4FVATIPROC)SDL_GL_GetProcAddress("glVertexStream4fvATI"))
			 && (glVertexStream4iATI = (PFNGLVERTEXSTREAM4IATIPROC)SDL_GL_GetProcAddress("glVertexStream4iATI"))
			 && (glVertexStream4ivATI = (PFNGLVERTEXSTREAM4IVATIPROC)SDL_GL_GetProcAddress("glVertexStream4ivATI"))
			 && (glVertexStream4sATI = (PFNGLVERTEXSTREAM4SATIPROC)SDL_GL_GetProcAddress("glVertexStream4sATI"))
			 && (glVertexStream4svATI = (PFNGLVERTEXSTREAM4SVATIPROC)SDL_GL_GetProcAddress("glVertexStream4svATI"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_ATI_vertex_streams fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_ATI_vertex_streams fails." << endl;
			}
		}
	}
	bool have_ATI_vertex_streams() {
		return loaded;
	}
	void GL_ATI_vertex_streams_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_ATI_vertex_streams_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_ATI_vertex_streams_NAMESPACE

//  ...for GL_EXT_422_pixels:
namespace GL_EXT_422_pixels_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_422_pixels fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_422_pixels fails." << endl;
			}
		}
	}
	bool have_EXT_422_pixels() {
		return loaded;
	}
	void GL_EXT_422_pixels_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_422_pixels_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_422_pixels_NAMESPACE

//  ...for GL_EXT_abgr:
namespace GL_EXT_abgr_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_abgr fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_abgr fails." << endl;
			}
		}
	}
	bool have_EXT_abgr() {
		return loaded;
	}
	void GL_EXT_abgr_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_abgr_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_abgr_NAMESPACE

//  ...for GL_EXT_bgra:
namespace GL_EXT_bgra_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_bgra fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_bgra fails." << endl;
			}
		}
	}
	bool have_EXT_bgra() {
		return loaded;
	}
	void GL_EXT_bgra_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_bgra_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_bgra_NAMESPACE

//  ...for GL_EXT_blend_color:
namespace GL_EXT_blend_color_NAMESPACE {
PFNGLBLENDCOLOREXTPROC glBlendColorEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glBlendColorEXT = (PFNGLBLENDCOLOREXTPROC)SDL_GL_GetProcAddress("glBlendColorEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_blend_color fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_blend_color fails." << endl;
			}
		}
	}
	bool have_EXT_blend_color() {
		return loaded;
	}
	void GL_EXT_blend_color_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_blend_color_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_blend_color_NAMESPACE

//  ...for GL_EXT_blend_equation_separate:
namespace GL_EXT_blend_equation_separate_NAMESPACE {
PFNGLBLENDEQUATIONSEPARATEEXTPROC glBlendEquationSeparateEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glBlendEquationSeparateEXT = (PFNGLBLENDEQUATIONSEPARATEEXTPROC)SDL_GL_GetProcAddress("glBlendEquationSeparateEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_blend_equation_separate fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_blend_equation_separate fails." << endl;
			}
		}
	}
	bool have_EXT_blend_equation_separate() {
		return loaded;
	}
	void GL_EXT_blend_equation_separate_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_blend_equation_separate_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_blend_equation_separate_NAMESPACE

//  ...for GL_EXT_blend_func_separate:
namespace GL_EXT_blend_func_separate_NAMESPACE {
PFNGLBLENDFUNCSEPARATEEXTPROC glBlendFuncSeparateEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glBlendFuncSeparateEXT = (PFNGLBLENDFUNCSEPARATEEXTPROC)SDL_GL_GetProcAddress("glBlendFuncSeparateEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_blend_func_separate fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_blend_func_separate fails." << endl;
			}
		}
	}
	bool have_EXT_blend_func_separate() {
		return loaded;
	}
	void GL_EXT_blend_func_separate_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_blend_func_separate_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_blend_func_separate_NAMESPACE

//  ...for GL_EXT_blend_logic_op:
namespace GL_EXT_blend_logic_op_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_blend_logic_op fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_blend_logic_op fails." << endl;
			}
		}
	}
	bool have_EXT_blend_logic_op() {
		return loaded;
	}
	void GL_EXT_blend_logic_op_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_blend_logic_op_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_blend_logic_op_NAMESPACE

//  ...for GL_EXT_blend_minmax:
namespace GL_EXT_blend_minmax_NAMESPACE {
PFNGLBLENDEQUATIONEXTPROC glBlendEquationEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glBlendEquationEXT = (PFNGLBLENDEQUATIONEXTPROC)SDL_GL_GetProcAddress("glBlendEquationEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_blend_minmax fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_blend_minmax fails." << endl;
			}
		}
	}
	bool have_EXT_blend_minmax() {
		return loaded;
	}
	void GL_EXT_blend_minmax_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_blend_minmax_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_blend_minmax_NAMESPACE

//  ...for GL_EXT_blend_subtract:
namespace GL_EXT_blend_subtract_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_blend_subtract fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_blend_subtract fails." << endl;
			}
		}
	}
	bool have_EXT_blend_subtract() {
		return loaded;
	}
	void GL_EXT_blend_subtract_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_blend_subtract_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_blend_subtract_NAMESPACE

//  ...for GL_EXT_clip_volume_hint:
namespace GL_EXT_clip_volume_hint_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_clip_volume_hint fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_clip_volume_hint fails." << endl;
			}
		}
	}
	bool have_EXT_clip_volume_hint() {
		return loaded;
	}
	void GL_EXT_clip_volume_hint_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_clip_volume_hint_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_clip_volume_hint_NAMESPACE

//  ...for GL_EXT_cmyka:
namespace GL_EXT_cmyka_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_cmyka fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_cmyka fails." << endl;
			}
		}
	}
	bool have_EXT_cmyka() {
		return loaded;
	}
	void GL_EXT_cmyka_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_cmyka_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_cmyka_NAMESPACE

//  ...for GL_EXT_color_matrix:
namespace GL_EXT_color_matrix_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_color_matrix fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_color_matrix fails." << endl;
			}
		}
	}
	bool have_EXT_color_matrix() {
		return loaded;
	}
	void GL_EXT_color_matrix_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_color_matrix_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_color_matrix_NAMESPACE

//  ...for GL_EXT_color_subtable:
namespace GL_EXT_color_subtable_NAMESPACE {
PFNGLCOLORSUBTABLEEXTPROC glColorSubTableEXT = NULL;
PFNGLCOPYCOLORSUBTABLEEXTPROC glCopyColorSubTableEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glColorSubTableEXT = (PFNGLCOLORSUBTABLEEXTPROC)SDL_GL_GetProcAddress("glColorSubTableEXT"))
			 && (glCopyColorSubTableEXT = (PFNGLCOPYCOLORSUBTABLEEXTPROC)SDL_GL_GetProcAddress("glCopyColorSubTableEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_color_subtable fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_color_subtable fails." << endl;
			}
		}
	}
	bool have_EXT_color_subtable() {
		return loaded;
	}
	void GL_EXT_color_subtable_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_color_subtable_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_color_subtable_NAMESPACE

//  ...for GL_EXT_compiled_vertex_array:
namespace GL_EXT_compiled_vertex_array_NAMESPACE {
PFNGLLOCKARRAYSEXTPROC glLockArraysEXT = NULL;
PFNGLUNLOCKARRAYSEXTPROC glUnlockArraysEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glLockArraysEXT = (PFNGLLOCKARRAYSEXTPROC)SDL_GL_GetProcAddress("glLockArraysEXT"))
			 && (glUnlockArraysEXT = (PFNGLUNLOCKARRAYSEXTPROC)SDL_GL_GetProcAddress("glUnlockArraysEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_compiled_vertex_array fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_compiled_vertex_array fails." << endl;
			}
		}
	}
	bool have_EXT_compiled_vertex_array() {
		return loaded;
	}
	void GL_EXT_compiled_vertex_array_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_compiled_vertex_array_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_compiled_vertex_array_NAMESPACE

//  ...for GL_EXT_convolution:
namespace GL_EXT_convolution_NAMESPACE {
PFNGLCONVOLUTIONFILTER1DEXTPROC glConvolutionFilter1DEXT = NULL;
PFNGLCONVOLUTIONFILTER2DEXTPROC glConvolutionFilter2DEXT = NULL;
PFNGLCONVOLUTIONPARAMETERFEXTPROC glConvolutionParameterfEXT = NULL;
PFNGLCONVOLUTIONPARAMETERFVEXTPROC glConvolutionParameterfvEXT = NULL;
PFNGLCONVOLUTIONPARAMETERIEXTPROC glConvolutionParameteriEXT = NULL;
PFNGLCONVOLUTIONPARAMETERIVEXTPROC glConvolutionParameterivEXT = NULL;
PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC glCopyConvolutionFilter1DEXT = NULL;
PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC glCopyConvolutionFilter2DEXT = NULL;
PFNGLGETCONVOLUTIONFILTEREXTPROC glGetConvolutionFilterEXT = NULL;
PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC glGetConvolutionParameterfvEXT = NULL;
PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC glGetConvolutionParameterivEXT = NULL;
PFNGLGETSEPARABLEFILTEREXTPROC glGetSeparableFilterEXT = NULL;
PFNGLSEPARABLEFILTER2DEXTPROC glSeparableFilter2DEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glConvolutionFilter1DEXT = (PFNGLCONVOLUTIONFILTER1DEXTPROC)SDL_GL_GetProcAddress("glConvolutionFilter1DEXT"))
			 && (glConvolutionFilter2DEXT = (PFNGLCONVOLUTIONFILTER2DEXTPROC)SDL_GL_GetProcAddress("glConvolutionFilter2DEXT"))
			 && (glConvolutionParameterfEXT = (PFNGLCONVOLUTIONPARAMETERFEXTPROC)SDL_GL_GetProcAddress("glConvolutionParameterfEXT"))
			 && (glConvolutionParameterfvEXT = (PFNGLCONVOLUTIONPARAMETERFVEXTPROC)SDL_GL_GetProcAddress("glConvolutionParameterfvEXT"))
			 && (glConvolutionParameteriEXT = (PFNGLCONVOLUTIONPARAMETERIEXTPROC)SDL_GL_GetProcAddress("glConvolutionParameteriEXT"))
			 && (glConvolutionParameterivEXT = (PFNGLCONVOLUTIONPARAMETERIVEXTPROC)SDL_GL_GetProcAddress("glConvolutionParameterivEXT"))
			 && (glCopyConvolutionFilter1DEXT = (PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC)SDL_GL_GetProcAddress("glCopyConvolutionFilter1DEXT"))
			 && (glCopyConvolutionFilter2DEXT = (PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC)SDL_GL_GetProcAddress("glCopyConvolutionFilter2DEXT"))
			 && (glGetConvolutionFilterEXT = (PFNGLGETCONVOLUTIONFILTEREXTPROC)SDL_GL_GetProcAddress("glGetConvolutionFilterEXT"))
			 && (glGetConvolutionParameterfvEXT = (PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC)SDL_GL_GetProcAddress("glGetConvolutionParameterfvEXT"))
			 && (glGetConvolutionParameterivEXT = (PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC)SDL_GL_GetProcAddress("glGetConvolutionParameterivEXT"))
			 && (glGetSeparableFilterEXT = (PFNGLGETSEPARABLEFILTEREXTPROC)SDL_GL_GetProcAddress("glGetSeparableFilterEXT"))
			 && (glSeparableFilter2DEXT = (PFNGLSEPARABLEFILTER2DEXTPROC)SDL_GL_GetProcAddress("glSeparableFilter2DEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_convolution fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_convolution fails." << endl;
			}
		}
	}
	bool have_EXT_convolution() {
		return loaded;
	}
	void GL_EXT_convolution_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_convolution_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_convolution_NAMESPACE

//  ...for GL_EXT_coordinate_frame:
namespace GL_EXT_coordinate_frame_NAMESPACE {
PFNGLBINORMAL3BEXTPROC glBinormal3bEXT = NULL;
PFNGLBINORMAL3BVEXTPROC glBinormal3bvEXT = NULL;
PFNGLBINORMAL3DEXTPROC glBinormal3dEXT = NULL;
PFNGLBINORMAL3DVEXTPROC glBinormal3dvEXT = NULL;
PFNGLBINORMAL3FEXTPROC glBinormal3fEXT = NULL;
PFNGLBINORMAL3FVEXTPROC glBinormal3fvEXT = NULL;
PFNGLBINORMAL3IEXTPROC glBinormal3iEXT = NULL;
PFNGLBINORMAL3IVEXTPROC glBinormal3ivEXT = NULL;
PFNGLBINORMAL3SEXTPROC glBinormal3sEXT = NULL;
PFNGLBINORMAL3SVEXTPROC glBinormal3svEXT = NULL;
PFNGLBINORMALPOINTEREXTPROC glBinormalPointerEXT = NULL;
PFNGLTANGENT3BEXTPROC glTangent3bEXT = NULL;
PFNGLTANGENT3BVEXTPROC glTangent3bvEXT = NULL;
PFNGLTANGENT3DEXTPROC glTangent3dEXT = NULL;
PFNGLTANGENT3DVEXTPROC glTangent3dvEXT = NULL;
PFNGLTANGENT3FEXTPROC glTangent3fEXT = NULL;
PFNGLTANGENT3FVEXTPROC glTangent3fvEXT = NULL;
PFNGLTANGENT3IEXTPROC glTangent3iEXT = NULL;
PFNGLTANGENT3IVEXTPROC glTangent3ivEXT = NULL;
PFNGLTANGENT3SEXTPROC glTangent3sEXT = NULL;
PFNGLTANGENT3SVEXTPROC glTangent3svEXT = NULL;
PFNGLTANGENTPOINTEREXTPROC glTangentPointerEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glBinormal3bEXT = (PFNGLBINORMAL3BEXTPROC)SDL_GL_GetProcAddress("glBinormal3bEXT"))
			 && (glBinormal3bvEXT = (PFNGLBINORMAL3BVEXTPROC)SDL_GL_GetProcAddress("glBinormal3bvEXT"))
			 && (glBinormal3dEXT = (PFNGLBINORMAL3DEXTPROC)SDL_GL_GetProcAddress("glBinormal3dEXT"))
			 && (glBinormal3dvEXT = (PFNGLBINORMAL3DVEXTPROC)SDL_GL_GetProcAddress("glBinormal3dvEXT"))
			 && (glBinormal3fEXT = (PFNGLBINORMAL3FEXTPROC)SDL_GL_GetProcAddress("glBinormal3fEXT"))
			 && (glBinormal3fvEXT = (PFNGLBINORMAL3FVEXTPROC)SDL_GL_GetProcAddress("glBinormal3fvEXT"))
			 && (glBinormal3iEXT = (PFNGLBINORMAL3IEXTPROC)SDL_GL_GetProcAddress("glBinormal3iEXT"))
			 && (glBinormal3ivEXT = (PFNGLBINORMAL3IVEXTPROC)SDL_GL_GetProcAddress("glBinormal3ivEXT"))
			 && (glBinormal3sEXT = (PFNGLBINORMAL3SEXTPROC)SDL_GL_GetProcAddress("glBinormal3sEXT"))
			 && (glBinormal3svEXT = (PFNGLBINORMAL3SVEXTPROC)SDL_GL_GetProcAddress("glBinormal3svEXT"))
			 && (glBinormalPointerEXT = (PFNGLBINORMALPOINTEREXTPROC)SDL_GL_GetProcAddress("glBinormalPointerEXT"))
			 && (glTangent3bEXT = (PFNGLTANGENT3BEXTPROC)SDL_GL_GetProcAddress("glTangent3bEXT"))
			 && (glTangent3bvEXT = (PFNGLTANGENT3BVEXTPROC)SDL_GL_GetProcAddress("glTangent3bvEXT"))
			 && (glTangent3dEXT = (PFNGLTANGENT3DEXTPROC)SDL_GL_GetProcAddress("glTangent3dEXT"))
			 && (glTangent3dvEXT = (PFNGLTANGENT3DVEXTPROC)SDL_GL_GetProcAddress("glTangent3dvEXT"))
			 && (glTangent3fEXT = (PFNGLTANGENT3FEXTPROC)SDL_GL_GetProcAddress("glTangent3fEXT"))
			 && (glTangent3fvEXT = (PFNGLTANGENT3FVEXTPROC)SDL_GL_GetProcAddress("glTangent3fvEXT"))
			 && (glTangent3iEXT = (PFNGLTANGENT3IEXTPROC)SDL_GL_GetProcAddress("glTangent3iEXT"))
			 && (glTangent3ivEXT = (PFNGLTANGENT3IVEXTPROC)SDL_GL_GetProcAddress("glTangent3ivEXT"))
			 && (glTangent3sEXT = (PFNGLTANGENT3SEXTPROC)SDL_GL_GetProcAddress("glTangent3sEXT"))
			 && (glTangent3svEXT = (PFNGLTANGENT3SVEXTPROC)SDL_GL_GetProcAddress("glTangent3svEXT"))
			 && (glTangentPointerEXT = (PFNGLTANGENTPOINTEREXTPROC)SDL_GL_GetProcAddress("glTangentPointerEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_coordinate_frame fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_coordinate_frame fails." << endl;
			}
		}
	}
	bool have_EXT_coordinate_frame() {
		return loaded;
	}
	void GL_EXT_coordinate_frame_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_coordinate_frame_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_coordinate_frame_NAMESPACE

//  ...for GL_EXT_copy_texture:
namespace GL_EXT_copy_texture_NAMESPACE {
PFNGLCOPYTEXIMAGE1DEXTPROC glCopyTexImage1DEXT = NULL;
PFNGLCOPYTEXIMAGE2DEXTPROC glCopyTexImage2DEXT = NULL;
PFNGLCOPYTEXSUBIMAGE1DEXTPROC glCopyTexSubImage1DEXT = NULL;
PFNGLCOPYTEXSUBIMAGE2DEXTPROC glCopyTexSubImage2DEXT = NULL;
PFNGLCOPYTEXSUBIMAGE3DEXTPROC glCopyTexSubImage3DEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glCopyTexImage1DEXT = (PFNGLCOPYTEXIMAGE1DEXTPROC)SDL_GL_GetProcAddress("glCopyTexImage1DEXT"))
			 && (glCopyTexImage2DEXT = (PFNGLCOPYTEXIMAGE2DEXTPROC)SDL_GL_GetProcAddress("glCopyTexImage2DEXT"))
			 && (glCopyTexSubImage1DEXT = (PFNGLCOPYTEXSUBIMAGE1DEXTPROC)SDL_GL_GetProcAddress("glCopyTexSubImage1DEXT"))
			 && (glCopyTexSubImage2DEXT = (PFNGLCOPYTEXSUBIMAGE2DEXTPROC)SDL_GL_GetProcAddress("glCopyTexSubImage2DEXT"))
			 && (glCopyTexSubImage3DEXT = (PFNGLCOPYTEXSUBIMAGE3DEXTPROC)SDL_GL_GetProcAddress("glCopyTexSubImage3DEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_copy_texture fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_copy_texture fails." << endl;
			}
		}
	}
	bool have_EXT_copy_texture() {
		return loaded;
	}
	void GL_EXT_copy_texture_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_copy_texture_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_copy_texture_NAMESPACE

//  ...for GL_EXT_cull_vertex:
namespace GL_EXT_cull_vertex_NAMESPACE {
PFNGLCULLPARAMETERDVEXTPROC glCullParameterdvEXT = NULL;
PFNGLCULLPARAMETERFVEXTPROC glCullParameterfvEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glCullParameterdvEXT = (PFNGLCULLPARAMETERDVEXTPROC)SDL_GL_GetProcAddress("glCullParameterdvEXT"))
			 && (glCullParameterfvEXT = (PFNGLCULLPARAMETERFVEXTPROC)SDL_GL_GetProcAddress("glCullParameterfvEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_cull_vertex fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_cull_vertex fails." << endl;
			}
		}
	}
	bool have_EXT_cull_vertex() {
		return loaded;
	}
	void GL_EXT_cull_vertex_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_cull_vertex_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_cull_vertex_NAMESPACE

//  ...for GL_EXT_depth_bounds_test:
namespace GL_EXT_depth_bounds_test_NAMESPACE {
PFNGLDEPTHBOUNDSEXTPROC glDepthBoundsEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glDepthBoundsEXT = (PFNGLDEPTHBOUNDSEXTPROC)SDL_GL_GetProcAddress("glDepthBoundsEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_depth_bounds_test fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_depth_bounds_test fails." << endl;
			}
		}
	}
	bool have_EXT_depth_bounds_test() {
		return loaded;
	}
	void GL_EXT_depth_bounds_test_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_depth_bounds_test_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_depth_bounds_test_NAMESPACE

//  ...for GL_EXT_draw_range_elements:
namespace GL_EXT_draw_range_elements_NAMESPACE {
PFNGLDRAWRANGEELEMENTSEXTPROC glDrawRangeElementsEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glDrawRangeElementsEXT = (PFNGLDRAWRANGEELEMENTSEXTPROC)SDL_GL_GetProcAddress("glDrawRangeElementsEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_draw_range_elements fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_draw_range_elements fails." << endl;
			}
		}
	}
	bool have_EXT_draw_range_elements() {
		return loaded;
	}
	void GL_EXT_draw_range_elements_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_draw_range_elements_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_draw_range_elements_NAMESPACE

//  ...for GL_EXT_fog_coord:
namespace GL_EXT_fog_coord_NAMESPACE {
PFNGLFOGCOORDDEXTPROC glFogCoorddEXT = NULL;
PFNGLFOGCOORDDVEXTPROC glFogCoorddvEXT = NULL;
PFNGLFOGCOORDFEXTPROC glFogCoordfEXT = NULL;
PFNGLFOGCOORDFVEXTPROC glFogCoordfvEXT = NULL;
PFNGLFOGCOORDPOINTEREXTPROC glFogCoordPointerEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glFogCoorddEXT = (PFNGLFOGCOORDDEXTPROC)SDL_GL_GetProcAddress("glFogCoorddEXT"))
			 && (glFogCoorddvEXT = (PFNGLFOGCOORDDVEXTPROC)SDL_GL_GetProcAddress("glFogCoorddvEXT"))
			 && (glFogCoordfEXT = (PFNGLFOGCOORDFEXTPROC)SDL_GL_GetProcAddress("glFogCoordfEXT"))
			 && (glFogCoordfvEXT = (PFNGLFOGCOORDFVEXTPROC)SDL_GL_GetProcAddress("glFogCoordfvEXT"))
			 && (glFogCoordPointerEXT = (PFNGLFOGCOORDPOINTEREXTPROC)SDL_GL_GetProcAddress("glFogCoordPointerEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_fog_coord fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_fog_coord fails." << endl;
			}
		}
	}
	bool have_EXT_fog_coord() {
		return loaded;
	}
	void GL_EXT_fog_coord_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_fog_coord_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_fog_coord_NAMESPACE

//  ...for GL_EXT_framebuffer_object:
namespace GL_EXT_framebuffer_object_NAMESPACE {
PFNGLBINDFRAMEBUFFEREXTPROC glBindFramebufferEXT = NULL;
PFNGLBINDRENDERBUFFEREXTPROC glBindRenderbufferEXT = NULL;
PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC glCheckFramebufferStatusEXT = NULL;
PFNGLDELETEFRAMEBUFFERSEXTPROC glDeleteFramebuffersEXT = NULL;
PFNGLDELETERENDERBUFFERSEXTPROC glDeleteRenderbuffersEXT = NULL;
PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC glFramebufferRenderbufferEXT = NULL;
PFNGLFRAMEBUFFERTEXTURE1DEXTPROC glFramebufferTexture1DEXT = NULL;
PFNGLFRAMEBUFFERTEXTURE2DEXTPROC glFramebufferTexture2DEXT = NULL;
PFNGLFRAMEBUFFERTEXTURE3DEXTPROC glFramebufferTexture3DEXT = NULL;
PFNGLGENERATEMIPMAPEXTPROC glGenerateMipmapEXT = NULL;
PFNGLGENFRAMEBUFFERSEXTPROC glGenFramebuffersEXT = NULL;
PFNGLGENRENDERBUFFERSEXTPROC glGenRenderbuffersEXT = NULL;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC glGetFramebufferAttachmentParameterivEXT = NULL;
PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC glGetRenderbufferParameterivEXT = NULL;
PFNGLISFRAMEBUFFEREXTPROC glIsFramebufferEXT = NULL;
PFNGLISRENDERBUFFEREXTPROC glIsRenderbufferEXT = NULL;
PFNGLRENDERBUFFERSTORAGEEXTPROC glRenderbufferStorageEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glBindFramebufferEXT = (PFNGLBINDFRAMEBUFFEREXTPROC)SDL_GL_GetProcAddress("glBindFramebufferEXT"))
			 && (glBindRenderbufferEXT = (PFNGLBINDRENDERBUFFEREXTPROC)SDL_GL_GetProcAddress("glBindRenderbufferEXT"))
			 && (glCheckFramebufferStatusEXT = (PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)SDL_GL_GetProcAddress("glCheckFramebufferStatusEXT"))
			 && (glDeleteFramebuffersEXT = (PFNGLDELETEFRAMEBUFFERSEXTPROC)SDL_GL_GetProcAddress("glDeleteFramebuffersEXT"))
			 && (glDeleteRenderbuffersEXT = (PFNGLDELETERENDERBUFFERSEXTPROC)SDL_GL_GetProcAddress("glDeleteRenderbuffersEXT"))
			 && (glFramebufferRenderbufferEXT = (PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)SDL_GL_GetProcAddress("glFramebufferRenderbufferEXT"))
			 && (glFramebufferTexture1DEXT = (PFNGLFRAMEBUFFERTEXTURE1DEXTPROC)SDL_GL_GetProcAddress("glFramebufferTexture1DEXT"))
			 && (glFramebufferTexture2DEXT = (PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)SDL_GL_GetProcAddress("glFramebufferTexture2DEXT"))
			 && (glFramebufferTexture3DEXT = (PFNGLFRAMEBUFFERTEXTURE3DEXTPROC)SDL_GL_GetProcAddress("glFramebufferTexture3DEXT"))
			 && (glGenerateMipmapEXT = (PFNGLGENERATEMIPMAPEXTPROC)SDL_GL_GetProcAddress("glGenerateMipmapEXT"))
			 && (glGenFramebuffersEXT = (PFNGLGENFRAMEBUFFERSEXTPROC)SDL_GL_GetProcAddress("glGenFramebuffersEXT"))
			 && (glGenRenderbuffersEXT = (PFNGLGENRENDERBUFFERSEXTPROC)SDL_GL_GetProcAddress("glGenRenderbuffersEXT"))
			 && (glGetFramebufferAttachmentParameterivEXT = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)SDL_GL_GetProcAddress("glGetFramebufferAttachmentParameterivEXT"))
			 && (glGetRenderbufferParameterivEXT = (PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC)SDL_GL_GetProcAddress("glGetRenderbufferParameterivEXT"))
			 && (glIsFramebufferEXT = (PFNGLISFRAMEBUFFEREXTPROC)SDL_GL_GetProcAddress("glIsFramebufferEXT"))
			 && (glIsRenderbufferEXT = (PFNGLISRENDERBUFFEREXTPROC)SDL_GL_GetProcAddress("glIsRenderbufferEXT"))
			 && (glRenderbufferStorageEXT = (PFNGLRENDERBUFFERSTORAGEEXTPROC)SDL_GL_GetProcAddress("glRenderbufferStorageEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_framebuffer_object fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_framebuffer_object fails." << endl;
			}
		}
	}
	bool have_EXT_framebuffer_object() {
		return loaded;
	}
	void GL_EXT_framebuffer_object_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_framebuffer_object_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_framebuffer_object_NAMESPACE

//  ...for GL_EXT_histogram:
namespace GL_EXT_histogram_NAMESPACE {
PFNGLGETHISTOGRAMEXTPROC glGetHistogramEXT = NULL;
PFNGLGETHISTOGRAMPARAMETERFVEXTPROC glGetHistogramParameterfvEXT = NULL;
PFNGLGETHISTOGRAMPARAMETERIVEXTPROC glGetHistogramParameterivEXT = NULL;
PFNGLGETMINMAXEXTPROC glGetMinmaxEXT = NULL;
PFNGLGETMINMAXPARAMETERFVEXTPROC glGetMinmaxParameterfvEXT = NULL;
PFNGLGETMINMAXPARAMETERIVEXTPROC glGetMinmaxParameterivEXT = NULL;
PFNGLHISTOGRAMEXTPROC glHistogramEXT = NULL;
PFNGLMINMAXEXTPROC glMinmaxEXT = NULL;
PFNGLRESETHISTOGRAMEXTPROC glResetHistogramEXT = NULL;
PFNGLRESETMINMAXEXTPROC glResetMinmaxEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glGetHistogramEXT = (PFNGLGETHISTOGRAMEXTPROC)SDL_GL_GetProcAddress("glGetHistogramEXT"))
			 && (glGetHistogramParameterfvEXT = (PFNGLGETHISTOGRAMPARAMETERFVEXTPROC)SDL_GL_GetProcAddress("glGetHistogramParameterfvEXT"))
			 && (glGetHistogramParameterivEXT = (PFNGLGETHISTOGRAMPARAMETERIVEXTPROC)SDL_GL_GetProcAddress("glGetHistogramParameterivEXT"))
			 && (glGetMinmaxEXT = (PFNGLGETMINMAXEXTPROC)SDL_GL_GetProcAddress("glGetMinmaxEXT"))
			 && (glGetMinmaxParameterfvEXT = (PFNGLGETMINMAXPARAMETERFVEXTPROC)SDL_GL_GetProcAddress("glGetMinmaxParameterfvEXT"))
			 && (glGetMinmaxParameterivEXT = (PFNGLGETMINMAXPARAMETERIVEXTPROC)SDL_GL_GetProcAddress("glGetMinmaxParameterivEXT"))
			 && (glHistogramEXT = (PFNGLHISTOGRAMEXTPROC)SDL_GL_GetProcAddress("glHistogramEXT"))
			 && (glMinmaxEXT = (PFNGLMINMAXEXTPROC)SDL_GL_GetProcAddress("glMinmaxEXT"))
			 && (glResetHistogramEXT = (PFNGLRESETHISTOGRAMEXTPROC)SDL_GL_GetProcAddress("glResetHistogramEXT"))
			 && (glResetMinmaxEXT = (PFNGLRESETMINMAXEXTPROC)SDL_GL_GetProcAddress("glResetMinmaxEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_histogram fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_histogram fails." << endl;
			}
		}
	}
	bool have_EXT_histogram() {
		return loaded;
	}
	void GL_EXT_histogram_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_histogram_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_histogram_NAMESPACE

//  ...for GL_EXT_index_array_formats:
namespace GL_EXT_index_array_formats_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_index_array_formats fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_index_array_formats fails." << endl;
			}
		}
	}
	bool have_EXT_index_array_formats() {
		return loaded;
	}
	void GL_EXT_index_array_formats_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_index_array_formats_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_index_array_formats_NAMESPACE

//  ...for GL_EXT_index_func:
namespace GL_EXT_index_func_NAMESPACE {
PFNGLINDEXFUNCEXTPROC glIndexFuncEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glIndexFuncEXT = (PFNGLINDEXFUNCEXTPROC)SDL_GL_GetProcAddress("glIndexFuncEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_index_func fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_index_func fails." << endl;
			}
		}
	}
	bool have_EXT_index_func() {
		return loaded;
	}
	void GL_EXT_index_func_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_index_func_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_index_func_NAMESPACE

//  ...for GL_EXT_index_material:
namespace GL_EXT_index_material_NAMESPACE {
PFNGLINDEXMATERIALEXTPROC glIndexMaterialEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glIndexMaterialEXT = (PFNGLINDEXMATERIALEXTPROC)SDL_GL_GetProcAddress("glIndexMaterialEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_index_material fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_index_material fails." << endl;
			}
		}
	}
	bool have_EXT_index_material() {
		return loaded;
	}
	void GL_EXT_index_material_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_index_material_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_index_material_NAMESPACE

//  ...for GL_EXT_index_texture:
namespace GL_EXT_index_texture_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_index_texture fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_index_texture fails." << endl;
			}
		}
	}
	bool have_EXT_index_texture() {
		return loaded;
	}
	void GL_EXT_index_texture_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_index_texture_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_index_texture_NAMESPACE

//  ...for GL_EXT_light_texture:
namespace GL_EXT_light_texture_NAMESPACE {
PFNGLAPPLYTEXTUREEXTPROC glApplyTextureEXT = NULL;
PFNGLTEXTURELIGHTEXTPROC glTextureLightEXT = NULL;
PFNGLTEXTUREMATERIALEXTPROC glTextureMaterialEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glApplyTextureEXT = (PFNGLAPPLYTEXTUREEXTPROC)SDL_GL_GetProcAddress("glApplyTextureEXT"))
			 && (glTextureLightEXT = (PFNGLTEXTURELIGHTEXTPROC)SDL_GL_GetProcAddress("glTextureLightEXT"))
			 && (glTextureMaterialEXT = (PFNGLTEXTUREMATERIALEXTPROC)SDL_GL_GetProcAddress("glTextureMaterialEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_light_texture fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_light_texture fails." << endl;
			}
		}
	}
	bool have_EXT_light_texture() {
		return loaded;
	}
	void GL_EXT_light_texture_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_light_texture_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_light_texture_NAMESPACE

//  ...for GL_EXT_misc_attribute:
namespace GL_EXT_misc_attribute_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_misc_attribute fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_misc_attribute fails." << endl;
			}
		}
	}
	bool have_EXT_misc_attribute() {
		return loaded;
	}
	void GL_EXT_misc_attribute_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_misc_attribute_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_misc_attribute_NAMESPACE

//  ...for GL_EXT_multi_draw_arrays:
namespace GL_EXT_multi_draw_arrays_NAMESPACE {
PFNGLMULTIDRAWARRAYSEXTPROC glMultiDrawArraysEXT = NULL;
PFNGLMULTIDRAWELEMENTSEXTPROC glMultiDrawElementsEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glMultiDrawArraysEXT = (PFNGLMULTIDRAWARRAYSEXTPROC)SDL_GL_GetProcAddress("glMultiDrawArraysEXT"))
			 && (glMultiDrawElementsEXT = (PFNGLMULTIDRAWELEMENTSEXTPROC)SDL_GL_GetProcAddress("glMultiDrawElementsEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_multi_draw_arrays fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_multi_draw_arrays fails." << endl;
			}
		}
	}
	bool have_EXT_multi_draw_arrays() {
		return loaded;
	}
	void GL_EXT_multi_draw_arrays_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_multi_draw_arrays_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_multi_draw_arrays_NAMESPACE

//  ...for GL_EXT_multisample:
namespace GL_EXT_multisample_NAMESPACE {
PFNGLSAMPLEMASKEXTPROC glSampleMaskEXT = NULL;
PFNGLSAMPLEPATTERNEXTPROC glSamplePatternEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glSampleMaskEXT = (PFNGLSAMPLEMASKEXTPROC)SDL_GL_GetProcAddress("glSampleMaskEXT"))
			 && (glSamplePatternEXT = (PFNGLSAMPLEPATTERNEXTPROC)SDL_GL_GetProcAddress("glSamplePatternEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_multisample fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_multisample fails." << endl;
			}
		}
	}
	bool have_EXT_multisample() {
		return loaded;
	}
	void GL_EXT_multisample_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_multisample_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_multisample_NAMESPACE

//  ...for GL_EXT_packed_pixels:
namespace GL_EXT_packed_pixels_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_packed_pixels fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_packed_pixels fails." << endl;
			}
		}
	}
	bool have_EXT_packed_pixels() {
		return loaded;
	}
	void GL_EXT_packed_pixels_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_packed_pixels_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_packed_pixels_NAMESPACE

//  ...for GL_EXT_paletted_texture:
namespace GL_EXT_paletted_texture_NAMESPACE {
PFNGLCOLORTABLEEXTPROC glColorTableEXT = NULL;
PFNGLGETCOLORTABLEEXTPROC glGetColorTableEXT = NULL;
PFNGLGETCOLORTABLEPARAMETERFVEXTPROC glGetColorTableParameterfvEXT = NULL;
PFNGLGETCOLORTABLEPARAMETERIVEXTPROC glGetColorTableParameterivEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glColorTableEXT = (PFNGLCOLORTABLEEXTPROC)SDL_GL_GetProcAddress("glColorTableEXT"))
			 && (glGetColorTableEXT = (PFNGLGETCOLORTABLEEXTPROC)SDL_GL_GetProcAddress("glGetColorTableEXT"))
			 && (glGetColorTableParameterfvEXT = (PFNGLGETCOLORTABLEPARAMETERFVEXTPROC)SDL_GL_GetProcAddress("glGetColorTableParameterfvEXT"))
			 && (glGetColorTableParameterivEXT = (PFNGLGETCOLORTABLEPARAMETERIVEXTPROC)SDL_GL_GetProcAddress("glGetColorTableParameterivEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_paletted_texture fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_paletted_texture fails." << endl;
			}
		}
	}
	bool have_EXT_paletted_texture() {
		return loaded;
	}
	void GL_EXT_paletted_texture_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_paletted_texture_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_paletted_texture_NAMESPACE

//  ...for GL_EXT_pixel_buffer_object:
namespace GL_EXT_pixel_buffer_object_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_pixel_buffer_object fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_pixel_buffer_object fails." << endl;
			}
		}
	}
	bool have_EXT_pixel_buffer_object() {
		return loaded;
	}
	void GL_EXT_pixel_buffer_object_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_pixel_buffer_object_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_pixel_buffer_object_NAMESPACE

//  ...for GL_EXT_pixel_transform:
namespace GL_EXT_pixel_transform_NAMESPACE {
PFNGLPIXELTRANSFORMPARAMETERFEXTPROC glPixelTransformParameterfEXT = NULL;
PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC glPixelTransformParameterfvEXT = NULL;
PFNGLPIXELTRANSFORMPARAMETERIEXTPROC glPixelTransformParameteriEXT = NULL;
PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC glPixelTransformParameterivEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glPixelTransformParameterfEXT = (PFNGLPIXELTRANSFORMPARAMETERFEXTPROC)SDL_GL_GetProcAddress("glPixelTransformParameterfEXT"))
			 && (glPixelTransformParameterfvEXT = (PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC)SDL_GL_GetProcAddress("glPixelTransformParameterfvEXT"))
			 && (glPixelTransformParameteriEXT = (PFNGLPIXELTRANSFORMPARAMETERIEXTPROC)SDL_GL_GetProcAddress("glPixelTransformParameteriEXT"))
			 && (glPixelTransformParameterivEXT = (PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC)SDL_GL_GetProcAddress("glPixelTransformParameterivEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_pixel_transform fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_pixel_transform fails." << endl;
			}
		}
	}
	bool have_EXT_pixel_transform() {
		return loaded;
	}
	void GL_EXT_pixel_transform_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_pixel_transform_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_pixel_transform_NAMESPACE

//  ...for GL_EXT_pixel_transform_color_table:
namespace GL_EXT_pixel_transform_color_table_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_pixel_transform_color_table fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_pixel_transform_color_table fails." << endl;
			}
		}
	}
	bool have_EXT_pixel_transform_color_table() {
		return loaded;
	}
	void GL_EXT_pixel_transform_color_table_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_pixel_transform_color_table_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_pixel_transform_color_table_NAMESPACE

//  ...for GL_EXT_point_parameters:
namespace GL_EXT_point_parameters_NAMESPACE {
PFNGLPOINTPARAMETERFEXTPROC glPointParameterfEXT = NULL;
PFNGLPOINTPARAMETERFVEXTPROC glPointParameterfvEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glPointParameterfEXT = (PFNGLPOINTPARAMETERFEXTPROC)SDL_GL_GetProcAddress("glPointParameterfEXT"))
			 && (glPointParameterfvEXT = (PFNGLPOINTPARAMETERFVEXTPROC)SDL_GL_GetProcAddress("glPointParameterfvEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_point_parameters fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_point_parameters fails." << endl;
			}
		}
	}
	bool have_EXT_point_parameters() {
		return loaded;
	}
	void GL_EXT_point_parameters_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_point_parameters_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_point_parameters_NAMESPACE

//  ...for GL_EXT_polygon_offset:
namespace GL_EXT_polygon_offset_NAMESPACE {
PFNGLPOLYGONOFFSETEXTPROC glPolygonOffsetEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glPolygonOffsetEXT = (PFNGLPOLYGONOFFSETEXTPROC)SDL_GL_GetProcAddress("glPolygonOffsetEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_polygon_offset fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_polygon_offset fails." << endl;
			}
		}
	}
	bool have_EXT_polygon_offset() {
		return loaded;
	}
	void GL_EXT_polygon_offset_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_polygon_offset_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_polygon_offset_NAMESPACE

//  ...for GL_EXT_rescale_normal:
namespace GL_EXT_rescale_normal_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_rescale_normal fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_rescale_normal fails." << endl;
			}
		}
	}
	bool have_EXT_rescale_normal() {
		return loaded;
	}
	void GL_EXT_rescale_normal_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_rescale_normal_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_rescale_normal_NAMESPACE

//  ...for GL_EXT_secondary_color:
namespace GL_EXT_secondary_color_NAMESPACE {
PFNGLSECONDARYCOLOR3BEXTPROC glSecondaryColor3bEXT = NULL;
PFNGLSECONDARYCOLOR3BVEXTPROC glSecondaryColor3bvEXT = NULL;
PFNGLSECONDARYCOLOR3DEXTPROC glSecondaryColor3dEXT = NULL;
PFNGLSECONDARYCOLOR3DVEXTPROC glSecondaryColor3dvEXT = NULL;
PFNGLSECONDARYCOLOR3FEXTPROC glSecondaryColor3fEXT = NULL;
PFNGLSECONDARYCOLOR3FVEXTPROC glSecondaryColor3fvEXT = NULL;
PFNGLSECONDARYCOLOR3IEXTPROC glSecondaryColor3iEXT = NULL;
PFNGLSECONDARYCOLOR3IVEXTPROC glSecondaryColor3ivEXT = NULL;
PFNGLSECONDARYCOLOR3SEXTPROC glSecondaryColor3sEXT = NULL;
PFNGLSECONDARYCOLOR3SVEXTPROC glSecondaryColor3svEXT = NULL;
PFNGLSECONDARYCOLOR3UBEXTPROC glSecondaryColor3ubEXT = NULL;
PFNGLSECONDARYCOLOR3UBVEXTPROC glSecondaryColor3ubvEXT = NULL;
PFNGLSECONDARYCOLOR3UIEXTPROC glSecondaryColor3uiEXT = NULL;
PFNGLSECONDARYCOLOR3UIVEXTPROC glSecondaryColor3uivEXT = NULL;
PFNGLSECONDARYCOLOR3USEXTPROC glSecondaryColor3usEXT = NULL;
PFNGLSECONDARYCOLOR3USVEXTPROC glSecondaryColor3usvEXT = NULL;
PFNGLSECONDARYCOLORPOINTEREXTPROC glSecondaryColorPointerEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glSecondaryColor3bEXT = (PFNGLSECONDARYCOLOR3BEXTPROC)SDL_GL_GetProcAddress("glSecondaryColor3bEXT"))
			 && (glSecondaryColor3bvEXT = (PFNGLSECONDARYCOLOR3BVEXTPROC)SDL_GL_GetProcAddress("glSecondaryColor3bvEXT"))
			 && (glSecondaryColor3dEXT = (PFNGLSECONDARYCOLOR3DEXTPROC)SDL_GL_GetProcAddress("glSecondaryColor3dEXT"))
			 && (glSecondaryColor3dvEXT = (PFNGLSECONDARYCOLOR3DVEXTPROC)SDL_GL_GetProcAddress("glSecondaryColor3dvEXT"))
			 && (glSecondaryColor3fEXT = (PFNGLSECONDARYCOLOR3FEXTPROC)SDL_GL_GetProcAddress("glSecondaryColor3fEXT"))
			 && (glSecondaryColor3fvEXT = (PFNGLSECONDARYCOLOR3FVEXTPROC)SDL_GL_GetProcAddress("glSecondaryColor3fvEXT"))
			 && (glSecondaryColor3iEXT = (PFNGLSECONDARYCOLOR3IEXTPROC)SDL_GL_GetProcAddress("glSecondaryColor3iEXT"))
			 && (glSecondaryColor3ivEXT = (PFNGLSECONDARYCOLOR3IVEXTPROC)SDL_GL_GetProcAddress("glSecondaryColor3ivEXT"))
			 && (glSecondaryColor3sEXT = (PFNGLSECONDARYCOLOR3SEXTPROC)SDL_GL_GetProcAddress("glSecondaryColor3sEXT"))
			 && (glSecondaryColor3svEXT = (PFNGLSECONDARYCOLOR3SVEXTPROC)SDL_GL_GetProcAddress("glSecondaryColor3svEXT"))
			 && (glSecondaryColor3ubEXT = (PFNGLSECONDARYCOLOR3UBEXTPROC)SDL_GL_GetProcAddress("glSecondaryColor3ubEXT"))
			 && (glSecondaryColor3ubvEXT = (PFNGLSECONDARYCOLOR3UBVEXTPROC)SDL_GL_GetProcAddress("glSecondaryColor3ubvEXT"))
			 && (glSecondaryColor3uiEXT = (PFNGLSECONDARYCOLOR3UIEXTPROC)SDL_GL_GetProcAddress("glSecondaryColor3uiEXT"))
			 && (glSecondaryColor3uivEXT = (PFNGLSECONDARYCOLOR3UIVEXTPROC)SDL_GL_GetProcAddress("glSecondaryColor3uivEXT"))
			 && (glSecondaryColor3usEXT = (PFNGLSECONDARYCOLOR3USEXTPROC)SDL_GL_GetProcAddress("glSecondaryColor3usEXT"))
			 && (glSecondaryColor3usvEXT = (PFNGLSECONDARYCOLOR3USVEXTPROC)SDL_GL_GetProcAddress("glSecondaryColor3usvEXT"))
			 && (glSecondaryColorPointerEXT = (PFNGLSECONDARYCOLORPOINTEREXTPROC)SDL_GL_GetProcAddress("glSecondaryColorPointerEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_secondary_color fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_secondary_color fails." << endl;
			}
		}
	}
	bool have_EXT_secondary_color() {
		return loaded;
	}
	void GL_EXT_secondary_color_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_secondary_color_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_secondary_color_NAMESPACE

//  ...for GL_EXT_separate_specular_color:
namespace GL_EXT_separate_specular_color_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_separate_specular_color fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_separate_specular_color fails." << endl;
			}
		}
	}
	bool have_EXT_separate_specular_color() {
		return loaded;
	}
	void GL_EXT_separate_specular_color_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_separate_specular_color_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_separate_specular_color_NAMESPACE

//  ...for GL_EXT_shadow_funcs:
namespace GL_EXT_shadow_funcs_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_shadow_funcs fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_shadow_funcs fails." << endl;
			}
		}
	}
	bool have_EXT_shadow_funcs() {
		return loaded;
	}
	void GL_EXT_shadow_funcs_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_shadow_funcs_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_shadow_funcs_NAMESPACE

//  ...for GL_EXT_shared_texture_palette:
namespace GL_EXT_shared_texture_palette_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_shared_texture_palette fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_shared_texture_palette fails." << endl;
			}
		}
	}
	bool have_EXT_shared_texture_palette() {
		return loaded;
	}
	void GL_EXT_shared_texture_palette_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_shared_texture_palette_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_shared_texture_palette_NAMESPACE

//  ...for GL_EXT_stencil_two_side:
namespace GL_EXT_stencil_two_side_NAMESPACE {
PFNGLACTIVESTENCILFACEEXTPROC glActiveStencilFaceEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glActiveStencilFaceEXT = (PFNGLACTIVESTENCILFACEEXTPROC)SDL_GL_GetProcAddress("glActiveStencilFaceEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_stencil_two_side fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_stencil_two_side fails." << endl;
			}
		}
	}
	bool have_EXT_stencil_two_side() {
		return loaded;
	}
	void GL_EXT_stencil_two_side_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_stencil_two_side_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_stencil_two_side_NAMESPACE

//  ...for GL_EXT_stencil_wrap:
namespace GL_EXT_stencil_wrap_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_stencil_wrap fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_stencil_wrap fails." << endl;
			}
		}
	}
	bool have_EXT_stencil_wrap() {
		return loaded;
	}
	void GL_EXT_stencil_wrap_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_stencil_wrap_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_stencil_wrap_NAMESPACE

//  ...for GL_EXT_subtexture:
namespace GL_EXT_subtexture_NAMESPACE {
PFNGLTEXSUBIMAGE1DEXTPROC glTexSubImage1DEXT = NULL;
PFNGLTEXSUBIMAGE2DEXTPROC glTexSubImage2DEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glTexSubImage1DEXT = (PFNGLTEXSUBIMAGE1DEXTPROC)SDL_GL_GetProcAddress("glTexSubImage1DEXT"))
			 && (glTexSubImage2DEXT = (PFNGLTEXSUBIMAGE2DEXTPROC)SDL_GL_GetProcAddress("glTexSubImage2DEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_subtexture fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_subtexture fails." << endl;
			}
		}
	}
	bool have_EXT_subtexture() {
		return loaded;
	}
	void GL_EXT_subtexture_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_subtexture_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_subtexture_NAMESPACE

//  ...for GL_EXT_texture:
namespace GL_EXT_texture_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_texture fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_texture fails." << endl;
			}
		}
	}
	bool have_EXT_texture() {
		return loaded;
	}
	void GL_EXT_texture_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_texture_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_texture_NAMESPACE

//  ...for GL_EXT_texture3:
namespace GL_EXT_texture3_NAMESPACE {
PFNGLTEXIMAGE3DEXTPROC glTexImage3DEXT = NULL;
PFNGLTEXSUBIMAGE3DEXTPROC glTexSubImage3DEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glTexImage3DEXT = (PFNGLTEXIMAGE3DEXTPROC)SDL_GL_GetProcAddress("glTexImage3DEXT"))
			 && (glTexSubImage3DEXT = (PFNGLTEXSUBIMAGE3DEXTPROC)SDL_GL_GetProcAddress("glTexSubImage3DEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_texture3 fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_texture3 fails." << endl;
			}
		}
	}
	bool have_EXT_texture3() {
		return loaded;
	}
	void GL_EXT_texture3_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_texture3_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_texture3_NAMESPACE

//  ...for GL_EXT_texture_compression_s3tc:
namespace GL_EXT_texture_compression_s3tc_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_texture_compression_s3tc fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_texture_compression_s3tc fails." << endl;
			}
		}
	}
	bool have_EXT_texture_compression_s3tc() {
		return loaded;
	}
	void GL_EXT_texture_compression_s3tc_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_texture_compression_s3tc_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_texture_compression_s3tc_NAMESPACE

//  ...for GL_EXT_texture_cube_map:
namespace GL_EXT_texture_cube_map_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_texture_cube_map fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_texture_cube_map fails." << endl;
			}
		}
	}
	bool have_EXT_texture_cube_map() {
		return loaded;
	}
	void GL_EXT_texture_cube_map_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_texture_cube_map_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_texture_cube_map_NAMESPACE

//  ...for GL_EXT_texture_env_add:
namespace GL_EXT_texture_env_add_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_texture_env_add fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_texture_env_add fails." << endl;
			}
		}
	}
	bool have_EXT_texture_env_add() {
		return loaded;
	}
	void GL_EXT_texture_env_add_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_texture_env_add_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_texture_env_add_NAMESPACE

//  ...for GL_EXT_texture_env_combine:
namespace GL_EXT_texture_env_combine_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_texture_env_combine fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_texture_env_combine fails." << endl;
			}
		}
	}
	bool have_EXT_texture_env_combine() {
		return loaded;
	}
	void GL_EXT_texture_env_combine_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_texture_env_combine_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_texture_env_combine_NAMESPACE

//  ...for GL_EXT_texture_env_dot3:
namespace GL_EXT_texture_env_dot3_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_texture_env_dot3 fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_texture_env_dot3 fails." << endl;
			}
		}
	}
	bool have_EXT_texture_env_dot3() {
		return loaded;
	}
	void GL_EXT_texture_env_dot3_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_texture_env_dot3_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_texture_env_dot3_NAMESPACE

//  ...for GL_EXT_texture_filter_anisotropic:
namespace GL_EXT_texture_filter_anisotropic_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_texture_filter_anisotropic fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_texture_filter_anisotropic fails." << endl;
			}
		}
	}
	bool have_EXT_texture_filter_anisotropic() {
		return loaded;
	}
	void GL_EXT_texture_filter_anisotropic_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_texture_filter_anisotropic_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_texture_filter_anisotropic_NAMESPACE

//  ...for GL_EXT_texture_lod_bias:
namespace GL_EXT_texture_lod_bias_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_texture_lod_bias fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_texture_lod_bias fails." << endl;
			}
		}
	}
	bool have_EXT_texture_lod_bias() {
		return loaded;
	}
	void GL_EXT_texture_lod_bias_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_texture_lod_bias_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_texture_lod_bias_NAMESPACE

//  ...for GL_EXT_texture_mirror_clamp:
namespace GL_EXT_texture_mirror_clamp_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_texture_mirror_clamp fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_texture_mirror_clamp fails." << endl;
			}
		}
	}
	bool have_EXT_texture_mirror_clamp() {
		return loaded;
	}
	void GL_EXT_texture_mirror_clamp_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_texture_mirror_clamp_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_texture_mirror_clamp_NAMESPACE

//  ...for GL_EXT_texture_object:
namespace GL_EXT_texture_object_NAMESPACE {
PFNGLARETEXTURESRESIDENTEXTPROC glAreTexturesResidentEXT = NULL;
PFNGLBINDTEXTUREEXTPROC glBindTextureEXT = NULL;
PFNGLDELETETEXTURESEXTPROC glDeleteTexturesEXT = NULL;
PFNGLGENTEXTURESEXTPROC glGenTexturesEXT = NULL;
PFNGLISTEXTUREEXTPROC glIsTextureEXT = NULL;
PFNGLPRIORITIZETEXTURESEXTPROC glPrioritizeTexturesEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glAreTexturesResidentEXT = (PFNGLARETEXTURESRESIDENTEXTPROC)SDL_GL_GetProcAddress("glAreTexturesResidentEXT"))
			 && (glBindTextureEXT = (PFNGLBINDTEXTUREEXTPROC)SDL_GL_GetProcAddress("glBindTextureEXT"))
			 && (glDeleteTexturesEXT = (PFNGLDELETETEXTURESEXTPROC)SDL_GL_GetProcAddress("glDeleteTexturesEXT"))
			 && (glGenTexturesEXT = (PFNGLGENTEXTURESEXTPROC)SDL_GL_GetProcAddress("glGenTexturesEXT"))
			 && (glIsTextureEXT = (PFNGLISTEXTUREEXTPROC)SDL_GL_GetProcAddress("glIsTextureEXT"))
			 && (glPrioritizeTexturesEXT = (PFNGLPRIORITIZETEXTURESEXTPROC)SDL_GL_GetProcAddress("glPrioritizeTexturesEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_texture_object fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_texture_object fails." << endl;
			}
		}
	}
	bool have_EXT_texture_object() {
		return loaded;
	}
	void GL_EXT_texture_object_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_texture_object_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_texture_object_NAMESPACE

//  ...for GL_EXT_texture_perturb_normal:
namespace GL_EXT_texture_perturb_normal_NAMESPACE {
PFNGLTEXTURENORMALEXTPROC glTextureNormalEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glTextureNormalEXT = (PFNGLTEXTURENORMALEXTPROC)SDL_GL_GetProcAddress("glTextureNormalEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_texture_perturb_normal fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_texture_perturb_normal fails." << endl;
			}
		}
	}
	bool have_EXT_texture_perturb_normal() {
		return loaded;
	}
	void GL_EXT_texture_perturb_normal_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_texture_perturb_normal_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_texture_perturb_normal_NAMESPACE

//  ...for GL_EXT_vertex_array:
namespace GL_EXT_vertex_array_NAMESPACE {
PFNGLARRAYELEMENTEXTPROC glArrayElementEXT = NULL;
PFNGLCOLORPOINTEREXTPROC glColorPointerEXT = NULL;
PFNGLDRAWARRAYSEXTPROC glDrawArraysEXT = NULL;
PFNGLEDGEFLAGPOINTEREXTPROC glEdgeFlagPointerEXT = NULL;
PFNGLGETPOINTERVEXTPROC glGetPointervEXT = NULL;
PFNGLINDEXPOINTEREXTPROC glIndexPointerEXT = NULL;
PFNGLNORMALPOINTEREXTPROC glNormalPointerEXT = NULL;
PFNGLTEXCOORDPOINTEREXTPROC glTexCoordPointerEXT = NULL;
PFNGLVERTEXPOINTEREXTPROC glVertexPointerEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glArrayElementEXT = (PFNGLARRAYELEMENTEXTPROC)SDL_GL_GetProcAddress("glArrayElementEXT"))
			 && (glColorPointerEXT = (PFNGLCOLORPOINTEREXTPROC)SDL_GL_GetProcAddress("glColorPointerEXT"))
			 && (glDrawArraysEXT = (PFNGLDRAWARRAYSEXTPROC)SDL_GL_GetProcAddress("glDrawArraysEXT"))
			 && (glEdgeFlagPointerEXT = (PFNGLEDGEFLAGPOINTEREXTPROC)SDL_GL_GetProcAddress("glEdgeFlagPointerEXT"))
			 && (glGetPointervEXT = (PFNGLGETPOINTERVEXTPROC)SDL_GL_GetProcAddress("glGetPointervEXT"))
			 && (glIndexPointerEXT = (PFNGLINDEXPOINTEREXTPROC)SDL_GL_GetProcAddress("glIndexPointerEXT"))
			 && (glNormalPointerEXT = (PFNGLNORMALPOINTEREXTPROC)SDL_GL_GetProcAddress("glNormalPointerEXT"))
			 && (glTexCoordPointerEXT = (PFNGLTEXCOORDPOINTEREXTPROC)SDL_GL_GetProcAddress("glTexCoordPointerEXT"))
			 && (glVertexPointerEXT = (PFNGLVERTEXPOINTEREXTPROC)SDL_GL_GetProcAddress("glVertexPointerEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_vertex_array fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_vertex_array fails." << endl;
			}
		}
	}
	bool have_EXT_vertex_array() {
		return loaded;
	}
	void GL_EXT_vertex_array_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_vertex_array_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_vertex_array_NAMESPACE

//  ...for GL_EXT_vertex_shader:
namespace GL_EXT_vertex_shader_NAMESPACE {
PFNGLBEGINVERTEXSHADEREXTPROC glBeginVertexShaderEXT = NULL;
PFNGLBINDLIGHTPARAMETEREXTPROC glBindLightParameterEXT = NULL;
PFNGLBINDMATERIALPARAMETEREXTPROC glBindMaterialParameterEXT = NULL;
PFNGLBINDPARAMETEREXTPROC glBindParameterEXT = NULL;
PFNGLBINDTEXGENPARAMETEREXTPROC glBindTexGenParameterEXT = NULL;
PFNGLBINDTEXTUREUNITPARAMETEREXTPROC glBindTextureUnitParameterEXT = NULL;
PFNGLBINDVERTEXSHADEREXTPROC glBindVertexShaderEXT = NULL;
PFNGLDELETEVERTEXSHADEREXTPROC glDeleteVertexShaderEXT = NULL;
PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC glDisableVariantClientStateEXT = NULL;
PFNGLENABLEVARIANTCLIENTSTATEEXTPROC glEnableVariantClientStateEXT = NULL;
PFNGLENDVERTEXSHADEREXTPROC glEndVertexShaderEXT = NULL;
PFNGLEXTRACTCOMPONENTEXTPROC glExtractComponentEXT = NULL;
PFNGLGENSYMBOLSEXTPROC glGenSymbolsEXT = NULL;
PFNGLGENVERTEXSHADERSEXTPROC glGenVertexShadersEXT = NULL;
PFNGLGETINVARIANTBOOLEANVEXTPROC glGetInvariantBooleanvEXT = NULL;
PFNGLGETINVARIANTFLOATVEXTPROC glGetInvariantFloatvEXT = NULL;
PFNGLGETINVARIANTINTEGERVEXTPROC glGetInvariantIntegervEXT = NULL;
PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC glGetLocalConstantBooleanvEXT = NULL;
PFNGLGETLOCALCONSTANTFLOATVEXTPROC glGetLocalConstantFloatvEXT = NULL;
PFNGLGETLOCALCONSTANTINTEGERVEXTPROC glGetLocalConstantIntegervEXT = NULL;
PFNGLGETVARIANTBOOLEANVEXTPROC glGetVariantBooleanvEXT = NULL;
PFNGLGETVARIANTFLOATVEXTPROC glGetVariantFloatvEXT = NULL;
PFNGLGETVARIANTINTEGERVEXTPROC glGetVariantIntegervEXT = NULL;
PFNGLGETVARIANTPOINTERVEXTPROC glGetVariantPointervEXT = NULL;
PFNGLINSERTCOMPONENTEXTPROC glInsertComponentEXT = NULL;
PFNGLISVARIANTENABLEDEXTPROC glIsVariantEnabledEXT = NULL;
PFNGLSETINVARIANTEXTPROC glSetInvariantEXT = NULL;
PFNGLSETLOCALCONSTANTEXTPROC glSetLocalConstantEXT = NULL;
PFNGLSHADEROP1EXTPROC glShaderOp1EXT = NULL;
PFNGLSHADEROP2EXTPROC glShaderOp2EXT = NULL;
PFNGLSHADEROP3EXTPROC glShaderOp3EXT = NULL;
PFNGLSWIZZLEEXTPROC glSwizzleEXT = NULL;
PFNGLVARIANTBVEXTPROC glVariantbvEXT = NULL;
PFNGLVARIANTDVEXTPROC glVariantdvEXT = NULL;
PFNGLVARIANTFVEXTPROC glVariantfvEXT = NULL;
PFNGLVARIANTIVEXTPROC glVariantivEXT = NULL;
PFNGLVARIANTPOINTEREXTPROC glVariantPointerEXT = NULL;
PFNGLVARIANTSVEXTPROC glVariantsvEXT = NULL;
PFNGLVARIANTUBVEXTPROC glVariantubvEXT = NULL;
PFNGLVARIANTUIVEXTPROC glVariantuivEXT = NULL;
PFNGLVARIANTUSVEXTPROC glVariantusvEXT = NULL;
PFNGLWRITEMASKEXTPROC glWriteMaskEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glBeginVertexShaderEXT = (PFNGLBEGINVERTEXSHADEREXTPROC)SDL_GL_GetProcAddress("glBeginVertexShaderEXT"))
			 && (glBindLightParameterEXT = (PFNGLBINDLIGHTPARAMETEREXTPROC)SDL_GL_GetProcAddress("glBindLightParameterEXT"))
			 && (glBindMaterialParameterEXT = (PFNGLBINDMATERIALPARAMETEREXTPROC)SDL_GL_GetProcAddress("glBindMaterialParameterEXT"))
			 && (glBindParameterEXT = (PFNGLBINDPARAMETEREXTPROC)SDL_GL_GetProcAddress("glBindParameterEXT"))
			 && (glBindTexGenParameterEXT = (PFNGLBINDTEXGENPARAMETEREXTPROC)SDL_GL_GetProcAddress("glBindTexGenParameterEXT"))
			 && (glBindTextureUnitParameterEXT = (PFNGLBINDTEXTUREUNITPARAMETEREXTPROC)SDL_GL_GetProcAddress("glBindTextureUnitParameterEXT"))
			 && (glBindVertexShaderEXT = (PFNGLBINDVERTEXSHADEREXTPROC)SDL_GL_GetProcAddress("glBindVertexShaderEXT"))
			 && (glDeleteVertexShaderEXT = (PFNGLDELETEVERTEXSHADEREXTPROC)SDL_GL_GetProcAddress("glDeleteVertexShaderEXT"))
			 && (glDisableVariantClientStateEXT = (PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC)SDL_GL_GetProcAddress("glDisableVariantClientStateEXT"))
			 && (glEnableVariantClientStateEXT = (PFNGLENABLEVARIANTCLIENTSTATEEXTPROC)SDL_GL_GetProcAddress("glEnableVariantClientStateEXT"))
			 && (glEndVertexShaderEXT = (PFNGLENDVERTEXSHADEREXTPROC)SDL_GL_GetProcAddress("glEndVertexShaderEXT"))
			 && (glExtractComponentEXT = (PFNGLEXTRACTCOMPONENTEXTPROC)SDL_GL_GetProcAddress("glExtractComponentEXT"))
			 && (glGenSymbolsEXT = (PFNGLGENSYMBOLSEXTPROC)SDL_GL_GetProcAddress("glGenSymbolsEXT"))
			 && (glGenVertexShadersEXT = (PFNGLGENVERTEXSHADERSEXTPROC)SDL_GL_GetProcAddress("glGenVertexShadersEXT"))
			 && (glGetInvariantBooleanvEXT = (PFNGLGETINVARIANTBOOLEANVEXTPROC)SDL_GL_GetProcAddress("glGetInvariantBooleanvEXT"))
			 && (glGetInvariantFloatvEXT = (PFNGLGETINVARIANTFLOATVEXTPROC)SDL_GL_GetProcAddress("glGetInvariantFloatvEXT"))
			 && (glGetInvariantIntegervEXT = (PFNGLGETINVARIANTINTEGERVEXTPROC)SDL_GL_GetProcAddress("glGetInvariantIntegervEXT"))
			 && (glGetLocalConstantBooleanvEXT = (PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC)SDL_GL_GetProcAddress("glGetLocalConstantBooleanvEXT"))
			 && (glGetLocalConstantFloatvEXT = (PFNGLGETLOCALCONSTANTFLOATVEXTPROC)SDL_GL_GetProcAddress("glGetLocalConstantFloatvEXT"))
			 && (glGetLocalConstantIntegervEXT = (PFNGLGETLOCALCONSTANTINTEGERVEXTPROC)SDL_GL_GetProcAddress("glGetLocalConstantIntegervEXT"))
			 && (glGetVariantBooleanvEXT = (PFNGLGETVARIANTBOOLEANVEXTPROC)SDL_GL_GetProcAddress("glGetVariantBooleanvEXT"))
			 && (glGetVariantFloatvEXT = (PFNGLGETVARIANTFLOATVEXTPROC)SDL_GL_GetProcAddress("glGetVariantFloatvEXT"))
			 && (glGetVariantIntegervEXT = (PFNGLGETVARIANTINTEGERVEXTPROC)SDL_GL_GetProcAddress("glGetVariantIntegervEXT"))
			 && (glGetVariantPointervEXT = (PFNGLGETVARIANTPOINTERVEXTPROC)SDL_GL_GetProcAddress("glGetVariantPointervEXT"))
			 && (glInsertComponentEXT = (PFNGLINSERTCOMPONENTEXTPROC)SDL_GL_GetProcAddress("glInsertComponentEXT"))
			 && (glIsVariantEnabledEXT = (PFNGLISVARIANTENABLEDEXTPROC)SDL_GL_GetProcAddress("glIsVariantEnabledEXT"))
			 && (glSetInvariantEXT = (PFNGLSETINVARIANTEXTPROC)SDL_GL_GetProcAddress("glSetInvariantEXT"))
			 && (glSetLocalConstantEXT = (PFNGLSETLOCALCONSTANTEXTPROC)SDL_GL_GetProcAddress("glSetLocalConstantEXT"))
			 && (glShaderOp1EXT = (PFNGLSHADEROP1EXTPROC)SDL_GL_GetProcAddress("glShaderOp1EXT"))
			 && (glShaderOp2EXT = (PFNGLSHADEROP2EXTPROC)SDL_GL_GetProcAddress("glShaderOp2EXT"))
			 && (glShaderOp3EXT = (PFNGLSHADEROP3EXTPROC)SDL_GL_GetProcAddress("glShaderOp3EXT"))
			 && (glSwizzleEXT = (PFNGLSWIZZLEEXTPROC)SDL_GL_GetProcAddress("glSwizzleEXT"))
			 && (glVariantbvEXT = (PFNGLVARIANTBVEXTPROC)SDL_GL_GetProcAddress("glVariantbvEXT"))
			 && (glVariantdvEXT = (PFNGLVARIANTDVEXTPROC)SDL_GL_GetProcAddress("glVariantdvEXT"))
			 && (glVariantfvEXT = (PFNGLVARIANTFVEXTPROC)SDL_GL_GetProcAddress("glVariantfvEXT"))
			 && (glVariantivEXT = (PFNGLVARIANTIVEXTPROC)SDL_GL_GetProcAddress("glVariantivEXT"))
			 && (glVariantPointerEXT = (PFNGLVARIANTPOINTEREXTPROC)SDL_GL_GetProcAddress("glVariantPointerEXT"))
			 && (glVariantsvEXT = (PFNGLVARIANTSVEXTPROC)SDL_GL_GetProcAddress("glVariantsvEXT"))
			 && (glVariantubvEXT = (PFNGLVARIANTUBVEXTPROC)SDL_GL_GetProcAddress("glVariantubvEXT"))
			 && (glVariantuivEXT = (PFNGLVARIANTUIVEXTPROC)SDL_GL_GetProcAddress("glVariantuivEXT"))
			 && (glVariantusvEXT = (PFNGLVARIANTUSVEXTPROC)SDL_GL_GetProcAddress("glVariantusvEXT"))
			 && (glWriteMaskEXT = (PFNGLWRITEMASKEXTPROC)SDL_GL_GetProcAddress("glWriteMaskEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_vertex_shader fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_vertex_shader fails." << endl;
			}
		}
	}
	bool have_EXT_vertex_shader() {
		return loaded;
	}
	void GL_EXT_vertex_shader_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_vertex_shader_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_vertex_shader_NAMESPACE

//  ...for GL_EXT_vertex_weighting:
namespace GL_EXT_vertex_weighting_NAMESPACE {
PFNGLVERTEXWEIGHTFEXTPROC glVertexWeightfEXT = NULL;
PFNGLVERTEXWEIGHTFVEXTPROC glVertexWeightfvEXT = NULL;
PFNGLVERTEXWEIGHTPOINTEREXTPROC glVertexWeightPointerEXT = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glVertexWeightfEXT = (PFNGLVERTEXWEIGHTFEXTPROC)SDL_GL_GetProcAddress("glVertexWeightfEXT"))
			 && (glVertexWeightfvEXT = (PFNGLVERTEXWEIGHTFVEXTPROC)SDL_GL_GetProcAddress("glVertexWeightfvEXT"))
			 && (glVertexWeightPointerEXT = (PFNGLVERTEXWEIGHTPOINTEREXTPROC)SDL_GL_GetProcAddress("glVertexWeightPointerEXT"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_EXT_vertex_weighting fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_EXT_vertex_weighting fails." << endl;
			}
		}
	}
	bool have_EXT_vertex_weighting() {
		return loaded;
	}
	void GL_EXT_vertex_weighting_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_EXT_vertex_weighting_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_EXT_vertex_weighting_NAMESPACE

//  ...for GL_GREMEDY_string_marker:
namespace GL_GREMEDY_string_marker_NAMESPACE {
PFNGLSTRINGMARKERGREMEDYPROC glStringMarkerGREMEDY = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glStringMarkerGREMEDY = (PFNGLSTRINGMARKERGREMEDYPROC)SDL_GL_GetProcAddress("glStringMarkerGREMEDY"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_GREMEDY_string_marker fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_GREMEDY_string_marker fails." << endl;
			}
		}
	}
	bool have_GREMEDY_string_marker() {
		return loaded;
	}
	void GL_GREMEDY_string_marker_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_GREMEDY_string_marker_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_GREMEDY_string_marker_NAMESPACE

//  ...for GL_HP_convolution_border_modes:
namespace GL_HP_convolution_border_modes_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_HP_convolution_border_modes fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_HP_convolution_border_modes fails." << endl;
			}
		}
	}
	bool have_HP_convolution_border_modes() {
		return loaded;
	}
	void GL_HP_convolution_border_modes_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_HP_convolution_border_modes_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_HP_convolution_border_modes_NAMESPACE

//  ...for GL_HP_image_transform:
namespace GL_HP_image_transform_NAMESPACE {
PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC glGetImageTransformParameterfvHP = NULL;
PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC glGetImageTransformParameterivHP = NULL;
PFNGLIMAGETRANSFORMPARAMETERFHPPROC glImageTransformParameterfHP = NULL;
PFNGLIMAGETRANSFORMPARAMETERFVHPPROC glImageTransformParameterfvHP = NULL;
PFNGLIMAGETRANSFORMPARAMETERIHPPROC glImageTransformParameteriHP = NULL;
PFNGLIMAGETRANSFORMPARAMETERIVHPPROC glImageTransformParameterivHP = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glGetImageTransformParameterfvHP = (PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC)SDL_GL_GetProcAddress("glGetImageTransformParameterfvHP"))
			 && (glGetImageTransformParameterivHP = (PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC)SDL_GL_GetProcAddress("glGetImageTransformParameterivHP"))
			 && (glImageTransformParameterfHP = (PFNGLIMAGETRANSFORMPARAMETERFHPPROC)SDL_GL_GetProcAddress("glImageTransformParameterfHP"))
			 && (glImageTransformParameterfvHP = (PFNGLIMAGETRANSFORMPARAMETERFVHPPROC)SDL_GL_GetProcAddress("glImageTransformParameterfvHP"))
			 && (glImageTransformParameteriHP = (PFNGLIMAGETRANSFORMPARAMETERIHPPROC)SDL_GL_GetProcAddress("glImageTransformParameteriHP"))
			 && (glImageTransformParameterivHP = (PFNGLIMAGETRANSFORMPARAMETERIVHPPROC)SDL_GL_GetProcAddress("glImageTransformParameterivHP"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_HP_image_transform fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_HP_image_transform fails." << endl;
			}
		}
	}
	bool have_HP_image_transform() {
		return loaded;
	}
	void GL_HP_image_transform_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_HP_image_transform_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_HP_image_transform_NAMESPACE

//  ...for GL_HP_occlusion_test:
namespace GL_HP_occlusion_test_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_HP_occlusion_test fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_HP_occlusion_test fails." << endl;
			}
		}
	}
	bool have_HP_occlusion_test() {
		return loaded;
	}
	void GL_HP_occlusion_test_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_HP_occlusion_test_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_HP_occlusion_test_NAMESPACE

//  ...for GL_HP_texture_lighting:
namespace GL_HP_texture_lighting_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_HP_texture_lighting fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_HP_texture_lighting fails." << endl;
			}
		}
	}
	bool have_HP_texture_lighting() {
		return loaded;
	}
	void GL_HP_texture_lighting_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_HP_texture_lighting_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_HP_texture_lighting_NAMESPACE

//  ...for GL_IBM_cull_vertex:
namespace GL_IBM_cull_vertex_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_IBM_cull_vertex fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_IBM_cull_vertex fails." << endl;
			}
		}
	}
	bool have_IBM_cull_vertex() {
		return loaded;
	}
	void GL_IBM_cull_vertex_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_IBM_cull_vertex_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_IBM_cull_vertex_NAMESPACE

//  ...for GL_IBM_multimode_draw_arrays:
namespace GL_IBM_multimode_draw_arrays_NAMESPACE {
PFNGLMULTIMODEDRAWARRAYSIBMPROC glMultiModeDrawArraysIBM = NULL;
PFNGLMULTIMODEDRAWELEMENTSIBMPROC glMultiModeDrawElementsIBM = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glMultiModeDrawArraysIBM = (PFNGLMULTIMODEDRAWARRAYSIBMPROC)SDL_GL_GetProcAddress("glMultiModeDrawArraysIBM"))
			 && (glMultiModeDrawElementsIBM = (PFNGLMULTIMODEDRAWELEMENTSIBMPROC)SDL_GL_GetProcAddress("glMultiModeDrawElementsIBM"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_IBM_multimode_draw_arrays fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_IBM_multimode_draw_arrays fails." << endl;
			}
		}
	}
	bool have_IBM_multimode_draw_arrays() {
		return loaded;
	}
	void GL_IBM_multimode_draw_arrays_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_IBM_multimode_draw_arrays_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_IBM_multimode_draw_arrays_NAMESPACE

//  ...for GL_IBM_rasterpos_clip:
namespace GL_IBM_rasterpos_clip_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_IBM_rasterpos_clip fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_IBM_rasterpos_clip fails." << endl;
			}
		}
	}
	bool have_IBM_rasterpos_clip() {
		return loaded;
	}
	void GL_IBM_rasterpos_clip_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_IBM_rasterpos_clip_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_IBM_rasterpos_clip_NAMESPACE

//  ...for GL_IBM_texture_mirrored_repeat:
namespace GL_IBM_texture_mirrored_repeat_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_IBM_texture_mirrored_repeat fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_IBM_texture_mirrored_repeat fails." << endl;
			}
		}
	}
	bool have_IBM_texture_mirrored_repeat() {
		return loaded;
	}
	void GL_IBM_texture_mirrored_repeat_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_IBM_texture_mirrored_repeat_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_IBM_texture_mirrored_repeat_NAMESPACE

//  ...for GL_IBM_vertex_array_lists:
namespace GL_IBM_vertex_array_lists_NAMESPACE {
PFNGLCOLORPOINTERLISTIBMPROC glColorPointerListIBM = NULL;
PFNGLEDGEFLAGPOINTERLISTIBMPROC glEdgeFlagPointerListIBM = NULL;
PFNGLFOGCOORDPOINTERLISTIBMPROC glFogCoordPointerListIBM = NULL;
PFNGLINDEXPOINTERLISTIBMPROC glIndexPointerListIBM = NULL;
PFNGLNORMALPOINTERLISTIBMPROC glNormalPointerListIBM = NULL;
PFNGLSECONDARYCOLORPOINTERLISTIBMPROC glSecondaryColorPointerListIBM = NULL;
PFNGLTEXCOORDPOINTERLISTIBMPROC glTexCoordPointerListIBM = NULL;
PFNGLVERTEXPOINTERLISTIBMPROC glVertexPointerListIBM = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glColorPointerListIBM = (PFNGLCOLORPOINTERLISTIBMPROC)SDL_GL_GetProcAddress("glColorPointerListIBM"))
			 && (glEdgeFlagPointerListIBM = (PFNGLEDGEFLAGPOINTERLISTIBMPROC)SDL_GL_GetProcAddress("glEdgeFlagPointerListIBM"))
			 && (glFogCoordPointerListIBM = (PFNGLFOGCOORDPOINTERLISTIBMPROC)SDL_GL_GetProcAddress("glFogCoordPointerListIBM"))
			 && (glIndexPointerListIBM = (PFNGLINDEXPOINTERLISTIBMPROC)SDL_GL_GetProcAddress("glIndexPointerListIBM"))
			 && (glNormalPointerListIBM = (PFNGLNORMALPOINTERLISTIBMPROC)SDL_GL_GetProcAddress("glNormalPointerListIBM"))
			 && (glSecondaryColorPointerListIBM = (PFNGLSECONDARYCOLORPOINTERLISTIBMPROC)SDL_GL_GetProcAddress("glSecondaryColorPointerListIBM"))
			 && (glTexCoordPointerListIBM = (PFNGLTEXCOORDPOINTERLISTIBMPROC)SDL_GL_GetProcAddress("glTexCoordPointerListIBM"))
			 && (glVertexPointerListIBM = (PFNGLVERTEXPOINTERLISTIBMPROC)SDL_GL_GetProcAddress("glVertexPointerListIBM"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_IBM_vertex_array_lists fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_IBM_vertex_array_lists fails." << endl;
			}
		}
	}
	bool have_IBM_vertex_array_lists() {
		return loaded;
	}
	void GL_IBM_vertex_array_lists_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_IBM_vertex_array_lists_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_IBM_vertex_array_lists_NAMESPACE

//  ...for GL_INGR_blend_func_separate:
namespace GL_INGR_blend_func_separate_NAMESPACE {
PFNGLBLENDFUNCSEPARATEINGRPROC glBlendFuncSeparateINGR = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glBlendFuncSeparateINGR = (PFNGLBLENDFUNCSEPARATEINGRPROC)SDL_GL_GetProcAddress("glBlendFuncSeparateINGR"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_INGR_blend_func_separate fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_INGR_blend_func_separate fails." << endl;
			}
		}
	}
	bool have_INGR_blend_func_separate() {
		return loaded;
	}
	void GL_INGR_blend_func_separate_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_INGR_blend_func_separate_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_INGR_blend_func_separate_NAMESPACE

//  ...for GL_INGR_color_clamp:
namespace GL_INGR_color_clamp_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_INGR_color_clamp fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_INGR_color_clamp fails." << endl;
			}
		}
	}
	bool have_INGR_color_clamp() {
		return loaded;
	}
	void GL_INGR_color_clamp_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_INGR_color_clamp_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_INGR_color_clamp_NAMESPACE

//  ...for GL_INGR_interlace_read:
namespace GL_INGR_interlace_read_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_INGR_interlace_read fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_INGR_interlace_read fails." << endl;
			}
		}
	}
	bool have_INGR_interlace_read() {
		return loaded;
	}
	void GL_INGR_interlace_read_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_INGR_interlace_read_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_INGR_interlace_read_NAMESPACE

//  ...for GL_INGR_palette_buffer:
namespace GL_INGR_palette_buffer_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_INGR_palette_buffer fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_INGR_palette_buffer fails." << endl;
			}
		}
	}
	bool have_INGR_palette_buffer() {
		return loaded;
	}
	void GL_INGR_palette_buffer_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_INGR_palette_buffer_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_INGR_palette_buffer_NAMESPACE

//  ...for GL_INTEL_parallel_arrays:
namespace GL_INTEL_parallel_arrays_NAMESPACE {
PFNGLCOLORPOINTERVINTELPROC glColorPointervINTEL = NULL;
PFNGLNORMALPOINTERVINTELPROC glNormalPointervINTEL = NULL;
PFNGLTEXCOORDPOINTERVINTELPROC glTexCoordPointervINTEL = NULL;
PFNGLVERTEXPOINTERVINTELPROC glVertexPointervINTEL = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glColorPointervINTEL = (PFNGLCOLORPOINTERVINTELPROC)SDL_GL_GetProcAddress("glColorPointervINTEL"))
			 && (glNormalPointervINTEL = (PFNGLNORMALPOINTERVINTELPROC)SDL_GL_GetProcAddress("glNormalPointervINTEL"))
			 && (glTexCoordPointervINTEL = (PFNGLTEXCOORDPOINTERVINTELPROC)SDL_GL_GetProcAddress("glTexCoordPointervINTEL"))
			 && (glVertexPointervINTEL = (PFNGLVERTEXPOINTERVINTELPROC)SDL_GL_GetProcAddress("glVertexPointervINTEL"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_INTEL_parallel_arrays fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_INTEL_parallel_arrays fails." << endl;
			}
		}
	}
	bool have_INTEL_parallel_arrays() {
		return loaded;
	}
	void GL_INTEL_parallel_arrays_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_INTEL_parallel_arrays_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_INTEL_parallel_arrays_NAMESPACE

//  ...for GL_INTEL_texture_scissor:
namespace GL_INTEL_texture_scissor_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_INTEL_texture_scissor fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_INTEL_texture_scissor fails." << endl;
			}
		}
	}
	bool have_INTEL_texture_scissor() {
		return loaded;
	}
	void GL_INTEL_texture_scissor_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_INTEL_texture_scissor_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_INTEL_texture_scissor_NAMESPACE

//  ...for GL_MESA_pack_invert:
namespace GL_MESA_pack_invert_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_MESA_pack_invert fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_MESA_pack_invert fails." << endl;
			}
		}
	}
	bool have_MESA_pack_invert() {
		return loaded;
	}
	void GL_MESA_pack_invert_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_MESA_pack_invert_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_MESA_pack_invert_NAMESPACE

//  ...for GL_MESA_resize_buffers:
namespace GL_MESA_resize_buffers_NAMESPACE {
PFNGLRESIZEBUFFERSMESAPROC glResizeBuffersMESA = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glResizeBuffersMESA = (PFNGLRESIZEBUFFERSMESAPROC)SDL_GL_GetProcAddress("glResizeBuffersMESA"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_MESA_resize_buffers fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_MESA_resize_buffers fails." << endl;
			}
		}
	}
	bool have_MESA_resize_buffers() {
		return loaded;
	}
	void GL_MESA_resize_buffers_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_MESA_resize_buffers_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_MESA_resize_buffers_NAMESPACE

//  ...for GL_MESA_window_pos:
namespace GL_MESA_window_pos_NAMESPACE {
PFNGLWINDOWPOS2DMESAPROC glWindowPos2dMESA = NULL;
PFNGLWINDOWPOS2DVMESAPROC glWindowPos2dvMESA = NULL;
PFNGLWINDOWPOS2FMESAPROC glWindowPos2fMESA = NULL;
PFNGLWINDOWPOS2FVMESAPROC glWindowPos2fvMESA = NULL;
PFNGLWINDOWPOS2IMESAPROC glWindowPos2iMESA = NULL;
PFNGLWINDOWPOS2IVMESAPROC glWindowPos2ivMESA = NULL;
PFNGLWINDOWPOS2SMESAPROC glWindowPos2sMESA = NULL;
PFNGLWINDOWPOS2SVMESAPROC glWindowPos2svMESA = NULL;
PFNGLWINDOWPOS3DMESAPROC glWindowPos3dMESA = NULL;
PFNGLWINDOWPOS3DVMESAPROC glWindowPos3dvMESA = NULL;
PFNGLWINDOWPOS3FMESAPROC glWindowPos3fMESA = NULL;
PFNGLWINDOWPOS3FVMESAPROC glWindowPos3fvMESA = NULL;
PFNGLWINDOWPOS3IMESAPROC glWindowPos3iMESA = NULL;
PFNGLWINDOWPOS3IVMESAPROC glWindowPos3ivMESA = NULL;
PFNGLWINDOWPOS3SMESAPROC glWindowPos3sMESA = NULL;
PFNGLWINDOWPOS3SVMESAPROC glWindowPos3svMESA = NULL;
PFNGLWINDOWPOS4DMESAPROC glWindowPos4dMESA = NULL;
PFNGLWINDOWPOS4DVMESAPROC glWindowPos4dvMESA = NULL;
PFNGLWINDOWPOS4FMESAPROC glWindowPos4fMESA = NULL;
PFNGLWINDOWPOS4FVMESAPROC glWindowPos4fvMESA = NULL;
PFNGLWINDOWPOS4IMESAPROC glWindowPos4iMESA = NULL;
PFNGLWINDOWPOS4IVMESAPROC glWindowPos4ivMESA = NULL;
PFNGLWINDOWPOS4SMESAPROC glWindowPos4sMESA = NULL;
PFNGLWINDOWPOS4SVMESAPROC glWindowPos4svMESA = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glWindowPos2dMESA = (PFNGLWINDOWPOS2DMESAPROC)SDL_GL_GetProcAddress("glWindowPos2dMESA"))
			 && (glWindowPos2dvMESA = (PFNGLWINDOWPOS2DVMESAPROC)SDL_GL_GetProcAddress("glWindowPos2dvMESA"))
			 && (glWindowPos2fMESA = (PFNGLWINDOWPOS2FMESAPROC)SDL_GL_GetProcAddress("glWindowPos2fMESA"))
			 && (glWindowPos2fvMESA = (PFNGLWINDOWPOS2FVMESAPROC)SDL_GL_GetProcAddress("glWindowPos2fvMESA"))
			 && (glWindowPos2iMESA = (PFNGLWINDOWPOS2IMESAPROC)SDL_GL_GetProcAddress("glWindowPos2iMESA"))
			 && (glWindowPos2ivMESA = (PFNGLWINDOWPOS2IVMESAPROC)SDL_GL_GetProcAddress("glWindowPos2ivMESA"))
			 && (glWindowPos2sMESA = (PFNGLWINDOWPOS2SMESAPROC)SDL_GL_GetProcAddress("glWindowPos2sMESA"))
			 && (glWindowPos2svMESA = (PFNGLWINDOWPOS2SVMESAPROC)SDL_GL_GetProcAddress("glWindowPos2svMESA"))
			 && (glWindowPos3dMESA = (PFNGLWINDOWPOS3DMESAPROC)SDL_GL_GetProcAddress("glWindowPos3dMESA"))
			 && (glWindowPos3dvMESA = (PFNGLWINDOWPOS3DVMESAPROC)SDL_GL_GetProcAddress("glWindowPos3dvMESA"))
			 && (glWindowPos3fMESA = (PFNGLWINDOWPOS3FMESAPROC)SDL_GL_GetProcAddress("glWindowPos3fMESA"))
			 && (glWindowPos3fvMESA = (PFNGLWINDOWPOS3FVMESAPROC)SDL_GL_GetProcAddress("glWindowPos3fvMESA"))
			 && (glWindowPos3iMESA = (PFNGLWINDOWPOS3IMESAPROC)SDL_GL_GetProcAddress("glWindowPos3iMESA"))
			 && (glWindowPos3ivMESA = (PFNGLWINDOWPOS3IVMESAPROC)SDL_GL_GetProcAddress("glWindowPos3ivMESA"))
			 && (glWindowPos3sMESA = (PFNGLWINDOWPOS3SMESAPROC)SDL_GL_GetProcAddress("glWindowPos3sMESA"))
			 && (glWindowPos3svMESA = (PFNGLWINDOWPOS3SVMESAPROC)SDL_GL_GetProcAddress("glWindowPos3svMESA"))
			 && (glWindowPos4dMESA = (PFNGLWINDOWPOS4DMESAPROC)SDL_GL_GetProcAddress("glWindowPos4dMESA"))
			 && (glWindowPos4dvMESA = (PFNGLWINDOWPOS4DVMESAPROC)SDL_GL_GetProcAddress("glWindowPos4dvMESA"))
			 && (glWindowPos4fMESA = (PFNGLWINDOWPOS4FMESAPROC)SDL_GL_GetProcAddress("glWindowPos4fMESA"))
			 && (glWindowPos4fvMESA = (PFNGLWINDOWPOS4FVMESAPROC)SDL_GL_GetProcAddress("glWindowPos4fvMESA"))
			 && (glWindowPos4iMESA = (PFNGLWINDOWPOS4IMESAPROC)SDL_GL_GetProcAddress("glWindowPos4iMESA"))
			 && (glWindowPos4ivMESA = (PFNGLWINDOWPOS4IVMESAPROC)SDL_GL_GetProcAddress("glWindowPos4ivMESA"))
			 && (glWindowPos4sMESA = (PFNGLWINDOWPOS4SMESAPROC)SDL_GL_GetProcAddress("glWindowPos4sMESA"))
			 && (glWindowPos4svMESA = (PFNGLWINDOWPOS4SVMESAPROC)SDL_GL_GetProcAddress("glWindowPos4svMESA"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_MESA_window_pos fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_MESA_window_pos fails." << endl;
			}
		}
	}
	bool have_MESA_window_pos() {
		return loaded;
	}
	void GL_MESA_window_pos_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_MESA_window_pos_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_MESA_window_pos_NAMESPACE

//  ...for GL_MESA_ycbcr_texture:
namespace GL_MESA_ycbcr_texture_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_MESA_ycbcr_texture fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_MESA_ycbcr_texture fails." << endl;
			}
		}
	}
	bool have_MESA_ycbcr_texture() {
		return loaded;
	}
	void GL_MESA_ycbcr_texture_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_MESA_ycbcr_texture_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_MESA_ycbcr_texture_NAMESPACE

//  ...for GL_NV_blend_square:
namespace GL_NV_blend_square_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_blend_square fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_blend_square fails." << endl;
			}
		}
	}
	bool have_NV_blend_square() {
		return loaded;
	}
	void GL_NV_blend_square_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_blend_square_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_blend_square_NAMESPACE

//  ...for GL_NV_copy_depth_to_color:
namespace GL_NV_copy_depth_to_color_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_copy_depth_to_color fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_copy_depth_to_color fails." << endl;
			}
		}
	}
	bool have_NV_copy_depth_to_color() {
		return loaded;
	}
	void GL_NV_copy_depth_to_color_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_copy_depth_to_color_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_copy_depth_to_color_NAMESPACE

//  ...for GL_NV_depth_clamp:
namespace GL_NV_depth_clamp_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_depth_clamp fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_depth_clamp fails." << endl;
			}
		}
	}
	bool have_NV_depth_clamp() {
		return loaded;
	}
	void GL_NV_depth_clamp_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_depth_clamp_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_depth_clamp_NAMESPACE

//  ...for GL_NV_evaluators:
namespace GL_NV_evaluators_NAMESPACE {
PFNGLEVALMAPSNVPROC glEvalMapsNV = NULL;
PFNGLGETMAPATTRIBPARAMETERFVNVPROC glGetMapAttribParameterfvNV = NULL;
PFNGLGETMAPATTRIBPARAMETERIVNVPROC glGetMapAttribParameterivNV = NULL;
PFNGLGETMAPCONTROLPOINTSNVPROC glGetMapControlPointsNV = NULL;
PFNGLGETMAPPARAMETERFVNVPROC glGetMapParameterfvNV = NULL;
PFNGLGETMAPPARAMETERIVNVPROC glGetMapParameterivNV = NULL;
PFNGLMAPCONTROLPOINTSNVPROC glMapControlPointsNV = NULL;
PFNGLMAPPARAMETERFVNVPROC glMapParameterfvNV = NULL;
PFNGLMAPPARAMETERIVNVPROC glMapParameterivNV = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glEvalMapsNV = (PFNGLEVALMAPSNVPROC)SDL_GL_GetProcAddress("glEvalMapsNV"))
			 && (glGetMapAttribParameterfvNV = (PFNGLGETMAPATTRIBPARAMETERFVNVPROC)SDL_GL_GetProcAddress("glGetMapAttribParameterfvNV"))
			 && (glGetMapAttribParameterivNV = (PFNGLGETMAPATTRIBPARAMETERIVNVPROC)SDL_GL_GetProcAddress("glGetMapAttribParameterivNV"))
			 && (glGetMapControlPointsNV = (PFNGLGETMAPCONTROLPOINTSNVPROC)SDL_GL_GetProcAddress("glGetMapControlPointsNV"))
			 && (glGetMapParameterfvNV = (PFNGLGETMAPPARAMETERFVNVPROC)SDL_GL_GetProcAddress("glGetMapParameterfvNV"))
			 && (glGetMapParameterivNV = (PFNGLGETMAPPARAMETERIVNVPROC)SDL_GL_GetProcAddress("glGetMapParameterivNV"))
			 && (glMapControlPointsNV = (PFNGLMAPCONTROLPOINTSNVPROC)SDL_GL_GetProcAddress("glMapControlPointsNV"))
			 && (glMapParameterfvNV = (PFNGLMAPPARAMETERFVNVPROC)SDL_GL_GetProcAddress("glMapParameterfvNV"))
			 && (glMapParameterivNV = (PFNGLMAPPARAMETERIVNVPROC)SDL_GL_GetProcAddress("glMapParameterivNV"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_evaluators fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_evaluators fails." << endl;
			}
		}
	}
	bool have_NV_evaluators() {
		return loaded;
	}
	void GL_NV_evaluators_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_evaluators_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_evaluators_NAMESPACE

//  ...for GL_NV_fence:
namespace GL_NV_fence_NAMESPACE {
PFNGLDELETEFENCESNVPROC glDeleteFencesNV = NULL;
PFNGLFINISHFENCENVPROC glFinishFenceNV = NULL;
PFNGLGENFENCESNVPROC glGenFencesNV = NULL;
PFNGLGETFENCEIVNVPROC glGetFenceivNV = NULL;
PFNGLISFENCENVPROC glIsFenceNV = NULL;
PFNGLSETFENCENVPROC glSetFenceNV = NULL;
PFNGLTESTFENCENVPROC glTestFenceNV = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glDeleteFencesNV = (PFNGLDELETEFENCESNVPROC)SDL_GL_GetProcAddress("glDeleteFencesNV"))
			 && (glFinishFenceNV = (PFNGLFINISHFENCENVPROC)SDL_GL_GetProcAddress("glFinishFenceNV"))
			 && (glGenFencesNV = (PFNGLGENFENCESNVPROC)SDL_GL_GetProcAddress("glGenFencesNV"))
			 && (glGetFenceivNV = (PFNGLGETFENCEIVNVPROC)SDL_GL_GetProcAddress("glGetFenceivNV"))
			 && (glIsFenceNV = (PFNGLISFENCENVPROC)SDL_GL_GetProcAddress("glIsFenceNV"))
			 && (glSetFenceNV = (PFNGLSETFENCENVPROC)SDL_GL_GetProcAddress("glSetFenceNV"))
			 && (glTestFenceNV = (PFNGLTESTFENCENVPROC)SDL_GL_GetProcAddress("glTestFenceNV"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_fence fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_fence fails." << endl;
			}
		}
	}
	bool have_NV_fence() {
		return loaded;
	}
	void GL_NV_fence_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_fence_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_fence_NAMESPACE

//  ...for GL_NV_float_buffer:
namespace GL_NV_float_buffer_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_float_buffer fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_float_buffer fails." << endl;
			}
		}
	}
	bool have_NV_float_buffer() {
		return loaded;
	}
	void GL_NV_float_buffer_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_float_buffer_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_float_buffer_NAMESPACE

//  ...for GL_NV_fog_distance:
namespace GL_NV_fog_distance_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_fog_distance fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_fog_distance fails." << endl;
			}
		}
	}
	bool have_NV_fog_distance() {
		return loaded;
	}
	void GL_NV_fog_distance_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_fog_distance_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_fog_distance_NAMESPACE

//  ...for GL_NV_fragment_program:
namespace GL_NV_fragment_program_NAMESPACE {
PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC glGetProgramNamedParameterdvNV = NULL;
PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC glGetProgramNamedParameterfvNV = NULL;
PFNGLPROGRAMNAMEDPARAMETER4DNVPROC glProgramNamedParameter4dNV = NULL;
PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC glProgramNamedParameter4dvNV = NULL;
PFNGLPROGRAMNAMEDPARAMETER4FNVPROC glProgramNamedParameter4fNV = NULL;
PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC glProgramNamedParameter4fvNV = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glGetProgramNamedParameterdvNV = (PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC)SDL_GL_GetProcAddress("glGetProgramNamedParameterdvNV"))
			 && (glGetProgramNamedParameterfvNV = (PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC)SDL_GL_GetProcAddress("glGetProgramNamedParameterfvNV"))
			 && (glProgramNamedParameter4dNV = (PFNGLPROGRAMNAMEDPARAMETER4DNVPROC)SDL_GL_GetProcAddress("glProgramNamedParameter4dNV"))
			 && (glProgramNamedParameter4dvNV = (PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC)SDL_GL_GetProcAddress("glProgramNamedParameter4dvNV"))
			 && (glProgramNamedParameter4fNV = (PFNGLPROGRAMNAMEDPARAMETER4FNVPROC)SDL_GL_GetProcAddress("glProgramNamedParameter4fNV"))
			 && (glProgramNamedParameter4fvNV = (PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC)SDL_GL_GetProcAddress("glProgramNamedParameter4fvNV"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_fragment_program fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_fragment_program fails." << endl;
			}
		}
	}
	bool have_NV_fragment_program() {
		return loaded;
	}
	void GL_NV_fragment_program_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_fragment_program_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_fragment_program_NAMESPACE

//  ...for GL_NV_fragment_program2:
namespace GL_NV_fragment_program2_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_fragment_program2 fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_fragment_program2 fails." << endl;
			}
		}
	}
	bool have_NV_fragment_program2() {
		return loaded;
	}
	void GL_NV_fragment_program2_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_fragment_program2_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_fragment_program2_NAMESPACE

//  ...for GL_NV_fragment_program_option:
namespace GL_NV_fragment_program_option_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_fragment_program_option fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_fragment_program_option fails." << endl;
			}
		}
	}
	bool have_NV_fragment_program_option() {
		return loaded;
	}
	void GL_NV_fragment_program_option_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_fragment_program_option_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_fragment_program_option_NAMESPACE

//  ...for GL_NV_half_float:
namespace GL_NV_half_float_NAMESPACE {
PFNGLCOLOR3HNVPROC glColor3hNV = NULL;
PFNGLCOLOR3HVNVPROC glColor3hvNV = NULL;
PFNGLCOLOR4HNVPROC glColor4hNV = NULL;
PFNGLCOLOR4HVNVPROC glColor4hvNV = NULL;
PFNGLFOGCOORDHNVPROC glFogCoordhNV = NULL;
PFNGLFOGCOORDHVNVPROC glFogCoordhvNV = NULL;
PFNGLMULTITEXCOORD1HNVPROC glMultiTexCoord1hNV = NULL;
PFNGLMULTITEXCOORD1HVNVPROC glMultiTexCoord1hvNV = NULL;
PFNGLMULTITEXCOORD2HNVPROC glMultiTexCoord2hNV = NULL;
PFNGLMULTITEXCOORD2HVNVPROC glMultiTexCoord2hvNV = NULL;
PFNGLMULTITEXCOORD3HNVPROC glMultiTexCoord3hNV = NULL;
PFNGLMULTITEXCOORD3HVNVPROC glMultiTexCoord3hvNV = NULL;
PFNGLMULTITEXCOORD4HNVPROC glMultiTexCoord4hNV = NULL;
PFNGLMULTITEXCOORD4HVNVPROC glMultiTexCoord4hvNV = NULL;
PFNGLNORMAL3HNVPROC glNormal3hNV = NULL;
PFNGLNORMAL3HVNVPROC glNormal3hvNV = NULL;
PFNGLSECONDARYCOLOR3HNVPROC glSecondaryColor3hNV = NULL;
PFNGLSECONDARYCOLOR3HVNVPROC glSecondaryColor3hvNV = NULL;
PFNGLTEXCOORD1HNVPROC glTexCoord1hNV = NULL;
PFNGLTEXCOORD1HVNVPROC glTexCoord1hvNV = NULL;
PFNGLTEXCOORD2HNVPROC glTexCoord2hNV = NULL;
PFNGLTEXCOORD2HVNVPROC glTexCoord2hvNV = NULL;
PFNGLTEXCOORD3HNVPROC glTexCoord3hNV = NULL;
PFNGLTEXCOORD3HVNVPROC glTexCoord3hvNV = NULL;
PFNGLTEXCOORD4HNVPROC glTexCoord4hNV = NULL;
PFNGLTEXCOORD4HVNVPROC glTexCoord4hvNV = NULL;
PFNGLVERTEX2HNVPROC glVertex2hNV = NULL;
PFNGLVERTEX2HVNVPROC glVertex2hvNV = NULL;
PFNGLVERTEX3HNVPROC glVertex3hNV = NULL;
PFNGLVERTEX3HVNVPROC glVertex3hvNV = NULL;
PFNGLVERTEX4HNVPROC glVertex4hNV = NULL;
PFNGLVERTEX4HVNVPROC glVertex4hvNV = NULL;
PFNGLVERTEXATTRIB1HNVPROC glVertexAttrib1hNV = NULL;
PFNGLVERTEXATTRIB1HVNVPROC glVertexAttrib1hvNV = NULL;
PFNGLVERTEXATTRIB2HNVPROC glVertexAttrib2hNV = NULL;
PFNGLVERTEXATTRIB2HVNVPROC glVertexAttrib2hvNV = NULL;
PFNGLVERTEXATTRIB3HNVPROC glVertexAttrib3hNV = NULL;
PFNGLVERTEXATTRIB3HVNVPROC glVertexAttrib3hvNV = NULL;
PFNGLVERTEXATTRIB4HNVPROC glVertexAttrib4hNV = NULL;
PFNGLVERTEXATTRIB4HVNVPROC glVertexAttrib4hvNV = NULL;
PFNGLVERTEXATTRIBS1HVNVPROC glVertexAttribs1hvNV = NULL;
PFNGLVERTEXATTRIBS2HVNVPROC glVertexAttribs2hvNV = NULL;
PFNGLVERTEXATTRIBS3HVNVPROC glVertexAttribs3hvNV = NULL;
PFNGLVERTEXATTRIBS4HVNVPROC glVertexAttribs4hvNV = NULL;
PFNGLVERTEXWEIGHTHNVPROC glVertexWeighthNV = NULL;
PFNGLVERTEXWEIGHTHVNVPROC glVertexWeighthvNV = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glColor3hNV = (PFNGLCOLOR3HNVPROC)SDL_GL_GetProcAddress("glColor3hNV"))
			 && (glColor3hvNV = (PFNGLCOLOR3HVNVPROC)SDL_GL_GetProcAddress("glColor3hvNV"))
			 && (glColor4hNV = (PFNGLCOLOR4HNVPROC)SDL_GL_GetProcAddress("glColor4hNV"))
			 && (glColor4hvNV = (PFNGLCOLOR4HVNVPROC)SDL_GL_GetProcAddress("glColor4hvNV"))
			 && (glFogCoordhNV = (PFNGLFOGCOORDHNVPROC)SDL_GL_GetProcAddress("glFogCoordhNV"))
			 && (glFogCoordhvNV = (PFNGLFOGCOORDHVNVPROC)SDL_GL_GetProcAddress("glFogCoordhvNV"))
			 && (glMultiTexCoord1hNV = (PFNGLMULTITEXCOORD1HNVPROC)SDL_GL_GetProcAddress("glMultiTexCoord1hNV"))
			 && (glMultiTexCoord1hvNV = (PFNGLMULTITEXCOORD1HVNVPROC)SDL_GL_GetProcAddress("glMultiTexCoord1hvNV"))
			 && (glMultiTexCoord2hNV = (PFNGLMULTITEXCOORD2HNVPROC)SDL_GL_GetProcAddress("glMultiTexCoord2hNV"))
			 && (glMultiTexCoord2hvNV = (PFNGLMULTITEXCOORD2HVNVPROC)SDL_GL_GetProcAddress("glMultiTexCoord2hvNV"))
			 && (glMultiTexCoord3hNV = (PFNGLMULTITEXCOORD3HNVPROC)SDL_GL_GetProcAddress("glMultiTexCoord3hNV"))
			 && (glMultiTexCoord3hvNV = (PFNGLMULTITEXCOORD3HVNVPROC)SDL_GL_GetProcAddress("glMultiTexCoord3hvNV"))
			 && (glMultiTexCoord4hNV = (PFNGLMULTITEXCOORD4HNVPROC)SDL_GL_GetProcAddress("glMultiTexCoord4hNV"))
			 && (glMultiTexCoord4hvNV = (PFNGLMULTITEXCOORD4HVNVPROC)SDL_GL_GetProcAddress("glMultiTexCoord4hvNV"))
			 && (glNormal3hNV = (PFNGLNORMAL3HNVPROC)SDL_GL_GetProcAddress("glNormal3hNV"))
			 && (glNormal3hvNV = (PFNGLNORMAL3HVNVPROC)SDL_GL_GetProcAddress("glNormal3hvNV"))
			 && (glSecondaryColor3hNV = (PFNGLSECONDARYCOLOR3HNVPROC)SDL_GL_GetProcAddress("glSecondaryColor3hNV"))
			 && (glSecondaryColor3hvNV = (PFNGLSECONDARYCOLOR3HVNVPROC)SDL_GL_GetProcAddress("glSecondaryColor3hvNV"))
			 && (glTexCoord1hNV = (PFNGLTEXCOORD1HNVPROC)SDL_GL_GetProcAddress("glTexCoord1hNV"))
			 && (glTexCoord1hvNV = (PFNGLTEXCOORD1HVNVPROC)SDL_GL_GetProcAddress("glTexCoord1hvNV"))
			 && (glTexCoord2hNV = (PFNGLTEXCOORD2HNVPROC)SDL_GL_GetProcAddress("glTexCoord2hNV"))
			 && (glTexCoord2hvNV = (PFNGLTEXCOORD2HVNVPROC)SDL_GL_GetProcAddress("glTexCoord2hvNV"))
			 && (glTexCoord3hNV = (PFNGLTEXCOORD3HNVPROC)SDL_GL_GetProcAddress("glTexCoord3hNV"))
			 && (glTexCoord3hvNV = (PFNGLTEXCOORD3HVNVPROC)SDL_GL_GetProcAddress("glTexCoord3hvNV"))
			 && (glTexCoord4hNV = (PFNGLTEXCOORD4HNVPROC)SDL_GL_GetProcAddress("glTexCoord4hNV"))
			 && (glTexCoord4hvNV = (PFNGLTEXCOORD4HVNVPROC)SDL_GL_GetProcAddress("glTexCoord4hvNV"))
			 && (glVertex2hNV = (PFNGLVERTEX2HNVPROC)SDL_GL_GetProcAddress("glVertex2hNV"))
			 && (glVertex2hvNV = (PFNGLVERTEX2HVNVPROC)SDL_GL_GetProcAddress("glVertex2hvNV"))
			 && (glVertex3hNV = (PFNGLVERTEX3HNVPROC)SDL_GL_GetProcAddress("glVertex3hNV"))
			 && (glVertex3hvNV = (PFNGLVERTEX3HVNVPROC)SDL_GL_GetProcAddress("glVertex3hvNV"))
			 && (glVertex4hNV = (PFNGLVERTEX4HNVPROC)SDL_GL_GetProcAddress("glVertex4hNV"))
			 && (glVertex4hvNV = (PFNGLVERTEX4HVNVPROC)SDL_GL_GetProcAddress("glVertex4hvNV"))
			 && (glVertexAttrib1hNV = (PFNGLVERTEXATTRIB1HNVPROC)SDL_GL_GetProcAddress("glVertexAttrib1hNV"))
			 && (glVertexAttrib1hvNV = (PFNGLVERTEXATTRIB1HVNVPROC)SDL_GL_GetProcAddress("glVertexAttrib1hvNV"))
			 && (glVertexAttrib2hNV = (PFNGLVERTEXATTRIB2HNVPROC)SDL_GL_GetProcAddress("glVertexAttrib2hNV"))
			 && (glVertexAttrib2hvNV = (PFNGLVERTEXATTRIB2HVNVPROC)SDL_GL_GetProcAddress("glVertexAttrib2hvNV"))
			 && (glVertexAttrib3hNV = (PFNGLVERTEXATTRIB3HNVPROC)SDL_GL_GetProcAddress("glVertexAttrib3hNV"))
			 && (glVertexAttrib3hvNV = (PFNGLVERTEXATTRIB3HVNVPROC)SDL_GL_GetProcAddress("glVertexAttrib3hvNV"))
			 && (glVertexAttrib4hNV = (PFNGLVERTEXATTRIB4HNVPROC)SDL_GL_GetProcAddress("glVertexAttrib4hNV"))
			 && (glVertexAttrib4hvNV = (PFNGLVERTEXATTRIB4HVNVPROC)SDL_GL_GetProcAddress("glVertexAttrib4hvNV"))
			 && (glVertexAttribs1hvNV = (PFNGLVERTEXATTRIBS1HVNVPROC)SDL_GL_GetProcAddress("glVertexAttribs1hvNV"))
			 && (glVertexAttribs2hvNV = (PFNGLVERTEXATTRIBS2HVNVPROC)SDL_GL_GetProcAddress("glVertexAttribs2hvNV"))
			 && (glVertexAttribs3hvNV = (PFNGLVERTEXATTRIBS3HVNVPROC)SDL_GL_GetProcAddress("glVertexAttribs3hvNV"))
			 && (glVertexAttribs4hvNV = (PFNGLVERTEXATTRIBS4HVNVPROC)SDL_GL_GetProcAddress("glVertexAttribs4hvNV"))
			 && (glVertexWeighthNV = (PFNGLVERTEXWEIGHTHNVPROC)SDL_GL_GetProcAddress("glVertexWeighthNV"))
			 && (glVertexWeighthvNV = (PFNGLVERTEXWEIGHTHVNVPROC)SDL_GL_GetProcAddress("glVertexWeighthvNV"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_half_float fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_half_float fails." << endl;
			}
		}
	}
	bool have_NV_half_float() {
		return loaded;
	}
	void GL_NV_half_float_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_half_float_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_half_float_NAMESPACE

//  ...for GL_NV_light_max_exponent:
namespace GL_NV_light_max_exponent_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_light_max_exponent fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_light_max_exponent fails." << endl;
			}
		}
	}
	bool have_NV_light_max_exponent() {
		return loaded;
	}
	void GL_NV_light_max_exponent_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_light_max_exponent_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_light_max_exponent_NAMESPACE

//  ...for GL_NV_multisample_filter_hint:
namespace GL_NV_multisample_filter_hint_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_multisample_filter_hint fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_multisample_filter_hint fails." << endl;
			}
		}
	}
	bool have_NV_multisample_filter_hint() {
		return loaded;
	}
	void GL_NV_multisample_filter_hint_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_multisample_filter_hint_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_multisample_filter_hint_NAMESPACE

//  ...for GL_NV_occlusion_query:
namespace GL_NV_occlusion_query_NAMESPACE {
PFNGLBEGINOCCLUSIONQUERYNVPROC glBeginOcclusionQueryNV = NULL;
PFNGLDELETEOCCLUSIONQUERIESNVPROC glDeleteOcclusionQueriesNV = NULL;
PFNGLENDOCCLUSIONQUERYNVPROC glEndOcclusionQueryNV = NULL;
PFNGLGENOCCLUSIONQUERIESNVPROC glGenOcclusionQueriesNV = NULL;
PFNGLGETOCCLUSIONQUERYIVNVPROC glGetOcclusionQueryivNV = NULL;
PFNGLGETOCCLUSIONQUERYUIVNVPROC glGetOcclusionQueryuivNV = NULL;
PFNGLISOCCLUSIONQUERYNVPROC glIsOcclusionQueryNV = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glBeginOcclusionQueryNV = (PFNGLBEGINOCCLUSIONQUERYNVPROC)SDL_GL_GetProcAddress("glBeginOcclusionQueryNV"))
			 && (glDeleteOcclusionQueriesNV = (PFNGLDELETEOCCLUSIONQUERIESNVPROC)SDL_GL_GetProcAddress("glDeleteOcclusionQueriesNV"))
			 && (glEndOcclusionQueryNV = (PFNGLENDOCCLUSIONQUERYNVPROC)SDL_GL_GetProcAddress("glEndOcclusionQueryNV"))
			 && (glGenOcclusionQueriesNV = (PFNGLGENOCCLUSIONQUERIESNVPROC)SDL_GL_GetProcAddress("glGenOcclusionQueriesNV"))
			 && (glGetOcclusionQueryivNV = (PFNGLGETOCCLUSIONQUERYIVNVPROC)SDL_GL_GetProcAddress("glGetOcclusionQueryivNV"))
			 && (glGetOcclusionQueryuivNV = (PFNGLGETOCCLUSIONQUERYUIVNVPROC)SDL_GL_GetProcAddress("glGetOcclusionQueryuivNV"))
			 && (glIsOcclusionQueryNV = (PFNGLISOCCLUSIONQUERYNVPROC)SDL_GL_GetProcAddress("glIsOcclusionQueryNV"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_occlusion_query fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_occlusion_query fails." << endl;
			}
		}
	}
	bool have_NV_occlusion_query() {
		return loaded;
	}
	void GL_NV_occlusion_query_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_occlusion_query_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_occlusion_query_NAMESPACE

//  ...for GL_NV_packed_depth_stencil:
namespace GL_NV_packed_depth_stencil_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_packed_depth_stencil fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_packed_depth_stencil fails." << endl;
			}
		}
	}
	bool have_NV_packed_depth_stencil() {
		return loaded;
	}
	void GL_NV_packed_depth_stencil_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_packed_depth_stencil_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_packed_depth_stencil_NAMESPACE

//  ...for GL_NV_pixel_data_range:
namespace GL_NV_pixel_data_range_NAMESPACE {
PFNGLFLUSHPIXELDATARANGENVPROC glFlushPixelDataRangeNV = NULL;
PFNGLPIXELDATARANGENVPROC glPixelDataRangeNV = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glFlushPixelDataRangeNV = (PFNGLFLUSHPIXELDATARANGENVPROC)SDL_GL_GetProcAddress("glFlushPixelDataRangeNV"))
			 && (glPixelDataRangeNV = (PFNGLPIXELDATARANGENVPROC)SDL_GL_GetProcAddress("glPixelDataRangeNV"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_pixel_data_range fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_pixel_data_range fails." << endl;
			}
		}
	}
	bool have_NV_pixel_data_range() {
		return loaded;
	}
	void GL_NV_pixel_data_range_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_pixel_data_range_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_pixel_data_range_NAMESPACE

//  ...for GL_NV_point_sprite:
namespace GL_NV_point_sprite_NAMESPACE {
PFNGLPOINTPARAMETERINVPROC glPointParameteriNV = NULL;
PFNGLPOINTPARAMETERIVNVPROC glPointParameterivNV = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glPointParameteriNV = (PFNGLPOINTPARAMETERINVPROC)SDL_GL_GetProcAddress("glPointParameteriNV"))
			 && (glPointParameterivNV = (PFNGLPOINTPARAMETERIVNVPROC)SDL_GL_GetProcAddress("glPointParameterivNV"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_point_sprite fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_point_sprite fails." << endl;
			}
		}
	}
	bool have_NV_point_sprite() {
		return loaded;
	}
	void GL_NV_point_sprite_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_point_sprite_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_point_sprite_NAMESPACE

//  ...for GL_NV_primitive_restart:
namespace GL_NV_primitive_restart_NAMESPACE {
PFNGLPRIMITIVERESTARTINDEXNVPROC glPrimitiveRestartIndexNV = NULL;
PFNGLPRIMITIVERESTARTNVPROC glPrimitiveRestartNV = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glPrimitiveRestartIndexNV = (PFNGLPRIMITIVERESTARTINDEXNVPROC)SDL_GL_GetProcAddress("glPrimitiveRestartIndexNV"))
			 && (glPrimitiveRestartNV = (PFNGLPRIMITIVERESTARTNVPROC)SDL_GL_GetProcAddress("glPrimitiveRestartNV"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_primitive_restart fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_primitive_restart fails." << endl;
			}
		}
	}
	bool have_NV_primitive_restart() {
		return loaded;
	}
	void GL_NV_primitive_restart_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_primitive_restart_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_primitive_restart_NAMESPACE

//  ...for GL_NV_register_combiners:
namespace GL_NV_register_combiners_NAMESPACE {
PFNGLCOMBINERINPUTNVPROC glCombinerInputNV = NULL;
PFNGLCOMBINEROUTPUTNVPROC glCombinerOutputNV = NULL;
PFNGLCOMBINERPARAMETERFNVPROC glCombinerParameterfNV = NULL;
PFNGLCOMBINERPARAMETERFVNVPROC glCombinerParameterfvNV = NULL;
PFNGLCOMBINERPARAMETERINVPROC glCombinerParameteriNV = NULL;
PFNGLCOMBINERPARAMETERIVNVPROC glCombinerParameterivNV = NULL;
PFNGLFINALCOMBINERINPUTNVPROC glFinalCombinerInputNV = NULL;
PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC glGetCombinerInputParameterfvNV = NULL;
PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC glGetCombinerInputParameterivNV = NULL;
PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC glGetCombinerOutputParameterfvNV = NULL;
PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC glGetCombinerOutputParameterivNV = NULL;
PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC glGetFinalCombinerInputParameterfvNV = NULL;
PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC glGetFinalCombinerInputParameterivNV = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glCombinerInputNV = (PFNGLCOMBINERINPUTNVPROC)SDL_GL_GetProcAddress("glCombinerInputNV"))
			 && (glCombinerOutputNV = (PFNGLCOMBINEROUTPUTNVPROC)SDL_GL_GetProcAddress("glCombinerOutputNV"))
			 && (glCombinerParameterfNV = (PFNGLCOMBINERPARAMETERFNVPROC)SDL_GL_GetProcAddress("glCombinerParameterfNV"))
			 && (glCombinerParameterfvNV = (PFNGLCOMBINERPARAMETERFVNVPROC)SDL_GL_GetProcAddress("glCombinerParameterfvNV"))
			 && (glCombinerParameteriNV = (PFNGLCOMBINERPARAMETERINVPROC)SDL_GL_GetProcAddress("glCombinerParameteriNV"))
			 && (glCombinerParameterivNV = (PFNGLCOMBINERPARAMETERIVNVPROC)SDL_GL_GetProcAddress("glCombinerParameterivNV"))
			 && (glFinalCombinerInputNV = (PFNGLFINALCOMBINERINPUTNVPROC)SDL_GL_GetProcAddress("glFinalCombinerInputNV"))
			 && (glGetCombinerInputParameterfvNV = (PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC)SDL_GL_GetProcAddress("glGetCombinerInputParameterfvNV"))
			 && (glGetCombinerInputParameterivNV = (PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC)SDL_GL_GetProcAddress("glGetCombinerInputParameterivNV"))
			 && (glGetCombinerOutputParameterfvNV = (PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC)SDL_GL_GetProcAddress("glGetCombinerOutputParameterfvNV"))
			 && (glGetCombinerOutputParameterivNV = (PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC)SDL_GL_GetProcAddress("glGetCombinerOutputParameterivNV"))
			 && (glGetFinalCombinerInputParameterfvNV = (PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC)SDL_GL_GetProcAddress("glGetFinalCombinerInputParameterfvNV"))
			 && (glGetFinalCombinerInputParameterivNV = (PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC)SDL_GL_GetProcAddress("glGetFinalCombinerInputParameterivNV"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_register_combiners fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_register_combiners fails." << endl;
			}
		}
	}
	bool have_NV_register_combiners() {
		return loaded;
	}
	void GL_NV_register_combiners_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_register_combiners_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_register_combiners_NAMESPACE

//  ...for GL_NV_register_combiners2:
namespace GL_NV_register_combiners2_NAMESPACE {
PFNGLCOMBINERSTAGEPARAMETERFVNVPROC glCombinerStageParameterfvNV = NULL;
PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC glGetCombinerStageParameterfvNV = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glCombinerStageParameterfvNV = (PFNGLCOMBINERSTAGEPARAMETERFVNVPROC)SDL_GL_GetProcAddress("glCombinerStageParameterfvNV"))
			 && (glGetCombinerStageParameterfvNV = (PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC)SDL_GL_GetProcAddress("glGetCombinerStageParameterfvNV"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_register_combiners2 fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_register_combiners2 fails." << endl;
			}
		}
	}
	bool have_NV_register_combiners2() {
		return loaded;
	}
	void GL_NV_register_combiners2_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_register_combiners2_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_register_combiners2_NAMESPACE

//  ...for GL_NV_texgen_emboss:
namespace GL_NV_texgen_emboss_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_texgen_emboss fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_texgen_emboss fails." << endl;
			}
		}
	}
	bool have_NV_texgen_emboss() {
		return loaded;
	}
	void GL_NV_texgen_emboss_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_texgen_emboss_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_texgen_emboss_NAMESPACE

//  ...for GL_NV_texgen_reflection:
namespace GL_NV_texgen_reflection_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_texgen_reflection fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_texgen_reflection fails." << endl;
			}
		}
	}
	bool have_NV_texgen_reflection() {
		return loaded;
	}
	void GL_NV_texgen_reflection_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_texgen_reflection_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_texgen_reflection_NAMESPACE

//  ...for GL_NV_texture_compression_vtc:
namespace GL_NV_texture_compression_vtc_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_texture_compression_vtc fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_texture_compression_vtc fails." << endl;
			}
		}
	}
	bool have_NV_texture_compression_vtc() {
		return loaded;
	}
	void GL_NV_texture_compression_vtc_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_texture_compression_vtc_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_texture_compression_vtc_NAMESPACE

//  ...for GL_NV_texture_env_combine4:
namespace GL_NV_texture_env_combine4_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_texture_env_combine4 fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_texture_env_combine4 fails." << endl;
			}
		}
	}
	bool have_NV_texture_env_combine4() {
		return loaded;
	}
	void GL_NV_texture_env_combine4_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_texture_env_combine4_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_texture_env_combine4_NAMESPACE

//  ...for GL_NV_texture_expand_normal:
namespace GL_NV_texture_expand_normal_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_texture_expand_normal fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_texture_expand_normal fails." << endl;
			}
		}
	}
	bool have_NV_texture_expand_normal() {
		return loaded;
	}
	void GL_NV_texture_expand_normal_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_texture_expand_normal_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_texture_expand_normal_NAMESPACE

//  ...for GL_NV_texture_rectangle:
namespace GL_NV_texture_rectangle_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_texture_rectangle fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_texture_rectangle fails." << endl;
			}
		}
	}
	bool have_NV_texture_rectangle() {
		return loaded;
	}
	void GL_NV_texture_rectangle_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_texture_rectangle_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_texture_rectangle_NAMESPACE

//  ...for GL_NV_texture_shader:
namespace GL_NV_texture_shader_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_texture_shader fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_texture_shader fails." << endl;
			}
		}
	}
	bool have_NV_texture_shader() {
		return loaded;
	}
	void GL_NV_texture_shader_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_texture_shader_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_texture_shader_NAMESPACE

//  ...for GL_NV_texture_shader2:
namespace GL_NV_texture_shader2_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_texture_shader2 fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_texture_shader2 fails." << endl;
			}
		}
	}
	bool have_NV_texture_shader2() {
		return loaded;
	}
	void GL_NV_texture_shader2_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_texture_shader2_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_texture_shader2_NAMESPACE

//  ...for GL_NV_texture_shader3:
namespace GL_NV_texture_shader3_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_texture_shader3 fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_texture_shader3 fails." << endl;
			}
		}
	}
	bool have_NV_texture_shader3() {
		return loaded;
	}
	void GL_NV_texture_shader3_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_texture_shader3_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_texture_shader3_NAMESPACE

//  ...for GL_NV_vertex_array_range:
namespace GL_NV_vertex_array_range_NAMESPACE {
PFNGLFLUSHVERTEXARRAYRANGENVPROC glFlushVertexArrayRangeNV = NULL;
PFNGLVERTEXARRAYRANGENVPROC glVertexArrayRangeNV = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glFlushVertexArrayRangeNV = (PFNGLFLUSHVERTEXARRAYRANGENVPROC)SDL_GL_GetProcAddress("glFlushVertexArrayRangeNV"))
			 && (glVertexArrayRangeNV = (PFNGLVERTEXARRAYRANGENVPROC)SDL_GL_GetProcAddress("glVertexArrayRangeNV"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_vertex_array_range fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_vertex_array_range fails." << endl;
			}
		}
	}
	bool have_NV_vertex_array_range() {
		return loaded;
	}
	void GL_NV_vertex_array_range_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_vertex_array_range_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_vertex_array_range_NAMESPACE

//  ...for GL_NV_vertex_array_range2:
namespace GL_NV_vertex_array_range2_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_vertex_array_range2 fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_vertex_array_range2 fails." << endl;
			}
		}
	}
	bool have_NV_vertex_array_range2() {
		return loaded;
	}
	void GL_NV_vertex_array_range2_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_vertex_array_range2_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_vertex_array_range2_NAMESPACE

//  ...for GL_NV_vertex_program:
namespace GL_NV_vertex_program_NAMESPACE {
PFNGLAREPROGRAMSRESIDENTNVPROC glAreProgramsResidentNV = NULL;
PFNGLBINDPROGRAMNVPROC glBindProgramNV = NULL;
PFNGLDELETEPROGRAMSNVPROC glDeleteProgramsNV = NULL;
PFNGLEXECUTEPROGRAMNVPROC glExecuteProgramNV = NULL;
PFNGLGENPROGRAMSNVPROC glGenProgramsNV = NULL;
PFNGLGETPROGRAMIVNVPROC glGetProgramivNV = NULL;
PFNGLGETPROGRAMPARAMETERDVNVPROC glGetProgramParameterdvNV = NULL;
PFNGLGETPROGRAMPARAMETERFVNVPROC glGetProgramParameterfvNV = NULL;
PFNGLGETPROGRAMSTRINGNVPROC glGetProgramStringNV = NULL;
PFNGLGETTRACKMATRIXIVNVPROC glGetTrackMatrixivNV = NULL;
PFNGLGETVERTEXATTRIBDVNVPROC glGetVertexAttribdvNV = NULL;
PFNGLGETVERTEXATTRIBFVNVPROC glGetVertexAttribfvNV = NULL;
PFNGLGETVERTEXATTRIBIVNVPROC glGetVertexAttribivNV = NULL;
PFNGLGETVERTEXATTRIBPOINTERVNVPROC glGetVertexAttribPointervNV = NULL;
PFNGLISPROGRAMNVPROC glIsProgramNV = NULL;
PFNGLLOADPROGRAMNVPROC glLoadProgramNV = NULL;
PFNGLPROGRAMPARAMETER4DNVPROC glProgramParameter4dNV = NULL;
PFNGLPROGRAMPARAMETER4DVNVPROC glProgramParameter4dvNV = NULL;
PFNGLPROGRAMPARAMETER4FNVPROC glProgramParameter4fNV = NULL;
PFNGLPROGRAMPARAMETER4FVNVPROC glProgramParameter4fvNV = NULL;
PFNGLPROGRAMPARAMETERS4DVNVPROC glProgramParameters4dvNV = NULL;
PFNGLPROGRAMPARAMETERS4FVNVPROC glProgramParameters4fvNV = NULL;
PFNGLREQUESTRESIDENTPROGRAMSNVPROC glRequestResidentProgramsNV = NULL;
PFNGLTRACKMATRIXNVPROC glTrackMatrixNV = NULL;
PFNGLVERTEXATTRIB1DNVPROC glVertexAttrib1dNV = NULL;
PFNGLVERTEXATTRIB1DVNVPROC glVertexAttrib1dvNV = NULL;
PFNGLVERTEXATTRIB1FNVPROC glVertexAttrib1fNV = NULL;
PFNGLVERTEXATTRIB1FVNVPROC glVertexAttrib1fvNV = NULL;
PFNGLVERTEXATTRIB1SNVPROC glVertexAttrib1sNV = NULL;
PFNGLVERTEXATTRIB1SVNVPROC glVertexAttrib1svNV = NULL;
PFNGLVERTEXATTRIB2DNVPROC glVertexAttrib2dNV = NULL;
PFNGLVERTEXATTRIB2DVNVPROC glVertexAttrib2dvNV = NULL;
PFNGLVERTEXATTRIB2FNVPROC glVertexAttrib2fNV = NULL;
PFNGLVERTEXATTRIB2FVNVPROC glVertexAttrib2fvNV = NULL;
PFNGLVERTEXATTRIB2SNVPROC glVertexAttrib2sNV = NULL;
PFNGLVERTEXATTRIB2SVNVPROC glVertexAttrib2svNV = NULL;
PFNGLVERTEXATTRIB3DNVPROC glVertexAttrib3dNV = NULL;
PFNGLVERTEXATTRIB3DVNVPROC glVertexAttrib3dvNV = NULL;
PFNGLVERTEXATTRIB3FNVPROC glVertexAttrib3fNV = NULL;
PFNGLVERTEXATTRIB3FVNVPROC glVertexAttrib3fvNV = NULL;
PFNGLVERTEXATTRIB3SNVPROC glVertexAttrib3sNV = NULL;
PFNGLVERTEXATTRIB3SVNVPROC glVertexAttrib3svNV = NULL;
PFNGLVERTEXATTRIB4DNVPROC glVertexAttrib4dNV = NULL;
PFNGLVERTEXATTRIB4DVNVPROC glVertexAttrib4dvNV = NULL;
PFNGLVERTEXATTRIB4FNVPROC glVertexAttrib4fNV = NULL;
PFNGLVERTEXATTRIB4FVNVPROC glVertexAttrib4fvNV = NULL;
PFNGLVERTEXATTRIB4SNVPROC glVertexAttrib4sNV = NULL;
PFNGLVERTEXATTRIB4SVNVPROC glVertexAttrib4svNV = NULL;
PFNGLVERTEXATTRIB4UBNVPROC glVertexAttrib4ubNV = NULL;
PFNGLVERTEXATTRIB4UBVNVPROC glVertexAttrib4ubvNV = NULL;
PFNGLVERTEXATTRIBPOINTERNVPROC glVertexAttribPointerNV = NULL;
PFNGLVERTEXATTRIBS1DVNVPROC glVertexAttribs1dvNV = NULL;
PFNGLVERTEXATTRIBS1FVNVPROC glVertexAttribs1fvNV = NULL;
PFNGLVERTEXATTRIBS1SVNVPROC glVertexAttribs1svNV = NULL;
PFNGLVERTEXATTRIBS2DVNVPROC glVertexAttribs2dvNV = NULL;
PFNGLVERTEXATTRIBS2FVNVPROC glVertexAttribs2fvNV = NULL;
PFNGLVERTEXATTRIBS2SVNVPROC glVertexAttribs2svNV = NULL;
PFNGLVERTEXATTRIBS3DVNVPROC glVertexAttribs3dvNV = NULL;
PFNGLVERTEXATTRIBS3FVNVPROC glVertexAttribs3fvNV = NULL;
PFNGLVERTEXATTRIBS3SVNVPROC glVertexAttribs3svNV = NULL;
PFNGLVERTEXATTRIBS4DVNVPROC glVertexAttribs4dvNV = NULL;
PFNGLVERTEXATTRIBS4FVNVPROC glVertexAttribs4fvNV = NULL;
PFNGLVERTEXATTRIBS4SVNVPROC glVertexAttribs4svNV = NULL;
PFNGLVERTEXATTRIBS4UBVNVPROC glVertexAttribs4ubvNV = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glAreProgramsResidentNV = (PFNGLAREPROGRAMSRESIDENTNVPROC)SDL_GL_GetProcAddress("glAreProgramsResidentNV"))
			 && (glBindProgramNV = (PFNGLBINDPROGRAMNVPROC)SDL_GL_GetProcAddress("glBindProgramNV"))
			 && (glDeleteProgramsNV = (PFNGLDELETEPROGRAMSNVPROC)SDL_GL_GetProcAddress("glDeleteProgramsNV"))
			 && (glExecuteProgramNV = (PFNGLEXECUTEPROGRAMNVPROC)SDL_GL_GetProcAddress("glExecuteProgramNV"))
			 && (glGenProgramsNV = (PFNGLGENPROGRAMSNVPROC)SDL_GL_GetProcAddress("glGenProgramsNV"))
			 && (glGetProgramivNV = (PFNGLGETPROGRAMIVNVPROC)SDL_GL_GetProcAddress("glGetProgramivNV"))
			 && (glGetProgramParameterdvNV = (PFNGLGETPROGRAMPARAMETERDVNVPROC)SDL_GL_GetProcAddress("glGetProgramParameterdvNV"))
			 && (glGetProgramParameterfvNV = (PFNGLGETPROGRAMPARAMETERFVNVPROC)SDL_GL_GetProcAddress("glGetProgramParameterfvNV"))
			 && (glGetProgramStringNV = (PFNGLGETPROGRAMSTRINGNVPROC)SDL_GL_GetProcAddress("glGetProgramStringNV"))
			 && (glGetTrackMatrixivNV = (PFNGLGETTRACKMATRIXIVNVPROC)SDL_GL_GetProcAddress("glGetTrackMatrixivNV"))
			 && (glGetVertexAttribdvNV = (PFNGLGETVERTEXATTRIBDVNVPROC)SDL_GL_GetProcAddress("glGetVertexAttribdvNV"))
			 && (glGetVertexAttribfvNV = (PFNGLGETVERTEXATTRIBFVNVPROC)SDL_GL_GetProcAddress("glGetVertexAttribfvNV"))
			 && (glGetVertexAttribivNV = (PFNGLGETVERTEXATTRIBIVNVPROC)SDL_GL_GetProcAddress("glGetVertexAttribivNV"))
			 && (glGetVertexAttribPointervNV = (PFNGLGETVERTEXATTRIBPOINTERVNVPROC)SDL_GL_GetProcAddress("glGetVertexAttribPointervNV"))
			 && (glIsProgramNV = (PFNGLISPROGRAMNVPROC)SDL_GL_GetProcAddress("glIsProgramNV"))
			 && (glLoadProgramNV = (PFNGLLOADPROGRAMNVPROC)SDL_GL_GetProcAddress("glLoadProgramNV"))
			 && (glProgramParameter4dNV = (PFNGLPROGRAMPARAMETER4DNVPROC)SDL_GL_GetProcAddress("glProgramParameter4dNV"))
			 && (glProgramParameter4dvNV = (PFNGLPROGRAMPARAMETER4DVNVPROC)SDL_GL_GetProcAddress("glProgramParameter4dvNV"))
			 && (glProgramParameter4fNV = (PFNGLPROGRAMPARAMETER4FNVPROC)SDL_GL_GetProcAddress("glProgramParameter4fNV"))
			 && (glProgramParameter4fvNV = (PFNGLPROGRAMPARAMETER4FVNVPROC)SDL_GL_GetProcAddress("glProgramParameter4fvNV"))
			 && (glProgramParameters4dvNV = (PFNGLPROGRAMPARAMETERS4DVNVPROC)SDL_GL_GetProcAddress("glProgramParameters4dvNV"))
			 && (glProgramParameters4fvNV = (PFNGLPROGRAMPARAMETERS4FVNVPROC)SDL_GL_GetProcAddress("glProgramParameters4fvNV"))
			 && (glRequestResidentProgramsNV = (PFNGLREQUESTRESIDENTPROGRAMSNVPROC)SDL_GL_GetProcAddress("glRequestResidentProgramsNV"))
			 && (glTrackMatrixNV = (PFNGLTRACKMATRIXNVPROC)SDL_GL_GetProcAddress("glTrackMatrixNV"))
			 && (glVertexAttrib1dNV = (PFNGLVERTEXATTRIB1DNVPROC)SDL_GL_GetProcAddress("glVertexAttrib1dNV"))
			 && (glVertexAttrib1dvNV = (PFNGLVERTEXATTRIB1DVNVPROC)SDL_GL_GetProcAddress("glVertexAttrib1dvNV"))
			 && (glVertexAttrib1fNV = (PFNGLVERTEXATTRIB1FNVPROC)SDL_GL_GetProcAddress("glVertexAttrib1fNV"))
			 && (glVertexAttrib1fvNV = (PFNGLVERTEXATTRIB1FVNVPROC)SDL_GL_GetProcAddress("glVertexAttrib1fvNV"))
			 && (glVertexAttrib1sNV = (PFNGLVERTEXATTRIB1SNVPROC)SDL_GL_GetProcAddress("glVertexAttrib1sNV"))
			 && (glVertexAttrib1svNV = (PFNGLVERTEXATTRIB1SVNVPROC)SDL_GL_GetProcAddress("glVertexAttrib1svNV"))
			 && (glVertexAttrib2dNV = (PFNGLVERTEXATTRIB2DNVPROC)SDL_GL_GetProcAddress("glVertexAttrib2dNV"))
			 && (glVertexAttrib2dvNV = (PFNGLVERTEXATTRIB2DVNVPROC)SDL_GL_GetProcAddress("glVertexAttrib2dvNV"))
			 && (glVertexAttrib2fNV = (PFNGLVERTEXATTRIB2FNVPROC)SDL_GL_GetProcAddress("glVertexAttrib2fNV"))
			 && (glVertexAttrib2fvNV = (PFNGLVERTEXATTRIB2FVNVPROC)SDL_GL_GetProcAddress("glVertexAttrib2fvNV"))
			 && (glVertexAttrib2sNV = (PFNGLVERTEXATTRIB2SNVPROC)SDL_GL_GetProcAddress("glVertexAttrib2sNV"))
			 && (glVertexAttrib2svNV = (PFNGLVERTEXATTRIB2SVNVPROC)SDL_GL_GetProcAddress("glVertexAttrib2svNV"))
			 && (glVertexAttrib3dNV = (PFNGLVERTEXATTRIB3DNVPROC)SDL_GL_GetProcAddress("glVertexAttrib3dNV"))
			 && (glVertexAttrib3dvNV = (PFNGLVERTEXATTRIB3DVNVPROC)SDL_GL_GetProcAddress("glVertexAttrib3dvNV"))
			 && (glVertexAttrib3fNV = (PFNGLVERTEXATTRIB3FNVPROC)SDL_GL_GetProcAddress("glVertexAttrib3fNV"))
			 && (glVertexAttrib3fvNV = (PFNGLVERTEXATTRIB3FVNVPROC)SDL_GL_GetProcAddress("glVertexAttrib3fvNV"))
			 && (glVertexAttrib3sNV = (PFNGLVERTEXATTRIB3SNVPROC)SDL_GL_GetProcAddress("glVertexAttrib3sNV"))
			 && (glVertexAttrib3svNV = (PFNGLVERTEXATTRIB3SVNVPROC)SDL_GL_GetProcAddress("glVertexAttrib3svNV"))
			 && (glVertexAttrib4dNV = (PFNGLVERTEXATTRIB4DNVPROC)SDL_GL_GetProcAddress("glVertexAttrib4dNV"))
			 && (glVertexAttrib4dvNV = (PFNGLVERTEXATTRIB4DVNVPROC)SDL_GL_GetProcAddress("glVertexAttrib4dvNV"))
			 && (glVertexAttrib4fNV = (PFNGLVERTEXATTRIB4FNVPROC)SDL_GL_GetProcAddress("glVertexAttrib4fNV"))
			 && (glVertexAttrib4fvNV = (PFNGLVERTEXATTRIB4FVNVPROC)SDL_GL_GetProcAddress("glVertexAttrib4fvNV"))
			 && (glVertexAttrib4sNV = (PFNGLVERTEXATTRIB4SNVPROC)SDL_GL_GetProcAddress("glVertexAttrib4sNV"))
			 && (glVertexAttrib4svNV = (PFNGLVERTEXATTRIB4SVNVPROC)SDL_GL_GetProcAddress("glVertexAttrib4svNV"))
			 && (glVertexAttrib4ubNV = (PFNGLVERTEXATTRIB4UBNVPROC)SDL_GL_GetProcAddress("glVertexAttrib4ubNV"))
			 && (glVertexAttrib4ubvNV = (PFNGLVERTEXATTRIB4UBVNVPROC)SDL_GL_GetProcAddress("glVertexAttrib4ubvNV"))
			 && (glVertexAttribPointerNV = (PFNGLVERTEXATTRIBPOINTERNVPROC)SDL_GL_GetProcAddress("glVertexAttribPointerNV"))
			 && (glVertexAttribs1dvNV = (PFNGLVERTEXATTRIBS1DVNVPROC)SDL_GL_GetProcAddress("glVertexAttribs1dvNV"))
			 && (glVertexAttribs1fvNV = (PFNGLVERTEXATTRIBS1FVNVPROC)SDL_GL_GetProcAddress("glVertexAttribs1fvNV"))
			 && (glVertexAttribs1svNV = (PFNGLVERTEXATTRIBS1SVNVPROC)SDL_GL_GetProcAddress("glVertexAttribs1svNV"))
			 && (glVertexAttribs2dvNV = (PFNGLVERTEXATTRIBS2DVNVPROC)SDL_GL_GetProcAddress("glVertexAttribs2dvNV"))
			 && (glVertexAttribs2fvNV = (PFNGLVERTEXATTRIBS2FVNVPROC)SDL_GL_GetProcAddress("glVertexAttribs2fvNV"))
			 && (glVertexAttribs2svNV = (PFNGLVERTEXATTRIBS2SVNVPROC)SDL_GL_GetProcAddress("glVertexAttribs2svNV"))
			 && (glVertexAttribs3dvNV = (PFNGLVERTEXATTRIBS3DVNVPROC)SDL_GL_GetProcAddress("glVertexAttribs3dvNV"))
			 && (glVertexAttribs3fvNV = (PFNGLVERTEXATTRIBS3FVNVPROC)SDL_GL_GetProcAddress("glVertexAttribs3fvNV"))
			 && (glVertexAttribs3svNV = (PFNGLVERTEXATTRIBS3SVNVPROC)SDL_GL_GetProcAddress("glVertexAttribs3svNV"))
			 && (glVertexAttribs4dvNV = (PFNGLVERTEXATTRIBS4DVNVPROC)SDL_GL_GetProcAddress("glVertexAttribs4dvNV"))
			 && (glVertexAttribs4fvNV = (PFNGLVERTEXATTRIBS4FVNVPROC)SDL_GL_GetProcAddress("glVertexAttribs4fvNV"))
			 && (glVertexAttribs4svNV = (PFNGLVERTEXATTRIBS4SVNVPROC)SDL_GL_GetProcAddress("glVertexAttribs4svNV"))
			 && (glVertexAttribs4ubvNV = (PFNGLVERTEXATTRIBS4UBVNVPROC)SDL_GL_GetProcAddress("glVertexAttribs4ubvNV"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_vertex_program fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_vertex_program fails." << endl;
			}
		}
	}
	bool have_NV_vertex_program() {
		return loaded;
	}
	void GL_NV_vertex_program_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_vertex_program_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_vertex_program_NAMESPACE

//  ...for GL_NV_vertex_program1_1:
namespace GL_NV_vertex_program1_1_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_vertex_program1_1 fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_vertex_program1_1 fails." << endl;
			}
		}
	}
	bool have_NV_vertex_program1_1() {
		return loaded;
	}
	void GL_NV_vertex_program1_1_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_vertex_program1_1_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_vertex_program1_1_NAMESPACE

//  ...for GL_NV_vertex_program2:
namespace GL_NV_vertex_program2_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_vertex_program2 fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_vertex_program2 fails." << endl;
			}
		}
	}
	bool have_NV_vertex_program2() {
		return loaded;
	}
	void GL_NV_vertex_program2_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_vertex_program2_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_vertex_program2_NAMESPACE

//  ...for GL_NV_vertex_program2_option:
namespace GL_NV_vertex_program2_option_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_vertex_program2_option fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_vertex_program2_option fails." << endl;
			}
		}
	}
	bool have_NV_vertex_program2_option() {
		return loaded;
	}
	void GL_NV_vertex_program2_option_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_vertex_program2_option_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_vertex_program2_option_NAMESPACE

//  ...for GL_NV_vertex_program3:
namespace GL_NV_vertex_program3_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_NV_vertex_program3 fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_NV_vertex_program3 fails." << endl;
			}
		}
	}
	bool have_NV_vertex_program3() {
		return loaded;
	}
	void GL_NV_vertex_program3_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_NV_vertex_program3_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_NV_vertex_program3_NAMESPACE

//  ...for GL_OES_read_format:
namespace GL_OES_read_format_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_OES_read_format fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_OES_read_format fails." << endl;
			}
		}
	}
	bool have_OES_read_format() {
		return loaded;
	}
	void GL_OES_read_format_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_OES_read_format_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_OES_read_format_NAMESPACE

//  ...for GL_OML_interlace:
namespace GL_OML_interlace_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_OML_interlace fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_OML_interlace fails." << endl;
			}
		}
	}
	bool have_OML_interlace() {
		return loaded;
	}
	void GL_OML_interlace_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_OML_interlace_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_OML_interlace_NAMESPACE

//  ...for GL_OML_resample:
namespace GL_OML_resample_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_OML_resample fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_OML_resample fails." << endl;
			}
		}
	}
	bool have_OML_resample() {
		return loaded;
	}
	void GL_OML_resample_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_OML_resample_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_OML_resample_NAMESPACE

//  ...for GL_OML_subsample:
namespace GL_OML_subsample_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_OML_subsample fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_OML_subsample fails." << endl;
			}
		}
	}
	bool have_OML_subsample() {
		return loaded;
	}
	void GL_OML_subsample_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_OML_subsample_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_OML_subsample_NAMESPACE

//  ...for GL_PGI_misc_hints:
namespace GL_PGI_misc_hints_NAMESPACE {
PFNGLHINTPGIPROC glHintPGI = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glHintPGI = (PFNGLHINTPGIPROC)SDL_GL_GetProcAddress("glHintPGI"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_PGI_misc_hints fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_PGI_misc_hints fails." << endl;
			}
		}
	}
	bool have_PGI_misc_hints() {
		return loaded;
	}
	void GL_PGI_misc_hints_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_PGI_misc_hints_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_PGI_misc_hints_NAMESPACE

//  ...for GL_PGI_vertex_hints:
namespace GL_PGI_vertex_hints_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_PGI_vertex_hints fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_PGI_vertex_hints fails." << endl;
			}
		}
	}
	bool have_PGI_vertex_hints() {
		return loaded;
	}
	void GL_PGI_vertex_hints_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_PGI_vertex_hints_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_PGI_vertex_hints_NAMESPACE

//  ...for GL_REND_screen_coordinates:
namespace GL_REND_screen_coordinates_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_REND_screen_coordinates fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_REND_screen_coordinates fails." << endl;
			}
		}
	}
	bool have_REND_screen_coordinates() {
		return loaded;
	}
	void GL_REND_screen_coordinates_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_REND_screen_coordinates_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_REND_screen_coordinates_NAMESPACE

//  ...for GL_SGIS_detail_texture:
namespace GL_SGIS_detail_texture_NAMESPACE {
PFNGLDETAILTEXFUNCSGISPROC glDetailTexFuncSGIS = NULL;
PFNGLGETDETAILTEXFUNCSGISPROC glGetDetailTexFuncSGIS = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glDetailTexFuncSGIS = (PFNGLDETAILTEXFUNCSGISPROC)SDL_GL_GetProcAddress("glDetailTexFuncSGIS"))
			 && (glGetDetailTexFuncSGIS = (PFNGLGETDETAILTEXFUNCSGISPROC)SDL_GL_GetProcAddress("glGetDetailTexFuncSGIS"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIS_detail_texture fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIS_detail_texture fails." << endl;
			}
		}
	}
	bool have_SGIS_detail_texture() {
		return loaded;
	}
	void GL_SGIS_detail_texture_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIS_detail_texture_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIS_detail_texture_NAMESPACE

//  ...for GL_SGIS_fog_function:
namespace GL_SGIS_fog_function_NAMESPACE {
PFNGLFOGFUNCSGISPROC glFogFuncSGIS = NULL;
PFNGLGETFOGFUNCSGISPROC glGetFogFuncSGIS = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glFogFuncSGIS = (PFNGLFOGFUNCSGISPROC)SDL_GL_GetProcAddress("glFogFuncSGIS"))
			 && (glGetFogFuncSGIS = (PFNGLGETFOGFUNCSGISPROC)SDL_GL_GetProcAddress("glGetFogFuncSGIS"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIS_fog_function fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIS_fog_function fails." << endl;
			}
		}
	}
	bool have_SGIS_fog_function() {
		return loaded;
	}
	void GL_SGIS_fog_function_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIS_fog_function_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIS_fog_function_NAMESPACE

//  ...for GL_SGIS_generate_mipmap:
namespace GL_SGIS_generate_mipmap_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIS_generate_mipmap fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIS_generate_mipmap fails." << endl;
			}
		}
	}
	bool have_SGIS_generate_mipmap() {
		return loaded;
	}
	void GL_SGIS_generate_mipmap_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIS_generate_mipmap_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIS_generate_mipmap_NAMESPACE

//  ...for GL_SGIS_multisample:
namespace GL_SGIS_multisample_NAMESPACE {
PFNGLSAMPLEMASKSGISPROC glSampleMaskSGIS = NULL;
PFNGLSAMPLEPATTERNSGISPROC glSamplePatternSGIS = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glSampleMaskSGIS = (PFNGLSAMPLEMASKSGISPROC)SDL_GL_GetProcAddress("glSampleMaskSGIS"))
			 && (glSamplePatternSGIS = (PFNGLSAMPLEPATTERNSGISPROC)SDL_GL_GetProcAddress("glSamplePatternSGIS"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIS_multisample fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIS_multisample fails." << endl;
			}
		}
	}
	bool have_SGIS_multisample() {
		return loaded;
	}
	void GL_SGIS_multisample_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIS_multisample_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIS_multisample_NAMESPACE

//  ...for GL_SGIS_pixel_texture:
namespace GL_SGIS_pixel_texture_NAMESPACE {
PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC glGetPixelTexGenParameterfvSGIS = NULL;
PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC glGetPixelTexGenParameterivSGIS = NULL;
PFNGLPIXELTEXGENPARAMETERFSGISPROC glPixelTexGenParameterfSGIS = NULL;
PFNGLPIXELTEXGENPARAMETERFVSGISPROC glPixelTexGenParameterfvSGIS = NULL;
PFNGLPIXELTEXGENPARAMETERISGISPROC glPixelTexGenParameteriSGIS = NULL;
PFNGLPIXELTEXGENPARAMETERIVSGISPROC glPixelTexGenParameterivSGIS = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glGetPixelTexGenParameterfvSGIS = (PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC)SDL_GL_GetProcAddress("glGetPixelTexGenParameterfvSGIS"))
			 && (glGetPixelTexGenParameterivSGIS = (PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC)SDL_GL_GetProcAddress("glGetPixelTexGenParameterivSGIS"))
			 && (glPixelTexGenParameterfSGIS = (PFNGLPIXELTEXGENPARAMETERFSGISPROC)SDL_GL_GetProcAddress("glPixelTexGenParameterfSGIS"))
			 && (glPixelTexGenParameterfvSGIS = (PFNGLPIXELTEXGENPARAMETERFVSGISPROC)SDL_GL_GetProcAddress("glPixelTexGenParameterfvSGIS"))
			 && (glPixelTexGenParameteriSGIS = (PFNGLPIXELTEXGENPARAMETERISGISPROC)SDL_GL_GetProcAddress("glPixelTexGenParameteriSGIS"))
			 && (glPixelTexGenParameterivSGIS = (PFNGLPIXELTEXGENPARAMETERIVSGISPROC)SDL_GL_GetProcAddress("glPixelTexGenParameterivSGIS"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIS_pixel_texture fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIS_pixel_texture fails." << endl;
			}
		}
	}
	bool have_SGIS_pixel_texture() {
		return loaded;
	}
	void GL_SGIS_pixel_texture_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIS_pixel_texture_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIS_pixel_texture_NAMESPACE

//  ...for GL_SGIS_point_line_texgen:
namespace GL_SGIS_point_line_texgen_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIS_point_line_texgen fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIS_point_line_texgen fails." << endl;
			}
		}
	}
	bool have_SGIS_point_line_texgen() {
		return loaded;
	}
	void GL_SGIS_point_line_texgen_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIS_point_line_texgen_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIS_point_line_texgen_NAMESPACE

//  ...for GL_SGIS_point_parameters:
namespace GL_SGIS_point_parameters_NAMESPACE {
PFNGLPOINTPARAMETERFSGISPROC glPointParameterfSGIS = NULL;
PFNGLPOINTPARAMETERFVSGISPROC glPointParameterfvSGIS = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glPointParameterfSGIS = (PFNGLPOINTPARAMETERFSGISPROC)SDL_GL_GetProcAddress("glPointParameterfSGIS"))
			 && (glPointParameterfvSGIS = (PFNGLPOINTPARAMETERFVSGISPROC)SDL_GL_GetProcAddress("glPointParameterfvSGIS"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIS_point_parameters fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIS_point_parameters fails." << endl;
			}
		}
	}
	bool have_SGIS_point_parameters() {
		return loaded;
	}
	void GL_SGIS_point_parameters_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIS_point_parameters_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIS_point_parameters_NAMESPACE

//  ...for GL_SGIS_sharpen_texture:
namespace GL_SGIS_sharpen_texture_NAMESPACE {
PFNGLGETSHARPENTEXFUNCSGISPROC glGetSharpenTexFuncSGIS = NULL;
PFNGLSHARPENTEXFUNCSGISPROC glSharpenTexFuncSGIS = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glGetSharpenTexFuncSGIS = (PFNGLGETSHARPENTEXFUNCSGISPROC)SDL_GL_GetProcAddress("glGetSharpenTexFuncSGIS"))
			 && (glSharpenTexFuncSGIS = (PFNGLSHARPENTEXFUNCSGISPROC)SDL_GL_GetProcAddress("glSharpenTexFuncSGIS"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIS_sharpen_texture fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIS_sharpen_texture fails." << endl;
			}
		}
	}
	bool have_SGIS_sharpen_texture() {
		return loaded;
	}
	void GL_SGIS_sharpen_texture_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIS_sharpen_texture_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIS_sharpen_texture_NAMESPACE

//  ...for GL_SGIS_texture4:
namespace GL_SGIS_texture4_NAMESPACE {
PFNGLTEXIMAGE4DSGISPROC glTexImage4DSGIS = NULL;
PFNGLTEXSUBIMAGE4DSGISPROC glTexSubImage4DSGIS = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glTexImage4DSGIS = (PFNGLTEXIMAGE4DSGISPROC)SDL_GL_GetProcAddress("glTexImage4DSGIS"))
			 && (glTexSubImage4DSGIS = (PFNGLTEXSUBIMAGE4DSGISPROC)SDL_GL_GetProcAddress("glTexSubImage4DSGIS"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIS_texture4 fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIS_texture4 fails." << endl;
			}
		}
	}
	bool have_SGIS_texture4() {
		return loaded;
	}
	void GL_SGIS_texture4_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIS_texture4_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIS_texture4_NAMESPACE

//  ...for GL_SGIS_texture_border_clamp:
namespace GL_SGIS_texture_border_clamp_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIS_texture_border_clamp fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIS_texture_border_clamp fails." << endl;
			}
		}
	}
	bool have_SGIS_texture_border_clamp() {
		return loaded;
	}
	void GL_SGIS_texture_border_clamp_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIS_texture_border_clamp_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIS_texture_border_clamp_NAMESPACE

//  ...for GL_SGIS_texture_color_mask:
namespace GL_SGIS_texture_color_mask_NAMESPACE {
PFNGLTEXTURECOLORMASKSGISPROC glTextureColorMaskSGIS = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glTextureColorMaskSGIS = (PFNGLTEXTURECOLORMASKSGISPROC)SDL_GL_GetProcAddress("glTextureColorMaskSGIS"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIS_texture_color_mask fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIS_texture_color_mask fails." << endl;
			}
		}
	}
	bool have_SGIS_texture_color_mask() {
		return loaded;
	}
	void GL_SGIS_texture_color_mask_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIS_texture_color_mask_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIS_texture_color_mask_NAMESPACE

//  ...for GL_SGIS_texture_edge_clamp:
namespace GL_SGIS_texture_edge_clamp_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIS_texture_edge_clamp fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIS_texture_edge_clamp fails." << endl;
			}
		}
	}
	bool have_SGIS_texture_edge_clamp() {
		return loaded;
	}
	void GL_SGIS_texture_edge_clamp_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIS_texture_edge_clamp_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIS_texture_edge_clamp_NAMESPACE

//  ...for GL_SGIS_texture_filter4:
namespace GL_SGIS_texture_filter4_NAMESPACE {
PFNGLGETTEXFILTERFUNCSGISPROC glGetTexFilterFuncSGIS = NULL;
PFNGLTEXFILTERFUNCSGISPROC glTexFilterFuncSGIS = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glGetTexFilterFuncSGIS = (PFNGLGETTEXFILTERFUNCSGISPROC)SDL_GL_GetProcAddress("glGetTexFilterFuncSGIS"))
			 && (glTexFilterFuncSGIS = (PFNGLTEXFILTERFUNCSGISPROC)SDL_GL_GetProcAddress("glTexFilterFuncSGIS"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIS_texture_filter4 fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIS_texture_filter4 fails." << endl;
			}
		}
	}
	bool have_SGIS_texture_filter4() {
		return loaded;
	}
	void GL_SGIS_texture_filter4_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIS_texture_filter4_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIS_texture_filter4_NAMESPACE

//  ...for GL_SGIS_texture_lod:
namespace GL_SGIS_texture_lod_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIS_texture_lod fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIS_texture_lod fails." << endl;
			}
		}
	}
	bool have_SGIS_texture_lod() {
		return loaded;
	}
	void GL_SGIS_texture_lod_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIS_texture_lod_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIS_texture_lod_NAMESPACE

//  ...for GL_SGIS_texture_select:
namespace GL_SGIS_texture_select_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIS_texture_select fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIS_texture_select fails." << endl;
			}
		}
	}
	bool have_SGIS_texture_select() {
		return loaded;
	}
	void GL_SGIS_texture_select_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIS_texture_select_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIS_texture_select_NAMESPACE

//  ...for GL_SGIX_async:
namespace GL_SGIX_async_NAMESPACE {
PFNGLASYNCMARKERSGIXPROC glAsyncMarkerSGIX = NULL;
PFNGLDELETEASYNCMARKERSSGIXPROC glDeleteAsyncMarkersSGIX = NULL;
PFNGLFINISHASYNCSGIXPROC glFinishAsyncSGIX = NULL;
PFNGLGENASYNCMARKERSSGIXPROC glGenAsyncMarkersSGIX = NULL;
PFNGLISASYNCMARKERSGIXPROC glIsAsyncMarkerSGIX = NULL;
PFNGLPOLLASYNCSGIXPROC glPollAsyncSGIX = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glAsyncMarkerSGIX = (PFNGLASYNCMARKERSGIXPROC)SDL_GL_GetProcAddress("glAsyncMarkerSGIX"))
			 && (glDeleteAsyncMarkersSGIX = (PFNGLDELETEASYNCMARKERSSGIXPROC)SDL_GL_GetProcAddress("glDeleteAsyncMarkersSGIX"))
			 && (glFinishAsyncSGIX = (PFNGLFINISHASYNCSGIXPROC)SDL_GL_GetProcAddress("glFinishAsyncSGIX"))
			 && (glGenAsyncMarkersSGIX = (PFNGLGENASYNCMARKERSSGIXPROC)SDL_GL_GetProcAddress("glGenAsyncMarkersSGIX"))
			 && (glIsAsyncMarkerSGIX = (PFNGLISASYNCMARKERSGIXPROC)SDL_GL_GetProcAddress("glIsAsyncMarkerSGIX"))
			 && (glPollAsyncSGIX = (PFNGLPOLLASYNCSGIXPROC)SDL_GL_GetProcAddress("glPollAsyncSGIX"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_async fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_async fails." << endl;
			}
		}
	}
	bool have_SGIX_async() {
		return loaded;
	}
	void GL_SGIX_async_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_async_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_async_NAMESPACE

//  ...for GL_SGIX_async_histogram:
namespace GL_SGIX_async_histogram_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_async_histogram fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_async_histogram fails." << endl;
			}
		}
	}
	bool have_SGIX_async_histogram() {
		return loaded;
	}
	void GL_SGIX_async_histogram_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_async_histogram_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_async_histogram_NAMESPACE

//  ...for GL_SGIX_async_pixel:
namespace GL_SGIX_async_pixel_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_async_pixel fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_async_pixel fails." << endl;
			}
		}
	}
	bool have_SGIX_async_pixel() {
		return loaded;
	}
	void GL_SGIX_async_pixel_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_async_pixel_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_async_pixel_NAMESPACE

//  ...for GL_SGIX_blend_alpha_minmax:
namespace GL_SGIX_blend_alpha_minmax_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_blend_alpha_minmax fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_blend_alpha_minmax fails." << endl;
			}
		}
	}
	bool have_SGIX_blend_alpha_minmax() {
		return loaded;
	}
	void GL_SGIX_blend_alpha_minmax_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_blend_alpha_minmax_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_blend_alpha_minmax_NAMESPACE

//  ...for GL_SGIX_calligraphic_fragment:
namespace GL_SGIX_calligraphic_fragment_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_calligraphic_fragment fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_calligraphic_fragment fails." << endl;
			}
		}
	}
	bool have_SGIX_calligraphic_fragment() {
		return loaded;
	}
	void GL_SGIX_calligraphic_fragment_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_calligraphic_fragment_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_calligraphic_fragment_NAMESPACE

//  ...for GL_SGIX_clipmap:
namespace GL_SGIX_clipmap_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_clipmap fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_clipmap fails." << endl;
			}
		}
	}
	bool have_SGIX_clipmap() {
		return loaded;
	}
	void GL_SGIX_clipmap_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_clipmap_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_clipmap_NAMESPACE

//  ...for GL_SGIX_convolution_accuracy:
namespace GL_SGIX_convolution_accuracy_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_convolution_accuracy fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_convolution_accuracy fails." << endl;
			}
		}
	}
	bool have_SGIX_convolution_accuracy() {
		return loaded;
	}
	void GL_SGIX_convolution_accuracy_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_convolution_accuracy_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_convolution_accuracy_NAMESPACE

//  ...for GL_SGIX_depth_pass_instrument:
namespace GL_SGIX_depth_pass_instrument_NAMESPACE {
PFNGLTBUFFERMASK3DFXPROC glTbufferMask3DFX = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glTbufferMask3DFX = (PFNGLTBUFFERMASK3DFXPROC)SDL_GL_GetProcAddress("glTbufferMask3DFX"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_depth_pass_instrument fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_depth_pass_instrument fails." << endl;
			}
		}
	}
	bool have_SGIX_depth_pass_instrument() {
		return loaded;
	}
	void GL_SGIX_depth_pass_instrument_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_depth_pass_instrument_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_depth_pass_instrument_NAMESPACE

//  ...for GL_SGIX_depth_texture:
namespace GL_SGIX_depth_texture_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_depth_texture fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_depth_texture fails." << endl;
			}
		}
	}
	bool have_SGIX_depth_texture() {
		return loaded;
	}
	void GL_SGIX_depth_texture_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_depth_texture_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_depth_texture_NAMESPACE

//  ...for GL_SGIX_flush_raster:
namespace GL_SGIX_flush_raster_NAMESPACE {
PFNGLFLUSHRASTERSGIXPROC glFlushRasterSGIX = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glFlushRasterSGIX = (PFNGLFLUSHRASTERSGIXPROC)SDL_GL_GetProcAddress("glFlushRasterSGIX"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_flush_raster fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_flush_raster fails." << endl;
			}
		}
	}
	bool have_SGIX_flush_raster() {
		return loaded;
	}
	void GL_SGIX_flush_raster_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_flush_raster_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_flush_raster_NAMESPACE

//  ...for GL_SGIX_fog_offset:
namespace GL_SGIX_fog_offset_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_fog_offset fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_fog_offset fails." << endl;
			}
		}
	}
	bool have_SGIX_fog_offset() {
		return loaded;
	}
	void GL_SGIX_fog_offset_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_fog_offset_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_fog_offset_NAMESPACE

//  ...for GL_SGIX_fog_scale:
namespace GL_SGIX_fog_scale_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_fog_scale fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_fog_scale fails." << endl;
			}
		}
	}
	bool have_SGIX_fog_scale() {
		return loaded;
	}
	void GL_SGIX_fog_scale_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_fog_scale_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_fog_scale_NAMESPACE

//  ...for GL_SGIX_fragment_lighting:
namespace GL_SGIX_fragment_lighting_NAMESPACE {
PFNGLFRAGMENTCOLORMATERIALSGIXPROC glFragmentColorMaterialSGIX = NULL;
PFNGLFRAGMENTLIGHTFSGIXPROC glFragmentLightfSGIX = NULL;
PFNGLFRAGMENTLIGHTFVSGIXPROC glFragmentLightfvSGIX = NULL;
PFNGLFRAGMENTLIGHTISGIXPROC glFragmentLightiSGIX = NULL;
PFNGLFRAGMENTLIGHTIVSGIXPROC glFragmentLightivSGIX = NULL;
PFNGLFRAGMENTLIGHTMODELFSGIXPROC glFragmentLightModelfSGIX = NULL;
PFNGLFRAGMENTLIGHTMODELFVSGIXPROC glFragmentLightModelfvSGIX = NULL;
PFNGLFRAGMENTLIGHTMODELISGIXPROC glFragmentLightModeliSGIX = NULL;
PFNGLFRAGMENTLIGHTMODELIVSGIXPROC glFragmentLightModelivSGIX = NULL;
PFNGLFRAGMENTMATERIALFSGIXPROC glFragmentMaterialfSGIX = NULL;
PFNGLFRAGMENTMATERIALFVSGIXPROC glFragmentMaterialfvSGIX = NULL;
PFNGLFRAGMENTMATERIALISGIXPROC glFragmentMaterialiSGIX = NULL;
PFNGLFRAGMENTMATERIALIVSGIXPROC glFragmentMaterialivSGIX = NULL;
PFNGLGETFRAGMENTLIGHTFVSGIXPROC glGetFragmentLightfvSGIX = NULL;
PFNGLGETFRAGMENTLIGHTIVSGIXPROC glGetFragmentLightivSGIX = NULL;
PFNGLGETFRAGMENTMATERIALFVSGIXPROC glGetFragmentMaterialfvSGIX = NULL;
PFNGLGETFRAGMENTMATERIALIVSGIXPROC glGetFragmentMaterialivSGIX = NULL;
PFNGLLIGHTENVISGIXPROC glLightEnviSGIX = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glFragmentColorMaterialSGIX = (PFNGLFRAGMENTCOLORMATERIALSGIXPROC)SDL_GL_GetProcAddress("glFragmentColorMaterialSGIX"))
			 && (glFragmentLightfSGIX = (PFNGLFRAGMENTLIGHTFSGIXPROC)SDL_GL_GetProcAddress("glFragmentLightfSGIX"))
			 && (glFragmentLightfvSGIX = (PFNGLFRAGMENTLIGHTFVSGIXPROC)SDL_GL_GetProcAddress("glFragmentLightfvSGIX"))
			 && (glFragmentLightiSGIX = (PFNGLFRAGMENTLIGHTISGIXPROC)SDL_GL_GetProcAddress("glFragmentLightiSGIX"))
			 && (glFragmentLightivSGIX = (PFNGLFRAGMENTLIGHTIVSGIXPROC)SDL_GL_GetProcAddress("glFragmentLightivSGIX"))
			 && (glFragmentLightModelfSGIX = (PFNGLFRAGMENTLIGHTMODELFSGIXPROC)SDL_GL_GetProcAddress("glFragmentLightModelfSGIX"))
			 && (glFragmentLightModelfvSGIX = (PFNGLFRAGMENTLIGHTMODELFVSGIXPROC)SDL_GL_GetProcAddress("glFragmentLightModelfvSGIX"))
			 && (glFragmentLightModeliSGIX = (PFNGLFRAGMENTLIGHTMODELISGIXPROC)SDL_GL_GetProcAddress("glFragmentLightModeliSGIX"))
			 && (glFragmentLightModelivSGIX = (PFNGLFRAGMENTLIGHTMODELIVSGIXPROC)SDL_GL_GetProcAddress("glFragmentLightModelivSGIX"))
			 && (glFragmentMaterialfSGIX = (PFNGLFRAGMENTMATERIALFSGIXPROC)SDL_GL_GetProcAddress("glFragmentMaterialfSGIX"))
			 && (glFragmentMaterialfvSGIX = (PFNGLFRAGMENTMATERIALFVSGIXPROC)SDL_GL_GetProcAddress("glFragmentMaterialfvSGIX"))
			 && (glFragmentMaterialiSGIX = (PFNGLFRAGMENTMATERIALISGIXPROC)SDL_GL_GetProcAddress("glFragmentMaterialiSGIX"))
			 && (glFragmentMaterialivSGIX = (PFNGLFRAGMENTMATERIALIVSGIXPROC)SDL_GL_GetProcAddress("glFragmentMaterialivSGIX"))
			 && (glGetFragmentLightfvSGIX = (PFNGLGETFRAGMENTLIGHTFVSGIXPROC)SDL_GL_GetProcAddress("glGetFragmentLightfvSGIX"))
			 && (glGetFragmentLightivSGIX = (PFNGLGETFRAGMENTLIGHTIVSGIXPROC)SDL_GL_GetProcAddress("glGetFragmentLightivSGIX"))
			 && (glGetFragmentMaterialfvSGIX = (PFNGLGETFRAGMENTMATERIALFVSGIXPROC)SDL_GL_GetProcAddress("glGetFragmentMaterialfvSGIX"))
			 && (glGetFragmentMaterialivSGIX = (PFNGLGETFRAGMENTMATERIALIVSGIXPROC)SDL_GL_GetProcAddress("glGetFragmentMaterialivSGIX"))
			 && (glLightEnviSGIX = (PFNGLLIGHTENVISGIXPROC)SDL_GL_GetProcAddress("glLightEnviSGIX"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_fragment_lighting fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_fragment_lighting fails." << endl;
			}
		}
	}
	bool have_SGIX_fragment_lighting() {
		return loaded;
	}
	void GL_SGIX_fragment_lighting_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_fragment_lighting_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_fragment_lighting_NAMESPACE

//  ...for GL_SGIX_framezoom:
namespace GL_SGIX_framezoom_NAMESPACE {
PFNGLFRAMEZOOMSGIXPROC glFrameZoomSGIX = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glFrameZoomSGIX = (PFNGLFRAMEZOOMSGIXPROC)SDL_GL_GetProcAddress("glFrameZoomSGIX"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_framezoom fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_framezoom fails." << endl;
			}
		}
	}
	bool have_SGIX_framezoom() {
		return loaded;
	}
	void GL_SGIX_framezoom_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_framezoom_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_framezoom_NAMESPACE

//  ...for GL_SGIX_igloo_interface:
namespace GL_SGIX_igloo_interface_NAMESPACE {
PFNGLIGLOOINTERFACESGIXPROC glIglooInterfaceSGIX = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glIglooInterfaceSGIX = (PFNGLIGLOOINTERFACESGIXPROC)SDL_GL_GetProcAddress("glIglooInterfaceSGIX"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_igloo_interface fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_igloo_interface fails." << endl;
			}
		}
	}
	bool have_SGIX_igloo_interface() {
		return loaded;
	}
	void GL_SGIX_igloo_interface_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_igloo_interface_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_igloo_interface_NAMESPACE

//  ...for GL_SGIX_impact_pixel_texture:
namespace GL_SGIX_impact_pixel_texture_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_impact_pixel_texture fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_impact_pixel_texture fails." << endl;
			}
		}
	}
	bool have_SGIX_impact_pixel_texture() {
		return loaded;
	}
	void GL_SGIX_impact_pixel_texture_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_impact_pixel_texture_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_impact_pixel_texture_NAMESPACE

//  ...for GL_SGIX_instruments:
namespace GL_SGIX_instruments_NAMESPACE {
PFNGLGETINSTRUMENTSSGIXPROC glGetInstrumentsSGIX = NULL;
PFNGLINSTRUMENTSBUFFERSGIXPROC glInstrumentsBufferSGIX = NULL;
PFNGLPOLLINSTRUMENTSSGIXPROC glPollInstrumentsSGIX = NULL;
PFNGLREADINSTRUMENTSSGIXPROC glReadInstrumentsSGIX = NULL;
PFNGLSTARTINSTRUMENTSSGIXPROC glStartInstrumentsSGIX = NULL;
PFNGLSTOPINSTRUMENTSSGIXPROC glStopInstrumentsSGIX = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glGetInstrumentsSGIX = (PFNGLGETINSTRUMENTSSGIXPROC)SDL_GL_GetProcAddress("glGetInstrumentsSGIX"))
			 && (glInstrumentsBufferSGIX = (PFNGLINSTRUMENTSBUFFERSGIXPROC)SDL_GL_GetProcAddress("glInstrumentsBufferSGIX"))
			 && (glPollInstrumentsSGIX = (PFNGLPOLLINSTRUMENTSSGIXPROC)SDL_GL_GetProcAddress("glPollInstrumentsSGIX"))
			 && (glReadInstrumentsSGIX = (PFNGLREADINSTRUMENTSSGIXPROC)SDL_GL_GetProcAddress("glReadInstrumentsSGIX"))
			 && (glStartInstrumentsSGIX = (PFNGLSTARTINSTRUMENTSSGIXPROC)SDL_GL_GetProcAddress("glStartInstrumentsSGIX"))
			 && (glStopInstrumentsSGIX = (PFNGLSTOPINSTRUMENTSSGIXPROC)SDL_GL_GetProcAddress("glStopInstrumentsSGIX"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_instruments fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_instruments fails." << endl;
			}
		}
	}
	bool have_SGIX_instruments() {
		return loaded;
	}
	void GL_SGIX_instruments_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_instruments_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_instruments_NAMESPACE

//  ...for GL_SGIX_interlace:
namespace GL_SGIX_interlace_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_interlace fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_interlace fails." << endl;
			}
		}
	}
	bool have_SGIX_interlace() {
		return loaded;
	}
	void GL_SGIX_interlace_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_interlace_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_interlace_NAMESPACE

//  ...for GL_SGIX_ir_instrument1:
namespace GL_SGIX_ir_instrument1_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_ir_instrument1 fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_ir_instrument1 fails." << endl;
			}
		}
	}
	bool have_SGIX_ir_instrument1() {
		return loaded;
	}
	void GL_SGIX_ir_instrument1_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_ir_instrument1_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_ir_instrument1_NAMESPACE

//  ...for GL_SGIX_list_priority:
namespace GL_SGIX_list_priority_NAMESPACE {
PFNGLGETLISTPARAMETERFVSGIXPROC glGetListParameterfvSGIX = NULL;
PFNGLGETLISTPARAMETERIVSGIXPROC glGetListParameterivSGIX = NULL;
PFNGLLISTPARAMETERFSGIXPROC glListParameterfSGIX = NULL;
PFNGLLISTPARAMETERFVSGIXPROC glListParameterfvSGIX = NULL;
PFNGLLISTPARAMETERISGIXPROC glListParameteriSGIX = NULL;
PFNGLLISTPARAMETERIVSGIXPROC glListParameterivSGIX = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glGetListParameterfvSGIX = (PFNGLGETLISTPARAMETERFVSGIXPROC)SDL_GL_GetProcAddress("glGetListParameterfvSGIX"))
			 && (glGetListParameterivSGIX = (PFNGLGETLISTPARAMETERIVSGIXPROC)SDL_GL_GetProcAddress("glGetListParameterivSGIX"))
			 && (glListParameterfSGIX = (PFNGLLISTPARAMETERFSGIXPROC)SDL_GL_GetProcAddress("glListParameterfSGIX"))
			 && (glListParameterfvSGIX = (PFNGLLISTPARAMETERFVSGIXPROC)SDL_GL_GetProcAddress("glListParameterfvSGIX"))
			 && (glListParameteriSGIX = (PFNGLLISTPARAMETERISGIXPROC)SDL_GL_GetProcAddress("glListParameteriSGIX"))
			 && (glListParameterivSGIX = (PFNGLLISTPARAMETERIVSGIXPROC)SDL_GL_GetProcAddress("glListParameterivSGIX"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_list_priority fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_list_priority fails." << endl;
			}
		}
	}
	bool have_SGIX_list_priority() {
		return loaded;
	}
	void GL_SGIX_list_priority_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_list_priority_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_list_priority_NAMESPACE

//  ...for GL_SGIX_pixel_texture:
namespace GL_SGIX_pixel_texture_NAMESPACE {
PFNGLPIXELTEXGENSGIXPROC glPixelTexGenSGIX = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glPixelTexGenSGIX = (PFNGLPIXELTEXGENSGIXPROC)SDL_GL_GetProcAddress("glPixelTexGenSGIX"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_pixel_texture fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_pixel_texture fails." << endl;
			}
		}
	}
	bool have_SGIX_pixel_texture() {
		return loaded;
	}
	void GL_SGIX_pixel_texture_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_pixel_texture_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_pixel_texture_NAMESPACE

//  ...for GL_SGIX_pixel_tiles:
namespace GL_SGIX_pixel_tiles_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_pixel_tiles fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_pixel_tiles fails." << endl;
			}
		}
	}
	bool have_SGIX_pixel_tiles() {
		return loaded;
	}
	void GL_SGIX_pixel_tiles_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_pixel_tiles_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_pixel_tiles_NAMESPACE

//  ...for GL_SGIX_polynomial_ffd:
namespace GL_SGIX_polynomial_ffd_NAMESPACE {
PFNGLDEFORMATIONMAP3DSGIXPROC glDeformationMap3dSGIX = NULL;
PFNGLDEFORMATIONMAP3FSGIXPROC glDeformationMap3fSGIX = NULL;
PFNGLDEFORMSGIXPROC glDeformSGIX = NULL;
PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC glLoadIdentityDeformationMapSGIX = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glDeformationMap3dSGIX = (PFNGLDEFORMATIONMAP3DSGIXPROC)SDL_GL_GetProcAddress("glDeformationMap3dSGIX"))
			 && (glDeformationMap3fSGIX = (PFNGLDEFORMATIONMAP3FSGIXPROC)SDL_GL_GetProcAddress("glDeformationMap3fSGIX"))
			 && (glDeformSGIX = (PFNGLDEFORMSGIXPROC)SDL_GL_GetProcAddress("glDeformSGIX"))
			 && (glLoadIdentityDeformationMapSGIX = (PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC)SDL_GL_GetProcAddress("glLoadIdentityDeformationMapSGIX"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_polynomial_ffd fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_polynomial_ffd fails." << endl;
			}
		}
	}
	bool have_SGIX_polynomial_ffd() {
		return loaded;
	}
	void GL_SGIX_polynomial_ffd_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_polynomial_ffd_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_polynomial_ffd_NAMESPACE

//  ...for GL_SGIX_reference_plane:
namespace GL_SGIX_reference_plane_NAMESPACE {
PFNGLREFERENCEPLANESGIXPROC glReferencePlaneSGIX = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glReferencePlaneSGIX = (PFNGLREFERENCEPLANESGIXPROC)SDL_GL_GetProcAddress("glReferencePlaneSGIX"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_reference_plane fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_reference_plane fails." << endl;
			}
		}
	}
	bool have_SGIX_reference_plane() {
		return loaded;
	}
	void GL_SGIX_reference_plane_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_reference_plane_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_reference_plane_NAMESPACE

//  ...for GL_SGIX_resample:
namespace GL_SGIX_resample_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_resample fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_resample fails." << endl;
			}
		}
	}
	bool have_SGIX_resample() {
		return loaded;
	}
	void GL_SGIX_resample_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_resample_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_resample_NAMESPACE

//  ...for GL_SGIX_scalebias_hint:
namespace GL_SGIX_scalebias_hint_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_scalebias_hint fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_scalebias_hint fails." << endl;
			}
		}
	}
	bool have_SGIX_scalebias_hint() {
		return loaded;
	}
	void GL_SGIX_scalebias_hint_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_scalebias_hint_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_scalebias_hint_NAMESPACE

//  ...for GL_SGIX_shadow:
namespace GL_SGIX_shadow_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_shadow fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_shadow fails." << endl;
			}
		}
	}
	bool have_SGIX_shadow() {
		return loaded;
	}
	void GL_SGIX_shadow_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_shadow_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_shadow_NAMESPACE

//  ...for GL_SGIX_shadow_ambient:
namespace GL_SGIX_shadow_ambient_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_shadow_ambient fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_shadow_ambient fails." << endl;
			}
		}
	}
	bool have_SGIX_shadow_ambient() {
		return loaded;
	}
	void GL_SGIX_shadow_ambient_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_shadow_ambient_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_shadow_ambient_NAMESPACE

//  ...for GL_SGIX_sprite:
namespace GL_SGIX_sprite_NAMESPACE {
PFNGLSPRITEPARAMETERFSGIXPROC glSpriteParameterfSGIX = NULL;
PFNGLSPRITEPARAMETERFVSGIXPROC glSpriteParameterfvSGIX = NULL;
PFNGLSPRITEPARAMETERISGIXPROC glSpriteParameteriSGIX = NULL;
PFNGLSPRITEPARAMETERIVSGIXPROC glSpriteParameterivSGIX = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glSpriteParameterfSGIX = (PFNGLSPRITEPARAMETERFSGIXPROC)SDL_GL_GetProcAddress("glSpriteParameterfSGIX"))
			 && (glSpriteParameterfvSGIX = (PFNGLSPRITEPARAMETERFVSGIXPROC)SDL_GL_GetProcAddress("glSpriteParameterfvSGIX"))
			 && (glSpriteParameteriSGIX = (PFNGLSPRITEPARAMETERISGIXPROC)SDL_GL_GetProcAddress("glSpriteParameteriSGIX"))
			 && (glSpriteParameterivSGIX = (PFNGLSPRITEPARAMETERIVSGIXPROC)SDL_GL_GetProcAddress("glSpriteParameterivSGIX"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_sprite fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_sprite fails." << endl;
			}
		}
	}
	bool have_SGIX_sprite() {
		return loaded;
	}
	void GL_SGIX_sprite_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_sprite_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_sprite_NAMESPACE

//  ...for GL_SGIX_subsample:
namespace GL_SGIX_subsample_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_subsample fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_subsample fails." << endl;
			}
		}
	}
	bool have_SGIX_subsample() {
		return loaded;
	}
	void GL_SGIX_subsample_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_subsample_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_subsample_NAMESPACE

//  ...for GL_SGIX_tag_sample_buffer:
namespace GL_SGIX_tag_sample_buffer_NAMESPACE {
PFNGLTAGSAMPLEBUFFERSGIXPROC glTagSampleBufferSGIX = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glTagSampleBufferSGIX = (PFNGLTAGSAMPLEBUFFERSGIXPROC)SDL_GL_GetProcAddress("glTagSampleBufferSGIX"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_tag_sample_buffer fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_tag_sample_buffer fails." << endl;
			}
		}
	}
	bool have_SGIX_tag_sample_buffer() {
		return loaded;
	}
	void GL_SGIX_tag_sample_buffer_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_tag_sample_buffer_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_tag_sample_buffer_NAMESPACE

//  ...for GL_SGIX_texture_add_env:
namespace GL_SGIX_texture_add_env_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_texture_add_env fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_texture_add_env fails." << endl;
			}
		}
	}
	bool have_SGIX_texture_add_env() {
		return loaded;
	}
	void GL_SGIX_texture_add_env_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_texture_add_env_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_texture_add_env_NAMESPACE

//  ...for GL_SGIX_texture_coordinate_clamp:
namespace GL_SGIX_texture_coordinate_clamp_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_texture_coordinate_clamp fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_texture_coordinate_clamp fails." << endl;
			}
		}
	}
	bool have_SGIX_texture_coordinate_clamp() {
		return loaded;
	}
	void GL_SGIX_texture_coordinate_clamp_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_texture_coordinate_clamp_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_texture_coordinate_clamp_NAMESPACE

//  ...for GL_SGIX_texture_lod_bias:
namespace GL_SGIX_texture_lod_bias_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_texture_lod_bias fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_texture_lod_bias fails." << endl;
			}
		}
	}
	bool have_SGIX_texture_lod_bias() {
		return loaded;
	}
	void GL_SGIX_texture_lod_bias_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_texture_lod_bias_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_texture_lod_bias_NAMESPACE

//  ...for GL_SGIX_texture_multi_buffer:
namespace GL_SGIX_texture_multi_buffer_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_texture_multi_buffer fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_texture_multi_buffer fails." << endl;
			}
		}
	}
	bool have_SGIX_texture_multi_buffer() {
		return loaded;
	}
	void GL_SGIX_texture_multi_buffer_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_texture_multi_buffer_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_texture_multi_buffer_NAMESPACE

//  ...for GL_SGIX_texture_scale_bias:
namespace GL_SGIX_texture_scale_bias_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_texture_scale_bias fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_texture_scale_bias fails." << endl;
			}
		}
	}
	bool have_SGIX_texture_scale_bias() {
		return loaded;
	}
	void GL_SGIX_texture_scale_bias_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_texture_scale_bias_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_texture_scale_bias_NAMESPACE

//  ...for GL_SGIX_texture_select:
namespace GL_SGIX_texture_select_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_texture_select fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_texture_select fails." << endl;
			}
		}
	}
	bool have_SGIX_texture_select() {
		return loaded;
	}
	void GL_SGIX_texture_select_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_texture_select_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_texture_select_NAMESPACE

//  ...for GL_SGIX_vertex_preclip:
namespace GL_SGIX_vertex_preclip_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_vertex_preclip fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_vertex_preclip fails." << endl;
			}
		}
	}
	bool have_SGIX_vertex_preclip() {
		return loaded;
	}
	void GL_SGIX_vertex_preclip_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_vertex_preclip_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_vertex_preclip_NAMESPACE

//  ...for GL_SGIX_ycrcb:
namespace GL_SGIX_ycrcb_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_ycrcb fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_ycrcb fails." << endl;
			}
		}
	}
	bool have_SGIX_ycrcb() {
		return loaded;
	}
	void GL_SGIX_ycrcb_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_ycrcb_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_ycrcb_NAMESPACE

//  ...for GL_SGIX_ycrcb_subsample:
namespace GL_SGIX_ycrcb_subsample_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_ycrcb_subsample fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_ycrcb_subsample fails." << endl;
			}
		}
	}
	bool have_SGIX_ycrcb_subsample() {
		return loaded;
	}
	void GL_SGIX_ycrcb_subsample_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_ycrcb_subsample_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_ycrcb_subsample_NAMESPACE

//  ...for GL_SGIX_ycrcba:
namespace GL_SGIX_ycrcba_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGIX_ycrcba fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGIX_ycrcba fails." << endl;
			}
		}
	}
	bool have_SGIX_ycrcba() {
		return loaded;
	}
	void GL_SGIX_ycrcba_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGIX_ycrcba_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGIX_ycrcba_NAMESPACE

//  ...for GL_SGI_color_matrix:
namespace GL_SGI_color_matrix_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGI_color_matrix fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGI_color_matrix fails." << endl;
			}
		}
	}
	bool have_SGI_color_matrix() {
		return loaded;
	}
	void GL_SGI_color_matrix_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGI_color_matrix_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGI_color_matrix_NAMESPACE

//  ...for GL_SGI_color_table:
namespace GL_SGI_color_table_NAMESPACE {
PFNGLCOLORTABLEPARAMETERFVSGIPROC glColorTableParameterfvSGI = NULL;
PFNGLCOLORTABLEPARAMETERIVSGIPROC glColorTableParameterivSGI = NULL;
PFNGLCOLORTABLESGIPROC glColorTableSGI = NULL;
PFNGLCOPYCOLORTABLESGIPROC glCopyColorTableSGI = NULL;
PFNGLGETCOLORTABLEPARAMETERFVSGIPROC glGetColorTableParameterfvSGI = NULL;
PFNGLGETCOLORTABLEPARAMETERIVSGIPROC glGetColorTableParameterivSGI = NULL;
PFNGLGETCOLORTABLESGIPROC glGetColorTableSGI = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glColorTableParameterfvSGI = (PFNGLCOLORTABLEPARAMETERFVSGIPROC)SDL_GL_GetProcAddress("glColorTableParameterfvSGI"))
			 && (glColorTableParameterivSGI = (PFNGLCOLORTABLEPARAMETERIVSGIPROC)SDL_GL_GetProcAddress("glColorTableParameterivSGI"))
			 && (glColorTableSGI = (PFNGLCOLORTABLESGIPROC)SDL_GL_GetProcAddress("glColorTableSGI"))
			 && (glCopyColorTableSGI = (PFNGLCOPYCOLORTABLESGIPROC)SDL_GL_GetProcAddress("glCopyColorTableSGI"))
			 && (glGetColorTableParameterfvSGI = (PFNGLGETCOLORTABLEPARAMETERFVSGIPROC)SDL_GL_GetProcAddress("glGetColorTableParameterfvSGI"))
			 && (glGetColorTableParameterivSGI = (PFNGLGETCOLORTABLEPARAMETERIVSGIPROC)SDL_GL_GetProcAddress("glGetColorTableParameterivSGI"))
			 && (glGetColorTableSGI = (PFNGLGETCOLORTABLESGIPROC)SDL_GL_GetProcAddress("glGetColorTableSGI"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGI_color_table fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGI_color_table fails." << endl;
			}
		}
	}
	bool have_SGI_color_table() {
		return loaded;
	}
	void GL_SGI_color_table_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGI_color_table_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGI_color_table_NAMESPACE

//  ...for GL_SGI_depth_pass_instrument:
namespace GL_SGI_depth_pass_instrument_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGI_depth_pass_instrument fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGI_depth_pass_instrument fails." << endl;
			}
		}
	}
	bool have_SGI_depth_pass_instrument() {
		return loaded;
	}
	void GL_SGI_depth_pass_instrument_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGI_depth_pass_instrument_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGI_depth_pass_instrument_NAMESPACE

//  ...for GL_SGI_texture_color_table:
namespace GL_SGI_texture_color_table_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SGI_texture_color_table fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SGI_texture_color_table fails." << endl;
			}
		}
	}
	bool have_SGI_texture_color_table() {
		return loaded;
	}
	void GL_SGI_texture_color_table_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SGI_texture_color_table_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SGI_texture_color_table_NAMESPACE

//  ...for GL_SUNX_constant_data:
namespace GL_SUNX_constant_data_NAMESPACE {
PFNGLFINISHTEXTURESUNXPROC glFinishTextureSUNX = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glFinishTextureSUNX = (PFNGLFINISHTEXTURESUNXPROC)SDL_GL_GetProcAddress("glFinishTextureSUNX"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SUNX_constant_data fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SUNX_constant_data fails." << endl;
			}
		}
	}
	bool have_SUNX_constant_data() {
		return loaded;
	}
	void GL_SUNX_constant_data_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SUNX_constant_data_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SUNX_constant_data_NAMESPACE

//  ...for GL_SUN_convolution_border_modes:
namespace GL_SUN_convolution_border_modes_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SUN_convolution_border_modes fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SUN_convolution_border_modes fails." << endl;
			}
		}
	}
	bool have_SUN_convolution_border_modes() {
		return loaded;
	}
	void GL_SUN_convolution_border_modes_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SUN_convolution_border_modes_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SUN_convolution_border_modes_NAMESPACE

//  ...for GL_SUN_global_alpha:
namespace GL_SUN_global_alpha_NAMESPACE {
PFNGLGLOBALALPHAFACTORBSUNPROC glGlobalAlphaFactorbSUN = NULL;
PFNGLGLOBALALPHAFACTORDSUNPROC glGlobalAlphaFactordSUN = NULL;
PFNGLGLOBALALPHAFACTORFSUNPROC glGlobalAlphaFactorfSUN = NULL;
PFNGLGLOBALALPHAFACTORISUNPROC glGlobalAlphaFactoriSUN = NULL;
PFNGLGLOBALALPHAFACTORSSUNPROC glGlobalAlphaFactorsSUN = NULL;
PFNGLGLOBALALPHAFACTORUBSUNPROC glGlobalAlphaFactorubSUN = NULL;
PFNGLGLOBALALPHAFACTORUISUNPROC glGlobalAlphaFactoruiSUN = NULL;
PFNGLGLOBALALPHAFACTORUSSUNPROC glGlobalAlphaFactorusSUN = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glGlobalAlphaFactorbSUN = (PFNGLGLOBALALPHAFACTORBSUNPROC)SDL_GL_GetProcAddress("glGlobalAlphaFactorbSUN"))
			 && (glGlobalAlphaFactordSUN = (PFNGLGLOBALALPHAFACTORDSUNPROC)SDL_GL_GetProcAddress("glGlobalAlphaFactordSUN"))
			 && (glGlobalAlphaFactorfSUN = (PFNGLGLOBALALPHAFACTORFSUNPROC)SDL_GL_GetProcAddress("glGlobalAlphaFactorfSUN"))
			 && (glGlobalAlphaFactoriSUN = (PFNGLGLOBALALPHAFACTORISUNPROC)SDL_GL_GetProcAddress("glGlobalAlphaFactoriSUN"))
			 && (glGlobalAlphaFactorsSUN = (PFNGLGLOBALALPHAFACTORSSUNPROC)SDL_GL_GetProcAddress("glGlobalAlphaFactorsSUN"))
			 && (glGlobalAlphaFactorubSUN = (PFNGLGLOBALALPHAFACTORUBSUNPROC)SDL_GL_GetProcAddress("glGlobalAlphaFactorubSUN"))
			 && (glGlobalAlphaFactoruiSUN = (PFNGLGLOBALALPHAFACTORUISUNPROC)SDL_GL_GetProcAddress("glGlobalAlphaFactoruiSUN"))
			 && (glGlobalAlphaFactorusSUN = (PFNGLGLOBALALPHAFACTORUSSUNPROC)SDL_GL_GetProcAddress("glGlobalAlphaFactorusSUN"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SUN_global_alpha fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SUN_global_alpha fails." << endl;
			}
		}
	}
	bool have_SUN_global_alpha() {
		return loaded;
	}
	void GL_SUN_global_alpha_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SUN_global_alpha_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SUN_global_alpha_NAMESPACE

//  ...for GL_SUN_mesh_array:
namespace GL_SUN_mesh_array_NAMESPACE {
PFNGLDRAWMESHARRAYSSUNPROC glDrawMeshArraysSUN = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glDrawMeshArraysSUN = (PFNGLDRAWMESHARRAYSSUNPROC)SDL_GL_GetProcAddress("glDrawMeshArraysSUN"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SUN_mesh_array fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SUN_mesh_array fails." << endl;
			}
		}
	}
	bool have_SUN_mesh_array() {
		return loaded;
	}
	void GL_SUN_mesh_array_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SUN_mesh_array_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SUN_mesh_array_NAMESPACE

//  ...for GL_SUN_slice_accum:
namespace GL_SUN_slice_accum_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SUN_slice_accum fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SUN_slice_accum fails." << endl;
			}
		}
	}
	bool have_SUN_slice_accum() {
		return loaded;
	}
	void GL_SUN_slice_accum_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SUN_slice_accum_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SUN_slice_accum_NAMESPACE

//  ...for GL_SUN_triangle_list:
namespace GL_SUN_triangle_list_NAMESPACE {
PFNGLREPLACEMENTCODEPOINTERSUNPROC glReplacementCodePointerSUN = NULL;
PFNGLREPLACEMENTCODEUBSUNPROC glReplacementCodeubSUN = NULL;
PFNGLREPLACEMENTCODEUBVSUNPROC glReplacementCodeubvSUN = NULL;
PFNGLREPLACEMENTCODEUISUNPROC glReplacementCodeuiSUN = NULL;
PFNGLREPLACEMENTCODEUIVSUNPROC glReplacementCodeuivSUN = NULL;
PFNGLREPLACEMENTCODEUSSUNPROC glReplacementCodeusSUN = NULL;
PFNGLREPLACEMENTCODEUSVSUNPROC glReplacementCodeusvSUN = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glReplacementCodePointerSUN = (PFNGLREPLACEMENTCODEPOINTERSUNPROC)SDL_GL_GetProcAddress("glReplacementCodePointerSUN"))
			 && (glReplacementCodeubSUN = (PFNGLREPLACEMENTCODEUBSUNPROC)SDL_GL_GetProcAddress("glReplacementCodeubSUN"))
			 && (glReplacementCodeubvSUN = (PFNGLREPLACEMENTCODEUBVSUNPROC)SDL_GL_GetProcAddress("glReplacementCodeubvSUN"))
			 && (glReplacementCodeuiSUN = (PFNGLREPLACEMENTCODEUISUNPROC)SDL_GL_GetProcAddress("glReplacementCodeuiSUN"))
			 && (glReplacementCodeuivSUN = (PFNGLREPLACEMENTCODEUIVSUNPROC)SDL_GL_GetProcAddress("glReplacementCodeuivSUN"))
			 && (glReplacementCodeusSUN = (PFNGLREPLACEMENTCODEUSSUNPROC)SDL_GL_GetProcAddress("glReplacementCodeusSUN"))
			 && (glReplacementCodeusvSUN = (PFNGLREPLACEMENTCODEUSVSUNPROC)SDL_GL_GetProcAddress("glReplacementCodeusvSUN"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SUN_triangle_list fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SUN_triangle_list fails." << endl;
			}
		}
	}
	bool have_SUN_triangle_list() {
		return loaded;
	}
	void GL_SUN_triangle_list_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SUN_triangle_list_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SUN_triangle_list_NAMESPACE

//  ...for GL_SUN_vertex:
namespace GL_SUN_vertex_NAMESPACE {
PFNGLCOLOR3FVERTEX3FSUNPROC glColor3fVertex3fSUN = NULL;
PFNGLCOLOR3FVERTEX3FVSUNPROC glColor3fVertex3fvSUN = NULL;
PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC glColor4fNormal3fVertex3fSUN = NULL;
PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC glColor4fNormal3fVertex3fvSUN = NULL;
PFNGLCOLOR4UBVERTEX2FSUNPROC glColor4ubVertex2fSUN = NULL;
PFNGLCOLOR4UBVERTEX2FVSUNPROC glColor4ubVertex2fvSUN = NULL;
PFNGLCOLOR4UBVERTEX3FSUNPROC glColor4ubVertex3fSUN = NULL;
PFNGLCOLOR4UBVERTEX3FVSUNPROC glColor4ubVertex3fvSUN = NULL;
PFNGLNORMAL3FVERTEX3FSUNPROC glNormal3fVertex3fSUN = NULL;
PFNGLNORMAL3FVERTEX3FVSUNPROC glNormal3fVertex3fvSUN = NULL;
PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC glReplacementCodeuiColor3fVertex3fSUN = NULL;
PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC glReplacementCodeuiColor3fVertex3fvSUN = NULL;
PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC glReplacementCodeuiColor4fNormal3fVertex3fSUN = NULL;
PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiColor4fNormal3fVertex3fvSUN = NULL;
PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC glReplacementCodeuiColor4ubVertex3fSUN = NULL;
PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC glReplacementCodeuiColor4ubVertex3fvSUN = NULL;
PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC glReplacementCodeuiNormal3fVertex3fSUN = NULL;
PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiNormal3fVertex3fvSUN = NULL;
PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN = NULL;
PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN = NULL;
PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN = NULL;
PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN = NULL;
PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC glReplacementCodeuiTexCoord2fVertex3fSUN = NULL;
PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC glReplacementCodeuiTexCoord2fVertex3fvSUN = NULL;
PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC glReplacementCodeuiVertex3fSUN = NULL;
PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC glReplacementCodeuiVertex3fvSUN = NULL;
PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC glTexCoord2fColor3fVertex3fSUN = NULL;
PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC glTexCoord2fColor3fVertex3fvSUN = NULL;
PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC glTexCoord2fColor4fNormal3fVertex3fSUN = NULL;
PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC glTexCoord2fColor4fNormal3fVertex3fvSUN = NULL;
PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC glTexCoord2fColor4ubVertex3fSUN = NULL;
PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC glTexCoord2fColor4ubVertex3fvSUN = NULL;
PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC glTexCoord2fNormal3fVertex3fSUN = NULL;
PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC glTexCoord2fNormal3fVertex3fvSUN = NULL;
PFNGLTEXCOORD2FVERTEX3FSUNPROC glTexCoord2fVertex3fSUN = NULL;
PFNGLTEXCOORD2FVERTEX3FVSUNPROC glTexCoord2fVertex3fvSUN = NULL;
PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC glTexCoord4fColor4fNormal3fVertex4fSUN = NULL;
PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC glTexCoord4fColor4fNormal3fVertex4fvSUN = NULL;
PFNGLTEXCOORD4FVERTEX4FSUNPROC glTexCoord4fVertex4fSUN = NULL;
PFNGLTEXCOORD4FVERTEX4FVSUNPROC glTexCoord4fVertex4fvSUN = NULL;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
			 && (glColor3fVertex3fSUN = (PFNGLCOLOR3FVERTEX3FSUNPROC)SDL_GL_GetProcAddress("glColor3fVertex3fSUN"))
			 && (glColor3fVertex3fvSUN = (PFNGLCOLOR3FVERTEX3FVSUNPROC)SDL_GL_GetProcAddress("glColor3fVertex3fvSUN"))
			 && (glColor4fNormal3fVertex3fSUN = (PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC)SDL_GL_GetProcAddress("glColor4fNormal3fVertex3fSUN"))
			 && (glColor4fNormal3fVertex3fvSUN = (PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC)SDL_GL_GetProcAddress("glColor4fNormal3fVertex3fvSUN"))
			 && (glColor4ubVertex2fSUN = (PFNGLCOLOR4UBVERTEX2FSUNPROC)SDL_GL_GetProcAddress("glColor4ubVertex2fSUN"))
			 && (glColor4ubVertex2fvSUN = (PFNGLCOLOR4UBVERTEX2FVSUNPROC)SDL_GL_GetProcAddress("glColor4ubVertex2fvSUN"))
			 && (glColor4ubVertex3fSUN = (PFNGLCOLOR4UBVERTEX3FSUNPROC)SDL_GL_GetProcAddress("glColor4ubVertex3fSUN"))
			 && (glColor4ubVertex3fvSUN = (PFNGLCOLOR4UBVERTEX3FVSUNPROC)SDL_GL_GetProcAddress("glColor4ubVertex3fvSUN"))
			 && (glNormal3fVertex3fSUN = (PFNGLNORMAL3FVERTEX3FSUNPROC)SDL_GL_GetProcAddress("glNormal3fVertex3fSUN"))
			 && (glNormal3fVertex3fvSUN = (PFNGLNORMAL3FVERTEX3FVSUNPROC)SDL_GL_GetProcAddress("glNormal3fVertex3fvSUN"))
			 && (glReplacementCodeuiColor3fVertex3fSUN = (PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC)SDL_GL_GetProcAddress("glReplacementCodeuiColor3fVertex3fSUN"))
			 && (glReplacementCodeuiColor3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC)SDL_GL_GetProcAddress("glReplacementCodeuiColor3fVertex3fvSUN"))
			 && (glReplacementCodeuiColor4fNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC)SDL_GL_GetProcAddress("glReplacementCodeuiColor4fNormal3fVertex3fSUN"))
			 && (glReplacementCodeuiColor4fNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC)SDL_GL_GetProcAddress("glReplacementCodeuiColor4fNormal3fVertex3fvSUN"))
			 && (glReplacementCodeuiColor4ubVertex3fSUN = (PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC)SDL_GL_GetProcAddress("glReplacementCodeuiColor4ubVertex3fSUN"))
			 && (glReplacementCodeuiColor4ubVertex3fvSUN = (PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC)SDL_GL_GetProcAddress("glReplacementCodeuiColor4ubVertex3fvSUN"))
			 && (glReplacementCodeuiNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC)SDL_GL_GetProcAddress("glReplacementCodeuiNormal3fVertex3fSUN"))
			 && (glReplacementCodeuiNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC)SDL_GL_GetProcAddress("glReplacementCodeuiNormal3fVertex3fvSUN"))
			 && (glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)SDL_GL_GetProcAddress("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN"))
			 && (glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)SDL_GL_GetProcAddress("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN"))
			 && (glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC)SDL_GL_GetProcAddress("glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN"))
			 && (glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)SDL_GL_GetProcAddress("glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN"))
			 && (glReplacementCodeuiTexCoord2fVertex3fSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC)SDL_GL_GetProcAddress("glReplacementCodeuiTexCoord2fVertex3fSUN"))
			 && (glReplacementCodeuiTexCoord2fVertex3fvSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC)SDL_GL_GetProcAddress("glReplacementCodeuiTexCoord2fVertex3fvSUN"))
			 && (glReplacementCodeuiVertex3fSUN = (PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC)SDL_GL_GetProcAddress("glReplacementCodeuiVertex3fSUN"))
			 && (glReplacementCodeuiVertex3fvSUN = (PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC)SDL_GL_GetProcAddress("glReplacementCodeuiVertex3fvSUN"))
			 && (glTexCoord2fColor3fVertex3fSUN = (PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC)SDL_GL_GetProcAddress("glTexCoord2fColor3fVertex3fSUN"))
			 && (glTexCoord2fColor3fVertex3fvSUN = (PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC)SDL_GL_GetProcAddress("glTexCoord2fColor3fVertex3fvSUN"))
			 && (glTexCoord2fColor4fNormal3fVertex3fSUN = (PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)SDL_GL_GetProcAddress("glTexCoord2fColor4fNormal3fVertex3fSUN"))
			 && (glTexCoord2fColor4fNormal3fVertex3fvSUN = (PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)SDL_GL_GetProcAddress("glTexCoord2fColor4fNormal3fVertex3fvSUN"))
			 && (glTexCoord2fColor4ubVertex3fSUN = (PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC)SDL_GL_GetProcAddress("glTexCoord2fColor4ubVertex3fSUN"))
			 && (glTexCoord2fColor4ubVertex3fvSUN = (PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC)SDL_GL_GetProcAddress("glTexCoord2fColor4ubVertex3fvSUN"))
			 && (glTexCoord2fNormal3fVertex3fSUN = (PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC)SDL_GL_GetProcAddress("glTexCoord2fNormal3fVertex3fSUN"))
			 && (glTexCoord2fNormal3fVertex3fvSUN = (PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)SDL_GL_GetProcAddress("glTexCoord2fNormal3fVertex3fvSUN"))
			 && (glTexCoord2fVertex3fSUN = (PFNGLTEXCOORD2FVERTEX3FSUNPROC)SDL_GL_GetProcAddress("glTexCoord2fVertex3fSUN"))
			 && (glTexCoord2fVertex3fvSUN = (PFNGLTEXCOORD2FVERTEX3FVSUNPROC)SDL_GL_GetProcAddress("glTexCoord2fVertex3fvSUN"))
			 && (glTexCoord4fColor4fNormal3fVertex4fSUN = (PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC)SDL_GL_GetProcAddress("glTexCoord4fColor4fNormal3fVertex4fSUN"))
			 && (glTexCoord4fColor4fNormal3fVertex4fvSUN = (PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC)SDL_GL_GetProcAddress("glTexCoord4fColor4fNormal3fVertex4fvSUN"))
			 && (glTexCoord4fVertex4fSUN = (PFNGLTEXCOORD4FVERTEX4FSUNPROC)SDL_GL_GetProcAddress("glTexCoord4fVertex4fSUN"))
			 && (glTexCoord4fVertex4fvSUN = (PFNGLTEXCOORD4FVERTEX4FVSUNPROC)SDL_GL_GetProcAddress("glTexCoord4fVertex4fvSUN"))
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_SUN_vertex fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_SUN_vertex fails." << endl;
			}
		}
	}
	bool have_SUN_vertex() {
		return loaded;
	}
	void GL_SUN_vertex_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_SUN_vertex_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_SUN_vertex_NAMESPACE

//  ...for GL_WIN_phong_shading:
namespace GL_WIN_phong_shading_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_WIN_phong_shading fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_WIN_phong_shading fails." << endl;
			}
		}
	}
	bool have_WIN_phong_shading() {
		return loaded;
	}
	void GL_WIN_phong_shading_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_WIN_phong_shading_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_WIN_phong_shading_NAMESPACE

//  ...for GL_WIN_specular_fog:
namespace GL_WIN_specular_fog_NAMESPACE {
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension GL_WIN_specular_fog fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension GL_WIN_specular_fog fails." << endl;
			}
		}
	}
	bool have_WIN_specular_fog() {
		return loaded;
	}
	void GL_WIN_specular_fog_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void GL_WIN_specular_fog_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace GL_WIN_specular_fog_NAMESPACE
