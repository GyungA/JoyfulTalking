#include <bangtal>
using namespace bangtal;

int main()
{
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	ScenePtr scene = Scene::create("방", "Images/방.png");

	auto ObjectX = 800, ObjectY = 270;
	ObjectPtr chicken = Object::create("Images/치킨.png", scene, ObjectX, ObjectY, true);
	ObjectPtr dog = Object::create("Images/강아지.png", scene, ObjectX, ObjectY, false);
	ObjectPtr rice = Object::create("Images/밥.png", scene, ObjectX, ObjectY, false);
	ObjectPtr love = Object::create("Images/사랑.png", scene, ObjectX, ObjectY, false);
	ObjectPtr spoon = Object::create("Images/숟가락.png", scene, ObjectX, ObjectY, false);


	// 지시어가 뜬다
	showMessage("'치킨'이라고 말해보자! *알맞은 그림이 뜰 때 아무 키나 누르세요");

	auto timer = Timer::create(0.1f);
	timer->setOnTimerCallback([&](TimerPtr timer) -> bool {
		chicken->hide();
		dog->show();
		
		return true;
	});


	showMessage("'강아지'라고 말해보자!");

	showMessage("'밥'이라고 말해보자!");

	showMessage("'사랑'이라고 말해보자!");


	showMessage("'숟가락'이라고 말해보자!");

	auto endButton = Object::create("Images/end.png", scene, 590, 20);

	endButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endGame();

		return true;
		});


	startGame(scene);

	return 0;
}