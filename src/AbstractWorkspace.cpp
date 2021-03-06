#include "tdp_application_framework/AbstractWorkspace.h"
#include "tdp_application_framework/AbstractMainWindow.h"

#include <QWidget>

namespace tdp_application_framework
{

//##################################################################################################
struct AbstractWorkspace::Private
{
  std::string name;
  AbstractMainWindow* mainWindow{nullptr};

  Private(std::string name_):
    name(std::move(name_))
  {

  }
};

//##################################################################################################
AbstractWorkspace::AbstractWorkspace(const std::string& name, QWidget* parent):
  QWidget(parent),
  d(new Private(name))
{
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

//##################################################################################################
AbstractWorkspace::~AbstractWorkspace()
{
  delete d;
}

//##################################################################################################
const std::string& AbstractWorkspace::name() const
{
  return d->name;
}

//##################################################################################################
AbstractMainWindow* AbstractWorkspace::mainWindow()const
{
  return d->mainWindow;
}

//##################################################################################################
nlohmann::json AbstractWorkspace::saveState()const
{
  return nlohmann::json();
}

//##################################################################################################
void AbstractWorkspace::loadState(const nlohmann::json& j)
{
  TP_UNUSED(j);
}

//##################################################################################################
void AbstractWorkspace::setMainWindow(AbstractMainWindow* mainWindow)
{
  d->mainWindow = mainWindow;
}

}
