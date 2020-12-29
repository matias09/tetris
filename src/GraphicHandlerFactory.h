#ifndef GRAPHIC_HANDLER_FACTORY_H
#define GRAPHIC_HANDLER_FACTORY_H

#include "GraphicHandlerInterface.h"

class GraphicHandlerFactory
{
public:
  GraphicHandlerFactory();
  ~GraphicHandlerFactory();
  GraphicHandlerInterface* GetGraphicHandler(const int lib);
};

#endif // !GRAPHIC_HANDLER_FACTORY_H
