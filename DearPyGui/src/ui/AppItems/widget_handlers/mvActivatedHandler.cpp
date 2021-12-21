#include "mvActivatedHandler.h"
#include "mvLog.h"
#include "mvItemRegistry.h"
#include "mvPythonExceptions.h"
#include "mvUtilities.h"

namespace Marvel {

    mvActivatedHandler::mvActivatedHandler(mvUUID uuid)
        :
        mvAppItem(uuid)
    {

    }

    void mvActivatedHandler::customAction(void* data)
    {

        mvAppItemState* state = static_cast<mvAppItemState*>(data);
        if (state->activated)
        {
            mvSubmitCallback([=]()
                {
                    if(_alias.empty())
                        mvRunCallback(getCallback(false), _uuid, ToPyUUID(state->parent), _user_data);
                    else
                        mvRunCallback(getCallback(false), _alias, ToPyUUID(state->parent), _user_data);
                });
        }
    }

}