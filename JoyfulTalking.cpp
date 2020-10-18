#include <bangtal>
using namespace bangtal;

int main()
{
	ScenePtr scene = Scene::create("방", "Images/방.png");


	ObjectPtr dog = Object::create("강아지", "Images/강아지.png", scene, 800, 270, true);


	// 지시어가 뜬다
	showMessage("'치킨'이라고 말해보자! *알맞은 그림이 뜰 때 클릭하세요");

	auto timer = Timer::create(1.f);
	showTimer(timer);
	timer->setOnTimerCallback([&](TimerPtr)->bool {

		return true;
		});

	showMessage("'강아지'라고 말해보자! *알맞은 그림이 뜰 때 클릭하세요");

	showMessage("'밥'이라고 말해보자! *알맞은 그림이 뜰 때 클릭하세요");

	showMessage("'사랑'이라고 말해보자! *알맞은 그림이 뜰 때 클릭하세요");


	showMessage("'숟가락'이라고 말해보자! *알맞은 그림이 뜰 때 클릭하세요");

	auto endButton = Object::create("Images/end.png", scene, 590, 20);

	endButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endGame();

		return true;
		});

	void endGame();


	void startGame(ScenePtr scene);

	return 0;
}