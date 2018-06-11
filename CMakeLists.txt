cmake_minimum_required(VERSION 3.8)
project(owenatorV2)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        owenatorV2
        main.cpp

        list/list.h
        list/listStructs.h
        list/addToList.h
        list/deleteFromList.h
        list/getFromList.h
        list/replaceInList.h
        list/sortList.h
        list/getNextFromList.h

        gui/gui.cpp gui/gui.h

        gui/render/render.cpp gui/render/render.h
        gui/cursor/cursor.cpp gui/cursor/cursor.h
        gui/color/color.cpp gui/color/color.h

        gui/handler/clickHandler/clickHandler.cpp gui/handler/clickHandler/clickHandler.h
        gui/handler/keyHandler/keyHandler.cpp gui/handler/keyHandler/keyHandler.h

        gui/guiElement/guiElement.cpp gui/guiElement/guiElement.h
        gui/guiElement/guiElementStruct.h
        gui/guiElement/guiElementInitialiser.h
        gui/guiElement/button/button.cpp gui/guiElement/button/button.h
        gui/guiElement/input/input.cpp gui/guiElement/input/input.h
        gui/guiElement/label/label.cpp gui/guiElement/label/label.h

        person/person.cpp person/person.h
        user/user.cpp user/user.h


        views/router.h
        views/routeOption.h
        views/login/login.cpp views/login/login.h
        views/login/loginOption.h
        views/overview/overview.cpp views/overview/overview.h
        views/overview/overviewOption.h
        views/register/register.cpp views/register/register.h views/register/registerOption.h person/personStruct.h user/userStruct.h views/createPerson/createPerson.cpp views/createPerson/createPerson.h views/createPerson/createPersonOption.h dept/dept.cpp dept/dept.h dept/deptStruct.h views/personDetail/personDetail.cpp views/personDetail/personDetail.h views/personDetail/personDetailOption.h views/addDept/addDept.cpp views/addDept/addDept.cpp views/addDept/addDept.h views/addDept/addDeptOption.h filemanager/filemanager.cpp filemanager/filemanager.cpp filemanager/filemanager.h views/save/save.cpp views/save/save.h views/save/saveOption.h)
