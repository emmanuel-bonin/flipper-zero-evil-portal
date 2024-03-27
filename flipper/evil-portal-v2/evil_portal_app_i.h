#pragma once

#include "evil_portal_app.h"
#include "evil_portal_custom_event.h"
#include "evil_portal_uart.h"
#include "scenes/evil_portal_scene.h"
#include "helpers/command_queue.h"

#include <gui/gui.h>
#include <gui/modules/text_box.h>
#include <gui/modules/variable_item_list.h>
#include <gui/scene_manager.h>
#include <gui/view_dispatcher.h>

struct Evil_PortalApp {
  Gui *gui;
  ViewDispatcher *view_dispatcher;
  SceneManager *scene_manager;

  // Array of logs that store messages from the esp32
  FuriString *portal_logs;
  CommandQueue *command_queue;
}