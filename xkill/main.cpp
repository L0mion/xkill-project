#include <xkill-sound/FMODEventSystem.h>
#include <xkill-sound/FMODEventSystemProgrammerReportParser.h>

//#pragma comment(lib, "../xkill-dependencies/Lib/fmod_event.lib")

int main()
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Sound test, note the txt file at xkill-project\xkill-dependencies\dll\FMOD dlls.txt
	FMODEventSystem* FMODEventSystemTest = new FMODEventSystem();
	FMODEventSystemTest->Init("../xkill-dependencies/sound/", "testproject.fev", 64);

	FMODEventSystemProgrammerReportParser* fmodEventSystemProgrammerReportParser = new FMODEventSystemProgrammerReportParser();
	
	if(!fmodEventSystemProgrammerReportParser->parseProgrammerReport(FMODEventSystemTest))
	{
		//std::cout << "parsing failed" << std::endl;
	}

	FMODEventSystemTest->StartSoundEventAt(0);
	while(1)
	{
		FMODEventSystemTest->Update();
	}

	//Does not execute when cancelling the console window by clicking on the "exit cross"
	delete FMODEventSystemTest;
	delete fmodEventSystemProgrammerReportParser;
}