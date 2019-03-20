#ifndef GRAPHICS_SHADOWSTENCIL_HPP
#define GRAPHICS_SHADOWSTENCIL_HPP

namespace Graphics {

//set up and tear down two-sided shadow state needed for, well,
//two-sided shadow stenciling.
void enable_shadow_stencil();
void disable_shadow_stencil();

}

#endif //GRAPHICS_SHADOWSTENCIL_HPP
