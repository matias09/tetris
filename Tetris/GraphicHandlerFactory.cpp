#include "GraphicHandlerFactory.h"
#include "Config.h"

// Implementations
#include "GraphicSdlImp.h"

GraphicHandlerFactory::GraphicHandlerFactory()
{}

GraphicHandlerFactory::~GraphicHandlerFactory()
{}

GraphicHandlerInterface * GraphicHandlerFactory::GetGraphicHandler(const int lib)
{
    GraphicHandlerInterface* grpHandler = nullptr;

    switch (lib)
    {
    case CONFIG::GRAPHIC_IMPLEMENTATION::SDL:
        grpHandler = new GraphicSdlImp();
        break;
    }

    return grpHandler;
}
