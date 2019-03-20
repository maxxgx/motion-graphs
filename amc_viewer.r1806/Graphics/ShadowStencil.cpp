#include "ShadowStencil.hpp"

#include <Graphics/Graphics.hpp>
#include <Graphics/GLExtensions.hpp>
#include <assert.h>

#include <iostream>

using std::cout;
using std::endl;

//We need one of these two:
REQUEST_GL_EXTENSION(GL_EXT_stencil_two_side);
REQUEST_GL_EXTENSION(GL_ATI_separate_stencil);

//We absolutely need this one:
REQUEST_GL_EXTENSION(GL_EXT_stencil_wrap);

namespace Graphics {

void enable_shadow_stencil() {
	assert(have_EXT_stencil_wrap());
	if (have_EXT_stencil_two_side()) {
		glEnable(GL_STENCIL_TEST_TWO_SIDE_EXT);

		glActiveStencilFaceEXT(GL_BACK);
		glStencilFunc(GL_ALWAYS, 1, ~0U);
		glStencilOp(GL_KEEP, GL_KEEP, GL_INCR_WRAP);

		glActiveStencilFaceEXT(GL_FRONT);
		glStencilFunc(GL_ALWAYS, 1, ~0U);
		glStencilOp(GL_KEEP, GL_KEEP, GL_DECR_WRAP);
 	} else if (have_ATI_separate_stencil()) {
		glStencilFuncSeparateATI( GL_ALWAYS, GL_ALWAYS, 1, ~0U );
		glStencilOpSeparateATI( GL_BACK, GL_KEEP, GL_KEEP, GL_INCR_WRAP );
		glStencilOpSeparateATI( GL_FRONT, GL_KEEP, GL_KEEP, GL_DECR_WRAP );
	} else {
		assert(0);
	}

}

void disable_shadow_stencil() {
	assert(have_EXT_stencil_wrap());
	if (have_EXT_stencil_two_side()) {
		glDisable(GL_STENCIL_TEST_TWO_SIDE_EXT);
	} else {
		/* nothing to disable */
	}
}

}
