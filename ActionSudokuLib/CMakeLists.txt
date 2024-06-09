project(ActionSudokuLib)

set(SOURCE_FILES
    MainFrame.cpp MainFrame.h
    pch.h
        GameView.cpp
        GameView.h
        Game.cpp
        Game.h
        ids.h
        Declaration.cpp
        Declaration.h
        Item.cpp
        Item.h
        ScoreBoard.h
        ScoreBoard.cpp
        LevelLoader.cpp
        LevelLoader.h
        DeclarationBackground.cpp
        DeclarationBackground.h
        ItemBackground.cpp
        ItemBackground.h
        ItemSparty.cpp
        ItemSparty.h
        DeclarationSparty.cpp
        DeclarationSparty.h
        DeclarationDigit.cpp
        DeclarationDigit.h
        ItemDigit.cpp
        ItemDigit.h
        DeclarationGiven.cpp
        DeclarationGiven.h
        ItemGiven.cpp
        ItemGiven.h
        DeclarationXray.cpp
        DeclarationXray.h
        ItemXray.cpp
        ItemXray.h
        DeclarationContainer.cpp
        DeclarationContainer.h
        ItemContainer.cpp
        ItemContainer.h
        ItemVisitor.cpp
        ItemVisitor.h
        XrayFinder.cpp
        XrayFinder.h
        FindDigitToEat.cpp
        FindDigitToEat.h
        FindDigitToReg.cpp
        FindDigitToReg.h
        ContainerFinder.h
        ContainerFinder.cpp
        ItemTrap.cpp
        ItemTrap.h
        DeclarationTrap.cpp
        DeclarationTrap.h
        TrapFinderVisitor.cpp
        TrapFinderVisitor.h
        SolveVisitor.cpp
        SolveVisitor.h
        DigitGivenFinder.cpp
        DigitGivenFinder.h
        Banner.cpp
        Banner.h
        SolveCheck.cpp
        SolveCheck.h
)

set(wxBUILD_PRECOMP OFF)

find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)