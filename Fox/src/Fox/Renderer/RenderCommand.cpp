#include "RenderCommand.h"

namespace Fox
{
    Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}
